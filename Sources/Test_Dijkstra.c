

#include "../Headers/main.h" 


int main(){

FILE* f1;
	if( ( f1=fopen("test_mot3.txt","r") ) == NULL ) return 1;
int taille_c=0;	
char** p=NULL;
int taille_mots = Taille_Mots(f1);
int nombre_mots = Taille_Fichier(f1);
taille_c=nombre_mots;
	printf("taillc: %d",taille_c);
char** C=Remplissage_Tableau(f1,taille_c,taille_mots);
	printf("taillc: %d",taille_c);
	C = Ajout_Mot_Tableau(C,taille_mots,"sel",&taille_c);
	printf("taillc: %d",taille_c);
	p = Recherche_Mot_Tableau(C,"dod",taille_c);
	printf("taillc: %d",taille_c);
	taille_c=Suppression_Dans_Tableau(C,"bac",taille_c);
	printf("taillc: %d",taille_c);
}

