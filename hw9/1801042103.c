#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 40


struct person{
 char name[SIZE];
 char surname[SIZE];
 char musical_Work[SIZE];
 int age;
 struct person *next;
}*top=NULL;//son personun nexti null'ı göstermeli.Döngüler için
int stack_size=0;

void addNode(char name[], char surname [], char creation [], int age)
{
	struct person *new_node=(struct person*)malloc(sizeof(struct person));
	strcpy(new_node->name,name);
	strcpy(new_node->surname,surname);
	strcpy(new_node->musical_Work,creation);
	new_node->age=age;
	new_node->next=top;
	top=new_node;//Top artık en son eklenen node.
	stack_size++;	
}
void deleteNode()
{
	if(stack_size==0)
	{
		printf("STACK IS EMPTY\n");
	}
	struct person *delete_node=top;
	top=top->next;//Top artık silinenin bir yanındaki
	free(delete_node);//Memory_leakingi önlemek için..
	stack_size--;
}
void print()
{
	struct person *pilot=top;
	int count=1;
	while(pilot!=NULL)//En başta Top'a null demiştik.işte bu yüzden
	{
		printf("%d) %s\n",count,pilot->name);
		printf("%s\n",pilot->surname);
		printf("%s\n",pilot->musical_Work);
		printf("%d\n",pilot->age);
		count++;
		pilot=pilot->next;
	}
}
void print_stack()
{
	struct person *pilot=top;
	while(pilot!=NULL)
	{
		printf("%s\n",pilot->name);
		printf("%s\n",pilot->surname);
		printf("%s\n",pilot->musical_Work);
		printf("%d\n",pilot->age);
		pilot=pilot->next;
	}
}
 
int Sort_Increasingly()
{
	struct person *pilot;
	struct person *p1,*p2;
	struct person **head=&top;
	char temp[SIZE];
	int i,j,swap,tempp;
	for(i=0;i<=stack_size;i++)
	{
		pilot=*head;
		swap=0;
		for(j=0;j<stack_size-i-1&&pilot->next!=NULL;j++)
		{
			p1=pilot;
			p2=p1->next;
			if(p1->age>p2->age)
			{
				strcpy(temp,p1->name);
				strcpy(p1->name,p2->name);
				strcpy(p2->name,temp);
				strcpy(temp,p1->surname);
				strcpy(p1->surname,p2->surname);
				strcpy(p2->surname,temp);
				strcpy(temp,p1->musical_Work);
				strcpy(p1->musical_Work,p2->musical_Work);
				strcpy(p2->musical_Work,temp);
				tempp=p1->age;
				p1->age=p2->age;
				p2->age=tempp;
				swap=1;
				
					
			}
			pilot=pilot->next;
			
		}
		if(swap==0)//Değişim yoksa..
			break;
		
	}
}
int Sort_Alphabetically()
{
	struct person *pilot;
	struct person *p1,*p2;
	struct person **head=&top;
	char temp[SIZE];
	int i,j,swap,tempp;
	for(i=0;i<=stack_size;i++)
	{
		pilot=*head;
		swap=0;
		for(j=0;j<stack_size-i-1&&pilot->next!=NULL;j++)
		{
			p1=pilot;
			p2=p1->next;
			if(strcmp(p1->name,p2->name)>0)
			{
				strcpy(temp,p1->name);
				strcpy(p1->name,p2->name);
				strcpy(p2->name,temp);
				strcpy(temp,p1->surname);
				strcpy(p1->surname,p2->surname);
				strcpy(p2->surname,temp);
				strcpy(temp,p1->musical_Work);
				strcpy(p1->musical_Work,p2->musical_Work);
				strcpy(p2->musical_Work,temp);
				tempp=p1->age;
				p1->age=p2->age;
				p2->age=tempp;
				swap=1;
				
					
			}
			pilot=pilot->next;
			
		}
		if(swap==0)//Değişim yoksa..
			break;
		
	}
}



int main()
{
	char name[SIZE],surname[SIZE],musical[SIZE],temp;
	int selection,age;
	
	while(selection!=5)
	{
		printf("****MENU****\n");
		printf("	1- Add a Person to the Stack\n");
		printf("	2- Pop a Person from the Stack\n");
		printf("	3- Sort in Alphabetical Order\n");
		printf("	4- Sort Age in Increasing Order\n");
		printf("	5- Exit menu\n");
		printf("*************\n\n");
		printf("Select your Choise: ");
		scanf("%d",&selection);
		scanf("%c",&temp);
		switch(selection)
		{
			case 1:
				printf("Name: ");
				scanf("%[^\n]s",name);
				scanf("%c",&temp);
				printf("Surname: ");
				scanf("%[^\n]s",surname);
				scanf("%c",&temp);
				printf("Creation: ");
				scanf("%[^\n]s",musical);
				scanf("%c",&temp);
				printf("Age: ");
				scanf("%d",&age);
				
				
				addNode(name,surname,musical,age);
				printf("----\n");
				print();
				break;
			case 2:
				deleteNode();
				print();
				break;
			case 3:
				Sort_Alphabetically();
				print_stack();
				break;
				
			case 4:
				Sort_Increasingly();
				print_stack();
				break;
			case 5:
				break;
			
			
			default:
				break;
				
				
				
				
				
		}
		
	}
	
	

}


