#include <bits/stdc++.h>
using namespace std;

void prims(int n,vector<vector<pair<int,int>>>&adj){
    vector<int>key(n,INT_MAX);
    vector<int>parent(n,-1);
    vector<bool>used(n,false);

    key[0]=0;
    for(int i=0;i<n;i++){
        int u=-1;
        for(int j=0;j<n;j++){
            if(!used[j] && (u==-1||key[j]<key[u]))
                u=j;
        }
        used[u]=true;

        for(auto e:adj[u]){
            int v=e.first;
            int wt= e.second;
            if(!used[v] && wt<key[v]){
                key[v]=wt;
                parent[v]=u;
            }
        }
    }
    int total=0;

    cout<<"\nMinimum Spanning Tree:\n";

    for(int i=1;i<n;i++){
        cout<<parent[i]<<" - "<<i<<" : "<<key[i]<<endl;
        total+=key[i];
    }
    cout<<"\nMinimum Cost = "<<total<<endl;
}

int main(){
    int n, e;
    cout<<"Enter vertices and edges: ";
    cin>>n>>e;
    vector<vector<pair<int,int>>> adj(n);
    cout<<"Enter u v w:\n";

    for(int i=0;i<e;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    prims(n,adj);
    return 0;
}