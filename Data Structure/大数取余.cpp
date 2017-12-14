//
//  大数取余.cpp
//  Data Structure
//
//  Created by 王子豪 on 2017/12/8.
//  Copyright © 2017年 王子豪. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;
long long int bigNumberMod(char num[]){
    int sum = 0;
    for(int i = 0;i < strlen(num);i++){
        sum = sum * 10 + num[i];
        sum %= 4;
    }
    return sum;
}
int main(void){
    char num[1000100];
    scanf("%s",num);
    long long int result = bigNumberMod(num);
    int map[] = {4,0,0,0};
    cout << map[result] << endl;
    return 0;
}


/* 1(1)    2(2)    3(3)    4 (4)
 1(1)    4(4)    9(4)    16(1)
 1(1)    8(3)    27(2)   64(4)
 1(1)    16(1)   81(1)   256(1)
 1(1)    32(2)   243(3)  1024(4)
 1(1)    64(4)   729(4)  4096(1)
 1(1)    128(3)  2187(2) 16384(4)
 1(1)    256(1)  6561(1) 65536(1)
 1(1)    512(2)
 1024(4)
 2048(3)
 4096(1)
 8192(2)
 
 
 */

