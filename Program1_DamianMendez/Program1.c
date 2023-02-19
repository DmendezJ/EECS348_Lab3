/*
 * Program1.c
 *
 *  Created on: Feb 8, 2023
 *      Author: d644m169
 */
#include <stdio.h>
#include <stdlib.h>
int main(){
	FILE *in_file = fopen("MonthlySalesIn.txt", "r");
	FILE *out_file = fopen("MonthlySalesOut.txt", "w");
	if (in_file == NULL || out_file == NULL){
		printf("Error opening file.\n\n");
		return 1;
	}
	char numbers[32][32];//Array for the future numbers
	char *months[12] = {"January","February","March","April","May","June","July","August","September","October","November","December"};

	fprintf(out_file, "Yearly Sales Report\n\n");
	fprintf(out_file, "     Month\tSales\n");

	int line = 0;//for loop goes through the text file and puts the character numbers into numbers array
	while (!feof(in_file) && !ferror(in_file)){
		if (fgets(numbers[line], 100, in_file) != NULL)
			line++;
	}
	fclose(in_file);

	double nums[12];//creates array to house numbers after type casting into double
	for (int i = 0; i < line; i++){ //Line declared earlier has total number of lines in the file
		nums[i] = atof(numbers[i]);
	}

	double total = 0; //total will find the total sales in next loop so we can calculate the average
	int max_index = 0;
	int min_index = 0;//max and min index will be used to track the indexes of the maximum amount of sales and minimum sales
	for (int i = 0; i < line; i++){//will iterate over all 12 months and data points, we will do a few things here
			fprintf(out_file,"%10s\t%8f\n",months[i],nums[i]); //prints out month with corresponding sales
			total = total + nums[i];
			if (nums[max_index] < nums[i]){max_index = i;}
			if (nums[min_index] > nums[i]){min_index = i;}
	}
	double avg = total/12;
	fprintf(out_file,"\nSales summary:\nMinimum sales:\t%8f\t(%s)\nMaximum sales:\t%8f\t(%s)\nAverage sales:\t%8f\n",nums[min_index],months[min_index],nums[max_index],months[max_index],avg);

	fprintf(out_file,"\nSix-Month Moving Average Report:\n");
	for(int i=0;i<=6;i++){
		double sixavg = 0;
		for(int j=0;j<=5;j++){
			sixavg = sixavg + nums[i+j];
		}
		fprintf(out_file,"%10s\t-\t%10s\t%8f\n",months[i],months[i+5],sixavg/6);
	}

	fprintf(out_file, "\nSales Report (Highest to Lowest)\n");
	for (int i = 0;i < 12; i++){
		for(int j = i+1; j < 12; j++){
			if (nums[i] < nums[j]){
				int temp = nums[i];
				char *tempc = months[i];
				nums[i] = nums[j];
				months[i] = months[j];
				nums[j] = temp;
				months[j] = tempc;
			}
		}
	}
	for (int i = 0; i < line; i++){
			fprintf(out_file,"%10s\t%8f\n",months[i],nums[i]);
	}
	fclose(out_file);
}
