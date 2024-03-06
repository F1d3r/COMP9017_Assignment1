#include <stdio.h>

int main(){
    
    float num;
    int odd_even = 1;
    int N;

    float points[N][2];

    while(scanf("%f", &num) != EOF){
        printf("%.2f", num);
        if(odd_even == 1){
            printf(", ");
            odd_even = 2;
        }else if(odd_even == 2){
            printf("\n");
            odd_even = 1;
        }
        getchar();
    }

    return 0;
}