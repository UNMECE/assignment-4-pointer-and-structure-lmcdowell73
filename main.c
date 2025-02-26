#include <stdio.h>
#include "item.h"
#include <stdlib.h>
#include <string.h>


void add_item(Item *item_list, double price, char *sku, char *category, char *name,int index){
    item_list[index].price = price;

    item_list[index].sku = (char *)malloc(strlen(sku) + 1);
    item_list[index].category = (char *)malloc(strlen(category) + 1);
    item_list[index].name = (char *)malloc(strlen(name) + 1);

    strcpy(item_list[index].sku,sku);
    strcpy(item_list[index].category,category);
    strcpy(item_list[index].name,name);
	
}

void free_items(Item *item_list,int size)
{
int i;
for(i=0;i<size;i++){
	free(item_list[i].sku);
	free(item_list[i].category);
	free(item_list[i].name);
	}
free(item_list);


}





double average_price(Item *item_list, int size)
{
double total=0;
int i;
for(i =0;i<size;i++){
	total += item_list[i].price;
}
return total/size;


}

void print_items(Item *item_list,int size)
{
 int i;
 for(i =0; i < size;i++){
	
	printf("------------------------\n");
	printf("item name: %s\n",item_list[i].name);	
	printf("item sku: %s\n",item_list[i].sku);
	printf("item name: %s\n",item_list[i].category);
	printf("item name: %.2f\n",item_list[i].price);
	printf("------------------------\n");
 }
}



int main(int argc,char *argv[])
{
if(argc != 2){
	printf("Usage:%s<size>",argv[0]);
	return EXIT_FAILURE;	
}

int findSKU = atoi(argv[1]);


int size = 5;
Item *item_list = (Item*)malloc(sizeof(Item)*size);

add_item(item_list, 1.99, "11223", "Dairy", "Cheese", 0);
add_item(item_list, 5.60, "34455", "Meat", "Ground Beef", 1);
add_item(item_list, 7.39, "66778", "Meat", "Chicken Breast", 2);
add_item(item_list, 4.45, "89910", "Bakery", "Bagels", 3);
add_item(item_list, 8.83, "12345", "Bakery", "Bread", 4);

print_items(item_list,size);

printf("Average price of items = %d\n", average_price(item_list,size));

int ct = 0;
while(ct < size && strcmp(item_list[ct].sku,argv[1]) != 0) 
{
ct++;
}

if(ct<size){
	
	printf("------------------------\n");
	printf("item name: %s\n",item_list[ct].name);	
	printf("item sku: %s\n",item_list[ct].sku);
	printf("item name: %s\n",item_list[ct].category);
	printf("item name: %.2f\n",item_list[ct].price);
	printf("------------------------\n");
}else
{
printf("item not found\n");
}

return 0;	
}



