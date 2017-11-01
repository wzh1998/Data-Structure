//
//  约瑟夫.cpp
//  Data Structure
//
//  Created by 王子豪 on 2017/10/27.
//  Copyright © 2017年 王子豪. All rights reserved.
//

#include <stdio.h>
#include <cstdlib>
#include <iostream>

using namespace std;

typedef struct Node{
    int Value;
    struct Node *next;
}Node,*hNode,*pNode;

void Init(hNode *head){
    (*head)->next = *head;
}

void Del(hNode head,int size,int k){
    int i;
    pNode p = head;
    pNode q;
    for(;size > 1;size--){
        for(i=1;i<k-1;i++) p = p->next;
        q = p->next;
        p->next = q->next;
        cout << q->Value << ',';
        p = p->next;
    }
    cout << p->Value ;
}

void Insert(Node *h, int position, int x){
    pNode p = h;
    pNode q = h;
    int i = 1;
    if (position == 1){
        p->Value = x;
        p->next = p;
        return;
    }
    while(i < position - 1){
        p=p->next;
        i++;
    }
    q=(pNode)malloc(sizeof(Node));
    q->Value=x;
    q->next=p->next;
    p->next=q;
}

int main(void){
    int timer,man,M;
    cin >> man;
    getchar();
    cin >> M;
    hNode h = ((hNode)malloc(sizeof(Node)));
    Init(&h);
    for (timer = 1; timer <= man; timer++){
        Insert(h, timer, timer);
    }
    M += 1;
    if(M > 1)
        Del(h, man, M);
    else{
        for(timer = 1; timer < man; timer++)
            cout << timer << ',';
        cout << man;
    }
    return 0;
}
