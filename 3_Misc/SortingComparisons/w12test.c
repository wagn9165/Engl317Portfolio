/*********************************************
 * Id: wagn9165
 * 
 * Sorting Comparison
 *********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

//Insertionsort: Sorts the array
void insertionsort(int*, int);

//SelectionSort: Sorts the array
void selectionSort(int*, int);

//QuickSort: Sorts the array
void quicksort(int*, int, int, int);

//HoarePartition: Partitions the array
int hoarePartition(int*, int, int);

int main()
{
   int begin = 2;
   int end = 6;
   int base = 10;
   int currPow;
   int i, j;
   srand(time(NULL));

   i = end - begin + 1; //index for how many entries to array
   double iTime[i];
   double sTime[i];
   double qTime[i];

   struct timeval start, stop;

   for(i = begin; i <= end; i++)
   {
      //Establish current number of entries
      currPow = 1;
      for(j = 0; j < i; j++)
      {
         currPow *= base;
      }

      //Create Array
      int A[currPow];
      for(j = 0; j < currPow; j++)
      {
         A[j] = rand() % 10;
      }

      gettimeofday(&start, NULL);
      insertionsort(A, currPow);
      gettimeofday(&stop, NULL);
      iTime[i - begin] = (double)(stop.tv_sec - start.tv_sec) * 1000 + (double)(stop.tv_usec - start.tv_usec) / 1000;

      gettimeofday(&start, NULL);
      selectionSort(A, currPow);
      gettimeofday(&stop, NULL);
      sTime[i - begin] = (double)(stop.tv_sec - start.tv_sec) * 1000 + (double)(stop.tv_usec - start.tv_usec) / 1000;

      gettimeofday(&start, NULL);
      quicksort(A, 0, currPow, currPow);
      gettimeofday(&stop, NULL);
      qTime[i - begin] = (double)(stop.tv_sec - start.tv_sec) * 1000 + (double)(stop.tv_usec - start.tv_usec) / 1000;
   }

   //Print Header
   printf("//+--------------------+----------------+----------------+------------+\n");
   printf("//| Number of Elements | Selection Sort | Insertion Sort | Quick Sort |\n");
   printf("//+--------------------+----------------+----------------+------------+\n");

   for(i = begin; i < end; i++)
   {
      //Establish current number of entries
      currPow = 1;
      for(j = 0; j < i; j++)
      {
         currPow *= base;
      }

      //Print Num Elements
      printf("//|%*d", 20, currPow);

      //Print Selection
      printf("|%*d", 16, (int)sTime[i - begin]);

      //Print Insertions
      printf("|%*d", 16, (int)iTime[i - begin]);

      //Print Quick
      printf("|%*d|\n", 12, (int)qTime[i - begin]);
   }
   printf("//+--------------------+----------------+----------------+------------+\n");

   return 0;
}

//insertionsort: sorts the array
void insertionsort(int *A, int size)
{
   int i, j, v;

   for(i = 1; i < size; i++)
   {
      v = A[i];
      j = i - 1;

      while(j >= 0 && A[j] > v)
      {
         A[j + 1] = A[j];
         j = j - 1;
      }
      A[j + 1] = v;
   }
   return;
}

//selectionSort: Performs a selection sort on the data
void selectionSort(int *A, int size)
{
   int i, j, min, temp;

   for(i = 0; i <= size - 2; i++)
   {
      min = i;
      for(j = i + 1; j <= size - 1; j++)
      {
         if(A[j] < A[min])
         {
            min = j;
         }
      }
      temp = A[i];
      A[i] = A[min];
      A[min] = temp;
   }
}

//Quicksort: sorts the array
void quicksort(int *A, int l, int r, int size)
{
   //printf("CAlled quicksort with %d, %d\n", l, r);
   int s;
   if(l < r)
   {
      s = hoarePartition(A, l, r);
      quicksort(A, l, s - 1, size);
      quicksort(A, s + 1, r, size);
   }
   return;
}

//hoarePartition: creates the partition and swaps
int hoarePartition(int *A, int l, int r)
{
   int p, i, j, temp;
   p = A[l];
   i = l;
   j = r + 1;

   do
   {
      do
      {
         i++;
      } while(A[i] < p);
      do
      {
         --j;
      } while(A[j] > p);
   
      temp = A[i];
      A[i] = A[j];
      A[j] = temp;
   } while(i < j);

   temp = A[i];
   A[i] = A[j];
   A[j] = temp;

   temp = A[l];
   A[l] = A[j];
   A[j] = temp;
   return j;
}
//+--------------------+----------------+----------------+------------+
//| Number of Elements | Selection Sort | Insertion Sort | Quick Sort |
//+--------------------+----------------+----------------+------------+
//|                 100|               0|               0|           0|
//|                1000|               1|               0|           0|
//|               10000|             130|              74|           1|
//|              100000|           20091|           10050|          18|
//+--------------------+----------------+----------------+------------+
//+--------------------+----------------+----------------+------------+
//| Number of Elements | Selection Sort | Insertion Sort | Quick Sort |
//+--------------------+----------------+----------------+------------+
//|                 100|               0|               0|           0|
//|                1000|               1|               0|           0|
//|               10000|             200|              94|           1|
//|              100000|           19215|           10459|          32|
//+--------------------+----------------+----------------+------------+
//+--------------------+----------------+----------------+------------+
//| Number of Elements | Selection Sort | Insertion Sort | Quick Sort |
//+--------------------+----------------+----------------+------------+
//|                 100|               0|               0|           0|
//|                1000|               1|               0|           0|
//|               10000|             131|              74|           1|
//|              100000|           19808|           11399|          37|
//+--------------------+----------------+----------------+------------+
