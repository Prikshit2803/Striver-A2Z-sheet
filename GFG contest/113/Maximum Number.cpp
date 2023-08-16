//My soln
 int maximumNumber(int N) {
        
        vector<int> ap;
        
        int n=N;
        
        while(n){
            int i=n%10;
            ap.push_back(i);
            n=n/10;
        }
        
        reverse(ap.begin(),ap.end());
        
        for(int i=0;i<ap.size();i++){
            if(ap[i]==7){
                ap[i]=9;
                break;
            }
            
        }
        
        int ans=0;
         for(int i=0;i<ap.size();i++){
            ans+=ap[i]*pow(10,ap.size()-i-1);
            
            }
            
            
            return ans;
        }

//similar approach but simpler
class Solution {
  public:
    int maximumNumber(int N) {
        // code here
        string s=to_string(N);
        
        for(int i=0;i<s.length();i++){
            if(s[i]=='7'){
                s[i]='9';
                break;
            }
        }
        return stoi(s);
    }
};
