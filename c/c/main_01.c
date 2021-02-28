#include "main.h"
#include "list.h"

int main(int argc, char *argv[])
{
    list *l0 = NULL;
    u16 hossz = 0;

    for(u8 i = 1;i<10;i++){
        l0 = list_pushforward(l0,i);
    }
    list_print(l0);
    
    for(u8 i = 100; i>80; i--){
        l0 = list_pushback(l0,i);
    }
    
    printf("Na mehet\n");

    list_print(l0);
    list_length(l0,&hossz);
    printf("A lista hossza: %d.\n",hossz);

    list_free(l0);

    return 0;
}