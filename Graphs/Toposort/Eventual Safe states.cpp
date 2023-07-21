 //DFS
  bool dfs(int node,vector<int> adj[],vector<int> &vis,vector<int> &dfsvis,vector<int> &check){
      vis[node]=1;
      dfsvis[node]=1;
      
      
      for(auto it : adj[node]){
          if(!vis[it]){
              if(!dfs(it,adj,vis,dfsvis,check))
              return false; 
          }
          
          if(dfsvis[it])
          return false; //cycle detected or connected to cycle
      }
      
      check[node]=1;
      dfsvis[node]=0;
      return true;
      
  }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
       
       vector<int> vis(V,0),dfsvis(V,0),check(V,0);
       
       for(int i=0;i<V;i++){
           if(!vis[i])
           dfs(i,adj,vis,dfsvis,check);
       }
       
       vector<int> ans;
       
       for(int i=0;i<V;i++){
           if(check[i]==1)
           ans.push_back(i);
       }
       
       return ans;
    }

//BFS

vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
       
       vector<int> vis(V,0),dfsvis(V,0),indegree(V,0);
      
       //reverse all edges and perform topo sort : reversing is done so nodes with outdegre 0 become nodes with indegree 1 hence bfs topo sort can be applied
         
         queue<int> q;
         vector<int> radj[V],ans;
         
         for(int i=0;i<V;i++){
             for(auto it : adj[i]){
                 radj[it].push_back(i);
             }
         }
         
         for(int i=0;i<V;i++){
             for(auto it : radj[i]){
                indegree[it]++;
             }
         }
         
         
         for(int i=0;i<V;i++){
            
            if(indegree[i]==0)
                q.push(i);
             
         }
         
         
         while(!q.empty()){
             int node=q.front();
             q.pop();
             ans.push_back(node);
             
             for(auto it : radj[node]){
                 indegree[it]--;
                 if(indegree[it]==0)
                 q.push(it);
             }
         }
         
         sort(ans.begin(),ans.end());
         return ans;
    }
