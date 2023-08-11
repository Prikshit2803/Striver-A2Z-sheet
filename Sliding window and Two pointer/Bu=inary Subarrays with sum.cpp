map<int, int> mp;
        int preSum = 0, count = 0;
        int i=0, j=0;
        while(j < N) {
            preSum += arr[j];
            mp[preSum]++;

// both the below statements must be if, not if and else if coz Itll fail in this case 0 0 1 1
            if(preSum == target) {
                count++;
            }
            else if(mp.find(preSum - target) != mp.end()) { //it means that if sum so far - target exists then target exists
                count += mp[preSum-target];
            }
            j++;
        }
        return count;
    }

//Space complexity : O(1)

 int numberOfSubarrays(vector<int>& arr, int N, int target){
       int l=0,r=0,ans=0,sum=0,temp=0;
      
      while(r<N){
          sum+=arr[r];
          
          if(arr[r]==1)
          temp=0;
          
          while(sum==target){
              temp++;
              sum=sum-arr[l];
              l++;
          }
          
          ans=ans+temp; //it works even when arr[r]=0 and sum!=target as temp from previous value is stored 
          
          r++;
      }
       
       return ans;
    }
