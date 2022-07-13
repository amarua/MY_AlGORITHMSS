#include<bits/stdc++.h>
using namespace std;
int cntuptoN(int n,int d){
    int c = 0;
    for(int i=1;i<=n;i*=10){
        int divv=i*10;
        int quo =n/divv;
        int rem = n%divv;
        c += quo*i;
        if(d==0){
            c-=i;
        }
        if(rem >= d*i){
            c+=min(i,rem-d*i+1);
        }
    }
    return c;
}