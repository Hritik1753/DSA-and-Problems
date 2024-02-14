#include<bits/stdc++.h>
using namespace std;

const int N=1e5+2;

int tree[4*N];
long long a[N];


void build(int node,int st,int en){
    if(st==en){
        tree[node]=a[st];
        return;
    }

    int mid=(st+en)/2;
    build(2*node,st,mid);
    build(2*node+1,mid+1,en);
    tree[node]=tree[2*node]+tree[2*node+1];

}

int query(int node ,int st,int en,int l,int r){
    if(st>r || en<l){
        return 0;
    }
    if(st>=l && en<=r){
        return tree[node];
    }

    int mid=(st+en)/2;
   int q1= query(2*node,st,mid,l,r);
   int q2=query(2*node+1,mid+1,en,l,r);

   return q1+q2;

}

void update(int node,int st,int en,int idx,int val){
    if(st==en){
        a[st]=val;
        tree[node]=val;
        return ;
    }

    int mid=(st+en)/2;
    if(idx<=mid){
        update(2*node,st,mid,idx,val);
    }
    else{
        update(2*node+1,mid+1,en,idx,val);
    }

    tree[node]=tree[2*node]+tree[2*node+1];
}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    build(1,0,n-1);

    for(int i=1;i<=2*n-1;i++){
        cout<<tree[i]<<" ";
    }

    while(1){
        cout<<"enter your choice"<<endl;
        int x;
        cout<<"for query type 1\n for update type 2\n for exist type -1\n";
        cin>>x;
        if(x==1){
            int l,r;
            cin>>l>>r;
            cout<<query(1,0,n-1,l,r);
        }
       else if(x==2){
        int x,val;
       cout<<"enter position at wich you want to change and its value\n make sure position is in between the 0 to "<<n<<endl;
        cin>>x>>val;
        update(1,0,n-1,x,val);
       }
       else if(x==-1){
        break;
       }


    }

    return 0;
}