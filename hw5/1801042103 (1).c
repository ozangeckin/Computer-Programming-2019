#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define DICT_SIZE 15
#define WORD_LEN 10
#define LINE_LEN 18
int compare_chars(char * ar1, char* ar2);
int get_line_size(char *line) {
	char *ch_iter = line; // so as not to lose beginning of line
	int counter = 0;
	// go until you see new line or null char
	while(*ch_iter != '\n' && *ch_iter != '\0') {
		ch_iter++; // next char
		counter++; // increment counter
	}
	
	return counter;
}

void copy_string(char *source, char *destination) {
	// get iterators over original pointers
	char *src_iter = source;
	char *dst_iter = destination;
	// until null char
	while (*src_iter != '\0') {
		// copy pointers
		*dst_iter = *src_iter;
		// advance to next char
		src_iter++;
		dst_iter++;
   }
   // terminate string
   *dst_iter = '\0';
}

void remove_newline(char *line) {
	char *ch_iter = line;
	// go until you see new line
	while(*ch_iter != '\n') {
		ch_iter++; // next char
	}
	*ch_iter = '\0'; // overwrite new line
}

void print_dictionary(char *dict[]) {
	int i;
	for(i = 0 ; i < DICT_SIZE ; i++) {
		printf("%s\n", dict[i]);
	}
}

void print_coord(int coord[DICT_SIZE][4]) {
	int i, j;
	for(i = 0 ; i < DICT_SIZE ; i++) {
		for(j = 0 ; j < 4 ; j++) {
			printf("%d ", coord[i][j]);
		}
		printf("\n");
	}
	
}

int main(){
	char *dict[DICT_SIZE];
    int coord[DICT_SIZE][4];    
    char line[LINE_LEN];
    char exit[10]="exit game";
	int q=0;
	int i,j,x,y ;
	char buf[20]={0};
	char a[15][15]; 
	int random;
	int size;
		
	FILE *fp = fopen("word_hunter.dat", "r");
	
	int line_counter = 0;
	int dict_counter = 0;
	while(fgets(line, LINE_LEN, fp) != NULL) {
		if(line_counter%5 == 0) {
			dict[dict_counter] = (char*) malloc(sizeof(char) * get_line_size(line));
			remove_newline(line);
			copy_string(line, dict[dict_counter]);
		} else if (line_counter%5 == 1){
			coord[dict_counter][0] = atoi(line);
		} else if (line_counter%5 == 2){			
			coord[dict_counter][1] = atoi(line);		
		} else if (line_counter%5 == 3){
			coord[dict_counter][2] = atoi(line);
		} else if (line_counter%5 == 4){
			coord[dict_counter][3] = atoi(line);
			dict_counter++;
		}
		line_counter++;
	}
	
	fclose(fp);
	//print_dictionary(dict);
	//print_coord(coord);
	
	// WRITE HERE...
	
 	


	printf("Welcome the world hunter game \n\n");
	for(i = 0;i<15;i++){
    	for(j = 0;j<15;j++){
			 
			random=(rand()%(26))+97;	   
	   		a[i][j]=random;
	   	}
    	}
	
	 	
 	for(i=0;i<15;i++){
 		for(j=0;j<15;j++){
 			if(i==coord[0][0] && j==coord[0][1]){
			   		x=i;
			   		size=sqrt(((coord[0][2]-coord[0][0])*(coord[0][2]-coord[0][0]))-((coord[0][3]-coord[0][1])*(coord[0][3]-coord[0][1])))+1;
			   		
					for(q=0;q<size;q++){
					   
				   	a[x][j]=dict[0][q];
				   	x++;
				}
			
				}
			
			 if(i==coord[1][0] && j==coord[1][1]){
					x=i;
					size=sqrt(((coord[1][2]-coord[1][0])*(coord[1][2]-coord[1][0]))-((coord[1][3]-coord[1][1])*(coord[1][3]-coord[1][1])))+1;
					for(q=0;q<size;q++){
					a[x][j]=dict[1][q];
					x++;
				}
			
				}
			

		
			if(i==coord[2][0]&&j==coord[2][1]){
						x=i;
						size=sqrt(((coord[2][2]-coord[2][0])*(coord[2][2]-coord[2][0]))-((coord[2][3]-coord[2][1])*(coord[2][3]-coord[2][1])))+1;
					for(q=0;q<size;q++){
					
					a[i][j]=dict[2][q];			
					x++;
			}
				
			}	
		if(i==coord[3][0]&&j==coord[3][1]){
					y=j;
					size=sqrt(((coord[3][2]-coord[3][0])*(coord[3][2]-coord[3][0]))-((coord[3][3]-coord[3][1])*(coord[3][3]-coord[3][1])))+1;
					for(q=0;q<size;q++){	
					a[i][y]=dict[3][q];			
					y++;
			}
			
			}
			
			if(i==coord[4][0]&&j==coord[4][1]){
					x=i;
					y=j;
					size=sqrt(((coord[4][2]-coord[4][0])*(coord[4][2]-coord[4][0]))-((coord[4][3]-coord[4][1])*(coord[4][3]-coord[4][1])))+1;
					for(q=0;q<size;q++){
					a[x][y]=dict[4][q];			
					x++;
					y++;
			
			}
				
			}
			
			if(i==coord[5][0]&&j==coord[5][1]){
					x=i;
					size=sqrt(((coord[5][2]-coord[5][0])*(coord[5][2]-coord[5][0]))-((coord[5][3]-coord[5][1])*(coord[5][3]-coord[5][1])))+1;
					
					for(q=0;q<size;q++){
					
					a[x][j]=dict[5][q];			
					x++;
			}
			}
			
			if(i==coord[6][0]&&j==coord[6][1]){
					x=i;
					y=j;
				size=sqrt(((coord[6][2]-coord[6][0])*(coord[6][2]-coord[6][0]))-((coord[6][3]-coord[6][1])*(coord[6][3]-coord[6][1])))+1;
					for(q=0;q<size;q++){
					
					a[x][y]=dict[6][q];			
					x++;
					y++;
			}
		
			}

			if(i==coord[7][0]&&j==coord[7][1]){
				x=i;
				y=j;
				size=sqrt(((coord[7][2]-coord[7][0])*(coord[7][2]-coord[7][0]))-((coord[7][3]-coord[7][1])*(coord[7][3]-coord[7][1])))+1;
				for(q=0;q<size;q++){
					
				a[x][y]=dict[7][q];			
					x++;
					y++;
			}
				
			}
				if(i==coord[8][0]&&j==coord[8][1]){
					x=i;
					y=j;
					size=sqrt(((coord[8][2]-coord[8][0])*(coord[8][2]-coord[8][0]))-((coord[8][3]-coord[8][1])*(coord[8][3]-coord[8][1])))+1;
					for(q=0;q<size;q++){
					
					a[x][y]=dict[8][q];			
					x++;
					y++;
			}
				
			}
			if(i==coord[9][0]&&j==coord[9][1]){
					x=i;
					size=sqrt(((coord[9][2]-coord[9][0])*(coord[9][2]-coord[9][0]))-((coord[9][3]-coord[9][1])*(coord[9][3]-coord[9][1])))+1;

					for(q=0;q<size;q++){
					a[x][j]=dict[9][q];			
					x++;
					
			}
						
			}

			if(i==coord[10][0]&&j==coord[10][1]){
					x=i;
					y=j;										
					size=sqrt(((coord[10][2]-coord[11][0])*(coord[11][2]-coord[11][0]))-((coord[11][3]-coord[11][1])*(coord[11][3]-coord[11][1])))+1;

					for(q=0;q<size;q++){
					
					a[x][y]=dict[10][q];			
					x++;
					y++;
			}
				

			}
				if(i==coord[11][0]&&j==coord[11][1]){
					x=i;
					size=sqrt(((coord[11][2]-coord[11][0])*(coord[11][2]-coord[11][0]))-((coord[11][3]-coord[11][1])*(coord[11][3]-coord[11][1])))+1;

					for(q=0;q<size;q++){
					
					a[x][j]=dict[11][q];			
					x++;
			}
				

			}
				if(i==coord[12][0]&&j==coord[12][1]){
					y=j;
					size=sqrt(((coord[12][2]-coord[12][0])*(coord[12][2]-coord[12][0]))-((coord[12][3]-coord[12][1])*(coord[12][3]-coord[12][1])))+1;

					for(q=0;q<size;q++){
					
					a[i][y]=dict[12][q];			
					y++;
			}
				

			}
				if(i==coord[13][0] && j==coord[13][1]){
					y=j;
					size=sqrt(((coord[13][2]-coord[13][0])*(coord[13][2]-coord[13][0]))-((coord[13][3]-coord[13][1])*(coord[13][3]-coord[13][1])))+1;

					for(q=0;q<size;q++){
					
					a[i][y]=dict[13][q];			
					y++;
			}
				
			}
			
					if(i==coord[14][0]&&j==coord[14][1]){
					y=j;
					size=sqrt(((coord[14][2]-coord[14][0])*(coord[14][2]-coord[14][0]))-((coord[14][3]-coord[14][1])*(coord[14][3]-coord[14][1])))+1;

					for(q=0;q<size;q++){
					
					a[i][y]=dict[14][q];			
					y++;
			}
				

			}
		}
	 
}
 		
		 for(i=0;i<15;i++){
    		for(j= 0;j<15;j++){
       		printf("%c ",a[i][j]);
    		}
  	 		printf("\n");

	
}
int r,t;
do{

	q=0;
	scanf("%d %d",&r,&t);
	scanf(" %[^\n]s", buf);
	
	
		for(i=0 ; i<15 ; i++)
		{
			for(j=0 ; j<15 ; j++)
			{
				
				if(buf[q]==a[i][j] && r==coord[0][0] && t==coord[0][1])
				{
					a[r][t]=a[i][j]-32;
					
				}
						
			}
						
		}
				
			
				
		

		for(i=0;i<15;i++){
    		for(j= 0;j<15;j++){
       		printf("%c ",a[i][j]);
    		}
  	 		printf("\n");
	}
}while(compare_chars(buf,exit)!=1);
	return 0;
}

int compare_chars(char * ar1, char* ar2){
	int i = 0;
  	while(ar1[i] == ar2[i]){
  		if(ar1[i] == '\0' && ar2[i] == '\0')
	  		break;
		i++;
	}
	if(ar1[i] - ar2[i] == 0)
		return 1;
	else
		return 0;
}




