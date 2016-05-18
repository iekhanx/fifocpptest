/*
 *
 * */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a = 1;

	printf("\nStart\n");

	while (a = 1)        /* infinite loop. if while (a == 1) break itself */
	{
		a++;
		printf("* a = %d\n", a);
	}

	printf("Done\n");
    return 0;
}

