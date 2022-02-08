/**
 * @file interations.c
 * @author Sebastian Kuckluck
 * @brief iterations in loops
 * @version 0.1
 * @date 2022-02-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "stdio.h"

int	main()
{
	int	iteration;

	iteration = 1;
	while (iteration <= 7)
	{
		if (iteration == 1)
			printf("This is iteration number %d\nAnd this is a custom message\n", iteration);
		else if (iteration == 7)
			printf("This is iteration number %d\nAnd this is a custom message\n", iteration);
		else
			printf("This is iteration number %d\n", iteration);
		iteration++;
	}
	return (0);
}
