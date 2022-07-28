#include <stdio.h> 
#include <stdlib.h>
#include "ArrayList.h"
#define _CRT_SECURE_NO_WARNINGS

int main() {
	List list;
	LData data;
	char name[NAME_LEN];
	char compName[NAME_LEN];
	char phone[PHONE_LEN];
	char phoneToChange[PHONE_LEN];
	int mode;

	ListInit(&list);

	printf("Please enter three person's information.\n");
	for (int i = 0; i < 3; i++) {
		printf("Name : ");
		scanf_s("%s", name, NAME_LEN);
		printf("Phone Number : ");
		scanf_s("%s", phone, PHONE_LEN);
		
		data = MakeNameCard(name, phone);
		LInsert(&list, data);
	}
	do {
		printf("\n1. Print Someone's Information\n");
		printf("2. Change Someone's Information\n");
		printf("3. Delete Someone's Information\n");
		printf("4. Print All Information\n");
		printf("0. Exit\n");
		printf("-----------------------------------------\n");
		printf("Enter the mode : ");
		scanf_s("%d", &mode);
		switch (mode) {

		case 0:
			printf("Exit Program.");
			break;

		case 1:
		case 2:
		case 3:
			printf("Enter the name : ");
			scanf_s("%s", compName, NAME_LEN);
			if (LFirst(&list, &data)) {
				if (NameCompare(data, compName) == 0) {
					if (mode == 1)
						ShowNameCardInfo(data);
					else if (mode == 2) {
						printf("Enter the phone number : ");
						scanf_s("%s", phoneToChange, PHONE_LEN);
						ChangePhoneNum(data, phoneToChange);
					}
					else {
						free(LRemove(&list));
					}
				}
				while (LNext(&list, &data)) {
					if (NameCompare(data, compName) == 0) {
						if (mode == 1)
							ShowNameCardInfo(data);
						else if (mode == 2) {
							printf("Enter the phone number : ");
							scanf_s("%s", phoneToChange, PHONE_LEN);
							ChangePhoneNum(data, phoneToChange);
						}
						else {
							free(LRemove(&list));
						}
					}
				}
			}
			break;

		case 4:
			if (LFirst(&list, &data)) {
				ShowNameCardInfo(data);

				while (LNext(&list, &data)) {
					ShowNameCardInfo(data);
				}
			}
			break;

		default :
			printf("There is wrong input\n");
		}
	} while (mode != 0);

	return 0;
}