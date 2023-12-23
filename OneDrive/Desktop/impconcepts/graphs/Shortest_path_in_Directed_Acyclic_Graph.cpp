 void dfs(unordered_map<int,list<pair<int,int>>> &adj,vector<bool> &visited,stack<int> &s,int node)
     {
         
         
         visited[node]=1;
         
         for (auto j: adj[node])
         {
             int i=j.first;
             if (!visited[i])  dfs(adj,visited,s,i);
             
         }
        //  cout<<node<<"  ";
         s.push(node);
     }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        
        unordered_map<int,list<pair<int,int>>> adj;
        for (int i=0;i<M;i++)
        {
           adj[edges[i][0]].push_back(make_pair(edges[i][1],edges[i][2])); 
        }
        
        stack<int> s;
        vector<bool> visited(N,0);
        for (int i=0;i<N;i++)
        {
            if (!visited[i])
            {
                dfs(adj,visited,s,i);
            }
        }
        // cout<<endl;
        
        vector<int> ans(N,INT_MAX);
        ans[0]=0;
        
        // for (int i=0;i<N;i++)
        while(!s.empty())
        {
            int i=s.top();
            s.pop();
            
            if(ans[i]==INT_MAX) {ans[i]=-1; continue;}
            for (auto j: adj[i])
            {
                int node=j.first;
                if (ans[node]>=ans[i]+j.second )
                {
                    ans[node]=ans[i]+j.second;
                    // cout<<node<<" "<<ans[node]<<endl;
                }
            }
        }
       
        
        return ans;
        
        
        
        
    }