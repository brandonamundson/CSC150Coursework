#define MAX 1
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
/*using namespace std;*/

/*const int MAX = 2;*/

void get_part_info(int *part_num, int *num_oh, float *price_part, int *min_oh);
void num_to_order(int *num_oh, int *min_oh, float *num_per_order);
void place_order(int * part_num, float *price_part, float *num_per_order);

int main()
{
	int part_num[MAX];
	int num_oh[MAX];
	float price_part[MAX];
	int min_oh[MAX];
	float num_per_order[MAX];

	get_part_info(part_num, num_oh, price_part, min_oh);
	num_to_order(num_oh, min_oh, num_per_order);
	place_order(part_num, price_part, num_per_order);

	return (0);	
}

/*prompts user to input part #, OH count, cost, & min_num_OH*/
void get_part_info(int *part_num, int *num_oh, float *price_part, int *min_oh)
{
	int i;
	
	for(i = 0; i < MAX; i++)
	{
		printf("Part number: ");
		scanf("%d", &part_num[i]);

		printf("Cost: ");
		scanf("%f", &price_part[i]);

		printf("Quantity On Hand: ");
		scanf("%d", &num_oh[i]);

		printf("Minimum Stock Level: ");
		scanf("%d", &min_oh[i]);
		printf("\n");
	}

}

/*using num_OH, & min_num_OH determine # to order that will result in min +10%
round up w/ ceil()*/
void num_to_order(int *num_oh, int *min_oh, float *num_per_order)
{
	int i;

	for(i = 0; i < MAX; i++)
	{
		num_per_order[i] = (min_oh[i] * .1);
		num_per_order[i] = (min_oh[i] + ceilf(num_per_order[i]));
	}
}

/*given part inventory arrays, DISPLAY items that must be ordered (part#,
partcost, quantity_to_order, order_cost) & total order cost for entire order*/
void place_order(int * part_num, float *price_part, float *num_per_order)
{
	float order_cost[MAX];
	float total_cost = 0;
	int i;

	printf("Parts To Order \n");
	printf("Part             Cost                    Number                  Total \n");

	/*while(num_per_order >= 0)
	{*/
		for(i = 0; i < MAX; i++)
		{
		order_cost[i] = (price_part[i] * num_per_order[i]);
		printf("%d       %f       %f       %f \n", part_num[i], price_part[i], num_per_order[i], order_cost[i]);
		total_cost += order_cost[i];
		}
	/*}*/
	printf("\n Total order Cost: %f \n", total_cost);
}