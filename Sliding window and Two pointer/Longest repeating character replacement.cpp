//length-maxfreq should be <=k
    int characterReplacement(string S, int K) {
       
       vector<int> cnt(26,0);
       
       int maxlen=0,maxcnt=0;
       int l=0;
       
       for(int r=0;r<S.length();r++){
           cnt[S[r]-'A']++;
           int currcnt=cnt[S[r]-'A'];
           
           maxcnt=max(maxcnt,currcnt);
           
           while((r-l+1)-maxcnt>K){ //no. of characters other than max occuring character are more than k
               cnt[S[l]-'A']--;
               l++;
           }
           
           maxlen=max(maxlen,r-l+1);
           
       }
       
       return maxlen;
    }
