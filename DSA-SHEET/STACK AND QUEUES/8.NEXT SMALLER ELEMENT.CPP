// https://practice.geeksforgeeks.org/problems/fab3dbbdce746976ba35c7b9b24afde40eae5a04

// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
//User function Template for C++

class Solution{
    
    public:
    vector<int> help_classmate(vector<int> arr, int n) {
            vector<int> ans(n);
       
       stack<int> st;
       st.push(-1);
       
       for(int i=n-1; i>=0; i--)
       {
           int item = arr[i];
           
           while(st.top()!=-1 && st.top() >= item)
               st.pop();
           if(st.top() < item)
               ans[i] = st.top();
           st.push(item);
       }
       
       return ans;
     
        // Your code goes here
    } 
};

// { Driver Code Starts.

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<int> array(n);
		for (int i = 0; i < n; ++i)
		{
			cin>>array[i];
		}
		Solution obj;
		vector<int> result = obj.help_classmate(array,n);
		for (int i = 0; i < n; ++i)
		{
			cout<<result[i]<<" ";
		}
		cout<<"\n";
	}
	return 0; 
}

  // } Driver Code Ends
