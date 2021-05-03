/*********************************************
 * Id: wagn9165
 * 
 * Performs Gaussian elimination on input
 *********************************************/

#include <stdio.h>
#include <stdlib.h>

//Prints the matrix to screen
void printMatrix(float **, int, int);

int main(int argc, char **argv)
{

   if(argc < 2)
   {
      printf("Please present the first variable as the number of equations,\n");
      printf("followed by elements of the equations.\n");
      return 1;
   }


   int argv1 = atoi(argv[1]);
   int cols = ((argc - 2) / argv1);
   if((argc - 2) % (argv1) != 0)
   {
      printf("The given input could not be made into %s equations.\n", argv[1]);
      printf("Please check your input and try again.\n");
      return 1;
   }

   float Arr[(argv1)][(argv1 + 1)];

   int i, j, k = 2;

   for(i = 0; i < argv1; i++)
   {
      for(j = 0; j < cols; j++)
      {
         Arr[i][j] = atoi(argv[k++]);
      }
   }

   //Print Function
   for(i = 0; i < argv1; i++)
   {
      for(j = 0; j < cols; j++)
      {
         printf("%.2f ", Arr[i][j]);
      }
      printf("\n");
   }

   printf("\n");

   float tempji;
   int temp, temp1;

   for(i = 0; i <= (argv1 - 2); i++)
   {
      for(j = (i + 1); j <= (argv1 - 1); j++)
      {
         tempji = Arr[j][i];
         for(k = i; k <= argv1; k++)
         {
            Arr[j][k] = (Arr[j][k] - ((Arr[i][k] * tempji) / Arr[i][i]));
         }
      }
      //Print Function
      for(temp = 0; temp < argv1; temp++)
      {
         for(temp1 = 0; temp1 < cols; temp1++)
         {
            printf("%.2f ", Arr[temp][temp1]);
         }
         printf("\n");
      } 
      printf("\n");
   }

   return 0;
}
