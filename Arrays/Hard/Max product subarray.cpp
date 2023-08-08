//possible cases
	//1. all +ve or even -ve, then multiply all
	//2. odd -ve, take prefix and suffix excluding each -ve ...i.e. remove one -ve to get even -ve
	//3. if arr[i]=0 , make produxt =1
	long long maxProduct(vector<int> arr, int n) {
	    
	    
	    
	    long long prefix=1,suffix=1,mxprod=INT_MIN;
	    
	    for(int i=0;i<n;i++){
	        if(prefix==0)
	        prefix=1;
	        
	        if(suffix==0)
	        suffix=1;
	        
	        prefix=prefix*arr[i];
	        
	        suffix=suffix*arr[n-i-1];
	        
	        mxprod=max(mxprod,max(prefix,suffix));
	    }
	   
	   return mxprod;
	}
