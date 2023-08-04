 int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<pair<int,int> ,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        vector<int> vis(V,0);
        
        pq.push({0,0}); //distance, node 
        
        
        int sum=0;
        
       
        
        while(!pq.empty()){
            
            auto i = pq.top();
            pq.pop();
            
            int wt=i.first;
            int node=i.second;
            
            if(vis[node]==1) continue;
            
            sum+=wt;
            
           vis[node]=1;
                for(auto it : adj[node]){
                    int adjnode=it[0];
                    int edw=it[1];
                    if(!vis[adjnode]){
                        pq.push({edw,adjnode});
                    }
                }
            
        }
        
        return sum;
    }
