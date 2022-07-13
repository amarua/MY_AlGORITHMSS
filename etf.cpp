#include <iostream>
#include <cmath>
using namespace std;
long etf(long n){ //eular totient function
    long k=n;
    long nn=n;
    if(nn%2==0){ k/=2; while(nn%2==0) { nn/=2; }}
    for(int i=3;i<=sqrt(nn)+1;i+=2){
        if(nn%i==0){
            k*=(i-1); 
            k/=i; 
            while(nn%i==0) { nn/=i; }
        }
    }
    if(nn > 2){
        k*=(nn-1);
        k/=nn;
    }
    return k;
}