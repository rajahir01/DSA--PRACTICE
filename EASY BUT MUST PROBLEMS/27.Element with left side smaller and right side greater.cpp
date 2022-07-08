// https://practice.geeksforgeeks.org/problems/unsorted-array4925

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int findElement(int arr[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) cin >> a[i];
        cout << findElement(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends


int findElement(int arr[], int n) {
       int maxl[n];
   maxl[0]=arr[0];
   for(int i=1;i<n;i++)
   {
       maxl[i]=max(maxl[i-1],arr[i]);
   }
   int minr[n];
   minr[n-1]=arr[n-1];
   for(int i=n-2;i>=0;i--)
   {
       minr[i]=min(minr[i+1],arr[i]);
   }
   
   for(int i=0;i<n;i++)
   {
           if(i==0 || i==n-1)
           continue;
       if(maxl[i]==arr[i] && minr[i]==arr[i])
       {
           
           return arr[i];
       }
   }
   
   return -1;
    
}
