//lINk : https://www.youtube.com/watch?v=IhIpreSnEhI

//Approach : For each thief we go from leftmost to rightmost in a greddy way and if thief found we
//go to next police 
//Intuition : Leftmost thief can be caught for a police then max ans
    
   
    int catchThieves(char arr[], int n, int k) 
    {
        int ans=0;
        for(int i=0;i<n;i++){
            
            if(arr[i]=='P'){
            int j=max(0,i-k); //so that we do go out of index bound
            
            int flag=0;
            
            //left side search
            for(int run=j;run<i;run++){
                if(arr[run]=='T'){
                    ans++;
                    arr[run]='C'; //thief caught
                    flag=1;
                    break;
                }
            }
            
            if(flag==0){ //i.e. no thief found on left side
            j=min(i+k,n-1);
            for(int run=i+1;run<=j;run++){
                if(arr[run]=='T'){
                    ans++;
                    arr[run]='C'; //thief caught
                    flag=1;
                    break;
                }
            }
            
         }
        }
        
        
        }
        
        return ans;
    }
