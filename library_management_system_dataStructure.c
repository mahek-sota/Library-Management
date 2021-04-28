#include<stdio.h>

#include<ctype.h>

#include<string.h>

#include<stdlib.h>





void Addbook();

void Searchbook();

void Displaybook();

void Addmembr();

void Exit();

char info[500];





struct

{

  int bid;

  char bname[25] ;

  char author[25];

}book;

struct

{

  int mid;

  char mname[25] ;

  char department[25];

  double phno;

}membr;

//initializing the files used in the program

FILE *librecord;

FILE *membrrecord;

int main()

{

    int choice=0,i;



    printf("\n\t\t<<LIBRARY MANAGEMENT SYSTEM>>\n");

    do{

    printf("\n\t~~MENU~~\n 1> Add A New Book\n 2> Search a book \n 3> Display Complete Information\n 4> Add A New Member\n 5> Exit the program\n\n\t Enter your choice <1-5>: ");

    scanf("%i",&choice);





    switch (choice)

    {

        case 1:

            Addbook();

            break;

        case 2:

            Searchbook();

            break;

        case 3:

            Displaybook();

            break;

        case 4:

            Addmembr();

            break;

        case 5:

            Exit();

        default:

            printf(" ! Invalid Input...\n");

    }

}while(choice!=5);

 return (0);

}



void Addbook()

{

    int i;

    librecord = fopen("librecord.txt","a+");

    printf("Enter The bookid :(Integer) \n");

        scanf("%d",&book.bid);

    printf("Enter The Name of The Book :\n");

        scanf("%s",book.bname);

    printf("Enter The Name of Author :\n");

        scanf("%s",book.author);

    fprintf(librecord,"\n%d\t%s\t%s",book.bid,book.bname,book.author);

    fclose(librecord);

    printf(" (' ' ) A New Book has been Added Successfully...\n");

}

void Displaybook()

{

    librecord = fopen("librecord.txt","a+");

    printf("\nBookid\tName\tAuthor\t",info);

    do

    {

        fgets(info,500,librecord);

        printf("%s\n",info);

    }while(!feof(librecord));

    fclose(librecord);

    membrrecord = fopen("membrrecord.txt","a+");

    printf("\nStudent id\t Student Name\t Dept\t Ph.no\n");

    do

    {

        fgets(info,500,membrrecord);

        puts(info);

    }while(!feof(membrrecord));

    fclose(membrrecord);



}

void Searchbook()

{



    char Target[25];

    int Found=0;

    if((librecord=fopen("librecord.txt","r"))==NULL)

        printf(" ! The File is Empty...\n\n");

    else

    {

        printf("\nEnter The Name Of Book : ");

            scanf("%s",Target);

        while(!feof(librecord)&& Found==0)

        {

        fscanf(librecord,"%d %s %s", &book.bid,book.bname,book.author);

            if(strcmp(Target,book.bname)==0)

                Found=1;

            else

            {

                Found=0;

            }

            

        }

        if(Found==1)

        {

            printf("\nThe Unique ID of The Book:  %d\nThe Name of Book is:  %s\nThe Author is:  %s\n\n",book.bid,book.bname,book.author);

            }

        else if(Found==0)

            printf("! There is no such Entry...\n");

        fclose(librecord);

    }



}



void Addmembr()

{

    int i;



    membrrecord = fopen("membrrecord.txt","a+");

    printf("Enter The userid of the Member(Integer) :\n");

        scanf("%d",&membr.mid);

    printf("Enter The Name of the Member :\n");

        scanf("%s",&membr.mname);

    printf("Enter The Department\n");

        scanf("%s",&membr.department);

    printf("Enter The phone number of the member:\n");

        scanf("%lf",&membr.phno);



    fprintf(membrrecord,"\n%d\t%s\t%s\t%lf",membr.mid,membr.mname,membr.department,membr.phno);

    fclose(membrrecord);

    printf("\n (' ') Added  A New member Successfully...\n");





}

void Exit()

{

  exit(0);

}

