#include <stdio.h>

int main(){
    //C : 센트, T : 테스트케이스 수, Q/D/N/P 단위
    int C,T,Q,D,N,P;
    scanf("%d",&T);
    for (int i = 0; i < T; i++) {
        Q = 0; D = 0; N = 0; P = 0;
        scanf("%d",&C);
        while (C >= 25) {
            C-=25;
            Q++;
        }
        while (C >= 10) {
            C-=10;
            D++;
        }
        while (C >= 5) {
            C-=5;
            N++;
        }
        while (C > 0) {
            C-=1;
            P++;
        }
        printf("%d %d %d %d\n",Q,D,N,P);
    }
    return 0;
}
