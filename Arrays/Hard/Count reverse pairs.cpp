// Merge sort and reverse paiurs
void merge(vector<int> &arr,int low,int mid,int high){
        int left=low; //start for 1st array
        int right = mid+1; //start for 2nd array
        
       // long long cnt=0;
        vector<int> temp;
        
        while(left<=mid && right<=high){
            if(arr[left]<=arr[right]){
                temp.push_back(arr[left]);
                left++;
                
            }
            
            else{ //arr[right]<arr[left]
                temp.push_back(arr[right]);
               // cnt+=mid-left+1; //modification
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
        
        
    }
    
int  countpairs(vector<int> &arr,int low,int mid,int high){
          int right=mid+1;
           int cnt=0;
             
             for(int i=low;i<=mid;i++){
                 while(right<=high && arr[i]>2*arr[right]) right++; //right increases and doesnt come back as if arr[i]>2*arr[right] is true than for all elements at index > i will also have the same pair sand more
                 cnt+=right-(mid+1); 
             }
            
            return cnt; 
    }
    
    long long mergesort(vector<int> &arr,int low,int high){
        
         int cnt=0;
        
        if(low>=high) //low==high means only one element left
        return cnt ;
        
       
        
        int mid=(low + high)/2;
        
       cnt+= mergesort(arr,low,mid);
       cnt+= mergesort(arr,mid+1,high);
       cnt+=countpairs(arr,low,mid,high);
        merge(arr,low,mid,high);
       
       return cnt;
        
    }
    int countRevPairs(int n, vector<int> arr) {
        
        return mergesort(arr,0,n-1);
    }
