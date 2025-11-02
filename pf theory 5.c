#include <stdio.h>
#include <string.h>

void encodeMessage(char message[]){
	int length = strlen(message);
	int start = 0;
	int end = length - 1;
	char temp;
	
	while(start < end){
		temp = message[start];
		message[start] = message[end];
		message[end] = temp;
		
		start++;
		end--;
	}
	
	int k = 0;
	while(message[k] != '\0'){
		message[k] ^= 18;                   // ^ is used for toggling bits, and 18 means 2 + 16 because 2nd bit means 2 (2 power 1) and 5th bit means 16 (2 power 4)
		k++;
	}
	
	printf("Encoded String: %s\n", message);
}

void decodeMessage(char message[]){
	int k = 0;
	while(message[k] != 0){
		message[k] ^= 18;
		k++;
	}
	
	int length = strlen(message);
	int start = 0;
	int end = length - 1;
	char temp;
	
	while(start < end){
		temp = message[start];
		message[start] = message[end];
		message[end] = temp;
		
		start++;
		end--;
	}
	
	printf("Decoded String: %s\n", message);
}

void main(){
	int choice;
	char message[100];
	
	printf("1. Encode Message \n2. Decode Message \n3. Exit");
	do{
		printf("\nEnter your choice: ");
		scanf("%d", &choice);
		
		while (getchar() != '\n');
		
		switch(choice){
			case 1:
				printf("\nEnter your message: ");
				gets(message);
				encodeMessage(message);
				break;
			case 2:
				printf("\nEnter your message: ");
				gets(message);
				decodeMessage(message);
				break;
			case 3:
				printf("\nExiting!");
				break;
			default:
				printf("\nInvalid Choice!");
		}
		
	}while(choice != 3);
}
