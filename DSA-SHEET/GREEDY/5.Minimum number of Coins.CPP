// https://practice.geeksforgeeks.org/problems/-minimum-number-of-coins4426


// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> minPartition(int N)
    {
        // code here
        int d[]={ 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 };
        int n=10;
        
        vector<int> ans;
        for(int j=n-1;j>=0;j--)
        {
            while(N >= d[j])
            {
                N-=d[j];
                ans.push_back(d[j]);
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends
