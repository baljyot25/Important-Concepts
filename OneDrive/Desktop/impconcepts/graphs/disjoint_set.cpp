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

void int_main()
{
     vector<int> parent(n,0);
    for (int i=0;i<n;i++)
    {
        parent[i]=i;
    }

    vector<int> rank(n,0);

}