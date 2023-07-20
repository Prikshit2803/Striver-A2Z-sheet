// All solutions in the comment section are bad. Here's how its done easily.

// During BFS add left and right child irrespective of wether its NULL or not. Stop BFS when Q.front() = NULL i.e First NULL node is encountered, and examine the queue.

// The Tree is Complete if no NON NULL node appears in the queue in the middle of null nodes.

// Even if one NON NULL node appears in the queue after NULL nodes then the tree is not complete.

  bool isCompleteBT(Node* root)
    {
        queue<Node*> Q;
        
        Q.push(root);
        
        while(!Q.empty() && Q.front() != NULL)
        {
            Node* curr = Q.front();
            Q.pop();
            Q.push(curr->left);
            Q.push(curr->right);
        }
        
        while(!Q.empty())
        {
            if(Q.front() != NULL)return false;
            Q.pop();
        }
        return true;
    }

//Once flag=false and a node is encountered we return false

 bool isCompleteBT(Node* root){
        //code here
       if(root==NULL) return 1;
       bool flag = true;
       queue<Node*> q;
       q.push(root);
       while(!q.empty()){
           int n = q.size();
           while(n--)
           {
               Node* temp = q.front();
               q.pop();
               
               if(temp->left){
                   if(flag == false)
                   return false;
                   q.push(temp->left);
               }
               else flag=false;
               
               if(temp->right)
               {
                   if(flag==false) return false;
                   q.push(temp->right);
               }
               else flag = false;
           }
           
       }
       return true;
    }
