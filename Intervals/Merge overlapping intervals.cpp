//sort the array : now if ans vector is empty or interval is greater than latest interval in ans 
//then push the interval into ans .. else update therange of latest interval in ans vector
//video link :https://www.youtube.com/watch?v=IexN60k62jo&t=778s
    vector<vector<int>> overlappedInterval(vector<vector<int>>& arr) {
         
         sort(arr.begin(),arr.end());
         
         int n=arr.size();
         
          vector<vector<int>> ans;
         
        
         for(int i=0;i<n;i++){
             
             if(ans.empty() || arr[i][0] > ans.back()[1]){ //either ans empty or interval greater than previous interval
                 ans.push_back(arr[i]);
             }
             
             else{ //intervals are overlapping
                 
                 ans.back()[1]=max(ans.back()[1],arr[i][1]);
             }
             
         }
         
         
         return ans;
    }
