//intuition : next : tells the next node in inorder traversal and hasnext tells if there is a next node
//we do iteratice inorder, we push root and all it's left then when next is called we pop it it and push all left of it's right node

//video link : https://www.youtube.com/watch?v=D2jMcmxU4bs

class BSTIterator {
    private: stack<TreeNode *> st;
public:
    BSTIterator(TreeNode* root) {
        pushAll(root); //iterative inorder
    }
    
    int next() {
        
        TreeNode * temp=st.top();

        st.pop();
        pushAll(temp->right); //iterative inorder

        return temp->val;
    }
    
    bool hasNext() {
        
        if(st.empty())
        return false;

        return true;
    }

    private:
    void pushAll(TreeNode* node){ //pushes all value left
              
              while(node!=NULL){
                  st.push(node);
                  node=node->left;
              }
    }
};
