#include "contact.h"

void menu()
{
	printf("############################################\n");
	printf("## 1. add                      2. delete  ##\n");
	printf("## 3. sort                     4. search  ##\n");
	printf("## 5. list                     6. empty   ##\n");
	printf("##                             0. exit    ##\n");
	printf("############################################\n");
	printf("Please Enter: ");
}
void enterPeople(people_p p)
{
	printf("Please Enter Your Name: ");
	scanf("%s", p->name);

	printf("Please Enter Your Sex<m,w>: ");
	scanf(" %c", &(p->sex));

	printf("Please Enter Your Age: ");
	scanf("%d", &(p->age));

	printf("Please Enter Your Telphone: ");
	scanf("%s", p->telphone);

	printf("Please Enter Your Address: ");
	scanf("%s", p->address);
}


int main()
{
	int select = 0;
	int quit = 0;

	contact_p ct = initContact(CONTACT_FILE);
	people_t p_;
	char name_[NAME_SIZE];

	while (!quit){
		menu();
		scanf("%d", &select);
		switch (select)
		{
		case 0:
			quit = 1;
			save(ct, CONTACT_FILE);
			break;
		case 1:
			enterPeople(&p_);
			addPeople(&ct, &p_);
			break;
		case 2:
			printf("Please Enter Name For Delete: ");
			scanf("%s", name_);
			deletePeople(ct, name_);
			break;
		case 3:
			sortContact(ct);
			break;
		case 4:
			printf("Please Enter Name For Search: ");
			scanf("%s", name_);
			searchPeople(ct, name_);
			break;
		case 5:
			listPeople(ct);
			break;
		case 6:
			clearContact(ct);
			break;
		default:
			printf("select error, try again!\n");
			break;
		}
	}
	printf("bye bye!\n");
	system("pause");
	return 0;
}