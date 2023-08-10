int longestOnes(int n, vector<int>& arr, int k) {
       
       int ans=0;
       int l=0,r=0;
       int cnt=k;
       while(r<n){
           
           
           
           if(arr[r]==0)
           cnt--;
           
           while(cnt<0){ // no. of zeroes are more than k 
               if(arr[l]==0)
               cnt++;
               
               l++;
               
           }
           
           
           ans=max(r-l+1,ans);
          // cout<<ans<<l<<r<<"...";
           r++;
       }
       
       return ans;
    }
