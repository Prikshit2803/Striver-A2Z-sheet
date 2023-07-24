//Given a value N. In how many ways you can construct a grid of size N x 4 using tiles of size 1 x 4.
//Youtube soln link : https://www.youtube.com/watch?v=EhjU_X7Src0

long long dpmemo(int i,vector<long long> &dp){
    if(i<=3)
    return 1;
    
    if(dp[i]!=1){
        return dp[i];
    }
    
    return dp[i]=dpmemo(i-1,dp) + dpmemo(i-4,dp); //coz it has same number of ways as 'N-1' as new horizontal node is added and also iabother case if all 1*4 tiles places in bottom row vertically 
    
    
}
    long long int arrangeTiles(int N){
        vector<long long> dp(N+1,1);
    //  return dpmemo(N,dp);
    
    //tabulation 
    //base-case already covered
    
    for(int i=4;i<=N;i++){
        dp[i]=dp[i-1] + dp[i-4]; 
    }
    
    return dp[N];
    }
