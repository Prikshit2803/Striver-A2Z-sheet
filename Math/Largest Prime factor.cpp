//prime factor lies from 2 to sqrt(N)
long long int largestPrimeFactor(int N){
       
       long long int ans=0;
       for(long long int i=2;i<=sqrt(N);i++){ //considers all numbers that can be prime factors
           while(N%i==0){
              ans=max(ans,i);
              N=N/i;
              
           }
       }
       
       if(N>1) //it means remaining N is prime and greater than sqrt(N) eg. 29 ,58 7 ,5 etc.
       ans=N;
       
       
       return ans;
    }
