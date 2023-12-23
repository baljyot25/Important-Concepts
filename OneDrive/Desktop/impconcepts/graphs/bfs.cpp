#include <bits/stdc++.h> 

void prepareadj(unordered_map<int,set<int>> &adj,vector<pair<int, int>> &edges)
{
    for (int i=0;i<edges.size();i++)
    {
        adj[edges[i].first].insert(edges[i].second);
        adj[edges[i].second].insert(edges[i].first);  
    }

    return ;
}

void bfs(unordered_map<int,set<int>> &adj,unordered_map<int ,bool>& visited,vector<int> &ans,int node)
{
    queue <int>q;
    q.push(node);
    visited[node]=1;
    while(!q.empty())
    {
        int front_node=q.front();
        q.pop();


        ans.push_back(front_node);

        for (auto i: adj[front_node])
        {
            if (!visited[i])
            {
                q.push(i);
                visited[i]=1;
            }
            
        }
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    // Write your code here 
    unordered_map<int,set<int>> adj;
    vector<int> ans;
    unordered_map<int ,bool> visited;

    prepareadj(adj,edges);
    for (int i=0;i<vertex;i++)
    {   
        if(!visited[i])
        {
            bfs(adj,visited,ans,i);
        }
    }
    return ans;
}





