//trvaerse through all substrings and store cnt and  then keep finding beauty
int beauty(int cnt[]){
      int mf=-1;
      int lf=1e9;
      
      for(int i=0;i<26;i++){
          mf=max(mf,cnt[i]);
          
          if(cnt[i]>=1){
              lf=min(lf,cnt[i]);
          }
      }
      
      return mf-lf;
  }
  
    int beautySum(string s) {
       
      int ans=0;
       
      for(int i=0;i<s.length();i++){
          int cnt[26]={0}; 
          //cnt(26,0);
          for(int j=i;j<s.length();j++){
                 cnt[s[j]-'a']++;
    
                 ans+=beauty(cnt);
              }
          }
           
          
      return ans;
    }
    
