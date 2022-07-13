// max distance for each of node in a tree
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
#define int long long
const int mx = 2e5 + 7;
int n = 0, top;
vector<int> ar[mx];
int s[mx]; 
void dfs_size(int cur, int par) {
	s[cur] = 1;
	for (int chi : ar[cur]) {
		if (chi != par) {
			dfs_size(chi, cur);
			s[cur] += s[chi];
		}
	}
}

int get_centroid(int cur, int par) {
	for (int chi : ar[cur]) {
		if (chi != par) {
			if (s[chi] * 2 > n) {
				return get_centroid(chi, cur);
			}
		}
	}
	return cur;
}

int32_t main(){
    int u,v; cin>>n;
    for(int i = 1; i <= n - 1;i++){
        cin>>u>>v;
        ar[u].push_back(v);
        ar[v].push_back(u);
    }
    dfs_size(1, -1);
	int centroid = get_centroid(1, -1);
	cout << centroid << '\n';
    return 0;
}