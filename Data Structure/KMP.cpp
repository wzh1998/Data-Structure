//
//  KMP.cpp
//  Data Structure
//
//  Created by 王子豪 on 2017/11/1.
//  Copyright © 2017年 王子豪. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <cstdlib>
#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

char wanted[1000];
char ori[1000];
int nextx[1000];
int real_next[1000];
int len_ori = 0;
int len_wan = 0;
bool result = false;

void KMP(){
    int i,j;
    for(i = 0,j = 0;i < len_ori;i++){
        while(j > 0 && wanted[j] != ori[i]) j = nextx[j-1];
        if(wanted[j] == ori[i]) j += 1;
        if(j == len_wan){
            cout << i - len_wan + 2 << endl;
            result = true;
        }
    }
}

void goNext(){
    int index = 1;
    int m_postfix = 0;
    while(index < len_wan){
        while(m_postfix > 0 && wanted[index] != wanted[m_postfix]) m_postfix = nextx[m_postfix - 1];
        if(wanted[index] == wanted[m_postfix]) m_postfix++;
        nextx[index] = m_postfix;
        index++;
    }
}
void getRealNext(){
    real_next[0] = 0;
    real_next[1] = 1;
    for(int i = 1;i < len_wan;i++){
        real_next[i] = nextx[i - 1] + 1;
    }
}
void printRealNext(){
    for(int z = 0;z < len_wan;z++){
        cout << real_next[z] << ",";
    }
    cout << endl;
}
int main(void){
    memset(nextx,0,sizeof(nextx));
    memset(real_next,0,sizeof(real_next));
    memset(wanted,'\0',sizeof(wanted));
    memset(ori,'\0',sizeof(ori));
    cin >> ori >> wanted;
    //    scanf("%s",ori);
    //    scanf("%s",wanted);
    for(len_ori = 0;ori[len_ori] != '\0';len_ori++);
    for(len_wan = 0;wanted[len_wan] != '\0';len_wan++);
    goNext();
    getRealNext();
    printRealNext();
    if(len_wan > len_ori) cout << "-1" << endl;
    else{
        KMP();
        if(result == false) cout << "-1" << endl;
    }
    return 0;
}
