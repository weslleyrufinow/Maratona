#include <stdio.h>

int main(){
    int a,b,c;
    char q;

    scanf("%d %d %d",&a,&b,&c);
    scanf("%*c");
    scanf("%c",&q);

    printf("%d %d %d\n",a,b,c);
    printf("%c",q);

return 0;}