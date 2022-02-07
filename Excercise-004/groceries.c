/**
 * @file groceries.c
 * @author Sebastian Kuckluck
 * @brief A program that ask the user for groceries to be bought
 * @version 0.1
 * @date 2022-02-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "stdio.h"
#include "string.h"
#include "ctype.h"

struct Item
{
	float	need;
	float	pack_size[2];
	float	price_brutto;
	float	need_suggestion[2];
	float	sum_brutto;
	float	sum_taxes;
	float	sum_netto;
};

void	start(void)
{
	printf("Your weekly groceries need to be bought.\nPlease enter how much of each item you need.\n\n");
}

void	check_amounts(float needs, float **pckSize)
{
	char	ret[1];
	int		tmp;
	int		tmp_small;
	int		tmp_big;

	tmp = (int)needs;
	if (*pckSize[0] > 0)	// items like eggs
	{
		if (tmp % (int)*pckSize[0] == 0 || tmp % (int)*pckSize[1] == 0)
			return;
		if (tmp % (int)*pckSize[0] != 0 || tmp % (int)*pckSize[1] != 0)
		{
			printf("Requested amount [%f] can't be bought.\n", needs);
			tmp_small = tmp;
			while (tmp_small % (int)*pckSize[0] != 0)
				tmp_small--;
			tmp_big = tmp;
			while (tmp_big % (int)*pckSize[1] != 0)
				tmp_big++;
			printf("Would you rather buy %f[A] or %f[B]? Please enter A or B.", (float)tmp_small, (float)tmp_big);
			scanf("%c", ret);
		}
	}
	else	// everything else
	{
		if (tmp % (int)*pckSize[1] != 0)
		{
			printf("Requested amount [%f] can't be bought.\n", needs);
			tmp_small = tmp;
			while (tmp_small % (int)*pckSize[1] != 0)
				tmp_small--;
			tmp_big = tmp;
			while (tmp_big % (int)*pckSize[1] != 0)
				tmp_big++;
			printf("Would you rather buy %f[A] or %f[B]? Please enter A or B.", (float)tmp_small, (float)tmp_big);
			scanf("%c", ret);
		}
	}
	if (ret[0] == 'A' || ret[0] == 'a')
		needs = (float)tmp_small;
	else if (ret[0] == 'B'|| ret[0] == 'b')
		needs = (float)tmp_big;
	printf("I entered here!!!");
}

void	items_needed(char itemName[20], char unit[10],float needs, float *pckSize)
{
	printf("%s [%s]:", itemName, unit);
	scanf("%f", &needs);
	check_amounts(needs, &pckSize);
}

int	main()
{
	//float	total;
	struct Item Eggs;
	Eggs.price_brutto = 0.3f;
	Eggs.pack_size[0] = 6;
	Eggs.pack_size[1] = 10;
	struct Item Rice;
	Rice.price_brutto = 1.93f;
	Rice.pack_size[0] = 0;
	Rice.pack_size[1] = 1;
	struct Item Hummus;
	Hummus.price_brutto = 4.98f;
	Hummus.pack_size[0] = 0;
	Hummus.pack_size[1] = 0.25;
	struct Item Tortillas;
	Tortillas.price_brutto = 6.41f;
	Tortillas.pack_size[0] = 0;
	Tortillas.pack_size[1] = 0.32;
	struct Item Beer;
	Beer.price_brutto = 0.9f;
	Beer.pack_size[0] = 0;
	Beer.pack_size[1] = 1;
	start();
	items_needed("Eggs", "Pcs", Eggs.need, Eggs.pack_size);
	items_needed("Rice", "Kg", Rice.need, Rice.pack_size);
	items_needed("Hummus", "Kg", Hummus.need, Hummus.pack_size);
	items_needed("Tortillas", "Kg", Tortillas.need, Tortillas.pack_size);
	items_needed("Beer", "Kg", Beer.need, Beer.pack_size);
	return (0);
}
