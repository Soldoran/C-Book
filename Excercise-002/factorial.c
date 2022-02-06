/**
 * @file factorial.c
 * @author Sebastian Kuckluck
 * @brief Use of loops
 * @version 0.1
 * @date 2022-02-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "stdio.h"

/*	My solution with a while-loop	*/

int	main()
{
	int	factorial;
	int	result;
	int	tmp;

	printf("Enter a whole number: ");
	scanf("%d", &factorial);
	tmp = factorial;
	result = 1;
	while (tmp > 1)
	{
		result = result * tmp;
		tmp--;
	}
	printf("%d! is %d\n", factorial, result);
	return (0);
}

/*	Solution from the Book with for-loop	*/

/*
int main()
{
	int x;
	int Produkt = 1;
	printf ("Es wird die Fakultaet aus der Zahl\n");
	scanf ("%d", &x);
	printf ("gebildet. \n...\n...\n");
	for (int i = 1; i<=x; i++)
	{
		Produkt = Produkt * i;
	}
	printf ("Trommelwirbel..\nErgebnis: %d", Produkt);
	return 0;
}
*/