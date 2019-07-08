#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>

struct trie {
    char letra;
    struct trie * combinaciones[27];
    struct listaDir * presente;
};

struct listaDir {
    char nombreArchivo[256]; //Cadena con el nombre de cada archivo del directorio
    struct listaDir * sig; //puntero a la siguiente cadena de nombre.
};

typedef struct listaDir listaDir;

typedef struct trie trie;

/*Funcion auxiliar para encadenar los nodos de la lista de directorio. Se utili
 za en leerDirectorio*/
void listar(listaDir ** cabeza, listaDir * nuevo) {
    listaDir * aux = (*cabeza);
    if ((*cabeza) == NULL) {
        (* cabeza) = nuevo;
        return;
    } else {
        while (aux->sig != NULL) {
            if(strcmp(aux->nombreArchivo,nuevo->nombreArchivo) == 0){
                free(nuevo);
                return;
            }
            aux = aux->sig;
        }
        if(strcmp(aux->nombreArchivo,nuevo->nombreArchivo) == 0){
            free(nuevo);
            return;
        }
        aux->sig = nuevo;
        return;
    }
}

listaDir * crearNodoLista (char * contenido){
    listaDir * nuevo = (listaDir *)malloc(sizeof(listaDir));
    if(nuevo != NULL){
        nuevo->sig = NULL;
        strcpy(nuevo->nombreArchivo,contenido);
        return nuevo;
    }
    else{
        printf("No hay mas memoria disponible!\n");
        exit(-1);
    }
}

/*Funcion que lee todos los nombres de archivo del directorio de trabajo y crea
 una lista con ellos*/
void leerDirectorio(DIR * dp, listaDir ** lista) {
    struct dirent *ep;

    dp = opendir("./prueba/");
    if (dp != NULL) {
        while (ep = readdir(dp)) {
            listaDir * nuevo = crearNodoLista(ep->d_name);
            if (strcmp(ep->d_name, "..") == 0 || strcmp(ep->d_name, ".") == 0 || strcmp(ep->d_name,".DS_Store") == 0)
                free(nuevo);
            else {
                listar(&(*lista), nuevo);
                puts(ep->d_name);
            }
        }
        (void) closedir(dp);
    } else
        perror("No se pudo abrir el directorio");
}

char * minusculas(char * texto){
    int i = 0;
    int j;
    //char TILDES [12] = {"áÁéÉíÍóÓúÚñÑ"};
    //char LETRAS [12] = {"aaeeiioouunn"};
    while(texto[i] != '\0'){
        if(texto[i] > 64 && texto[i] < 91){
            texto[i] = texto[i] + 32;
        }
        //for(j = 0;j < 12;j++){
          //  if(texto[i] == TILDES[j])
            //    texto[i] = LETRAS[j];
        //}
        i ++;
    }
    //puts(texto);
    return texto;
}

char * leerArchivo(listaDir * lista) {
    if (lista != NULL) {
        char * TEXTO;
        char PATH [100] = {"./prueba/"};
        FILE * archivo;
        archivo = fopen(strcat(PATH, lista->nombreArchivo), "r");
        int size;
        fseek(archivo, 0, SEEK_END);
        size = ftell(archivo);
        fseek(archivo, 0, SEEK_SET);
        TEXTO = (char *) malloc(size + 1);
        fread(TEXTO, 1, size, archivo);
        fclose(archivo);
        TEXTO[size] = '\0';
        printf("\n\n\t\t\tARCHIVO %s\n",lista->nombreArchivo);
        puts(TEXTO);
        return minusculas(TEXTO);
    } else
        return NULL;
}

trie * crearNodoTrie(char LETRA) {
    trie * nuevo = (trie *) malloc(sizeof (trie));
    if (nuevo == NULL) {
        printf("No hay mas memoria\n");
        exit(-1);
    } else {
        nuevo->letra = LETRA;
        for (int i = 0; i < 27; i++) {
            nuevo->combinaciones[i] = NULL;
        }
        nuevo->presente = NULL;
    }
    return nuevo;
}

trie * crearCadenaTrie(char * PALABRA, listaDir * aux) {//a partir de una palabra que ya no esta en el trie crea la nueva sucesion de nodos
    int i = 0;
    trie * cabeza = crearNodoTrie(PALABRA[i]); //crea el primer nodo el que se retornará
    trie * ant = NULL;
    trie * act = cabeza;
    trie * nuevo;
    i++; //avanzamos a la siguiente letra;
    if (PALABRA[i] == '\0') {
        listar(&act->presente, crearNodoLista(aux->nombreArchivo));
        return cabeza;
    } else {
        while (PALABRA[i] != '\0') {
            nuevo = crearNodoTrie(PALABRA[i]); //crear nuevo nodo de la siguiente letra
            act->combinaciones[PALABRA[i] - 97] = nuevo; //apuntar al nuevo
            ant = act; //avanzar el anterior
            act = nuevo; //avanzar el actual
            i++;
            if (PALABRA[i] == '\0') {
                listar(&act->presente, crearNodoLista(aux->nombreArchivo));
            }
        }
        return cabeza;
    }

}

void cortarPalabras(char * PALABRA, trie * raiz, listaDir * aux) {
    int i = 0;
    int size = strlen(PALABRA);
    if (raiz->combinaciones[PALABRA[i] - 97] == NULL) {//si el casillero del vector puntero es null
        raiz->combinaciones[PALABRA[i] - 97] = crearCadenaTrie(&PALABRA[i], aux); //crear cadena trie en el
    } else {//sino..
        while (raiz->combinaciones[PALABRA[i] - 97] != NULL) {//mientras ya exista la cadena avanzar...
            raiz = raiz->combinaciones[PALABRA[i] - 97]; //avanzar al siguiente nodo trie
            i++; //avanzar el contador para pasar a la siguiente letra de la palabra (va uno adelante)
            if (i == size) {//si se termino la palabra y ya existe
                listar(&raiz->presente,crearNodoLista(aux->nombreArchivo)); //agregar a la ultima letra el EOW y en que archivo esta!
                return;
            }
        }
        raiz->combinaciones[PALABRA[i] - 97] = crearCadenaTrie(&PALABRA[i], aux); //crear cadena a partir de esa letra
        return;
    }
}



void cortarTexto(trie * raiz, char * TEXTO, listaDir * aux) {
    char SIMBOLOS[31] = {" .-,';:{}[]!@#$%ˆ*()1234567890"};
    char * PALABRA = strtok(TEXTO, SIMBOLOS);
    char * PREFIJO;
    int i = 0;
    int tam = strlen(PALABRA);
    do {
        while (i < tam) {
            cortarPalabras(&PALABRA[i], raiz, aux);
            PREFIJO[i] = '\0';
            if(i > 0){
                cortarPalabras(PREFIJO, raiz, aux);
            }
            i++;
            strcpy(PREFIJO,PALABRA);
        }
        PALABRA = strtok(NULL, SIMBOLOS);
        if (PALABRA != NULL) {
            tam = strlen(PALABRA);
            i = 0;
        }
    } while (PALABRA != NULL);
}

void imprimir(listaDir * lista,int i){
    if(lista != NULL){
        printf("%d. %s\n",i,lista->nombreArchivo);
        imprimir(lista->sig,++i);
    }
}

void buscarCadena(char * BUSCAR,char * BUSCADO,trie * raiz){
    int i = 0;
    int tam = strlen(BUSCAR);
    while(raiz->combinaciones[BUSCAR[i] - 97] != NULL){
        raiz = raiz->combinaciones[BUSCAR[i] - 97];
        i++;
        //printf("%c",raiz->letra);
    }
    if(raiz->presente != NULL && i == tam){
        printf("Encontrado en: \n");
        imprimir(raiz->presente, 1);
    }
    else{
        printf("%s no existe en ningun archivo del directorio!\n",BUSCADO);
    }
}

/*
 *
 */
int main(void) {
    DIR * dp;
    listaDir * lista = NULL;
    listaDir * aux = NULL;
    char * TEXTO;
    int letrasBuscadas, i = 0;
    char BUSCADO[100];
    char BUSCAR[100];
    trie * raiz = (trie *) malloc(sizeof (trie));
    raiz->letra = '#';
    for (int i = 0; i < 27; i++) {
        raiz->combinaciones[i] = NULL;
    }
    raiz->presente = NULL;
    printf("=========>Bienvenido a Trie<===========\n");
    printf("Leyendo el directorio...\n");
    leerDirectorio(dp, &lista);
    aux = lista;
    printf("Procesando archivos...\n");
    while (aux != NULL) {
        TEXTO = leerArchivo(aux);
        cortarTexto(raiz, TEXTO, aux);
        printf("-------%s procesado correctamente-------\n",aux->nombreArchivo);
        aux = aux->sig;
    }
    do{
        printf("\nIngrese cadena a buscar:\n(fin) para terminar:\n");
        fflush(stdin);
        //system("cls");
        scanf("%s",BUSCADO);
        strcpy(BUSCAR,BUSCADO);
        strcpy(BUSCAR,minusculas(BUSCAR));
        if(strcmp(BUSCAR,"fin") != 0){
            if(strlen(BUSCAR) > 1)
               buscarCadena(BUSCAR,BUSCADO,raiz);
            else
                printf("Ingrese mas de una letra a buscar!!!\n");
        }
    }while(strcmp(BUSCAR,"fin") != 0);

    return (EXIT_SUCCESS);
}

