/*********************************************
 * Id: wagn9165
 * 
 * Tower of Hanoi Algorithm
 *********************************************/

#include <stdio.h>
#include <stdlib.h>

//moveDisk: moves the disks
void moveDisk(int, char, char, char);

int main(int argc, char **argv)
{
   moveDisk(atoi(argv[1]), 'A', 'B', 'C');
   return 0;
}

//moveDisk: moves the disk
void moveDisk(int n, char currPeg, char auxPeg, char goalPeg)
{
   if(n == 1)
   {
      printf("Move %c to %c\n", currPeg, goalPeg);
      return;
   }

   moveDisk(n - 1, currPeg, goalPeg, auxPeg);
   printf("Move %c to %c\n", currPeg, goalPeg);
   moveDisk(n - 1, auxPeg, currPeg, goalPeg);
   return;
}
