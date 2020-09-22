/*
 *
 * Joey Sheridan
 * 2290839
 * OS Assignment 1
 * filecpy()
 *
 * To run, compile filecpu() with gcc and then run the following command :
 * ./a.out source.txt destination.txt
 *
 */




#include <stdio.h>

//Allows for multiple arguments to be passed and stored in argv[]
int main(int argc, char *argv[])
{
   //File pointers from passed arguments in command line
   FILE *fptr1;
   FILE *fptr2;

   //Program variables
   int i;
   char ch;

   //Test for argument functionality
   printf("Total number of argument passed : %d\n", argc);

   //Opens source file using argv[1] in read mode using "r" to check if it exists
   if((fptr1 = fopen(argv[1], "r") ) == NULL)
   {

      printf("Error. . . \n The file cant be opened. . .\n");
      return -1;

   }

   //Opens the destination file
   fptr2 = fopen(argv[2], "w");

   //While the end of the file has not yet been reached , copy the next character to variable ch
   //then, put ch into ptr2(destination) with putc
   while( !feof(fptr1))
   {
      ch = getc(fptr1);
      if (ch != EOF)
      {
         putc(ch,fptr2);
      }
   }

   //Close connections
   fclose(fptr1);
   fclose(fptr2);

   printf("File copy complete");

   return 0;

}
