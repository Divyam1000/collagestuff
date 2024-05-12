#include<stdio.h>

#define arrSize 6

int main()
{

   char arr[] = {'d', 'c', 'v', 'g', 'k', 'a'};
   char current;   
   int i, j;
   for(i = 1; i<arrSize; i++)
   {
	current = arr[i];
	for(j = i-1; j>=0 && arr[j] > current; j--)
	{
	    arr[j+1] = arr[j];
	}
	arr[j+1] = current;
	 
   }

   for(int t = 0; t <arrSize ; t++)
	printf("%c  ", arr[t]);

   
}