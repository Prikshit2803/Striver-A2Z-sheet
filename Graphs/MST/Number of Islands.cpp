//intuition : if a cell is not visited, mark it visited , increase cnt of islans, and check if an island
// exists in all four directions of it , if island exists and ultimate parent is not same reduce cnt and perform union
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
  
  bool isvalid(int r,int c,int n,int m){
      if(r>=0 && r<n && c>=0 && c<m)
      return 1;
      
      return 0;
  }
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
         
         DisjointSet ds(n*m);
         
         vector<int> ans;
         
         int cnt=0;
         
         vector<vector<int>> vis(n,vector<int>(m,0));
         
         for(auto it : operators){
             int row=it[0];
             int col=it[1];
             
             if(vis[row][col]==1){
                 ans.push_back(cnt);
                 continue;
             }
             
             vis[row][col]=1;
             cnt++;
             
             //check all four directions
            int dx[]={-1,0,1,0};
            int dy[]={0,1,0,-1};
            
            for(int i=0;i<4;i++){
                int adjr=row + dx[i];
                int adjc= col + dy[i];
                
                if(isvalid(adjr,adjc,n,m)){
                    if(vis[adjr][adjc]==1){ //it means adjnode has island
                        int node=row*m + col; //get cell/node number
                        int adjnode=adjr*m + adjc;
                        if(ds.findUPar(adjnode)!=ds.findUPar(node)){
                            cnt--;
                            ds.unionBySize(adjnode,node);
                        }
                    }
                }
            }
            
            ans.push_back(cnt); //enter number of island after all for directions explored
         }
         
         return ans;
    }
};
