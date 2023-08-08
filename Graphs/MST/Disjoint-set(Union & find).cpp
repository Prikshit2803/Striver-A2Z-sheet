int find(int A[],int X)
{
      if(A[X]==X)
      return X;
      
      else
      return A[X]=find(A,A[X]); //find parent and when ultimate parent found make it parent of all nodes in path
}
void unionSet(int A[],int X,int Z)
{
	int par_x=find(A,X);
	int par_z=find(A,Z);
	
	A[par_x]=par_z; //make parent of x the parent of z and this is union
}
