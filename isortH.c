#include <stdio.h>
#include "isortH.h"

/**
 * this method guts a pointer to some place at the array
 * and runs i times and moves the i's elements one place to the right
 */
void shift_element(int* arr,int i){
    int numbersToJump=i;
    for(int k=0;k<numbersToJump;k++){
        *(arr+i)=*(arr+i-1);
        i--;
    }
}//end shift_element 

/**
 *this method is the isertionSort but eith the shift_element method
 * it use it to move the bigger element then the key to right side 
 */
void insertion_sort(int* arr , int len){
    int i, key,j=0;
    for(i=1;i<len;i++){
        int countForShift=0;
        key=*(arr+i);
        j=i-1;
        while(j>= 0 && *(arr+j)>key){            
            countForShift++; 
            j--;
        }
        shift_element((arr+j+1),countForShift);
        *(arr+j+1)=key;
    }
}//end insertion_sort
