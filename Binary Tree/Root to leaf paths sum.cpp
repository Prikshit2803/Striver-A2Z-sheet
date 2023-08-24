//Both methods work : Intuition : store prev values and if leaf node , add to prev and return
class Solution {
public:

//int ans=0;
    //  void solve(TreeNode * node, int prev){
    //         if(node->left==NULL && node->right==NULL){
    //           ans+=prev*10 + node->val;
    //           return ;
    //         }

             
    //          prev=prev*10 + node->val;

    //         if(node->left)
    //         solve(node->left,prev);

    //         if(node->right)
    //         solve(node->right,prev);

    //  }

     int solve(TreeNode * node, int prev){
            if(node->left==NULL && node->right==NULL){
              return prev*10 + node->val;
            }

             
             prev=prev*10 + node->val;
             int l=0,r=0;
            if(node->left)
             l=solve(node->left,prev);

            if(node->right)
             r=solve(node->right,prev);

            return l+r;

     }
    int sumNumbers(TreeNode* root) {
        
        return solve(root,0);

        //return ans;
    }
};
