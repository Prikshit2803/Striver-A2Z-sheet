//Sort pairs and is start < end of prev added interval , change the end and if start > end of prev added interval add arr[i] to ans

 vector<vector<int>> overlappedInterval(vector<vector<int>>& arr) {
    
    vector<vector<int>> ans;
    sort(arr.begin(),arr.end());
    
    for(int i=0;i<arr.size();i++){
        if(ans.empty()|| arr[i][0] > ans.back()[1]){ //ans empty or start of new interval is greater than end of previously added to 'ans' vector
        ans.push_back(arr[i]);
            
        }
        
        else{ //start of ith element is lesser than or equal to  end prev added interval to 'ans'
            ans.back()[1]=max(arr[i][1],ans.back()[1]);
        }
        
        
    }
     
     return ans;
    }
