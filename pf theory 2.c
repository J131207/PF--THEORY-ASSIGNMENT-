#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 5
#define MAX_CART 10

char customerName[50], customerCNIC[16];

char productNames[MAX_ITEMS][20] = {"Rice", "Oil", "Sugar", "Flour", "Tea"};
int productPrices[MAX_ITEMS] = {200, 500, 150, 180, 350};
int productStock[MAX_ITEMS] = {10, 8, 12, 15, 7};

int cartIndex[MAX_CART];
int cartQty[MAX_CART];
int cartCount = 0;

void customerInfo(){
	printf("Enter your name: ");
	gets(customerName);
	
	printf("Enter your cnic in format XXXXX-XXXXXXX-X: ");
	gets(customerCNIC);
}

void displayInventory(){
	printf("\nInventory\n");
	printf("No.\tName\t\tPrice\tStock\n");
	int i;
	for(i=0; i<MAX_ITEMS; i++){
		printf("%d\t%-10s\t%d\t%d\n", i + 1, productNames[i], productPrices[i], productStock[i]);
	}
}

void updateInventory(int id, int qty){
	productStock[id] -= qty;
}

void addItemToCart(){
	int id, qty;
    displayInventory();
    printf("\nEnter product ID to add to cart: ");
    scanf("%d", &id);
    id--;

    if(id < 0 || id >= MAX_ITEMS) {
        printf("Invalid product ID!\n");
        return;
    }

    printf("Enter quantity: ");
    scanf("%d", &qty);

    if(qty > productStock[id]) {
        printf("Not enough stock available!\n");
        return;
    }

    cartIndex[cartCount] = id;
    cartQty[cartCount] = qty;
    cartCount++;

    updateInventory(id, qty);
    printf("Item added to cart successfully!\n");
}

void displayBill(){
    float total = 0, discountedTotal = 0;
    char answer[5], promo[20];

    printf("\n CART ITEMS \n");
    printf("Product\t\tQty\tPrice\tSubtotal\n");

	int i;
    for(i = 0; i < cartCount; i++) {
        int id = cartIndex[i];
        float subtotal = productPrices[id] * cartQty[i];
        printf("%-10s\t%d\t%d\t%.2f\n", productNames[id], cartQty[i], productPrices[id], subtotal);
        total += subtotal;
    }

    printf("\nTotal Bill: %.2f\n", total);

    printf("Do you have a promocode? (yes/no): ");
    scanf("%s", answer);

    if(strcmp(answer, "yes") == 0) {
        printf("Enter promocode: ");
        scanf("%s", promo);
        if(strcmp(promo, "Eid2025") == 0) {
            discountedTotal = total * 0.75;
            printf("Promo applied! 25%% discount.\n");
        } else {
            discountedTotal = total;
            printf("Invalid promocode!\n");
        }
    } else {
        discountedTotal = total;
    }

    printf("\nINVOICE \n");
    printf("Customer Name: %s\n", customerName);
    printf("CNIC: %s\n", customerCNIC);
    printf("Product\t\tQty\tPrice\tSubtotal\n");
    for(i = 0; i < cartCount; i++) {
        int id = cartIndex[i];
        float subtotal = productPrices[id] * cartQty[i];
        printf("%-10s\t%d\t%d\t%.2f\n", productNames[id], cartQty[i], productPrices[id], subtotal);
    }

    printf("Total (without discount): %.2f\n", total);
    printf("Final Bill (after discount): %.2f\n", discountedTotal);
}


void main(){
	int choice;
	char name[50], cnic[15];
	
	customerInfo();
	
	printf("\nSupermarket Operations: \n1. Display Inventory \n2. Add Item to Cart \n3. Display Bill and Invoice \n4. Exit\n");
	
	
	do{
		printf("Enter your choice: ");
		scanf("%d", &choice);
		
		switch(choice){
			case 1:
				displayInventory();
				break;
			case 2:
				addItemToCart();
				break;
			case 3:
				displayBill();
				break;
			case 4:
				printf("\nExiting!");
				break;
			default:
				printf("\nInvalid Choice!");
		}
	}while(choice != 4);
}
