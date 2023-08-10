  //maximum contiguous subarray with two types of integers
    int totalFruits(int N, vector<int> &fruits) {
        
        int l=0,r=0; //l keeps track of start of a subaaray with two fruit types
        
        int a=-1,b=-1; //keeps index 
        
        int ans=0;
        
        while(r<N){
            
            if(a==-1||fruits[r]==fruits[a]){ // 'a' has not appeared or element is same as element at index 'a'
                a=r;
            }
            
            else if(b==-1||fruits[r]==fruits[b]){
                b=r;
            }
            
            else{ //third-type of element found
                if(r-1==a){ //now we form subarray with arr[i] and 'a'
                    l=b+1; //now subarray after last appearance of b
                    b=r; //b becomes new element at index r
                }
                
                else{ //now we form subarray with arr[i] and b as it is appearing right before new element
                  
                  l=a+1; //l is placed after last appearance of a
                  a=r; //a is now the element at index r 
                }
            }
            
            ans=max(ans,r-l+1);
            r++;
        }
        
        return ans;
    }
