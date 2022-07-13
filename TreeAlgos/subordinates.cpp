#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long
const int mx = 2e5 + 7;
vector<int> ar[mx];
int res[mx] = {};
int dfs(int i){
    int cnt = 0;
    for(auto x: ar[i]){
        cnt += 1 + dfs(x);
    }
    return res[i]= cnt;
}
int32_t main(){
    int n,boss; cin>>n;
    for(int i = 2; i <= n;i++){
        cin>>boss;
        ar[boss].push_back(i);
    }
    dfs(1);
    for(int i = 1; i <= n;i++){
        cout<<res[i]<<" ";
    }
    return 0;
}