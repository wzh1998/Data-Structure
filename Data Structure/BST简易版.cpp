//
//  BST简易版.cpp
//  Data Structure
//
//  Created by 王子豪 on 2017/11/10.
//  Copyright © 2017年 王子豪. All rights reserved.
//

#include <queue>
#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

struct BSTNode{
    int val;
    BSTNode *left;
    BSTNode *right;
};

void InsertNode(BSTNode *&root, int data)
{
    if(root == NULL)
    {
        root = new BSTNode;
        root->left = NULL;
        root->right = NULL;
        root->val = data;
    }
    else if(root->val < data)
        InsertNode(root->right,data);
    else if(root->val > data)
        InsertNode(root->left,data);
    else
        ;
}

void InorderTranversal(BSTNode *treeNode)
{
    if (treeNode != NULL)
    {
        InorderTranversal(treeNode->left);
        cout << treeNode->val << ",";
        InorderTranversal(treeNode->right);
    }
}

void PostOrderTranversal(BSTNode *treeNode)
{
    if (treeNode != NULL)
    {
        PostOrderTranversal(treeNode->left);
        PostOrderTranversal(treeNode->right);
        cout << treeNode->val << ",";
    }
}

int main(void){
    int temp = 0;
    char x = '\0';
    BSTNode *root = NULL;
    while(scanf("%d",&temp) != EOF){
        if(temp == '\n') break;
        InsertNode(root,temp);
        x = getchar();
        if(x == '\n') break;
    }
    PostOrderTranversal(root);
    cout << "\n";
    InorderTranversal(root);
    cout << "\n";
    
    return 0;
}
