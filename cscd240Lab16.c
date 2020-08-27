#include "./words/word.h"
#include "./utils/utils.h"
#include "./utils/fileUtils.h"
#include "./listUtils/listUtils.h"
#include "./linkedList/linkedList.h"

int main()
{

   int total, choice;
   FILE * fin = NULL;
   LinkedList * myList = linkedList();

   fin = openInputFile_Prompt();
   total = countRecords(fin, 1);
   buildList(myList, fin, total, buildTypeWord);
   fclose(fin);
  
   do
   {
      choice = menu();

      switch(choice)
      {
         case 1: printList(myList, printTypeWord);
                 break;

         case 2: addFirst(myList, buildNode(stdin, buildTypeWord_Prompt));
                 break;

         case 3: addLast(myList, buildNode(stdin, buildTypeWord_Prompt));
                 break;

         case 4: sort(myList, compareWords);
                 break;

         case 5: removeLast(myList, cleanTypeWord);
                 break;
				 
	 case 6: removeItem(myList, buildNode(stdin, buildTypeWord_Prompt), cleanTypeWord, compareWords);
		 break;
				 
	 case 7: clearList(myList, cleanTypeWord);
		 break;
				 
      }// end switch

   }while(choice != 8);

   myList = cleanList(myList, cleanTypeWord);
   
   return 0;

}// end main
