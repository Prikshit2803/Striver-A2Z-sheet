//video-link : https://www.youtube.com/watch?v=JnxAWShm4PU
//Intuition : create a vector string to store string in each row
    //start with row = 0 and keep storing till row=n-1 then store till row=0
    //continue this until string is completely traversed
    string convert(string s, int n) {
        
        if(n==1)
        return s;
        
        int flag=false;
        
        vector<string> zigzag(n);
        
        int i=0;
        
        for(auto ch : s){
            
            zigzag[i]+=ch;
            
            if(i==0)
            flag=true;
            
            else if(i==n-1)
            flag=false;
            
            if(flag)
            i++;
            
            else
            i--;
        }
        
        
        string ans="";
        
        for(auto str : zigzag)
        ans+=str;
        
        
        return ans;
        
    }
