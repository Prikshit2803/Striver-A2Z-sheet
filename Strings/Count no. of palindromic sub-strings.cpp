//for each substring check if it is a palindrome by using two pointers

int CountPS(char s[], int N)
{
    int cnt=0;
    
    for(int i=0;i<N-1;i++){
        for(int j=i+1;j<N;j++){
            
            if(s[i]==s[j]){
                int a=i+1;
                int b=j-1;
                int flag=1;
                
                while(a<b){
                    if(s[a]!=s[b]){
                        flag=0;
                        break;
                    }
                    
                    a++;
                    b--;
                }
                
                if(flag==1)
                cnt++;
            }
        }
    }
    
    
    return cnt;
    
    
}
