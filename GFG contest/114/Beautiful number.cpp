// Given n, check if it is a beautiful number or not. 
// You will have to follow a process to determine if a number is beautiful or not:

// Starting with the given number (guaranteed to be an integer), replace the number by the sum of the squares of its digits.
// The process continues until the number equals 1, or it loops endlessly in a cycle which does not include 1.
// Numbers for which this process ends in 1 are considered beautiful.

bool beautifulNumber(int n) {
       long long int N=n;
        
        map<long long int,long long int> mp;
        mp[n]++;
        
        while(1){
            long long int sum=0;
            while(N){
                int i=N%10;
                N=N/10;
                sum+=i*i;
                 }
                 
                 if(sum==1)
                 return 1;
                 
                 else if(mp[sum]==1){
                    return 0; 
                 }
                 
                 
                 else{
                     mp[sum]++;
                   N=sum;  
                 }
                 
        }
    }
