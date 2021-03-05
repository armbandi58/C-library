#ifndef LIST_KOMPLEX_H_
#define LIST_KOMPLEX_H_

#include "main.h"

typedef struct komplex_list{
    float data_Re;
    float data_Im;
    float data_degre;
    float data_abs;
    struct komplex_list *next;
}komplex_list;

komplex_list *komplex_pushforward(komplex_list *l0,float Re,float Im);
komplex_list *komplex_pushback(komplex_list *l0,float Re,float Im);
void komplex_print(komplex_list *l0);
void komplex_free(komplex_list *l0);
void komplex_length(komplex_list *l0,u16 *hossz);
void komplex_find(komplex_list *l0,float re,float im);
void komplex_position(komplex_list *lk,u16 pos);
float euler_degre(float re,float im);
float euler_abs(float re,float im);
/*void _komplextoeuler(float re,float im,float *res_deg,float *res_abs);
void __komplextoeuler2(float re,float im);
void euler(float re, float im);
*/

//gcc -lm
#endif //LIST_KOMPLEX_H_