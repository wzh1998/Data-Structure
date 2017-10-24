//
//  二叉搜索树.cpp
//  Data Structure
//
//  Created by 王子豪 on 2017/10/24.
//  Copyright © 2017年 王子豪. All rights reserved.
//

#include <stdio.h>


typedef struct node{
    int val;
    node *lch;
    node *rch;
}node;

node *insert(node *p, int x){
    if(p == NULL){
        node *q = new node;
        q->val = x;
        q->lch = NULL;
        q->rch = NULL;
        return q;
    }
    else{
        if(x < p->val) p->lch = insert(p, x);
        else p->rch = insert(p,x);
        return p;
    }
}

bool find(node *p,int x){
    if(p == NULL) return false;
    else if(x < p->val) find(p->lch,x);
    else if(x > p->val) find(p->rch,x);
    else if (x == p->val) return true;
    
    return false;
}

node *remove(node *p,int x){
    if(p == NULL) return NULL;
    else if(x < p->val) remove(p->lch, x);
    else if(x > p->val) remove(p->rch, x);
    else if(p->lch == NULL){      //能走到这一步说明此时 p->val == x
        node *q = p->rch;
        delete p;
        return q;
    }
    else if(p->lch->rch == NULL){
        node *q = p->lch;
        q->rch = p->rch;
        delete p;
        return q;
    }
    else{
        node *q;
        for(q = p->lch;q->rch->rch != NULL;q = q->rch);
        node *r = q->rch;
        q->rch = r->lch;
        r->lch = p->lch;
        r->rch = p->rch;
        delete p;
        return r;
    }
    return p;
}
int main(void){
    node *root = NULL;
    root = insert(root,1);
    find(root,1);
}

