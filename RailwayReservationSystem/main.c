#include<stdio.h>
#include<stdlib.h>
#include "conio2.h"
#include "rlyres.h"
int main()
{
    int choice,ticket_no;
    Passenger* psr;
    add_trains();
    do
    {
        clrscr();
        choice = enterchoice();
        if(choice==9)
            exit(0);
        switch(choice)
        {
            case 1:
                view_trains();
                break;
            case 2://book_ticket();
                psr=get_passenger_details();
                if(psr!=NULL)
                {
                    ticket_no=book_ticket(*psr);
                    if(ticket_no==-1)
                    {
                        textcolor(LIGHTRED);
                        printf("\n\nBOKKING FAILED!!!!!!!!!!!!!!!! ");
                    }
                    else
                    {
                        clrscr();
                        gotoxy(1,1);
                        textcolor(LIGHTGREEN);
                        printf("\nTicket Booked Successfully\n\nYour Ticket No is ");
                        textcolor(LIGHTBLUE);
                        printf("%d",ticket_no);
                    }
                }
                textcolor(WHITE);
                printf("\n\n\nPress Any Key To Go To Main Menu ");
                getch();
                break;
            case 3:
                view_ticket();
                break;
            case 4:
                get_ticket_no();
                break;
            case 5:
                //view_all_bookings();
                break;
            case 6:
                //view_bookings();
                break;
            case 7:
                //cancel_ticket();
                break;
            case 8:
                //cancel_train();
                break;
            default:
                textcolor(LIGHTRED);
                printf("\nWrong Choice! Try Again");
                getch();

        }

    }while(1);


return 0;
}
