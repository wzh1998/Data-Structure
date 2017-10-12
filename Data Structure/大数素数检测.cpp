//
//  大数素数检测.cpp
//  Data Structure
//
//  Created by 王子豪 on 2017/10/12.
//  Copyright © 2017年 王子豪. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;
const int TRAILS = 5;


long witness(long a,long i,long n){
    if(i == 0) return 1;
    long x = witness(a,i/2,n);
    if(x == 0) return 0;
    long y = (x * x) % n;
    if(y == 1 && x != 1 && x != n - 1) return 0;
    if(i % 2 != 0)
        y = (a * y) % n;
    
    return y;
}
bool is_prime(long n){
    long HIGH = n - 2;
    long LOW = 2;
    srand(unsigned(time(NULL)));
    long rnum = rand() % (HIGH - LOW + 1) + LOW;
    for(int counter = 0;counter < TRAILS;counter++){
        if(witness(rnum, n - 1, n) != 1)
            return false;
    }
    return true;
    
}
int main(void){
    long x;
    cin >> x;
    while(x != EOF){
        if(x <= 3) {
            cout << "YES" << endl;
            cin >> x;
            continue;
        }
        if(is_prime(x))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
