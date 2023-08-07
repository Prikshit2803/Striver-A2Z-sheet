//TLE my soln
 void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            int i=0,j=0;
            
            while(i<n){
                if(arr1[i]<=arr2[j])
                i++;
                
               else if(arr1[i]>arr2[j]){
                    int temp=arr1[i];
                    
                    arr1[i]=arr2[j];
                    arr2[j]=temp;
                    i++;
                    
                    // while(j+1<n && arr2[j]>arr2[j+1]){
                        
                    //     swap(arr2[j],arr2[j+1]);
                    //     j++;
                    // }
                    sort(arr2,arr2+m);
                    //j=0;
                }
            }
            
             sort(arr2,arr2+m);
        } 

//Another approach
//compare last element and first element of arr1 and arr2 respectively and swap if arr1> arr2 keep comparing till arr1>arr2 
void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            int i=n-1,j=0;
            
            while(i>=0 && j<m){
                if(arr1[i]>arr2[j]){
                    int temp=arr1[i];
                    arr1[i]=arr2[j];
                    arr2[j]=temp;
                    
                    i--;
                    j++;
                }
                
                else{
                    
                    break; //break coz since arr1 will be sorted from i to 0 and arr2 sorted from j to m hence no more swaps needed
                }
                
            }
                
              sort(arr1,arr1+n);  
             sort(arr2,arr2+m);
        } 

//Shell sort - gap method
void swapIfGreater(long long arr1[], long long arr2[], int ind1, int ind2) {
    if (arr1[ind1] > arr2[ind2]) {
        swap(arr1[ind1], arr2[ind2]);
    }
}

void merge(long long arr1[], long long arr2[], int n, int m) {
    // len of the imaginary single array:
    int len = n + m;

    // Initial gap:
    int gap = (len / 2) + (len % 2);

    while (gap > 0) {
        // Place 2 pointers:
        int left = 0;
        int right = left + gap;
        while (right < len) {
            // case 1: left in arr1[]
            //and right in arr2[]:
            if (left < n && right >= n) {
                swapIfGreater(arr1, arr2, left, right - n);
            }
            // case 2: both pointers in arr2[]:
            else if (left >= n) {
                swapIfGreater(arr2, arr2, left - n, right - n);
            }
            // case 3: both pointers in arr1[]:
            else {
                swapIfGreater(arr1, arr1, left, right);
            }
            left++, right++;
        }
        // break if iteration gap=1 is completed:
        if (gap == 1) break;

        // Otherwise, calculate new gap:
        gap = (gap / 2) + (gap % 2);
    }
}
