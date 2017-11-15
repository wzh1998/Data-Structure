//
//  AVL树.cpp
//  Data Structure
//
//  Created by 王子豪 on 2017/11/10.
//  Copyright © 2017年 王子豪. All rights reserved.
//

#include <stdio.h>
#include <cstdlib>
#include <iostream>

const int Z = 0;
const int LEFT = 1;
const int RIGHT = -1;

typedef struct AVLNode{
    int key;
    int bS;
    struct AVLNode *L_Child,*R_Child;
}AVLNode,*AVLTree;

void PreOrder(AVLTree root){
    if(NULL != root){
        printf("%d,",root->key);
        PreOrder(root->L_Child);
        PreOrder(root->R_Child);
    }
}

void Rotate_R(AVLTree *p){
    AVLTree lc=(*p)->L_Child;
    (*p)->L_Child=lc->R_Child;
    lc->R_Child=*p;
    *p=lc;
}

void Rotate_L(AVLTree *p){
    AVLTree rc=(*p)->R_Child;
    (*p)->R_Child=rc->L_Child;
    rc->L_Child=*p;
    *p=rc;
}

void LeftBalance(AVLTree *T){
    AVLTree lc = (*T)->L_Child;
    AVLTree rd = lc->R_Child;
    if(lc->bS == LEFT){
        (*T)->bS=lc->bS=Z;
        Rotate_R(T);
    }
    else if (lc->bS == RIGHT){
        if(rd->bS == LEFT){
            (*T)->bS=RIGHT;
            lc->bS=Z;
        }
        else if(rd->bS == Z){
            (*T)->bS=lc->bS=Z;
        }
        else if(rd->bS == RIGHT){
            (*T)->bS=Z;
            lc->bS=LEFT;
        }
        rd->bS=Z;
        Rotate_L(&((*T)->L_Child));
        Rotate_R(T);
    }
}

void RightBalance(AVLTree *T){
    AVLTree rc=(*T)->R_Child;
    AVLTree ld=rc->L_Child;
    if(rc->bS == RIGHT){
        (*T)->bS=rc->bS=Z;
        Rotate_L(T);
    }
    else if(rc->bS == RIGHT){
        if(ld->bS == RIGHT){
            (*T)->bS=LEFT;
            rc->bS=Z;
        }
        else if(ld->bS == Z){
            (*T)->bS=rc->bS=Z;
            
        }
        else if(ld->bS == LEFT){
            (*T)->bS=Z;
            rc->bS=RIGHT;
        }
        ld->bS=Z;
        Rotate_R(&((*T)->R_Child));
        Rotate_L(T);
    }
}


bool InsertAVL(AVLTree *t,int e,bool *taller){
    if(NULL == t)
        return false;
    if(NULL == *t){
        *t=(AVLTree)malloc(sizeof(AVLNode));
        if(NULL == *t)
            return false;
        (*t)->key=e;
        (*t)->R_Child=NULL;
        (*t)->L_Child = (*t)->R_Child;
        (*t)->bS = Z;
        *taller = true;
    }
    else{
        if(e==(*t)->key){
            *taller=false;
            return false;
        }
        else if(e<(*t)->key){
            if(false == InsertAVL(&((*t)->L_Child),e,taller))
                return false;
            if(*taller){
                if((*t)->bS == LEFT){
                    LeftBalance(t);
                    *taller=false;
                }
                else if((*t)->bS == Z){
                    (*t)->bS=LEFT;
                    *taller=true;
                }
                else if((*t)->bS == RIGHT){
                    (*t)->bS=Z;
                    *taller=false;
                }
            }
        }
        else{
            if(false == InsertAVL(&((*t)->R_Child),e,taller))
                return false;
            if(*taller){
                if((*t)->bS == RIGHT){
                    RightBalance(t);
                    *taller=false;
                }
                else if((*t)->bS == Z){
                    (*t)->bS=RIGHT;
                    *taller=true;
                }
                else if((*t)->bS == LEFT){
                    (*t)->bS=Z;
                    *taller=false;
                }
            }
        }
    }
    return true;
}

int main(void){
    AVLTree root=NULL;
    bool taller = false;
    int temp = 0;
    while(scanf("%d",&temp) != EOF){
        InsertAVL(&root,temp,&taller);
        getchar();
    }
    PreOrder(root);
}
