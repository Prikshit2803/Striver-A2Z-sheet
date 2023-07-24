//Function to return list containing elements of right view of binary tree.
    //using BFS
    vector<int> rightView(Node *root)
    {
      queue<Node *> q;
      vector<int> ans;
      ans.push_back(root->data);
      
      q.push(root);
      
      while(!q.empty()){
          int sz=q.size();
          int ele=-1;
          for(int i=0;i<sz;i++){
              
            Node * node=q.front();
           q.pop();
          
              if(node->left){
                  q.push(node->left);
                  ele=node->left->data;
              }
              
              if(node->right){
                  q.push(node->right);
                  ele=node->right->data;
              }
          }
         
         if(ele!=-1)
         ans.push_back(ele);
    
      }

      //Another similar approach
      vector<int> rightView(Node *root)
    {
       // Your Code here
       vector<int> v;
       queue<Node*>q;
       q.push(root);
       while(!q.empty()){
           int ss= q.size();
           for(int i=0;i<ss;i++){
                Node* top= q.front();
                q.pop();
                if(i==ss-1){
                    v.push_back(top->data);
                }
               
                if(top->left) q.push(top->left);
                if(top->right) q.push(top->right);
           }
       }
       return v;
    }


      
      return ans;
    }
