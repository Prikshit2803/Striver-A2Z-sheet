// we do a reverse post-order(RLN)as answer must be in pre-order form
    Node * prev=NULL;
    
    void flatten(Node *root)
    {
        if(root==NULL)
        return;
        
        flatten(root->right);
        flatten(root->left);
        
        root->right=prev;
        root->left=NULL;
        
        prev=root;
        
        
    }

//Morris trvaersal - preorder
void flatten(Node *root)
    {
        //code here
        Node *curr = root;
        while(curr != NULL){
            if(curr -> left){
                Node *pred = curr -> left;
                while(pred -> right)
                     pred = pred -> right;  //it is element after root in pre-order
                pred -> right = curr -> right;
                curr -> right = curr -> left;
                curr -> left = NULL;
            }
            curr = curr -> right;
        }
    }
//stack
void flatten(Node *root)
    {
        //code here
        if(root==NULL)
            return;
        stack<Node*> st;
        st.push(root);
        while(!st.empty())
        {
            Node* cur=st.top();
            st.pop();
            if(root->right)
                st.push(root->right);
            if(root->left)
                st.push(root->left);
            if(!st.empty())
                cur->right=st.top();
            cur->left=NULL;
        }
    }
