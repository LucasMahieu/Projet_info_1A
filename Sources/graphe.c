//
//  graph.c
//  
//
//  Created by Mahieu Lucas on 18/04/2015.
//

#include "../Headers/main.h"

L_SOMMET* Creer_Graphe(FILE* fichier,int taille_mots, int nombre_mots){ // on va retourner en adresse la taille de la table
	char mot_fichier[20];  // 20 = taille max d'un mots avec de la marge
	int position=0;
	L_SOMMET* Table_hachage;
	rewind(fichier);
	printf("\n\n ---\n");
	if((Table_hachage=(L_SOMMET*)calloc(nombre_mots,sizeof(*Table_hachage)))==NULL) return NULL;  // il faudra faire une fonction qui calcule le # de mots
	
	// ici on va remplir notre tableau avec les listes. La position est déterminer par la sortie du hachoire AH AH AH (sadique)
	while (fgets(mot_fichier,taille_mots+2,fichier)!=NULL){   
	//fgets = null quand on a EOF. Il arrete la saise de charactere lorsqu'il rencontre un retour à la ligne. c'est pourquoi j'ai mis +2, comme ça il va aller lui meme 'buter' contre le retour à la ligne, et au coup	d'après il sera en bonne position.
		if(mot_fichier[strlen(mot_fichier)-1]=='\n') mot_fichier[strlen(mot_fichier)-1]='\0';
		printf("mot: %s\n",mot_fichier);
		if((strlen(mot_fichier)-1)<taille_mots){
			position=Hash(mot_fichier,CODE_HACHAGE,nombre_mots,taille_mots); //calcul de la position dans la table par fct de hachage
			printf("hash: %d \n",position);		
			Table_hachage[position]=Ajout_Tete_L_SUCC(Ajout_Tete(mot_fichier,NULL,taille_mots),*(Table_hachage+position));       // puis on l'ajoute en tete de liste pour ne pas deranger les éventuels mots deja présents
		}
	};
	printf("--- \n\n");
	rewind(fichier);
	return (Table_hachage);
}


void Recherche_Successeur(T_GRAPHE G,FILE* f1,int taille_mots, int nombre_mots){
	int i=0,chgt_alpha=0,P_Hash=0,lettre=0;
	int position = 0;
	char* mot_origine;
	char* mot_test; 
	mot_test=(char*)calloc(taille_mots,sizeof(*mot_test));
	char alpha[26]="abcdefghijklmnopqrstuvwxyz";//On utilisera cette chaine de caractère pour mofifier les charactères dans le mot "mot"
	L_SOMMET p_collision = NULL;// On prend un pointeur pour pouvoir parcourir les listes associées à la table de hachage
	p_collision = *(G.table);
	L_SOMMET r =NULL;
	rewind(f1);
	//On parcours la table de hashage pour chaque mot formé avec la variable "mot_remplissage". Ce mot "mot_remplisssage" est formé à partir des mots déjà présent dans la table de hashage. Et si on trouve ce nouveau mot_remplissage dans la table de hashage on peut l'ajouter en tête
	for(lettre=0;lettre<taille_mots;lettre++){  // lettre que l'on bouge
		for(P_Hash=0;P_Hash<nombre_mots;P_Hash++){//P_Hash fait changer le ligne dans la table de hashage
			p_collision=*((G.table)+P_Hash);
			while(p_collision){
				mot_origine=(p_collision->val)->mot;
				for (i=0;i<taille_mots;i++) mot_test[i]=mot_origine[i];
				for(chgt_alpha=0;chgt_alpha<26;chgt_alpha++){
					mot_test[lettre]=alpha[chgt_alpha];//On modifie la lettre de mot_test avec le tableau alphabet
					if(strcmp(mot_test,mot_origine)) {
						position=Hash(mot_test,CODE_HACHAGE,nombre_mots,taille_mots);//On hash le mot_test et on regarde si il appartient à la table de hasgae
						r=Rech_Chaine(mot_test,*((G.table)+position));//On recherche si le mot_remplissage est bien présent dans la table hashage
						if(r){//Si mot_remplissage est présent dans la table de hashage, on peut faire un ajout en tête
							((p_collision->val)->Liste_succ)=Ajout_Tete_L_SUCC(r->val,(p_collision->val)->Liste_succ);
						}
					}
				}
				p_collision=p_collision->suiv;
			}
		}
	}
	rewind(f1);
}


//0n applique l'algorithme de Dijkstra

void plus_court_chemin(char* depart, char* arrive, int nombre_mots, T_GRAPHE G, FILE* fichier, int taille_mots){

	int i; 
	int* pcc;
	int infini = INT_MAX;
	int position; //Utilisé pour localiser le mot depart dans la table de hashage
	
	T_GRAPHE C ; //On définit le tableau C des sommets à visiter. EST CE QUE POINTEUR SUR L_SOMMET PEUT SUFFIR ?
	L_SOMMET* S; //On définit le tableau S des sommets visités
	L_SUCC pointeur_sur_depart;


	C.table =Creer_Graphe(fichier,taille_mots);//On crée un graphe avec tous les mots du fichier
	Recherche_Successeur(C,fichier,taille_mots,nombre_mots,taille_fichier);// On recomplète l'ensemble des successeurs associé à chacun des mots du fichier


	pcc = calloc(nombre_mots,sizeof(*pcc)); //On alloue un tableau pour retenir toutes les valeurs de cout, valeur de PCC

	*************On initialise l'ensemble des élements de PCC**********
	pcc[0]=0;//La distance du mot "départ" à lui même est de zéro
	for(i=1,i<nombre_mots,i++){
		pcc[i]=infini;
	}


	*************On applique l'algorithme**********
	position = Hash(depart,CODE_HASHAGE,nombre_mots);//On regarde où se situe notre mot de "départ" dans la table de hashage 
	//On va chercher dans les successeurs de mot "départ" pour déterminer le départ du chemin suivant, voir graphe.On se positionne dans la table de hashage là où se trouve le mot "depart" et on regarde la liste de successeur 
	pointeur_sur_depart = Rech_Chaine(mot_remplissage,*(C.table+position)); //Retourne un pointeur sur où se trouve le mot dans la liste associé à l'endroit où se trouve mot "depart" dans la table de hashage. C'est un pointeur sur un l-succ
	//On va parcourir l'ensemble de la table des successeurs associé à "depart". De cette manière on peut parcourir tous les élements qui sont à plus proche distance de depart
	q = pointeur_sur_depart;
	while(!q){
		positionq
		q = q->suiv;
		
		
		
		
	
