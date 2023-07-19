int isSumProperty(Node *root)
    {
     //bfs
     
     queue<Node *> q;
     
     q.push(root);
     
     while(!q.empty()){
         int a=0,b=0;
         Node * node=q.front();
         q.pop();
         
         if(node->left==NULL && node->right==NULL)
         continue;
         
         if(node->left!=NULL){
             a=node->left->data;
             q.push(node->left);
         }
         
         if(node->right!=NULL){
             b=node->right->data;
             q.push(node->right);
         }
         
         if(node->data!=a+b)
         return 0;
         
         
         
     }
     
     return 1;
    }
