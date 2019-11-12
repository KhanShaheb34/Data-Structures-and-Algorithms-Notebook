#include <stdio.h>

void transitionTable(char *query, int M, int TF[][256]){
    int i, lps=0, x;

    for(x=0; x<256; x++) TF[0][x]=0;
    TF[0][query[0]]=1;

    for(i=1; i<=M; i++){
        for(x=0; x<256; x++) TF[i][x]=TF[lps][x];
        TF[i][query[i]]=i+1;
        if(i<M) lps = TF[lps][query[i]];
    }
}

void patternMatching2(char *query, char *mainString){
    int M = 0, N = 0;
    while(mainString[N]!='\0') N++;
    while(query[M]!='\0') M++;
    int TF[M+1][256];

    transitionTable(query, M, TF);

    int i, j=0;
    for(i=0; i<N; i++){
        j=TF[j][mainString[i]];
        if(j==M) printf("%d\t", i-M+1);
    }
}

int main(){
    char str[100]="Tomay Amar Shonar Bangla, Ami Tomay Valobashi! Tomay!", query[100]="Tomay";
    patternMatching2(query, str);
    return 0;
}
