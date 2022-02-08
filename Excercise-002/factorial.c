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
