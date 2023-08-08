	int findparent(int node, vector<int> &par){
	    if(par[node]==node)
	    return node; //ultimate parent as it is parent of itself
	    
	    else
	    return par[node]=findparent(par[node],par); //this step does path compression
	}
	
	void unionbyrank(int u,int v, vector<int> &rank, vector<int> &par){
	    int u_par=findparent(u,par);
	    int v_par=findparent(v,par); //find ultimate parent of both 
	    
	    if(u_par==v_par)
	    return;
	    
	    else if(rank[u_par]>rank[v_par]){
	        par[v_par]=u_par;
	       }
	       
	   else if(rank[u_par]<rank[v_par]){
	        par[u_par]=v_par;
	       }
	       
	       else if(rank[u_par]==rank[v_par]){
	            par[v_par]=u_par;
	            rank[u_par]++;
	       }
	}
	
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int,pair<int,int>>> edges;
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                int adjnode=it[0];
                int wt=it[1];
                int node=i;
                
                edges.push_back({wt,{node,adjnode}});
            }
        }
        
        sort(edges.begin(),edges.end());
        
        
         vector<int> par(V);
        vector<int> rank(V);
        for(int i = 0; i < V; i++) {
            par[i] = i;
            rank[i] = 0;
        }
        
        int mstwt=0;
        
        for(auto it : edges){
            int wt=it.first;
            int u=it.second.first;
            int v=it.second.second;
            
            if(findparent(u,par)!=findparent(v,par)){
                mstwt+=wt;
                unionbyrank(u,v,rank,par);
            }
        }
        
        return mstwt;
    }
