#include <stdio.h>
#include "txtfindHelp.h"
#define check 100
 
int main (){
char strToSent [check]={'\0'};
char order='0';
int ch=0;
int i=0;
while ((ch=getchar())!=' '){
    strToSent[i]=ch;  
    i++;
}
order=(ch=getchar());

printf("strToSent is :%s\n",strToSent);
if(order=='a'){
    print_similar_words(strToSent);
}
else if(order=='b'){
    print_lines(strToSent);
}

    return 0;
}
