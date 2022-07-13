#include<iostream>
#include<vector>
#include<algorithm>
#include <numeric>
using namespace std;
#define int long long
const int mx = 2e5 + 7;
int levels = 21;
vector<vector<int>> dp(mx,vector<int>(levels));
int L[mx];  //store level of the nodes
vector<int> ar[mx];
void dfs(int u, int p, int l) 
{
    dp[u][0] = p;
    L[u] = l;
	for (int v: ar[u])
		if(v != p) 
		    dfs(v, u, l+1);
}
void preprocess(int n){
    dfs(1,-1,0);
    for(int i = 1;i < levels; i++){
        for(int j = 0; j <= n; j++){
            if(dp[j][i-1] != -1)
                dp[j][i] = dp[dp[j][i-1]][i-1];
        }
    }
}
int qry(int u,int v){
    if(L[u] < L[v]) swap(u,v);
    int diff = L[u] - L[v];
    for(int i = 0;i < levels;i++){
        if(diff & (1 << i)) u = dp[u][i];
    }
    if(u == v) return u;
    for(int i = levels - 1; i >= 0 ; i--){
        if(dp[u][i] != dp[v][i]){
            u = dp[u][i];
            v = dp[v][i];
        }
    }
    return dp[u][0];
}
int32_t main(){
    int n,q; cin>>n>>q;
    int u,v;
    for(int i = 2;i <= n ; i++){
        cin>>v;
        ar[v].push_back(i);
        ar[i].push_back(v);
    }
    preprocess(n);
    while(q--){
        cin>>u>>v;
        cout<<qry(u,v)<<endl;
    }
    return 0;
}