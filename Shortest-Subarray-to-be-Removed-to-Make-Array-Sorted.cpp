#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int l = 0, r = n-1;
        while(l < n-1 && arr[l] <= arr[l+1]) l++;
        while(r > 0 && arr[r-1] <= arr[r]) r--;
        int res = max(0,min(r,n-l-1));
        int s = 0;
        while(s <= l && r < n){
            if(arr[s] <= arr[r]){
                res = max(0,min(res,r-s-1));
                s++;
            }else{
                r++;
            }
        }
        return res;
    }
};