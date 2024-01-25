#include<bits/stdc++.h>
using namespace std;

class graph{
    vector<vector<int>>adj;
    public:
    graph(int v){
        adj.resize(v);
    }
    void add_edge(int m,int n){
        adj[m].push_back(n);
    }

    void cycle_detect(){
       //calculate indegree first
      
      vector<int>ind(adj.size());
       for(int i=0;i<adj.size();i++){
        for(auto it:adj[i]){
            ind[it]++;
        }
       }

       int count=0;
       queue<int>q;

       for(int i=0;i<ind.size();i++){
        if(ind[i]==0){
            count++;
            q.push(i);
        }
       }

       while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto it:adj[node]){
            ind[it]--;
            if(ind[it]==0){
                q.push(it);
                count++;
            }
        }
       }

       if(count!=adj.size()){
        cout<<"yes cycle is present\n";
       }
       else{
       cout<<"there is no cycle is present in it\n";
       }

    }
};
int main(){

     graph g1(5);
g1.add_edge(0,1);
g1.add_edge(1,2);
g1.add_edge(2,4);
g1.add_edge(4,2);
g1.add_edge(2,3);
g1.add_edge(3,0);


g1.cycle_detect();

}