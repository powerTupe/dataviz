#include <stdio.h>
#include "DATAV.h"

void choice_1(struct arr_col_1 arr1[], int row);
void choice_2(struct arr_col_2 arr2[], int row);

void col_1(FILE *file, int row){
	struct arr_col_1 *arr1;
	int i;
	rewind(file);
	arr1 = (struct arr_col_1*)malloc(row * sizeof(struct arr_col_1));

	for(i = 0; i < row; i++){
		fscanf(file, "%d", &arr1[i].x);
		printf("\n%d", arr1[i].x);
	}
	getch();
	choice_1(arr1, row);
}

void col_2(FILE *file, int row){
	struct arr_col_2 *arr2;
	int i;
	rewind(file);
	arr2 = (struct arr_col_2*)malloc(row * sizeof(struct arr_col_2));

	for(i = 0; i < row; i++){
		fscanf(file, "%d,%d", &arr2[i].x, &arr2[i].y);
		printf("\n%d %d", arr2[i].x, arr2[i].y);
	}
	getch();
	choice_2(arr2, row);
}


void choice_1(struct arr_col_1 arr1[], int row){
	int choice;
	do{
		clrscr();
		printf("1>Bar Graph  2>Line Graph  3>Bar with line Graph  4>Point with Line  5>Point Graph  6>Draw Curve  7>Pie Graph  8>Exit \nEnter your choice = ");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				draw_bar_graph_col_1(arr1, row);
				break;
			case 2:
				draw_line_graph_col_1(arr1, row);
				break;
			case 3:
				draw_bar_with_line_graph_col_1(arr1, row);
				break;
			case 4:
				draw_point_with_line_graph_col_1(arr1, row);
				break;
			case 5:
				draw_point_graph_col_1(arr1, row);
				break;
			case 6:
				draw_curve_graph_col_1(arr1, row);
				break;
			case 7:
				draw_pie_graph_col_1(arr1, row);
				break;
			case 8:
				printf("Exitting.....");
				exit(0);
			default:
				printf("Please Enter Correct coice...");
				break;
		}
	}while(choice != 8);

}

void choice_2(struct arr_col_2 arr2[], int row){
	int choice;
	do{
		clrscr();
		printf("1>Bar Graph 2>Line Graph 3>Bar with line Graph 4>Point with graph 5>Point graph 6>Curve Graph 7>Pie Graph 8>Exit \nEnter your choice = ");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				draw_bar_graph_col_2(arr2, row);
				break;
			case 2:
				draw_line_graph_col_2(arr2, row);
				break;
			case 3:
				draw_bar_with_line_graph_col_2(arr2, row);
				break;
			case 4:
				draw_point_with_line_graph_col_2(arr2, row);
				break;
			case 5:
				draw_point_graph_col_2(arr2, row);
				break;
			case 6:
				draw_curve_graph_col_2(arr2, row);
				break;
			case 7:
				draw_pie_graph_col_2(arr2, row);
				break;
			case 8:
				printf("Exitting.....");
				exit(0);
			default:
				printf("Please Enter Correct coice...");
				break;
		}
	}while(choice != 8);

}
