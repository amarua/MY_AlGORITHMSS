#include<iostream>
#include<vector>
#include<algorithm>
#include <numeric>
using namespace std;
#define int long long
const int mx = 2e5 + 7;
vector<int> ar[mx];
int d = 0;
int dfs(int v,int p){   //vertex,parent
    int d1 = 0, d2 = 0;
    for(auto x: ar[v]){
        if( x == p) continue;
        int curd = dfs(x,v);
        if(curd > d1){
            d2 = d1;
            d1 = curd;
        }else if(curd > d2){
            d2 = curd;
        }
    }
    d = max(d, d1 + d2);
    return 1 + max(d1,d2);
}
int32_t main(){
    int n; cin>>n;
    int a,b;
    for(int i = 1;i <= n-1 ; i++){
        cin>>a>>b;
        ar[a].push_back(b);
        ar[b].push_back(a);
    }
    dfs(1,-1);
    cout<<d<<endl;
    return 0;
}