#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Tree{
    vector<int>v;
    int N;
public:
    Tree(vector<int> ar){
        N = ar.size();
        v.resize(2*N);
        for(int i = 0;i<N;i++){
            v[i+N] = ar[i];
        }
        for(int i = N-1; i >= 1; i--){
            v[i] = v[i << 1] + v[i << 1 | 1];
        }
    }
    void update(int inx,int val){
        v[inx += N] = val;    //if the function is "add" replace '=' with '+=' here
        for(inx /= 2 ; inx >= 1;inx /= 2){
            v[inx] = v[inx << 1] + v[inx << 1 | 1];
        }
    }
    //0 indexed so can be called with qry(0,3)
    int qry(int l,int r){
        l += N; r += N;
        int s = 0;
        while( l <= r){
            if(l%2 == 1) s+= v[l++];
            if(r%2 == 0) s+= v[r--];
            l /= 2; r /= 2;
        }
        return s;
    }
};

int main(){
    Tree t({1,2,3,4,5,6,7});
    cout<<t.qry(1,3)<<endl;
    t.update(0,5);
    cout<<t.qry(0,3)<<endl;
    return 0;
}