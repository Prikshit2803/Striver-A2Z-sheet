//we find max digit of each number and put it into map and then see if the max digit exists and then we take sum and maximise it
int maxSum(vector<int>& arr) {
        
        int n=arr.size();
        
        int ans=-1;
        
        map<int,int> mp;
        
        for(int i=0;i<n;i++){
            int N=arr[i];
            int mx=0;
            
            while(N){
                int k=N%10;
                mx=max(k,mx);
                N=N/10;
            }
              
             
            for(auto it : mp){
                if(it.second==mx){
                    int sum=arr[i]+arr[it.first];
                    ans=max(sum,ans);
                }
                    
            }
            
            mp[i]=mx;
        }
        
        return ans;
        
    }
