 void bfs(unordered_map <int , vector<int>>  &adj,unordered_map<int,int> &parent,unordered_map<int,bool> &visited,int i)
    {
        queue<int> q;
        q.push(i);
        visited[i]=1;
        parent[i]=-1;
        
        while(!q.empty())
        {
            int front =q.front();
            q.pop();
            for (auto j:adj[front])
            {
                if (!visited[j])
                {
                    visited[j]=1;
                    parent[j]=front;
                    q.push(j);
                }
            }
            
        }
        
    }
    vector<int> shortestPath(vector<vector<int>>& edges, int nodes,int no_edges, int src){
        // code here
        
        unordered_map <int , vector<int>>  adj;
        for (int i=0;i<no_edges;i++)
        {
            int v=edges[i][0];
            int u=edges[i][1];
            if (u==v)  continue;
            adj[u].push_back(v);
            adj[v].push_back(u);
            
            
        }
        
        // for (int i=0;i<nodes;i++)
        // {
        //     for (int j=0;j<adj[i].size();j++)
        //     {
        //         cout<<adj[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        unordered_map<int,int>parent;
        unordered_map<int,bool>visited;
        
        bfs(adj,parent,visited,src);
        
        for(int i=0;i<nodes;i++)
        {
            if (!visited[i])
            {
                bfs(adj,parent,visited,i);
                
            }
            
        }
        vector<int> ans;
        for (int i=0;i<nodes;i++)
        {
            int curr=i;
            int d=0;
            while(curr!=src)
            {
                
                d++;
                curr=parent[curr];
                if (curr==-1)
                {
                    d=-1;
                    break;
                }
            }
            
            ans.push_back(d);
            
            
        }
        return ans;
        // vector<int>ans;
        // for(int i = 0;i<nodes;i++){
        //     int current = i;
        //     int cst = 0;
        //     while(current!=src){
        //         cst++;
        //         current = parent[current];
        //         if(current==-1){
        //             cst = -1;
        //             break;
        //         }
        //     }
        //     ans.push_back(cst);
        // }
        // return ans;
        
        
        
    }