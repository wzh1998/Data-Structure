//
//  图论-最短路-Dijkstra-邻接表.cpp
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
