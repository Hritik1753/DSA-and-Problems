#include<bits/stdc++.h>
using namespace std;

// void make_adj(int garph[][],vector<vector<int>>&adj,int n,int m)
//error

// In C++, you cannot have an unspecified size for the second dimension of a 
// function parameter when declaring a multi-dimensional array. The size of 
// the second dimension must be specified. In other words, you need to specify 
// the size of the second dimension, like int graph[][some_size].

void make_adj(int graph[][2],vector<vector<int>>&adj,int n,int m){

    for(int i=0;i<m;i++){
        int u=graph[i][0];
        int v=graph[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

}


void bfs(vector<vector<int>>&adj,int start){

unordered_map<int,bool>visited;
    queue<int>q;
    q.push(start);

    visited[start]=true;

    while(!q.empty()){

        int k=q.size();

        for(int i=0;i<k;i++){
        int node=q.front();
        q.pop();
        cout<<node<<" ";

       for(auto &it:adj[node]){
        if(visited[it]!=true){
            q.push(it);
            visited[it]=true;
        }
       }

        }

        cout<<endl;

    }
}

int main(){

    int graph[6][2]={{0,1},{0,2},{1,2},{1,3},{2,4},{3,4}};

    // given graph is undirected grpah
    //first make adjacency list of graph

    // here grpah is consist of 5 nodes so =5
    int n=5;
    vector<vector<int>>adj(n);

    

    make_adj(graph,adj,n,6);

    // you can do bfs from any node with your sutibality
    int starting_node=0;
    bfs(adj,starting_node);

    // for(int i=0;i<5;i++){
    //     for(int j=0;j<adj[i].size();j++){
    //         cout<<adj[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    return 0;

}