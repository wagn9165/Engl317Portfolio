/*********************************************
 * Id: wagn9165
 * 
 * Horspool String Matching
 *********************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAX_ALPHABET 128
#define TABLE_ROW_LENGTH 16
#define MIN_WRITEABLE 32

//printShiftTable: prints shift tbale starting at first wrtiable character (space)
void printShiftTable(int table[]);

//buildShiftTable: creates shift table
void buildShiftTable(int **, char*, int);

//horspoolMatching: performs the matching
void horspoolMatching(char*, int, char*, int, int*, int*);

int main(int argc, char *argv[])
{
   char *p = argv[1];
   char *t = argv[2];

   int *shiftTable;
   shiftTable = (int*)malloc(sizeof(int) * (MAX_ALPHABET - MIN_WRITEABLE));

   int pSize = 0;
   while(p[pSize])
   {
      pSize++;
   }

   int tSize = 0;
   while(t[tSize])
   {
      tSize++;
   }

   int *matchTable;
   matchTable = (int*)malloc(sizeof(int) * tSize);

   //printf("key: %s size: %d\n", p, pSize);
   //printf("string: %s size: %d\n", t, tSize);

   buildShiftTable(&shiftTable, p, pSize);
   printShiftTable(shiftTable);
   horspoolMatching(p, pSize, t, tSize, shiftTable, matchTable);
   return 0;
}

//horspoolMatching: performs the matching
void horspoolMatching(char *p, int pSize, char *t, int tSize, int *shiftTable, int *matchTable)
{
   //m = pSize
   //n = tSize
   int i, j = 0, k;

   printf("%s\n", t);

   i = pSize - 1;

   while(i <= tSize - 1)
   {
      k = 0;

      while((k <= pSize - 1) && (p[pSize - 1 - k] == t[i - k]))
      {
         k++;
      }

      if(k == pSize)
      {
         printf("%*s%s---found\n", i-pSize+1, "", p);
         matchTable[j++] = i - pSize + 1;
         matchTable[j] = -1;
      }
      else
      {
         printf("%*s%s\n", i-pSize+1, "", p);
      }
      i = i + shiftTable[t[i] - MIN_WRITEABLE];
  }

   printf("Matches found at locations:");
   i = 0;
   while(matchTable[i] != -1)
   {
      printf(" %d", matchTable[i++]);
   }
   printf("\n");
   return;
}
//buildShiftTable: builds the shift table
void buildShiftTable(int **A, char *p, int pSize)
{
   int i;

   for(i = 0; i < MAX_ALPHABET - MIN_WRITEABLE; i++)
   {
      (*A)[i] = pSize;
   }

   for(i = 0; i < pSize - 1; i++)
   {
      (*A)[p[i] - MIN_WRITEABLE] = pSize - 1 - i;
   }

   return;
}

//printShiftTable: prints shift tbale starting at first wrtiable character (space)
void printShiftTable(int table[])
{
   int i, start;
   for(start = MIN_WRITEABLE; start < MAX_ALPHABET; start += TABLE_ROW_LENGTH)
   {
      for(i = start; i < start + TABLE_ROW_LENGTH; i++)
      {
         printf("%c\t", i);
      }
      printf("\n");

      for(i = start; i < start + TABLE_ROW_LENGTH; i++)
      {
         printf("%d\t", table[i - MIN_WRITEABLE]);
      }
      printf("\n\n");
   }

   return;
}
