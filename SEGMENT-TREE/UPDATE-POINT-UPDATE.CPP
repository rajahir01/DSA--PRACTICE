 // USE CASE
// GIVEN ARR- 2,1,0,3,4,5,4  // 0 BASED INDEXING
// Q= 1-3
//TYPE-1 QUERY - FIND MIN(L,R)
//TYPE-2 QUERY - UPDATE IND,VAL AT A[IND]= 4;

// EXAMPLE
// TYPE-1 IN RANGE IN 1 -3 ---> MIN(IND)==0  WHICH IS AT INDEX=2 POSITION
// TYPE-2 RANGE 2 ---> 4 UPDATED
// NOW THE ARR IS 2,1,4,3,4,5,4

int update(int ind, int low, int high, int i, int val, int seg[])
   { 
    if(low== high)  // we have reached the last k node
    {
      seg[ind]= val;
      return;
    }
    int mid= (low + high)>>1;
  if(i<= mid) // if i is present before mid then go low to mid
  {
    update(2*ind+1,low, mid,i,val);
  }
  else
  {
  update(2*ind+2,mid+1,high,i,val);
  }
  
  
  seg[ind]= min(seg[2*ind+1], seg[2*ind+2]);
  

    }
