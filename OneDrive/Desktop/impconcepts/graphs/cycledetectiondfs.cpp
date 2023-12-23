//for undirected grahs


bool isCyclicDFS(int src,int parent,unordered_map<int,bool> &visited,unordered_map<int ,list<int>> &adj)
{
    visited[src]=1;
    for (auto i: adj[src])
    {
        if (!visited[i])
        {
            bool cd=isCyclicDFS(i,src,visited,adj);
            if (cd)
            {

                return true;
            }


        }
        else if (i!=parent)
        {
            
            return true;
        }
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
            bool ans=isCyclicDFS(i,-1,visited,adj);
            if(ans==1)
            {
                return "Yes";
            }
        }
    }
    return "No";

}