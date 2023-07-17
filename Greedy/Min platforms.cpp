/my approach: that works
//Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
         vector<pair<int,int>> v;
         
         for(int i=0;i<n;i++){
             v.push_back({arr[i],dep[i]});
         }
         
         sort(v.begin(),v.end());
         
         int cnt=1;
         vector<int> limit;
          limit.push_back(v[0].second);
         
         
         for(int i=1;i<n;i++){
             int flag=1;
             for(int j=0;j<limit.size();j++){
                 if(v[i].first>limit[j]) //arrival>=depature at a platform
                 {
                     limit[j]=v[i].second;
                    flag=0;
                    break;
                 }
                 
                 
             }
             
             if(flag==1){
                 cnt++;
                 limit.push_back(v[i].second);
             }
         }
         
         return cnt;
    }

//Striver approach : Sort both arrays independently
   int findPlatform(int arr[], int dep[], int n)
    {
        int cnt=1;
        int res=1;
        
        sort(arr,arr + n);
        sort(dep,dep + n);
        
        
        int i=1,j=0;
        
        while(i<n && j<n){
            
            if(arr[i]<=dep[j]){ //if arr=dep then also different platforms to be used : given in question
                cnt++;
                i++;
            }
            
            else if(arr[i]>dep[j]){
                cnt--; //train has departed
                j++;
            }
            
            res=max(res,cnt);
        }
        
        return res;
    }
