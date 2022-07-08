// https://practice.geeksforgeeks.org/problems/index-of-an-extra-element


// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
  public:
//   int findarr(int a[], int b[])
//   {
      
//       if(a[i]==b[])
//   }
    int findExtra(int a[], int b[], int n) {
        // add code here.
        // int j=0;
        // int i=0;
        // while(i<n && i++)
        // {
        //     if(a[i]==b[j])
        //     {
        //         j++;
        //         continue;
        //     }
        // }
        // return i;
        //  int j=0;
        // for(int i=0;i<n;i++)
        // {
        //     if(a[i]==b[j])
        //     {
        //         j++;
        //         continue;
        //     }
        //     return i;
        // }
         unordered_map<int,int>m;
        
         for(int i=0;i<n;i++){
            m[b[i]]++;
           
        }
        for(int i=0;i<n;i++){
            m[a[i]]++;
             if(m[a[i]]==1)
            return i;
        }
        return -1;
        
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n], b[n - 1];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n - 1; i++) {
            cin >> b[i];
        }
        Solution obj;
        cout << obj.findExtra(a, b, n) << endl;
    }
}  // } Driver Code Ends
