#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
enum player_type{noone,cap,car};
enum block_type{start,property,tax,punish};
typedef struct{
	enum player_type type;
	int current_block_id;
	int owned_block_ids[11];
	int account;
	int turn_to_wait;
	char *name;
	int *current_player;
}player;
 typedef struct{
	int block_id;
	char *name;
	int price;
	int rent;
	int rent_1;
	int rent_2;
	int rent_3;
	int house_price;
	int house_count;
	player owner;
	int *current_block;
	enum block_type type;
}block;

void init_the_board(block board[20])
{
	board[0].block_id=0;
	board[0].name = (char*)malloc(5*sizeof(char)); 
	strcpy(board[0].name,"Start");
	board[0].price=0;
	board[0].rent=0;
	board[0].rent_1=0;
	board[0].rent_2=0;
	board[0].rent_3=0;
	board[0].house_price=0;
	board[0].type=0;

	board[1].block_id=1;
	board[1].name = (char*)malloc(8*sizeof(char)); 
	strcpy(board[1].name,"Esenyurt");
	board[1].price=16000;
	board[1].rent=800;
	board[1].rent_1=4000;
	board[1].rent_2=9000;
	board[1].rent_3=25000;
	board[1].house_price=10000;
	board[1].type=1;

	board[2].block_id=2;
	board[2].name = (char*)malloc(8*sizeof(char)); 
	strcpy(board[2].name,"Car Park");
	board[2].price=0;
	board[2].rent=1500;
	board[2].rent_1=0;
	board[2].rent_2=0;
	board[2].rent_3=0;
	board[2].house_price=0;
	board[2].type=2;

	board[3].block_id=3;
	board[3].name = (char*)malloc(5*sizeof(char)); 
	strcpy(board[3].name,"Tuzla");
	board[3].price=16500;
	board[3].rent=850;
	board[3].rent_1=4250;
	board[3].rent_2=9500;
	board[3].rent_3=26000;
	board[3].house_price=12000;
	board[3].type=1;

	board[4].block_id=4;
	board[4].name = (char*)malloc(10*sizeof(char));
	strcpy(board[4].name,"Arnavutköy");
	board[4].price=17000;
	board[4].rent=875;
	board[4].rent_1=4500;
	board[4].rent_2=10000;
	board[4].rent_3=28000;
	board[4].house_price=12000;
	board[4].type=1;

	board[5].block_id=5;
	board[5].name = (char*)malloc(11*sizeof(char));
	strcpy(board[5].name,"Wait 2 Turn");
	board[5].price=0;
	board[5].rent=2;
	board[5].rent_1=0;
	board[5].rent_2=0;
	board[5].rent_3=0;
	board[5].house_price=3;
	board[5].type=0;

	board[6].block_id=6;
	board[6].name = (char*)malloc(7*sizeof(char));
	strcpy(board[6].name,"Catalca");
	board[6].price=20000;
	board[6].rent=1000;
	board[6].rent_1=5000;
	board[6].rent_2=12000;
	board[6].rent_3=30000;
	board[6].house_price=13000;
	board[6].type=1;

	board[7].block_id=7;
	board[7].name = (char*)malloc(6*sizeof(char));
	strcpy(board[7].name,"Beykoz");
	board[7].price=23000;
	board[7].rent=1100;
	board[7].rent_1=5500;
	board[7].rent_2=12500;
	board[7].rent_3=33000;
	board[7].house_price=13000;
	board[7].type=1;

	board[8].block_id=8;
	board[8].name = (char*)malloc(7*sizeof(char));
	strcpy(board[8].name,"Car Fix");
	board[8].price=0;
	board[8].rent=1750;
	board[8].rent_1=0;
	board[8].rent_2=0;
	board[8].rent_3=0;
	board[8].house_price=0;
	board[8].type=2;

	board[9].block_id=9;
	board[9].name = (char*)malloc(7*sizeof(char));
	strcpy(board[9].name,"Maltepe");
	board[9].price=30000;
	board[9].rent=1350;
	board[9].rent_1=7000;
	board[9].rent_2=15000;
	board[9].rent_3=40000;
	board[9].house_price=15000;
	board[9].type=1;

	board[10].block_id=10;
	board[10].name = (char*)malloc(5*sizeof(char));
	strcpy(board[10].name,"Bills");
	board[10].price=0;
	board[10].rent=2000;
	board[10].rent_1=0;
	board[10].rent_2=0;
	board[10].rent_3=0;
	board[10].house_price=0;
	board[10].type=2;

	board[11].block_id=11;
	board[11].name = (char*)malloc(5*sizeof(char));
	strcpy(board[11].name,"Sisli");
	board[11].price=33000;
	board[11].rent=1500;
	board[11].rent_1=8000;
	board[11].rent_2=16000;
	board[11].rent_3=42000;
	board[11].house_price=16000;
	board[11].type=1;

	board[12].block_id=12;
	board[12].name = (char*)malloc(3*sizeof(char));
	strcpy(board[12].name,"Oil");
	board[12].price=0;
	board[12].rent=2250;
	board[12].rent_1=0;
	board[12].rent_2=0;
	board[12].rent_3=0;
	board[12].house_price=0;
	board[12].type=2;

	board[13].block_id=13;
	board[13].name = (char*)malloc(8*sizeof(char));
	strcpy(board[13].name,"Atasehir");
	board[13].price=35000;
	board[13].rent=1600;
	board[13].rent_1=8500;
	board[13].rent_2=17000;
	board[13].rent_3=45000;
	board[13].house_price=17000;
	board[13].type=1;

	board[14].block_id=14;
	board[14].name = (char*)malloc(7*sizeof(char));
	strcpy(board[14].name,"Sarıyer");
	board[14].price=40000;
	board[14].rent=1750;
	board[14].rent_1=9500;
	board[14].rent_2=19000;
	board[14].rent_3=48000;
	board[14].house_price=19000;
	board[14].type=1;

	board[15].block_id=15;
	board[15].name = (char*)malloc(11*sizeof(char));
	strcpy(board[15].name,"Wait 1 Turn");
	board[15].price=0;
	board[15].rent=1;
	board[15].rent_1=0;
	board[15].rent_2=0;
	board[15].rent_3=0;
	board[15].house_price=0;
	board[15].type=3;

	board[16].block_id=16;
	board[16].name = (char*)malloc(7*sizeof(char));
	strcpy(board[16].name,"Kadiköy");
	board[16].price=43000;
	board[16].rent=1900;
	board[16].rent_1=11000;
	board[16].rent_2=21500;
	board[16].rent_3=55000;
	board[16].house_price=23000;
	board[16].type=1;

	board[17].block_id=17;
	board[17].name = (char*)malloc(8*sizeof(char));
	strcpy(board[17].name,"Besiktas");
	board[17].price=60000;
	board[17].rent=2500;
	board[17].rent_1=15000;
	board[17].rent_2=28000;
	board[17].rent_3=60000;
	board[17].house_price=30000;
	board[17].type=1;

	board[18].block_id=18;
	board[18].name = (char*)malloc(8*sizeof(char));
	strcpy(board[18].name,"Vocation");
	board[18].price=0;
	board[18].rent=5000;
	board[18].rent_1=0;
	board[18].rent_2=0;
	board[18].rent_3=0;
	board[18].house_price=0;
	board[18].type=2;

	board[19].block_id=19;
	board[19].name = (char*)malloc(5*sizeof(char));
	strcpy(board[19].name,"Bebek");
	board[19].price=70000;
	board[19].rent=3500;
	board[19].rent_1=20000;
	board[19].rent_2=35500;
	board[19].rent_3=65000;
	board[19].house_price=35000;
	board[19].type=1;
}

void show_board(block board[20],player player_one,player player_two)
{
	int i,j;
	int array[49][145];
	for(i=0;i<49;i++){
		for(j=0;j<145;j++){
			array[i][j]=' ';
		}	
	}
	for(i=0;i<49;i++){
		for(j=0;j<145;j++){
			if(i==0)
			{
				array[i][j]='-';
			}
			if(i==48)
			{
				array[i][j]='-';
			}
			if(i==8){
				array[i][j]='-';			
			}
			if(i==40){
				array[i][j]='-';			
			}
			if(i==2 && j==0){
				array[i][j]='|';
			}
			if(i==4 && j==0)	{
				array[i][j]='|';
			}
			if(i==6 && j==0)	{
				array[i][j]='|';
			}
			if(i==10 && j==0)	{
				array[i][j]='|';
			}
			if(i==12 && j==0)	{
				array[i][j]='|';
			}
			if(i==14 && j==0)	{
				array[i][j]='|';
			}
			if(i==16 && j<=25){
				array[i][j]='-';
			}
			if(i==18 && j==0){
				array[i][j]='|';
			}
			if(i==20 && j==0){
				array[i][j]='|';
			}
			if(i==22 && j==0){
				array[i][j]='|';
			}
			if(i==24 && j<=25){
				array[i][j]='-';
			}
			if(i==26 && j==0){
				array[i][j]='|';
			}
			if(i==28 && j==0){
				array[i][j]='|';
			}
			if(i==30 && j==0){
				array[i][j]='|';
			}
			if(i==32 && j<=25){
				array[i][j]='-';
			}
			if(i==34 && j==0){
				array[i][j]='|';
			}
			if(i==36 && j==0){
				array[i][j]='|';
			}
			if(i==38 && j==0){
				array[i][j]='|';
			}
			if(i==42 && j==0){
				array[i][j]='|';
			}
			if(i==44 && j==0){
				array[i][j]='|';
			}
			if(i==46 && j==0){
				array[i][j]='|';
			}
			if(i==2 && j==20){
				array[i][j]='|';
			}
			if(i==4 && j==25)	{
				array[i][j]='|';
			}
			if(i==6 && j==17)	{
				array[i][j]='|';
			}
			if(i==10 && j==20)	{
				array[i][j]='|';
			}
			if(i==12 && j==19)	{
				array[i][j]='|';
			}
			if(i==14 && j==25)	{
				array[i][j]='|';
			}
			if(i==18 && j==17){
				array[i][j]='|';
			}
			if(i==20 && j==20){
				array[i][j]='|';
			}
			if(i==22 && j==25){
				array[i][j]='|';
			}
			if(i==26 && j==17){
				array[i][j]='|';
			}
			if(i==28 && j==19){
				array[i][j]='|';
			}
			if(i==30 && j==25){
				array[i][j]='|';
			}
			if(i==34 && j==18){
				array[i][j]='|';
			}
			if(i==36 && j==19){
				array[i][j]='|';
			}
			if(i==38 && j==25){
				array[i][j]='|';
			}
			if(i==42 && j==14){
				array[i][j]='|';
			}
			if(i==44 && j==25){
				array[i][j]='|';
			}
			if(i==46 && j==25){
				array[i][j]='|';
			}
			if(i==2 && j==97){
				array[i][j]='|';
			}
			if(i==4 && j==121)	{
				array[i][j]='|';
			}
			if(i==6 && j==136)	{
				array[i][j]='|';
			}
			if(i==10 && j==132)	{
				array[i][j]='|';
			}
			if(i==12 && j==132)	{
				array[i][j]='|';
			}
			if(i==14 && j==144)	{
				array[i][j]='|';
			}
			if(i==18 && j==130){
				array[i][j]='|';
			}
			if(i==20 && j==133){
				array[i][j]='|';
			}
			if(i==22 && j==144){
				array[i][j]='|';
			}
			if(i==26 && j==129){
				array[i][j]='|';
			}
			if(i==28 && j==133){
				array[i][j]='|';
			}
			if(i==30 && j==144){
				array[i][j]='|';
			}
			if(i==34 && j==130){
				array[i][j]='|';
			}
			if(i==36 && j==132){
				array[i][j]='|';
			}
			if(i==38 && j==144){
				array[i][j]='|';
			}
			if(i==42 && j==105){
				array[i][j]='|';
			}
			if(i==44 && j==116){
				array[i][j]='|';
			}
			if(i==46 && j==144){
				array[i][j]='|';
			}
			if(i==16 && j>=119){
				array[i][j]='-';
			}
			if(i==24 && j>=119){
				array[i][j]='-';
			}
			if(i==32 && j>=119){
				array[i][j]='-';
			}
			if(i==2 && j==83){
				array[i][j]='|';
			}
			if(i==4 && j==96)	{
				array[i][j]='|';
			}
			if(i==6 && j==111)	{
				array[i][j]='|';
			}
			if(i==10 && j==114)	{
				array[i][j]='|';
			}
			if(i==12 && j==113)	{
				array[i][j]='|';
			}
			if(i==14 && j==119)	{
				array[i][j]='|';
			}
			if(i==18 && j==111){
				array[i][j]='|';
			}
			if(i==20 && j==114){
				array[i][j]='|';
			}
			if(i==22 && j==119){
				array[i][j]='|';
			}
			if(i==26 && j==111){
				array[i][j]='|';
			}
			if(i==28 && j==113){
				array[i][j]='|';
			}
			if(i==30 && j==119){
				array[i][j]='|';
			}
			if(i==34 && j==112){
				array[i][j]='|';
			}
			if(i==36 && j==113){
				array[i][j]='|';
			}
			if(i==38 && j==119){
				array[i][j]='|';
			}
			if(i==42 && j==85){
				array[i][j]='|';
			}
			if(i==44 && j==96){
				array[i][j]='|';
			}
			if(i==46 && j==119){
				array[i][j]='|';
			}
			if(i==2 && j==36){
				array[i][j]='|';
			}
			if(i==4 && j==43)	{
				array[i][j]='|';
			}
			if(i==6 && j==41)	{
				array[i][j]='|';
			}
			if(i==2 && j==52){
				array[i][j]='|';
			}
			if(i==4 && j==62)	{
				array[i][j]='|';
			}
			if(i==6 && j==65)	{
				array[i][j]='|';
			}
			if(i==2 && j==71){
				array[i][j]='|';
			}
			if(i==4 && j==80)	{
				array[i][j]='|';
			}
			if(i==6 && j==89)	{
				array[i][j]='|';
			}
			if(i==42 && j==31){
				array[i][j]='|';
			}
			if(i==44 && j==43)	{
				array[i][j]='|';
			}
			if(i==46 && j==49)	{
				array[i][j]='|';
			}
			if(i==42 && j==47){
				array[i][j]='|';
			}
			if(i==44 && j==61)	{
				array[i][j]='|';
			}
			if(i==46 && j==73)	{
				array[i][j]='|';
			}
			if(i==42 && j==68){
				array[i][j]='|';
			}
			if(i==44 && j==80)	{
				array[i][j]='|';
			}
			if(i==46 && j==97)	{
				array[i][j]='|';
			}
	
		}
	}
	for(i=0;i<49;i++){
		for(j=0;j<145;j++){
			
			if(i==2 && j==8){
			printf("%s",board[0].name);			
			}
			if(i==4 && j==34){
			printf("%d$",board[1].price);
			}	
			if(i==6 && j==8){
			printf("%s ",player_two.name);		
			}
			if(i==6 && j==11){
			printf(" %s",player_one.name);
			}
			if(i==2 && j==29){
			printf("%s",board[1].name);		
			}
			printf("%c",array[i][j]);
			if(i==10 && j==8){
			printf("%s",board[19].name);
			}
			if(i==12 && j==8){
			printf("%d$",board[19].price);			
			}
			if(i==18 && j==8){
			printf("%s",board[18].name);		
			}
			if(i==20 && j==8){
			printf("%d$",board[18].rent);			
			}
			if(i==26 && j==8){
			printf("%s",board[17].name);				
			}
			if(i==28 && j==8){
			printf("%d$",board[17].price);			
			}
			if(i==34 && j==8){
			printf("%s",board[16].name);	
			}
			if(i==36 && j==8){
			printf("%d$",board[16].price);			
			}
			if(i==42 && j==8){
			printf("%s",board[15].name);
			}
			if(i==42 && j==22){
			printf("%s",board[14].name);
			}
			if(i==44 && j==33){
			printf("%d$",board[14].price);			
			}
			if(i==42 && j==39){
			printf("%s",board[13].name);			
			}
			if(i==44 && j==51){
			printf("%d$",board[13].price);			
			}
			if(i==42 && j==55){
			printf("%s",board[12].name);			
			}
			if(i==44 && j==69){
			printf("%d$",board[12].rent);			
			}
			if(i==42 && j==76){
			printf("%s",board[11].name);			
			}
			if(i==44 && j==88){
			printf("%d$",board[11].price);			
			}
			if(i==42 && j==94){
			printf("%s",board[10].name);			
			}
			if(i==44 && j==105){
			printf("%d$",board[10].rent);			
			}
			if(i==2 && j==44){
			printf("%s",board[2].name);			
			}
			if(i==4 && j==51){
			printf("%d$",board[2].rent);			
			}
			if(i==2 && j==61){
			printf("%s",board[3].name);			
			}
			if(i==4 && j==71){
			printf("%d$",board[3].price);			
			}
			if(i==2 && j==77){
			printf("%s",board[4].name);			
			}
			if(i==4 && j==86){
			printf("%d$",board[4].price);			
			}
			if(i==2 && j==90){
			printf("%s",board[5].name);			
			}
			if(i==10 && j==122){
			printf("%s",board[6].name);			
			}
			if(i==12 && j==121){
			printf("%d$",board[6].price);			
			}
			if(i==18 && j==119){
			printf("%s",board[7].name);			
			}
			if(i==20 && j==122){
			printf("%d$",board[7].price);		
			}
			if(i==26 && j==119){
			printf("%s",board[8].name);			
			}
			if(i==28 && j==121){
			printf("%d$",board[8].rent);			
			}
			if(i==34 && j==120){
			printf("%s",board[9].name);			
			}
			if(i==36 && j==121){
			printf("%d$",board[9].price);			
			}
			
		}
		printf("\n");	
	}
}
void show_properties(block board[20]){
	int choice;
do{	
	printf("Please select a property to see details:\n");
	printf("1-	Esenyurt\n");
	printf("4-	Arnavutkoy\n");
	printf("6-	Catalca\n");
	printf("7-	Beykoz\n");
	printf("9-	Maltepe\n");
	printf("11-	Sisli\n");
	printf("13-	Atasehir\n");
	printf("14-	Sariyer\n");
	printf("16-	Kadikoy\n");
	printf("17-	Besiktas\n");
	printf("19-	Bebek\n");
	printf("0-	Game Start\n");
	scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("---------------------------------\n");
				printf("                                 \n");
				printf("|	   %s	        |\n",board[1].name);
				printf("                                 \n");
				printf("---------------------------------\n");
				printf("                                 \n");
				printf("|      Rent             %d$    |\n",board[1].rent);
				printf("                                 \n");
				printf("|      Rent 1 H         %d$   |\n",board[1].rent_1);
				printf("                                 \n");
				printf("|      Rent 2 H         %d$   |\n",board[1].rent_2);
				printf("                                 \n");
				printf("|      Rent 1 H         %d$  |\n",board[1].rent_3);
				printf("                                 \n");
				printf("---------------------------------\n");
				printf("                                 \n");
				printf("|      House Price      %d$  |\n",board[1].house_price);
				printf("                                 \n");
				printf("---------------------------------\n");
				break;
			case 4:
				printf("---------------------------------\n");
				printf("                                 \n");
				printf("|	   %s	        |\n",board[4].name);
				printf("                                 \n");
				printf("---------------------------------\n");
				printf("                                 \n");
				printf("|      Rent             %d$    |\n",board[4].rent);
				printf("                                 \n");
				printf("|      Rent 1 H         %d$   |\n",board[4].rent_1);
				printf("                                 \n");
				printf("|      Rent 2 H         %d$  |\n",board[4].rent_2);
				printf("                                 \n");
				printf("|      Rent 1 H         %d$  |\n",board[4].rent_3);
				printf("                                 \n");
				printf("---------------------------------\n");
				printf("                                 \n");
				printf("|      House Price      %d$  |\n",board[4].house_price);
				printf("                                 \n");
				printf("---------------------------------\n");
				break;
			case 6:
				printf("---------------------------------\n");
				printf("                                 \n");
				printf("|	   %s	        |\n",board[6].name);
				printf("                                 \n");
				printf("---------------------------------\n");
				printf("                                 \n");
				printf("|      Rent             %d$   |\n",board[6].rent);
				printf("                                 \n");
				printf("|      Rent 1 H         %d$   |\n",board[6].rent_1);
				printf("                                 \n");
				printf("|      Rent 2 H         %d$  |\n",board[6].rent_2);
				printf("                                 \n");
				printf("|      Rent 1 H         %d$  |\n",board[6].rent_3);
				printf("                                 \n");
				printf("---------------------------------\n");
				printf("                                 \n");
				printf("|      House Price      %d$  |\n",board[6].house_price);
				printf("                                 \n");
				printf("---------------------------------\n");
				break;
			case 7:
				printf("---------------------------------\n");
				printf("                                 \n");
				printf("|	   %s	        |\n",board[7].name);
				printf("                                 \n");
				printf("---------------------------------\n");
				printf("                                 \n");
				printf("|      Rent             %d$   |\n",board[7].rent);
				printf("                                 \n");
				printf("|      Rent 1 H         %d$   |\n",board[7].rent_1);
				printf("                                 \n");
				printf("|      Rent 2 H         %d$  |\n",board[7].rent_2);
				printf("                                 \n");
				printf("|      Rent 1 H         %d$  |\n",board[7].rent_3);
				printf("                                 \n");
				printf("---------------------------------\n");
				printf("                                 \n");
				printf("|      House Price      %d$  |\n",board[7].house_price);
				printf("                                 \n");
				printf("---------------------------------\n");
				break;
			case 9:
				printf("---------------------------------\n");
				printf("                                 \n");
				printf("|	   %s	        |\n",board[9].name);
				printf("                                 \n");
				printf("---------------------------------\n");
				printf("                                 \n");
				printf("|      Rent             %d$   |\n",board[9].rent);
				printf("                                 \n");
				printf("|      Rent 1 H         %d$   |\n",board[9].rent_1);
				printf("                                 \n");
				printf("|      Rent 2 H         %d$  |\n",board[9].rent_2);
				printf("                                 \n");
				printf("|      Rent 1 H         %d$  |\n",board[9].rent_3);
				printf("                                 \n");
				printf("---------------------------------\n");
				printf("                                 \n");
				printf("|      House Price      %d$  |\n",board[9].house_price);
				printf("                                 \n");
				printf("---------------------------------\n");
				break;
			case 11:
				printf("---------------------------------\n");
				printf("                                 \n");
				printf("|	   %s	        |\n",board[11].name);
				printf("                                 \n");
				printf("---------------------------------\n");
				printf("                                 \n");
				printf("|      Rent             %d$   |\n",board[11].rent);
				printf("                                 \n");
				printf("|      Rent 1 H         %d$   |\n",board[11].rent_1);
				printf("                                 \n");
				printf("|      Rent 2 H         %d$  |\n",board[11].rent_2);
				printf("                                 \n");
				printf("|      Rent 1 H         %d$  |\n",board[11].rent_3);
				printf("                                 \n");
				printf("---------------------------------\n");
				printf("                                 \n");
				printf("|      House Price      %d$  |\n",board[11].house_price);
				printf("                                 \n");
				printf("---------------------------------\n");
				break;
			case 13:
				printf("---------------------------------\n");
				printf("                                 \n");
				printf("|	   %s	        |\n",board[13].name);
				printf("                                 \n");
				printf("---------------------------------\n");
				printf("                                 \n");
				printf("|      Rent             %d$   |\n",board[13].rent);
				printf("                                 \n");
				printf("|      Rent 1 H         %d$   |\n",board[13].rent_1);
				printf("                                 \n");
				printf("|      Rent 2 H         %d$  |\n",board[13].rent_2);
				printf("                                 \n");
				printf("|      Rent 1 H         %d$  |\n",board[13].rent_3);
				printf("                                 \n");
				printf("---------------------------------\n");
				printf("                                 \n");
				printf("|      House Price      %d$  |\n",board[13].house_price);
				printf("                                 \n");
				printf("---------------------------------\n");
				break;
			case 14:
				printf("---------------------------------\n");
				printf("                                 \n");
				printf("|	   %s	        |\n",board[14].name);
				printf("                                 \n");
				printf("---------------------------------\n");
				printf("                                 \n");
				printf("|      Rent             %d$   |\n",board[14].rent);
				printf("                                 \n");
				printf("|      Rent 1 H         %d$   |\n",board[14].rent_1);
				printf("                                 \n");
				printf("|      Rent 2 H         %d$  |\n",board[14].rent_2);
				printf("                                 \n");
				printf("|      Rent 1 H         %d$  |\n",board[14].rent_3);
				printf("                                 \n");
				printf("---------------------------------\n");
				printf("                                 \n");
				printf("|      House Price      %d$  |\n",board[14].house_price);
				printf("                                 \n");
				printf("---------------------------------\n");
				break;
			case 16:
				printf("---------------------------------\n");
				printf("                                 \n");
				printf("|	   %s	        |\n",board[16].name);
				printf("                                 \n");
				printf("---------------------------------\n");
				printf("                                 \n");
				printf("|      Rent             %d$   |\n",board[16].rent);
				printf("                                 \n");
				printf("|      Rent 1 H         %d$  |\n",board[16].rent_1);
				printf("                                 \n");
				printf("|      Rent 2 H         %d$  |\n",board[16].rent_2);
				printf("                                 \n");
				printf("|      Rent 1 H         %d$  |\n",board[16].rent_3);
				printf("                                 \n");
				printf("---------------------------------\n");
				printf("                                 \n");
				printf("|      House Price      %d$  |\n",board[16].house_price);
				printf("                                 \n");
				printf("---------------------------------\n");
				break;
			case 17:
				printf("---------------------------------\n");
				printf("                                 \n");
				printf("|	   %s	        |\n",board[17].name);
				printf("                                 \n");
				printf("---------------------------------\n");
				printf("                                 \n");
				printf("|      Rent             %d$   |\n",board[17].rent);
				printf("                                 \n");
				printf("|      Rent 1 H         %d$  |\n",board[17].rent_1);
				printf("                                 \n");
				printf("|      Rent 2 H         %d$  |\n",board[17].rent_2);
				printf("                                 \n");
				printf("|      Rent 1 H         %d$  |\n",board[17].rent_3);
				printf("                                 \n");
				printf("---------------------------------\n");
				printf("                                 \n");
				printf("|      House Price      %d$  |\n",board[17].house_price);
				printf("                                 \n");
				printf("---------------------------------\n");
				break;
			case 19:
				printf("---------------------------------\n");
				printf("                                 \n");
				printf("|	   %s	        |\n",board[19].name);
				printf("                                 \n");
				printf("---------------------------------\n");
				printf("                                 \n");
				printf("|      Rent             %d$   |\n",board[19].rent);
				printf("                                 \n");
				printf("|      Rent 1 H         %d$  |\n",board[19].rent_1);
				printf("                                 \n");
				printf("|      Rent 2 H         %d$  |\n",board[19].rent_2);
				printf("                                 \n");
				printf("|      Rent 1 H         %d$  |\n",board[19].rent_3);
				printf("                                 \n");
				printf("---------------------------------\n");
				printf("                                 \n");
				printf("|      House Price      %d$  |\n",board[19].house_price);
				printf("                                 \n");
				printf("---------------------------------\n");
				break;
			case 0:

				break;
			default:
				printf("please enter one of the numbers in the table");				
			
		}
	}while(choice!=0);


}

void buy_property(block* current_block, player* current_player){
	
}
void sell_property(block board[20],player* current_player){
}

void gameplay(block board[20],player player_one,player player_two){
	
	
	int i,j,choice;
do{	
	printf("Please select a property to see details:\n");
	printf("1 - Roll the dice\n");
	printf("2 - Show my account\n");
	printf("3 - Show my propertion\n");
	printf("4 - Show property deeds\n");
	printf("5 - Buy property\n");
	printf("6 - Buy House\n");
	printf("7 - Sell property\n");
	printf("0-Exit\n");
	scanf("%d",&choice);
		switch(choice){
			case 1:
				srand(time(NULL));
				int membrane=rand()%6+1;
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				break;
			case 7:
				break;	
			case 0:

				break;
			default:
				printf("please enter one of the numbers in the table");				
	}		
		
	}while(choice!=0);


}
int main()
{	
	block board[20];
	player player_one;
	player player_two;
	player_one.type=1;
	player_one.current_block_id=0;
	player_one.account=100000;
	player_one.name = (char*)malloc(3*sizeof(char));	
	strcpy(player_one.name,"Cap");
	
	player_two.type=2;
	player_two.current_block_id=0;
	player_two.account=100000;
	player_two.name = (char*)malloc(3*sizeof(char));
	strcpy(player_two.name,"Car");
	
	init_the_board(board);
	show_board(board,player_one,player_two);
	show_properties(board);
	gameplay(board,player_one,player_two);
}
