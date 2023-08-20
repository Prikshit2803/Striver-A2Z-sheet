 //we use kadane's algorithm
    //we find max sum of array and min sum of array(without circular property) and array sum
    //if min sum==array sum it means all elements -ve hence we return max_Sum
    //else we return max of (max sum and (array sum - min_sum)) min_sum is always -ve or zero
    //(array sum - min_sum) this gives  circular sum 
    
    int circularSubarraySum(int arr[], int n){
        
        int max_sum=INT_MIN;
        int temp_max=0;
        int array_sum=0;
        int min_sum=INT_MAX;
        int temp_min=0;
        
        for(int i=0;i<n;i++){
            array_sum+=arr[i];
            
            temp_max+=arr[i];
            
            max_sum=max(temp_max,max_sum);
            
            if(temp_max<0)
            temp_max=0;
            
            temp_min+=arr[i];
            
            min_sum=min(min_sum,temp_min);
            
            if(temp_min>0)
            temp_min=0;
        }
        
        if(min_sum==array_sum) //all elements -ve
         return max_sum; 
         
         return max(max_sum,(array_sum - min_sum ));
        
    }
