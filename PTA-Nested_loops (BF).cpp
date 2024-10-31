#include<stdio.h>
int n,s=0;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=i;++j) s+=j;
    }
    printf("sum=%d",s);
    return 0;
}