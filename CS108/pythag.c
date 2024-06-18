#include <stdio.h>
/* This is defining the 3 additional functions in this program that will
calculate the values of the Pythagorean triple. */
void calc_side1(void);
void calc_side2(void);
void hypotenuse(void);

/* This is defining the global variables that will be passed between the
functions.*/
int side1, side2, hyp, m, n;

int main(void)
{
/* The following defines the local variables. */
int num1, num2;

/* This prompts the user for the 2 values that go into the pythagorean theorem,
and assigns them to the appropiate variables. */
printf("Please enter two integers to find out the Pythagorean triple it");
printf(" belongs to.\n");
scanf("%d %d", &num1, &num2);

//This makes sure that the integer m is greater than the integer n.
if(num1 > num2){
	m=num1, n=num2;
	}

else {
	m=num2, n=num1;
	}

/*This is calling each of the functions in order to figure out the triplet.*/
calc_side1();
calc_side2();
hypotenuse();

return 0;

}

/* Each of the functions below are using the varables m and n in order to
calculate the appropiate side of the triangle. */

void calc_side1(void){
	side1=(m*m)-(n*n);
	printf("The first side of the triangle is %d\n", side1);
	}

void calc_side2(void){
	side2=2*m*n;
	printf("The second side to the triangle is %d\n", side2);
	}

void hypotenuse(void){
	hyp=(m*m)+(n*n);
	printf("The hypotenuse of the triangle is %d\n", hyp);
	}
