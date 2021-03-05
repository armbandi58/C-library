#include "list_komplex.h"

komplex_list *komplex_pushforward(komplex_list *l0,float Re,float Im){
    komplex_list *uj = (komplex_list*)malloc(sizeof(komplex_list));
    uj -> data_Re = Re;
    uj -> data_Im = Im;
    uj -> data_degre = euler_degre(Re,Im);
    uj -> data_abs = euler_abs(Re,Im);
    uj -> next = l0;

    return uj;
}

komplex_list *komplex_pushback(komplex_list *l0,float Re,float Im){
    komplex_list *uj = (komplex_list*)malloc(sizeof(komplex_list));
    uj -> data_Re = Re;
    uj -> data_Im = Im;
    uj -> data_degre = euler_degre(Re,Im);
    uj -> data_abs = euler_abs(Re,Im);
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
        printf("[%.2f:%.2f], (%.3f*e^j%.3f fok)\n",p->data_Re, p->data_Im, p->data_abs, p->data_degre);
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

void komplex_length(komplex_list *l0,u16 *hossz){
    komplex_list *p = l0;
    u16 db = 0;
    while(p != NULL){
        db++;
        p = p->next;
    }
    *hossz = db;
}

void komplex_find(komplex_list *l0,float re,float im){
    komplex_list *p = l0;
    u16 hely = 0;
    bool flag0 = 0;
    while(p != NULL){
        //if((p->data_Re == re)){
        if((p->data_Im == im)){
            printf("Benne van a %d helyen.\n",hely);
            flag0 = 1;
            //p = NULL;
            break;
        }else{
            p = p->next;
            hely++;
        }
    }
    if(flag0 == 0){
        printf("Nincs benne.\n");
    }
}

void komplex_position(komplex_list *lk,u16 pos){
    komplex_list *p = lk;
    u16 db = 0;
    bool flag = 0;

    while(p != NULL){
        if(db == pos){
            printf("A(z) %d. poz.:[%.2f:%.2f], (%.3f*e^j%.3f fok)\n",db,p->data_Re, p->data_Im, p->data_abs, p->data_degre);        
            flag = 1;
            break;
        }else{
            p = p->next;
            db++;
        }
    }
    if(flag == 0){
        printf("Helytelen pozicio.\n");
    }
}

float euler_degre(float re,float im){
    float res = atan(im/re);
    return res = (180/PI)*res;
}

float euler_abs(float re,float im){
    float abs = pow(re,2)+pow(im,2);
    return abs = sqrt(abs);
}
/*
void _komplextoeuler(float re,float im,float *res_deg,float *res_abs){
    *res_abs = sqrt(pow(im,2)+pow(re,2));
    *res_deg = im/re;
    *res_deg = atan(*res_deg);
    printf("%.5f*%.5f",*res_abs,*res_deg);
}

void __komplextoeuler2(float re,float im){
   // float tmp1 = pow(im,2)+pow(re,2);
    //float res_abs = sqrt(tmp1);
    float res_abs = 1.0;
    float res_deg = 2.3;//im/re;
    //res_deg = atan(res_deg);
    printf("%.5f*%.5f",res_abs,res_deg);
}

void euler(float re, float im){
    printf("%f,%f",re,im);
}
*/

