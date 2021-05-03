/*********************************************
 * Id: wagn9165
 * 
 * Tower of Hanoi Algorithm
 *********************************************/

#include <stdio.h>
#include <stdlib.h>

//moveDisk: moves the disks
void moveDisk(int, char, char, char);

//moveDiskTwo: moves the disks but different
void moveDiskTwo(int, char, char, char);

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
      printf("Move %c to %c\n", currPeg, auxPeg);
      printf("Move %c to %c\n", auxPeg, goalPeg);
      return;
   }

   //Move Stack to C
   moveDisk(n - 1, currPeg, auxPeg, goalPeg);
   //Move bottom disk to middle
   printf("Move %c to %c\n", currPeg, auxPeg);
   //Move right stack to beginning
   moveDiskTwo(n - 1, goalPeg, auxPeg, currPeg);
   //Move bottom disk to end
   printf("Move %c to %c\n", auxPeg, goalPeg);
   //Move beginning to end
   moveDisk(n - 1, currPeg, auxPeg, goalPeg);
   return;
}

//Another move function with default case to only move one peg
void moveDiskTwo(int n, char currPeg, char auxPeg, char goalPeg)
{
   if(n == 1)
   {
      //Move disk 1
      printf("Move %c to %c\n", currPeg, goalPeg);
      return;
   }

   moveDisk(n - 1, currPeg, goalPeg, auxPeg);
   printf("Move %c to %c\n", currPeg, goalPeg);
   moveDisk(n - 1, auxPeg, currPeg, goalPeg);
   return;
}
