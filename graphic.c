#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <stdlib.h>

typedef struct arr_col_1{
	int x;
};

typedef struct arr_col_2{
	int x, y;
};

typedef struct array{
	int x1, y1;
};

void col_1(FILE *file, int row);
void col_2(FILE *file, int row);

void choice_1(struct arr_col_1 arr[], int row);
void choice_2(struct arr_col_2 arr[], int row);

void draw_bar_graph_col_1(struct arr_col_1 arr[], int row);
void draw_bar_graph_col_2(struct arr_col_2 arr[], int row);
/*
void draw_line_graph_col_1(struct arr_col_1 arr[], int row);
void draw_line_graph_col_2(struct arr_col_2 arr[], int row);

void draw_bar_with_line_graph_col_1(struct arr_col_1 arr[], int row);
void draw_bar_with_line_graph_col_2(struct arr_col_2 arr[], int row);
*/
int draw_x_y_axis_col_1(int arr1[], int row);
int draw_x_y_axis_col_2(int arr1[], int arr2[], int row);

int main(){
	FILE* file;
	int row = 0, col = 1, i;
	char fname[40], chr;
	int gd = DETECT, gm;

	initgraph(&gd, &gm, "C:\\TurboC3\\BGI");
	do{
		printf("\nEnter the file which you want to vizualize = ");
		scanf("%s", &fname);
		file = fopen(fname, "r");

		if(file == NULL){
			printf("\nPlease Enter correct file name ");
		}
	}while(file == NULL);

	chr = getc(file);

	while(chr != EOF){
		if(chr == '\n'){
			row++;
		}
		if((row == 0)&&(chr == ',')){
			col++;
		}
		chr = getc(file);
	}
	printf("%d row  %d col", row, col);
	if(col == 1){
	       col_1(file, row);
	}
	if(col == 2){
	       col_2(file, row);
	}
	getch();
	return 0;
}


void col_1(FILE *file, int row){
	struct arr_col_1 *arr1;
	int i;
	rewind(file);
	arr1 = (struct arr_col_1*)malloc(row * sizeof(struct arr_col_1));

	for(i = 0; i < row; i++){
		fscanf(file, "%d", &arr1[i].x);
		printf("\n%d\n", arr1[i].x);
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
		printf("\n%d %d\n", arr2[i].x, arr2[i].y);
	}
	getch();
	choice_2(arr2, row);
}

void choice_1(struct arr_col_1 arr1[], int row){
	int choice;
	do{
		clrscr();
		printf("\n1>Bar Graph \n2>Line Graph \n3>Bar with line Graph \n4>Exit \nEnter your choice = ");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				draw_bar_graph_col_1(arr1, row);
				break;
		   /*   	case 2:
				draw_line_graph_col_1(arr1, row);
				break;
			case 3:
				draw_bar_with_line_col_1(arr1, row);
				break;
		   */
			case 4:
				printf("Exitting.....");
				exit(0);
			default:
				printf("Please Enter Correct coice...");
				break;
		}
	}while(choice != 4);

}

void choice_2(struct arr_col_2 arr2[], int row){
	int choice;
	do{
		clrscr();
		printf("\n1>Bar Graph \n2>Line Graph \n3>Bar with line Graph \n4>Exit \nEnter your choice = ");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				draw_bar_graph_col_2(arr2, row);
				break;
		/*	case 2:
				draw_line_graph_col_2(arr2, row);
				break;
			case 3:
				draw_bar_with_line_col_2(arr2, row);
				break;
		*/	case 4:
				printf("Exitting.....");
				exit(0);
			default:
				printf("Please Enter Correct coice...");
				break;
		}
	}while(choice != 4);

}

int draw_x_y_axis_col_1(int arr1[], int row){
	int i = 0;
	int max = arr1[i];
	int x1 = 100, y1 = 100, x2, y2;
	for(i = 1; i < row; i++){
		if(arr1[i] > max){
			max = arr1[i];
		}
	}
	if(max > 2500){
		for(i = 0; i < row; i++){
			arr1[i] /= 100;
		}
		max /= 100;
	}
	if(max > 250){
		for(i = 0; i < row; i++){
			arr1[i] /= 10;
		}
	       max /= 10;
	}


	x2 = x1;
	y2 = y1 + 100 + max;

	setcolor(BLACK);
	line(x1, y1, x2, y2);
	line(x1, y2, x2*9, y2);
	return y2;

}

int draw_x_y_axis_col_2(int arr1[], int arr2[], int row){

	int i = 0;
	int max1 = arr1[i];
	int max2 = arr2[i];

	int x1 = 100, y1 = 100, x2, y2;

	for(i = 1; i < row; i++){
		if(arr1[i] > max1){
			max1 = arr1[i];
		}
		if(arr2[i] > max2){
			max2 = arr2[i];
		}
	}
	if(max2 > 2500){
		for(i = 0; i < row; i++){
			arr2[i] /= 100;
		}
		max2 /= 100;
	}
	if(max2 > 250){
		for(i = 0; i < row; i++);
			arr2[i] /= 10;
		max2 /= 10;
	}


	x2 = x1;
	y2 = y1 + 100 + max2;
	printf("%d",y2);
	setcolor(BLACK);
	line(x1, y1, x2, y2);
	line(x1, y2, x2*6, y2);
	return y2;
}


void draw_bar_graph_col_1(struct arr_col_1 arr[], int row){

	int *arr_copy = (int*)malloc(row * sizeof(int));

	int i, count = 0;
	int left = 110, right, top, bottom;

	for(i = 0; i < row; i++){
		arr_copy[i] = arr[i].x;
	}

	bottom = draw_x_y_axis_col_1(arr_copy, row);
	if(row >= 20){
		for(i = 0; i < row; i++){
			left += count;
			right = left + 10;
			top = bottom - arr_copy[i];
			setfillstyle(SOLID_FILL, BLUE);
			bar(left, top, right, bottom);
			delay(100);
			count = 20;
		}
	}else{
		for(i = 0; i < row; i++){
			left += count;
			right = left + 20;
			top = bottom - arr_copy[i];
			setfillstyle(SOLID_FILL, BLUE);
			bar(left, top, right, bottom);
			delay(100);
			count = 30;
		}
	}
	getch();
	cleardevice();
}

void draw_bar_graph_col_2(struct arr_col_2 arr[], int row){
	int *arr_copy_1 = (int*)malloc(row * sizeof(int));
	int *arr_copy_2 = (int*)malloc(row * sizeof(int));
	int i;

	for(i = 0; i < row; i++){
		arr_copy_1[i] = arr[i].x;
		arr_copy_2[i] = arr[i].y;
	}
	draw_x_y_axis_col_2(arr_copy_1, arr_copy_2, row);
}
