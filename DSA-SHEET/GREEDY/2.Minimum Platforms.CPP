//https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620


// { Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    // 	sort(arr, arr+n);
    // 	sort(dep, dep+n);
    // 	int plat=1,res=1;
    // 	int i=1,j=0;
    // 	while(i<n && j<n)
    // 	{
    // 	    if(arr[i] <= dep[j])
    // 	    {
    // 	        plat++;
    // 	        i++;
    // 	    }
    // 	    if(arr[i] > dep[j]){
    // 	        plat--;
    // 	        j++;
    // 	    }
    // 	}
    // 	if(plat> res){
    // 	    res=plat;
    // 	}
    // 	return res;
    
    // line sweep method  // tc- O(n)
    // Your code here
	int count[2400]={0};
	for(int i=0;i<n;i++){
	    count[arr[i]]+=1;
	    count[dep[i]+1]-=1;
	}
	int ans=0;
	for(int i=1;i<2400;i++){
	    count[i]+=count[i-1];
	    ans=max(ans,count[i]);
	}
	return ans;
    }
};


// { Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}  // } Driver Code Ends
