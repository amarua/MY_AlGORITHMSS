#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0" or num2=="0") return "0";
        int m=num1.length();
        int n=num2.length();
        vector<int>arr(m+n,0);
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                int p1=i+j;
                int p2=i+j+1;
                int sum=arr[p2]+(num1[i]-'0')*(num2[j]-'0');
                arr[p2]=sum%10;
                arr[p1]+=sum/10;
            }
        }
        string ans="";
        for(int i=0;i<n+m;i++){
            if(!(ans.length()==0 and arr[i]==0)) ans+=char(arr[i]+'0');
        }
        return ans;
    }
};