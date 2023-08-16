//O(2N) and SC: O(N)
    void inorder(struct Node *root, vector<int> &in){
        if(root==NULL)
        return;
        
        inorder(root->left,in);
        in.push_back(root->data);
        inorder(root->right,in);
    }
    int isPairPresent(struct Node *root, int target)
    {
       
        
        vector<int> in;
         inorder(root,in); 
        
        int ans=0;
        
        int i=0,j=in.size()-1;
        
        while(i<j){
            if(in[i]+in[j]==target){
           return 1;
            }
            
            else if(in[i]+in[j]>target)
            j--;
            
            else
            i++;
        }
        
        return  ans;
    }

