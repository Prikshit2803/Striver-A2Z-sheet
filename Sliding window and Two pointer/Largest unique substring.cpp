 // TC :  O(2N) - TLE
    int longestUniqueSubsttr(string S){
        int n=S.length();
        map<char,int> mp;
        int cnt=0,ans=0;;
        
        int l=0,r=0;
        
        while(r<n ){
            if(mp[S[r]]==0){
                
                ans=max(r-l+1,ans); //check if max length
                mp[S[r]]++; //increase cnt
                r++;
            }
            
            else{
                
                   mp[S[l]]--; //move l forward by 1 and decrease cnt
                    l++;
               
                
            }
            
           
        }
        
        return ans;
    }

 // TC :  O(N)
    int longestUniqueSubsttr(string S){
        int n=S.length();
        
        vector<int> mp(256,-1);
        
        int ans=0;
       
       int l=0,r=0;
       
       while(r<n){
           if(mp[S[r]]!=-1){ //character already exists between l and r
              l=max(mp[S[r]]+1,l); //shift l if last found index of S[r] is greater than l else let it be as char last encountered is not in range 
           }
           
           mp[S[r]]=r; //update last found index of S[r]
           
           ans=max(r-l+1,ans);
           
           r++;
       }
       
       return ans; 
    }
