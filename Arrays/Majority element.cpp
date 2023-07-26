//My soln
int majorityElement(int a[], int size)
    {
        
      map<int,int> mp;
      
      int maxi=-1;
      
      for(int i=0;i<size;i++){
          mp[a[i]]++;
          
          if(mp[a[i]]>(size/2))
          maxi=a[i];
      }
       
       return maxi; 
    }

//Moore's Voting Algorithm
int majorityElement(int a[], int n)
    {
        
        int ele,cnt=0;;
        for(int i=0;i<n;i++){
            
            if(cnt==0){ //cnt==0 means that ele wasnt max in the particular subarray
                ele=a[i];
                cnt=1;
            }
            
            else if(a[i]!=ele){
                cnt--;
            }
            
            else if(a[i]==ele){
                cnt++;
            }
        }
      
      //ele is the majority element : IF there exists a majority element
      
      cnt=0;
      for(int i=0;i<n;i++){
          if(a[i]==ele)
          cnt++;
      }
      
      if(cnt>n/2)
      return ele;
      
      else
      return -1;
    }
