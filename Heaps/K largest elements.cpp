//Intuition : create a min-heap and store only k values in it and if a value greater that pq.top() (minimum element) , pop the element and push the other one
//Function to return k largest elements from an array.
    vector<int> kLargest(int arr[], int n, int k)
    {
        priority_queue<int, vector<int>, greater<int>> pq; //min-heap
        
        vector<int> ans;
        
        int cnt=0;
        
        for(int i=0;i<n;i++){
            
            if(cnt==k){
                if(arr[i]>pq.top()){
                    pq.pop();
                    pq.push(arr[i]);
                }
                
                continue;
            }
            
            pq.push(arr[i]);
            cnt++;
        }
        
        while(!pq.empty()){
            ans.push_back(pq.top());
            pq.pop();
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
