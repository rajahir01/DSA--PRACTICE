#include<bits/stdc++.h>
using namespace std;
vector<int> adj[100];
int vis[1000];

//  U - edges
// V- vertices

void dfssolve()
{
  vector<int> vis;
  int n,m; cin>>n>>m;
  for(int i=0;i<=m;i++)
  {
    int U,V;
    cin>>U>>V;
    adj[U].push_back(V);
    adj[V].push_back(U);
    
  }
  for(int i=0;i<=n;i++)
  {
    if(vis[i]==0)
      dfs(i);
  }
  
}


// T.C. ------>  APPROX ~~ O(N)

void dfs(int node)
{
  
vis[node]=1;   // initialize with 1
  // traverse one by one till the depth
  for(auto it: adj[U]){
  if(vis[i]==0)  {  // if not visited 
  dfs(i);   // call dfs
  } 
    
  }
  cout<<node;
}
