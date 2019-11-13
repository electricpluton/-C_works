/*
 *
 * 
 * 
 */


#include <stdio.h>
#include <stdlib.h>
#include <math.h>



 void conversion (int n) {
	int x,y,z;
	char *unite[9] = { "un", "deux", "trois", "quatre", "cinq", "six", "sept", "huit", "neuf" } ;
	char *dizaine[9]= {"onze", "douze", "treize", "quatorze", "quinze", "seize", "dix-sept","dix-huit", "dix-neuf"};
	char *centaine[9] = {"dix", "vingt", "trente", "quarante", "cinquante", "soixante", "soixante-dix", "quatre-vingt", "quatre-vingt-dix"};
	
	
	
	if ( (n >= 0) && (n <= 999) ) {
		
		x = (n/100) ; 			// x le chiffre des centaines
		y = ((n%100)/10) ;		// y le chiffre des dizaines
		z = ( (n%100)%10);		// z le chiffre des unites
		
		if ( x == 0) {			// cas ou x = 0 
			if ( y == 0) {
				if ( z == 0) {
					printf (" zero \n");
				}else {
					printf (" %s \n", unite[z-1]);
					 
				}
			
			}else										// y != 0 mais x = 0 
				if (z == 0) {
					printf (" %s \n", centaine[y-1]);
					
				}else {
					if ( y == 1) {
						printf (" %s \n",dizaine[z-1]); // cas particulier ou y vaut 1 et z != 0 alors ca donne des onze en allant
					
					}else if ( (y==7) || (y==9) ) {
						printf (" %s %s \n", centaine [y-2],dizaine[z-1]); // la numerotation change avec soixante onze et non soixante dix un 
					
					}else {
						printf (" %s %s \n", centaine[y-1], unite[z-1]);
					}	
				}
				
			
		
		}else {								// x != 0 et y,z variables
			
			if ( ( y == 0) && (z == 0) ) {
				if ( x== 1) {
					printf (" cent \n");	// cas particulier ou x vaut 1 (on ecrit cent et non un cent)
				
				}else{
					printf (" %s cent \n", unite[x-1]);
				}
					
			}else if ( (y == 0) && (z != 0) ) {
				if ( x == 1) {
					printf (" cent %s \n",unite[z-1]);
				
				}else {
					printf (" %s cent %s \n",unite[x-1],unite[z-1]);
				}
			
			}else if ( (y != 0) && (z == 0) ) {
				if (x == 1){
					printf (" cent %s",centaine[y-1]);
				
				}else {
					printf (" %s cent %s \n",unite[x-1],centaine[y-1]);
				}
			
			}else {
				if (x == 1) {
					if (y == 1) {
						printf (" cent %s \n",dizaine[z-1]);
					
					}else if ( (y==7) || (y==9) ) {
						printf (" cent %s %s \n",centaine[y-2],dizaine[z-1]);
					
					}else {
						printf (" cent %s %s \n",centaine[y-1],unite[z-1]); 
					}
				
				}else {
					if (y==1) {
						printf (" %s cent %s \n",unite[x-1],dizaine[z-1]);
					
					}else if ( (y==7) || (y==9) ) {
						printf (" %s cent %s %s \n",unite[x-1],centaine[y-2],dizaine[z-1]);
					
					}else {
						printf (" %s cent %s %s \n",unite[x-1],centaine[y-1],unite[z-1]);
					}
				}
			}		
	     
	      }
	
	}else {
		printf ("votre nombre ne se situe pas entre 0 et 999");
	}
}


int main () {
	int a ,  choix ;
	
	printf (" Bienvenue dans ce mini programme de conversion \n");
	printf (" Entrer un chiffre compris entre 0 et 999 \n ");
	debut : printf ("	Entrer un nombre : ");
	scanf ("%d", &a);
	conversion (a);
	
	printf ("		taper : (0) quitter ou (1) continuer : ");
	scanf ("%d",&choix);
	
	if (choix) {
		goto debut ;
	
	}else {
		return 0 ;
	} 
}	
		
