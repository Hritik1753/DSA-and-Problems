#include<bits/stdc++.h>
using namespace std;

// topological sort is the linear ordering of vertices such thatfor every edge u->v 
// u is always comes first then v is occuring
class graph{
int n;
vector<vector<int>>adj;

public:
graph(int v){
  n=v;
  adj.resize(n);
}

void add_edge(int m,int p){
    adj[m].push_back(p);
}
void topo_sort(stack<int>&s,unordered_map<int,bool>&visited,int node){
  visited[node]=true;
  for(auto &it:adj[node]){
    if(visited[it]!=true){
      topo_sort(s,visited,it);
    }
  }

  s.push(node);
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
stack<int>s;
unordered_map<int,bool>visited;
for(int i=0;i<6;i++){
  if(visited[i]!=true){
    g1.topo_sort(s,visited,i);
  }
}

while(!s.empty()){
cout<<s.top()<<" ";
s.pop();
}



}