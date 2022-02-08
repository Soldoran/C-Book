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

float	check_amounts(float needs, struct Item item)
{
	char	ch[1];
	float	small;
	float	big;
	float	tmp;

	tmp = needs;
	if (item.pack_size[0] == 0)
	{		
		while ((tmp > 0 && tmp >= item.pack_size[1]) && tmp != 0)
			tmp = tmp - item.pack_size[1];
		if (tmp == 0)
			return (needs);
		if (tmp > 0)
		{
			small = needs - tmp;
			big = needs + (item.pack_size[1] - tmp);
		}
		else if (tmp < 0)
		{
			small = needs + tmp;
			big = needs + (item.pack_size[1] + tmp);
		}
	}
	else if (item.pack_size[0] > 0.0f)
	{
		while (tmp > 0 && tmp != 0)
			tmp = tmp - item.pack_size[0];
		if (tmp == 0)
			return (needs);

		tmp = needs;
		while (tmp > 0 && tmp != 0)
			tmp = tmp - item.pack_size[1];
		if (tmp == 0)
			return (needs);

		tmp = needs;
		small = item.pack_size[0];
		while (tmp > small)
		{
			tmp = tmp - small;
		}
		small = tmp;
		tmp = needs;
		small = tmp - small;
		big = small + item.pack_size[0];
	}
	printf("Your amount can't be bought. Please choose from these 2 options:\n[A]: %.2f\t[B]: %.2f\n", small, big);
	while (!(ch[0] >= 'A' && ch[0] <= 'B') || (ch[0] >= 'a' && ch[0] <= 'b'))
	{
		scanf("%1s", ch);
		if (ch[0] == 'A' || ch[0] == 'a')
			needs = small;
		else if (ch[0] == 'B' || ch[0] == 'b')
			needs = big;
		else
			printf("[%c] is not a valid answer. Please choose from these 2 options:\n[A]: %.2f\t[B]: %.2f\n", ch[0], small, big);
	}
	return (needs);
}

float	get_order(char *name, char *unit, struct Item item)
{
	float 	needs;
	printf("%s [%s]: ", name, unit);
	scanf("%f", &needs);
	needs = check_amounts(needs, item);
	printf("Added %.2f [%s] %s(s) to list.\n", needs, unit, name);
	return (needs);
}

void	print_list(struct Item item1, struct Item item2, struct Item item3, struct Item item4, struct Item item5)
{
	float taxes;
	float total_Brutto;
	float total_Taxes;
	float total_Netto;

	taxes = 0.16;

	item1.sum_brutto = item1.need * item1.price_brutto;
	item1.sum_netto = item1.sum_brutto * (1.00 - taxes);
	item1.sum_taxes = item1.sum_brutto - item1.sum_netto;

	item2.sum_brutto = item2.need * item2.price_brutto;
	item2.sum_netto = item2.sum_brutto * (1.00 - taxes);
	item2.sum_taxes = item2.sum_brutto - item2.sum_netto;
	
	item3.sum_brutto = item3.need * item3.price_brutto;
	item3.sum_netto = item3.sum_brutto * (1.00 - taxes);
	item3.sum_taxes = item3.sum_brutto - item3.sum_netto;

	item4.sum_brutto = item4.need * item4.price_brutto;
	item4.sum_netto = item4.sum_brutto * (1.00 - taxes);
	item4.sum_taxes = item4.sum_brutto - item4.sum_netto;

	item5.sum_brutto = item5.need * item5.price_brutto;
	item5.sum_netto = item5.sum_brutto * (1.00 - taxes);
	item5.sum_taxes = item5.sum_brutto - item5.sum_netto;

	if (item1.need > 0.0)
		printf("%s\t\t%2.0f\t[%s]\t%8.2f\t%8.2f\t%8.2f\n", "Eggs", item1.need, "Pcs", item1.sum_brutto, item1.sum_taxes, item1.sum_netto);
	if (item2.need > 0.0)
		printf("%s\t\t%2.2f\t[%s]\t%8.2f\t%8.2f\t%8.2f\n", "Rice", item2.need, "Kg", item2.sum_brutto, item2.sum_taxes, item2.sum_netto);
	if (item3.need > 0.0)
		printf("%s\t\t%2.2f\t[%s]\t%8.2f\t%8.2f\t%8.2f\n", "Hummus", item3.need, "Kg", item3.sum_brutto, item3.sum_taxes, item3.sum_netto);
	if (item4.need > 0.0)
		printf("%s\t%2.2f\t[%s]\t%8.2f\t%8.2f\t%8.2f\n", "Tortillas", item4.need, "Kg", item4.sum_brutto, item4.sum_taxes, item4.sum_netto);
	if (item5.need > 0.0)
		printf("%s\t\t%2.0f\t[%s]\t%8.2f\t%8.2f\t%8.2f\n", "Beer", item5.need, "Can/s", item5.sum_brutto, item5.sum_taxes, item5.sum_netto);

	total_Brutto = item1.sum_brutto + item2.sum_brutto + item3.sum_brutto + item4.sum_brutto + item5.sum_brutto;
	total_Taxes = item1.sum_taxes + item2.sum_taxes + item3.sum_taxes + item4.sum_taxes + item5.sum_taxes;
	total_Netto = item1.sum_netto + item2.sum_netto + item3.sum_netto + item4.sum_netto + item5.sum_netto;

	printf("\n");
	printf("Total NETTO:\t%.2f€\n", total_Netto);
	printf("Total TAXES:\t%.2f€\n", total_Taxes);
	printf("Total BRUTTO:\t%.2f€\n", total_Brutto);
}

int	main()
{
	struct Item Eggs;
	Eggs.price_brutto = 0.3f;
	Eggs.pack_size[0] = 6.0f;
	Eggs.pack_size[1] = 10.0f;
	struct Item Rice;
	Rice.price_brutto = 1.93f;
	Rice.pack_size[0] = 0.0f;
	Rice.pack_size[1] = 1.0f;
	struct Item Hummus;
	Hummus.price_brutto = 4.98f;
	Hummus.pack_size[0] = 0.0f;
	Hummus.pack_size[1] = 0.25f;
	struct Item Tortillas;
	Tortillas.price_brutto = 6.41f;
	Tortillas.pack_size[0] = 0.0f;
	Tortillas.pack_size[1] = 0.32f;
	struct Item Beer;
	Beer.price_brutto = 0.9f;
	Beer.pack_size[0] = 0.0f;
	Beer.pack_size[1] = 1.0f;
	printf("Your weekly groceries need to be bought.\nPlease enter how much of each item you need.\n");
	Eggs.need = get_order("Eggs", "Pcs", Eggs);
	Rice.need = get_order("Rice", "Kg", Rice);
	Hummus.need = get_order("Hummus", "Kg", Hummus);
	Tortillas.need = get_order("Tortillas", "Kg", Tortillas);
	Beer.need = get_order("Beer", "Can(s)", Beer);
	printf("-------------------------------------------------------------------------------\n");
	printf("Product\t\tNeed\tUnit\tSum Brutto\tSum Taxes\tSum Netto\n");
	printf("-------------------------------------------------------------------------------\n");
	print_list(Eggs, Rice, Hummus, Tortillas, Beer);
	printf("-------------------------------------------------------------------------------\n");
	return (0);
}
