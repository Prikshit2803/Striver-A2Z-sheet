class Solution
{
public:

//Brian Kernighan's Algorithm  to count set bits : takes O(logn) time
 int cntsetbits(int n){
     int cnt=0;
     
     while(n){
         n&=(n-1);
         cnt++;
     }
     return cnt;
 }
 
// Maximum number of set bits in any integer  <=  N will be log2(N), 
//so the minimum value of i such that i + setBits(i) = N will be N - ceil(log2(N))

	int is_bleak(int n)
	{
	   //for(int i = n - 1; i >= n - ceil(log2(n)); i--){
	   //    int a=cntsetbits(i);
	   //    if(i+a==n)
	   //    return 0;
	   //}
	   
	   //The function ceil(log2(n)) essentially calculates the number of bits required to represent the number n
	   
	   for(int i = n - 1; i >= n - 32; i--){
	       if(i<0)
	       break;
	       int a=cntsetbits(i);
	       if(i+a==n)
	       return 0;
	   }
	   
	   return 1;
	}
};
