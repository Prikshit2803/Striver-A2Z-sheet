// Intuition
// This is a very hard problem and we need to solve several smaller problems.

// Prime Score
// This is a medium/easy problem. We first use the sieve of eratosthenes to find a list of prime numbers. Then we can simply do division for any input num against each prime number in the list to find their prime score.

// Note we only need to find primes up to n\sqrt{n} 
// n
// ​
//   when trying to divide nnn up.

// Subarray Count
// For a specific number(index) in the array, how many subarrays (containing that index of course) will choose it as x?

// Consider the start of the subarray, it can be any smaller index until there is one element with a prime score not less than it.
// Consider the end of the subarray, it can be any greater index until there is one element with a prime score greater than it.
// For example, let's say we have the prime scores as [1, 2, 3, 5, 4, (5), 3, 5, 6, 2], consider index 5 (the score value is 5 too):

// To the left, for the starting index of a subarray, we can pick index 5 or 4, but not 3. This is because if that were included, the subarray would choose index 3 as the index of x.
// To the right, for the end index of a subarray, we can pick index 5, 6 or 7, but not 8. (index 7 is OK because when they have the same score the smaller index wins)
// Therefor we can multiply these two counts to get 2×3=62 \times 3 = 62×3=6 as the subarray count for subarrays that will choose 5.

// We can use a monotonic stack to efficiently find the subarray count for each index in one-pass.

// Largest k
// We simply go through all the nums from the largest to smallest, and take into account of their subarray count.

// Note that k could be really really large so any algorithm that tries to iterate k times would be quite slow. Luckily we have an efficient algorithm for calculating ana^na 
// n
//   where aaa is a num in the input and nnn is its subarray count, this way our iteration will be at most NNN times in this step.

// Approach
// We basically solved the 3 smaller problems mentioned above and put them together.

// Complexity
// Time complexity:
// Θ(Nlog⁡N+Nlog⁡V+V)\Theta(N \log N + N \log V + \sqrt{V})Θ(NlogN+NlogV+ 
// V
// ​
//  )

// NNN is the length of the input and VVV is the value range of the numbers in the input.

// Our sieve algorithm takes Θ(V)\Theta(\sqrt{V})Θ( 
// V
// ​
//  ) to find primes we care.
// Our prime score calculation takes Θ(log⁡a)\Theta(\log a)Θ(loga) for each aaa in the input, so total Θ(Nlog⁡V)\Theta(N \log V)Θ(NlogV)
// Our one pass algorithm takes Θ(N)\Theta(N)Θ(N) to generate all the pairs for ana^na 
// n
//  .
// Our final step takes Θ(Nlog⁡N)\Theta(N \log N)Θ(NlogN) to sort and then the same Θ(Nlog⁡N)\Theta(N \log N)Θ(NlogN) to iterate from largest as each ana^na 
// n
//   takes Θ(log⁡n)\Theta(\log n)Θ(logn) to calculate.
// Space complexity:
// Θ(N)\Theta(N)Θ(N)

constexpr int kMod = 1000'000'007;

vector<int> GetPrimes(int limit) {
  vector<int> not_prime(limit);
  vector<int> primes;
  for (int i = 2; i < limit; ++i) {
    if (not_prime[i]) {
      continue;
    }
    primes.push_back(i);
    for (int j = i * i; j < limit; j += i) {
      not_prime[j] = 1;
    }
  }
  return primes;
}

// 400 * 400 > 10^5
const vector<int> kPrimes = GetPrimes(400);

int PrimeScore(int n) {
  int score = 0;
  for (int p : kPrimes) {
    if (p * p > n) {
      break;
    }
    if (n % p != 0) {
      continue;
    }
    ++score;
    while (n % p == 0) {
      n /= p;
    }
  }
  score += n > 1;
  return score;
}

int ModPow(int64_t a, int x) {
  int64_t r = 1;
  while (x > 0) {
    if (x % 2 == 1) {
      r = r * a % kMod;
    }
    a = a * a % kMod;
    x /= 2;
  }
  return r;
}

class Solution {
public:
  int maximumScore(vector<int>& nums, int k) {
    const int N = nums.size();
    vector<pair<int, int>> score_and_indices;  // A stack for one-pass algorithm
    vector<pair<int, int64_t>> value_and_powers;  // Results of this one-pass algorithm
    for (int i = 0; i < N; ++i) {
      int score = PrimeScore(nums[i]);
      while (!score_and_indices.empty() && score_and_indices.back().first < score) {
        auto [s, index] = score_and_indices.back();
        score_and_indices.pop_back();
        int64_t left = score_and_indices.empty() ? -1 : score_and_indices.back().second;
        value_and_powers.push_back({nums[index], (index - left) * (i - index)});
      }
      score_and_indices.push_back({score, i});
    }
    while (!score_and_indices.empty()) {
      auto [s, index] = score_and_indices.back();
      score_and_indices.pop_back();
      int64_t left = score_and_indices.empty() ? -1 : score_and_indices.back().second;
      value_and_powers.push_back({nums[index], (index - left) * (N - index)});
    }
    
    std::sort(value_and_powers.begin(), value_and_powers.end());
    
    int64_t answer = 1;
    for (int i = value_and_powers.size() - 1; i >= 0 && k > 0; --i) {
      auto [value, power] = value_and_powers[i];
      k -= power;
      if (k < 0) {
        power += k;
      }
      answer = answer * ModPow(value, power) % kMod;
    }
    return answer;
  }
};
