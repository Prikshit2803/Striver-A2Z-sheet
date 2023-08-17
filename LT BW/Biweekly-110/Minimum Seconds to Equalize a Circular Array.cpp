//approach : Since circular array , make array repeated now for each element check the max time taken to conver elements between them and this is given 
//by the max elements between any 2 occurences of elements , now for all elements check which approach takes minimum time

int minimumSeconds(vector<int>& nums) {
        
        int ans=nums.size();
        int n=nums.size();
        
        map<int,int> last;
        
        for(int i=0;i<n;i++){
            nums.push_back(nums[i]);
            last[nums[i]]=-1;
        }
        
       n=nums.size(); //new size of array : 2*n
        
        map<int,int> mx_time;
        for(int i=0;i<n;i++){
           
            if(last[nums[i]]!=-1){
                // int ele=i-last[nums[i]]-1; //elements in between two occurences of nums[i]
                // int tot=(ele+1); // total time taken , +1 done for odd cases for eg. ele=3 then ele+1/2 gives 2 which is correct
                // tot=tot/2;
                
                int tot=(i-last[nums[i]]);
                tot/=2;
                mx_time[nums[i]]=max(mx_time[nums[i]],tot);
            }
            
            
            last[nums[i]]=i; //store-recent occurence
        }
        
        for(auto &it : mx_time){
            ans=min(ans,it.second);
            
        }
        
        return ans;
        
         
    }
