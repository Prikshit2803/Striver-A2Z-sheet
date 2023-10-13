//link : https://www.youtube.com/watch?v=jFZmBQ569So
int CountWays(string str){
		   
		   int mod=1e9+7;
		   
		   int n=str.length();
		   vector<int> dp(n+1,0);
		   
		   dp[0]=1; //0 represents -ve index to handle i-2 case where i=1 if index 0 and 1 both non-zero and less than 26 then we add dp[i-1 ] and dp[i-2] in which case both are 1 hence dp[0] and dp[1] are 1
		   dp[1]=1;
		   
		   for(int i=2;i<=n;i++){
		       if(str[i-1]!='0'){
		           dp[i]=dp[i-1];
		       }
		       
		       if((str[i-2]=='1') || (str[i-2]=='2' && str[i-1]<='6'))
		       dp[i]=(dp[i] + dp[i-2]%mod)%mod;
		   }
		   
		   return dp[n];
}
