/*********************************************
 * Id: wagn9165
 * 
 * Tower of Hanoi Algorithm
 *********************************************/

#include <stdio.h>
#include <stdlib.h>

//moveDisk: moves the disks
void moveDiskRestricted(int, char, char, char);

int main(int argc, char **argv)
{
   moveDiskRestricted(atoi(argv[1]), 'A', 'B', 'C');
   return 0;
}

//moveDisk: moves the disk
void moveDiskRestricted(int n, char currPeg, char auxPeg, char goalPeg)
{
   if(n == 1)
   {
      printf("Move %c to %c\n", currPeg, auxPeg);
      printf("Move %c to %c\n", auxPeg, goalPeg);
      return;
   }

   moveDiskRestricted(n - 1, currPeg, auxPeg, goalPeg);
   printf("Move %c to %c\n", currPeg, auxPeg);
   moveDiskRestricted(n - 1, goalPeg, auxPeg, currPeg);
   printf("Move %c to %c\n", auxPeg, goalPeg);
   moveDiskRestricted(n - 1, currPeg, auxPeg, goalPeg);
   return;
}
