//if -ve nos = +ve nos
void rearrange(int a[], int n) {
	   
     int ans[n];
     int pos=0,neg=1;
     
     for(int i=0;i<n;i++){
         if(a[i]<0){
             
             ans[neg]=a[i];
             neg+=2;
             
             
         }
         
         else if(a[i]<0 && pos<n){
             
             
             ans[pos]=a[i];
             pos+=2;
           
         }
         
         
     }

         for (int i = 0; i < n; i++) {
                 a[i] = ans[i];
              }
	}

//Modified Brute force
	void rearrange(int a[], int n) {
	   
	  vector<int> pos,neg;
	  
	  for(int i=0;i<n;i++){
	      if(a[i]>=0){
	          pos.push_back(a[i]);
	      }
	      
	      else
	      neg.push_back(a[i]);
	  }
	  
	  
	  if(pos.size()>neg.size()){
	      
	      for(int i=0;i<neg.size();i++){
	          a[2*i]=pos[i];
	          a[2*i +1]=neg[i];
	      }
	      
	      int ind=neg.size()*2;
	      for(int i=neg.size();i<pos.size();i++){
	          a[ind++]=pos[i];
	      }
	  }
	  
	  else {
	      
	      for(int i=0;i<pos.size();i++){
	          a[2*i]=pos[i];
	          a[2*i +1]=neg[i];
	      }
	      
	      int ind=pos.size()*2;
	      for(int i=pos.size();i<neg.size();i++){
	          a[ind++]=neg[i];
	      }
	  }
	  
	}
