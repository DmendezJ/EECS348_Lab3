/*
 * Program2.c
 *
 *  Created on: Feb 18, 2023
 *      Author: Damian Mendez
 */
#include <stdio.h>
#include <stdlib.h>


int main(){
	while(1){
	printf("Enter 0 or 1 to STOP\n");
	int target;
	printf("Enter target score: ");
	scanf("%d",&target);
	int TD2, TD1, TD, FG, S;
	if (target == 0 || target == 1){
		exit(0);
	}
	for (S = 0; S <= (target/2 + 1); S++){
		for(FG = 0; FG <= (target/3 + 1); FG++){
			for (TD = 0; TD <= (target/6 + 1); TD++){
				for (TD1 = 0; TD1 <= (target/7 + 1); TD1++){
					for (TD2 = 0; TD2 <= (target/8 + 1); TD2++){
						if ((2*S)+(3*FG)+(6*TD)+(7*TD1)+(8*TD2) == target){
							printf("%d TD + 2pt, %d TD + 1pt, %d TD, %d FG, %d Safety\n", TD2, TD1, TD, FG, S);
						}
					}
				}
			}
		}
	}
	}
}
