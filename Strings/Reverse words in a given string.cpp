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

//leetcode version : spaces are there and not dots and remove initial and ending unecesarry spaces
tring reverseWords(string s) {
       
       string temp="",ans="";

       int i=0;

       while(i<s.length()){

           if(s[i]!=' '){
               temp+=s[i];
           }

           else if(s[i]==' ' && temp!=""){ //space encountered and temp not null i.e it indeicates a space after a word
                   ans=temp + " " + ans; //reverses words
                   temp=""; //make temp NULL
           }

          
          i++;
       }

       if(temp!=""){ //indicates no space after last word
             ans=temp + " " + ans;
       }

       return ans.substr(0,ans.length()-1);
    }
