

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 150

typedef struct Nodo {
    char letra; //caracter asignado al nodo, puede ser NULL
    int peso; //peso del nodo, no puede ser cero
    struct Nodo *sig; //Puntero para el siguiente en la lista que se crea cuando se cargan los datos
    struct Nodo *padre; //Puntero para el padre en el arbol
    struct Nodo *izq; //Hijo Izquierdo
    struct Nodo *der; //Hijo derecho
} Nodo;

typedef struct TablaHuf {
    char letra;
    char codigo[30];
    struct TablaHuf * sig;
} Tabla;

typedef Tabla * TablaPtr;

typedef Nodo * NodoPtr;

/*Funcion que llena una Lista en orden decreciente con los nodos cargados mediante
 el archivo abecedario.txt*/
void leerArchivo(NodoPtr * Lista, FILE *archivo) {
    NodoPtr nuevoNodo, actNodo, antNodo;
    char aux;
    int peso;
    fscanf(archivo, "%c %d\n", &aux, &peso);
    while (!feof(archivo)) {//mientras el archivo no termine
        actNodo = *Lista;
        antNodo = NULL;
        nuevoNodo = (NodoPtr) malloc(sizeof (Nodo));
        nuevoNodo->peso = peso;
        nuevoNodo->letra = aux;
        if (nuevoNodo != NULL) {
            nuevoNodo->der = nuevoNodo->izq = nuevoNodo->sig = nuevoNodo->padre = NULL; //inicializo izq y der en NULL
            //fscanf(archivo, "%c %d", &nuevoNodo->letra, &nuevoNodo->peso); //cargo los datos de la primer linea en el nodo
            if (nuevoNodo->peso == 0) {
                free(nuevoNodo);
                continue;
            }
            while (actNodo != NULL && nuevoNodo->peso > actNodo->peso) {
                antNodo = actNodo; /*walk to...*/
                actNodo = actNodo->sig; /*...next node*/
            }
            if (antNodo == NULL) {
                nuevoNodo->sig = *Lista;
                *Lista = nuevoNodo;
            } else {
                antNodo->sig = nuevoNodo;
                nuevoNodo->sig = actNodo;
            }
        } else {
            printf("No hay mas memoria disponible, archivo demasiado grande");
            break;
        }
        fscanf(archivo, "%c %d\n", &aux, &peso);
    }
}

/*Si bien la Lista se carga ordenada, esta funcion evita que tome de manera desordenda
 los nodos menores en caso de que los nuevoNodo sean mayores*/
NodoPtr menorPeso(NodoPtr Lista) {//recorrer toda la Lista en busca de un nodo menor
    NodoPtr aux;
    NodoPtr actNodo, antNodo;
    actNodo = Lista;
    antNodo = NULL;
    aux = actNodo;
    if (actNodo == NULL) return NULL;
    while (actNodo != NULL) {
        if (aux->peso >= actNodo->peso) {
            aux = actNodo;
        }
        antNodo = actNodo;
        actNodo = actNodo->sig;
    }
    return aux;
}

NodoPtr crearArbol(NodoPtr Lista) {
    NodoPtr menorNodoA, menorNodoB, nuevoNodo, actNodo, antNodo, cursorLista;
    //int i = 1;
    cursorLista = Lista;
    if (!Lista) return NULL;
    else {
        while (menorNodoB != NULL && cursorLista != NULL) {
            menorNodoA = menorPeso(cursorLista);
            cursorLista = cursorLista->sig;
            menorNodoB = menorPeso(cursorLista);
            if (menorNodoB != NULL) {
                cursorLista = cursorLista->sig;
                nuevoNodo = (NodoPtr) malloc(sizeof (Nodo)); //Creo al nuevo padre...
                //printf("%d\n",i);
                //i++;
                if (nuevoNodo != NULL) {
                    nuevoNodo->peso = menorNodoA->peso + menorNodoB->peso; //Le doy al padre la suma del peso de los hijos
                    nuevoNodo->letra = '\0'; //Le asigno el caracter nulo al padre...
                    nuevoNodo->izq = menorNodoA; /* asigno el hijo menor al padre*/
                    menorNodoA->padre = nuevoNodo; /*asigno el padre al hijo menor*/
                    nuevoNodo->der = menorNodoB; /*asigno el hijo mayor al padre*/
                    menorNodoB->padre = nuevoNodo; /*asigno el padre al hijo mayor*/
                    if (cursorLista != NULL) {
                        actNodo = cursorLista;
                        antNodo = NULL;
                        while (actNodo != NULL && nuevoNodo->peso >= actNodo->peso) {
                            antNodo = actNodo;
                            actNodo = actNodo->sig;
                        }
                        if (antNodo == NULL) {
                            nuevoNodo->sig = cursorLista;
                            cursorLista = nuevoNodo;
                        } else {
                            antNodo->sig = nuevoNodo;
                            nuevoNodo->sig = actNodo;
                        }
                    }
                } else {
                    printf("Memoria insuficiente para crear los nodos...\n");
                    return NULL;
                }
            }

        }
    }

    return nuevoNodo;
}

void imprimirLista(NodoPtr top) {
    if (top == NULL) {
        //printf("No hay nodos cargados!!!\n");
        return;
    } else {
        printf("(%c,%d) -> ", top->letra, top->peso);
        imprimirLista(top->sig);
        return;
    }
}

char * invertirCadena(char * ARRAY) {
    int i;
    int j = strlen(ARRAY) - 1;
    char aux;
    for (i = 0; i < (strlen(ARRAY) / 2); i++) {
        aux = ARRAY[i];
        ARRAY[i] = ARRAY[j];
        ARRAY[j] = aux;
        j--;
    }
    return ARRAY;
}

void imprimirHuffman(NodoPtr Lista, TablaPtr * Clave) {
    NodoPtr nodoAct = Lista;
    NodoPtr nodoAnt = NULL;
    NodoPtr nodoPadre = Lista->padre;
    NodoPtr nodoHijo = Lista;
    char ARRAY [30] = {"\0"};
    char RESET [30] = {"\0"};
    printf("Letra\tCodigo\n");
    while (nodoAct != NULL) {
        if (nodoAct->letra != '\0') {
            TablaPtr Nuevo = (TablaPtr) malloc(sizeof (Tabla));
            if (!Nuevo) {
                printf("Insuficiente memoria, no pudo ser guardado el codigo\n");
            }
            Nuevo->letra = nodoAct->letra;
            if (Nuevo->letra == '#')
                Nuevo->letra = ' ';
            printf("%c\t", nodoAct->letra);
            while (nodoPadre != NULL) {
                if (nodoPadre->izq == nodoHijo) {
                    strcat(ARRAY, "0");
                } else if (nodoPadre->der == nodoHijo) {
                    strcat(ARRAY, "1");
                }
                nodoHijo = nodoPadre;
                nodoPadre = nodoPadre->padre;
            }
            puts(invertirCadena(ARRAY));
            strcpy(Nuevo->codigo, ARRAY);
            strcpy(ARRAY, RESET);
            TablaPtr tablaAct = (*Clave);
            TablaPtr tablaAnt = NULL;
            while (tablaAct != NULL) {
                tablaAnt = tablaAct;
                tablaAct = tablaAct->sig;
            }
            if (tablaAnt == NULL) {
                (* Clave) = Nuevo;
                Nuevo->sig = tablaAct;
            } else {
                tablaAnt->sig = Nuevo;
                Nuevo->sig = tablaAct;
            }

        }
        nodoAnt = nodoAct;
        nodoAct = nodoAct->sig;
        if (nodoAct != NULL) {
            nodoPadre = nodoAct->padre;
            nodoHijo = nodoAct;
        }
    }
}

void codificarHuffman(char * ORIGINAL, char * DESTINO, TablaPtr Codigo) {
    int tamOriginal = strlen(ORIGINAL);
    int i;
    for (i = 0; i < tamOriginal - 1; i++) {
        TablaPtr act = Codigo;
        TablaPtr ant = NULL;
        while (act != NULL && act->letra != ORIGINAL[i]) {
            ant = act;
            act = act->sig;
        }
        if (act == NULL) {
            printf("ERROR FATAL! el simbolo buscado no existe en los registros\n");
            return;
        }
        strcat(DESTINO, act->codigo);
    }
    printf("CODIFICACION TERMINADA!\n");
    return;

}

void decodificarHuffman(char * MENSAJE, NodoPtr cab) {
    int tamMsj = strlen(MENSAJE);
    int i, j;
    NodoPtr aux = cab;
    for (i = 0; i <= tamMsj; i++) {
        if (aux->letra != '\0') {
            if (aux->letra == '#')
                printf(" ");
            else
                printf("%c", aux->letra);
            aux = cab;
        }
        if (MENSAJE[i] == '0')
            aux = aux->izq;
        else
            aux = aux->der;
    }
    printf("\nDECODIFICACION TERMINADA!\n");
}

/*
 *
 */
int main(int argc, char** argv) {
    FILE *abcPtr; //puntero file para el comienzo del archivo
    NodoPtr Lista = NULL;
    NodoPtr arbol = NULL;
    TablaPtr ClaveHuf = NULL;
    int tamOri, tamCod;
    char TEXTO [SIZE] = {'\0'};
    char CODIFICADO [SIZE * 8] = {'\0'};
    printf("Bienvenido a Codigo Huffman\n");
    abcPtr = fopen("abecedariocompleto.txt", "r");
    if (abcPtr == NULL)
        printf("No hay archivo de abecedario");
    else {
        leerArchivo(&Lista, abcPtr);
        imprimirLista(Lista);
        printf("\n");
        arbol = crearArbol(Lista); /*Esta funcion rompe la lista hay que reveer esoooo!!!!*/
        imprimirHuffman(Lista, &ClaveHuf);
        printf("Codificacion creada correctamente.\n");
        printf("Ingrese texto a codificar:\n");
        fgets(TEXTO, 104, stdin);
        tamOri = strlen(TEXTO)*8;
        printf("El tamaño del texto en bits es: %d\n\n", tamOri);
        codificarHuffman(TEXTO, CODIFICADO, ClaveHuf);
        puts(CODIFICADO);
        tamCod = strlen(CODIFICADO);
        printf("\n\nEl nuevo tamaño en bits es de: %d y se comprimio un %.2f%%", tamCod, 100.0 - (tamCod * 100.0) / tamOri);
        printf("\nDecodificando...\n");
        decodificarHuffman(CODIFICADO, arbol);
        printf("\nPrograma finalizado! (0 para terminar)\n");
        int opc = 1;
        scanf("%d", &opc);
        while (opc != 0) {
            printf("\nPrograma finalizado! (0 para terminar)\n");
            scanf("%d", &opc);
        }
    }
    return (EXIT_SUCCESS);
}

