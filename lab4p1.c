#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<assert.h>


/*
Author: John Cody
 Date created: 02/14/2018
 Program Description: This program tests the Pi_value function using the assert function. 
Correct operation results in no output and the program ending. 
*/

double Pi_value(int numaccuracy);
double sin_approx(double x_deg);
double sind(double x_deg);

int main(void) {

	const double pi = 3.141592653589793238462643383;

	assert(fabs(Pi_value(1) - pi) < pow(10.0, -1));
	assert(fabs(Pi_value(2) - pi) < pow(10.0, -2));
	assert(fabs(Pi_value(3) - pi) < pow(10.0, -3));     // Part #1
	assert(fabs(Pi_value(4) - pi) < pow(10.0, -4));
	assert(fabs(Pi_value(5) - pi) < pow(10.0, -5));
	assert(fabs(Pi_value(6) - pi) < pow(10.0, -6));


	int x = 0;                                            // Part #2 - Beginning
	int upperBound = -360, lowerBound = 360;
	double y1 = 0.0, y2 = 0.0;
	double error = 0.0;

	for (x = -360; x < 361; x++) {
		y1 = sin_approx(x);
		y2 = sind(x);
		error = abs(y1 - y2);

		if (error < 0.0022) {
			if (x < lowerBound) {
				lowerBound = x; }
			if (x > upperBound) {
				upperBound = x; }
		}
	}

	printf("The sin_approx funtion is a valid apprximation from %d to %d.\n", lowerBound, upperBound);  // Part #2 - End

	
	double volume = 0.0, height = 0.0;                           // Part #3 - Beginnning
	double radius = 0.0, slength = 0.0;
	char var = 'y';

	while (var == 'y') {
		printf("\nEnter the volume of the cone : ");
		scanf(" %lf", &volume);

		printf("\nEnter the height of the cone : ");
		scanf(" %lf", &height);

		if (height == 0.0 || volume == 0.0) {
			printf("\nNo such cone exists");
		}
		else {
			radius = pow((3 * volume) / (Pi_value(10)*height), 0.5);
			slength = pow(radius*radius + height*height, 0.5);
			printf("The radius and side length of the cone are r = %.3lf, l = %.3lf", radius, slength);
		}

		var = 'm';
		while (var != 'y' && var != 'n') {
			printf("\nDo you want to continue (y / n)");
			scanf(" %c", &var);
		}

	}                                                         // Part #3 - End

	return 0;    // Fin
}

double Pi_value(int numaccuracy) {
	const double pi = 3.141592653589793238462643383;
	double pi2 = 3.0;
	int j = 2;

	while (fabs(pi2 - pi) > pow(10.0, -numaccuracy*1.0)) {
		if (j % 4 > 0) {
			pi2 = pi2 + 4.0 / (j * (j + 1) * (j + 2) * 1.0); }
		else {
			pi2 = pi2 - (4.0 / (j * (j + 1) * (j + 2) * 1.0)); }
		j += 2;
	}
	return pi2;
}

double sin_approx(double x_deg) {
	double sinVal = 0.0;
	sinVal = (4 * x_deg*(180 - x_deg)) / (40500 - x_deg*(180 - x_deg));
	return sinVal;
}

double sind(double x_deg) {
	double pi, y;
	pi = Pi_value(10);
	y = sin(x_deg * pi / 180.);
	return(y);
}