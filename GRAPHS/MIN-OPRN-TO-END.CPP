
//https://practice.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/1/

// lets say start= 3 and end=30
// given arr={2,5,10}
// start*arr[0]......arr[n-1] to reach end -> min multi required
// find min operation to get end
// example: start=3 then start*2*5=3*2*5=30  which is end here u required 2 multi
// example: start*10= end=30 here u require 1 multi only
// we can use number as many as want
// if not posssible to find min oprn return -1;

int minmoves(int start, int end, int arr[])
{
  
  int vis[end+1]; // to keep count and not to repeat the steps
  vis[start]=1;
  queue<pair<int, int>>q;
  q.push({start, 0}) // storing start and couting the steps
    while(!q.empty())
    {
      int node= q.front().first;
      int steps=q.front().second;
       if(node==end) return steps;
      q.pop();
      for(int i=0;i<n;i++)
      {
        int dest= node * arr[i];
       
        if(dest<=end && !vis[dest])
        {
          q.push({dest,steps+1})
            vis[dest]=1;
            
        }
      }
      
    }
  return -1;
}
