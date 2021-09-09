#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#define PI 3
#define SQUARE 1
#define RECTANGULAR 2
#define CIRCULAR 3
#define RED 0
#define YELLOW 1
#define BLUE 2
#define	BLACK 3
#define WHITE 4
/* I've defined the terms I'll use in my code above*/
double CreateBody(int shape){
/*According to main the shape selaction if enters the match and calculates the size of the shape*/	
	float size;	
	int a,b;
	if(shape==SQUARE){
		printf("please enter a side length of the frame ");
		scanf("%d",&a);
		size=a*a;		
	}
	
	if(shape==RECTANGULAR){
		printf("please enter the edge lengths of the rectangle");
		scanf("%d",&a);
		printf("please enter the edge lengths of the rectangle");
		scanf("%d",&b);
		size=a*b;
	}
	if(shape==CIRCULAR){
		printf("please enter the radius of the circle");
		scanf("%d",&a);
		size=PI*a*a;
	}
	return size;
}
int SetColor(int color){
/* 0 is smaller than 0 and a large value of 1000 is returned */
	int color1,result;
	if (color<0 && color>1000){
		return 1;
	}
/*takes the value of the entered value according to the 5 and makes the color assignment according to the result*/
	result=color%5;
	if(result==0){
		color1=RED;
	}
	if(result==1){
		color1=YELLOW;
	}
	if(result==2){
		color1=BLUE;
	}
	if(result==3){
		color1=BLACK;
	}
	if(result==4){
		color1=WHITE;
	}
	return color1;
}
double LoadMoves(int shape,double body_size){
/*in this function, I found their environment from the size of shapes*/	
	int length,edge_size,radius;
	if(shape==SQUARE){
/*I have found the edge length of the square based on the value we create from the create body function with the sqrt function defined in the math.h library*/
		edge_size=sqrt(body_size);
		length=4*edge_size;		
	}
	if(shape==RECTANGULAR){
		edge_size=body_size/5;
		length=2*(edge_size+5);	
	}
	if(shape==CIRCULAR){
		radius=sqrt((body_size/PI));
		length=2*PI*radius;
	}
	return length;
}
int SetAttackPower(int lower_bound,int upper_bound){
/*assigns random values between lower_bound and upper_bound using defined functions in time.h and stdlib.h*/
	int attack_power;
	srand(time(NULL));
	attack_power=(rand()%(upper_bound-lower_bound+1))+lower_bound;
	return attack_power;
}
void ShowPokemon(int shape,double body_size,int color,double move_length,int attack_power){
/*values and figures received in previous functions are printed in this function*/	
	
	int lower_bound,upper_bound;
	if(shape==SQUARE){
	int i=0;
	int j=0;	
		int	edge_size=(move_length/4);
		 for(i=0;i<edge_size;i++){ //her satir icin
       		for(j = 0;j<edge_size;j++){ // boyut kadar yildiz bas
          	printf("X");
       }
       printf("\n"); // alt satira gec
    }
    printf("Name= Square Pokemon\n");
	printf("Size:%lf\n",body_size);
	if(color==0){
	printf("Color:RED\n");	
	}
	if(color==1){
	printf("Color:YELLOW\n");	
	}
	if(color==2){
	printf("Color:BLUE\n");	
	}
	if(color==3){
	printf("Color:BLACK\n");	
	}
	if(color==4){
	printf("Color:WHITE\n");	
	}
	
	printf("Move:%lf\n",move_length);	
	printf("Attack Power:%d\n",attack_power);
	}
	if(shape==RECTANGULAR){
		int edge_size1=((move_length/2)-5);
		int k,l;
	for(k = 0;k<edge_size1;k++){ //her satir icin
       	for(l = 0;l<5;l++){ // boyut kadar yildiz bas
          printf("X");
        }
       printf("\n"); // alt satira gec
    	}
    	printf("Name= Rectangular Pokemon\n");
	printf("Size:%lf\n",body_size);
	if(color==0){
	printf("Color:RED\n");	
	}
	if(color==1){
	printf("Color:YELLOW\n");	
	}
	if(color==2){
	printf("Color:BLUE\n");	
	}
	if(color==3){
	printf("Color:BLACK\n");	
	}
	if(color==4){
	printf("Color:WHITE\n");	
	}
	printf("Move:%lf\n",move_length);	
	printf("Attack Power:%d\n",attack_power);

	}
	if(shape==CIRCULAR){
	int i,space,star=0,count=1;
	int radius=move_length/(2*PI);
	if(radius%2!=0){

	radius=radius-(radius-1)/2;
	
	 /* Printing upper triangle */
    	for(i = 1; i <= radius; i++) {
        /* Printing spaces */
       		 for(space = 1; space <= radius-i; space++) {
           printf("\t");
        }
        /* Printing stars */
        	while(star != (2*i - 1)) {
			
         	if(star == 0 || star==2*i-2) {
                printf("X");
		printf("\t");
      		}
		else {
                printf("\t");
        	 }

  		 star++;
       		}
        	star=0;
       		 /* move to next row */
       		 printf("\n");
        	count++;
        
			
			
   	 }
   
    	radius--;
    	/* Printing lower triangle */
    	for(i = radius;i >= 1; i--) {
        /* Printing spaces */
       		 for(space = 0; space <= radius-i; space++) {
           printf("\t");
        }
        /* Printing stars */
        star = 0;
       		 while(star != (2*i - 1)) {

         	if(star == 0 || star==2*i-2)
                printf("X\t");
		
           	 else
                printf("\t");
            	star++;
        
	
		}
        
       		 printf("\n");
        	 count++;
   	
    		}
	}
	radius=move_length/(2*PI);
	if(radius%2==0){
		
	radius=((radius/2)+1);
	
	 /* Printing upper triangle */
   	for(i = 1; i <= radius; i++) {
        /* Printing spac{es */
       		 for(space = 1; space <= radius-i; space++) {
       
	      	 printf("\t");
	      
       		 }
        
        if(count==2){
        	  while(star != (2*i - 1)) {
        		 if(star == 0 || star==2*i-2) {
                	 printf("   X\t");			
      			 }	
         		 else{
         		 printf("  ");
		  	 }

  		 	 star++;
        		 }
       			 star=0;
        		 /* move to next row */
        		 printf("\n");
        	
			 }
		         else{
       
        		 /* Printing stars */
       			 while(star != (2*i - 1)) {
         		 if(star == 0 || star==2*i-2) {
                	  printf("X\t");		
			
      			 }	
		
         		 else{
         		 printf("\t");
			 }

  		 	 star++;
        		 }
        		 star=0;
        		 /* move to next row */
        		 printf("\n");
    		     }
    		count++;
	}
    	radius--;
    	/* Printing lower triangle */
    	count=1;
	for(i = radius;i >= 1; i--) {
        /* Printing spaces */
           for(space = 0; space <= radius-i; space++) {
           	printf("\t");
        	}
        
              if(i==2){
          	star=0;
        	  while(star != (2*i - 1)) {
         		if(star == 0 || star==2*i-2) {
                	printf("   X\t");			
      			}	
      			else{
         		printf("  ");
		 	}

  		 	star++;
        		}
        
       			/* move to next row */
       			printf("\n");
        	
			}
			else{
       
        		/* Printing stars */
        		star = 0;
        		while(star != (2*i - 1)) {

         		if(star == 0 || star==2*i-2)
               		printf("X\t");
		
      			else if(i==2){
        		printf("\t ");
			}
			else
                	printf("\t");
         		star++;   
        		}
        
       			printf("\n");
    			}
   		count++;
		}
		
	}
	printf("Name= Cýrcular Pokemon\n");
	printf("Size:%lf\n",body_size);
	if(color==0){
	printf("Color:RED\n");	
	}
	if(color==1){
	printf("Color:YELLOW\n");	
	}
	if(color==2){
	printf("Color:BLUE\n");	
	}
	if(color==3){
	printf("Color:BLACK\n");	
	}
	if(color==4){
	printf("Color:WHITE\n");	
	}
	printf("Move:%lf\n",move_length);	
	printf("Attack Power:%d\n",attack_power);

	
	}
}

int main(){
	int shape,color,attack_power;
	double size_of_body,move_length;
	shape= RECTENGULAR / CIRCULAR / SQUARE // Pick one of them
	size_of_body=CreateBody (shape);
	color = 798;
	color = SetColor(color);
	move_length = LoadMoves(shape, size_of_body);
	attack_power = SetAttackPower(0,150);
	ShowPokemon(shape, size_of_body, color, move_length, attack_power);
}
