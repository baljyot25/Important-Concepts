// DID NOT PASS TESTCASE;

#include <bits/stdc++.h> 
#include<list>
#include<unordered_map>
#include<stack>
#include<vector>

/
void dfs(int src,unordered_map<int,bool> visited,stack<int> s, unordered_map <int,list<int>> adj)
{
    visited[src]=1;

    for (auto i: adj[src])
    {
        if(!visited[i])
        {
            dfs(i  ,visited,s,adj);
        }
    }
    s.push(src);


}


vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    unordered_map<int,list<int>> adj;
    for (int i=0;i<e;i++)
    {
        int v=edges[i][0];
        int u=edges[i][1];

        adj[v].push_back(u);

    }
    stack <int> s;
    unordered_map<int,bool> visited;
    for (int i=0;i<v;i++)
    {
        if (!visited[i])
        {
            dfs(i,visited,s,adj);
        }
    }
    vector<int> ans;
    while(!s.empty())
    {
        ans.push_back(s.top());
        // #cout<<s.top()<<" ";
        s.pop();
    }

    return ans;

}