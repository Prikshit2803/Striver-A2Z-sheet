Node* solve(int pre[],int preStart,int preEnd,int in[],int inStart,int inEnd, map<int,queue<int>> &mp){
        if(preStart>preEnd || inStart>inEnd )
        return NULL;
        
        Node * root = new Node(pre[preStart]);
        
        int inRoot = mp[root->data].front(); //index of root in inorder
        
        mp[root->data].pop();
        
        int numsleft= inRoot - inStart; //numbers remaining on left of root in inorder
        
        
        
        root->left=solve(pre,preStart+1,preStart+numsleft,in,inStart,inRoot-1,mp);
        root->right=solve(pre,preStart+numsleft+1,preEnd,in,inRoot + 1,inEnd,mp);
        
        return root;
        
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        map<int,queue<int>> mp; //this done so that we can stire index od duplicate elements
        
        for(int i=0;i<n;i++)
        mp[in[i]].push(i); //store index of an element
        
        
        return solve(pre,0,n-1,in,0,n-1,mp);
