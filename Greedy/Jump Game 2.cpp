//DP TLE soln as it takes space complexity
int dpmemo(int i,int arr[], int n, vector<int> &dp){
      if(i>=n)
      return 1e9;//INT_MAX + 1 can give segmentation fault
      
      if(i==n-1)
      return 0;
      
      if(arr[i]==0)
      return 1e9;
      
      if(dp[i]!=-1)
      return dp[i];
      
      int step=INT_MAX;
      for(int k=1;k<=arr[i];k++){
          step=min(step,1+dpmemo(i+k,arr,n,dp));
      }
      
      return dp[i]=step;
  }
    int minJumps(int arr[], int n){
        
        vector<int> dp(n+1,-1);
         int ans=dpmemo(0,arr,n,dp);
        
        if(ans>=1e9)
        return -1;
        
        else
        return ans;
    }

//optimal greedy soln

 int minJumps(int arr[], int n){
        
        if(arr[0]==0)
        return -1;
        
        if(n==1)
        return 1;
        
        int maxreach=arr[0];
        int steps=arr[0];
        int jump=1;
        
        for(int i=1;i<n;i++){
            if(i==n-1)
            return jump;
            
            maxreach=max(maxreach,i+arr[i]);
            steps--; //steps that can be taken from each index i.e. if step!=0 we can reach it from some prev index
            
            if(steps==0){ //last index reachable from some prev index with max reach
            jump++;
            
            if(i>=maxreach)
            return -1;
            
            steps=maxreach-i; //it means we take next jump from here 
                
            }
        }
        
    }
