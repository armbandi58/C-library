#ifndef LIST_H_
#define LIST_H_

#include "main.h"

typedef struct list{
    u8 data_u8;
    struct list *next;
}list;

list *list_pushback(list *l0,u8 mit);
list *list_pushforward(list *l0,u8 what);
void list_print(list *l0);
void list_free(list *l0);
void list_length(list *l0,u16 *length);
void list_find(list *l0,u8 mit);

#endif //LIST_H_