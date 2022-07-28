#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include "NameCard.h"

NameCard* MakeNameCard(char* name, char* phone) {
	
	NameCard* pcard = (NameCard*)malloc(sizeof(NameCard)); 
	
	strcpy_s(pcard->name, NAME_LEN, name);
	strcpy_s(pcard->phone, PHONE_LEN, phone);

	return pcard;
}

void ShowNameCardInfo(NameCard* pcard) {
	printf("Name : %s\n", pcard->name);
	printf("Phone Number : %s\n", pcard->phone);
}

int NameCompare(NameCard* pcard, char* name) {
	return strcmp(pcard->name, name);
		
}

void ChangePhoneNum(NameCard* pcard, char* phone) {
	strcpy_s(pcard->phone, PHONE_LEN, phone);
}