//
//  图论-最短路-Bellman-Ford.cpp
//  Data Structure
//
//  Created by 王子豪 on 2017/12/15.
//  Copyright © 2017年 王子豪. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <iostream>
#include <cstring>

#define MAX_E 10000
#define MAX_V 10000
#define INF 9999999

using namespace std;

struct edge{
    int from;
    int to;
    int cost;
};
edge es[MAX_V];
int d[MAX_E];
int V,E;

void shortest_path(int s){
    for(int i = 0;i < V;i++) d[i] = INF;
    d[s] = 0;
    while(true){
        bool update = false;
        for(int i = 0;i < E;i++){
            edge e = es[i];
            if(d[e.from] != INF && d[e.to] > d[e.from] + e.cost){
                d[e.to] = d[e.from] + e.cost;
                update = true;
            }
        }
        if(!update) break;
    }
}

//寻找负根

bool find_nagative(){
    memset(d, 0, sizeof(d));
    
    for(int i = 0;i < V;i++){
        for(int j = 0;j < E;j++){
            edge e = es[j];
            d[e.to] = d[e.from] + e.cost;
            
            if(i == V - 1) return true;
        }
    }
    return false;
}
