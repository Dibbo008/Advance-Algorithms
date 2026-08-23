#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void flyodWar(vector<vector<int>>&dist){
    int v=dist.size();
    int inf=10000;

    for(int k=0;k<v;k++){
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                if(dist[i][k]!=inf && dist[k][j]!=inf){
                    dist[i][j]=min(dist[i][j],(dist[i][k]+dist[k][j]));
                }
            }
        }
    }
}

int main() {
    int v;
    cout<<"Enter your Vertex : ";
    cin>>v;

    vector<vector<int>>dist(v,vector<int>(v));
    cout<<"Enter adjacency matrix (Use 10000 for no edge):\n";
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            cin>>dist[i][j];
        }
    }

    flyodWar(dist);

    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
}