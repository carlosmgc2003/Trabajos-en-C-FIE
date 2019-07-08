#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct materia{
    int codigoMat;
    //char nombreMat [30]; No implementado, podria asignarse materias con mismo codigo y diferente nombre a alumnos diferentes.
    struct materia *sigMat;//Puntero a la siguiente materia
};

struct alumno{
    int dni;
    char nombreAlu [31];
    struct materia *listaInscriptas;//Puntero tipo materia para relacionar al alumno con las materias que cursa.
    struct alumno *sigAlu;//Puntero al siguiente alumno
};

typedef struct alumno alumno;

typedef struct materia materia;

typedef alumno* alumnoPtr;

typedef materia* materiaPtr;

void menu(void){
    printf("\n\n(1) para agregar Alumno...\n"
            "(2) para agregar o eliminar materias a un alumno existente...\n"
            "(3) para ver materias inscriptas de un alumo...\n"
            "(4) listar alumnos anotados en una materia...\n"
            "(0) para salir a Windows.\n");
}

void crearMateria (alumnoPtr *Alumno, int codigo){
    materiaPtr nuevaMateria, actMateria, antMateria;
    nuevaMateria = (materiaPtr)malloc(sizeof(materia));
    actMateria = (*Alumno)->listaInscriptas;
    antMateria = NULL;
    nuevaMateria->codigoMat = codigo;
    nuevaMateria->sigMat = NULL;
    while(actMateria != NULL && codigo > actMateria->codigoMat){
        antMateria = actMateria;
        actMateria = actMateria->sigMat;
        }
    if (antMateria == NULL){
        nuevaMateria->sigMat = (*Alumno)->listaInscriptas;
        (*Alumno)->listaInscriptas = nuevaMateria;
    }
    else {
        antMateria->sigMat = nuevaMateria;
        nuevaMateria->sigMat = actMateria;
    }
}

void eliminarMateria (alumnoPtr *alumno, int codigo){
    materiaPtr actMateria, antMateria;
    actMateria = (*alumno)->listaInscriptas;
    antMateria = NULL;
    while(actMateria != NULL && codigo != actMateria->codigoMat){
        antMateria = actMateria;
        actMateria = actMateria->sigMat;
    }
    if(antMateria == NULL){
        (*alumno)->listaInscriptas = actMateria->sigMat;
    } else {
        antMateria->sigMat = actMateria->sigMat;
        free(actMateria);
    }
    printf("La materia cod %d de DNI %d se elimino con exito.\n",codigo,(*alumno)->dni);
}

void crearAlumno(alumnoPtr *listaAlumnos){
    alumnoPtr nuevoAlumno, actAlumno, antAlumno;
    int dni;
    int codigo;
    int i = 0;
    char temp [30] = {'\0'};
    nuevoAlumno = (alumnoPtr)malloc(sizeof(alumno));
    nuevoAlumno->listaInscriptas = NULL;
    nuevoAlumno->sigAlu = NULL;
    if (nuevoAlumno != NULL){//Si hay espacio en la memoria del sistema para crear un nuevo alumno!!!
        antAlumno = NULL;
        actAlumno = *listaAlumnos;
        //Empieza la carga de los atributos de alumno (DNI y Materias)

        
        printf("Ingrese DNI del alumno: \n");
        scanf("%d",&dni);
        while(dni > 99999999 || dni <= 0){
            printf("DNI inválido, intente nuevamente\n");
            scanf("%d",&dni);
        }
        nuevoAlumno->dni = dni;//Fin de carga de DNI
        printf("Ingrese el nombre del Alumno\n");
        while(getchar()!= '\n');
        //fflush(stdin);
        fgets(temp,30,stdin);
        while(temp[i] != '\0'){
            if (temp[i] == '\n')
                temp[i] = '\0';
            i++;
        }
        strcpy(nuevoAlumno->nombreAlu,temp);
        printf("Ingrese los codigos de materia del alumno %d (0 para terminar)\n",nuevoAlumno->dni);//La idea es encolar de una en una las materias del alumno
        while (codigo != 0){//no esta encadenando bien las materias del alumno
            scanf("%d",&codigo);
            while (codigo < 0 || codigo > 999){
                printf("Codigo invalido, intente nuevamente:\n");
                scanf("%d",&codigo);
            }
            if (codigo != 0)
                crearMateria(&nuevoAlumno,codigo);
        }
        while (actAlumno != NULL && dni > actAlumno->dni){
            antAlumno = actAlumno;
            actAlumno = actAlumno->sigAlu;
            }
        if (antAlumno == NULL){
            nuevoAlumno->sigAlu = *listaAlumnos;
            *listaAlumnos = nuevoAlumno;
        }
        else {
            antAlumno->sigAlu = nuevoAlumno;
            nuevoAlumno->sigAlu = NULL;
        }
    }
    else {
        printf("No se puede crear nuevo Alumno, no hay memoria disponible\n");
    }
}

void imprimirListaAlumnos(alumnoPtr inicio){
    if(inicio == NULL){
        printf("Lista vacía.\n");
        return;
    } else{
        while (inicio != NULL){
            printf("\n%s\tDNI Nro: %d\n",inicio->nombreAlu,inicio->dni);
            materiaPtr materia, antMateria;
            materia = inicio->listaInscriptas;
            antMateria = NULL;
            if (materia == NULL){
                printf("No tiene materias inscriptas.\n");
            } else {
                printf("Esta inscripto en: \t");
                while (materia != NULL){
                    printf("%d\t",materia->codigoMat);
                    antMateria = materia;
                    materia = materia->sigMat;
                }
            }
            inicio = inicio->sigAlu;
        }
    }
}

void imprimirMaterias (alumnoPtr alumno){
          printf("\n%s DNI Nro: %d \n",alumno->nombreAlu,alumno->dni);
        materiaPtr materia, antMateria;
        materia = alumno->listaInscriptas;
        antMateria = NULL;
        if (materia == NULL)
            printf("\nNo tiene materias inscriptas.\n");
        else {
            printf("Esta inscripto en: \t");
                while (materia != NULL){
                    printf("%d\t",materia->codigoMat);
                    antMateria = materia;
                    materia = materia->sigMat;
                }
        }
}

void menuModificarMaterias(){
    printf("\n(1) para agregar, (2) para quitar, (3) para terminar.\n");
}

alumnoPtr buscarDNI (int dni, alumnoPtr listaAlumnos){
    alumnoPtr actualAlumno, antAlumno;
    if (listaAlumnos == NULL) return NULL;
    else{
        actualAlumno = listaAlumnos;
        antAlumno = NULL;
        while(actualAlumno != NULL && actualAlumno->dni != dni){
            antAlumno = actualAlumno;
            actualAlumno = actualAlumno->sigAlu;
        }
        if (actualAlumno != NULL){
            return actualAlumno;
        }
    }
    return NULL;
}

materiaPtr buscaMateria(alumnoPtr alumno, int codigo){
    materiaPtr materia, antMateria;
    materia = alumno->listaInscriptas;
    antMateria = NULL;
    if(materia == NULL){
        printf("Este alumno no esta inscripto en ninguna materia");
        return NULL;
    }
    else {
        while (materia != NULL){
            if(materia->codigoMat == codigo)
                return materia;
            else{
                antMateria = materia;
                materia = materia->sigMat;
            }
            
        }
        return materia;
    }

   printf("La materia cod %d no existe para %s DNI %d\n",codigo,alumno->nombreAlu,alumno->dni);
    return NULL;
}

void modificarMaterias(int dni, alumnoPtr listaAlumnos){
    int opcion, codigo;
    alumnoPtr alumno = buscarDNI(dni,listaAlumnos);
    materiaPtr materia;
    if(alumno == NULL){
        printf("El DNI solicitado no pertenece a un alumno valido\n");
        return;
    }
    else{
        imprimirMaterias(alumno);
        }
        menuModificarMaterias();
        printf("? ");
        scanf("%d",&opcion);
        switch(opcion){
            case 1: printf("Ingrese el codigo de la materia a agregar:\n");
            do{
                scanf("%d",&codigo);
                if(codigo > 999 || codigo < 0)
                    printf("Codigo inválido, intente nuevamente... \n");
            }while(codigo > 999 || codigo < 0);
        materia = buscaMateria(alumno,codigo);
        if(materia == NULL){
            crearMateria(&alumno,codigo);
        }
        else{
            printf("La materia ya existe para %s DNI: %d\n",alumno->nombreAlu,alumno->dni);
        }
        break;
            case 2: printf("Ingrese el codigo de la materia a quitar:\n");
            do{
                scanf("%d",&codigo);
                if(codigo > 999 || codigo < 0)
                    printf("Codigo inválido, intente nuevamente... \n");
            }while(codigo > 999 || codigo < 0);
        materia = buscaMateria(alumno,codigo);
        if(materia == NULL){
            printf("El alumno %s DNI:%d no se encuentra asociado a la materia %d\n",alumno->nombreAlu,alumno->dni,codigo);
        }
        else{
            eliminarMateria(&alumno,codigo);
            imprimirMaterias(alumno);
        }
        break;
            case 3: printf("Regreso al menu principal sin realizar cambios!\n");
                    break;
            default: printf("Opcion no valida!!!\n");
            modificarMaterias(dni,listaAlumnos);
        }
    }

void listarMateria (alumnoPtr listaAlumnos, int codigo){
    if(codigo > 999 || codigo < 0){
        printf("Codigo no valido!!!\n");
        return;
    }
    else if(listaAlumnos == NULL){
        printf("No hay alumnos registrados...\n");
    }
    else {
        int i = 0;
        alumnoPtr alumno, antAlumno;
        alumno = listaAlumnos;
        antAlumno = NULL;
        materiaPtr materia, antMateria;
        materia = listaAlumnos->listaInscriptas;
        antMateria = NULL;
        printf("LISTADO DE LA MATERIA %d\n",codigo);
        while (alumno != NULL){
            materia = alumno->listaInscriptas;
            while(materia != NULL){
                if(materia->codigoMat == codigo){
                    i++;
                    printf("%d. %s\t\t\t %d\n",i,alumno->nombreAlu,alumno->dni);
                }
                antMateria = materia;
                materia = materia->sigMat;
            }
            antAlumno = alumno;
            alumno = alumno->sigAlu;
        }
    }
}



int main(int argc, char** argv) {
    alumnoPtr listaAlumnos = NULL;
    alumnoPtr alumno;
    int opcion;
    int dniBuscado, matBuscado;
    printf("\tBIENVENIDO A ALUMNOS & MATERIAS\n\tEST 2017\n");
    menu();
    printf("? ");
    scanf("%d",&opcion);

    while(opcion != 0){

        switch(opcion){
            case 0: break;
            case 1:
            crearAlumno(&listaAlumnos);
            imprimirListaAlumnos(listaAlumnos);
            break;
            case 2: printf("Ingrese un DNI de alumno:\n");
            scanf("%d",&dniBuscado);
            modificarMaterias(dniBuscado,listaAlumnos);
            break;
            case 3:printf("Ingrese un DNI de alumno:\n");
            scanf("%d",&dniBuscado);
            alumno = buscarDNI(dniBuscado,listaAlumnos);
            if(alumno == NULL){
                printf("El alumno %d no existe...",dniBuscado);
            }
            else{
                imprimirMaterias(alumno);
            }
            break;
            case 4: printf("Ingrese un codigo de materia:\n");
            scanf("%d",&matBuscado);
            listarMateria(listaAlumnos,matBuscado);
            break;
            default: printf("Seleccion invalida\n\n");
            menu();
            break;
        }
        menu();
        printf("? ");
        scanf("%d",&opcion);
    }
    return (EXIT_SUCCESS);
}

