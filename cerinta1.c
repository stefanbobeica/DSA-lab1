#include "student.h"

//----- Prelucrarea informatiilor pentru un student -----

/**
 * //TODO: Implementarea metodei ,,nr_restante"
 * @param stud - studentul a carui numar de restante trebuie aflat
 * @return numarul de restante
 */
int nr_restante (student stud) {
int aux=0;
for(int i=0;i<5;i++){
	if(stud.note[i] < 5)
	aux++;
}
return aux;
}

/**
 * //TODO: Implementarea metodei ,,medie"
 * @param stud - studentul a carei medie trebuie calculata
 * @return valoare mediei aritmetice 
 */
double medie (student stud) {
double m=0;
for(int i=0;i<5;i++){
   m=m+stud.note[i];
}
m=m/5;
return m;
}

//----- Instantierea & popularea vectorului de studenti -----

/**
 * //TODO: Implementarea metodei ,,alocare_memorie"
 * Hint: 
	- numele si prenumele se aloca in timpul citirii datelor pentru fiecare student
 * @param vector - pointer catre vectorul de studenti
 * @param dimensiune - dimensiunea vectorului
 */
void alocare_memorie (student **vector, int dimensiune) {
*vector=(struct student *)malloc(dimensiune*sizeof(struct student));
}
/** 
 * //TODO: Implementarea metodei ,,citire_fisier" (se citesc datele din fisier)
 * @param vector - vectorul de studenti
 * @param dimensiune - dimensiunea vectorului
 * @param input - fisierul de date
 */
void citire_fisier(student *vector, int dimensiune, FILE *input) {

fscanf(input,"%d",&dimensiune);
for(int i=0; i < dimensiune ; i++){
	vector[i].nume=(char *)malloc(50*sizeof(char));
	fscanf(input,"%s",vector[i].nume);
    vector[i].nume=(char * )realloc(vector[i].nume,strlen(vector[i].nume)*sizeof(char));
    vector[i].prenume=(char *)malloc(50*sizeof(char));
	fscanf(input,"%s",vector[i].prenume);
	vector[i].prenume=(char *)realloc(vector[i].prenume,strlen(vector[i].prenume)*sizeof(char));
	fscanf(input,"%s",vector[i].id);
	fscanf(input,"%lf %lf %lf %lf %lf",&vector[i].note[0],&vector[i].note[1],&vector[i].note[2],&vector[i].note[3],&vector[i].note[4]);
}
}

/**
 * //TODO: Implementarea metodei ,,afisare_fisier"
 * @param vector  - vectorul de studenti
 * @param dimensiune - dimensiunea vectorului
 */
void afisare_fisier(student *vector, int dimensiune) {

	FILE* f1;
	f1=fopen("output.txt","w");
	for(int i=0;i<5;i++){
		fprintf(f1,"%s\n",vector[i].id);
		fprintf(f1,"%s\n",vector[i].nume);
	    fprintf(f1,"%s\n",vector[i].prenume);
		fprintf(f1,"%lf %lf %lf %lf %lf",vector[i].note[0],vector[i].note[1],vector[i].note[2],vector[i].note[3],vector[i].note[4]);
	    if(nr_restante(vector[i])!=0){
			printf("Numar restante %d",nr_restante(vector[i]));
		}
	
	}

	fclose(f1);
}

/**
 * //TODO: Implementarea metodei ,,citire"
 * Hint: 
	- datele sunt citite de la tastatura
 * @param vector - vectorul de studenti ce trebuie populat cu date
 * @param dim - dimensiunea vectorului
 */
void populare_vector(student *vector, int dimensiune) {
      for(int i=0; i < dimensiune ; i++){
	printf("ID=");
	scanf("%s",vector[i].id);
	vector[i].nume=(char *)malloc(50*sizeof(char));
	printf("Numele=");
	scanf("%s",vector[i].nume);
    vector[i].nume=(char *) realloc(vector[i].nume,strlen(vector[i].nume)*sizeof(char));
    vector[i].prenume=(char *)malloc(50*sizeof(char));
	printf("Prenumele="); 
	scanf("%s",vector[i].prenume);
	vector[i].prenume=(char *)realloc(vector[i].prenume,strlen(vector[i].prenume)*sizeof(char));
	for(int j=0;j<5;j++){
		printf("Nota nr. %d =",j);
		scanf("%lf",&vector[i].note[j]);
      }
}
}
/*
 * //TODO: Implementarea metodei ,,afisare"
 * De afisat: nume, prenume, id, note, nr_restante
 * @param stud - studentul a carui date o sa fie afisate
 */
void afisare_student(student stud) {
printf("%s\n",stud.id);
printf("%s\n",stud.nume);
printf("%s\n",stud.prenume);
for(int i=0;i<5;i++){
	printf("%lf ",stud.note[i]);
}
}

//----- Sortarea vectorului de studenti -----

/**
 * //TODO: Implementarea metodei ,,swap" (interschimba datele a 2 studenti)
 * @param first_stud  - primul student
 * @param second_stud - al 2-lea student
 */
void swap(student *first_stud, student *second_stud) {
student aux;
aux=*first_stud;
*first_stud=*second_stud;
*second_stud=aux;
}

/**
 * //TODO: Implementarea metodei ,,sortare" (se sorteaza crescator in functie de medie)
 * Hint:
	- pentru sortare se foloseste metoda swap
 * @param vector  - vectorul de studenti 
 * @param dimensiune - dimensiunea vectorului
 */
void sortare_vector(student *vector, int dimensiune) {
for(int i=0;i<dimensiune;i++)
	for(int j=i;j<dimensiune;j++){
		if(medie(vector[i])>medie(vector[j]))
		swap(&vector[i],&vector[j]);
	}

}