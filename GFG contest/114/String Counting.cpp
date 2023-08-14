//youtube-link-https://www.youtube.com/watch?v=yRx2B3sQey0
//Brute-force : TLE
   long long int countStrings(string s){
        map<string,int> mp;
        int n=s.length();
        
        // string q=s;
        // reverse(q.begin()+0,q.begin()+n);
        // cout<<q;
        
        for(int i=0;i<n;i++){
            for(int j=i;j<=n;j++){
                string t=s;
                reverse(t.begin()+i,t.begin()+j);
                if(mp[t]==1)
                continue;
                
                else{
                    mp[t]++;
                }
            }
        }
        
        long long int ans=0;
        
        for(auto it : mp){
            if(it.second==1)
            ans++;
        }
        
        return ans;
    }
};

//optmised-way
//only strings with different start and ending character will generate new substring
//we take cnt of a char and multiply with count of all other unique chars in the string
long long int countStrings(string s){
        long long int ans=1;
        vector<int> cnt(26,0);
        
        for(int i=0;i<s.length();i++)
        cnt[s[i]-97]++; //as 'a' at index 0
        
        for(int i=0;i<26;i++){
            for(int j=i+1;j<26;j++){
                ans+=cnt[i]*cnt[j];
            }
        }
        return ans;
    }
