#ifndef __QUADRATIC_EQUATION__
#define __QUADRATIC_EQUATION__

/**
 Three numbers (a,b,c) that define a quadratic equation of the form ax^2 + bx + c = 0 
 */
typedef struct {
	double a;
	double b;
	double c;
}quadraticEquation_t;

/**
 * Writes original equation and its solution(s)
 * @param equation - structure of the quadraticEquation_t
 * @return count of roots
 */
int PrintSolution(quadraticEquation_t equation);

#endif // !__QUADRATIC_EQUATION__

