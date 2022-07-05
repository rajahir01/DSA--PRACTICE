// https://codeforces.com/problemset/problem/339/D
// Xenia the beginner programmer has a sequence a, consisting of 2n non-negative integers: a1, a2, ..., a2n. Xenia is currently studying bit operations. To better understand how they work, Xenia decided to calculate some value v for a.

// Namely, it takes several iterations to calculate value v. At the first iteration, Xenia writes a new sequence a1 or a2, a3 or a4, ..., a2n - 1 or a2n, consisting of 2n - 1 elements. In other words, she writes down the bit-wise OR of adjacent elements of sequence a. At the second iteration, Xenia writes the bitwise exclusive OR of adjacent elements of the sequence obtained after the first iteration. At the third iteration Xenia writes the bitwise OR of the adjacent elements of the sequence obtained after the second iteration. And so on; the operations of bitwise exclusive OR and bitwise OR alternate. In the end, she obtains a sequence consisting of one element, and that element is v.

// Let's consider an example. Suppose that sequence a = (1, 2, 3, 4). Then let's write down all the transformations (1, 2, 3, 4)  →  (1 or 2 = 3, 3 or 4 = 7)  →  (3 xor 7 = 4). The result is v = 4.

// You are given Xenia's initial sequence. But to calculate value v for a given sequence would be too easy, so you are given additional m queries. Each query is a pair of integers p, b. Query p, b means that you need to perform the assignment ap = b. After each query, you need to print the new value v for the new sequence a.

// Input
// The first line contains two integers n and m (1 ≤ n ≤ 17, 1 ≤ m ≤ 105). The next line contains 2n integers a1, a2, ..., a2n (0 ≤ ai < 230). Each of the next m lines contains queries. The i-th line contains integers pi, bi (1 ≤ pi ≤ 2n, 0 ≤ bi < 230) — the i-th query.

// Output
// Print m integers — the i-th integer denotes value v for sequence a after the i-th query.

// Examples
// inputCopy
// 2 4
// 1 6 3 5
// 1 4
// 3 4
// 1 2
// 1 2
// outputCopy
// 1
// 3
// 3
// 3

//   EXAMPLE     1    2    3   4
//                \   /     \   /  OR
//                   3         7
//                     \      /   XOR
//                         4 (ANS SHUD BE SINGE ELEMENT)
// IT LOOKS LIKE SG TREE PROBLEMS
// WHEN N=EVEN  ROOT NODE WILL BE XOR
// WHEN N=ODD ROOT NODE WILL BE OR

void build(int ind,int low,int high,int arr[],int seg[],int ORR)
{
  // orr is variable which tell its true means or otherwise xor
  if(low == high)  // base
  {
    seg[ind]=arr[low];
  }
  int mid=(low+high)>>1;
  build(2*ind+1,low,mid,arr,seg,!ORR);
  build(2*ind+2,mid+1,high,arr,seg,!ORR);
  
  if(ORR)
  {
    seg[ind]= seg[2*ind+1] or seg[2*ind+2];
    
  }
  else
    seg[ind]= seg[2*ind+1] xor seg[2*ind+2];
}


void update(int ind,int low,int high,int seg[],int ORR,int i ,int val)
{
  if(low==high)
  {
  seg[ind]=val;
    return;
  }
  int mid=(low+high)>>1;
  if(i<=mid) update(ind,low,mid,arr,seg,!ORR,i,val);
  else  update(ind,mid+1,high,arr,seg,!ORR,i,val);
  
  if(ORR) seg[ind]= seg[2*ind+1] or seg[2*ind+2];
  else  seg[2*ind+1] xor seg[2*ind+2];
}


// driver funciton

void solve()
{
  int n,q; cin>>n>>q;
  int el=pow(2,n); 
  int arr[el];
  for(int i=0;i<n;i++) cin>>arr[i];
  int seg[4*n];
  
  // cases
  if(n%2==0) build(0,0,el-1,arr,seg,0)  //  here ORR=0 but in function we gave !ORR  means start with XOR
    else build(0,0,el-1,arr,seg,1);
  
  int q;
  cin>>q;
  while(q--)
  {
    int i,val;
    cin>>i>>val;
    if(n%2==0) update(0,0,el-1,seg,0,i ,val); // start with xor
    else update(0,0,el-1,seg,1,i,val); // start with or
    
    cout<<seg[0]<<endl; //last elememt is ans
  }
  
}

