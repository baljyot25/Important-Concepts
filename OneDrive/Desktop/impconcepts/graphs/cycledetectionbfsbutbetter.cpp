//for undirected graphs

#include<unordered_map>
#include<list>
#include<queue>
      // if the number of visited nodes in any adjacency list is >=2 then there is a cycle.
        // no need for extra parent data structure
//Sample code which passed all the test cases:-

bool isCyclicBFS(int node, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adjList) {
    queue<int> q;
    q.push(node);
    visited[node] = true;

    while(!q.empty()) {
        node = q.front();
        // counter for already visited nodes
        int cnt = 0;
        //traversing the adjacency list
        for(int i: adjList[node]) {
            if(!visited[i]) {
                q.push(i);
                visited[i] = true;
            } else {
                cnt++;
            }
        }
        q.pop();
        // if the number of visited nodes in any adjacency list is >=2 then there is a cycle.
        if(cnt >= 2)
            return true;
    }
    return false;
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
 
    unordered_map<int ,list<int>> adj;

    for (int i=0;i<m;i++)
    {
        int u=edges[i][0];
        int v=edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    unordered_map<int,bool> visited;
    for (int i=0;i<n;i++)
    {
        if (!visited[i])
        {
            bool ans=isCyclicBFS(i,visited,adj);
            if(ans==1)
            {
                return "Yes";
            }
        }
    }
    return "No";

}
