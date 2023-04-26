#include <stdio.h>

int
main ()
{
  int a, b, c , d, e=-9999, i=0,j;
  while(scanf("%d", &a) != EOF){
  i++;
      for (j = 1; j <= a; j++)
	{
	  scanf ("%d", &b);
	  scanf ("%d", &c);
	  if(e<c || (e==c && b<d)){
	      e = c;
	      d = b;
	  }
	}
	printf ("Dia %d\n%d\n\n",i,d);
	e=-99999;
	d=99999999;
    }
  

  return 0;
}
