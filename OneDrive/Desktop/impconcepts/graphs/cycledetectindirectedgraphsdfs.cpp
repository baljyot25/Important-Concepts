#include<unordered_map>
#include<list>


bool iscyclicdfs(int src, unordered_map<int,bool> &visited
            ,unordered_map<int,bool> &dfsvisited
            ,unordered_map<int,list<int>> &adj)
{
  visited[src]=1;
  dfsvisited[src]=1;
  for (auto i:adj[src])
  {
    if (!visited[i])
    {
      bool ans=iscyclicdfs(i, visited,dfsvisited, adj);
      if(ans)
      {
        return true;
      }

    }
    else if (dfsvisited[i])
    {
      return true;
    }
  }


  dfsvisited[src]=0;
  return false;

}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
  unordered_map<int,list<int>> adj;
	for (int i=0;i<edges.size();i++)
	{
		int u=edges[i].first;
		int v=edges[i].second;
		
		adj[u].push_back(v);
	}
  unordered_map<int,bool> visited;
  unordered_map<int,bool> dfsvisited;

  for (int i=0;i<=n;i++)
  {
    if (!visited[i])
    {
      bool ans=iscyclicdfs(i,visited,dfsvisited,adj);
      if (ans)
      {
        return true;
      }
    }
  }
  return false; 
}