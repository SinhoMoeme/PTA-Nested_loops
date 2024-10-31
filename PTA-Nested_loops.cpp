#include<stdio.h>
int n,now=0,s=0;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        now+=i;
        s+=now;
    }
    printf("sum=%d",s);
    return 0;
}