 //cant use long long or int or anything as string size is too big
    //we will do kid multiplication but in reverse 

//video link : https://www.youtube.com/watch?v=tS6_n-2JmWw

    string multiplyStrings(string s1, string s2) {
     
     int sign=1;
     if(s1[0]=='-'){
         sign*=-1;
         s1=s1.substr(1);
     }
     
     if(s2[0]=='-'){
         sign*=-1;
         s2=s2.substr(1);
     }
     
     reverse(s1.begin(),s1.end());
     reverse(s2.begin(),s2.end());
     
     
     int n=s1.size();
     int m=s2.size();
     
     vector<int> res(n+m+20,0);
     for(int i=0;i<m;i++){
         int pos=i; //to know where to start adding products
         
         int x=s2[i]-'0';
         
         for(int j=0;j<n;j++){
             int y=s1[j]-'0';
             
             res[pos]+= x*y;
             
             if(res[pos]>9){
                 res[pos+1]+=res[pos]/10 ; //carry forward
                 res[pos]=res[pos]%10;
             }
             
             pos++;
             
         }
     }
     
     string ans;
     
     bool found=0; //indicates a non-zero found to begin the number
     //as res may have many zeroes left in end
     for(int i=res.size()-1;i>=0;i--){
         
         if(res[i]!=0)
         found=1;
         
         if(found){
             ans+=(res[i]+ '0');
         }
     }
     
     if(sign==-1)
     ans='-' +ans;
     
     return ans;
            
    }     
