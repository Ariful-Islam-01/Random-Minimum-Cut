#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>edges;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        edges.push_back({u,v});
    }
    int f=n+1;
    vector<int>used;
    int x=min((int)edges.size(),n-2);
    map<pair<int,int>,int>done;
    for(int i=0;i<x;i++){

        auto u=edges[i];
        int v1=u.first;
        int v2=u.second;
        vector<pair<int,int>>e;
        for(int j=i;j<edges.size();j++){
            if(done[edges[j]])continue;

            if(edges[j].first==v1||edges[j].first==v2){
                edges[j].first=f;
            }
            if(edges[j].second==v1||edges[j].second==v2){
                edges[j].second=f;
            }
        }
        f++;
        done[edges[i]]=1;

        for(int j=i;j<edges.size();j++){
            if(edges[i].first==edges[i].second){
                done[edges[i]]=1;
            }
        }



    }

    int ans=edges.size()-x;
    cout<<ans<<endl;

}