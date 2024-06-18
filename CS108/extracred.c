#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
	This program has the purpose of taking in user data about specific parts of the car, including make, model, mileage, manufacture and purchase dates
	tank capacity, and current fuel level. It does this by having created a structure and filling it in through a function, and displaying the
	information in another. It takes information for 4 different cars.

	The structure is defined globally, but all variables are either local or passed to a function. It uses while loops and if/else selection.

	This program was written for extra credit by Betsy Kamas and was last modified on December 16, 2021.
*/

// Defined outside of main for all functions to know the data type auto_t //
typedef struct
	{
	char make[20];
	char model[20];
	int odom;
	int manu_date[4];
	int purc_date[4];
	double tank_cap;
	double cur_fuel;
	} auto_t;

int main(void)
/*
	Function Prototypes:
		scan_auto ~ takes an auto_t as input and returns nothing
		print_auto ~ takes an auto_t as input and returns nothing

	Dictionary of Variables:
		car1 ~ structure that holds info for car 1
		car2 ~ structure that holds info for car 2
		car3 ~ structure that holds info for car 3
		car4 ~ structure that holds info for car 4

	Purpose:
		Main calls the other functions.
*/
{

	// Defining Functions //
	void scan_auto(auto_t *);
	void print_auto(auto_t);

	// Defining Variables //
	auto_t car1, car2, car3, car4;

	// Getting Info from User //
	printf("Enter information for cars");
	scan_auto(&car1);
	scan_auto(&car2);
	scan_auto(&car3);
	scan_auto(&car4);

	// Printing out the information //
	printf("Car information:\n\n");
	print_auto(car1);
	print_auto(car2);
	print_auto(car3);
	print_auto(car4);
	printf("\n");



	return 0;
}


void scan_auto(auto_t *car)
/*
	Dictionary of Variables:
		*car ~ points back to one of the auto_t variables so the structure can be filled
		c ~ a character that is assigned whatever the user inputs which is then assigned to a location in the array
		i ~ a loop counter variable

	Purpose:
		This function prompts the user to input information which is then assigned to the correct location in the structure.

	This function uses an if selection structure and while loops to receive information
*/
{

	// Defining Variables //
	char c;
	int i=0;

	// Prompting User //
	printf("\nWhat's the make?\n");

	// This ensures that the new line from above does not influence what c is assigned //
	if((c=getchar())!= '\n')
		{
		// Assigning to Location //
		(*car).make[i]=c;
		i++;
		}

	// Taking user input until reaching the new line //
	while((c=getchar())!= '\n')
		{
		(*car).make[i]=c;
		i++;
		}

	// Adding Null so string can be read later //
	(*car).make[i]='\0';

	// Resetting loop counter //
	i=0;

	// Prompting User //
	printf("What's the model?\n");

	// This ensures that the new line from above does not influence what c is assigned //
	if((c=getchar())!= '\n')
		{
		// Assigning to Location //
		(*car).model[i]=c;
		i++;
		}

	// Taking user input until reaching the new line //
	while((c=getchar())!= '\n')
		{
		(*car).model[i]=c;
		i++;
		}

	// Adding Null so string can be read later //
	(*car).model[i]='\0';

	// Resetting Loop Counter //
	i=0;

	// Prompting User //
	printf("How many miles?\n");
	scanf("%d", &(*car).odom);

	// Prompting User and Assigning to correct array locations //
	printf("Manufacture month?\n");
	scanf("%d", &(*car).manu_date[0]);
	printf("Manufacture day?\n");
	scanf("%d", &(*car).manu_date[1]);
	printf("Manufacture year?\n");
	scanf("%d", &(*car).manu_date[2]);

	// Prompting User and Assigning to correct array locations //
	printf("Purchase month?\n");
	scanf("%d", &(*car).purc_date[0]);
	printf("Purchase day?\n");
	scanf("%d", &(*car).purc_date[1]);
	printf("Purchase year?\n");
	scanf("%d", &(*car).purc_date[2]);

	// Prompting User //
	printf("Tank capacity?\n");
	scanf("%lf", &(*car).tank_cap);

	// Prompting User //
	printf("Current fuel level?\n");
	scanf("%lf", &(*car).cur_fuel);

}

void print_auto(auto_t car)
/*
	Dictionary of Variables:
		car ~ refers to the auto_t variable that was used in the call to function

	Purpose:
		This function is a series of printf statements in order to display the information for the different cars 
*/
{


	// Displaying Car Information //
	printf("\n%s",(car).make);
	printf("   %s",(car).model);
	printf("   %7d", (car).odom);
	printf("   %7d", (car).manu_date[0]);
	printf("   %7d", (car).manu_date[1]);
	printf("   %7d", (car).manu_date[2]);
	printf("   %7d", (car).purc_date[0]);
	printf("   %7d", (car).purc_date[1]);
	printf("   %7d", (car).purc_date[2]);
	printf("   %4.2lf", (car).tank_cap);
	printf("   %4.2lf\n", (car).cur_fuel);


}
