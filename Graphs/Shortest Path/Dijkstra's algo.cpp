//Priority queue method : queue can also be used but that takes more time
vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
         priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //min-heap
         
         pq.push({0,S});
         
         vector<int> dist(V,1e9);
         
         dist[S]=0;
         
         while(!pq.empty()){
             
             auto i=pq.top();
             pq.pop();
             
             int node=i.second;
             int w=i.first; //node distance
             
             for(auto it: adj[node]){
                 if(w+it[1]<dist[it[0]]){
                     dist[it[0]]=w+it[1];
                     pq.push({dist[it[0]],it[0]});
                 }
             }
         }
         
         return dist;
    }
