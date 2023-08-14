  int diffSum(int n,int m,int arr[])
    {
        priority_queue<int> pq1;//max-heap
        
         priority_queue<int,vector<int>,greater<int>> pq2; //min-heap--for max elements
         
         int cnt=0;
         
         
         for(int i=0;i<n;i++){
             
             if(cnt==m){
                 if(arr[i]>pq2.top()){
                     pq2.pop();
                     pq2.push(arr[i]);
                 }
                 
                 if(arr[i]<pq1.top()){
                     pq1.pop();
                     pq1.push(arr[i]);
                 }
             }
             
             else{
                 cnt++;
                 pq1.push(arr[i]);
                 pq2.push(arr[i]);
             }
             
         }
         
         int sum1=0,sum2=0;
         
         while(!pq2.empty()){ //pq1 and pq2 of same size m
             sum1+=pq2.top();
             pq2.pop();
             
             sum2+=pq1.top();
             pq1.pop();
         }
        
        return sum1-sum2;
    }

//Other soln
class Solution{
public:

    int diffSum(int n,int m,int arr[])
    {
        //write your code here
        
        int sum1=0,sum2=0;
        
        sort(arr,arr+n);
        
        for(int i=0;i<m;i++)
        {
            sum1+=arr[i];
            sum2+=arr[n-i-1];
        }
        return sum2-sum1;
    }
};
