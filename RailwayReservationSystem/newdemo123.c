#include<stdio.h>
void main()
{
    int a,b,y;
    printf("CALCULATOR BY ...................................................................................");
    printf("\nPress 1 for Addition:");
    printf("\nPress 2 for Subtraction:");
    printf("\nPress 3 for Multiplication:");
    printf("\nPress 4 for Division:");
    scanf(" %d",&y);
    printf("Enter two numbers:");
    scanf(" %d %d",&a,&b);
    switch(y)
    {
    case 1:printf("sum=%d\n\n\n\n\n\n\n\n\n",a+b);break;
    case 2:printf("sub=%d",a-b);break;
    case 3:printf("mul=%d",a*b);break;
    case 4:printf("div=%d",a/b);break;
    }


}
