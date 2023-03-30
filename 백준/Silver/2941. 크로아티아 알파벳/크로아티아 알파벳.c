#include <stdio.h>
#include <string.h>

int main(){
    char S[101];
    int len,cnt = 0;
    scanf("%s",S);
    len = (int)strlen(S);
    for (int i = 0; i < len; i++) {
        switch (S[i]) {
            case 'd':
                if(S[i+1] == 'z' && S[i+2] == '=')
                    i+=2;
                if(S[i+1] == '-')
                    i++;
                break;
            case 'l':
            case 'n':
                if(S[i+1] == 'j')
                    i++;
                break;
            case 's':
            case 'c':
            case 'z':
                if(S[i+1] == '-' || S[i+1] == '=')
                    i++;
                break;
            default:
                break;
        }
        cnt++;
    }
    printf("%d",cnt);
    return 0;
}
