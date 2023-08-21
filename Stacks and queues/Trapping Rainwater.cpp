long long trappingWater(int arr[], int n){
       
     vector<int> a(n,0),b(n,0);
     
     
     a[0]=arr[0];
     for(int i=1;i<n;i++){
         a[i]=max(a[i-1],arr[i]);
     }
     
    //  for(int i=0;i<n;i++){
    //      cout<<a[i]<<".";
    //  }
      
      b[n-1]=arr[n-1];
     
      for(int i=n-2;i>=0;i--){
         b[i]=max(b[i+1],arr[i]);
     }
       
     long long ans=0;
     
     for(int i=1;i<n-1;i++){
         ans+=min(a[i],b[i])-arr[i];
     }
     
     return ans;
    }

    // we apply ans+= min(leftmax,rightmax) - arr[i]
    long long trappingWater(int arr[], int n){
       
       //stack<int> st;
       
       vector<int> lg; //to take greatest element from left
       
       lg.push_back(arr[0]);
       
       int maxi=arr[0];
       
       for(int i=1;i<n;i++){
           if(arr[i]>maxi){
               maxi=arr[i];
           }
           
           lg.push_back(maxi);
       }
       
       vector<int> rg;
       
        rg.push_back(arr[n-1]);
       
       maxi=arr[n-1];
       
       for(int i=n-2;i>=0;i--){
           if(arr[i]>maxi){
               maxi=arr[i];
           }
           
           rg.push_back(maxi);
       }
       
       reverse(rg.begin(),rg.end());
       
       long long ans=0;
       
       for(int i=0;i<n;i++){
           ans+=min(lg[i],rg[i])-arr[i];
       }
       
       return ans;
       
    }

//video link : https://www.youtube.com/watch?v=m18Hntz4go8
//now a two pointer approach with S.C. : O(1)
//intuition : two pointer approach of min(leftmax,rightmax) - arr[i]
    int trap(vector<int>& arr) {
        
        int n=arr.size();
   
        int l=0;

        int r=n-1;

        int res=0;

        int leftmax=0;

        int rightmax=0;


        while(l<=r){
              

              if(arr[l]<=arr[r]){ 

                  if(arr[l]>=leftmax)
                  leftmax=arr[l];

                  else
                  res+=leftmax-arr[l];

                  l++;
              }

              else{
                
                 if(arr[r]>=rightmax)
                  rightmax=arr[r];

                  else
                  res+=rightmax-arr[r];

                  r--; 
              }
        }

        return res;
    }
