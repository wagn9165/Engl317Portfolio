/*********************************************
 * Id: wagn9165
 * 
 * String Matching
 *********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
   //printf("%zu\n", strlen(argv[2]));
   printf("Matches found at locations:");

   int i, j;
   for(i = 0; i <= (strlen(argv[2]) - strlen(argv[1])); i++)
   {
      j = 0;
      while((j < strlen(argv[1])) && (argv[1][j] == argv[2][i + j]))
      {
         j++;
      }
      //printf("\tj: %d\n", j);

      if(j == strlen(argv[1]))
      {
         printf(" %d", i);
      }
   }
   printf("\n");
   return 0;
}

