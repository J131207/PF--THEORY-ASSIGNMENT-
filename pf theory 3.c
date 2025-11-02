#include <stdio.h>
#include <stdbool.h>

void updateSectorStatus(int grid[][3]){
	int row, col, flagnumber, toggle;
	printf("\nEnter coordinates of sector: ");
	scanf("%d %d", &row, &col);
	
	printf("\n1. Power Status (1 = ON, 0 = OFF) \n2. Overload Warning (1 = Overloaded, 0 = Normal) \n3. Maintenance Required (1 = Yes, 0 = No) \nChoose Flag :");
	scanf("%d", &flagnumber);
	
	printf("\nEnter 1 to SET or 0 to CLEAR: ");
	scanf("%d", &toggle);
	
	int bitPos = flagnumber - 1;
	
	if(toggle == 1){
		grid[row][col] |= (1 << bitPos); 
	}
	else{
		grid[row][col] &= ~(1 << bitPos);
	}
	
	printf("\nUpdated value at (%d, %d): %d\n", row, col, grid[row][col]);	
}

void querySectorStatus(int grid[][3]){
	int row,col,k;
	bool flag1 = false, flag2 = false, flag3 = false;
	
	printf("\nEnter coordinates of sector: ");
	scanf("%d %d", &row, &col);
	
	for(k=3; k>=0; k--){
		int bit = (grid[row][col] >> k) & 1;
		if(k == 0 && bit == 1) flag1 = true;
		else if(k == 1 && bit == 1) flag2 = true;
		else if(k == 2 && bit == 1) flag3 = true;
	}
	
	flag1 ? printf("Power Status : ON") : printf("\nPower Status : OFF");
	flag2 ? printf("\nOverloaded Status : Overloaded") : printf("\nOverloaded Status : Normal");
	flag3 ? printf("\nMaintenance Required : YES\n") : printf("\nMaintenance Required : NO\n");
}

void runSystemDiagnostic(int grid[][3]){
	int i,j,k, overloadedSectors = 0, maintenance = 0;
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			for(k=3; k>=0; k--){
				int bit = (grid[i][j] >> k) & 1;
				if(k == 1 && bit == 1){
					overloadedSectors++;
				}
				if(k == 2 && bit == 1){
					maintenance++;
				}
			}
		}
	}
	printf("\n%d Sectors are currently overloaded", overloadedSectors);
	printf("\n%d Sectors require maintenance\n", maintenance);
}

void main(){
	int grid[3][3] = {{1,2,3}, {3,4,8}, {9,1,7}};
	
	int i,j,k;
	
	printf("Sector's Grid: \n");
	
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			printf("%d  ", grid[i][j]);
		}
		printf("\n");
	}
	
	printf("\n1. Update Sector Status \n2. Query Sector Status \n3. Run System Diagnostic \n4. Exit\n");
	int choice;
	
	do{
		printf("\nEnter your choice: ");
		scanf("%d", &choice);
		
		switch(choice){
			case 1:
				updateSectorStatus(grid);
				break;
			case 2:
				querySectorStatus(grid);
				break;
			case 3:
				runSystemDiagnostic(grid);
				break;
			case 4:
				printf("\nExiting!");
				break;
			default:
				printf("\nInvalid Choice!");
		}
	}while(choice != 4);
}
