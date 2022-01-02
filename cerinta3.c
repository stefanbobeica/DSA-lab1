#include "student.h"

/**
 * //TODO: Implementarea metodei ,,realocare_memorie" 
 * @param vector  - pointer catre vectorul de studenti 
 * @param dimensiune - dimensiunea vectorului
 */
void realocare_memorie (student **vector, int dimensiune) {
*vector=(student *)realloc(*vector,dimensiune * sizeof(student));
}

/**
 * //TODO: Implementarea metodei ,,add_student" (se adauga un nou student pe pozitia poz)
 * Hint:
	- optional: se poate utiliza functia swap implementata la cerinta1
 * @param vector  - pointer catre vectorul de studenti 
 * @param poz - pozitia pe care trebuie adaugat noul student
 * @param dimensiune - dimensiunea vectorului
 * @param stud - reprezinta studentul care trebuie adaugat in vector (acesta are datele necesare deja completate -nume,prenume,etc-)
 */
//consider ca stud se afla pe ultima pozitie si il aduc pe pozitia poz cum s-a spus pe teams
void adaugare_student (student *vector, int poz, int dimensiune, student stud) {
    
	
	swap(&vector[poz],&vector[dimensiune-1]);//presupun ca restul pozitiilor nu trebuie pastrate
	
	
	
	/*TODO: Care este complexitatea metodei folosite?*/
}

