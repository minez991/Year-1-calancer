#include <stdio.h>

struct date{    /*Structure for the dates.*/
	int day;
	int month;
	int year;
}date;

int is_leap_year(int);   /*Check for leap year (not going to be used.)*/
int checkdate(struct date, int month[]); /* Prototype. Validate the date and check for leap year*/
void calc_diff(struct date,struct  date, int month[]);
int convert_day(struct date,int month[]);
int if_leap_year(struct date);

int main(){  /* Main function*/


	struct date D1;  /*first date*/
	struct date D2;  /*Second date*/

	int month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    
    do{
		printf("First date: ");
		scanf("%i %*[-/] %i %*[-/] %i", &(D1.day),&(D1.month),&(D1.year));
	}while (checkdate(D1,month) == 0);

	do{
		printf("\nSecond date: ");
		scanf("%i %*[-/] %i %*[-/] %i", &(D2.day),&(D2.month),&(D2.year));
	}while (checkdate(D2,month) == 0);



	printf("D1:%i",D1.day);
	printf(" m1:%i",D1.month);
	printf(" y:%i\n",D1.year);
	printf("l1:%i\n", if_leap_year(D1));
	/*printf("Day Number: %i\n", convert_day(D1,month));*/

	printf("D2:%i",D2.day);
	printf(" m2:%i",D2.month);
	printf(" y2:%i\n",D2.year);
	printf("l2:%i\n", if_leap_year(D2));
	/*printf("Day Number: %i\n", convert_day(D2,month));*/

	calc_diff(D1,D2,month);
	return 0;
}

int if_leap_year(struct date date){
	if (date.year%4 == 0){
		return 1;
	}else{
		return 0;
	}
}


void calc_diff(struct date date1,struct date date2,int month[]){
	int day1,day2;
	printf("------------------Day1----------------\n");
	day1 = convert_day(date1,month);
	printf("------------------Day2----------------\n");
	day2 = convert_day(date2,month);

	printf("Date Diff: %i \n", day2-day1);
	
}

int convert_day(struct date date,int month[]){
	int daynumber,days_in_months = 0, days_in_years = 0;
	int i;
	for (i = 1 ; i < date.month ; i++){
		days_in_months = days_in_months + month[i-1]; 
	}

	for (i = 1; i <= date.year - 1  ; i++){
		if (i%4 == 0 ){
			days_in_years = days_in_years +366;
		}else{
			days_in_years = days_in_years + 365;
		}
	}

	daynumber = days_in_years + days_in_months + date.day-1;
	return daynumber;
}

int checkdate(struct date day, int month[]){	
	/*Check if the date is valid*/
	if (if_leap_year(day) == 1){
		month[1] = 29;
	}
	
	if ( (day.day >=1 && (day.day <= month[day.month - 1])) && (day.month >= 1 && day.month <= 12) && (day.year >= 1 && day.year <= 10000)){
		return 1;
	}else{
		printf("%i",month[0]);
		fprintf(stderr, "%s", "Check Your Dates Again!\n");
		return 0;
	}
}


