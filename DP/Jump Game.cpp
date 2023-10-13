//Given an positive integer N and a list of N integers A[]. Each element in the array denotes the maximum length of jump you can cover. 
//Find out if you can make it to the last index if you start at the first index of the list.
int dpmemo(int i,int A[], int n,vector<int> &dp){
      
      if(i==n-1)
      return 1;
      
      if(dp[i]!=-1)
      return dp[i];
      
      
      if(A[i]==0)
      return 0;
      
      for(int k=1;k<=A[i];k++){
          if(dpmemo(i+k,A,n,dp))
          return 1;
      }
      
      return 0;
  }
    int canReach(int A[], int N) {
       
       vector<int> dp(N+1,-1);
       
       return dpmemo(0,A,N,dp);
    }
