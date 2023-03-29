#include <stdio.h>

int main(){
    int M,N,sum_demi=0,min=0,tmp;
    scanf("%d",&M);
    scanf("%d",&N);
    for (int i = M; i <= N; i++) {
        tmp = 0;
        for (int  j = 2; j < i; j++) {
            if(i%j != 0)
                tmp++;
        }
        if(tmp == i - 2){
            sum_demi+=i;
            if(min == 0)
                min = i;
        }
    }
    if(sum_demi != 0)
        printf("%d\n%d",sum_demi,min);
    else
        printf("-1");
    return 0;
}
