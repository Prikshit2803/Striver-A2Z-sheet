// Given a target position on infinite number line, i.e -infinity to +infinity. Starting form 0 you have to reach the target by moving as described : In ith move you can take i steps forward or backward. Find the minimum number of moves require to reach the target.
// If target is negative, we can take it as positive because we start from 0 in symmetrical way. 

//Article Link : https://www.geeksforgeeks.org/find-minimum-moves-reach-target-infinite-line/


int reachTarget(int target)
{
    // Handling negatives by symmetry
    target = abs(target);
     
    // Keep moving while sum is smaller or difference
    // is odd.
    int sum = 0, step = 0;
    while (sum < target || (sum - target) % 2 != 0) { //(sum - target) % 2 != 0 if this is even our job is done as we take only +ve numbers
        step++;
        sum += step;
    }
    return step;
}
