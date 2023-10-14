/*
* filename: f4.cpp
* Project: Focused 4
* By: Luke Dennis
* Date: October 13th, 2023
* Description: This code will take inputted numbers and tell the user smallest one using arrays AND will display which index they inputted it at. 
*/

#include <stdio.h>
#pragma warning(disable: 4996) //required by visual studios so getNum() will cooperate

int main()
{
    const int kArrayQuan = 10; /* everything else will be initialized to zero except for this one line, this is the number that will assist in only collecting 10 digits of user input, has been made a constant since it will
     not change*/
    int array[kArrayQuan];
    int count = 0;
    int small = 0;
    int indexNumber = 0;
    int getNum(void);
    /* prototype for the function that is present at the botton of this code, getNum is responsible for gathering user inputs */

    printf("Please input 10 numbers (press enter after each one)\n");

    for (count = 0; count < kArrayQuan; count++) 
    {
        array[count] = getNum();

        if (count == 0 || array[count] < small)
        {
            small = array[count];
            indexNumber = count;
        }
    }

    printf("The lowest value is %d at index %d\n", small, indexNumber);

    return 0;
}

int getNum(void)
{
/* the array is 121 bytes in size; we'll see in a later lecture how we can improve this code */
	char record[121] = { 0 }; /* record stores the string */
	int number = 0;
	/* NOTE to student: brace this function consistent with your others */
	/* use fgets() to get a string from the keyboard */
	fgets(record, 121, stdin);
	/* extract the number from the string; sscanf() returns a number
	      * corresponding with the number of items it found in the string */
	if (sscanf(record, "%d", &number) != 1)
	{
		/* if the user did not enter a number recognizable by
		/* the system, set number to -1 */
		number = -1;
	}
	return number;
}