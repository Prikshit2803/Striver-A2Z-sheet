# You are playing the following Nim Game with your friend:

# Initially, there is a heap of stones on the table.
# You and your friend will alternate taking turns, and you go first.
# On each turn, the person whose turn it is will remove 1 to 3 stones from the heap.
# The one who removes the last stone is the winner.
# Given n, the number of stones in the heap, return true if you can win the game assuming both you and your friend play optimally, otherwise return false.
 bool canWinNim(int n) {
        
         if(n==1||n==2||n==3)
            return true;
        
        if(n==4)
            return false;
        
       // vector<long long> dp(n+2,0);
        
        // dp[1]=1; //if first person takes turn and 1 stone left
        // dp[2]=1;
        // dp[3]=1;
        // dp[4]=0;
       
        
//        int p1=1,p2=1,p3=1,p4=0,curr=0;
        
        
        
//         for(long long i=5;i<=n;i++){
            
//             // if(dp[i-1]==0||dp[i-2]==0||dp[i-3]==0)
//             //     dp[i]=1;
            
//             if(p2==0||p3==0||p4==0)
//                 curr=1;
//             else
//                 curr=0;
            
//             p2=p3;
//             p3=p4;
//             p4=curr;
//         }
        
//         if(p4==1)
//             return true;
        
//         else
//             return false;
        
        if((n-1)%4==0 ||(n-2)%4==0 || (n-3)%4==0)
            return true;
        
        return false;
    }

//both approaches work : dp approach gives TLE
