#include <graphics.h>

typedef struct arr_col_1{
	int x;
};

typedef struct arr_col_2{
	int x, y;
};

typedef struct array{
	int x1, y1;
};

void draw_bar_graph_col_1(struct arr_col_1 arr[], int row);
void draw_bar_graph_col_2(struct arr_col_2 arr[], int row);
void draw_line_graph_col_1(struct arr_col_1 arr[], int row);
/*
void draw_line_graph_col_2(struct arr_col_2 arr[], int row);

void draw_bar_with_line_graph_col_1(struct arr_col_1 arr[], int row);
void draw_bar_with_line_graph_col_2(struct arr_col_2 arr[], int row);
*/


int draw_x_y_axis_col_1(int arr1[], int row){
	int i = 0;
	int max = arr1[i];
	int x1 = 50, y1 = 100, x2, y2;
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
	line(x1, y2, x2*15, y2);
	return y2;

}

int draw_x_y_axis_col_2(int arr1[], int arr2[], int row){

	int i = 0;
	int max1 = arr1[i];
	int max2 = arr2[i];

	int x1 = 50, y1 = 100, x2, y2;

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
		for(i = 0; i < row; i++){
			arr2[i] /= 10;
		}
		max2 /= 10;
	}


	x2 = x1;
	y2 = y1 + 100 + max2;
	printf("%d",y2);
	setcolor(BLACK);
	line(x1, y1, x2, y2);
	line(x1, y2, x2*15, y2);
	return y2;
}


void draw_bar_graph_col_1(struct arr_col_1 arr[], int row){

	int *arr_copy = (int*)malloc(row * sizeof(int));

	int i, count = 0;
	int left = 60, right, top, bottom;

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

	free(arr_copy);
	cleardevice();
}

void draw_bar_graph_col_2(struct arr_col_2 arr[], int row){
	int *arr_copy_1 = (int*)malloc(row * sizeof(int));
	int *arr_copy_2 = (int*)malloc(row * sizeof(int));
	int i, count = 0;
	int left = 60, top, right, bottom;

	for(i = 0; i < row; i++){
		arr_copy_1[i] = arr[i].x;
		arr_copy_2[i] = arr[i].y;
	}
	bottom  = draw_x_y_axis_col_2(arr_copy_1, arr_copy_2, row);

	if(row >= 20){
		for(i = 0; i < row; i++){
			left += count;
			right = left + 10;
			top = bottom - arr_copy_2[i];
			setfillstyle(SOLID_FILL, BLUE);
			bar(left, top, right, bottom);
			delay(100);
			count = 20;
		}
	}else{
		for(i = 0; i < row; i++){
			left += count;
			right = left + 20;
			top = bottom - arr_copy_2[i];
			setfillstyle(SOLID_FILL, BLUE);
			bar(left, top, right, bottom);
			delay(100);
			count = 30;
		}
	}
	getch();
	free(arr_copy_1);
	free(arr_copy_2);

	cleardevice();
}

void draw_line_graph_col_1(struct arr_col_1 arr[], int row){
	struct array *dta = (struct array*)malloc(row * sizeof(struct array));

	int *arr_copy = (int*)malloc(row * sizeof(int));

	int i, count = 0;
	int left = 60, right, top, bottom;

	for(i = 0; i < row; i++){
		arr_copy[i] = arr[i].x;
	}

	bottom = draw_x_y_axis_col_1(arr_copy, row);
	if(row >= 20){
		for(i = 0; i < row; i++){
			left += count;
			right = left + 10;
			top = bottom - arr_copy[i];
			dta[i].x1 = (left + right)/2;
			dta[i].y1 = top;
			count = 20;
		}

		for(i = 0; i < row -1; i++){
			setlinestyle(SOLID_LINE, 0, 2);
			line(dta[i].x1, dta[i].y1, dta[i+1].x1, dta[i+1].y1);
			delay(100);
		}
	}else{
		for(i = 0; i < row; i++){
			left += count;
			right = left + 20;
			top = bottom - arr_copy[i];
			dta[i].x1 = (left + right)/ 2;
			dta[i].y1 = top;
			count = 30;
		}

		for(i= 0; i < row - 1; i++){
			setlinestyle(SOLID_LINE, 0, 2);
			line(dta[i].x1, dta[i].y1, dta[i+1].x1, dta[i+1].y1);
			delay(100);
		}
	}

	free(arr_copy);
	free(dta);
	getch();
	cleardevice();
}
