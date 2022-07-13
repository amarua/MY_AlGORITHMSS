#include<iostream>
#include<vector>
#include<algorithm>
#include <numeric>
using namespace std;
#define int long long
const int mx = 2e5 + 7;
int ar[mx];
int levels = 20;
vector<vector<int>> dp(mx,vector<int>(levels,-1));
int solv(int emp,int k){
    for(int i = 0;i<levels;i++){
        if(k&(1<<i)) emp = dp[emp][i];
        if(emp == -1) return -1;
    }
    return emp;
}
int32_t main(){
    int n,q; cin>>n>>q;
    int emp,k;
    for(int i = 2;i <= n ; i++){
        cin>>ar[i];
        dp[i][0] = ar[i];
    }
    for(int i = 1;i < levels; i++){
        for(int j = 2;j <= n; j++){
            if(dp[j][i-1] != -1) 
                dp[j][i] = dp[dp[j][i-1]][i-1];
        }
    }
    // for(int i = 1;i <= n ;i++){
    //     for(int j = 0;j < levels; j++){
    //         cout<<dp[i][j]<<" ";
    //     }cout<<endl;
    // }
    while(q--){
        cin>>emp>>k;
        cout<<solv(emp,k)<<endl;
    }
    return 0;
}