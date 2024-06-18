/* The purpose of this program is to determine the Pythagorean triple
 based on two integers entered by the user. The integers entered correspond
 to the variables m and n. These variables are then passed into 3 different
 functions that will calculate the sides to the triangle. Each side's result
 is passed back to main, and then the user is then shown the triple based off
 the integers they entered. */

/* Input Parameters: Integers

 Dictionary of local variables in main:
 num1 ~ this corresponds to the first integer entered by the user.
 num2 ~ this corresponds to the second integer entered by the user.
 m ~ this is assigned the greater of the two integers entered by the user.
 n ~ this is assigned the lesser of the two integers entered by the user.
 side1 ~ an integer result from the calc_side1 function.
 side2 ~ an integer result from the calc_side2 function.
 hyp ~ an integer result from the hypotenuse function.

 Input:
 Two user defined integers.

 Process:
 The two user defined integers are assigned to the appropriate variables.
 The value of m and n are printed out to the user after the if else
 statement. In main, 3 functions are called: calc_side1, calc_side2, and
 hyp. They are passed the values of m and n. The function then computes the
 value and returns it to main. It then prints out the value after each
 function is called.

 Output:
 m and n ~ user defined integers values placed in descending order by an
	if else statement
 side1, side2, and hyp ~ integer values that are computed by the appropriate
	function.

 "scope.c" by R. Mullick was referenced for the organization and structure
 of documentation.

 Written by Betsy Kamas for GHP#3. */

#include <stdio.h>

int main(void)
{

/* Function prototype definitions for calculating the triangle triplet. */
int calc_side1(int, int);
int calc_side2(int, int);
int hypotenuse(int, int);

/* Local variables. */
int num1, num2, m, n, side1, side2, hyp;

/* Prompting user for 2 values, assigning them to temporary variables,
 and then displaying them back. */
printf("Please enter two integers to find out the Pythagorean triple it");
printf(" belongs to.\n");
scanf("%d %d", &num1, &num2);
printf("\nThe numbers entered were %d & %d.\n", num1, num2);

/* Verifying integer m is greater than the integer n. */
if(num1 > num2){
	m=num1, n=num2;
	}

else {
	m=num2, n=num1;
	}
/* This is telling the user which values became associated with each
 variable.*/
printf("This makes m=%d and n=%d.\n", m, n);

/* This is calling each of the functions in order to figure out the
 triplet. Each function is being passed the values of m and n. It is also
 displaying to the user the value of the appropriate side to the Pythagorean
 triple based on the calculation preformed by the function. */

side1=calc_side1(m,n);
printf("The first side of the triple is %d.\n", side1);

side2=calc_side2(m,n);
printf("The second side of the triple is %d.\n", side2);

hyp=hypotenuse(m,n);
printf("The hypotenuse of the triple is %d.\n", hyp);

return 0;

}

/* Each of the functions below are using the variables m and n as input
 in order to calculate the appropriate side of the triangle. In each
 function 'a' corresponds to 'm' and 'b' corresponds to 'n'. They all return an
 integer back to main which corresponds to a side of the Pythagorean
 triple. */

/* Input Parameters: integers

 Dictionary of Variables:
 a ~ corresponds to m argument in the call from main
 b ~ corresponds to n argument in the call from main
 s1 ~ an integer result calculated within the function and passed back to main

 Input:
 a and b are passed the vales of m and n from main

 Process:
 A simple calculation is done to determine one part of the triple.

 Output:
 s1 ~ calculated value of first part of the triple and returned to main and
	assigned to side1

 Written by Betsy Kamas for GHP#3 */

int calc_side1(int a, int b){
	int s1;
	s1=(a*a)-(b*b);
	return s1;
	}

/* Input Parameters: integers

 Dictionary of Variables:
 a ~ corresponds to m argument in the call from main
 b ~ corresponds to n argument in the call from main
 s2 ~ an integer result calculated within the function and passed back to main

 Input:
 a and b are passed the vales of m and n from main

 Process:
 A simple calculation is done to determine one part of the triple.

 Output:
 s2 ~ calculated value of second part of the triple and returned to main and
	assigned to side2

 Written by Betsy Kamas for GHP#3 */

int calc_side2(int a, int b){
	int s2;
	s2=2*a*b;
	return s2;
	}

/* Input Parameters: integers

 Dictionary of Variables:
 a ~ corresponds to m argument in the call from main
 b ~ corresponds to n argument in the call from main
 h ~ an integer result calculated within the function and passed back to main

 Input:
 a and b are passed the vales of m and n from main

 Process:
 A simple calculation is done to determine one part of the triple.

 Output:
 h ~ calculated value of final part of the triple which is passed back to main
	and assigned to hyp.

 Written by Betsy Kamas for GHP#3 */

int hypotenuse(int a, int b){
	int h;
	h=(a*a)+(b*b);
	return h;
	}
