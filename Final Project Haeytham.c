/*          Programmer Block

Programmer: Haeytham AlMalak
Date: April 3, 2019
Discriprion:  The Econo-Airlines fleet consists of one plane with a seating
              capacity of 12.
			  It makes one flight daily.
              The aircraft seating is arranged in 6 rows with 2 seats per row.
              The program uses an array of 12 structures.
              Each structure holds a seat identification number,
              a marker that indicates whether the seat is assigned,
              the last name of the seat holder, and the first name of the seat holder.
              The program displays the following menu:
              To choose a function, enter its letter label:

                      a. Display ALL seat assignments (including Empty).
                      b. Show ONLY a list of empty seats and show total of empty seats
                      c. SHOW ONLY the assigned seats with name of person and total assigned.
                      d. Assign the customer to an empty seat.
                      e. Delete ONE seat assignment.
                      f. Delete ALL seat assignments.
                      q. Quit program.

					  NOT: The selection must NOT be case sensitive.
             ==========--------____________--------==========
Verson:1.0
Note : Uplouad to Github on date October 16, 2022
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct
{
	char marker;
	int	 seatNumber;
	char firstName[10];
	char lastName[10];

} seat;

char userChoise(void);
void emptySeats(seat plane[]);
void DisplaySeat(seat plane[]);
void assignedSeats(seat plane[]);
void AssignCustomerToSeat(seat plane[]);
void DeletONEseat(seat plane[]);
void DeleteALL(seat plane[]);

int main(void)
{
	system("COLOR 0A");

	int index;
	char choise = '0';

	seat plane[12];

	for (index = 0; index < 12; index++)
	{
		plane[index].marker = 'n';
		strcpy(plane[index].firstName, "empty");
		strcpy(plane[index].lastName, "seat");
		plane[index].seatNumber = (index + 1);
	}
	
	while (choise != 'q')
	{

		choise = userChoise();

		switch (choise)
		{
		   case 'a':

		     	system("cls");

		    	DisplaySeat(plane);

	           break;
		    case 'b':

			    system("cls");

		    	emptySeats(plane);

	           break;
	    	case 'c':

		    	system("cls");

		    	assignedSeats(plane);

		    	break;
		    case 'd':

		    	system("cls");

		    	AssignCustomerToSeat(plane);

		    	break;
		    case 'e':

		    	system("cls");

		    	DeletONEseat(plane);

		    	break;
		    case 'f':

		    	system("cls");

		    	DeleteALL(plane);

		    	break;
		}

	}

	puts("\n");

	system("pause");
	return 0;
}

char userChoise(void)
{
	char reservation = 'z';

	printf("\t\t\t\tWelcome in Econo-Airlines Menu\n\n");
	puts("a.  Display ALL seat assignments (including Empty).");
	puts("b.  Show ONLY a list of empty seatsand show total of empty seats");
	puts("c.  SHOW ONLY the assigned seats with name of personand total assigned.");
	puts("d.  Assign the customer to an empty seat.");
	puts("e.  Delete ONE seat assignment.");
	puts("f.  Delete ALL seat assignments.");
	puts("q.  Quit program.");
	printf("\nInput your choise please  ");

	fflush(stdin);

	scanf(" %c", &reservation);

	reservation = tolower(reservation);

	return reservation;
}

void DisplaySeat(seat plane[])
{
	int index;

	printf("\nSeats Arrangment\n\n");
	printf("seat Number     Used     Lastname    Firstname\n\n");

	for (index = 0; index < 12; index++)
	{
		printf("%-9d\t%-9c %-5s \t%-1s \n", plane[index].seatNumber, plane[index].marker, plane[index].lastName, plane[index].firstName);
	}
	puts("");

	system("pause");
	system("cls");
	return;
}

void emptySeats(seat plane[])
{
	int index;
	int cnt = 0;

	printf("\nEmpty Seat Number(s) : \n");
	puts("\t\t\t");

	for (index = 0; index < 12; index++)
	{
		if (plane[index].marker ==  'n' )
		{
			printf("%-5d", plane[index].seatNumber);

			cnt++;
		}
	}

	printf("\n\nEmpty seats in total : %d ", cnt);
	puts("\n\n");
	
	system("pause");
	system("cls");
	return;
}

void assignedSeats(seat plane[])
{
	int index;
	int cnt = 0;

	printf("Booked Seatt(s) :\n");
	puts("");
	printf("\nSeat Number     Lastname   Firstname\n\n");

	for (index = 0; index < 12; index++)
	{
		if (plane[index].marker == 'y')
		{

			printf("%5d \t\t %-10s %-10s \n", plane[index].seatNumber, plane[index].lastName, plane[index].firstName);

			cnt++ ;
		}
	}
	
	printf("\nBooked seats in total : %d \n\n", cnt);

	system("pause");
	system("cls");
	return;
}

void AssignCustomerToSeat(seat plane[])
{
	int num;

	printf("\nEnter the flowing information please:\n");
	printf("\nseat number please: ");

	scanf(" %d", &num);

	printf("\nFirst Name: ");

	fflush(stdin);

	scanf("%s", &plane[num - 1].firstName);

	printf("\nLast Name: ");
	scanf("%s", &plane[num - 1].lastName);

	plane[num - 1].marker = 'y';

	puts("");

	system("pause");
	system("cls");
	return;
}

void  DeletONEseat(seat plane[]) 
{

	int seatNum;

	printf("\nEnter number the seat you like to deleate olease:\n");
	scanf_s("%d",&seatNum);

	plane[seatNum-1].marker = 'n';
	strcpy(plane[seatNum-1].firstName, "empty");
	strcpy(plane[seatNum-1].lastName, "seat");

	printf("\nThe Seat Number ( %d ) has beed Deleted\n", seatNum);
	puts("");

	system("pause");
	system("cls");
	return;
}

void DeleteALL(seat plane[])
{
	int index;
	
		for (index = 0; index < 12; index++)
		{
			plane[index].marker = 'n';
			strcpy(plane[index].firstName, "empty");
			strcpy(plane[index].lastName, "seat");
			plane[index].seatNumber = (index + 1);
		}

		printf("\nAll Seats has beed Deleted\n");
		puts("");

	system("pause");
	system("cls");
	return;
}
/*
p0
								Welcome in Econo-Airlines Menu

a.  Display ALL seat assignments (including Empty).
b.  Show ONLY a list of empty seatsand show total of empty seats
c.  SHOW ONLY the assigned seats with name of personand total assigned.
d.  Assign the customer to an empty seat.
e.  Delete ONE seat assignment.
f.  Delete ALL seat assignments.
q.  Quit program.

Input your choise please

pA)
Seats Arrangment

seat Number     Used     Lastname    Firstname

1               n         seat          empty
2               n         seat          empty
3               y         Dilon         Alan
4               n         seat          empty
5               n         seat          empty
6               n         seat          empty
7               n         seat          empty
8               n         seat          empty
9               n         seat          empty
10              n         seat          empty
11              n         seat          empty
12              n         seat          empty

Press any key to continue . . .

PB)

Empty Seat Number(s) :

1    2    3    4    5    6    7    8    9    10   11   12

Empty seats in total : 12


Press any key to continue . . .

pB)

Booked Seatt(s) :


Seat Number     Lastname   Firstname


Booked seats in total : 0

Press any key to continue . . .

PC)

Enter the flowing information please:

seat number please: 3

First Name: ALAN

Last Name: Delon

Press any key to continue . . .

PD)

Enter the flowing information please:

seat number please: 3

First Name: Alan

Last Name: Dilon

Press any key to continue . . .

PE)
Enter number the seat you like to deleate olease:
2

The Seat Number ( 2 ) has beed Deleted

Press any key to continue . . .

PF)

All Seats has beed Deleted

Press any key to continue . . .


*/