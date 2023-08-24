//Video link: https://www.youtube.com/watch?v=o6N-12CtEO8

//recursive inorder but without storing inorder in a vector as we only need previous elmenet 
    //in inorder (Sorted) manner
    //store the previous element everytime u move right(towards a bigger node)
// Intuition : minimum difference would always be one among difference between consecutive elements in sorted array 

Node * prev=NULL; 
    void inorder(Node * root, int &ans){
        
        if(root->left)
        inorder(root->left,ans);
        
        if(prev!=NULL)
          ans=min(ans,root->data-prev->data);
          
          prev=root;
          
          if(root->right)
          inorder(root->right,ans);
    }
    int absolute_diff(Node *root)
    {
        int ans=INT_MAX;
        inorder(root,ans);
        
        return ans;
    }
