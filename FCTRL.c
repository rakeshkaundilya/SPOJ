#include<stdio.h>
int main()
{
	long int n,a;
	int t;
	scanf("%d",&t);
	for(;t;t--)
	{
	a=0;
		scanf("%ld",&n);
	while(n)
	{
		a=a+(n/5);
		n=n/5;
	}
	printf("%ld\n",a);
	}
return 0;
}
