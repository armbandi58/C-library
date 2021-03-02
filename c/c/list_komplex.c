#include "list_komplex.h"

komplex_list *komplex_pushforward(komplex_list *l0,float Re,float Im){
    komplex_list *uj = (komplex_list*)malloc(sizeof(komplex_list));
    uj -> data_Re = Re;
    uj -> data_Im = Im;
    uj -> next = l0;

    return uj;
}

komplex_list *komplex_pushback(komplex_list *l0,float Re,float Im){
    komplex_list *uj = (komplex_list*)malloc(sizeof(komplex_list));
    uj -> data_Re = Re;
    uj -> data_Im = Im;
    uj -> next = NULL;

    if(l0 == NULL){
        return uj;
    }else{
        komplex_list *p = l0;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = uj;
        return l0;
    }
}

void komplex_print(komplex_list *l0){
    komplex_list *p = l0;
    while(p != NULL){
        printf("[%.2f:%.2f]\n",p->data_Re, p->data_Im);
        p = p->next;
    }
}

void komplex_free(komplex_list *l0){
    komplex_list *p = l0;
    while(p != NULL){
        komplex_list *tmp = p->next;
        free(p);
        p = tmp;
    }
    printf("Felszabaditva(komplex).\n");
}