#include <stdio.h>

int main()
{
	int a,  i = 0, j;
	while (scanf("%d", &a) != EOF)
	{
		int b, c = 11;
		char n[102], n2[102];
		i++;
		for (j = 1; j <= a; j++)
		{
			scanf("%s %d", n, &b);
			if (b < c)
			{
				c = b;
				for (int j = 0; j <= 102; j++)
				{
					n2[j] = n[j];
				}
			}
			else if (b == c)
			{
				for (int j = 0; j <= 102; j++)
				{
					if (n2[j] > n[j])
					{
						break;
					}
					else if (n2[j] < n[j])
					{
						c = b;
						for (int j = 0; j <= 102; j++)
						{
							n2[j] = n[j];
						}
						break;
					}
				}
			}
		}
		printf("Instancia %d\n%s\n\n", i, n2);
	}

	return 0;
}
