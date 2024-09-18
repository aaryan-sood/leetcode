// problem link
// https://www.geeksforgeeks.org/problems/disjoint-set-union-find/1
int find(int parent[],int x)
{
       //add code here
       if(x == parent[x])
       {
           return x;
       }
       else
       {
           return parent[x]= find(parent,parent[x]);
       }
}
void unionSet(int parent[],int x,int z)
{
	//add code here.
	int ulp_x=find(parent,x);
	int ulp_z=find(parent,z);
	
	if(ulp_x == ulp_z)
	{
	    return;
	}
	parent[ulp_x]=ulp_z;
}