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


bool cyclic_detect_bfs(vector<vector<int>>&adj,unordered_map<int,bool>&visited,int node){
    
      queue<int>q;
        q.push(node);
        visited[node]=true;
        unordered_map<int,int>parent;
        parent[node]=-1;
        
        while(!q.empty()){
            int n=q.front();
            q.pop();
            visited[n]=true;
            
            for(auto &it:adj[n]){
                if(visited[it]!=true){
                    q.push(it);
                    parent[it]=n;
                }
                else{
                    if(parent[n]!=it){
                        return true;
                    }
                }
            }
        }

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

    unordered_map<int,bool>visited;
     
     for(int i=0;i<n;i++){
            if(visited[i]!=true){
                if(cyclic_detect_bfs(adj,visited,i)){
                    iscycle= true;
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