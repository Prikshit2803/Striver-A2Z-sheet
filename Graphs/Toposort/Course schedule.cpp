//DFS soln to detect cycle and do topo sort
void dfs(int node,vector<int> adj[],vector<int> &vis,stack<int> &st,vector<int>&dfsVis){
      //detects cycle in graph and also does topo sort both using dfs
      vis[node]=1;
      dfsVis[node] = 1;
      
      for(auto it : adj[node]){
          if(!vis[it]){
              dfs(it,adj,vis,st,dfsVis);
          }
          
          if(vis[it] && dfsVis[it]){
                return; //it means don't add this element(node) to stack as it is part of cycle hence size of ans vector!=n
            }
      }
      
      dfsVis[node] = 0;
      st.push(node);
  }
    vector<int> findOrder(int n, int m, vector<vector<int>> pre) 
    {
        vector<int> ans,adj[n],vis(n,0);
        vector<int> dfsVis(n,0);
        
        stack<int> st;
        
        for(int i=0;i<m;i++){
            adj[pre[i][1]].push_back(pre[i][0]); //as edge from pre[i][1] to pre[i][0]
        }
        
      //now apply topo sort
      
      for(int i=0;i<n;i++){
          if(!vis[i]){
              dfs(i,adj,vis,st,dfsVis);
          }
      }
      
      while(!st.empty()){
        //   cout<<st.top()<<".";
          ans.push_back(st.top());
          st.pop();
      }
      
      //reverse(ans.begin(),ans.end());
       
        if(ans.size() == n) return ans;
        
        else
        return {};
       
    }

//BFS approach
vector<int> findOrder(int n, int m, vector<vector<int>> pre) 
    {
        vector<int> ans,adj[n],Indeg(n,0);
        vector<int> dfsVis(n,0);
        
        queue<int> q;
        
        for(int i=0;i<m;i++){
            adj[pre[i][1]].push_back(pre[i][0]); //as edge from pre[i][1] to pre[i][0]
        }
        
      //now apply topo sort bfs approach
      
      for(int i=0;i<n;i++){
         for(auto it : adj[i]){
             Indeg[it]++;
         }
      }
      
       for(int i=0;i<n;i++){
         if(Indeg[i]==0)
         q.push(i);
      }
      
      while(!q.empty()){
          
          int node=q.front();
          q.pop();
          ans.push_back(node);
          
          for(auto it:adj[node]){
              Indeg[it]--;
              
              if(Indeg[it]==0)
              q.push(it);
              
              }
      }
      
     
        if(ans.size() == n) return ans;
        
        else
        return {};
       
    }
