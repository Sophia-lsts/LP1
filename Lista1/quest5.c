#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void check(char (*numcmp)(const char)(const char), (*), int (*cmp)(const char*, const char*)){
    printf("testando igualde\n");
    if(!(*cmp)(a,b))
        printf("igual");
    else
        printf("diferente");
}

int numcmp(const char *a, const char *b){
    if(atoi(a)==atoi(b))
        return 0;
    else
        return 1;
}

void main(){
    char s1[80], s2[80];
    int (*p) ();
    int (*p2) ();

    p = strcmp;
    p2 = numcmp;

    gets(s1);
    gets(s2);

    if(isalpha(*s1))
        check(s1,s2,p);
    else
        check(s1,s2,p2);
}