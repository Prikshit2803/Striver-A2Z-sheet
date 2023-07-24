  int mod=1e5;
  
  //apply dijikstra's
    int minimumMultiplications(vector<int>& arr, int start, int end) {
       
       priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;//min-heap
       
       pq.push({0,start}); //{steps,start}
       
       vector<int> dist(100000,1e9); //as all possible values possible from 0 till 9999 as mod=1e5
       
       dist[start]=0;
       
       while(!pq.empty()){
           auto it=pq.top();
           pq.pop();
           
           int step=it.first;
           int node=it.second;
           
           if(node==end)
           return step;
           
           for(int i=0;i<arr.size();i++){
               
               int a=(node*arr[i])%mod;
               
               if(step+1<dist[a]){
                   dist[a]=step+1;
                   
                   pq.push({dist[a],a});
               }
           }
       }
       
       return -1;
    }
