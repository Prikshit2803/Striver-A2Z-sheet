 // returns the inorder successor of the Node x in BST (rooted at 'root')
   
    //intuition : to get first larger value then x
    Node * inOrderSuccessor(Node *root, Node *x)
    {
        Node * ans;
        while(root!=NULL){
            if(root->data<=x->data)
            root=root->right; //as root value is smaller so we go right
            
            else{
                ans=root; 
                root=root->left; //it means root is greater so we move leftwards 
            }
        }
        
        return ans;
    }
