/**
 * @file ex001.c
 * @author Sebastian Kuckluck
 * @brief look for all possible dividers of input
 * @version 0.1
 * @date 2022-02-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include "stdio.h"

/*	This is the books solution	*/
int	main()
{
	int	x;

	x = 0;
	printf("Enter any whole number: ");
	scanf("%d", &x);
	printf("%d can be divided by: ", x);
	if ((x % 2 == 0) && (x % 3 == 0) && (x % 5 == 0) && (x % 7 == 0))
		printf("Seven, Five, Three or Two");
	else if ((x % 2 == 0) && (x % 3 == 0) && (x % 5 == 0))
		printf("Five, Three or Two");
	else if ((x % 2 == 0) && (x % 3 == 0))
		printf("Three or Two");
	else if (x % 2 == 0)
		printf("Two");
	else if (x % 3 == 0)
		printf("Three");
	else if (x % 5 == 0)
		printf("Five");
	else if (x % 7 == 0)
		printf("Seven");
	else
		printf("One and itself. Thats a prime!");
	return (0);
}
