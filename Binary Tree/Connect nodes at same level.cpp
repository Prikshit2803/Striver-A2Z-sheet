class Solution
{
    public:
    //Function to connect nodes at same level.
    //do level order traversal and store prev
    void connect(Node *root)
    {
      queue<Node *> q;
       
      q.push(root);
     
      
      while(!q.empty()){
          
          int size=q.size();
          
          Node * prev=NULL;
          for(int i=0;i<size;i++){
              
          Node * node=q.front();
          q.pop();
           
             if(prev!=NULL){
                 prev->nextRight=node;
             }
             
             prev=node;
             
             if(node->left!=NULL)
             q.push(node->left);
            
             if(node->right!=NULL)
             q.push(node->right);
        
        
          }
          
             
          }
            
    }    
      
};

//O(1) Space complexity
void connectNodes(BinaryTreeNode<int> *root) {

    // Keep the address of the first node of the current level.
    BinaryTreeNode<int> *startNode = root;

    while(startNode != NULL) {

        BinaryTreeNode<int> *ptr = startNode;
        BinaryTreeNode<int> *previous = NULL;
        startNode = NULL;
        
        // Traversing over nodes of current level and populating 'next' pointer of nodes of next level.
        while(ptr != NULL) {

            if(ptr->left != NULL) {

                if(previous != NULL) {
                    previous->next = ptr->left;
                }

                // Update 'startNode' with first node of next level if not already done.
                if(startNode == NULL) {
                    startNode = ptr->left;
                }

                // Update previous pointer
                previous = ptr->left;
            }

            if(ptr->right != NULL) {

                if(previous != NULL) {
                    previous->next = ptr->right;
                }

                // Update 'startNode' with first node of next level if not already done.
                if(startNode == NULL) {
                    startNode = ptr->right;
                }

                // Update previous pointer.
                previous = ptr->right;
            }

            ptr = ptr->next;
        }
    }
}
