/*
 ============================================================================
 Name        : linked_list.c
 Author      : AHMED SHABAN
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <string.h>
#include <conio.h>
struct sstudent*gpstudent=NULL;

char temp_text [40];
//efective data
struct sdata {
	int id;
	char name[40];
	float heigth;
};
//linked_list  componation
struct sstudent {
	struct sdata student;
	struct sstudent*pnextstudent;                                         //pointer refer to address that use to link the data
};
//struct sstudent*gpstudent=NULL;                                       //pointer refer to the record
//APIS
// funcation add student
void add_student()
{        struct sstudent *pnewstudent;                          //local ponter refer to the new list
struct sstudent *plaststudent;                         // local poiner refer to the last list make
//check if list is empty
if(gpstudent==NULL)
{
	//create new recorde
	pnewstudent= (struct sstudent *) malloc (sizeof(struct sstudent));
	//set the pointer that refer to list to a newlist that create
	gpstudent=pnewstudent ;
}
else
{
	plaststudent=gpstudent ;
	//loop until go to the last list
	while (plaststudent->pnextstudent)
		plaststudent=plaststudent->pnextstudent;
	//create new recorde
	pnewstudent= (struct sstudent *) malloc (sizeof(struct sstudent));
	//make the pnewstudent  address refer to the plaststudent
	plaststudent->pnextstudent=pnewstudent;
}
//enter student data
printf("\t enter student data:\n")  ;
printf("\t enter student ID:\n")  ;
gets(temp_text);
pnewstudent->student.id=atoi(temp_text);
printf("\t enter student name :\n")  ;
gets(pnewstudent->student.name);
printf("\t enter student heigth :\n")  ;
gets(temp_text);
pnewstudent->student.heigth=atof(temp_text);
pnewstudent->pnextstudent=NULL;
}

//founcation to deleat list in the data
int deleat()
{
	char temp_text [40];
	int selected_id;
	printf("please enter the ID number of the student you want to deleat from the data base \n");
	gets(temp_text);
	selected_id =atoi(temp_text);
	if(gpstudent)
	{
		struct sstudent *pprestudent=NULL;                          //local ponter refer to the new list
		struct sstudent *pselcstudent=gpstudent;
		while(pselcstudent)
		{
			if(pselcstudent-> student.id == selected_id)
			{
				pprestudent-> pnextstudent =pselcstudent-> pnextstudent ;
			}
			else
			{
				gpstudent=pselcstudent-> pnextstudent;
			}
			free(pselcstudent);
			return 1 ;
		}
		pprestudent=pselcstudent;
		pselcstudent=pselcstudent->pnextstudent;
	}
	printf("\t sorry i can not find the student \n") ;
}

//printf("\t sorry i can not find the student \n") ;
//return 0 ;
void print_list()
{
	struct sstudent *pcurrentlist=gpstudent;
	int count=0;
	if(gpstudent==NULL)
		printf("empty list \n");
	else
	{
		while (pcurrentlist)
		{
			printf("student data %d\n",count+1);
			printf(" \t student id %d \n" ,pcurrentlist->student.id);
			printf(" \t student name %s \n" ,pcurrentlist->student.name);
			printf(" \t student hiegth %f \n" ,pcurrentlist->student.heigth);
			pcurrentlist=pcurrentlist->pnextstudent;
			count++;
		}
	}


}
void delet_all()
{
	struct sstudent *pcurrentlist=gpstudent;
	int count=0;
	if(gpstudent==NULL)
		printf("empty list \n");
	else
	{
		while (pcurrentlist)
		{
			struct sstudent *ptrmpstudent=pcurrentlist;
			pcurrentlist=  pcurrentlist->pnextstudent;
			free(ptrmpstudent);
		}
		gpstudent=NULL;
	}


}

int main()
{

	char  temp_text [40];
	while(1)
	{
		printf("============================================================================================================================\n");
		printf("chose one of the follwing optation\n");
		printf("add student data :1\n");
		printf("delate student data :2\n");
		printf("view student:3\n");
		printf("delete all:4=\n");
		gets(temp_text);
		printf("================================================================================================================\n");
		switch(atoi(temp_text))
		{
		case 1:

			add_student();
			break;

		case 2:

			deleat();
			break ;
		case 3:

			print_list();
			break ;
		case 4:

			delet_all();
			break ;
		default :
			printf("wrong option");
			break ;
		}

	}
}

