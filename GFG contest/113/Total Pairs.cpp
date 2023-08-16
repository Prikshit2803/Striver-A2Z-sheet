// Geek is given an array nums of length n and two integers x and y. Geek is interested to find the total number of pairs (i, j) such that x <= a[i]*a[j] <= y (1 <= i < j <= n).
// Help geek to find the total number of such pairs.

//My soln : optimised Brute-Force
 sort(nums.begin(),nums.end());
         int n=nums.size();
         int ans=0;

          for(int i=0;i<n;i++){
              for(int j=i+1;j<n;j++){
                  if(nums[i]*nums[j]>=x && nums[i]*nums[j]<=y)
                  ans++;
                  
                  if(nums[i]*nums[j]>y)
                  break;
              }
          }
          
          return ans;

// sort the array nums.
// Initialize a variable ans equal to 0.
// Run a loop i from 0 to ans.size().
// Initialize a variable p with value equal to ceil value of (x/nums[i]).
// Initialize a variable q with value equal to (y/nums[i]).
// Initialize a variable l and store the lower_bound of p.
// Initialize a variable r and store the upper_bound of q.
// Decrease the r by 1, as the upper bound will find the number which will be greater than q.
// If l is less than equal to r, then add the (r - l + 1) to ans.
// Return ans.

int TotalPairs(vector<int>&nums, int x, int y){
		sort(nums.begin(), nums.end());
		int ans = 0;
		for(int i = 0; i < nums.size(); i++){
			int p = ceil((x*1.0)/nums[i]);
			int q = y/nums[i];
			int l = lower_bound(nums.begin()+i+1, nums. end(), p) - nums.begin();
			int r = upper_bound(nums.begin()+i+1, nums.end(), q) - nums.begin();
			r--;
			if(l <= r){
				ans += (r-l+1);
			}
		}
		return ans;
	}
