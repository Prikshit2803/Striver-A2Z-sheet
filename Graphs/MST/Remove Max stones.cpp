//n-'no. of connected componenets' //componenets shouldn't be just one node
//rows and cols are treated as nodes
class DisjointSet {
    vector<int> rank, parent, size;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
    
class Solution {
  public:
    int maxRemove(vector<vector<int>>& stones, int n) {
        int maxrow=0,maxcol=0;
        
        int cnt=0; //keeps track of connected components
        for(auto it: stones){
            maxrow=max(maxrow,it[0]);
            maxcol=max(maxcol,it[1]);
        }
        
        
        DisjointSet ds(maxrow+maxcol+1); //+1 for safety reasons
        
        map<int,int> stoneNodes; //keep track of stanes that have have other stones
        for(auto it : stones){
            
            int r=it[0];
            int c=it[1]+maxrow+1;
            
            ds.unionByRank(r,c); //perform union  nodes r and c
            
            stoneNodes[r]=1; //it means r and c nodes have appeared and hence put into map
            stoneNodes[c]=1;
        }
        
        for(auto it : stoneNodes){
            if(ds.findUPar(it.first)==it.first)
            cnt++;
        }
        
        return n-cnt;
        
    }
