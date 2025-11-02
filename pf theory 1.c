#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void addNewBook(int isbns[], char titles[][50], float prices[], int quantities[], int *count){
	int isbn, quantity;
	char title[50];
	float price;
	
	printf("Enter ISBN: ");
	scanf("%d", &isbn);
	
	int i;
	bool flag = false;
	for(i=0; i<(*count); i++){
		if(isbns[i] == isbn){
			flag = true;
		}
	}
	
	if(flag) printf("Duplicate ISBN!");
	else{
		printf("Enter Title: ");
		fgets(title, 50, stdin);
		while (getchar() != '\n');
		printf("Enter Price: ");
		scanf("%f", &price);
		printf("Enter Quantity: ");
		scanf("%d", &quantity);
		
		isbns[*count] = isbn;
		strcpy(titles[*count], title);
		prices[*count] = price;
		quantities[*count] = quantity;
		(*count)++;
    	printf("Book Added Successfully");
    }
}

void processSale(int isbns[], int quantities[], int *count){
	int isbn;
	printf("Enter ISBN: ");
	scanf("%d", &isbn);
	
	int i, index;
	bool flag = false;
	for(i=0; i<(*count); i++){
		if(isbns[i] == isbn){
			flag = true;
			index = i;
		}
	}
	
	if(flag){
		int quantity;
		printf("Enter Number of Books Sold: ");
		scanf("%d", &quantity);
		if(quantities[index] > quantity){
			quantities[index] -= quantity;
			printf("Quantity Updated!");
		}
		else printf("Out of Stock");
	}
	else printf("Book Not Found!");
}

void generateLowStockReport(int isbns[], char titles[][50], float prices[], int quantities[], int *count){
	int i;
	bool flag = false;
	
	printf("Low Stock Report");
	for(i=0; i<(*count); i++){
		if(quantities[i] < 5){
			printf("\nISBN: %d, Title: %s, Price: %.2f, Quantity: %d", isbns[i], titles[i], prices[i], quantities[i]);
			flag = true;
		}
	}
	
	if(!flag) printf("All Books have sufficient stock!");
}

void main(){
	int isbns[100] = {12345, 67890};
	char titles[100][50] = {"C Programming", "Data Structures"};
	float prices[100] = {850.0, 950.0};
	int quantities[100] = {12, 3};
	int choice;
	int *count = 2; //sizeof(isbns)/sizeof(isbns[0]);
	
	printf("Liberty Books Main Menu");
	printf("\n1. Add New Book \n2. Process a Sale \n3. Generate Low-Stock Report \n4. Exit");
	
	do{
		printf("\n\nEnter your choice: ");
		scanf("%d", &choice);
		
		switch(choice){
			case 1:
				addNewBook(isbns, titles, prices, quantities, &count);
				break;
			case 2:
				processSale(isbns, quantities, &count);
				break;
			case 3:
				generateLowStockReport(isbns, titles, prices, quantities, &count);
				break;
			case 4:
				printf("\nExiting!");
				break;
			default:
				printf("\nInvalid Choice");
		}
	}while(choice != 4);
}
