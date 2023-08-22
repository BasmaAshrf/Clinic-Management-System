/*
 * lib1.h
 *
 *  Created on: Aug 21, 2023
 *      Author: basma ashraf
 */

#ifndef LIB1_H_
#define LIB1_H_

typedef struct patient{
	char name[30];
	int age;
	char gender;
	int ID;
} patient;

char admin_or_user_func(char *feature);
void password_func(char *feature );
void admin_features_list(char *feature);
void Add_new(patient * person , int *person_num);
void Edit_pat_func(struct patient *person , int *id , int *person_num);
int search (struct patient *person  , int *id , int *person_num);
void display_info(struct patient *person , int *index);
void edit_info(struct patient *person , int *index);
void Reserve_aslot_with_the_doctor(int *id , int *array , patient * person , int *person_num);
void Cancel_reservation(int *id , int *array);
void user_features(char *character_user_sel );
void view_reservations(int *array);


#endif /* LIB1_H_ */
