//Link : https://www.youtube.com/watch?v=UvksR0hR9nA
//Approack : Pick the best among the worst
    //n - no. of eggs
    //k- no. of floors
    int dpmemo(int n,int k,vector<vector<int>> &dp){
        if(n==1)
        return k;
        
        
        if(k==0 || k==1)
        return k;
        
        if(dp[n][k]!=-1)
        return dp[n][k];
        
        int mini=INT_MAX;
        for(int i=1;i<=k;i++){
            int breaks=dpmemo(n-1,i-1,dp);
            int notbreaks=dpmemo(n,k-i,dp); //n remains same and we check remaining floor upwards
            
            int worst=max(breaks,notbreaks) + 1; //1 added for current move
            
            mini=min(mini,worst);
        }
        
       return dp[n][k]=mini;
    }
    int eggDrop(int n, int k) 
    {
    //   vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
       
       
    //   return dpmemo(n,k,dp);
    
    vector<vector<int>> dp(n+1,vector<int>(k+1,0));
    
    for(int i=1;i<=k;i++)
    dp[1][i]=i;
    
    for(int i=1;i<=n;i++){
        dp[i][0]=0;
        dp[i][1]=1;
    }
    
    for(int i=2;i<=n;i++){ //egg
        for(int j=2;j<=k;j++){ //floor
            
        int mini=INT_MAX;
        for(int s=1;s<=j;s++){
            int breaks=dp[i-1][s-1];
            int notbreaks=dp[i][j-s]; //n remains same and we check remaining floor upwards
            
            int worst=max(breaks,notbreaks) + 1; //1 added for current move
            
            mini=min(mini,worst);
        }
        
       dp[i][j]=mini;
        }
    }
    
    
    return dp[n][k];
    }
