//Hashmap approach
int getPairsCount(int arr[], int n, int k) {
        int cnt=0;
        map<int,int> mp;
       for(int i=0;i<n;i++){
           int more=k-arr[i];
           
           if(mp[more]){ //it means more exits in hahmap as mp[more]!=0
               cnt+=mp[more];
           }
           
           mp[arr[i]]++;
       }
       
       return cnt;
    }
