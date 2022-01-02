#include "student.h"

/**
 * //TODO: Implementarea metodei ,,eliminare_restantieri" (se elimina fiecare student restantier)
 * Hint:
	- dimensiunea se schimba
	- se creeaza un vector auxiliar
 * @param vector  - vectorul de studenti 
 * @param dimensiune - dimensiunea vectorului
 * @return vectorul de studenti fara restanta
 */
student* eliminare_restantieri(student *vector, int *dimensiune) {
int *v;
student *v2;
int k=0;
v=(int *)malloc( *dimensiune * sizeof(int));
for(int i=0; i < *dimensiune;i++){

	for(int j=0;j<5;j++){
           if(vector[i].note[j]<5){
		      v[i]=1;
			  k++;
             j=6;
		    } 
		   

	}
	
}
for(int i=0;i<*dimensiune-1;i++)
  for(int j=i+1; j < *dimensiune ;j++){
	  if(v[i]==1)
	  swap(&vector[i],&vector[j]);

}

v2=(student * )malloc((*dimensiune-k) * sizeof(student ));
for(int i=0;i < *dimensiune - k; i++){
	v2[i]=vector[i];
}

return v2;
}

	/*TODO: Care este complexitatea pentru secventa de stergere a elementelor din vector cu realocare de memorie?* 
	dimensiune^2 */
