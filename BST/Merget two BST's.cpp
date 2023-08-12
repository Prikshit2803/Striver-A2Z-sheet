//Intuition ; store inorder traversal in two arrays then merge the two sorted arrays

class Solution
{
    public:
    //Function to return a list of integers denoting the node 
    //values of both the BST in a sorted order.
    
     void inorder(struct Node *root, vector<int> &in){
        if(root==NULL)
        return;
        
        inorder(root->left,in);
        in.push_back(root->data);
        inorder(root->right,in);
    }
    
    vector<int> merge(Node *root1, Node *root2)
    {
       vector<int> r1,r2;
       
    inorder(root1,r1);
     inorder(root2,r2);
       
       vector<int> ans;
       
       int i=0,j=0;
       int n=r1.size();
       int m=r2.size();
       
       while(i<n && j<m){
           if(r1[i]<r2[j]){
               ans.push_back(r1[i]);
               i++;
           }
           
           else{
                ans.push_back(r2[j]);
               j++;
           }
       }
       
       while(i<n){
           ans.push_back(r1[i]);
               i++;
       }
       
       while(j<m){
            ans.push_back(r2[j]);
               j++;
       }
       
       return ans;
    }
