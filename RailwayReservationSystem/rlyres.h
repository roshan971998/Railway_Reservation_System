#ifndef RLYRES_H_INCLUDED
#define RLYRES_H_INCLUDED
typedef struct
 {
     char train_no[10];
     char from[10];
     char to[10];
     int fac_fare;
     int sac_fare;

 }Train;
 typedef struct
 {
     char p_name[20];
     char gender;
     char train_no[10];
     char p_class;
     char mob_no[13];
     int age;
     char address[30];
     int ticket_no;
 }Passenger;


int enterchoice();
void add_trains();
void view_trains();

int check_train_no(const char*);
int check_mobile_no(char *);

Passenger* get_passenger_details();
int get_booked_ticket_count(char*,char);
int last_ticket_no();

void displayError(int,int,char*);
void cancelRes(void);
void cancellingInput(void);

int book_ticket(Passenger);
int get_ticket_no();
int view_ticket();
void view_all_bookings();
void view_bookings(char*);
int cancel_ticket(int);
int cancel_train(char*);



#endif // RLYRES_H_INCLUDED
