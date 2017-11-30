//
//  约瑟夫问题及其变形综整.cpp
//  Data Structure
//
//  Created by 王子豪 on 2017/11/30.
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
