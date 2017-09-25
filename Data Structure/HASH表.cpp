#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

typedef struct NODE{
    int data;
    struct NODE* next;
}NODE;

typedef struct _HASH_TABLE{
    NODE* value[10];
}HASH_TABLE;

HASH_TABLE* create_hash_table(){
    HASH_TABLE *pHashTb1 = (HASH_TABLE*) malloc (sizeof(HASH_TABLE));
    //    cout << sizeof(HASH_TABLE);
    memset(pHashTb1,0,sizeof(HASH_TABLE));
    return pHashTb1;
}
NODE* find_data_in_hash(HASH_TABLE *pHashTb1,int data){
    NODE* pNode;
    if(NULL == pHashTb1)
        return NULL;
    if(NULL == (pNode = pHashTb1 ->value[data % 10])){
        return NULL;
    }
    while(pNode){
        if(data == pNode->data)
            return pNode;
        pNode = pNode->next;
    }
    return NULL;
}

bool insert_data_into_hash(HASH_TABLE* pHashTb1,int data){
    NODE* pNode;
    if(NULL == pHashTb1->value[data % 10]){
        pNode = (NODE*)malloc(sizeof(NODE));
        memset(pNode,0,sizeof(NODE));
        pNode->data = data;
        return true;
    }
    
    if(NULL != find_data_in_hash(pHashTb1, data)){
        return false;
    }
    
    pNode = pHashTb1->value[data % 10];
    while(NULL != pNode->next){
        pNode = pNode->next;
    }
    pNode->next = (NODE*)malloc(sizeof(NODE));
    memset(pNode->next,0,sizeof(NODE));
    pNode->next->data = data;
    return true;
}

bool delete_data_from_hash(HASH_TABLE* pHashTb1,int data){
    NODE *pHead;
    NODE *pNode;
    if(NULL == pHashTb1 || NULL == pHashTb1->value[data % 10]){
        return false;
    }
    if(NULL == (pNode = find_data_in_hash(pHashTb1, data))){
        return false;
    }
    if(pNode == pHashTb1->value[data % 10]){
        pHashTb1->value[data % 10] = pNode->next;
        goto final;
    }
    pHead = pHashTb1->value[data % 10];
    while(pNode != pHead->next)
        pHead = pHead->next;
    final:
    free(pNode);
    return true;
}
int main(void){
    HASH_TABLE* mynewone;
    mynewone = create_hash_table();
    insert_data_into_hash(mynewone, 1);
    insert_data_into_hash(mynewone, 4);
    insert_data_into_hash(mynewone, 5);
    
    
    return 0;
    
}

