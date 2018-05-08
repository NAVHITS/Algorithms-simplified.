//Maximum and minimum with divide and conquer method.


#include<stdio.h>
#include<time.h>
int max, min, a[20];
void maxmin(int i, int j)
{
 int max1, min1, mid;
 if(i==j)
 {
  max = min = a[i];
 }
 else
 {
  if(i == i+1)
  {
   if(a[i] <a[j])
   {
    max = a[j];
    min = a[i];
   }
   else
   {
    max = a[i];
    min = a[j];
   }
  }
  else
  {
   mid = (i+j)/2;
   maxmin(i, mid);
   max1 = max; min1 = min;
   maxmin(mid+1, j);
   if(max <max1)
    max = max1;
   if(min > min1)
    min = min1;
  }
 }
}
int main ()
{
 int i, n;
 clock_t t;
 t=clock();
 printf("\nHow many elements?\n");
 scanf("%d",&n);
 printf("\nEnter the numbers : \n");
 for (i=1;i<=n;i++)
  scanf("%d",&a[i]);

 max = a[0];
 min = a[0];
 maxmin(1, n);
 printf("Minimum element in an array : %d\n", min);
 printf("Maximum element in an array : %d\n", max);
 t=clock()-t;
 double total=((double)t);
 printf("Timespent: %f", total);
 return 0;
}
