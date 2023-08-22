/*
 * lib1.c
 *
 *  Created on: Aug 21, 2023
 *      Author: basma ashraf
 */

#include <stdio.h>
#include"lib1.h"

char admin_or_user_func(char *feature ){//to choose admin or user
	char your_choice;
	do{
	printf("a.admin\n");
	printf("b.user\n");
	printf("select your choice:");
	scanf(" %c" , &your_choice);
	if((your_choice=='a')||(your_choice=='A')){
		password_func(feature);
	}
	}while((your_choice != 'a')&&(your_choice != 'b'));
	return your_choice;
}

void password_func(char *feature ){//the passward should admin enter , the user does not enter a passward
	int pass;
	int password=1234;
	int n=0;
	do{
		printf("enter your password:");
		scanf(" %d" , &pass);
		n++;
		printf("=========================================\n");

	}while((pass != password) && (n<3));

	if(n==3){
		printf("close program\n\n");// a condition if the admin entered the password three times incorrectly
		admin_or_user_func(feature);
	}else{
		admin_features_list(feature);
	}
}

void admin_features_list(char *feature){// function for admin to choose what he wants to do
	do{
	printf("\n select your choice:\n");
	printf("a.Add new patient record\n");
	printf("b.Edit patient record\n");
	printf("c.Reserve a slot with the doctor\n");
	printf("d.Cancel reservation.\n");
	printf("your answer:");
	scanf(" %c" , feature);
	printf("=========================================\n");
	}while(!(*feature >= 'a' && *feature <= 'd'));
}

void Add_new(patient * person , int *person_num){//function to add patient
	char flag;
	printf("enter information\n");
	printf("Name: ");
	scanf(" %s" , person[*person_num].name);
	printf("age: ");
	scanf(" %d" , &(person[*person_num].age));
	printf("gender: ");
	scanf(" %c" , &(person[*person_num].gender));
	do{
	printf("ID: ");
	scanf(" %d" , &(person[*person_num].ID));
	flag = search (person  , &(person[*person_num].ID) , person_num);
	if(flag != -1)
		printf("this ID is already exist\n");
	}while(flag != -1);
	(*person_num)++;
}

void Edit_pat_func(patient * person , int *id , int *person_num){//function to edit patient information
	int num_in_database;
	printf("enter id:");
	scanf("%d" , id);
	num_in_database = search (person  , id , person_num);
	if(num_in_database != -1){
		display_info(person, &num_in_database);
		edit_info(person,&num_in_database);
	}else{
		printf("incorrect ID");
		printf("=========================================\n");
	}
}


int search (patient * person  , int *id , int *person_num){//function to search if the id exists or not
	for(int i= 0 ; i < (*person_num) ; i++){
		if(person[i].ID == *id){
			return i;
		}
	}
	return -1;
}

void display_info(patient * person , int * index){//function to display patient info
	printf("Name: %s\n" , person[*index].name);
	printf("Age: %d\n" , person[*index].age);
	if(person[*index].gender == '0')
		printf("gender: Male\n");
	else
		printf("gender: Female\n");
	printf("ID: %d\n" , person[*index].ID);
}


void edit_info(patient * person , int * index){
	printf("enter information to edit\n");
	printf("Name: ");
	scanf(" %s" , person[*index].name);
	printf("age: ");
	scanf(" %d" , &(person[*index].age));
	printf("gender: ");
	scanf(" %c" , &(person[*index].gender));
	printf("=========================================\n");

}
void Reserve_aslot_with_the_doctor(int *id , int *array , patient * person , int *person_num){//functio to reserve a slot with doctor
	char reserve;
	char flag;
	do{
	printf("the available slots:\n");
	if(array[0]==0)
		printf("a.2pm to 2:30pm\n");
	if(array[1]==0)
		printf("b.2:30pm to 3pm\n");
	if(array[2]==0)
		printf("c.3pm to 3:30pm\n");
	if(array[3]==0)
		printf("d.4pm to 4:30pm\n");
	if(array[4]==0)
		printf("e.4:30pm to 5pm\n");
	if((array[0] !=0 ) && (array[1]!=0) && (array[2]!=0) &&( array[3]!=0) && (array[4]!=0)){
		printf("now time available");}
	printf("choose slot:");
	scanf(" %c" , &reserve);
	printf("enter ID: ");
	scanf(" %d" , id);
	printf("=========================================\n");
	flag = search (person  , id , person_num );
		if(flag == -1){
			printf("this id is not exist\n");
			printf("=========================================\n");
			return;
		}
		else{

		}
	if(reserve=='a')
		array[0] = *id;
	if(reserve=='b')
		array[1]=*id;
	if(reserve=='c')
		array[2]=*id;
	if(reserve=='d')
		array[3]=*id;
	if(reserve=='e')
		array[4]=*id;
	}while(!(reserve >= 'a' && reserve <= 'e'));
}
void Cancel_reservation(int *id , int *array){//to cancel reservation with doctor
	int i;
	printf("enter id to cancel reservation:\n");
	scanf(" %d" , id);
	for(i=0 ; i<5 ; i++){
		if(*id==array[i]){
			array[i]=0;
			return;
		}
	}
	if(i == 5)
		printf("this ID did not reserve");
}
void user_features(char *character_user_sel ){
	do{
	printf("choose what you want\n");
	printf("a.View patient record\n");
	printf("b.View today’s reservations\n");
	printf("your answer:");
	scanf(" %c" , character_user_sel);
	if((*character_user_sel != 'a')&&( *character_user_sel!= 'b')){
		printf("wrong character!!!\n");
	}
	printf("=========================================\n");
	}while((*character_user_sel != 'a')&&( *character_user_sel!= 'b'));
}
void view_reservations(int *array){
	printf("a.2pm to 2:30pm : %d\n" , array[0]);
	printf("b.2:30pm to 3pm : %d\n" , array[1]);
	printf("c.3pm to 3:30pm : %d\n" , array[2]);
	printf("d.4pm to 4:30pm : %d\n" , array[3]);
	printf("e.4:30pm to 5pm : %d\n" , array[4]);
	printf("=========================================\n");
}

