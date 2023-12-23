#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#include<unordered_map>
#include<list>

class graph
{

    public: 
        unordered_map<int,list<int>>adj;
        void edge(int u,int v,bool direction)
        {
            //direction refers to whether undirected(0) or directed(1)
            adj[u].push_back(v);
            if(!direction)
            {
                adj[v].push_back(u );
            }
        }

        void printadjlist()
        {
            for (auto i: adj)
            {
                cout<<i.first<<" ";
                for (auto j:i.second)
                {
                    cout<<j<<",";
                }
                cout<<endl;
            }
        }
        

};
