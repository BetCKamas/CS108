/* This program is made in order to record user defined temperatures into
   an array that will categorize them into hot, pleasant and cold days. The
   the program will then tell the user the total number of each day type there
   was.

   This program uses variables local to main, a function, loops and selection
   structures. There are no global variables.

   This program was written for GHP#4 by Betsy Kamas on November 3, 2021.
   Last updated November 10, 2021.
*/

#include <stdio.h>

int main(void){

	/* Dictionary

	Variables:
	h represents the number of hot days
	p represents the number of pleasant days
	c represents the number of cold days
	x represents the location within the array

	Array:
	temp can hold at most 25 pieces of data

	Function Prototype:
	Categorize_temperatures takes 4 pieces of integer input; one array
		and three reference parameters

	Purpose:
	This function initializes all cells in the array to zero, and then
	calls the Categorize_temperatures function to sift through the user
	defined data. After Categorize_temperatures runs, the totals are then
	displayed to the user.
	*/

	int h=0;
	int p=0;
	int c=0;
	int x;
	void Categorize_temperatures(int[], int*, int*, int*);
	int temp[25];

	for(x=0; x<25; x++)
		temp[x]=0;

	/* The above for statement initializes the array to 0's */

	Categorize_temperatures(temp, &h, &p, &c);

	/* Calling the function */

	printf("\nHot days:%4d\nPleasant days:%4d\nCold days:%4d\n", h,p,c);

	/* Displaying to the user the number of each kind of day. */

return 0;
}

void Categorize_temperatures(int t[], int *hot, int *pleasant, int *cold){

/* Dictionary

   Variables:
   hot is a reference parameter pointing back to h in main.
   pleasant is a reference parameter pointing back to p in main.
   cold is a reference parameter pointing back to c in main.
   x and i are variables that will specify the location in the array.
   y is a loop counter variable for the number of data points displayed in
	a row.

   This function is going to be using loops and a selection structure in order
   to count the number of each type of day.

   This function references t to temp in main for the array. It will allow for
   25 pieces of data to be entered into the array.

   Purpose:
   This function asks the user for input, and then displayes it back to the
   user in a nice 5x5 table format. It is then processed by a while loop to
   determine how many of each kind of day type there is based on the
   temperature.
*/

	int i=0;
	int y=0;
	int x;

	printf("\nPlease enter 25 temperatures to categorize\n");

	/* asking for user input */

	for(x=0; x<25; x++)
		scanf("%d", &t[x]);

	/* This for statement is assigning the user defined temperatures into
	   the array. */

	printf("\nThe temperatures entered were:\n");

	for(x=0; x<25; x++){
		printf("%4d", t[x]);

		if(y<4){
			y++;
			}
		else{
			printf("\n");
			y=0;
			}
		}

	/* The above will redisplay the temperatures to the user in a nice
	   5x5 table. */

	while(i<25){

		if(t[i]>=85)
			*hot=*hot+1;

		else if(t[i]<60)
			*cold=*cold+1;

		else
			*pleasant=*pleasant+1;

		i++;

		}

	/* This while loop is reading the data in from each cell in the array and taking it through
	   the if statement and classifying each temperature into hot, pleasant, or cold. It then
	   keeps a running total of each kind of day. The number of the type of day is then pointed
	   back to main, since this function returns nothing. It repeats until
	   the end of the array has been reached. */

}
