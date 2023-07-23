void   dfstopo(int i,vector<pair<int,int>> adj[],vector<int> &vis,stack<int> &st){
            vis[i]=1;
            
            for(auto it: adj[i]){
                if(!vis[it.first]){
                    dfstopo(it.first,adj,vis,st);
                }
            }
            
            st.push(i);
        }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        
        vector<int> vis(N,0);
        stack<int> st;
        
        vector<pair<int,int>> adj[N];
        
        for(auto it : edges){
            adj[it[0]].push_back({it[1],it[2]});
        }
        
        
        for(int i=0;i<N;i++){
            if(!vis[i])
            dfstopo(i,adj,vis,st);
        }
        
        vector<int> dist(N,1e9);
        dist[0]=0; //src
        
        while(!st.empty()){
            int node=st.top();
            st.pop();
            
            for(auto it: adj[node]){
                if(dist[node]+it.second<dist[it.first]){
                    dist[it.first]=dist[node]+it.second;
                }
            }
        }
        
        for(int i=0;i<N;i++){
            if(dist[i]==1e9)
            dist[i]=-1;
        }
        
        return dist;
    }
