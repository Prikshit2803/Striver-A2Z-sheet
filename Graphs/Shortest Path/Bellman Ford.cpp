  //Similar to Dijkstra's excpet N-1 iterations and detects -ve cycle
    //negative weights are allowed but not negative cycle
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        
        vector<int> dist(V,1e8);
        
        dist[S]=0;
        
        for(int i=0;i<V;i++){
            for(auto it : edges){
                int u=it[0];
                int v=it[1];
                int wt=it[2];
                
                
                if(dist[u]!=1e8 && dist[u]+wt<dist[v] ){ //this means u has been visited 
                    
                        dist[v]=dist[u]+wt;
                    
                }
            }
        }
        
        //Nth iteration to detect negative cycle
        
        for(auto it : edges){
                int u=it[0];
                int v=it[1];
                int wt=it[2];
                
                
                if(dist[u]!=1e8){
                    if(dist[u]+wt<dist[v]){
                        
                        vector<int> ans(1,-1);
                        return ans;
                    }
                }
            }
            
            
            return dist;
    }
