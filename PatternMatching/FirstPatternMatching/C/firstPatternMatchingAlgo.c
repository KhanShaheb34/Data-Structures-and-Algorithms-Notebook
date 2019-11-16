#include<stdio.h>

void patternMatching1(char *mainString, char *query, int pos[100]){
    int strLen=0, i, qStrLen=0, j, f, arrPos=0, found;

    while(mainString[strLen]!='\0') strLen++;
    while(query[qStrLen]!='\0') qStrLen++;

    for(i=0; i<strLen-qStrLen; i++){
        if(mainString[i]==query[0]) {
            f=1;
            for(j=1; j<qStrLen; j++){
                if(mainString[i+j]!=query[j]) {
                    f=0;
                    break;
                }
            }
            if(f==1){
                pos[arrPos]=i+1;
                arrPos++;
                i+=qStrLen-1;
            }
            else i++;
        }
    }
}

int main(){
    char str[100] = "Tomay Amar Shonar Bangla, Ami Tomay Valobashi! Tomay!", queryString[100] = "Tomay";
    int pos[100], i;
    for(i=0; i<100; i++) pos[i]=0;
    i=0;
    patternMatching1(str, queryString, pos);
    while(pos[i]!=0) printf("%d\t",pos[i]-1), i++;
    return 0;
}
