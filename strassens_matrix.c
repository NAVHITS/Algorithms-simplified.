//Strassen matrix multiplication.

//Program begins at line 35

//Normal matrix multiplication
//Imagine matrix1 a,b,c,d
//Matrix2 e,f,g,h
//matrix3=matrix1*matrix2 (refer google for the steps to do this)

//Starssens method (I have no idea of why this exists)
//Imagine matrix1 a,b,c,d
//Matrix2 e,f,g,h
//matrix3 c1,c2,c3,c4
//p1=a(f-h)
//p2=(a+b)h
//p3=(c+d)e
//p4=d(g-e)
//p5=(a+d)(e+h)
//p6=(b-d)(g+h)
//p7=(a-c)(e+f)

//Matrix3 formation
//c1=p4+p5+p6-p2
//c2=p1+p2
//c3=p3+p4
c4=p1-p3+p5-p7

//Put them together in tge matrix form.
//Strassens method done. (Don't ask me why it works this way.)





#include<stdio.h>
void main()
{
	int a[2][2], b[2][2], c[2][2], p1,p2,p3,p4,p5,p6,p7,c1,c2,c3,c4,i,j;
	printf("Enter the 1st matrix\n");
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	printf("\nEnter the 2nd matrix\n");
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			scanf("%d",&b[i][j]);
		}
	}
	p1=(a[0][0]*(b[0][1]-b[1][1]));
	p2=((a[0][0]+a[0][1])*b[1][1]);
	p3=((a[1][0]+a[1][1])*b[0][0]);
	p4=(a[1][1]*(b[1][0]-b[0][0]));
	p5=(a[0][0]+a[1][1])*(b[0][0]+b[1][1]);
	p6=(a[0][1]-a[1][1])*(b[1][0]+b[1][1]);
	p7=(a[0][0]-a[1][0])*(b[0][0]+b[0][1]);
	c[0][0]=p4+p5+p6-p2;
	c[0][1]=p1+p2;
	c[1][0]=p3+p4;
	c[1][1]=p1-p3+p5-p7;
	printf("\nResult\n");
	for(i=0;i<2;i++)
	{
		printf("\n");
		for(j=0;j<2;j++)
		{
			printf("%d\t",c[i][j]);
		}
	}
}
