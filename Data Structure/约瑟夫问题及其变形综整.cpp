//
//  约瑟夫问题及其变形综整.cpp
//  Data Structure
//
//  Created by 王子豪 on 2017/11/30.
//  Copyright © 2017年 王子豪. All rights reserved.
//


//计算胜者
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;
int main(void){
    int n = -1;
    int m = -1;
    int s = 0;
    scanf("%d %d",&n,&m);
    for(int i = 2;i <= n;i++){
        s = (s + m) % i;
    }
    cout << s + 1<< endl;
    
    return 0;
}

// 数组模拟过程 O(mn)
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int main(void){
    int m,n,p;
    int arr[500];
    
    while(1){
        scanf("%d%d%d",&n,&p,&m);
        if(n == 0 && p == 0 && m == 0) break;
        for(int i = 0;i < n;i++) arr[i] = i + 1;
        int current = p - 1;
        int dead = 0;
        int num = 0;
        while(dead != n){
            if(arr[current] != 0){
                if(num == m - 1){
                    cout << arr[current];
                    (dead != n - 1) ? cout << "," : cout << endl;
                    arr[current] = 0;
                    num = 0;
                    dead++;
                    continue;
                }
                else
                    num++;
            }
            current = (current + 1) % n;
            
        }
    }
    return 0;
}
