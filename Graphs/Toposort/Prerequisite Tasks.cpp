bool dfs(int node,vector<int> adj[],vector<int> &vis,vector<int> &dfsvis){
    //detects cycle
    vis[node]=1;
    dfsvis[node]=1;
    
    for(auto it : adj[node]){
        if(!vis[it]){
            if(!dfs(it,adj,vis,dfsvis))
            return false;
        }
        
        if(vis[it] && dfsvis[it])
        return false;
    }
    
    dfsvis[node]=0;
    return true;
    
}
	bool isPossible(int N,int P, vector<pair<int, int> >& pre) {
	   
	   vector<int> adj[N],vis(N,0),dfsvis(N,0);
	   
	   for(int i=0;i<P;i++){
	       adj[pre[i].second].push_back(pre[i].first);
	   }
	   
	    for(int i=0;i<N;i++){
	      if(!vis[i]){
	          if(!dfs(i,adj,vis,dfsvis))
	          return false;
	      }
	   }
	   
	   return true;
	}
