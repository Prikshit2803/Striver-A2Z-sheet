int dpmemo(int i,int *arr,vector<int> &dp,int n){
	    if(i>=n)
	    return 0;
	    
	    if(dp[i]!=-1)
	    return dp[i];
	    
	    int Take=arr[i] + dpmemo(i+2,arr,dp,n);
	    
	    int notTake=dpmemo(i+1,arr,dp,n);
	    
	    return dp[i]=max(Take,notTake);	
	    
	}
	int findMaxSum(int *arr, int n) {
	   // vector<int> dp(n,-1);
	    
	   // return dpmemo(0,arr,dp,n);
	   
	    vector<int> dp(n+2,0);
	    
	    for(int i=n-1;i>=0;i--){
	        int Take=arr[i] + dp[i+2];
	    
	    int notTake=dp[i+1];
	    
	   dp[i]=max(Take,notTake);	
	    }
	    
	    return dp[0];
	    
	}
