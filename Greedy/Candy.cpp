//video link : https://www.youtube.com/watch?v=h6_lIwZYHQw
//divide problem into left and right neighbors then take max from both arrays
    int minCandy(int N, vector<int> &arr) {
        vector<int> left(N,1),right(N,1);
        
        int cnt=0;
        
        for(int i=1;i<N;i++){
            if(arr[i]>arr[i-1])
            left[i]=left[i-1]+1;
        }
        
        
        for(int i=N-2;i>=0;i--){
            if(arr[i]>arr[i+1])
            right[i]=right[i+1]+1;
        }
        
         for(int i=0;i<N;i++){
            cnt+=max(left[i],right[i]);
        }
        
        return cnt;
        
    }
