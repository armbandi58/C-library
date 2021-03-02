#include "main.h"
#include "list.h"
#include "list_komplex.h"

int main(int argc, char *argv[])
{
    list *l0 = NULL;
    komplex_list *lk = NULL;
    u16 hossz = 0;
    u8 j = 0;
    float tmp1 = 1.2, tmp2 = 2.3;

    for(u8 i = 0;i <= 10;i++){
        l0 = list_pushforward(l0,i);
    }
    list_print(l0);
    
    for(u8 i = 100; i>=80; i--){
        l0 = list_pushback(l0,i);
    }

    while(j < 10){
        lk = komplex_pushforward(lk,tmp1,tmp2);
        j++;
        tmp1 += 0.9;
        tmp2 += 1.1;
    }
    komplex_print(lk);
    printf("==================\n");

    tmp1 = 1.1;
    tmp2 = 2.2;
    for(u8 i = 0; i<10;i++){
        lk = komplex_pushback(lk,tmp1,tmp2);
        tmp1 -= 0.2;
        tmp2 -= 0.5;
    }
    //printf("Na mehet\n");
    komplex_print(lk);
    printf("================\n");

    list_print(l0);
    list_length(l0,&hossz);
    printf("A lista hossza: %d.\n",hossz);
    list_find(l0,7);
    list_find(l0,90);
    list_find(l0,50);

    list_free(l0);
    komplex_free(lk);

    return 0;
}