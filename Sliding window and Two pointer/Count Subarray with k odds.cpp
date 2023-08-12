//Same as ''Binary subarray with sum'
 int countSubarray(int n, vector<int>& arr, int k) {
       
        int l=0,r=0,ans=0,cnt=0,temp=0;
      
      while(r<n){
          
          if(arr[r]%2==1){
              cnt++;
          }
          
          if(arr[r]%2==1)
          temp=0;
          
          while(cnt==k){
              temp++;
             
             if(arr[l]%2==1){
              cnt--;
          }
              l++;
          }
          
          ans=ans+temp; //it works even when arr[r]=0 and sum!=target as temp from previous value is stored 
          
          r++;
      }
       
       return ans;
    }
