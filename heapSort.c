#include<stdio.h>
#include<math.h>
void printArray( int A[] , int n)
{ int i ;
  for(i = 0 ; i < n ; i++)
    printf(" %d ",A[i]);
  printf("\n");}
  
int makeshort( int A[] , int l )
{  int i;
   int B[l];
   for ( i=0 ; i <l ; i++)
     B[i] = A[i];
   return B ;}
   
void maxHeapify( int A[] , int i )
{ int left = 2i+1;
  int right = 2i+2;
  int largest ;
  if ( A[i] < A[left] )
    largest = left;
  else 
    largest =  i ;
  if ( A[largest] < A[right] )
    largest = right ; 
  if ( largest != i )
    maxHeapify(A,largest);
  }
    
void buildMaxHeap( int A[] )
{  int l = sizeof(A)/sizeof(A[0]);
   int i ;
   for ( i = (floor(l/2))-1 ; i >= 0 ; i--)
     maxHeapify(A,i);
   }
     
void heapSort( int A[] )
{  int l = sizeof(A)/sizeof(A[0]);
   int i ;
   buildMaxHeap(A);
   for ( i = l-1 ; i >= 0 ; i--)
   {  A[0] = A[i] ;
      l = l-1;
      A = makeshort(A,l);
      maxHeapify(A,0);}
}
      
int main ()
{  int n,i,A[1000];
   printf("please enter the length of your array:\n");
   scanf("%d",&n);
   printf("please enter the values:\n");
   for ( i = 0 ; i < n ; i++)
     scanf("%d",&A[i]);
   printf(" Your array looks like:\n");
   printArray(A,n);
   heapSort(A);
   printf(" The required sorted array is :\n");
   printArray(A,n);
   return 0;}      