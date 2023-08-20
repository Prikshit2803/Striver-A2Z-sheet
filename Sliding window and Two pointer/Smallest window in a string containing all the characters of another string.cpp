//Approach : store all characters of pattern in a map/vector and store cnt of unique characters and traverse string s using two pointers and
//decrement in map and if mp[char]==0 do cnt-- as that char has been completely found and if cnt==0 alll char are found now start 
//releasing elements by incrementing i and increase mp[char] ++ and if mp[char]==1 it means a character of pattern has been released and do
//cnt++ and store the string len and start

    string smallestWindow (string s, string p)
    {
       // map<int,int> mp; //causes TLE
       vector<int>mp(256,0);
        
        if(s.length()<p.length())
        return "-1";
        
        int cnt=0; //distinct characters count
        for(int i=0;i<p.length();i++){
            
            if(mp[p[i]-'a']==0)
            cnt++;
            
            mp[p[i]-'a']++;
        }
        
        
        int start=0;
        int len=INT_MAX;
        int i=0;
        int j=0; //sliding window
        
        while(j<s.length()){
            
            //acquiring elements
            mp[s[j]-'a']--;
            
            if(mp[s[j]-'a']==0)
            cnt--;
           
           if(cnt==0){ 
            while(cnt==0){
                
                if((j-i+1)<len){
                    len=j-i+1;
                    start=i;
                }
                
                //now we start releasing elements to get min string
                
                mp[s[i]-'a']++;
                
                if(mp[s[i]-'a']==1)
                cnt+=1; //it means a character of p has been released
                
                i++;
                
                
            }
           }
            
            j++;
        }
        
        if(len==INT_MAX)
        return "-1";
        
        return s.substr(start,len);
        
    }

video link : https://www.youtube.com/watch?v=ZluoN6g6o0s
more intuitive approach video link : https://www.youtube.com/watch?v=e1HlptlipB0
