#include "q_equation_solver.h"
#include <math.h>
#include <stdio.h>
#define ABS(x) (x < 0 ? -x : x)

typedef struct {
	char count;
	double x1;
	double x2;
}roots_t;

//HELPFUL FUNCTIONS
static double FindDiscriminant(quadraticEquation_t equation) {
	return (equation.b * equation.b - 4 * equation.a * equation.c);
}
static roots_t FindRoots(quadraticEquation_t equation) {
	double D = FindDiscriminant(equation);
	roots_t roots = { 0,0,0 };

	//special and linear cases
	if (equation.a == 0.0) {
		if (equation.b == 0.0 && equation.c == 0.0)
			return roots;
		else  if (equation.b == 0.0)
			return roots;
		else {
			roots.count = 1;
			roots.x1 = (-equation.c / equation.b);
			return roots;
		}
	}

	//general case
	if (D > 0) {
		roots.count = 2;
		roots.x1 = (((-1.0) * equation.b + sqrt(D)) / (2.0 * equation.a));
		roots.x2 = (((-1.0) * equation.b - sqrt(D)) / (2.0 * equation.a));
		if (roots.x1 > roots.x2) {
			double temp = roots.x2;
			roots.x2 = roots.x1;
			roots.x1 = temp;
		}
		return roots;
	}
	else if (D == 0) {
		roots.count = 1;
		roots.x1 = (((-1.0) * equation.b) / (2.0 * equation.a));
		return roots;
	}
	else
		return roots;
}
static void PrettyPrintEquation(quadraticEquation_t equation) {
	printf("Equation: ");
	if (equation.a != 0) {
		if (equation.a == 1)
			printf("x^2 ");
		else if (equation.a == -1)
			printf("-x^2 ");
		else
			printf("%gx^2 ", equation.a);
		if (equation.b > 0)
			printf("+ ");
		else if (equation.b < 0)
			printf("- ");
	}

	if (equation.b != 0) {
		if (equation.b == 1 || equation.b == -1) {
			if (equation.b == -1 && equation.a == 0)
				printf("-");
			printf("x ");
		}
		else {
			if (equation.a == 0)
				printf("%gx ", equation.b);
			else
				printf("%gx ", ABS(equation.b));
		}
	}

	if (equation.c >= 0) {
		if (equation.a != 0 || equation.b != 0) {
			if (equation.c == 0) 
				printf("= 0\n");
			else 
				printf("+ %g = 0\n", equation.c);
		}
		else 
			printf("%g = 0\n", equation.c);
	}
	else
		printf("- %g = 0\n", ABS(equation.c));
}

//GENERAL FUNCTIONS
int PrintSolution(quadraticEquation_t equation) {
	roots_t roots = FindRoots(equation);

	PrettyPrintEquation(equation);

	if (roots.count == 2)
		printf("Roots: x1 = %g; x2 = %g\n", roots.x1, roots.x2);
	else if (roots.count == 1)
		printf("Root: x = %g\n", roots.x1);
	else
		printf("This equation has no roots\n");
	
	return (int)roots.count;
}
