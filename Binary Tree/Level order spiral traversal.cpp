//Function to return a list containing the level order traversal in spiral form.
vector<int> findSpiral(Node *root)
{
   queue<Node *> q;
   
   q.push(root);
   
   int flag=0;
   
   vector<int> ans;
   
   ans.push_back(root->data);
   
   while(!q.empty()){
        vector<int> ap;
       int sz=q.size();
       
       for(int i=0;i<sz;i++){
           Node * node=q.front();
           q.pop();
           
           if(node->left){
               q.push(node->left);
               ap.push_back(node->left->data);
           }
           
           if(node->right){
               q.push(node->right);
               ap.push_back(node->right->data);
           }
       }
       
       if(flag==1){
           reverse(ap.begin(),ap.end());
           flag=0;
       }
       
       else{
           flag=1;
       }
       
       ans.insert(ans.end(), ap.begin(), ap.end());
       
       
   }
   
   return ans;
}

