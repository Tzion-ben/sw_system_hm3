#include <stdio.h>
#include "txtfindHelp.h"
#define strToSentSize 50
 
int main (){
char strToSent [strToSentSize]={'\0'};
char order='0';
int ch=0;
int i=0;
while ((ch=getchar())!=' '){
    strToSent[i]=ch;  
    i++;
}
order=(ch=getchar());

if(order=='b'){
    print_similar_words(strToSent);
}
else if(order=='a'){
    print_lines(strToSent);
}

    return 0;
}
