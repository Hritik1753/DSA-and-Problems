#include<bits/stdc++.h>
using namespace std;

//it is also called khan's algorithm

class graph{
int k;
vector<vector<int>>adj;

public:
graph(int v){
    adj.resize(v);
    k=v;   
}
void add_edge(int m,int n){
    adj[m].push_back(n);
}

void toposort(){
    vector<int>in_degree(k);
    for(int i=0;i<adj.size();i++){
        for(int j=0;j<adj[i].size();j++){
            in_degree[adj[i][j]]++;
        }
    }

    queue<int>q;
    for(int i=0;i<in_degree.size();i++){
        if(in_degree[i]==0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int front=q.front();
        q.pop();
        cout<<front<<" ";
        for(auto &it:adj[front]){
            in_degree[it]--;
            if(in_degree[it]==0){
                q.push(it);
            }
        }
    }
}

};

int main(){
    graph g1(7);
g1.add_edge(1,2);
g1.add_edge(1,3);
g1.add_edge(2,4);
g1.add_edge(3,4);
g1.add_edge(4,5);
g1.add_edge(4,6);
g1.add_edge(5,6);
g1.toposort();
}