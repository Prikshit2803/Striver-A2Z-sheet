// Store in hashmap the index of email if it doesnt exist , if it exists link the index(node) to the one that already contains email ,
// now create a 2-D array to store the mails with merging done so that all mails of nodes are put with parent node
//now create another 2-D array and if a node has merged mails then push name of person on that node and then push all the merged mails(should be sorted first )

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

class Solution{
  public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
       
       DisjointSet ds(accounts.size());
       map<string,int> mpp;
       
       //store emails in hashmap
       for(int i=0;i<accounts.size();i++){
           for(int j=1;j<accounts[i].size();j++){ //we start from j=1 as j=0 has name of person
               
               if(mpp.find(accounts[i][j])==mpp.end()){//email doesn't exits
                   mpp[accounts[i][j]]=i; // store at which row it exits
               }
               
               else{
                   ds.unionBySize(mpp[accounts[i][j]],i); //the original index becomes parent of i //unionByRank also works
               }
           }
       }
       
       vector<string> mergedmail[accounts.size()];
       //
       for(auto it: mpp){
           string mail=it.first;
           int node=ds.findUPar(it.second);
           
           mergedmail[node].push_back(mail); //merge all mails that have same parents
           }
           
           vector<vector<string>> ans;
           
           for(int i=0;i<accounts.size();i++){
               
               if(mergedmail[i].size()==0) continue;
               
               sort(mergedmail[i].begin(),mergedmail[i].end());
               
               vector<string> temp;
               
               temp.push_back(accounts[i][0]); //name of person pushed first
               
               for(auto it: mergedmail[i]){
                   temp.push_back(it);
               }
               
               ans.push_back(temp);
           }
       
       return ans;
    }
