vector <int> dijkstra(int V, vector<vector<int>> adj[], int s)
    {
        // Code here
        vector<int>dist(V,INT_MAX);
        
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > pq;
        
        dist[s]=0;
        
        pq.push({0,s});
        
        while(!pq.empty())
        {
            int distance = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto it:adj[node])
            {
                int adjnode=it[0];
                int adjweight=it[1];
                
                if(distance + adjweight < dist[adjnode])
                {
                    dist[adjnode]=distance + adjweight;
                    pq.push({dist[adjnode],adjnode});
                }
            }
        }
        
        return dist;
        
    }