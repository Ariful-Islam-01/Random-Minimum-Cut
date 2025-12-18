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
    int x=n;
    map<pair<int,int>,int>done;
    for(int i=0;i<edges.size();i++){

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
        x--;
        for(int j=i;j<edges.size();j++){
            if(edges[i].first==edges[i].second){
                done[edges[i]]=1;
            }
        }
        
        if(x==2)break;

        



    }

    int ans=0;
    for(int i=0;i<edges.size();i++){
        if(!done[edges[i]])ans++;
    }
    cout<<ans<<endl;

}