//
//  八皇后问题.cpp
//  Data Structure
//
//  Created by 王子豪 on 2018/1/30.
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
#include <cmath>

using namespace std;

int n = 8;
int Column[8];
int result = 0;
void search(int row){
    if(row == n) result++;
    else{
        for(int i = 0;i < n;i++){
            bool ok = true;
            Column[row] = i;
            for(int j = 0;j < row;j++){
                if(Column[row] == Column[j] || row - Column[row] == j - Column[j] || row + Column[row] == j + Column[j]){
                    ok = false;
                    break;
                }
            }
            if(ok) search(row + 1);
        }
    }
}


int main(void){
    search(0);
    cout << result << endl;
    return 0;
}
