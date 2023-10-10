int dpmemo(int i,string A,unordered_map<string,int> &mp,vector<int> &dp){
  //this commented part doesnt work
//     int n=A.length();
    
//     //ans+=A[i];
    
//     if(i==n)
//     {
//       if(mp.find(ans)!=mp.end())
//       return 1;
       
//       return 0;
//     }
    
//     if(dp[i]!=-1)
//     return dp[i];
    
    
    
    
//     int Take=0;
    
//     if(mp.find(ans + A[i])!=mp.end())
//     {
//         Take=dpmemo(i+1,"",A,B,mp,dp);
//     }
    
//   int notTake=dpmemo(i+1,ans + A[i],A,B,mp,dp);
    
//     return dp[i]=(Take || notTake);

if(i==A.length())
return 1;

if(dp[i]!=-1)
return dp[i];

string temp="";
for(int j=i;j<A.length();j++){
    temp+=A[j];
    
    if(mp.find(temp)!=mp.end()){
    if(dpmemo(j+1,A,mp,dp))
    return dp[i]=1;
    }
}

return dp[i]=0;
}
    int wordBreak(string A, vector<string> &B) {
        
        unordered_map<string,int> mp;
        
        for(int i=0;i<B.size();i++)
        mp[B[i]]=1;
        
        
        // vector<int> dp(A.length()+1,-1);
        
        
        // return dpmemo(0,A,mp,dp);
        
        
        int n=A.length();
         vector<int> dp(A.length()+1,0);
         
         dp[n]=1;
         
         for(int i=n-1; i>=0; i--){
             string temp = "";
          for(int j=i;j<n; j++){
                temp+= A[j];
    
             if(mp.find(temp)!= mp.end()){
                  if(dp[j+1]){
                    dp[i]=1;
                    break;
                  }
    }
}


         }
        
        return dp[0];
        
       
        
    }
