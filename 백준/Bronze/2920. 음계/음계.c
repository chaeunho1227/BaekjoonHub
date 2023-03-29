#include <stdio.h>
int main(){
    int input,tmp = 0;
    for (int i = 1; i <= 8; i++) {
        scanf("%d",&input);
        if(input == i)
            tmp++;
        else if (input == 9-i)
            tmp--;
        else
            break;
    }
    if(tmp == 8)
        printf("ascending");
    else if(tmp == -8)
        printf("descending");
    else
        printf("mixed");
    return 0;
}
