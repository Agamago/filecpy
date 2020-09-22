/*
 *
 * Joey Sheridan
 * 2290839
 * OS Assignment 1
 * filecpy()
 *
 * To run, compile filecpu() with gcc and then run the following command :
 * ./a.out source.txt destination.txt
 
 */




#include <stdio.h>

//Allows for multiple arguments to be passed and stored in argv[]
int main(int argc, char *argv[])
{
   //File pointers from passed arguments in command line
   FILE *source;
   FILE *destination;

   //Program variables
   int i;
   char ch;

   //Test for argument functionality
   printf("Total number of argument passed : %d\n", argc);

   //Opens source file using argv[1] in read mode using "r" to check if it exists
   if((source = fopen(argv[1], "r") ) == NULL)
   {

      printf("Error. . . \n The file cant be opened. . .\n");
      return -1;

   }

   //Opens the destination file with writting permissions
   destination = fopen(argv[2], "w");

   //While the end of the file has not yet been reached , copy the next character to variable ch
   //then, put ch into destination with putc
   while( !feof(source))
   {
      ch = getc(source);
      if (ch != EOF)
      {
         putc(ch,destination);
      }
   }

   //Close connections
   fclose(source);
   fclose(destination);

   printf("File copy complete");

   return 0;

}
