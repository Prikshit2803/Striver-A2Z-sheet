//Both soln use inorder
//2nd approach is from minimum absolute difference between two nodes in BST
//Video link : https://www.youtube.com/watch?v=o6N-12CtEO8
class Solution {
public:

// void inorder(TreeNode * root,vector<int> &ans){
//     if(!root)
//     return ;

//     inorder(root->left,ans);
//     ans.push_back(root->val);
//     inorder(root->right,ans);

// }

TreeNode * prev=NULL;
bool inorder(TreeNode * root){
    // if(!root)
    // return ;
      
      bool l=true,r=true;

      if(root->left)
    l= inorder(root->left);
     
     if(prev!=NULL){
        if(root->val <= prev->val)
          return false;
     }
     
      
      prev=root;

    if(root->right)
    r=inorder(root->right);

     if(l==false || r==false)
     return false;

     return true;

}
    bool isValidBST(TreeNode* root) {

    //     if(!root)
    //     return true;

    //     vector<int> ans;

    //    inorder(root,ans);

    //    for(int i=1;i<ans.size();i++){
    //          if(ans[i]<=ans[i-1])
    //          return false;
    //    }
    //    return true;
      
      if(root==NULL)
      return true;

      return inorder(root);
        
    }
};

//3rd approach
//here we take min and max
//if we move left max is updated to current node value and if we move right min changes to root value
 class Solution {
public:
    bool check(TreeNode* root,long int min,long int max){
        if(root==NULL)return true;
        if(root->val >min && root->val<max){
            bool left=check(root->left,min,root->val);
            bool right=check(root->right,root->val,max);
            return left && right;
        }
        return false;
    }
    bool isValidBST(TreeNode* root) {
        if(root==NULL)return true;
        if((root->left==NULL && root->right==NULL))return true;
        return check(root,LONG_MIN,LONG_MAX);
    }
};
