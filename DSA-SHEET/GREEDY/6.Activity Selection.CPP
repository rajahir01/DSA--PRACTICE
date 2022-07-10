// JUST LIKE  N MEETING IN A ROOM PROBLEM

//https://practice.geeksforgeeks.org/problems/activity-selection-1587115620

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of activities that can
    //be performed by a single person.
static bool cmp(vector<int>&v1,vector<int>&v2){
       return v1[1]<v2[1];
       return v1[2]<v2[2];
   
   }
   int activitySelection(vector<int> start, vector<int> end, int n)
   {
       // Your code here
       vector<vector<int>>v;
       for(int i=0;i<n;i++){
           v.push_back({start[i],end[i],i+1});
       }
       int cnt=1;
       sort(v.begin(),v.end(),cmp);
       int endlimit=v[0][1];
       for(int i=1;i<v.size();i++){
           if(endlimit<v[i][0]){
               endlimit=v[i][1];
               cnt++;
           }
       }
       return cnt;
   }
};

// { Driver Code Starts.
int main()
{
    int t;
    
    //testcases
    cin >> t;
    while(t--)
    {
        //size of array
        int n;
        cin >> n;
        vector<int> start(n), end(n);
        
        //adding elements to arrays start and end
        for(int i=0;i<n;i++)
            cin>>start[i];
        for(int i=0;i<n;i++)
            cin>>end[i];
        Solution ob;
        //function call
        cout << ob.activitySelection(start, end, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends
