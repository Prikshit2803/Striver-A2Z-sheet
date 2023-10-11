  long long dpmemo(int n,int X,int N,int M, vector<vector<long long>>  &dp){
      if(n==N){
          if(X==0)
      return 1;
      
      return 0;
      }
      
      if(X<0)
      return 0;
      
      if(dp[n][X]!=-1)
      return dp[n][X];
      
      
      long long Take=0;
      for(long long i=1;i<=M;i++){
          
           Take+=dpmemo(n+1,X-i,N,M,dp);
      }
      
      return dp[n][X]=Take;
  }
    long long noOfWays(int M , int N , int X) {
     // vector<vector<long long>> dp(N+1,vector<long long>( X+1,-1));
    
    //vector<long long> dp(N+1,-1);
       
       //return dpmemo(0,X,N,M,dp);
       
             vector<vector<long long>> dp(N+1,vector<long long>( X+1,0));
             
             dp[N][0]=1;
             
             for(int n=N-1;n>=0;n--){
                 for(int x=0;x<=X;x++){
                       long long Take=0;
      for(long long i=1;i<=M;i++){
          
          if(x-i>=0)
           Take+=dp[n+1][x-i];
      }
      
       dp[n][x]=Take;
                 }
             }
             
             return dp[0][X];
    }
