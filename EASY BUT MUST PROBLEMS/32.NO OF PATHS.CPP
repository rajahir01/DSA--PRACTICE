

/// https://practice.geeksforgeeks.org/problems/number-of-paths0926


// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

 // } Driver Code Ends
long long  numberOfPaths(int m, int n)
{
    // Code Here  TC- O(M*N)
    // int i=0,j=0;
    // if(i==(n-1) || j==(m-1)) return 1;
    // if(i>=n || j>=m) return 0;
    
    // else return numberOfPaths(m-1,n) + numberOfPaths(m,n-1);
    
    
    //OPTIMAL SOLN USING FACTTORIAL
    // int N=n+m-2;
    // int r=m-1;
    // double res=1;
    // for(int i=1;i<=r;i++){
    //     res = res*(N-r+1)/i;  // factorial
    // }
    // cout<<res<<endl;
    
    // return (int)res;
    
}

// { Driver Code Starts.

 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>m>>n;
	    cout << numberOfPaths(m, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends
