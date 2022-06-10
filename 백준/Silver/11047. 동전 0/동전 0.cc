#include <stdio.h>

int main()
{
	int count=0;
	int n, k, won[15];
	scanf("%d %d",&n,&k);
	for(int i=0; i<n; i++)
	{
		scanf("%d",&won[i]);
	}
	
	for(int i=n-1; i>=0; i--)
	{
		if(k == 0)
		{
			break;
		}
		if(won[i] > k)
		{
			continue;
		}
		else
		{
			k-=won[i];
			count++;
			i++;
		}
	}	
	printf("%d",count);
}