#include <stdio.h>

struct date{    /*Structure for the dates.*/
	int day;
	int month;
	int year;
}date;

int is_leap_year(int);   /*Check for leap year (not going to be used.)*/
int checkdate(struct date); /* Prototype. Validate the date and check for leap year*/

void main(){  /* Main function*/


	struct date D1;  /*first date*/
	struct date d2;  /*Second date*/

        while (checkdate(D1) == 0){
		printf("First date: ");
		scanf("%i %*[-/] %i %*[-/] %i", &(D1.day),&(D1.month),&(D1.year));
	}
	while (checkdate(d2) == 0){
		printf("\nSecond date: ");
		scanf("%i %*[-/] %i %*[-/] %i", &(d2.day),&(d2.month),&(d2.year));
	}



	printf("D1:%i",D1.day);
	printf(" m1:%i",D1.month);
	printf(" y:%i\n",D1.year);
	printf("l1:%i\n", is_leap_year(D1.year));

	printf("d2:%i",d2.day);
	printf(" m2:%i",d2.month);
	printf(" y2:%i\n",d2.year);
	printf("l2:%i\n", is_leap_year(d2.year));

}


int is_leap_year(int year){    /*Planning ahead,as in assignment 1 we ignore leap year, we will set this to always return 0*/
		return 0; 
};

int checkdate(struct date day){	
	int month[12];
	if (is_leap_year(day.year) == 0){                       /*Defining days in months according to the year*/
		int month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};   

	} else {

		int month[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
	}
	/*Check if the date is valid*/
	if ( (day.day >=1 && (day.day <= month[day.month - 1])) && (day.month >= 1 && day.month <= 12) && (day.year >= 1 && day.year <= 10000)){
		return 1;
	}else{
		fprintf(stderr, "%s", "Check Your Dates Again!\n");
		return 0;
	}
}


