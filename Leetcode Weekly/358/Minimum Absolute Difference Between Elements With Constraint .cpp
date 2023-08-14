 // Add elements less than x to the multi set
// find the upper bound of the current element in the multi set.
// As we get the next larger number using upper_bound, check the diff with it and also with the previous (smaller or equal )element and take the min.
         
int minAbsoluteDifference(vector<int>& nums, int x) {
    
         
         int ans=INT_MAX;

         set<int> s;
         int n=nums.size();

         for(int i=0;i<n;i++){
             if((i-x)>=0)
             s.insert(nums[i-x]);

             auto it1=s.upper_bound(nums[i]); //It returns an iterator pointing to the first element that is greater than the given value.
              
              
              //auto it2=s.lower_bound(nums[i]);// 

              if(it1!=s.end())
              ans=min(ans,abs(nums[i]-*it1));

              if(it1!=s.begin())
                ans=min(ans,abs(nums[i]-*prev(it1)));
             
             // ans=min(ans,abs(nums[i]-*it2)); //not working as lower bpund finds greater element

         }
        
        return ans;
    }
