// Remove duplicate elements from sorted Array
// https://practice.geeksforgeeks.org/problems/remove-duplicate-elements-from-sorted-array/1/?page=1&difficulty[]=0&company[]=Zoho&sortBy=submissions#

// Remove duplicate elements from sorted Array

// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
public:
    int remove_duplicate(int a[],int n){
        // code here
        long long count=0;
        // long long slow=a[0];
        // long fast=a[1];
        // if(n==0 || n==1){
        //     return 1;
        // }
        // while(fast<n)
        // {
        //     if(a[slow]==a[fast]){
        //         fast++;
        //     }
        //     if(a[slow]!=a[fast])
        //     {
        //         count++;
        //         slow++;
        //     }
            
        // }
        for(int i=1;i<n;i++)
        {
            if(a[i]==a[i-1]){
                count++;
            }
            else
            {
                a[i-count]=a[i];
            }
        }
        return n-count;
    }
};

// { Driver Code Starts.
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int a[N];
        for(int i=0;i<N;i++)
        {
            cin>>a[i];
        }
    Solution ob;
    int n = ob.remove_duplicate(a,N);

    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    }
}  // } Driver Code Ends


// TC O(N)
//SC O(1)
