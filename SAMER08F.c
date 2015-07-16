#include<stdio.h>
int main()
{
	int t=1,n,s;
	for(;t;)
	{
		scanf("%d",&n);
			if(n==0)
				break;
		for(s=0;n;n--)
			s=s+n*n;
		printf("%d\n",s);
	}
return 0;
}
