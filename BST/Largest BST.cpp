//intuition : it is BST if node is greater than largest value on left and smaller than smallest value on right and we do this bottom up
class NodeValue{
    public:
    int minNode,maxNode,maxSize;
    
    NodeValue(int minNode,int maxNode,int maxSize){
        this->minNode=minNode;
         this->maxNode=maxNode;
          this->maxSize=maxSize;
    }
};

class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    
    NodeValue solve(Node * root){
        if(!root){
            return  NodeValue(INT_MAX,INT_MIN,0); //null node so we ensure that every node has value greater than minNode and every node is less than maxNode
        }
        
        NodeValue left= solve(root->left);
        NodeValue right=solve(root->right); //postorder traversal 
        
        
        if(left.maxNode<root->data && root->data<right.minNode){//it means it is a BST
            return  NodeValue(min(root->data,left.minNode),max(root->data,right.maxNode),1+left.maxSize+right.maxSize);
        }
        
        else{
            return  NodeValue(INT_MIN,INT_MAX,max(left.maxSize,right.maxSize));//it means not a bST so we takle maximum and minimum values so no other bst can be built from this and we take the max size of bST so far
        }
    } 
    int largestBst(Node *root)
    {
    	return solve(root).maxSize;
    }
};
