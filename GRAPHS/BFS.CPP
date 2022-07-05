#include<bits/stdc++.h>
using namespace std;
vector<int> adj[100];
int vis[1000];

//  U - edges
// V- vertices

void bfssolve()
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
      bfs(i);
  }
  
}


// T.C. ------>  APPROX ~~ O(N)

void bfs(int  node)
{
  vis[node]=1;
  queue<int>q;  // to store all nodes
  q.push(node);
  while(!q.empty())
  {
    int node =q.front();
    q.pop();
    cout<<node<<" ";
    for( auto it: adj[node])
    {
      if(!vis[it]){
        vis[it]=1;
       q.push(it); 
      }
      
        
    }
  }
}
