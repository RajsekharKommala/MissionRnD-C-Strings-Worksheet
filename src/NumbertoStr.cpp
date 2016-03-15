/*
OVERVIEW: Given a float number ,Convert it into a string 

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include <stdio.h>
void number_to_str(float number, char *str,int afterdecimal){
	int  decimal_number = 1, i, j = 0, k = 0;
	int len = afterdecimal;
	for (i = 1; i <= len; i++)
		decimal_number *= 10;

	if (number < 0){
		str[j++] = '-';
		k = 1;
		number *= -1;
	}
	//extract the integer part
	int i_part = (int)number;
	int c;
	c = number * decimal_number;
	i = 0;
	while (i<len)
	{
		i++;
		str[j++] = (c % 10) + 48;
		c /= 10;
	}
	if (len>0){
		str[j++] = '.';
	}
	printf("%d ",i_part);
	while (i_part != 0)
	{
		str[j++] = (i_part % 10) + 48;
		i_part /= 10;
	}
	str[j] = '\0';
	printf("\n %s", str);
	int n;
	while (k < j){
		n = str[--j];
		str[j] = str[k];
		str[k++] = n;
	}

}
