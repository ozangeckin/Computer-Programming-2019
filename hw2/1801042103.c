#include<stdio.h>
#include<time.h>
#include<stdlib.h>
//I defined the functions I used below
void draw_hourglass(int height);
int make_a_guess(int trial,int min,int max);
void show_scores(int score_human,int score_program);
void draw_mountain_road(int length,int max_radius);
//I made a menu using the do while loop and this menu does not close until the 4 is pressed
void menu(){
	int choice;
	int height;
	int trial,min,max,length,max_radius;
do{
	printf("***** MENU *****\n");
	printf("1. Play Lucky Number\n");
	printf("2. Draw Hourglass\n");
	printf("3. Draw Mountain Road\n");
	printf("4. Exit\n");
	printf("Choice:\n");
	scanf("%d",&choice);
		switch(choice){
				case 1:
						printf("welcome to play lucky number\n");
						make_a_guess(trial,min,max);
						break;
				case 2:
						printf("welcome to draw hourglass\n");
						scanf("%d",&height);
						draw_hourglass(height);
						break;
				case 3:
							  draw_mountain_road(length,max_radius);					
						break;				
				case 4:
						
						printf("Exiting..\n");
						break;
						
				default:
						printf ("This is an invalid choice.Try again\n");
						break;
						
					}
			
		}while(choice!=4);
}
int count;
int count2;
int count3;

int make_a_guess(int trial,int min,int max){

	trial=1;	
	min=0;
	max=1024;
//program sets a random number between 0 and 1024.
	int LN=rand()%1024+1;
	int GN;
//Dear teacher,If you want to change the trial right you can do it by changing the following 11
	while(trial!=11){
//In lucky number, the game shows us the number of attempts and the range.
	printf("(Trial: %d)Make a guess between %d and %d:",trial,min,max);
	
	scanf("%d",&GN);
	
	while(GN<min || GN>max){
	//check whether the entered numbers are in range and alert

		printf("please enter a number between %d and %d:",min,max);
		scanf("%d",&GN);
	}
		int Distance;
		if(LN>GN){
				min=GN;
				Distance=LN-GN;			
			}
			else{
				max=GN;
				Distance=GN-LN;
			}
		
			if(Distance>=512&&Distance<=1023){
			printf("Distance:10\n");
			
			}
			else if(Distance>=256&&Distance<=511){
			printf("Distance:9\n");
			
			}
			else if(Distance>=128&&Distance<=255){
			printf("Distance:8\n");
			
			}
			else if(Distance>=64&&Distance<=127){
			printf("Distance:7\n");
			
			}
			else if(Distance>=32&&Distance<=63){
			printf("Distance:6\n");
			
			}
			else if(Distance>=16&&Distance<=31){
			printf("Distance:5\n");
			
			}
			else if(Distance>=8&&Distance<=15){
			printf("Distance:4\n");
			
			}
			else if(Distance>=4&&Distance<=7){
			printf("Distance:3\n");
		
			}
			else if(Distance>=2&&Distance<=3){
			printf("Distance:2\n");
			
			}
			else if(Distance==1){
			printf("Distance:1\n");
		
			}
			else if(Distance==0){
			printf("Distance:0.You Win!");
			count++;
			break;
			}
		
		trial++;
		}
		count2++;
	show_scores(count,count2);
	
}
	
			
void show_scores(int score_human,int score_program){
//stores counts of counts throughout the program.


		if(count2>count){
			count3=count2-count;
		}
		else if(count2<count){
			count3=count-count2;
		}
		printf("\nYour Source:%d Program Score:%d\n\n",count,count3);
}
	

void draw_hourglass(int height){

int spacenumber,starnumber,i,j;
//ıt warns against even numbers, and ıt wants an odd number again.

	while(height%2==0){
		printf("please enter single number:");
		scanf("%d",&height);
	}
		if(height%2!=0){
			

    spacenumber = 0;
    

    starnumber = height;
    

    for(i=0; i<height; i++){
        

        for(j=0; j<starnumber;j++)
            printf("*");        
 

        if( i < (height / 2) ){
            starnumber-=2;
            spacenumber++;
    
	    }
            

        else{
            starnumber+=2;
            spacenumber--;
        }
 
        printf("\n");
        for(j=0; j<spacenumber;j++)    
            printf(" ");
        
    }	
		}
		printf("\n");
}
int mountain_for_even(int max_r,int space){//sola yatık
	int i,j,r;
	r=rand()%max_r;
	space=max_r;
	
	for(j=0;j<=r;j++){
		for(i=0;i<space;i++)
			printf(" ");
		printf("/\n");
		space--;
	}
	for(i=0;i<space;i++)
		printf(" ");
	printf("|\n");
	space++;
	for(j=0;j<=r;j++){
		for(i=0;i<space;i++)
			printf(" ");
		printf("\\\n");
		space++;
	}
	return space;
}
int mountain_for_odd(int max_r,int space){//sağa yatık
	int i,j,r;
	r=rand()%max_r;

	for(j=0;j<=r;j++){
		for(i=0;i<space;i++)
			printf(" ");
		printf("\\\n");
		space++;
	}
	for(i=0;i<space;i++)
		printf(" ");
	printf("|\n");
	space--;
	for(j=0;j<=r;j++){
		for(i=0;i<space;i++)
			printf(" ");
		printf("/\n");
		space--;
	}
	return space;
}

void draw_mountain_road(int length,int max_radius){
	int i,j,n,max_r,space=0;
	printf("Length: "); scanf("%d",&n);
	printf("max radius: "); scanf("%d",&max_radius);	

	for(i=0;i<n;i++){
		if(i%2==0)
			space=mountain_for_even(max_radius,space);
		
		else
		space=mountain_for_odd(max_radius,space);
	}
}

	
int main(){
	menu();
	srand(time(NULL));
	
	return 0;
}
