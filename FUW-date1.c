#include <stdio.h>

struct date{    //Structure for the dates.
	int day;
	int month;
	int year;
}date;

int is_leap_year(int);   //Check for leap year (not going to be used.)
int checkdate(struct date); // Validate the date and check for leap year

void main(){  // Main function


	struct date d1;  //first date
	struct date d2;  //Second date

        while (checkdate(d1) == 0){
		printf("First date: ");
		scanf("%i %*[-/] %i %*[-/] %i", &(d1.day),&(d1.month),&(d1.year));
	}
	printdate(
	while (checkdate(d2) == 0){
		printf("\nSecond date: ");
		scanf("%i %*[-/] %i %*[-/] %i", &(d2.day),&(d2.month),&(d2.year));
	}



	printf("d1:%i",d1.day);
	printf(" m1:%i",d1.month);
	printf(" y:%i\n",d1.year);
	printf("l1:%i\n", is_leap_year(d1.year));

	printf("d2:%i",d2.day);
	printf(" m2:%i",d2.month);
	printf(" y2:%i\n",d2.year);
	printf("l2:%i\n", is_leap_year(d2.year));

}


int is_leap_year(int year){
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)){ //every 4 year *need to fix*
		return 1;
	}else{
		return 0;
	}
};

int checkdate(struct date day){	

	int month[12];
	if (is_leap_year(day.year) == 0){   // Defining days in months according to the calendar
		int month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};   

	} else {

		int month[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
	}
	/*
	printf("day: %i\n",(day.day >=1 && (day.day <= month[day.month+1]));
	printf("week: %i\n", (day.month >= 1 && day.month <= 12));
	printf("month: %i\n", (day.year >= 1 && day.year <= 10000));
	*/
	if ( (day.day >=1 && (day.day <= month[day.month - 1])) && (day.month >= 1 && day.month <= 12) && (day.year >= 1 && day.year <= 10000)){
		return 1;
	}else{
		return 0;
	}
}


