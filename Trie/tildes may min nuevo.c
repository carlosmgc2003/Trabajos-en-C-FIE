#include<stdio.h>
#include<stdlib.h>
void MayToMin(char []);

void main()//buscar
{
	char cadena[80];
	printf("Ingrese la busqueda:\n");    //esto iria en la funcion de busqueda
	fflush(stdin);                       //hay que ver como es esa funcion y adaptarlo
	gets(cadena);
	MayToMin(cadena); //llama a la funcion
	printf ("En Minusculas: %s\n", cadena);
}
void MayToMin(char string[])
{
    int i=0,j=0;
	int dif='a'-'A';
	for (i=0;string[i]!='\0';++i)
    {
        if(string[i]>='A'&&string[i]<='Z'){
           string[i]=string[i]+32;
        }
        else if
        (string[i]==-96){//á
        string[i]='a';
         }
         else if
        (string[i]==-126){//é
        string[i]='e';
         }
         else if
        (string[i]==-95){
        string[i]='i';
         }
         else if
        (string[i]==-94){
        string[i]='o';
         }
         else if
        (string[i]==-93){
        string[i]='u';
         }
         else if
        (string[i]==-75){//Á
        string[i]='a';
         }
         else if
        (string[i]==-112){//É
        string[i]='e';
         }
         else if
        (string[i]==-42){
        string[i]='i';
         }
         else if
        (string[i]==-32){
        string[i]='o';
         }
         else if
        (string[i]==-23){
        string[i]='u';
         }
         //printf ("En ASCII: %d\n", string[i]);
    }
}
