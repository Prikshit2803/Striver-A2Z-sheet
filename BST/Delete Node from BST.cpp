//we find the node to be deleted , then connect it's parent to it's left child whilst also connecting the biggest value on left child to be connected to the right child of node to be deleted

// Function to delete a node from BST.
Node * lastLeftnode(Node *root){
    if(root->right==NULL)
    return root;
    
    else 
    return lastLeftnode(root->right);
}

Node * helper(Node *root){
    if(root->left==NULL)
    return root->right; //hence root is deleted
    
    else if(root->right==NULL)
    return root->left;
    
    Node * r = root->right;
    
    Node * last=lastLeftnode(root->left); //last(biggest ) node on left portion
    
    
    last->right=r;
    
    return root->left; //hence root node deleted
}
Node *deleteNode(Node *root, int x) {
    
    if(root==NULL)
    return NULL;
    
    if(root->data==x){
        return helper(root);
    }
    
    Node * rt =root;
    
    while(root!=NULL){
        
        if(root->data>x){
            if(root->left!=NULL && root->left->data==x){
                root->left=helper(root->left); //root->left is the node to be deleted , the helper function will delete it
            
               break;
            }
            
            else
            root=root->left;
            
        }
        
        
        else{
            if(root->right!=NULL && root->right->data==x){
                root->right=helper(root->right); //root->left is the node to be deleted , the helper function will delete it
            
               break;
            }
            
            else
            root=root->right;
        }
    }
    
    return rt;
}
