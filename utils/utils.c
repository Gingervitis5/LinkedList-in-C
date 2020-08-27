#include "utils.h"

void strip(char *array)
{
	if(array == NULL)
	{
		perror("array is null");
		exit(-99);
	}// end if

	int len = strlen(array), x = 0;
   
	while(array[x] != '\0' && x < len)
	{
	  if(array[x] == '\r')
		 array[x] = '\0';

	  else if(array[x] == '\n')
		 array[x] = '\0';

	  x++;

	}// end while
   
}// end strip



int menu()
{
   int choice;
   printf("1) Print the list\n");
   printf("2) Add First\n");
   printf("3) Add Last\n");
   printf("4) Sort\n");
   printf("5) Remove Last\n");
   printf("6) Remove Item\n");  
   printf("7) Clear the list\n"); 
   printf("8) Quit\n"); 
   printf("Choice --> ");
   scanf("%d", &choice);
   
   while(choice < 1 || choice > 8)
   {
   printf("1) Print the list\n");
   printf("2) Add First\n");
   printf("3) Add Last\n");
   printf("4) Sort\n");
   printf("5) Remove Last\n");
   printf("6) Remove Item\n");  
   printf("7) Clear the list\n"); 
   printf("8) Quit\n"); 
   printf("Choice --> ");
   scanf("%d", &choice);
   
   }// end while
   char temp[100];
   fgets(temp, 100, stdin);
   return choice;
   
}// end menu

int readIndex(int total)
{
	int num;

	do
	{
		printf("Please enter an index ");
		scanf("%d", &num);

	}while(num < 0 || num >= total);

	while(fgetc(stdin) != '\n') ;

	return num;
}// end readIndex
