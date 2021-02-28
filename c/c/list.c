#include "list.h"

list *list_pushback(list *l0,u8 mit){
    list *uj = (list*)malloc(sizeof(list));
    uj -> data_u8 = mit;
    uj -> next = NULL;

    if(l0 == NULL){
        return uj;
    }else{
        list *p = l0;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = uj;
        return l0;
    }
}

list *list_pushforward(list *l0,u8 what){
    list *uj = (list*)malloc(sizeof(list));
    uj -> data_u8 = what;
    uj -> next = l0;

    return uj;
}

void list_print(list *l0){
    u16 db = 0;
    list *p = l0;
    while(p != NULL){
        if(p->next == NULL){
            printf("%d.\n",p->data_u8);
            p = p->next;
        }else{
            printf("%d, ",p->data_u8);
            p = p->next;
        }
    }
    //printf("")
}

void list_free(list *l0){
    list *p = l0;
    while(p != NULL){
        list *tmp = p -> next;
        free(p);
        p = tmp;
    }
    printf("Felszabaditva\n");
}

void list_length(list *l0,u16 *length){
    list *p = l0;
    u16 db = 0;
    while(p != NULL){
        p = p-> next;
        db++;
    }
    *length = db;
}

void list_find(list *l0,u8 mit){
    list *p = l0;
    u16 hely = 0;
    bool flag = 0;
    while(p != NULL){
        hely++;
        if(p->data_u8 == mit){
            printf("Benne van a %d. helyen.\n",hely);
            p = NULL;
            flag = 1;
            break;
            //return;
        }else{
            p = p->next;
        }
    }
    if(flag == 0){
        printf("Nincs benne.\n");
    }
}