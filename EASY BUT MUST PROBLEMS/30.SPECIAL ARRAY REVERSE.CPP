// https://practice.geeksforgeeks.org/problems/special-array-reversal2328



// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    string reverse(string str)
    { 
        //code here.
        
          string ptr="";
       int i;
       for(i=0;i<str.size();i++)
       {
           if((str[i]>='A' && str[i]<='Z' )|| (str[i]>='a' && str[i]<='z'))
           ptr+=str[i];
       }
       int j=ptr.size()-1;
       
       string fin="";
       for(i=0;i<str.size();i++)
       {
           if((str[i]>='A' && str[i]<='Z' )|| (str[i]>='a' && str[i]<='z'))
           {
               fin+=ptr[j];
               j--;
           }
           else
           fin+=str[i];
       }
       return fin;
        
    } 
};

// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout <<ob.reverse(s) << endl;
    }
return 0;
}

  // } Driver Code Ends
