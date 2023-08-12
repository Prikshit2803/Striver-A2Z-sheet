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
          
          ans=ans+temp; //when element os ven ,it means that if odd elements was before were k, now no longer k but r is even number means all previous subarrays could have formed with it
          
          r++;
      }
       
       return ans;
    }

//76 68 92 23 82 95 91 89 42 79
//k=4
//look at '42' to understand temp
