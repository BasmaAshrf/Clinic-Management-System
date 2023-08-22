/*
 * clinic.c
 *
 *  Created on: Aug 21, 2023
 *      Author: basma ashraf
 */
//*************************************************************
//*************************link section************************
//*************************************************************
#include<stdio.h>
#include<stdlib.h>
#include"lib1.h"


//*************************************************************
//************************main section*************************
//*************************************************************
int main(){
	setvbuf(stdout,NULL,_IONBF,0);
	setvbuf(stderr,NULL,_IONBF,0);
	char feature;
	char character_user_sel;
	char your_choice;
	int index;
	patient person[100];
	int array[5]={0,0,0,0,0};
	int person_num = 0;
	int id;
	do{
		feature = 0;
		your_choice = 0;
		character_user_sel = 0;
		your_choice =admin_or_user_func(&feature );
		  if(your_choice=='b'){
			  printf("=========================================\n");
			user_features(&character_user_sel );
		}
		if(character_user_sel=='a'){
			printf("enter your ID: ");
			scanf(" %d" , &id);
			index = search ( &person  , &id , &person_num);
			if(index==-1){
				printf("this id is not exist\n");
				printf("=========================================\n");
				continue;
			}else
			display_info(&person , &index);
			printf("=========================================\n");
		}
		if(character_user_sel=='b'){
			view_reservations(array);
		}
		if(feature=='a'){
			Add_new(&person, &person_num);
			printf("you are added\n");
			printf("=========================================\n");
		}
		else if(feature=='b'){
			Edit_pat_func(&person , &id , &person_num);
		}
		else if(feature=='c'){
			Reserve_aslot_with_the_doctor(&id , array , &person, &person_num);
		}
		else if(feature=='d'){
			Cancel_reservation(&id , array);
		}
	}while(1);

}

