//we find opeartions to make string of form : 11...1 00..00 as only then no 01 exists
//Brute-force is the correct soln here
    int secondsToRemoveOccurrences(string s) {
         int flag=0;
         int cnt=0;
        
         
         while(true){
             flag=0;
        for(int i=0;i<s.length()-1;i++){ 
            if(s[i]=='0' && s[i+1]=='1'){
                s[i]='1';
                s[i+1]='0';

                i++; // this also  gets incremented again on for loop execution  , done to avoid case where 
                //o11 becomes 101 , this 01 should be changed in next loop
                flag=1;
            }    
        }
        
        if(flag==0) //no 01 exsits in string
            break;

            else
            cnt++; //1 more sec added to answer

         }
        return cnt;

    }
