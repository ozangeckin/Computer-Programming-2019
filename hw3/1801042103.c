//OZAN GEÇKİN
#include <stdio.h>
#include <stdlib.h>

int add(int number1, int number2){
    return number1 + number2;
}
int sub(int number1, int number2){
    return number1 - number2;
}
int mul(int number1, int number2){
    return number1 * number2;
}
int divv(int number1, int number2){
    return number1 / number2;
}
int power(int number1, int number2){
    int i = 1;
    int buf = number1;
    if(number2 == 0){
		return 1;
	}
    while(i < number2){
		buf *= number1;
		i++; 
	}
	return buf;
}
int mod(int number1, int number2){
    return number1 % number2;
}

int doit(int op, int first_number, int second_number){
    switch (op){
        case 0:
            return add(first_number, second_number);
        case 1:
            return sub(first_number, second_number);
        case 2:
            return mul(first_number, second_number);
        case 3:
            return divv(first_number, second_number);
        case 4:
            return power(first_number, second_number);
        case 5:
            return mod(first_number, second_number);
    }
}

void take_grades(int a[]){
	int i;
	for(i = 0; i < 10; i = i + 1){
		printf("Enter the %dst grade: ", i+1);
		scanf("%d", &a[i]);
	}
}

void take_exam_grades(int a[]){
	printf("Enter the midterm grade: ");
	scanf("%d", &a[0]);
	printf("Enter the final grade: ");
	scanf("%d", &a[1]);
}

double calculate_homework (int a[]){
	int i;
	double sum = 0;
	for(i = 0; i < 10; i = i + 1){
		sum += a[i];
	}
	sum = sum / 10;
	return sum;
}

double calculate_lab (int a[]){
	int i;
	double sum = 0;
	for(i = 0; i < 10; i = i + 1){
		sum += a[i];
	}
	sum = sum / 10;
	return sum;
}

double calculate_all (int lab, int exam [], int homework){
	double midterm = exam[0];
	double final = exam[1];
	homework = homework * 10;
	homework = homework / 100;
	
	lab = lab * 20;
	lab = lab / 100;
	
	midterm = midterm * 30;
	midterm = midterm / 100;

	final = final * 40;
	final = final / 100;
	double total = final + midterm + homework + lab;
	
	return total;
}

int main(){
	printf("Welcome. Please choose the part from below and enter the index of it (1, 2 or 3):\n");
	int part;
	do{
		printf("1. Basic Calculator (Part1)\n2. Grade Calculator (Part2)\n3. Triangle with * (Part3)\n");
		printf("Enter the part number (enter 0 to exit): ");
		scanf("%d%*c", &part);
		if(part == 0){
			break;
		}
		else if(part == 1){
			char c[4];
			char firstt[50];
			char secondd[50];
			int first = 0, second = 0, ans = 0;
			while(1==1) {
				printf("Select an operator:\n\t+ for summation\n\t- for substraction\n\t");
				printf("* for multiplication\n\t/ for division\n\t** for power operation\n\t %% for modulation\n\t-- for exit from Part1\n");
				printf("Enter the operator ");
				fgets(c, sizeof(c), stdin);
				if(!strcmp(c, "--\n")){
					break;
				}
				
				printf("Enter the first number ");
				fgets(firstt, sizeof(firstt), stdin);
				
				printf("Enter the second number if you have done the first operation and you want to trade on the result you just need to enter enter ");
				fgets(secondd, sizeof(secondd), stdin);
				
				first = atoi(firstt);
				second = atoi(secondd);
							
				if (firstt[0] == '\n' && secondd[0] != '\n') {
					first = ans;
				}
				
				if (firstt[0] != '\n' && secondd[0] == '\n') {
					second = first;
					first = ans;
				}
			
				if(!strcmp(c, "+\n")){
					ans = doit(0, first, second);
				}
				if(!strcmp(c, "-\n")){
					ans = doit(1, first, second);
				}
				if(!strcmp(c, "*\n")){
					ans = doit(2, first, second);
				}
				if(!strcmp(c, "/\n")){
					ans = doit(3, first, second);
				}
				if(!strcmp(c, "**\n")){
					ans = doit(4, first, second);
				}
				if(!strcmp(c, "%\n")){
					ans = doit(5, first, second);
				}
				
				printf("%d\n", ans);
			}
		}
		else if(part == 2){
			int homeworks[10];
			int labgrades[10];
			int examgrades[2];
			double lab_avg, hw_avg;
			double result;
			printf("Enter homework grades\n");
			take_grades(homeworks);
			printf("Enter lab grades\n");
			take_grades(labgrades);
			printf("Enter midterm and final grades\n");
			take_exam_grades(examgrades);
			
			lab_avg = calculate_lab(labgrades);
			hw_avg = calculate_homework(homeworks);
			
			result = calculate_all(lab_avg, examgrades, hw_avg);
			printf("Result: %f\n", result);

		}
		else if(part == 3){
			int x = 0;
			printf("Enter height ");
			scanf("%d", &x);
			int i,j;
			for(i = 0; i < x; i = i + 1){
				for(j = 0; j < x - i - 1; j = j + 1){
					printf(" ");
				}
				printf("/");
				for(j = 0; j < 2*i ; j = j + 1){
					printf("*");
				}
				printf("\\");
				for(j = 0; j < x - i - 1; j = j + 1){
					printf(" ");
				}
				printf("\n");		
			}
			for(i = 0; i < x; i = i + 1){
				for(j = 0; j < i ; j = j + 1){
					printf(" ");
				}
				printf("\\");
				for(j = 0; j < 2*(x-i-1) ; j = j + 1){
					printf("*");
				}
				printf("/");
				for(j = 0; j < i; j = j + 1){
					printf(" ");
				}
				printf("\n");		
			}
		}
		else{
			printf("Invalid part number\n");
		}
	
	}while(part != 0);
	
}
