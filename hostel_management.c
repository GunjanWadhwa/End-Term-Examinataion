
//including header files
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//function declaration
void menu();
void new_record();
void modify();
void view_list();
void del();
void view();


//structure defination

struct hostel{
    char roll_no[10];
    char name[60];
    char sex[2];
    char age[3];
    char hostelno[5];
    char roomno[5];
    char course[20];
    char year[5];
    char allotedtill[11];
    };

struct hostel add,upd,check;

//--------------------------------------------------------------------------------------------------------------------
//main function
int main()
{ int flow=0;
  while(flow==0)
  {
	menu();
	printf("\n\nDo you wish to continue? Press 0 (zero) to Continue: ");
	scanf("%d",&flow);
  }
  return 0;
}

void menu()
{
    int choice;
    system("CLS");
    printf("\n\tHOSTEL RECORD MANAGEMENT SYSTEM");
    printf("\n\tWELCOME TO THE MAIN MENU");
    printf("\nPlease Select the desired option to proceed");
    printf("\n\t1>> Enter new Student's data");
    printf("\n\t2>> Update or Modify information of existing student");
    printf("\n\t3>> Check the details of existing account");
    printf("\n\t4>> Remove or Delete existing student information");
    printf("\n\t5>> View all students information");
    printf("\n\tPlease Enter your choice: ");

    scanf("%d",&choice);

    switch(choice)
    {

	case 1:new_record();
	break;
	case 2:modify();
	break;
	case 3:view();
	break;
	case 4:del();
	break;
	case 5:view_list();
	break;
	default:menu();
    }
}

//------------------------------------------------------------------------------------------------------------------

void new_record()
{
    FILE *ptr,*hostel;
    system("CLS");
    ptr=fopen("record.dat","a+");
    roll_no:
    printf("\n\t ADD NEW STUDENT DATA");
    printf("\n Please Enter the roll number:");
    scanf("%s",&check.roll_no);
    while(fscanf(ptr,"%s %s %s %s %s %s %s %s %s\n",add.roll_no, add.name, add.sex, add.age, add.hostelno, add.roomno, add.course, add.year, add.allotedtill)!=EOF)
    {
	if (strcmp(check.roll_no,add.roll_no)==0)
	{
		printf("\nStudents roll no. already in use!");
		goto roll_no;
	}
    }

    strcpy(add.roll_no,check.roll_no);
    printf("\nEnter the name:");
    scanf("%s",add.name);
    printf("\nEnter the Sex of Student [M or F]:");
    scanf("%s",add.sex);
    printf("\nEnter the age:");
    scanf("%s",add.age);
    printf("\nEnter the Hostel No:");
    scanf("%s",add.hostelno);
    printf("\nEnter the Room number: ");
    scanf("%s",add.roomno);
    printf("\n Enter Student Course :");
    scanf("%s",add.course);
    printf("\n Enter student's year [1st, 2nd, etc]:");
    scanf("%s",add.year);
    printf("\n Enter the date till the hostel room is alloted till \n Please enter in this format [dd/mm/yy] :");
    scanf("%s",add.allotedtill);

    fprintf(ptr,"%s %s %s %s %s %s %s %s %s\n",add.roll_no, add.name, add.sex, add.age, add.hostelno, add.roomno, add.course, add.year, add.allotedtill);
    fclose(ptr);
    printf("\nStudent added successfully!");
}

//------------------------------------------------------------------------------------------------------------------

void modify()
{
    int choice,test=0;
    FILE *old,*newrec;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");
    system("CLS");

    printf("\nEnter the roll no. of the student whose info you want to change:");
    scanf("%s",upd.roll_no);

    while(fscanf(old,"%s %s %s %s %s %s %s %s %s\n",add.roll_no, add.name, add.sex, add.age, add.hostelno, add.roomno, add.course, add.year, add.allotedtill)!=EOF)
    {
	if (strcmp(add.roll_no,upd.roll_no)==0)
	{   test=1;
	    choice_menu:
	    printf("\n\n Which part of the record do you wish to update:");
	    //printf("\n1>Name :\n2>Sex :\n3>Age :\n4>Hostel No. :\n5>Room No. :\n6>Course :\n7>Year :\n8>Date Hostel Alloted till");
	    printf("\nRoll No: %s",add.roll_no);
	    printf("\n[1] Name: %s",add.name);
	    printf("\n[2] Sex [M or F]: %s",add.sex);
	    printf("\n[3] Age: %s",add.age);
	    printf("\n[4] Hostel No: %s",add.hostelno);
	    printf("\n[5] Room number: %s",add.roomno);
	    printf("\n[6] Student Course : %s",add.course);
	    printf("\n[7] Student's year [1st, 2nd, etc]: %s",add.year);
	    printf("\n[8] Date till the hostel room is alloted [dd/mm/yy] :%s \n",add.allotedtill);
	    scanf("%d",&choice);

	    switch(choice)
		{

		case 1: printf("\nEnter the name:");
			scanf("%s",upd.name);
			fprintf(newrec,"%s %s %s %s %s %s %s %s %s\n", add.roll_no, upd.name, add.sex, add.age, add.hostelno, add.roomno, add.course, add.year, add.allotedtill);
			break;
		case 2: printf("\nEnter the Sex of Student [M or F]");
			scanf("%s",upd.sex);
			fprintf(newrec,"%s %s %s %s %s %s %s %s %s\n", add.roll_no, add.name, upd.sex, add.age, add.hostelno, add.roomno, add.course, add.year, add.allotedtill);
			break;
		case 3: printf("\nEnter the age:");
			scanf("%s",upd.age);
			fprintf(newrec,"%s %s %s %s %s %s %s %s %s\n",add.roll_no, add.name, add.sex, upd.age, add.hostelno, add.roomno, add.course, add.year, add.allotedtill);
			break;
		case 4: printf("\nEnter the Hostel No:");
			scanf("%s",upd.hostelno);
			fprintf(newrec,"%s %s %s %s %s %s %s %s %s\n",add.roll_no, add.name, add.sex, add.age, upd.hostelno, add.roomno, add.course, add.year, add.allotedtill);
			break;
		case 5: printf("\nEnter the Room number: ");
			scanf("%s",upd.roomno);
			fprintf(newrec,"%s %s %s %s %s %s %s %s %s\n",add.roll_no, add.name, add.sex, add.age, add.hostelno, upd.roomno, add.course, add.year, add.allotedtill);
			break;
		case 6: printf("\n Enter Student Course :");
			scanf("%s",upd.course);
			fprintf(newrec,"%s %s %s %s %s %s %s %s %s\n",add.roll_no, add.name, add.sex, add.age, add.hostelno, add.roomno, upd.course, add.year, add.allotedtill);
			break;
		case 7: printf("\n Enter student's year [1st, 2nd, etc]:");
			scanf("%s",upd.year);
			fprintf(newrec,"%s %s %s %s %s %s %s %s %s\n",add.roll_no, add.name, add.sex, add.age, add.hostelno, add.roomno, add.course, upd.year, add.allotedtill);
			break;
		case 8:	printf("\n Enter the date till the hostel room is alloted till \n Please enter in this format [dd/mm/yy] :");
			scanf("%s",upd.allotedtill);
			fprintf(newrec,"%s %s %s %s %s %s %s %s %s\n",add.roll_no, add.name, add.sex, add.age, add.hostelno, add.roomno, add.course, add.year, upd.allotedtill);
			break;
		default: goto choice_menu;
		}
	}
	else
	    fprintf(newrec,"%s %s %s %s %s %s %s %s %s\n",add.roll_no, add.name, add.sex, add.age, add.hostelno, add.roomno, add.course, add.year, add.allotedtill);

    }
    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("new.dat","record.dat");
    if(test!=1)
    printf("\nRecord not found!!\a\a\a");
}


//------------------------------------------------------------------------------------------------------------------

void view_list()
{   int test=0;
    FILE *view;
    view=fopen("record.dat","r");
    system("CLS");

    while(fscanf(view,"%s %s %s %s %s %s %s %s %s\n",add.roll_no, add.name, add.sex, add.age, add.hostelno, add.roomno, add.course, add.year, add.allotedtill)!=EOF)
    {
	printf("\nRoll No: %s",add.roll_no);
	printf("\nName: %s",add.name);
	printf("\nSex [M or F]: %s",add.sex);
	printf("\nAge: %s",add.age);
	printf("\nHostel No: %s",add.hostelno);
	printf("\nRoom number: %s",add.roomno);
	printf("\nStudent Course : %s",add.course);
	printf("\nStudent's year [1st, 2nd, etc]: %s",add.year);
	printf("\nDate till the hostel room is alloted [dd/mm/yy] :%s \n",add.allotedtill);
     test++;
    }
    fclose(view);
    if (test==0)
	{
	 printf("\nNO RECORDS FOUND!!\n");
	}

}

//------------------------------------------------------------------------------------------------------------------

void view()
{
    FILE *ptr;
    int test=0;
    int choice;
    system("CLS");
    ptr=fopen("record.dat","r");

    search_menu:
    printf("Do you want to check by\n1.Roll no\n2.Name\nEnter your choice:");
    scanf("%d",&choice);
    if (choice==1)
    {   printf("\n\nEnter the roll number:");
	scanf("%s",check.roll_no);
	while(fscanf(ptr,"%s %s %s %s %s %s %s %s %s\n",add.roll_no, add.name, add.sex, add.age, add.hostelno, add.roomno, add.course, add.year, add.allotedtill)!=EOF)
	{
	    if(strcmp(add.roll_no,check.roll_no)==0)
	    {
		test=1;
		printf("\nFound the Student deatails as:");
		printf("\nName: %s",add.name);
		printf("\nSex [M or F]: %s",add.sex);
		printf("\nAge: %s",add.age);
		printf("\nHostel No: %s", add.hostelno);
		printf("\nRoom number: %s", add.roomno);
		printf("\nStudent Course : %s",add.course);
		printf("\nStudent's year [1st, 2nd, etc]: %s",add.year);
		printf("\nDate till the hostel room is alloted [dd/mm/yy] :%s",add.allotedtill);
	     }
	}
    }
    else if (choice==2)
    {   printf("\n\nEnter the name:");
	scanf("%s",check.name);
	while(fscanf(ptr,"%s %s %s %s %s %s %s %s %s\n",add.roll_no, add.name, add.sex, add.age, add.hostelno, add.roomno, add.course, add.year, add.allotedtill)!=EOF)
	{
	    if(strcmp(add.name,check.name)==0)
	    {
		test=1;
		printf("\nFound the Student deatails as:");
		printf("\nName: %s",add.name);
		printf("\nSex [M or F]: %s",add.sex);
		printf("\nAge: %s",add.age);
		printf("\nHostel No: %s",add.hostelno);
		printf("\nRoom number: %s",add.roomno);
		printf("\nStudent Course : %s",add.course);
		printf("\nStudent's year [1st, 2nd, etc]: %s",add.year);
		printf("\nDate till the hostel room is alloted [dd/mm/yy] :%s",add.allotedtill);

	    }
	}
    }
     fclose(ptr);
     if(test!=1)
	printf("\nRecord not found!!");
	printf("\nEnter 0 to try search again:");
	scanf("%d",&choice);
	if (choice==0)
	{ test=0;
	  ptr=fopen("record.dat","r");
	  goto search_menu;
	}

}


//------------------------------------------------------------------------------------------------------------------

void del()
{
    FILE *old,*newrec;
    int test=0;
    system("CLS");
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");
    printf("Enter the roll no. of student whose data you want to delete:");
    scanf("%s",upd.roll_no);

    while(fscanf(old,"%s %s %s %s %s %s %s %s %s\n",add.roll_no, add.name, add.sex, add.age, add.hostelno, add.roomno, add.course, add.year, add.allotedtill)!=EOF)
    {
	  if(strcmp(add.roll_no,upd.roll_no)!=0)
	    fprintf(newrec,"%s %s %s %s %s %s %s %s %s\n",add.roll_no, add.name, add.sex, add.age, add.hostelno, add.roomno, add.course, add.year, add.allotedtill);
	  else
	    {test++;
	    printf("\nRecord  deleted successfully!\n");
	    }
	}
    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("new.dat","record.dat");
    if(test==0)
	    printf("\nRecord not found!!\a\a\a");
}
