#include<stdio.h>
int main()
{
	int t,a,b,c;
	scanf("%d",&t);
	for(;t;t--)
	{
		scanf("%d%d",&a,&b);
		if(a==b)
		{
			if(a%2==0)
				printf("%d\n",a+b);
			else
				printf("%d\n",a+b-1);
		}
		else if(a-b==2)
		{
			if(a%2==0)
				printf("%d\n",a+b);
			else
				printf("%d\n",a+b-1);
		}
		else
			printf("No Number\n");
			
	}	
return 0;
}
