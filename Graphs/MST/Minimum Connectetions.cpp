//find extraedges and number of connected components 
  int findparent(int node,vector<int> &par){
        
        if(par[node]==node)
        return node;
        
        else
        return par[node]=findparent(par[node],par);
    }
    
    
    void unionbyrank(int u,int v,vector<int> &rank,vector<int> &par){
        
        int u_par=findparent(u,par);
        int v_par=findparent(v,par);
        
        if(u_par==v_par)
        return;
        
        else if(rank[u_par]>rank[v_par]){
            par[v_par]=u_par;
        }
        
         else if(rank[u_par]<rank[v_par]){
            par[u_par]=v_par;
        }
        
        
        else{
            par[v_par]=u_par;
            rank[u_par]++;
        }
    }
        int minimumConnections(int n , vector<vector<int>> &connections)
        {
            
            vector<int> par(n),rank(n);
            for(int i=0;i<n;i++){
                par[i]=i;
                  rank[i]=0;
            }
            
            int cntedges=0; //keeps count of extra edges and cnt of cn=onnected. components
            for(auto it : connections){
                int u=it[0];
                int v=it[1];
                
                if(findparent(u,par)==findparent(v,par))
                cntedges++;
                
                else
                unionbyrank(u,v,rank,par);
            }
            
            
            int cntc=0;
            for(int i=0;i<n;i++){
                if(par[i]==i)
                cntc++;
            }
            
            int ans=cntc-1; 
            
            if(cntedges>=ans)
            return ans;
            
            else
            return -1;
        }
