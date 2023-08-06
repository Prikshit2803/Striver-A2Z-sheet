//Same as 3sum with one more loop
 vector<vector<int> > fourSum(vector<int> &arr, int k) {
        
        vector<vector<int> > ans;
        sort(arr.begin(),arr.end());
        
        int n=arr.size();
        
        for(int i=0;i<n-3;i++){
            if(i>0 && arr[i]==arr[i-1]) continue;
            for(int j=i+1;j<n-2;j++){
                 if(j>i+1 && arr[j]==arr[j-1]) continue;
                int l=j+1;
                int m=n-1;
                
                while(l<m){
                    if(arr[i]+arr[j]+arr[l]+arr[m]==k){
                        vector<int> temp={arr[i],arr[j],arr[l],arr[m]};
                      
                        ans.push_back(temp);
                        
                        l++;
                        m--;
                        
                        while(l<m && arr[l]==arr[l-1])
                        l++;
                        
                        while(l<m && arr[m]==arr[m+1])
                        m--;
                    } 
                    
                    else if(arr[i]+arr[j]+arr[l]+arr[m]>k)
                    m--;
                    
                    else
                    l++;
                }
                
               
            }
        }
        
        return ans;
    }
