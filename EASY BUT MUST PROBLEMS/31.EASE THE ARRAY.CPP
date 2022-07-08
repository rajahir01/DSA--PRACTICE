
///https://practice.geeksforgeeks.org/problems/ease-the-array0633

// { Driver Code Starts
//Initial Template for C++

// C++ implementation to rearrange the array 
// elements after modification 
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        void modifyAndRearrangeArr(int arr[], int n) 
    { 
    	// Complete the function
    	for(int i=0;i<n-1;i++)
    	{
    	    if(arr[i]!=0){
    	        if(arr[i]==arr[i+1] && i+1<=n-1)
    	        {
    	            int val=arr[i];
    	            arr[i]= 2*val; // double the value
    	            arr[i+1]=0;
    	            i++;
    	        }
    	    }
    	}
    	
    	//rearrange
    	int j=0;
    	for(int i=0;i<n;i++)
    	{
    	    if(arr[i]!=0)
    	    {
    	        arr[j]=arr[i];
    	        j++;
    	    }
    	   
    	}
    
    	while(j<n){
    	    arr[j]=0;
    	    j++;
    	    
    	}
   
   // method 2 
    //  int k=0;
    // 	for(int  i=0; i<n-1; i++)
    // 	{
    // 	    if(arr[i]==arr[i+1] and arr[i]!=0)
    // 	    {
    // 	        arr[i]=2*arr[i];
    // 	        arr[i+1]=0;
    // 	    }
    // 	}
    // 	for(int j=0; j<n; j++)
    // 	{
    // 	    if(arr[j]!=0)
    // 	    {
    // 	        swap(arr[k],arr[j]); k++;
    // 	    }
    // 	}
    	
    
    
    
    
    	
    }
}; 


// { Driver Code Starts.
// Driver program to test above 
int main() 
{ 
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        ob.modifyAndRearrangeArr(arr, n);
        for(int i=0;i<n;i++)
            cout << arr[i] << " ";
        cout << endl;
        
    }

	return 0; 
} 
  // } Driver Code Ends
