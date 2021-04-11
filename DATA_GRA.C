#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <stdlib.h>
#include "data.h"

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
	}while(file  == NULL);

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
