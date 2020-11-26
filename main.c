#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "functions.h"

DataItem* item;

int main(int argc, char const *argv[]){
  char name[20];
   int age;
   int choix;

   while(choix!=5){

   printf("MENU :\n1-Inserer\n2-Rechercher\n3-Supprimer\n4-Afficher\n5-Quitter\n\nQuelle option ? : ");
   scanf("%d",&choix);

   switch(choix){
   	case 1:
   		printf("Entrez le nom : ");
   		scanf("%s",name);
   		printf("Entrez l'age  : ");
   		scanf("%d",&age);
   		insert(name,age);
   		break;
   	case 2:
   		printf("Entrez le nom a rechercher :");
   		scanf("%s",name);
   		item = search(name);
   		if(item == NULL)
   			printf("Introuvable\n");
   		else
   			printf("nom : %s , Numero de tel : %d\n",item->name,item->age);
   		break;
   	case 3:
   		printf("Entrez le nom a supprimer : ");
   		scanf("%s",name);
   		item = search(name);
   		if(item == NULL)
   			printf("Introuvable\n");
   		else
   			delete(item);//delete is supposed to look this up //okay
   		break;
   	case 4:
   		display();
   		break;
   	case 5:
   		printf("Au revoir !!!\n");
   		break;

   }
}
  return 0;
}
