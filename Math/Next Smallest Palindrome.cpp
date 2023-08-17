//Approach : make the array a palindrome by num[j] = num[i] and if num[j]>num[i] mark flag=1 as it means our number has become smaller
//now check middle element if flag=1 and if it is 9 make it and it's palindrome counter-part (n-i-1) as 0 and do this till no more 9 then increment the first element we get after and it's palindrome counterpart
//video-link : https://www.youtube.com/watch?v=PTh_9auwvdk
vector<int> generateNextPalindrome(int num[], int n) {


      int i=0;
      int j=n-1;
      int flag=1; //for n=1 wala case
       while(i<j){
           if(num[j]>num[i]) //
           flag=1;
           
           else if(num[j]<num[i]) 
           flag=0;
           
           num[j]=num[i];
           
           i++;
           j--;
       }
       
       vector<int> ans;
       
       for(int i=0;i<n;i++)
       ans.push_back(num[i]);
       
       int carry=flag;
       
       int ind=n/2;
       
       while(carry && ind<n){
           
           if(ans[ind]==9){
               ans[ind]=0;
               ans[n-ind-1]=0;
           }
           
           else{
               ans[ind]=ans[ind]+1;
               ans[n-ind-1]=ans[ind];
               carry=0;
           }
           
           ++ind;
       }
       
       if(carry){ //ind>=n wala case when alll elements are 9
           
           ans[0]=1;
           ans.push_back(1);
       }
       
       return ans;
	}
