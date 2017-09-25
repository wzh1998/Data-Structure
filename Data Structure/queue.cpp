//
//  queue.cpp
//  Data Structure
//
//  Created by 王子豪 on 2017/8/28.
//  Copyright © 2017年 王子豪. All rights reserved.
//

#include <algorithm>
#include <queue>
#include <cstdlib>
#include <iostream>

using namespace std;

template <class Telem>
class SqQueue: public queue<Telem>{
    Telem * elem;
    int front,rear,count;
    const int len;
    
public:
    SqQueue(int maxsz = 12): len(maxsz)
    {
        elem = new Telem[len];
        front = rear = 0;
        count = 0;
    };
    ~SqQueue(){ delete []elem;};
    void clear(){front = rear = 0;count = 0;};
    int leng(){return count;};
    bool empt(){return(count == 0);};
    bool full(){return(count >= len);};
    bool enque(Telem& el);
    Telem dlque();
    Telem getf();
};
template<class Telem> bool SqQueue<Telem>::enque(Telem& el){
    if(count >= len) return(false);
    else{
        elem[rear] = el;
        rear = (rear + 1) % len;
        count++;
        return (true);
    }
}

