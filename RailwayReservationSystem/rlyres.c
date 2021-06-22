#include<stdio.h>
#include<stdlib.h>
#include<process.h>
#include<dos.h>
#include<string.h>
#include "conio2.h"
#include "rlyres.h"
int enterchoice()
{
    int i=0,choice;
    textcolor(YELLOW);
    gotoxy(26,1);
    printf("RAILWAY RESERVATION SYSTEM\n");
    while(i<80)
    {
        printf("-");
        i++;
    }
    printf("\n-------------------\n");
    printf("Select an option\n\n");
    printf("1- View Trains\n2- Book Ticket\n3- View Ticket\n4- Search Ticket No\n");
    printf("5- View All Bookings\n6- View Train Bookings\n7- Cancel Ticket\n8- Cancel Train\n9- QUIT\n");
    printf("\n\nEnter Choice : ");
    fflush(stdin);
    scanf("%d",&choice);

    return choice;

}

void add_trains()
{
    FILE *fp=fopen("allTrains.dat","rb");
    if(fp==NULL)
    {
        fp=fopen("allTrains.dat","wb");
        Train allTrains[4]={
                     {"123","BPL","GWL",2100,1500},
                     {"546","BPL","DEL",3500,2240},
                     {"345","HBJ","AGR",1560,1135},
                     {"896","HBJ","MUM",4500,3360}
                };
        fwrite(allTrains,4*sizeof(Train),1,fp);
        printf("File saved successfully");
        fclose(fp);
    }
    else
    {
        printf("File Already Present");
        fclose(fp);
    }
}

void view_trains()
{
    int i;
    Train tList[4];
    FILE *fp;
    clrscr();
    textcolor(YELLOW);
    printf("TRAIN NO\tFROM\tTO\tFIRST AC FAIR\t     SECOND AC FAIR\n");
    for(i=0;i<80;i++)
    printf("-");
    printf("\n\n");
    fp=fopen("allTrains.dat","rb");
    fread(tList,4*sizeof(Train),1,fp);
    for(i=0;i<4;i++)
    {
        printf("%s%16s%8s%9d%21d\n",tList[i].train_no,tList[i].from,tList[i].to,tList[i].fac_fare,tList[i].sac_fare);
    }
    fclose(fp);
    textcolor(WHITE);
    printf("\n\n\nPress Any Key To Continue To Main Screen");
    getch();
}
int  check_train_no(const char *train_no)
{
    char tr[10];
    FILE *fp=fopen("allTrains.dat","rb");

    while(fp==NULL)
    fopen("allTrains.dat","rb");

    while(fread(tr,10*sizeof(char),1,fp))
    {
        if(strcmp(train_no,tr)==0)
        {
            fclose(fp);
            return 1;
        }
        fseek(fp,sizeof(Train)-sizeof(tr),SEEK_CUR);
    }
    fclose(fp);
  return 0;
}
int check_mobile_no(char *mob_no)
{
    int valid;
    valid=((strlen(mob_no)>0&&strlen(mob_no)<10)||((strlen(mob_no)==10)&&((mob_no[0]>=58||mob_no[0]<=53)
                                               ||(mob_no[1]>=58||mob_no[1]<=47)
                                               ||(mob_no[2]>=58||mob_no[2]<=47)
                                               ||(mob_no[3]>=58||mob_no[3]<=47)
                                               ||(mob_no[4]>=58||mob_no[4]<=47)
                                               ||(mob_no[5]>=58||mob_no[5]<=47)
                                               ||(mob_no[6]>=58||mob_no[6]<=47)
                                               ||(mob_no[7]>=58||mob_no[7]<=47)
                                               ||(mob_no[8]>=58||mob_no[8]<=47)
                                               ||(mob_no[9]>=58||mob_no[9]<=47))));
                        return valid;
}
void cancelRes()
{
          textcolor(LIGHTRED);
          gotoxy(1,25);
          printf("RESERVATION CANCELLED!");
          sleep(1);


}
void displayError(int x,int y,char* emsg)
{
    int i=0;
    textcolor(LIGHTRED);
    gotoxy(1,25);
    printf("%s",emsg);
    fflush(stdin);//this is optional when as we take input in string variable present in that function
    getch();
    printf("\r");
    for(i=0;i<80;i++)
     printf(" ");
    gotoxy(x,y);
    for(i=0;i<20;i++)
     printf(" ");
    gotoxy(x,y);
    textcolor(YELLOW);

}
void cancellingInput()
{
     textcolor(LIGHTRED);
     gotoxy(1,25);
     printf("CANCELLING CHECKING!\n");
     textcolor(WHITE);
     printf("\nPress Any Key To Go To Main Menu ");
     fflush(stdin);
     getch();

}

Passenger* get_passenger_details()
{
    int i,valtrn=0,mobval=1;
    static Passenger psn;
    char *pos;
    clrscr();
    textcolor(LIGHTGREEN);
    gotoxy(50,1);
    printf("Press 0 to Exit at any point ");
    textcolor(YELLOW);

    gotoxy(1,2);
    printf("Enter passenger Name:");
    fflush(stdin);/*as this is not the first input of our program,previously buffer has enter left after choice value given*/
    fgets(psn.p_name,20,stdin);
    pos=strchr(psn.p_name,'\n');
    if(pos!=NULL)
    *pos='\0';//at this point psn.p_name variabe will be having two null or '\0' at the end of string
    if(strcmp(psn.p_name,"0")==0)
    {
       cancelRes();
       return NULL;
    }

    gotoxy(1,3);
    printf("Enter Gender(M/F):");
    do{
        scanf(" %c",&psn.gender);  //instead of flush we can use one space before %c in scaf
        if(psn.gender=='0')
        {
          cancelRes();
          return NULL;
         }
        else if((psn.gender=='M'||psn.gender=='F')==0)
        {
            textcolor(LIGHTRED);
            gotoxy(1,25);
            printf("ERROR! Gender Should Be M or F(in UpperCase)");
            fflush(stdin);//Highly important and in this case we are using char variable
            getch();//i.e p.gender so while giving input from screen if we give more than on character(let say 4 chars be jlmp) then the p.gender will accept only first character and remainning will be in buffer
            printf("\r");//now since we have given more than one char so else if block is executed
            for(i=0;i<80;i++)//and as result error is printed now without using fflush() if we write getch then without any delay it accept ony one char from buffer
               {             // and program behaviour is like from getch printf and for is skipped and cursor directly goes to gotoxy and before filling spacec in place of error messg it erases all input field of gender and then we have to press 3 any caracters
                 printf(" ");//i.e we have to strike one less character as we gave during input to see eroor msg disappear again and before disapppear of error msg the 3 extra chars we again strike do not get stored to gender
               }
            gotoxy(19,3);
            for(i=0;i<20;i++)
            {
                printf(" ");
            }
            textcolor(YELLOW);
          }
           gotoxy(19,3);
      }while((psn.gender=='M'||psn.gender=='F')==0);

      gotoxy(1,4);
      printf("Enter Train No:");
      while(valtrn==0)
      {
           scanf(" %s",psn.train_no);
           if(strcmp(psn.train_no,"0")==0)
           {
              cancelRes();
              return NULL;
           }
           valtrn=check_train_no(psn.train_no);
           if(valtrn==0)
           {
               displayError(16,4,"ERROR! Invalid Train No");
           }
      }


      gotoxy(1,5);
      printf("Enter Traveling Class(First AC-F,Second AC-S):");
      do
      {
        scanf(" %c",&psn.p_class);
        if(psn.p_class=='0')
        {
          cancelRes();
          return NULL;
         }
        else if((psn.p_class=='F'||psn.p_class=='S')==0)
        {
            displayError(47,5,"ERROR! Travelling Class Should Be F or S(in UpperCase)");
        }
      }while((psn.p_class=='F'||psn.p_class=='S')==0);

      gotoxy(1,6);
      printf("Enter The Mobile No(in 10 digit only):");
      while(mobval==1)
      {
          scanf(" %s",psn.mob_no);
          if(strlen(psn.mob_no)==1&&psn.mob_no[0]=='0')
          {
              cancelRes();
              return NULL;
          }
           mobval=check_mobile_no(psn.mob_no);
          if (mobval==1)
          {
              displayError(39,6,"ERROR! Invalid Mobile No");
          }
      }

      gotoxy(1,7);
      printf("Enter Address:");
      fflush(stdin);
      fgets(psn.address,30,stdin);
      pos=strchr(psn.address,'\n');
      if(pos!=NULL)
      *pos='\0';
      if(strcmp(psn.address,"0")==0)
      {
          cancelRes();
          return NULL;

      }

      gotoxy(1,8);
      printf("Enter age:");
      do
      {
          fflush(stdin);
          scanf("%d",&psn.age);
          if(psn.age==0)
          {
              cancelRes();
              return NULL;
          }
          else if(psn.age<0)
          {
              displayError(11,8,"ERROR! Invalid Age");
          }

      }while(psn.age<0);

      textcolor(LIGHTRED);
      gotoxy(1,25);
      printf("PLEASE WAIT! Ticket Booking Is Under Process.....");
      sleep(2);
    return &psn;
}

int get_booked_ticket_count(char *train_no,char t_c)
{
    Passenger pr;
    int count=0;
    FILE *fp=fopen("allBookings.dat","rb");
    if(fp==NULL)
    {
        return 0;
    }
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
        if(strcmp(pr.train_no,train_no)==0&&pr.p_class==t_c)
        {
            count++;
        }
    }
    fclose(fp);
    return count;
}
int last_ticket_no()
{
    Passenger pr;
    FILE *fp=fopen("allBookings.dat","rb");
    if(fp==NULL)
    {
        return 0;
    }
    fseek(fp,-1*sizeof(pr),SEEK_END);
    fread(&pr,sizeof(pr),1,fp);
    fclose(fp);
    return pr.ticket_no;
}
  int book_ticket(Passenger p)
  {
    int ticket_count=get_booked_ticket_count(p.train_no,p.p_class);
    if(ticket_count==30)
    {
        clrscr();
        textcolor(LIGHTRED);
        gotoxy(1,1);
        printf("\nALL SEATS ARE FULL IN ");
        printf("%s %c !!!!!",p.train_no,p.p_class);
        return -1;

    }

    int ticket_no=last_ticket_no()+1;
    p.ticket_no=ticket_no;
    FILE *fp=fopen("allBookings.dat","ab");
    if(fp==NULL)
    {
        clrscr();
        gotoxy(1,1);
        textcolor(LIGHTRED);
        printf("\nSorry FILE not found");
        return -1;
    }
    fwrite(&p,sizeof(p),1,fp);
    fclose(fp);
    return ticket_no;
}

int view_ticket()
{
    int count=0,t_no,t_fare;
    char tr_class;
    Passenger pr;
    Train tr;
    FILE*fp1;
    clrscr();
    textcolor(LIGHTGREEN);
    gotoxy(50,1);
    printf("Press 0 to Exit at any point ");
    gotoxy(1,1);
    textcolor(YELLOW);

    printf("Enter Ticket No:");
    fflush(stdin);
    scanf("%d",&t_no);
    if(t_no==0)
    {
        cancellingInput();
        return 0;
    }
    printf("\nPlease Wait...");
    sleep(2);
    FILE *fp=fopen("allBookings.dat","rb");
    if(fp==NULL)
    {
        textcolor(LIGHTRED);
        printf("\n\nUnable to Check The Ticket!!!!");
        count++;
        return 0;
    }
    while(fread(&pr,sizeof(pr),1,fp))
    {
        if(pr.ticket_no==t_no)
        {
            count++;
            break;
        }
    }
    fclose(fp);
    if(count==0)
    {

        textcolor(LIGHTRED);
        printf("\n\nNo Details of Ticket No %d Found !!!!! ",t_no);
        textcolor(WHITE);
        printf("\n\n\nPress Any Key To Go To Main Menu ");
        getch();
        return 0;
    }
    fp1=fopen("allTrains.dat","rb");
    if(fp1==NULL)
    {
        textcolor(LIGHTRED);
        printf("\n\nUnable to Check The Ticket!!!!");
        textcolor(WHITE);
        printf("\n\n\nPress Any Key To Go To Main Menu ");
        getch();
        return 0;
    }
    while(fread(&tr,sizeof(tr),1,fp1))
    {
        if(strcmp(tr.train_no,pr.train_no)==0)
        {
            break;
        }

    }
    tr_class=pr.p_class;
    if(tr_class=='F')
        t_fare=tr.fac_fare;
    else if(tr_class=='S')
        t_fare=tr.sac_fare;

    gotoxy(1,4);
    textcolor(LIGHTGREEN);
    printf("\nNAME: %s",pr.p_name);
    printf("\nGENDER: %c",pr.gender);
    printf("\nTRAIN NO: %s",pr.train_no);
    printf("\nTRAVELLING CLASS: %c",pr.p_class);
    printf("\nADDRESS: %s",pr.address);
    printf("\nAGE: %d",pr.age);
    printf("\nTICKET NO: %d",pr.ticket_no);
    printf("\nFROM: %s",tr.from);
    printf("\nTO: %s",tr.to);
    printf("\nFARE: %d",t_fare);
    textcolor(WHITE);
    printf("\n\n\nPress Any Key To Go To Main Menu ");
    getch();

}

int get_ticket_no()
{
    char mobile_no[12];
    int t_no,count;
    Passenger pr;

    clrscr();
    textcolor(LIGHTGREEN);
    gotoxy(50,1);
    printf("Press 0 to Exit at any point ");
    gotoxy(1,1);
    textcolor(YELLOW);
    printf("Enter Mobile No:");
    do
    {
    fflush(stdin);
    scanf("%s",mobile_no);
    if(strcmp(mobile_no,"0")==0)
    {
        cancellingInput();
        return 0;
    }
    count=check_mobile_no(mobile_no);
    if(count==1)
       displayError(17,1,"INALID MOBILE NO");
    }while(count==1);
    gotoxy(1,4);
    textcolor(LIGHTGREEN);
    printf("TICKET NO:");
    textcolor(LIGHTMAGENTA);
    printf("\n----------");
    textcolor(YELLOW);
    FILE *fp=fopen("allBookings.dat","rb");
    if(fp==NULL)
    {
        textcolor(LIGHTRED);
        printf("\n\nUnable to Check The Ticket!!!!");
        return 0;
    }
    count=0;
    while(fread(&pr,sizeof(pr),1,fp))
    {
        if(strcmp(pr.mob_no,mobile_no)==0)
        {
            count++;
            t_no=pr.ticket_no;
            printf("\n%d",t_no);
        }
    }
    fclose(fp);
    if(count==0)
    {
    clrscr();
    gotoxy(1,1);
    textcolor(LIGHTRED);
    printf("Sorry No Tickets Booked For Mobile No %d",mobile_no);
    gotoxy(1,25);
    textcolor(WHITE);
    printf("\n\n\nPress Any Key To Go To Main Menu ");
    getch();
   return 0;
    }

    gotoxy(1,25);
    textcolor(WHITE);
    printf("\n\n\nPress Any Key To Go To Main Menu ");
    getch();
   return 0;


}












