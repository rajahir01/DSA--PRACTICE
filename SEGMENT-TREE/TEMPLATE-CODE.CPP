 // GIVEN TWO ARRAYS-  ARR1[ ........] AND ARR2[........ ]
// QUERIES FOR MIN AND UPDATE
// TYPE-1 L1-R1  TO GET MIN1 IN ARR1 AND L2-R2 TO GET MIN2 IN ARR2 THEN FIND---> OVERALL MIN(MIN1, MIN2)
//TYPE-2 ARR1,IND1,VAL1----> UPDATE ARR1 AND ARR2,IND2,VAL2----> UPDATE ARR2
// IF WE WRITE SEPARATE CODE ITS GONNA BE LENGTHY CODE 
// BETTER TO WRITE CLASS WITH OBJECT CODE
 #include<bits/stdcc+.h>
  class SGTree{
   public: vector<int> seg;
		public: 
		SGTree(int n)
		{
			seg.resize(4*n);
		}
		void build(int ind,int low,int high,int arr[])
		{
		if(low==high) // base case when same range 0,0 or 1,1, or n-1,n-1
		{ 
			seg[ind]=arr[low];
			return;
		}
			int mid=(low + high)>>1; // if TLE use this mid= low - (high-low)/2;
			build(2*ind+1,low,mid,arr);
			build(2*ind+2,mid+1,high,arr);
			seg[ind]=min(seg[2*ind+1],seg[2*ind+2]);
		}
		// query function
		
		int query(int ind,int low,int high,int l,int r)
		{
		// no overlap
			if(r<low && high<l) return INT_MAX;
			
			//  complete overlap
			if(low<=l && high<=r) return seg[ind];
			
			// partial overal- go left and go right
			int mid=(low+high)/2;
			int left=query(2*ind+1,low,mid,l,r);
			int right=query(2*ind+2,mid+1,high,l,r);
      return min(left, right);
		}
    
    // update function
    void update(int ind, int low, int high, int i, int val)
    {
    //base case
      if(low==high)
      {
      seg[ind]=val;
        return;
      }
      
      int mid=(low+high)>>1;
      //if i is in range of low to mid
      if(i<=mid) update(2*ind+1,low,mid,i,val)
        // then it will be in range of mid+1 to high
      else update(2*ind+2,mid+1,high,i,val);
      
      seg[ind]=min(seg[2*ind+1], seg[2*ind+2]);
    }
		
		
   };

// DRIVER FUNCTION OR MAIN FUNCTION
void solve()
{
int n1; cin>>n1;
int arr1[n1];
  for(int i=0;i<n;i++) cin>>arr1[i];
  SGTree sg1(n1); // obj 1 
  sg1.build(0,0,n1-1,arr1);
  int n2; cin>>n2;
  int arr2[n2];
  for(int i=0;i<n;i++) cin>>arr2[i];
  SGTree sg2(n2); // obj 2
  // queries
  int q; cin>>q;
  while(q--)
  {
    int type; cin>>type;
    if(type==1)
    {
    int l1,r1,l2,r2;
      cin>>l1>>r1>>l2>>r2;
      int min1=sg1.query(0,0,n1-1,l1,r1);
      int min2=sg2.query(0,0,n2-1,l2,r2);
      cout<<min(min1, min2)<<endl;
    }
    
    // two case
    else
    {
    int arrN,i,val;
      cin>>arrN>>i>>val;
      if(arrN==1) // if one array 
      {
        sg1.update(0,0,n1-1,i,val);
        arr1[i]=val;
      }
      else
      {
      sg2.update(0,0,n2-1,i,val);
        arr2[i]=val;
      }
      
    }
  }
  

}
