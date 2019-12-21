#include <stdio.h>
#include "isortH.h"
#define arraySize 50

 int main(){
     int arr[arraySize]={0};
     for(int i=0;i<arraySize;i++){
        int num=0;
        printf("Chose a number\n");
        scanf("%d",&num); 
        *(arr+i)=num;
     }//insertion of 50 numbers

     insertion_sort(arr,arraySize);
     for(int i=0;i<arraySize;i++){
     if(i==0)
        printf("%d",arr[i]);
      printf(",%d",arr[i]);
     }
     printf("\n");
     return 0;
 }