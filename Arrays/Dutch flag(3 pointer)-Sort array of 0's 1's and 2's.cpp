//Brute force ; O(2N)

void sort012(int a[], int n)
    {
        int cnt0=0,cnt1=0,cnt2=0;
        for(int i=0;i<n;i++){
            if(a[i]==0)
            cnt0++;
            
             if(a[i]==1)
            cnt1++;
            
             if(a[i]==2)
            cnt2++;
        }
        
        int i=0;
        while(cnt0){
            a[i++]=0;
            cnt0--;
        }
        
        while(cnt1){
            a[i++]=1;
            cnt1--;
        }
        
         while(cnt2){
            a[i++]=2;
            cnt2--;
        }
        
        
    }

//Dutch national flag algo : 3 pointer

//3 pointer : Dutch national flag : 0 to l-1 : 0.  -- l to m-1 : 1 -- m to h : unsoted -- h+1 to n-1 : 2's
    void sort012(int a[], int n)
    {
       int l=0,m=0,h=n-1;
       
       while(m<=h){
           if(a[m]==0){
               swap(a[l],a[m]);
               l++;
               m++;
           }
           
           else if(a[m]==1)
           m++;
           
           else if(a[m]==2){
               swap(a[m],a[h]);
               h--;
           }
       }
        
        
    }
