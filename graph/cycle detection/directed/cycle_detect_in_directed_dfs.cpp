#include<bits/stdc++.h>
using namespace std;

// To find cycle in a directed graph we can use the Depth First Traversal (DFS) technique.
// It is based on the idea that there is a cycle in a graph only
// if there is a back edge [i.e., a node points to one of its ancestors] present in the graph.

// To detect a back edge, we need to keep track of the nodes visited till now and the nodes that
// are in the current recursion stack [i.e., the current path that we are visiting]. If during 
// recursion, we reach a node that is already in the recursion stack, there is a cycle present in the graph.

void make_adj(vector<vector<int>>&graph,int m,vector<vector<int>>&adj){
    for(int i=0;i<m;i++ ){
        int u=graph[i][0];
        int v=graph[i][1];
        adj[u].push_back(v);
        // adj[v].push_back(u);
    }
}

bool cyclic_detect(vector<vector<int>>&adj,unordered_map<int,bool>&visited,int node,unordered_map<int,bool>&dfs_visited){
    visited[node]=true;
    dfs_visited[node]=true;
    for(auto &it:adj[node]){
        if(visited[it]!=true){
            if(cyclic_detect(adj,visited,it,dfs_visited)){
                return true;
            }
        }
        else{
            if(dfs_visited[it]){
                return true;
            }
        }
    }
    dfs_visited[node]=false;
    return false;
} 


int main(){

 int m;
    cout<<"enter number of edges\n";
    cin>>m;

    cout<<"enter number of nodes in the graph\n";
    int n;
    cin>>n;
    
    bool iscycle=false;

    cout<<"set edges in graph\n";
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

    

    vector<vector<int>>adj(n);

    make_adj(graph,m,adj);

    unordered_map<int,bool>visited,dfs_visited;

    for(int i=0;i<n;i++){
        if(visited[i]!=true){
            if(cyclic_detect(adj,visited,i,dfs_visited)){
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