//
//  数据结构lab2.cpp
//  Data Structure
//
//  Created by 王子豪 on 2017/9/20.
//  Copyright © 2017年 王子豪. All rights reserved.
//


#include <stdio.h> 
#include <sys/time.h>
#include <iostream>

int linearSearch(int array[], int n, int search){  // 50 + 30
    for(int i=0; i<n; i++){ //(10 + 10 + 10 + 10) * (n + 1)
        if(array[i]==search){//10 * n
            printf("%d found at location %d.\n", search, i);//(50 + 10 + 10)
            return 0;//50
        }
    }
    printf("Not found! %d is not present in the list.\n", search);//50 + 10 + 10
    return 0;//50
    
    //Total = 80 + 40(n+1) + 10n + 120 = 240 + 50*n;
}
int binarySearch(int array[], int n, int search){ // 50 + 30
    int first = 0;//10
    int last = n - 1;//10 + 10
    int middle = (first+last)/2;//10 + 10 + 10
    while (first <= last) { //10 * (L + 1)
        if (array[middle] < search) // 10 * L
            first = middle + 1; // (10 + 10) * L
        else if (array[middle] == search) { //10 * L
            printf("%d found at location %d.\n", search, middle+1);//(50 + 10 + 10 + 10) * L
            break;
        }
        else
            last = middle - 1; //(10 + 10) * L
        middle = (first + last)/2; // (10 + 10 + 10) * L
    }
    if (first > last) // 10
        printf("Not found! %d is not present in the list.\n", search);//(50 + 10 + 10)
    return 0; // 50
    
    //Total = 280 + 170*L = 280 + 170(logn [base 2])
}

int main(){
    int arr[100000] = {0};
    for(int i = 0;i < 100000;i++){
        arr[i] = i;
    }
    struct timeval start , end,start2,end2;
//    memset(arr,0,sizeof(arr));
    
    gettimeofday(&start, NULL);
    linearSearch(arr, 100000, 50000);
    gettimeofday(&end, NULL);
    gettimeofday(&start2, NULL);
    binarySearch(arr, 100000, 50000);
    gettimeofday(&end2, NULL);
    double seconds = (end.tv_sec - start.tv_sec);
    seconds = seconds + (end.tv_usec -start.tv_usec)/ 1000000.0;
    double seconds2 = (end2.tv_sec - start2.tv_sec);
    seconds2 = seconds2 + (end2.tv_usec -start2.tv_usec)/ 1000000.0;
    printf("linear search took %f s \n" , seconds );
    printf("binary search took %f s \n" , seconds2 );
    /*
    Running result:
     
    50000 found at location 50000.
    50000 found at location 50001.
    linear search took 0.000185 s
    binary search took 0.000002 s
    */
}

/*  Q3
    1.linear O(n)
    2.logarithmic O(logn)
    3.we can reduce the complecity of this by:
        3.1 replace linear search witht binary search(the array need to be incresing or decreasing).
        3.2 we can break out of the for loop when we find the num we want.
        3.3 use more efficient search alg to reduce complexity from O(logn) to O(n) even O(1)

*/


