#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "CLinkedList.h"


Data WhoIsNext(List * plist, char name[], int cycle) {

	Emp * empData;
	int i;

	if (LFirst(plist, &empData)) {
		if (plist->cur->data->name == name) {
			for (i = 0; i < cycle; i++) {
				LNext(plist, &empData);
			}
		}
		else {
			while (LNext(plist, &empData)) {
				if (plist->cur->data->name == name){
					for (i = 0; i < cycle; i++) {
					LNext(plist, &empData);
					}
				}
			}
		}
	}
	return empData;
}



int main()
{

	List list;
	int i;
	Emp * data;
	ListInit(&list);
	char name[10];
	int cycle;
	Emp * answer;


	Emp * emp1 = (Emp*)malloc(sizeof(Emp));
	strcpy(emp1->name, "Federer");
	emp1->empNum = 1;

	Emp * emp2 = (Emp*)malloc(sizeof(Emp));
	strcpy(emp2->name, "Nadal");
	emp2->empNum = 2;

	Emp * emp3 = (Emp*)malloc(sizeof(Emp));
	strcpy(emp3->name, "Djokovic");
	emp3->empNum = 3;

	Emp * emp4 = (Emp*)malloc(sizeof(Emp));
	strcpy(emp4->name, "Murray");
	emp4->empNum = 4;

	LInsert(&list, emp1);
	LInsert(&list, emp2);
	LInsert(&list, emp3);
	LInsert(&list, emp4);



	if (LFirst(&list, &data)) {
		printf("name:%s, number:%d \n", data->name, data->empNum);

		for (i = 0; i < LCount(&list)*3 - 1; i++) {
			if (LNext(&list, &data))
				printf("name:%s, number:%d \n", data->name, data->empNum);
		}
	}
	printf("\n");

	printf("이름과 숫자를 입력하시오");
	scanf("%s %d", name, &cycle);

	answer = WhoIsNext(&list, name, cycle);

	printf("%d일 뒤에 서야하는 사람은 :%s",cycle, answer->name);

	LRemove(&list);


	return 0;

}