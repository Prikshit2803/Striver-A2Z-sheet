//merge sort with slight modification
   long long merge(long long arr[],long long low,long long mid,long long high){
        long long left=low; //start for 1st array
        long long right = mid+1; //start for 2nd array
        
        long long cnt=0;
        vector<long long> temp;
        
        while(left<=mid && right<=high){
            if(arr[left]<=arr[right]){
                temp.push_back(arr[left]);
                left++;
                
            }
            
            else{ //arr[right]<arr[left]
                temp.push_back(arr[right]);
                cnt+=mid-left+1; //modification
                right++;
                
            }
            
        }
        
        while(left<=mid){
           temp.push_back(arr[left]);
                left++; 
        }
        
        while(right<=high){
            temp.push_back(arr[right]);
                right++; 
        }
        
        for(int i=low;i<=high;i++)
        arr[i]=temp[i-low];
        
        return cnt;
    }
    
    long long mergesort(long long arr[],long long low,long long high){
        
         long long cnt=0;
        
        if(low>=high) //low==high means only one element left
        return cnt ;
        
       
        
         long long mid=(low + high)/2;
        
       cnt+= mergesort(arr,low,mid);
       cnt+= mergesort(arr,mid+1,high);
       cnt+= merge(arr,low,mid,high);
       
       return cnt;
        
    }
    long long int inversionCount(long long arr[], long long N)
    
    {
        return mergesort(arr,0,N-1);
          
    }
