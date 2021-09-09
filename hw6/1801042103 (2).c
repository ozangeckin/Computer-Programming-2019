#include <stdio.h>
#include <stdlib.h>


int common(int num1, int num2, int total, int i){
	int divisors[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};				//Prime numbers for factors
	int d = divisors[i];			//Factor number to look in numbers
	if(num1 <=1 || num2 <= 1)		
		return total;
	if(num1 % d == 0 && num2 % d == 0){			//If the factor number is common
		total *= d;								//Multiply it with total
		total = common(num1/d, num2/d, total, i);	//Function is called recursively
	}
	else if(num1 % d != 0 && num2 % d == 0){	//If the factor number is not common
		i += 1;
		total = common(num1, num2/d, total, i);	//Function is called recursively
	}
	else if(num1 % d == 0 && num2 % d != 0){	//If the factor number is not common
		i += 1;
		total = common(num1/d, num2, total, i);	//Function is called recursively
	}
	else{										//If the factor number is not valid
		i += 1;
		total = common(num1, num2, total, i);	//Function is called recursively
	}
	return total;
}
int mix(int ar[],int x,int a,int y)
{
	int q,t,z;
	int b1= a - x + 1;
	int b2= y - a;
	int E[b1],C[b2];// Two temporary arrays to hold the two arrays to be merged
	
	for(q=0;q<b1;q++)
	{
		E[q] = ar[x + q];
	}
	for(t=0;t<b2;t++)
	{
		C[t] = ar[a + 1 + t];	
	}
	E[q]=8888; // To mark the end of each temporary array
	C[t]=8888;

	q=0;
	t=0;
	for(z=x; z<=y; z++) { //process of combining two sorted arrays
	if(E[q]<=C[t])
	ar[z]=E[q++];
	else
	ar[z]=C[t++];
	}
	return 0;
}
void merge_sort(int ar[],int x,int y)
{
	if(x < y)
	{
		int a=x+(y-x)/2; // Same as (x+y)/2, but avoids overflow for 
		// large x and y 
		merge_sort(ar,x,a); // Sort first and second halves 
		merge_sort(ar,a+1,y);
		mix(ar,x,a,y);
	}
}
void formula(int a){
	if(a <= 1)						//If number is 0 or 1 function stops calculation
		printf("\n"); 
	else{
		if(a % 2 == 0){				//Calculation is done according to formula
			a = a / 2;
			printf(" %d", a);
			formula(a);				//Function is called recursively
		}
		else{
			a = 3*a + 1;
			printf(" %d", a);
			formula(a);				//Function is called recursively
		}
	}	
}

int equalOrNot(int a, int N, int f){
	if(a == 0)
		return 0;
	int b = a % 10;
	int i, tot = 1;
	for(i = 0; i < N; i++)
		tot = tot * b;							//Multiplying operation (N times)
	if(f == 1){									//For checking result
		tot = tot + equalOrNot(a/10, N, 0);		//Function is called recursively
		if(tot == a)
			printf("Equal\n");
		else
			printf("Not Equal\n");
		return tot;
	}
	else
		return tot + equalOrNot(a/10, N, 0);		//Function is called recursively
}

char findCapital(char* a){
	char c = a[0];			//Taking char
	if(c == '\0')			//End of string
		return '*';
	if(c >= 'A' && c <= 'Z')		//Checking if char is capital
		return c;			
	else{
		a++;
		return findCapital(a);		//If the char is not capital function is called again recursively
	}
}

int main(){
	int sel = 5;
	while(sel != 0){
		printf("Please select an option to continue: (0 to exit)\n\n");
		printf("1) Part 1\n");
		printf("2) Part 2\n");
		printf("3) Part 3\n");
		printf("4) Part 4\n");
		printf("5) Part 5\n");
		printf("Selection: ");
		scanf("%d", &sel);
		
		if(sel == 0)
			break;
		else if(sel == 1){
			int n1, n2;
			printf("First number: ");				//Numbers are taken
			scanf("%d", &n1);
			printf("Second number: ");
			scanf("%d", &n2);
			printf("Common factors of %d and %d is = %d\n", n1, n2, common(n1, n2, 1, 0));			//Function is called
		}
		else if(sel == 2){
			int array[20];
			int n,i,q;
			int size;	
			printf("Enter the length of the list: ");
			scanf("%d",&size);
			printf("Enter the elements of list: \n");			
			for(i=0;i<size;i++)
			{	
				scanf("%d",&n);
				array[i]=n;				
			}
			printf("input\n");
			for(q=0;q<size;q++){
			printf("%d ",array[q]);
			}	
			merge_sort(array,0,size);
			printf("\n");	
			printf("Output\n");
			for (q=0;q<size;q++){
			printf("%d ",array[q]);
			}	
			printf("\n");
		}
		else if(sel == 3){
			int n1, n2;
			printf("Enter number: ");		//Taking number from user
			scanf("%d", &n1);
			printf("Output: %d", n1);
			formula(n1);					//Function is called			
		}
		else if(sel == 4){
			int n1;
			printf("Enter number: ");
			scanf("%d", &n1);
			int buf = n1;
			int digit = 0;
			while(buf != 0){		//Calculating number of digits
				buf = buf / 10;
				digit += 1;
			}
			int c = equalOrNot(n1, digit, 1);	
		}
		else if(sel == 5){
			char in[50];
			char* s = in;
			printf("Enter the sentence: ");
			scanf(" %[^\n]s", in);
			int i;
			for(i = 0; i < 50; i++){
				if(in[i] == 0){
					in[i] = '\0';			//Inserting '\0' for the last element of string
					break;
				}
			}
			char c = findCapital(s);		//Function call
			if(c == '*')					//Checks the result and prints it
				printf("No capital letters!!\n");
			else
				printf("Output: %c\n", c);
		}
		else
			printf("Selection you made is not valid.\n");
	}	
}
