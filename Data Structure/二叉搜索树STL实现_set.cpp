//
//  二叉搜索树STL实现_set.cpp
//  Data Structure
//
//  Created by 王子豪 on 2017/10/24.
//  Copyright © 2017年 王子豪. All rights reserved.
//

//
//  二叉搜索树STL实现_set.cpp
//  Data Structure
//
//  Created by 王子豪 on 2017/10/24.
//  Copyright © 2017年 王子豪. All rights reserved.
//

#include <cstdio>
#include <iostream>
#include <set>

using namespace std;

int main(void){
    set<int> s;
    
    //insert
    s.insert(1);
    s.insert(3);
    s.insert(5);
    
    //find
    set<int>::iterator ite;
    ite = s.find(1);
    if(ite == s.end()) cout << "not found" << endl;
    else cout << "found" << endl;
    
    ite = s.find(2);
    if(ite == s.end()) cout << "not found" << endl;
    else cout << "found" << endl;
    
    s.erase(3);
    
    //other method to find
    if(s.count(3) != 0) cout << "found" << endl;
    else cout << "not found" << endl;
    
    //遍历
    for(ite = s.begin();ite != s.end();ite++){
        printf("%d ",*ite);
    }
    
    return 0;
}
