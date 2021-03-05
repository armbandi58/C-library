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
    printf("A lista hossza(normal): %d.\n",hossz);
    komplex_length(lk,&hossz);
    printf("A lista hossza(komplex): %d.\n",hossz);
    printf("================\n");

    list_find(l0,7);
    list_find(l0,90);
    list_find(l0,50);
    printf("================\n");

    //komplex_find(lk,9.30,tmp3);
    //komplex_find(lk,100.30,100.20);
    //    printf("\n");
  /*  __komplextoeuler2(2,2);
    float im = 2.5, re = 2.5;
    float tmp00 = pow(im,2)+pow(re,2);
    float res_abs = sqrt(tmp00);
    //float res_abs = 1.0;
    float res_deg =  im/re;
    res_deg = atan(res_deg);
    res_deg = (180/PI)*res_deg;
    printf("%.5f\n%.5f\n%.5f\n",res_abs,res_deg,tmp00);
    
    euler(2.2,3.3);*/

    float tmp000 = euler_abs(2.5,2.5);
    printf("%f\n",tmp000);
    tmp000 = euler_degre(2.5,2.5);
    printf("%f\n",tmp000);

    printf("================\n");
    komplex_position(lk,0);
    komplex_position(lk,3);
    komplex_position(lk,10);
    komplex_position(lk,19);
    komplex_position(lk,20);
    
    list_free(l0);
    komplex_free(lk);

    return 0;
}