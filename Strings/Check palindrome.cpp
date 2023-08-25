//start from middle and keep checking
class Solution{
public:	
	
	
	int isPalindrome(string s)
	{
	    int n=s.length();
	    
	    int flag=1;
	    if(n%2==0){
	        int l=n/2-1;
	        int r=l+1;
	        
	        while(l>=0 && r<n){
	            if(s[l]!=s[r]){
	                flag=0;
	                break;
	            }
	            
	            l--;
	            r++;
	        }
	        
	        if(flag==0)
	        return 0;
	        
	        return 1;
	    }
	    
	    else{
	        int l=n/2;
	        int r=l;
	        
	        l--;
	        r++;
	        
	        while(l>=0 && r<n){
	            if(s[l]!=s[r]){
	                flag=0;
	                break;
	            }
	            
	            l--;
	            r++;
	        }
	        
	        if(flag==0)
	        return 0;
	        
	        return 1;
	    }
	}

};
