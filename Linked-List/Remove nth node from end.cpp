//find cnt and then maintain prev and move till cnt-n and then remove node by skipping cur(node to be deleted) and handle two edge cases

ListNode* removeNthFromEnd(ListNode* head, int n) {
int cnt=0;
           
           ListNode * cur=head;
           while(cur){
               cnt++;
               cur=cur->next;
           }
           
           cur=head;
           int c=cnt-n;

           if(cnt==1 && n==1)
           return NULL;
      
       ListNode* prev=NULL;
           if(cnt==n){
               head=head->next;

               return head;
           }
           
           if(n>cnt)
           return head;
           
          

           
           while(c){
               c--;
               prev=cur;
               cur=cur->next;
           }
           
           //int ans=cur->data;
           prev->next=cur->next;
           
           return head;
    }
