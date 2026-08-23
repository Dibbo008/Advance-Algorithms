#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// ১. Bellman-Ford ফাংশন (h পটেনশিয়াল অ্যারে বের করার জন্য)
vector<int>bell(int vtx,vector<vector<pair<int,int>>>&adj,int src,bool &hasCycle) {
    int INF = 10000;
    vector<int> dist(vtx,INF);
    dist[src] = 0;

    // Relaxation V-1 বার
    for(int m=0;m<vtx-1;m++){
        for(int i=0;i<vtx;i++){
            for(auto a:adj[i]){
                int u=i;
                int v=a.first;
                int wt=a.second;

                if(dist[u]!=INF&& dist[u]+wt<dist[v]){
                    dist[v]=dist[u]+wt;
                }
            }
        }
    }

    // Negative Cycle চেক করা
    hasCycle=false;
    for(int i=0;i<vtx;i++){
        for(auto a:adj[i]){
            int u=i;
            int v= a.first;
            int wt=a.second;

            if(dist[u]!=INF && dist[u]+wt<dist[v]){
                hasCycle=true;
                return{};
            }
        }
    }

    return dist;
}

// ২. Dijkstra's Algorithm (আপনার কোডই অপরিবর্তিত রাখা হয়েছে)
vector<int>dijkstra(int vtx,vector<vector<pair<int, int>>>&adj,int src){
    int INF=10000;
    vector<int>dist(vtx, INF);
    dist[src]=0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
    pq.push({0,src});

    while(!pq.empty()){
        auto top=pq.top();
        pq.pop();
        int d=top.first;
        int u=top.second;

        if(d>dist[u]) continue;

        for(auto &p:adj[u]){
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

// ৩. Johnson's Algorithm এর মূল ফাংশন
void johnson(int vtx,vector<vector<pair<int,int>>>&adj) {
    int INF = 10000;

    // ধাপ ১: একটি কাল্পনিক Extra Node (vtx) যোগ করা যার থেকে সবার ডিস্টেন্স 0
    vector<vector<pair<int,int>>>tempAdj=adj;
    tempAdj.push_back({}); // Extra Node Index = vtx
    for(int i=0;i<vtx;i++) {
        tempAdj[vtx].push_back({i,0});
    }

    // ধাপ ২: Extra Node থেকে Bellman-Ford রান করে h[] অ্যারে বের করা
    bool hasCycle=false;
    vector<int> h=bell(vtx+1,tempAdj,vtx,hasCycle);

    if (hasCycle) {
        cout<<"Negative Weight Cycle Detected! Algorithm stopped."<<endl;
        return;
    }

    // ধাপ ৩: Reweighting - সব এজকে Non-negative বানিয়ে নতুন Graph (newAdj) তৈরি করা
    vector<vector<pair<int,int>>>newAdj(vtx);
    for (int u=0;u<vtx;u++) {
        for (auto e:adj[u]) {
            int v=e.first;
            int wt=e.second;
            int new_wt= wt+h[u]-h[v]; // সমীকরণ: w' = w + h[u] - h[v]
            newAdj[u].push_back({v,new_wt});
        }
    }

    // ধাপ ৪: প্রতিটি নোড থেকে Dijkstra চালিয়ে শর্টেস্ট ডিস্টেন্স বের করা
    vector<vector<int>>finalDist(vtx,vector<int>(vtx));
    for (int s=0;s<vtx;s++) {
        vector<int> d_prime=dijkstra(vtx, newAdj, s);
        
        for (int v=0;v<vtx;v++) {
            if (d_prime[v]>=INF) {
                finalDist[s][v]=INF;
            } else {
                // মূল দূরত্ব রিকভার করার সমীকরণ: d = d' + h[v] - h[u]
                finalDist[s][v]=d_prime[v]+h[v]-h[s];
            }
        }
    }

    // ফলাফল প্রিন্ট করা (Result Matrix)
    cout<<"\nAll-Pairs Shortest Path Matrix (Johnson's Algorithm):\n";
    for (int i=0;i<vtx;i++) {
        for (int j=0;j<vtx;j++) {
            if(finalDist[i][j]>=INF)
                cout<<"INF ";
            else
                cout<<finalDist[i][j]<<" ";
        }
        cout << "\n";
    }
}

int main() {
    int vtx,edge;
    cout<<"Enter V & E : ";
    cin>>vtx>>edge;

    vector<vector<pair<int, int>>>adj(vtx);

    cout<<"Enter u v w : ";
    for (int i=0;i<edge;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
    }

    // Johnson's Algorithm কল করা
    johnson(vtx,adj);

    return 0;
}
