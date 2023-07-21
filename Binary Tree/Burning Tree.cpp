  //bfs to traverse from target node
  int solve(Node* start, map<Node *,Node *> &mp){
       
        queue<Node *> q;
       int maxi=0;
       map<Node *,int> vis;
       
       q.push(start);
       
       
       while(!q.empty()){
           int sz=q.size(); //perform equal to queue size as all non-connected nodes burn together
           
           int fl=0;
           
           for(int i=0;i<sz;i++){
               Node * node=q.front();
               vis[node]=1;
               q.pop();
               
               if(node->left && !vis[node->left]){
                   fl=1;
                   q.push(node->left);
               }
               
               if(node->right && !vis[node->right]){
                   fl=1;
                   q.push(node->right);
               }
               
               if(mp[node] && !vis[mp[node]] ) //mp[node] means parent exists or not
               {
                   fl=1;
                    q.push(mp[node]);
               }
           }
           
           if(fl==1) //at least one node got burned
           maxi++;
           
       }
      
      return maxi;
  }
  
  Node * mapparent(Node* root,map<Node *,Node *> &mp,int target){
      queue<Node *> q;
     
     Node * res;
      q.push(root);
      
      while(!q.empty()){
          
          Node * node=q.front();
          q.pop();
          if(node->data==target)
          res=node;
          
          
          if(node->left){
              mp[node->left]=node;
              q.push(node->left);
          }
          
          if(node->right){
              mp[node->right]=node;
              q.push(node->right);
          }
      }
      
      return res;
  }
  
  //dfs to find max height from target node 
  int height(Node* root ,   map<Node *,Node *> &mp ,  map<Node*, int>&vis)
{
    if(!root)
    return 0;
    
    vis[root]=1;
    
    int lh= INT_MIN;
     int rh= INT_MIN;
      int ph= INT_MIN;
    
    if(!vis[root->left])
     lh= height(root->left, mp, vis);
      if(!vis[root->right])
        rh= height(root->right, mp, vis);
          if(!vis[mp[root]])
        ph= height(mp[root] , mp, vis);
    
    return  max(ph, max(lh,rh)) +1;
}
    int minTime(Node* root, int target) 
    {
       map<Node *,Node *> mp;
       Node *start=mapparent(root,mp,target);
        map<Node *,int> vis;
       
    //   int ans = solve(start,mp);
    //   return ans;  //this also works
    
    int ans = height(start,mp,vis);
       
       return ans-1; //this is done as in final return we add +!
    }
