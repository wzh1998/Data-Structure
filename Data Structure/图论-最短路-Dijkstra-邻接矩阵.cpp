//
//  图论-最短路-Dijkstra.cpp
//  Data Structure
//
//  Created by 王子豪 on 2017/12/15.
//  Copyright © 2017年 王子豪. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

#define MAX_E 10000
#define MAX_V 10000
#define INF 9999999

int cost[MAX_V][MAX_V];
int d[MAX_V];
bool used[MAX_V];
int V;

void dijkstra(){
    fill(d, d + V, INF);
    fill(used,used + V,INF);
    while(true){
        int v = -1;
        for(int u = 0;u < V;u++){
            if(!used[u] && (v == -1 || d[u] < d[v])) v = u;
        }
        if(v == -1) break;
        used[v] = true;
        for(int u = 0;u < V;u++){
            d[u] = min(d[u], d[v] + cost[u][v]);
        }
    }
}

