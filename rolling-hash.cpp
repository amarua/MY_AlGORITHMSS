#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string subStrHash(string s, int p, int m, int k, int hashValue) {
        long hash = 0;
        int n = s.length(), res = 1;
        long pk = 1;
        for (int i = n - 1; i >= 0; --i) {
            hash = (hash * p + code(s[i])) % m;
            if(i+k < n){
                hash = (hash - code(s[i+k]) * pk % m + m) % m;
            }else{
                pk = pk * p % m;
            }
            if (i+k <= n && hash == hashValue)
                res = i;
        }
        return res == -1 ? "" : s.substr(res,k);
    }
    int code(char c){
        return c-'a'+1;
    }
};