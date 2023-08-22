//Two-pointer aapproach
//Intuition : start at extreme ends and find area and change the pointer that has lesser value
//area= min(arr[l],arr[r]) * (r-l) : this is water containing area

long long maxArea(long long arr[], int len)
{
    int n=len;
        int l=0;
        int r=n-1;
        
        long long ans=0; //stores max area
        while(l<r){
             ans=max(ans,min(arr[l],arr[r])*(r-l));

             if(arr[l]<=arr[r])
             l++;

             else
             r--;
        }

        return ans;
}
