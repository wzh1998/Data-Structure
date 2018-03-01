//
//  矩阵快速幂.cpp
//  Data Structure
//
//  Created by 王子豪 on 2018/3/1.
//  Copyright © 2018年 王子豪. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <queue>
#include <vector>
#include <stack>
#include <set>
#include <cmath>

using namespace std;
typedef long long int ll;

#define MAX_LENGTH 25
#define MOD 1000000007

ll T,n;
ll x[MAX_LENGTH][MAX_LENGTH];
ll result[MAX_LENGTH][MAX_LENGTH];

void Matrix_Multi(ll arr1[][MAX_LENGTH],ll arr2[][MAX_LENGTH],ll result[][MAX_LENGTH]){
    for(int i = 0;i < T;i++){
        for(int j = 0;j < T;j++){
            ll temp = 0;
            for(int z = 0;z < T;z++) temp += arr1[i][z] * arr2[z][j] % MOD;
            result[i][j] = temp % MOD;
        }
    }
}

void Matrix_mod_power(){
    ll res[MAX_LENGTH][MAX_LENGTH];
    ll mxtemp[MAX_LENGTH][MAX_LENGTH];
    for(int i = 0;i < T;i++){
        for(int j = 0;j < T;j++){
            if(i == j) res[i][j] = 1;
            else res[i][j] = 0;
        }
    }
    ll temp_n = n;
    while(temp_n > 0){
        if(temp_n & 1){
            Matrix_Multi(res, x, mxtemp);
            for(int i = 0;i < T;i++){
                for(int j = 0;j < T;j++) res[i][j] = mxtemp[i][j];
            }
        }
        Matrix_Multi(x, x, mxtemp);
        for(int i = 0;i < T;i++){
            for(int j = 0;j < T;j++) x[i][j] = mxtemp[i][j];
        }
        temp_n >>= 1;
    }
    
    for(int i = 0;i < T;i++){
        for(int j = 0;j < T;j++) cout << res[i][j] << " ";
        cout << endl;
    }
}

int main(void){
    
    cin >> T >> n;
    for(int i = 0;i < T;i++){
        for(int j = 0;j < T;j++){
            scanf("%lld",&x[i][j]);
        }
    }
    Matrix_mod_power();
    
    return 0;
}
