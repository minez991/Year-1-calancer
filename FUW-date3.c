#include <stdio.h>

struct date{    /*Structure for the dates.*/
	int day;
	int month;
	int year;
	int epochday;
}date;

int is_leap_year(int);   /*Check for leap year (not going to be used.)*/
int checkdate(struct date, int month[]); /* Prototype. Validate the date and check for leap year*/
int convert_day(struct date,int month[]);
int if_leap_year(struct date);
void bubblesort(struct date[], int);

int main(){  /* Main function*/
	int n,j,i;
	scanf("%i",&n);

	struct date date_array[n];
	struct date date;  /*first date*/
	printf("hi");
	int month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

	for (j = 0 ; j < n ; j++){
		do{	
			printf("date of %i: ", j);
			scanf("%i %*[-/] %i %*[-/] %i", &(date.day),&(date.month),&(date.year));
			date.epochday = convert_day(date,month);
		}while (checkdate(date,month) == 0);
		date_array[j] = date;
	}
	bubblesort(date_array,n);

	for( i = 0; i < n ; i++ ){
		printf("\n%i/%i/%i\n",date_array[i].day,date_array[i].month,date_array[i].year);
	}



	return 0;
}


void bubblesort(struct date array[], int n){
	int i,j;
	for (i = 0; i < n ; i++){
		for(j = 0 ; j < n-i-1 ; j++ ){
			if (array[j].epochday>array[j+1].epochday){
				struct date temp;
				temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}
	}
}
int if_leap_year(struct date date){
	if (date.year%4 == 0){
		return 1;
	}else{
		return 0;
	}
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


