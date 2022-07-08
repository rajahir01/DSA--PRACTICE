// https://practice.geeksforgeeks.org/problems/roman-number-to-integer3201


// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int romanToDecimal(string &str) {
        // code here
        
        if(str.length()==0){
           return 0;
       }
       unordered_map <char,int> mp;
       mp['I']=1;
       mp['V']=5;
       mp['X']=10;
       mp['L']=50;
       mp['C']=100;
       mp['D']=500;
       mp['M']=1000;
   int n =str.length();
   char first=str[n-1];
   int sum=mp[first];
 
   for(int i=n-2;i>=0;i--){
       char curr=str[i];
       char prev=str[i+1];
       if(mp[curr]>=mp[prev]){
           sum+=mp[curr];
       }
       else{
           sum-=mp[curr];
       }
   }
   return sum;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}  // } Driver Code Ends

