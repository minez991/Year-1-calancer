#include <stdio.h>

struct date{    /*Structure for the dates.*/
	int day;
	int month;
	int year;
}date;

int is_leap_year(int);   /*Check for leap year (not going to be used.)*/
int checkdate(struct date, int month[]); /* Prototype. Validate the date and check for leap year*/
void calc_diff(struct date,struct  date, int month[]); /*Prototype, Calculate difference*/
int convert_day(struct date,int month[]); /*Prototype Convert date to days from 1/1/1*/

int main(){  /* Main function*/


	struct date D1;  /*first date*/
	struct date D2;  /*Second date*/
	char ch;

	int month[12] = {31,28,31,30,31,30,31,31,30,31,30,31}; /*Month array*/
    
    do{

		int test=scanf("%i %*[-/] %i %*[-/] %i", &(D1.day),&(D1.month),&(D1.year));   /*Input first date*/
		if (test!=3)
			for(ch=getchar();ch!='\n';ch=getchar()){
				if (ch ==EOF){
					fprintf(stderr, "Error unexpected EOF\n");
					return 0;
				}
			}; /*Clear input buffer*/


	}while (checkdate(D1,month) == 0); /*Check if the date is valid, if not repeat*/

	do{
		int test = scanf("%i %*[-/] %i %*[-/] %i", &(D2.day),&(D2.month),&(D2.year));
		if (test!=3)
			for(ch=getchar();ch!='\n';ch=getchar()){
				if (ch ==EOF){
					fprintf(stderr, "Error unexpected EOF\n" );
					return 0;
				}
			};	

	}while (checkdate(D2,month) == 0); /*Check if the date is valid, if not repeat*/

	calc_diff(D1,D2,month);
	return 0;
}

int checkdate(struct date day, int month[]){	
	/*Check if the date is valid*/


	if(day.month >= 1 && day.month <= 12){			/*Check month first to prevent a seg fault*/
		if ( (day.day >=1 && (day.day <= month[day.month - 1])) && (day.month >= 1 && day.month <= 12) && (day.year >= 1 && day.year <= 10000)){
			return 1;
		}else{
			fprintf(stderr, "%s", "Check Your Dates Again!\n");
			return 0;
		}
	}else{
		fprintf(stderr, "%s", "Check Your Dates Again!\n");
		return 0;
	}

}




int is_leap_year(int year){    /*Planning ahead,as in assignment 1 we ignore leap year, we will set this to always return 0*/
		return 0; 
}



void calc_diff(struct date date1,struct date date2,int month[]){
	printf("%i\n", convert_day(date2,month)-convert_day(date1,month));
	
}

int convert_day(struct date date,int month[]){
	int daynumber,days_in_months = 0,i;

	for (i = 1 ; i < date.month ; i++){
		days_in_months = days_in_months + month[i-1]; 
	}
	daynumber = ((date.year -1) * 365) + days_in_months + date.day-1;
	return daynumber;
}




