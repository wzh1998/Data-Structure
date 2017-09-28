//
//  数据结构lab3.cpp
//  Data Structure
//
//  Created by 王子豪 on 2017/9/28.
//  Copyright © 2017年 王子豪. All rights reserved.
//

#include <stdio.h>

/*
 * Question1
 * (1) The best performance is O(1).This case happens when the num we want to search is just at the middle of the whole array.
 * (2) The worst performance is O(logn) which is base 2,this case happens when the num we want to search is at the beginning or the end of the array.
 * (3) int main(void){
        int arr[10000];
        for(int i = 0;i < 10000;i++)
            arr[i] = i;
        bool result = false;
        result = bSearch(arr,10000,5000);

    //(in this case, we just need one loop in fuction bsearch such that we can find the number we want. Cause it just at the middle of the whole array;
 
 * Question2
 *   对于选择排序，最好、最坏情况的复杂度都是O(n^2)，也就是说，其不存在紧确上界和下界。但是，对于交换次数上是有差别的。最少交换次数出现的情况是数组已经是按从小到大排好序的了，此时使用选择排序将不会进行交换操作。最多的交换次数出现的情况是数组恰好是按倒序排序，即从大到小，这种情况下一共要进行n次交换操作。
 
 
 * Question3
 *    (1) O(n^4)
 *    (2) O(n^3)
 *    (3) O(logn)
 *    (4) O(n * logn)


 *  Question4
 *    (1)O(n^4)
 *    (2) O(n^2)
 *    (3) O(logn)

 *  Question5
 *  The worst situation happens if and only if the whole array is strict increasing sequence.And in this situation, currentMax will update for (data.length - 1).（不算一开始附值的话）


*/
