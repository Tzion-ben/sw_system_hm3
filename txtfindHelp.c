#include <stdio.h>
#include <string.h>
#include "txtfindHelp.h"

#define LINE 256
#define WORD 30

/**
 * this function guts the string from the user and counting the length
 * of it, it eill be ends by enter
 */
void getLine(char s[]){
    int lineLengh=0;
    int i=1;
    int ch=0;
    while((ch=getchar())!='\n'){
        s[i]=ch; 
        i++;
        lineLengh++;
    }
}

/**
 * this function guts the string from the user and counting the length
 * of it, it will be end with spaces, tabs or enter
 */
void getWord(char w[]){
int wordLength=0;
int i=1;
int ch=0;
    while((ch=getchar()))
    {
        if((ch!='\n')&&(ch!='\t')&&(ch!=' ')){
        w[i]=ch;
        i++;
        wordLength++;
    }
        else
            break;
    }
}

/**
 * this fynction checking if str2 contains at str1
 */
int subStrings(char *str1,char *str2){
    int subStr=1;//returns 1 if str2 is contained at str1
    if(strlen(str1)<strlen(str2)){//if str2 is longer then str1 it can't happened
        subStr=0;
        return subStr;
    }
    else{
        char *placeOfSub=strstr(str1,str2);
        if(placeOfSub==(NULL)){
            subStr=0;
            return subStr;
        }
    }
    return subStr;
}

int similar (char *s, char *t, int n){
    int out=0;
    if(strlen(s)>=strlen(t)){
        if(n==0){//if n is zere then we compare the strings
        // to know if they are equal or not
            int result=strcmp(t,s);
            if(result==0){
                out=1;
                return out;
            }
        }//else, if n >0:
        int i=0;int j=0;int runT=0;
        char tempStr [strlen(t)];//help string to check if the strings are equal
        while((strlen(s)>i)||(strlen(t)>j)){
            if((s[i]==t[j])&&(strlen(t)>j)){
                tempStr[runT]=t[j];
                runT++;j++;
            }
            else
                n--;
            i++;//the s string keep running
        }//end while
        int result=strcmp(t,tempStr); 
        if((n==0)&&(result==0)){
            out=1;
            return out;
        }
    }
    return out;
}

void print_lines(char * str){
char lineX [LINE]={'\0'};
int ch=0;
    while ((ch=getchar())!=EOF){//reading all the file to Strings
        lineX[0]=ch;//reading the first letter
        getLine(lineX);
        int subS=0;//for the answer if the str is subString at spesific line
        subS=subStrings(lineX,str);
        if(subS==1){//printing only if the str is inv th line
            printf("%s\n",lineX);
        }
    }//end of the while to read the file  
}

void print_similar_words(char * str){
int ch=0;
    while ((ch=getchar())!=EOF){//reading all the file to Strings
        char wordX [WORD]={'\0'};
        wordX[0]=ch;//reading the first letter
        getWord(wordX);

        int simelarsIf1=0;//for the answer if the str is subString at spesific line when n is 1
        int simelarsIf0=0;//for the answer if the str is subString at spesific line when n is 0

        simelarsIf1=similar(wordX,str,1);
        if(simelarsIf1!=1)
            simelarsIf0=similar(wordX,str,0);

        if((simelarsIf1==1)||(simelarsIf0==1)){//printing only if the str is inv th line
            printf(" %s\n",wordX);
        }
    }//end of
} 