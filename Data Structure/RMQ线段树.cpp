//
//  RMQ线段树.cpp
//  Data Structure
//
//  Created by 王子豪 on 2017/11/27.
//  Copyright © 2017年 王子豪. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

const int MAX_N = 1 << 17;
int n;
int dat[2 * MAX_N - 1];

void init(int n_){
    n = 1;
    while(n < n_) n *= 2;
    
    for(int i = 0;i < n * 2 - 1;i++) dat[i] = MAX_N;
}
void update(int k,int a){
    k += n - 1;
    dat[k] = a;
    while(k > 0){
        k = (k - 1) / 2;
        dat[k] = min(dat[k * 2 - 1],dat[k * 2 - 1]);
    }
}
int query(int a,int b,int k,int l,int r){
    if(r <= a || l >= r) return INT_MAX;
    if(a <= l && b >= r) return dat[k];
    else{
        int vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
        int vr = query(a, b, k * 2 + 2, (l + r) / 2 , r);
        return min(vl,vr);
    }
}

int main(void){
    
    return 0;
}
