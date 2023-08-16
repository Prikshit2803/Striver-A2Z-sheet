 int findCatalan(int n) 
    {
        vector<long long> dp(n+1,0);
        
        int mod=1e9+7;
        
        dp[0]=1;
        dp[1]=1;
        
        for(int i=2;i<=n;i++){
            for(int j=0;j<i;j++){
                dp[i]=(dp[i] + (dp[j]*dp[i-j-1])%mod)%mod;
            }
        }
        
        return dp[n]%mod;
    }
