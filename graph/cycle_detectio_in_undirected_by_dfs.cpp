#include<bits/stdc++.h>
using namespace std;

void make_adj(vector<vector<int>>&graph,int m,vector<vector<int>>&adj){
    for(int i=0;i<m;i++ ){
        int u=graph[i][0];
        int v=graph[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}


bool cyclic_detect(vector<vector<int>>&adj,unordered_map<int,bool>&visited,int node,int parent){
    visited[node]=true;
    for(auto &it:adj[node]){
        if(visited[it]!=true){
            if(cyclic_detect(adj,visited,it,node)){
                return true;
            }
        }
        else{
            if(parent!=it){
                return true;
            }
        }
    }

    return false;
}
int main(){
    int m;
    cin>>m;
    bool iscycle=false;
    vector<vector<int>>graph(m,vector<int>(2));
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        graph[i][0]=a;
        graph[i][1]=b;

        if(a==b){
            iscycle=true;
        }

        // for handling of self loop case we check here if a=b then self loop is present;
    }

    cout<<"enter number of nodes in the graph\n";
    int n;
    cin>>n;

    vector<vector<int>>adj(n);

    make_adj(graph,m,adj);

    unordered_map<int,bool>visited;
     
    for(int i=0;i<n && !iscycle;i++){
        if(visited[i]!=true){
            bool ans=cyclic_detect(adj,visited,i,-1);
            if(ans==true){
                
                iscycle=true;
                break;
            }
        }
    }

    if(iscycle!=true){
        cout<<"no there is no cycle in the graph\n";
    }
    else{
        cout<<"yes cycle  or self loop is present in our graph\n ";
    }


}