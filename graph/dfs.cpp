#include<bits/stdc++.h>
using namespace std;

const int max_size=2;

void make_adj(int** arr, vector<vector<int>>&adj,int m,int n){
      for(int i=0;i<m;i++){
        int u=arr[i][0];
        int v=arr[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
      }

}


void dfs(vector<vector<int>>&adj,unordered_map<int,bool>&visited,int node){
    visited[node]=true;
    cout<<node<<" ";
    for(auto &it:adj[node]){
        if(visited[it]!=true){
            dfs(adj,visited,it);
        }
    }
}

int main(){
    int m,n;
    cin>>m>>n;

    // int arr[m][n];

    int** arr = new int*[m];
    for (int i = 0; i < m; i++) {
        arr[i] = new int[n];
    }


    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }



    int num_nodes;
    cin>>num_nodes;

    vector<vector<int>>adj(num_nodes);

    make_adj(arr,adj,m,n);
    unordered_map<int,bool>visited;
    for(int i=0;i<num_nodes;i++){
        if(visited[i]!=true){
            dfs(adj,visited,i);
        }
    }

    return 0;
}