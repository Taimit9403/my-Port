//Tai mitchell
#include <stdio.h>
#include <stdlib.h>

int choice;
int capacity = 10;
int seats[10];

const char* class(int s){
	if(s >= 0 && s < 5)	return "First Class\n";
	else if(s >= 5 && s < 10)	return "Economy\n";
	return "Unknown\n";
}
void welcome(){
	printf("Welcome to Tai's Airport services, thank you for boarding with us!\n");
	printf("Please type 1 for 'First Class' or type 2 for 'Economy'\n");
	printf("---------------------------------------------------------------------\n");
	scanf("%d", &choice);
}
void printTicket(int seat){
	printf("Boarding Pass: Seat %d \nClass: %s \n", seat+1, class(seat));
	printf("---------------------------------------------------------------------\n");
}
int isEmpty(int seats[], int type)
{
	int i;
	if(type == 1){
		for( i=0; i<5; i++){
			if(seats[i] == 0){
				return i;
			}
		}
	} else if(type == 2){
		for( i=5; i<10; i++){
			if(seats[i] == 0){
				return i;
			}
		}
	} 
	return -1;
}
int main() {
	int seat;
	int i;
	char changeClass;
	for( i=0; i<capacity; i++) seats[i] = 0;
	welcome();
	while(choice != 3){
		if(choice == 1){
			if(isEmpty(seats, 1) != -1){
				seat = isEmpty(seats, 1);
				seats[seat] = 1;
				printTicket(seat);
			} else if(isEmpty(seats, 2) != -1){
				printf("First Class is full. Would you like an economy seat instead? (y/n)\n" );
				printf("---------------------------------------------------------------------\n");
				scanf(" %c", &changeClass);
				if(changeClass == 'Y' || changeClass == 'y'){
					seat = isEmpty(seats, 2);
					seats[seat] = 1;
					printTicket(seat);
				} else {
					printf("Sorry no more seats!, Next flight leaves in 3 hours.");
					return 0;
					}
			} else {
			 printf("Sorry all seats have been booked for this flight. Next flight leaves in 3 hours.\n");
			 return 0;
			}
		} else if(choice == 2){
			if(isEmpty(seats, 2) != -1){
				seat = isEmpty(seats, 2);
				seats[seat] = 1;
				printTicket(seat);
			} else if(isEmpty(seats, 1) != -1){
				printf("Economy Class is full. Would you like a First Class seat instead? (y/n)\n" );
				scanf(" %c", &changeClass);
				if(changeClass == 'Y' || changeClass == 'y'){
					seat = isEmpty(seats, 1);
					seats[seat] = 2;
					printTicket(seat);
				} else {
				printf("Sorry no more seats!, Next flight leaves in 3 hours.");
				return 0;
				}
			} else {
			 printf("Sorry all seats have been booked for this flight. Next flight leaves in 3 hours.\n");
			 return 0;
			}
		} else {
			printf("Wrong choice!\n");
		}
		welcome();
	}
	return 0;
}//Tai mitchell
