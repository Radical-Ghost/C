//To find the Roots of a Quadratic Equation

#include<stdio.h>
#include<conio.h>
#include<math.h>
int main()
{
	int a,b,c,d,r1,r2;
	printf("Enter the coefficients of the quadratic equation: ");
	scanf("%d%d%d",&a,&b,&c);
	
	d=b*b-4*a*c;
	
	if (d>0)
	{
      r1 = -b+sqrt (d) / (2*a);
      r2 = -b-sqrt (d) / (2*a);
      printf ("The real roots = %d %d", r1, r2);
   }
   else if (d==0)
   {
      r1 = -b/(2*a);
      r2 = -b/(2*a);
      printf ("roots are equal =%d %d", r1, r2);
   }
   else
      printf("Roots are imaginary");
      getch();
}
