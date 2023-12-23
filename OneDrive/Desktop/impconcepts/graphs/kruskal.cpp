#include<algorithm>
#include<vector>
int  find_parent(int node, vector<int> &parent)
{
    if (parent[node]==node)
    {
        return node;
    }

   return parent[node]=  find_parent(parent[node],parent);
}

void union_fun(int u,int v, vector<int> &parent,vector<int> &rank)
{
    u=find_parent(u,parent);
    v=find_parent(v,parent);

    if (rank[u]<rank[v])
    {
        parent[u]=v;
    }
    else if (rank[u]>rank[v])
    {
        parent[v]=u;

    }
    else{
        parent[v]=u;
        rank[u]++;

    }
}
 
bool cmp(vector<int> & a,vector<int> & b)
{
    return a[2]<b[2];

}
int minimumSpanningTree(vector<vector<int>>& edges, int n)
{

    vector<int> parent(n,0);
    for (int i=0;i<n;i++)
    {
        parent[i]=i;
    }

    vector<int> rank(n,0);

    sort(edges.begin(),edges.end(),cmp);
    int ans=0;
    for (int i=0;i<edges.size();i++)
    {
        int u=edges[i][0];
        int v=edges[i][1];
        u=find_parent(u,parent);
        v=find_parent(v,parent);

        if (find_parent(u,parent)!=find_parent(v,parent))
        {
            ans=ans+edges[i][2];
            union_fun(u,v,parent, rank);
       
        }
    }
    return ans;



}