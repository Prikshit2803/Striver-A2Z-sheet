//1. Find i element from behind that is arr[i]<arr[i+1] , this will be min element that we can use to create next permuation
//from n-1 find 1st element greater than i,it will be smallest greater element
//now reverse remaining arr after ind
vector<int> nextPermutation(int n, vector<int> arr){
     int ind=-1;
     
     for(int i=n-2;i>=0;i--){
         if(arr[i]<arr[i+1]){ //first point where smaller element found hence we can get next permutation from here
             ind=i;
             break;
         }
     }
     
     if(ind==-1){
     reverse(arr.begin(),arr.end()); //1st permutation as arr is originally in descending order
     return arr;
    }
    
    for(int i=n-1;i>ind;i--){
        if(arr[i]>arr[ind]){
    
    swap(arr[i],arr[ind]); //as it is smallest elemnt greater to a[ind]
    break;
        
        }
        
        
    }
    
    reverse(arr.begin() + ind+1,arr.end());
    
    return arr;
}
