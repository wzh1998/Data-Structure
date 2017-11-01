//
//  中缀表达式转后缀(Infix_to_Postfix).cpp
//  Data Structure
//
//  Created by 王子豪 on 2017/10/27.
//  Copyright © 2017年 王子豪. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>

using namespace std;
int pri(char x){
    if(x == '(') return -2;
    if(x == '*' || x == '/') return 1;
    else if(x == '+' || x == '-') return -1;
    return 0;
}

int main(void){
    stack<char> myStack;
    string s;
    getline(cin,s);
    int i = 0;
    char x = s[i];
    while(i < s.length()){
        if(x >= '0' && x <= '9') cout << x << ' ';
        else if(x == '(') myStack.push(x);
        else if(x == ')'){
            char y = myStack.top();
            while(y != '('){
                cout << myStack.top() << ' ';
                myStack.pop();
                y = myStack.top();
            }
            myStack.pop();
            
        }
        else{
            if(!myStack.empty()){
                int r_y = pri(myStack.top());
                int r_x = pri(x);
                while(r_y >= r_x && !myStack.empty() && r_y != '('){
                    cout << myStack.top() << ' ';
                    myStack.pop();
                    if(myStack.empty()) break;
                    r_y = pri(myStack.top());
                }
            }
            myStack.push(x);
        }
        i += 2;
        if(!(i < s.length())) break;
        x = s[i];
    }
    while(!myStack.empty()){
        cout << myStack.top() << ' ';
        myStack.pop();
    }
    return 0;
}
