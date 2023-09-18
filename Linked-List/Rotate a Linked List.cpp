//find the element till which to rotate and make it's next to null,point last element to head and return element after the element to be rotated
class Solution
{
    public:
    //Function to rotate a linked list.
    Node* rotate(Node* head, int k)
    {
        
        int n=0;
        Node* cp=head;
        while(cp!=NULL){
            cp=cp->next;
            n++;
        }
        //cout<<n;
        
        if(k==n)
        return head;
       int cnt=k-1;
       Node *cur=head;
       while(cnt){
           cur=cur->next;
           cnt--;
       }
       Node* st=cur->next;
       
       Node* ls=head;
       
       while(ls->next!=NULL){
           ls=ls->next;
       }
       
       ls->next=head;
       
       cur->next=NULL;
       
       return st;
       
    }
};

//another soln
class Solution
{
    public:
    //Function to rotate a linked list.
    Node* rot(Node*curr,Node*last){
        Node*head;
        
        last->next=curr;
        head=curr->next;
        curr->next=NULL;
        
        return head;
    }
    Node* rotate(Node* head, int k)
    {
        Node*last=head;
        while(last->next!=NULL){
            last=last->next;
        }
        for(int i=0;i<k;i++){
            Node*temp=head;
            head=rot(head,last);
            last=temp;
        }
        return head;
    }
};
