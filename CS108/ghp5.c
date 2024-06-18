
#include <stdio.h>
#include <math.h>

/*
	The purpose of this program is to take input from the user and place them into two lists of equal size, which are both less than 20.
	It uses a sentinel value to end input in the first list. The program then places the same sentinel value in the corresponding position in
	the array for the second list. It then takes the values in the arrays, finds the product for the matching array positions, sums the total of
	the products, square roots the summed total, and finally finds the smallest number in array z.

	The program uses arrays, local variables, and a pointer in the call to one of the functions. There are also for and while loops, and if selection
	structures.

	This program was written for GHP#5 by Betsy Kamas, and it was last modified on December 16, 2021.
*/

int main(void)
/*
	Function Prototypes:
		scannums ~ takes an array and a pointer as input and returns nothing
		multiply ~ takes 3 arrays and an integer as input and returns nothing
		snsrt ~ takes an array and an integer as input and returns nothing
		printres ~ takes 3 arrays, an integer, and a pointer as input and returns nothing
		search ~ takes an array and an integer as input and returns nothing

	Dictionary of Variables:
		x[20] ~ A user defined array with up to 20 fillable data spots
		y[20] ~ A user defined array with up to 20 fillable data spots
		z[20] ~ An array which houses the product of the values in corresponding array locations
		n ~ This is the length of all the arrays.
		b ~ This is the running total of all the elements in array z
	Purpose:
		Main is the calling environment for all of the various functions

*/
{

	// Defining Functions //
	void scannums(int[], int *);
	void multiply(int[], int[], int[], int);
	void snsrt(int[], int, int *);
	void printres(int[], int[], int[], int, int*);
	void search(int [], int);

	// Defining Variables //
	int x[20], y[20], z[20];
	int n=0;
	int b=0;

	// Asking for Input //
	printf("\n\nEnter values for the first list\n\n");
	// Calling Function with x //
	scannums(x, &n);

	//Asking for Input//
	printf("\n\nEnter values for the second list\n\n");
	// Calling Function with y //
	scannums(y, &n);

	// Calling Function for Product //
	multiply(x,y,z,n);
	// Calling Function for Sum and Square Root //
	snsrt(z,n, &b);
	// Calling function to print everything out //
	printres(x,y,z,n, &b);
	// Calling function to find the smallest number in array //
	search(z,n);

	return 0;
}

void scannums(int nums[], int *length)
/*
	Dictionary of Variables:
		i ~ a variable that keeps track of the location within the array
		f ~ a variable that is assigned the data input by the user and is then assigned to a position in the array
		nums[] ~ the local name for the array that was used in the call which happens to be either x or y
		*length ~ a pointer that refers to n in main and is the total length for each array after the length of the first list was defined

	Purpose:
		This function takes user input and assigned it to the proper memory location within the array

	This function uses an if/else statement to decide whether it was the fist time the function had been called or not. It also uses a while
	loop to fill the array with data.
*/
{

	// Defining Variables //
	int i=0;
	int f;

	// Testing if it is the first array that decides the length of all arrays //
	// *length was initialized to '0' which is why it works for the first loop and not subsequent //
	if(*length==0)
	{
		// Taking Input and Assigning to f//
		scanf("%d", &f);

		// Looping to see if the sentinel value was encountered //
		while(f!=-555)
		{
			// Assigning f to array position //
			nums[i]=f;
			// Increasing position in array //
			i++;
			printf("Enter another number or -555 to end list\n");
			// Taking Input and Assigning to f //
			scanf("%d", &f);

		}

	}

	// This is for the second list because now we have a set length for the arrays determined by the length of the first one //
	else
	{
		// This assigns the sentinel value to the same position it was in for the first list ensuring the two are equal in length //
		nums[*length]=-555;

		// Taking Input and Assigning to f //
		scanf("%d", &f);

		// Looping through the array positions and checking if they have the sentinel value to end loop //
		while(nums[i]!=-555)
		{
			// Assigns f to the array position //
			nums[i]=f;
			// Move to the next position //
			i++;
			// Checking to see if the next array position has the sentinel value; if yes, skip and finish loop, if no, take next input //
			if(nums[i]!=-555)
				scanf("%d", &f);
		}
	}

	// This assigns the value of i, which is the array length, to n back in main to be used in other functions' loops //
	*length=i;

}

void multiply(int num1[], int num2[], int product[], int total)
/*
	Dictionary of Variables:
		num1[] ~ refers to array x in main
		num2[] ~ refers to array y in main
		product[] ~ refers to array z in main
		total ~ refers to n in main and is the length of the array
		i ~ it is a loop counter variable and also refers to the position in the array

	Purpose:
		This function loops through the array and sums up the total for the corresponding positions in each array.

	This function multiplies the elements using a for loop
*/
{
	// Defining variable //
	int i;

	// Looping through the array //
	for(i=0; i<total; i++)
		// Multiplying the array elements //
		product[i]=num1[i]*num2[i];

}

void snsrt(int e[], int total, int *s)
/*
	Dictionary of Variables:
		e[] ~ references z in main
		s ~ a pointer to b in main
		total ~ length of the arrays
		i ~ a loop counter variable that refers to the position in the array

	Purpose:
		This sums all the numbers in z and then points the total back to b in main.

	This function uses a while loop to sum up all the elements.
*/
{
	// Defining Variable //
	int i=0;

	// looping through and adding all elements together //
	while(i<total)
	{
		*s=*s+e[i];
		i++;
	}

}

void printres(int list1[], int list2[], int list3[], int total, int *s)
/*
	Dictionary of Variables:
		list1[] ~ references array x in main
		list2[] ~ references array y in main
		list3[] ~ references array z in main
		total ~ is the length of the array
		s ~ is a pointer to b in main and is the total for all the elements in array z
		i ~ a loop counter variable in reference to the position of the array

	Purpose:
		This function prints out all the elements in the array in a nice table like format and also tells what the sum and square root of z are.

	This function uses a for loop to loop through the arrays to print out the elements.
*/

{
	// Defining Variable //
	int i;

	// Printing out the elements //
	printf("\n\n   x |   y |  z \n");
	printf("  ---------------\n");
	for(i=0; i<total; i++)
		printf(" %3d | %3d | %3d \n", list1[i], list2[i], list3[i]);

	// Printing out calculations //
	printf("\nThe sum of all the products in z is: %d", *s);
	printf("\nThe square root of the sum of z is: %3.2lf\n", (sqrt(*s)));

}

void search(int list[], int total)
/*
	Dictionary of Variables:
		i ~ a loop counter variable that indicates the position in the array
		p ~ the position of the smallest value in the array
		s ~ the smallest value in the array
		list[] ~ refers to array z in main
		total ~ refers to n in main and is the length of the array

	Purpose:
		This function searches for the smallest number in the array and prints out its value and
		position.

	This function uses a for loop in order to accomplish its search.
*/
{
	// Defining Variables //
	int i;
	int p=0;
	int s=list[0];

	// Looping to find smallest value //
	for(i=0;i<total;i++)
		{
		if(s>list[i])
			{
				p=i;
				s=list[i];
			}
		}

	// Displaying Results //
	printf("The smallest number in array z is %d and is in z[%d]", s, p);
}
