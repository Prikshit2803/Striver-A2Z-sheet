//Prefix sum is used
// we take the net opeartion on every index and then apply it
//video-link : https://www.youtube.com/watch?v=oZReOH5pD_U

//Brute-Force
        // for(auto it : shifts){
        //     int start = it[0];
        //     int end=it[1];
        //     int dir=it[2];

        //     if(dir==1){
        //         for(int i=start;i<=end;i++){
        //             if(s[i]=='z')
        //             s[i]='a';
                     
        //              else
        //             s[i]=s[i]+1;

        //         }
        //           //cout<<s<<"..";
        //     }

        //    else if(dir==0){
        //         for(int i=start;i<=end;i++){
        //             if(s[i]=='a')
        //             s[i]='z';
                    
        //             else
        //             s[i]=s[i]-1;
                    
        //         }

        //         //cout<<s<<",,";
        //     }
        // }


   string shiftingLetters(string s, vector<vector<int>>& shifts) {    
        


        vector<int> presum(s.length()+1,0);

        for(auto it : shifts){
            int start = it[0];
            int end=it[1];
            int dir=it[2];
             
             if(dir==1){
                 presum[start]++;
                 presum[end+1]--; //marks end point
             }

             else{
                 presum[start]--;
                 presum[end+1]++; //marks end point
             }
               
        }

        for(int i=1;i<s.length();i++)
              presum[i]+=presum[i-1]; //calculate sum so far


              for(int i=0;i<s.length();i++){
                  int inc=(s[i]-'a'+ presum[i])%26;

                  //if inc is -ve
                  inc=(inc + 26)%26;

                  s[i]='a' + inc;
              }


        return s;
    }
