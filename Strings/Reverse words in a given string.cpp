//store all strings in a vector , reverse the vector and create a new string ans
    string reverseWords(string S) 
    { 
        vector<string> b;
        
        for(int i=0;i<S.length();i++){
            string a="";
            while(i<S.length() && S[i]!='.'){
                a+=S[i];
                i++;
            }
            
           // cout<<a<<"..";
            b.push_back(a);
        }
        
        reverse(b.begin(),b.end());
        
        string ans;
        for(int i=0;i<b.size();i++){
            ans+=b[i];
            
            if(i!=b.size()-1)
            ans+=".";
        }
        
        return ans;
    } 
