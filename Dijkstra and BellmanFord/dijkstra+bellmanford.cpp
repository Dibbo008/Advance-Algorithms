#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int>bell(int vtx,vector<vector<pair<int,int>>>&adj,int src){
    vector<int>dist(vtx,10000);
    dist[src]=0;

    for(int m=0;m<vtx-1;m++){
    for(int i=0;i<vtx;i++){
        for(auto a:adj[i]){
            int u=i;
			int v=a.first;
			int wt=a.second;

			if(dist[u]+wt<dist[v]){
                dist[v]=dist[u]+wt;
			}
        }
      }
    }
    return dist;
}

vector<int>dijkstra(int vtx,vector<vector<pair<int,int>>>&adj,int src){
    vector<int>dist(vtx,10000);
    dist[src]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,src});

    while(!pq.empty()){
        auto top=pq.top();
        pq.pop();
        int d=top.first;
        int u=top.second;

        for(auto &p:adj[u]) {
            int v=p.first;
            int wt=p.second;

            if(dist[u]+wt<dist[v]){
                dist[v]=dist[u]+wt;
                pq.emplace(dist[v],v);
            }
        }
    }
    return dist;
}

int main(){

    int vtx,edge;
    cout<<"Enter V & E : "<<endl;
    cin>>vtx>>edge;

    vector<vector<pair<int,int>>>adj(vtx);

    cout<<"Enter u,v,w : "<<endl;
    for(int i=0;i<edge;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        cout<<endl;
    }

    int source=4; //starting node 4(change korle kore nite hobe)
    vector<int>res=bell(vtx,adj,source);
    vector<int>res2=dijkstra(vtx,adj,source);

    for(int dist:res)
        cout<<dist<<" ";

    for(int dist:res2)
        cout<<dist<<" ";

    /*for(int i=0;i<vtx;i++){
        for(pair<int,int>ed:adj[i]){
            cout<<"Node : "<<i<<":"<<"("<<ed.first<<" "<<ed.second<<")"<<endl;
        }
    }*/

    return 0;
}




