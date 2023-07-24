//This is correct : In dijkstra's the initial shortest distances are  smallest as we take minimum priority queue
  int mod=1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        
        vector<pair<int,int>> adj[n];
        
        for(auto it : roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        pq.push({0,0}); //{distance,node}
        
        vector<int> dist(n,INT_MAX),ways(n,0);
        dist[0]=0;
        ways[0]=1;
        while(!pq.empty()){
            auto it=pq.top();
            
            pq.pop();
            
            int tm=it.first; //time
            int node=it.second;
            
            for(auto i: adj[node]){
                if(tm + i.second <dist[i.first]){
                    dist[i.first]=(tm + i.second)%mod;
                    pq.push({ dist[i.first],i.first});
                    
                    ways[i.first]=ways[node];
                }
                
               else if(tm + i.second == dist[i.first]){
                    ways[i.first] = (ways[i.first] + ways[node])%mod;
                }
            }
            
        }
        
         
   
        
        return ways[n-1]%mod;
    }
