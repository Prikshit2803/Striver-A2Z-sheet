//refer ro find first and last occurrence of x problem
int count(int arr[], int n, int x) {
	   
	   int lb=lower_bound(arr,arr+n,x)-arr;
	   
	   if(lb==n||arr[lb]!=x)
	   return 0;
	   
	   int ub=upper_bound(arr,arr+n,x)-arr;
	   
	   //return (ub-1)-lb+1; //this is the true idea lb : gives first occurence 
	   
	   return ub-lb;
	}

//pure binary search
//video-link : https://www.youtube.com/watch?v=hjR1IYVx9lY

	int first_occurrence(int arr[],int n,int x){
	    
	    int low=0;
	    int high=n-1;
	   
	    
	    int first=-1;
	    while(low<=high){
	        
	         int mid=(low + high)/2;
	         
	        if(arr[mid]==x){
	           first=mid;
	           high=mid-1; //search left portion
	        }
	        
	        else if(arr[mid]>x)
	        high=mid-1;
	        
	        else
	        low=mid+1; //search right portion
	    }
	    
	    return first;
	}
	
	
		int last_occurrence(int arr[],int n,int x){
	    
	    int low=0;
	    int high=n-1;
	   
	    
	    int last=-1;
	    while(low<=high){
	        
	         int mid=(low + high)/2;
	         
	        if(arr[mid]==x){
	           last=mid;
	           low=mid+1; //search right portion
	        }
	        
	        else if(arr[mid]>x)
	        high=mid-1;
	        
	        else
	        low=mid+1; //search right portion
	    }
	    
	    return last;
	}
		
	int count(int arr[], int n, int x) {
	   
	   int first=first_occurrence( arr, n,x);
	   
	   
	   int last=last_occurrence(arr, n,x);
	   
	   if(first==-1)
	   return 0;
	   
	   return last-first+1;
	}
