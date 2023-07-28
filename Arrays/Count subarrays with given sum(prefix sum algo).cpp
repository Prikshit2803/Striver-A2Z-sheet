 // intuition : prefix sum, in a subarray if subarray sum is p and there exits a portion
   //with sum k then there must be a prefix portion with sum p-k, its existence confirms k exists
    int findSubArraySum(int arr[], int n, int k)
    {
      
      //normal map gives TLE
          unordered_map<int,int> mp;
          int prefixsum=0,cnt=0;
          
          mp[0]++; //this means subarray from 0th element equals k , hence no prefix sum
          
          for(int i=0;i<n;i++){
              prefixsum+=arr[i];
              
              int remove=prefixsum-k;
              
              cnt+=mp[remove];
              
              mp[prefixsum]++;
          }
           
           return cnt;
    }
