int mod=1e9+7;
  
  bool isSafe(int x,int y,int n,int m){
      if(x<0||y<0 || x>=n ||y>=m)
      return 0;
      
      return 1;
  }
  int dpmemo(int i,int j,vector<vector<int>> &grid,vector<vector<int>> &dp){
      int n=grid.size();
      int m=grid[0].size();
      
      if(grid[0][0] == 0 || grid[n-1][m-1] == 0) return 0;
      
      if(i==n-1 && j==m-1)
      return 1;
      
      if(dp[i][j]!=-1)
      return dp[i][j];
      
      int dx[]={0,1};
      int dy[]={1,0}; //to move right and down
      
      int res=0;
      for(int k=0;k<2;k++){
          int x=i + dx[k];
          int y=j + dy[k];
          
          if(isSafe(x,y,n,m) && grid[x][y]==1)
          res=(res+dpmemo(x,y,grid,dp))%mod;
      }
      
      return dp[i][j]=res%mod;
  }
    int uniquePaths(int n, int m, vector<vector<int>> &grid) {
        vector<vector<int>> dp(n,vector<int>(m,-1));
        
        return dpmemo(0,0,grid,dp);
    }
