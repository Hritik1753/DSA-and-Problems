#include<bits/stdc++.h>
using namespace std;

pair<string, int> solve(int i, int j, int p[], int n, vector<vector<pair<string, int>>> &dp) {
        if(i == j) {
            string s = "";
            s = (i - 1) + 'A';
            return {s, 0};
        }
        
        if(dp[i][j].second != -1)
            return dp[i][j];
            
        int mini = 1e9;
        string str;
        
        for(int k = i; k < j; k++) {
            auto p1 = solve(i, k, p, n, dp);
            auto p2 = solve(k + 1, j, p, n, dp);
            
            int cost = p1.second + p2.second + p[i - 1] * p[k] * p[j];
            string s = "(" + p1.first + p2.first + ")";
            
            if(cost < mini) {
                mini = cost;
                str = s;
            }
        }
        
        return dp[i][j] = {str, mini};
    }

    string matrixChainOrder(int p[], int n){
        vector<vector<pair<string, int>>> dp(n, vector<pair<string, int>> (n, {"", -1}));
        auto pair = solve(1, n - 1, p, n, dp);
        return pair.first;
    }

int main(){
    
    int n=5;
    int p[]={40, 20, 30, 10, 30};
   string s=matrixChainOrder(p,n);
   cout<<s<<endl;

}