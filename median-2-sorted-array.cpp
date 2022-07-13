#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        
        int n=A.size();
        int m=B.size();
        if(n > m) return findMedianSortedArrays(B,A);
        
        int totalLeft=(n+m+1)/2;
        int s=0;
        int e=n;
        while(s<=e){
            int mid=(s+e)/2;
            int countA=mid;
            int countB=totalLeft-countA;
            
            int LeftA=(countA==0)?INT_MIN:A[countA-1];
            int RightA=(countA==n)?INT_MAX:A[countA];
            int LeftB=(countB==0)?INT_MIN:B[countB-1];
            int RightB=(countB==m)?INT_MAX:B[countB];
            
            if(RightA < LeftB){
                s=mid+1;
            }else if(RightB < LeftA){
                e=mid-1;
            }else{
                int total=m+n;
                if(total%2 == 1){
                    return max(LeftA,LeftB);
                }else{
                    return (max(LeftA,LeftB)+min(RightA,RightB))/2.0;
                }
            }
        }
        return 0;
    }
};