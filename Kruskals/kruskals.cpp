#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int find(vector<int>&p,int i){
    if(i==p[i])return i;
    return p[i]=find(p,p[i]);
}

bool merge(vector<int>&p,int i,int j){
    int rootI=find(p,i),rootJ=find(p,j);
    if(rootI!=rootJ){
        p[rootI]=rootJ;
        return true;
    }
    return false;
}

int main(){
    int V,E;
    if(!(cin>>V>>E))return 0;
    vector<pair<int,pair<int,int>>>edges(E);
    for(int i=0;i<E;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back({w,{u,v}});
        edges.push_back({w,{v,u}});
    }
    sort(edges.begin(),edges.end(),greater<pair<int,pair<int,int>>>()); //For Maximum spanning tree
    //sort(edges.begin(),edges.end()); //For Minimum spanning tree


    vector<int>p(V);
    for(int i=0;i<V;i++)p[i]=i;
    int total=0,cnt=0;

    cout<<"Edges in MST:\n";
    for(auto&e:edges){
        int w=e.first;
        int u=e.second.first;
        int v=e.second.second;
        if(merge(p,u,v)){
            cout<<u<<"-"<<v<<":"<<w<<endl;
            total+=w;
            cnt++;
            if(cnt==V-1)
                break;
        }
    }
    cout<<"Total Wt: "<<total<<endl;

    return 0;
}
