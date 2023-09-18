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
