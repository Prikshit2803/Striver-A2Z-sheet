//Without merge sort but works
 vector<int> ans;
        
       Node * cur=head;
       
       while(cur){
           ans.push_back(cur->data);
           cur=cur->next;
       }
       
       sort(ans.begin(),ans.end());
       
       Node * l = new Node(ans[0]);
       
       Node * dummy=l;
       
       for(int i=1;i<ans.size();i++){
           
           Node * p = new Node(ans[i]);
           l->next=p;
           l=l->next;
       }
       
       return dummy;

//using merge sort
//Intuition : find mid element using fast and slow approach , now divide list into  two left and right list and sort them thorugh recursion and 
//merge them 

class Solution{
  public:
  
  Node * findmid(Node* head){
      Node * slow=head;
      Node * fast=head->next;
      
      while(fast!=NULL && fast->next!=NULL){
          slow=slow->next;
          fast=fast->next->next;
      }
      
      return slow;
  }
  
  
  Node * merge(Node * left,Node * right){
      
      if(left==NULL)
      return right;
      
      if(right==NULL)
      return left;
      
      Node * ans=new Node(-1);
      Node * temp=ans;
      
      while(left!=NULL && right!=NULL){
          
          if(left->data<right->data){
              temp->next=left;
              temp=left;
              left=left->next;
          }
          
          else{
              
              temp->next=right;
              temp=right;
              right=right->next;
              
          }
      }
      
      while(left!=NULL){
          temp->next=left;
              temp=left;
              left=left->next;
      }
      
      while(right!=NULL){
          
          temp->next=right;
              temp=right;
              right=right->next;
      }
      
    ans= ans->next;
    
    return ans;
  }
    //Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
       
       //base-condition 
       if(head==NULL||head->next==NULL)
       return head;
       
       
       //divide into two linked lists
       
       Node * mid=findmid(head);
       
       Node * left=head;
       Node * right=mid->next;
       mid->next=NULL;
       
       //recursive calls to sort
       left=mergeSort(left);
       right=mergeSort(right);
       
       //now we megre the sorted left and right
       Node * ans = merge(left,right);
       
       return ans;
       
    }
};
