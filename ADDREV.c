#include<stdio.h>
int rev(int m)
{
	int p,s=0;
	while(m)
	{
	p=m%10;
	m=m/10;	
	s=s*10+p;
	}
	return(s);
}
int main()
{
	int n,a,b,c,d;
	scanf("%d",&n);
	while(n)
	{
		scanf("%d%d",&a,&b);
		c=rev(a);
		d=rev(b);
		printf("%d\n",rev(c+d));
		n--;
	}
return 0;
}
