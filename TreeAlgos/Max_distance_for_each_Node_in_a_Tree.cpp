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
queue<int> q;
int res[mx] = {};
int bfs(int src) {
	vector<int> d(n+1, -1);
    q = {};
	d[src] = 0;
	res[src] = max(res[src], d[src]);
	q.push(src);
 
	while(!q.empty()) {
		top = q.front();
		q.pop();
 
		for(int v: ar[top]) {
			if(d[v] == -1) {
				q.push(v);
				d[v] = d[top] + 1;
				res[v] = max(res[v], d[v]);
			}
		}
	}
	return top;
}
int32_t main(){
    int u,v; cin>>n;
    for(int i = 1; i <= n - 1;i++){
        cin>>u>>v;
        ar[u].push_back(v);
        ar[v].push_back(u);
    }
    int end1 = bfs(1);
    int end2 = bfs(end1);
    bfs(end2);
    for(int i = 1; i <= n;i++){
        cout<<res[i]<<" ";
    }
    return 0;
}