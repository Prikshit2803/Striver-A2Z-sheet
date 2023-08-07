//Space complecity O(N) and TC O(N)
vector<int> findTwoElement(vector<int> arr, int n) {
       
       map<int,int> mp;
       
       vector<int> ans;
       for(int i=0;i<n;i++){
           mp[arr[i]]++;
           
           if(mp[arr[i]]==2)
           ans.push_back(arr[i]);
       }
       
       for(int i=0;i<n;i++){
           if(mp[i+1]==0)
           ans.push_back(i+1);
       }
       
       return ans;
    }

//O(1) space complexity
 vector<int> findTwoElement(vector<int> arr, int N) {
       
       long long n=N; // this is essential else error
       
       //vector<int> ans;
       //x : repeating , y: missing
       //S-SN = x-y sum of natural nos
       //S2 - S2N=(x-y)(x+y) sum of squares
       
       long long SN= ((n*(n+1))/2);
        long long S2N= ((n*(n+1)*(2*n+1))/6);
        
        long long S=0,S2=0;
       for(int i=0;i<n;i++){
         S+=((long long) arr[i]);
         S2+=((long long)arr[i] * (long long)arr[i]);
       }
       
       long long val1=S-SN; //x-y
       long long val2=S2-S2N;//(x-y)(x+y)
       
       val2=val2/val1; //x+y
       
       long long x=(val1 + val2)/2;
       long long y=x-val1;
       
       return {(int)x,(int)y};
    }
