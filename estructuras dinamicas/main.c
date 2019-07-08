/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Carlos
 *
 * Created on 21 de junio de 2017, 22:53
 */

#include <stdio.h>
#include <stdlib.h>
struct nodo{
    int dato;
    struct nodo *signodo; 
};
typedef struct nodo NODO;
typedef NODO * NODOPTR;
void agregar_nodo (NODO *cab,int num){
    NODOPTR nuevoptr,anteriorptr,actualptr;
    nuevoptr = malloc(sizeof(NODO));
    if (nuevoptr != NULL){/* Si hay espacio en la memoria*/
        nuevoptr->dato = num;
        nuevoptr->signodo = NULL;
        
        anteriorptr = NULL;
        actualptr = *cab;
    }
        
}
void quitar_nodo (NODOPTR,int);
void imprimir_lista (NODO *);
void menu (){
    printf("Bienvenido a lista!!!\n(1) para agregar entero\n (2) para quitar entero\n(3) para terminar\n");
}
/*
 * 
 */
int main(int argc, char** argv) {
    int opcion,num;
    NODOPTR cabecera = NULL;
    do{
       menu();
       scanf("%d",&opcion);
       switch (opcion){
           case 1:
               printf("Ingrese el numero a agregar:\n");
               scanf("%d",&num);
               agregar_nodo(&cabecera,num);
               imprimir_lista(cabecera);
               break;
           case 2:
               printf("Ingrese el numero a quitar:\n");
               scanf("%d",&num);
               quitar_nodo(&cabecera,num);
               imprimir_lista(cabecera);
               break;
           case 3:
               printf("Gracias por porbar!\n");
       }
    }while (opcion != 3);
    return (EXIT_SUCCESS);
}

