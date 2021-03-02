#ifndef LIST_KOMPLEX_H_
#define LIST_KOMPLEX_H_

#include "main.h"

typedef struct komplex_list{
    float data_Re;
    float data_Im;
    struct komplex_list *next;
}komplex_list;

komplex_list *komplex_pushforward(komplex_list *l0,float Re,float Im);
komplex_list *komplex_pushback(komplex_list *l0,float Re,float Im);
void komplex_print(komplex_list *l0);
void komplex_free(komplex_list *l0);

#endif //LIST_KOMPLEX_H_