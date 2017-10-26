//
//  并查集.cpp
//  Data Structure
//
//  Created by 王子豪 on 2017/10/26.
//  Copyright © 2017年 王子豪. All rights reserved.
//

#include <stdio.h>

int pre[100];
int weight[100];
int MAX_N = 100;
void init(int n){
    for(int i = 0;i < MAX_N;i++){
        pre[i] = i;
        weight[i] = 0;
    }
}
int Find_loop(int x){
    int p = x;
    while(x != pre[x]){
        x = pre[x];
    }
    while(p != x){
        int tmp = pre[p];
        pre[p] = x;
        p = tmp;
    }
    return x;
}
int Find_recursion(int x){
    if(pre[x] != x) pre[x] = Find_recursion(pre[x]);
    return pre[x];
}

void unite(int x,int y){
    int p = Find_loop(x);
    int q = Find_loop(y);
    if(weight[x] < weight[y]){
        pre[p] = q;
        weight[q] += weight[p];
    }
    else{
        pre[q] = p;
        weight[p] += weight[q];
    }
}

bool same(int x,int y){
    return (Find_loop(x) == Find_loop(y));
}
