#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#define PROPERTY_COUNT 13

typedef enum block_type{start=0,property,fortune,tax,punish}b_type;
typedef enum player_type{none=-1,car,cap}player_type;

typedef struct
{
	player_type type;
	int current_block_id;
	int owned_blocks[PROPERTY_COUNT];
	int account;
	int turn_to_wait;
	char *player_name;
} player;

typedef struct
{
    int id;
    char * name;
    int price;
    int rent;
    int rent_1;
    int rent_2;
    int rent_3;
    int house_price;
    int h_count;
    player owner;
    b_type type;
} block;
struct fortune
{
	int id;
	char *name;
};

struct link_block
{
	block block_;
	struct link_block *next,*prev; 
};


void init_board(struct link_block **head)
{
	block gecici;
	player player_temp;
	player_temp.type=none;
	struct link_block *pilot;
	
    
    
   gecici.id=0;
   gecici.name="Start";
   gecici.price=0;
   gecici.rent=0;
   gecici.rent_1=0;
   gecici.rent_2=0;
   gecici.rent_3=0;
   gecici.owner=player_temp;
   gecici.house_price=0;
   gecici.h_count=0;
   gecici.type=start;
    
    (*head)=(struct link_block*)malloc(sizeof(struct link_block));
    (*head)->block_=gecici;
    pilot=(*head);
    (*head)->prev=NULL;
    
   gecici.type=fortune;
   gecici.id=3;
   gecici.name="Fortune Card";
    pilot->next=(struct link_block*)malloc(sizeof(struct link_block));
    pilot->next->block_=gecici;
    pilot=pilot->next; 
   gecici.id=9;
    pilot->next=(struct link_block*)malloc(sizeof(struct link_block));
    pilot->next->block_=gecici;
    pilot=pilot->next; 
   gecici.id=21;
    pilot->next=(struct link_block*)malloc(sizeof(struct link_block));
    pilot->next->block_=gecici;
    pilot=pilot->next; 
   gecici.id=15;
    pilot->next=(struct link_block*)malloc(sizeof(struct link_block));
    pilot->next->block_=gecici;
    pilot=pilot->next; 
    
    
   gecici.type=tax;
   gecici.name="Car park";
   gecici.id=2;
   gecici.price=1500;
    pilot->next=(struct link_block*)malloc(sizeof(struct link_block));
    pilot->next->block_=gecici;
    pilot=pilot->next; 
   gecici.name="Car fix";
   gecici.id=10;
   gecici.price=1750;
    pilot->next=(struct link_block*)malloc(sizeof(struct link_block));
    pilot->next->block_=gecici;
    pilot=pilot->next; 
   gecici.name="Bills";
   gecici.id=12;
   gecici.price=2000;
    pilot->next=(struct link_block*)malloc(sizeof(struct link_block));
    pilot->next->block_=gecici;
    pilot=pilot->next; 
   gecici.name="Oil";
   gecici.id=14;
   gecici.price=2250;
    pilot->next=(struct link_block*)malloc(sizeof(struct link_block));
    pilot->next->block_=gecici;
    pilot=pilot->next; 
	gecici.name="Vocation";
   gecici.id=22;
   gecici.price=5000;
    pilot->next=(struct link_block*)malloc(sizeof(struct link_block));
    pilot->next->block_=gecici;
    pilot=pilot->next; 

	gecici.type=punish;
	gecici.name="Wait 2 turn";
	gecici.price=2;
   gecici.id=6;
    pilot->next=(struct link_block*)malloc(sizeof(struct link_block));
    pilot->next->block_=gecici;
    pilot=pilot->next; 
	gecici.name="Wait 1 turn";
	gecici.price=1;
   gecici.id=18;
    pilot->next=(struct link_block*)malloc(sizeof(struct link_block));
    pilot->next->block_=gecici;
    pilot=pilot->next; 


   gecici.type=property;

   gecici.id=1;
   gecici.name="Esenyurt";
   gecici.price=16000;
   gecici.rent=800;
   gecici.rent_1=4000;
   gecici.rent_2=9000;
   gecici.rent_3=25000;
   gecici.house_price=10000;
   gecici.h_count=0;
    pilot->next=(struct link_block*)malloc(sizeof(struct link_block));
    pilot->next->block_=gecici;
    pilot=pilot->next; 

   gecici.id=4;
   gecici.name="Tuzla";
   gecici.price=16500;
   gecici.rent=850;
   gecici.rent_1=4250;
   gecici.rent_2=9500;
   gecici.rent_3=26000;
   gecici.house_price=12000;
   gecici.h_count=0;
    pilot->next=(struct link_block*)malloc(sizeof(struct link_block));
    pilot->next->block_=gecici;
    pilot=pilot->next; 

   gecici.id=5;
   gecici.name="Arnavutkoy";
   gecici.price=17000;
   gecici.rent=850;
   gecici.rent_1=4500;
   gecici.rent_2=10000;
   gecici.rent_3=28000;
   gecici.house_price=12000;
   gecici.h_count=0;
    pilot->next=(struct link_block*)malloc(sizeof(struct link_block));
    pilot->next->block_=gecici;
    pilot=pilot->next; 

   gecici.id=7;
   gecici.name="Catalca";
   gecici.price=20000;
   gecici.rent=1000;
   gecici.rent_1=5000;
   gecici.rent_2=12000;
   gecici.rent_3=30000;
   gecici.house_price=13000;
   gecici.h_count=0;
    pilot->next=(struct link_block*)malloc(sizeof(struct link_block));
    pilot->next->block_=gecici;
    pilot=pilot->next; 

	gecici.id=8;
   gecici.name="Beykoz";
   gecici.price=23000;
   gecici.rent=1100;
   gecici.rent_1=5500;
   gecici.rent_2=12500;
   gecici.rent_3=33000;
   gecici.house_price=13000;
   gecici.h_count=0;
    pilot->next=(struct link_block*)malloc(sizeof(struct link_block));
    pilot->next->block_=gecici;
    pilot=pilot->next; 

	gecici.id=11;
   gecici.name="Maltepe";
   gecici.price=30000;
   gecici.rent=1350;
   gecici.rent_1=7000;
   gecici.rent_2=15000;
   gecici.rent_3=40000;
   gecici.house_price=15000;
   gecici.h_count=0;
    pilot->next=(struct link_block*)malloc(sizeof(struct link_block));
    pilot->next->block_=gecici;
    pilot=pilot->next; 
	
	gecici.id=13;
   gecici.name="Sisli";
   gecici.price=33000;
   gecici.rent=1500;
   gecici.rent_1=8000;
   gecici.rent_2=16000;
   gecici.rent_3=42000;
   gecici.house_price=16000;
   gecici.h_count=0;
    pilot->next=(struct link_block*)malloc(sizeof(struct link_block));
    pilot->next->block_=gecici;
    pilot=pilot->next; 

	gecici.id=16;
   gecici.name="Atasehir";
   gecici.price=35000;
   gecici.rent=1600;
   gecici.rent_1=8500;
   gecici.rent_2=17000;
   gecici.rent_3=45000;
   gecici.house_price=17000;
   gecici.h_count=0;
    pilot->next=(struct link_block*)malloc(sizeof(struct link_block));
    pilot->next->block_=gecici;
    pilot=pilot->next; 

	gecici.id=17;
   gecici.name="Sariyer";
   gecici.price=40000;
   gecici.rent=1750;
   gecici.rent_1=9500;
   gecici.rent_2=19000;
   gecici.rent_3=48000;
   gecici.house_price=19000;
   gecici.h_count=0;
    pilot->next=(struct link_block*)malloc(sizeof(struct link_block));
    pilot->next->block_=gecici;
    pilot=pilot->next; 

	gecici.id=19;
   gecici.name="Kadikoy";
   gecici.price=43000;
   gecici.rent=1900;
   gecici.rent_1=11000;
   gecici.rent_2=21500;
   gecici.rent_3=55000;
   gecici.house_price=23000;
   gecici.h_count=0;
    pilot->next=(struct link_block*)malloc(sizeof(struct link_block));
    pilot->next->block_=gecici;
    pilot=pilot->next; 

   gecici.id=20;
   gecici.name="Besiktas";
   gecici.price=60000;
   gecici.rent=2500;
   gecici.rent_1=15000;
   gecici.rent_2=28000;
   gecici.rent_3=60000;
   gecici.house_price=30000;
   gecici.h_count=0;
    pilot->next=(struct link_block*)malloc(sizeof(struct link_block));
    pilot->next->block_=gecici;
    pilot=pilot->next; 

	gecici.id=23;
   gecici.name="Bebek";
   gecici.price=70000;
   gecici.rent=3500;
   gecici.rent_1=20000;
   gecici.rent_2=35500;
   gecici.rent_3=65000;
   gecici.house_price=35000;
   gecici.h_count=0;
    pilot->next=(struct link_block*)malloc(sizeof(struct link_block));
    pilot->next->block_=gecici;
    pilot=pilot->next;
    pilot->next=NULL;
    
	
}
void print(struct link_block *head)
{
	while(head->next!=NULL)
	{
		printf("%s\n",head->block_.name);
		head=head->next;
	}
	while(head!=NULL)
	{
		printf("%s\n",head->block_.name);
		head=head->prev;
	}
}
struct link_block* swap(struct link_block* ptr1, struct link_block* ptr2) 
{ 
    struct link_block* tmp = ptr2->next; 
    ptr2->next = ptr1; 
    ptr1->next = tmp; 
    return ptr2; 
} 
  
/* Function to sort the list */
int bubbleSort(struct link_block** head, int count) 
{ 
    struct link_block ** h; 
    int i, j, swapped; 
  
    for (i = 0; i <= count; i++) { 
  
        h = head; 
        swapped = 0; 
  
        for (j = 0; j < count - i - 1; j++) { 
  
            struct link_block* p1 = *h; 
            struct link_block* p2 = p1->next; 
  
            if (p1->block_.id > p2->block_.id) { 
  
                /* update the link after swapping */
                *h = swap(p1, p2); 
                swapped = 1; 
            } 
  
            h = &(*h)->next; 
        } 
  
        /* break if the loop ended without any swap */
        if (swapped == 0) 
            break; 
    } 
} 

  



void show_board(struct link_block *head,player player_one,player player_two)
{
	struct link_block *pilot=head;
	printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	int i=0,space_flag=0;
	for (i=0;i<7;i++)
	{
        if (strlen(pilot->block_.name)<8)
		    printf("|\t%s\t\t",pilot->block_.name);
        else
            printf("|\t%s\t",pilot->block_.name);
            
        pilot=pilot->next;
	}
	pilot=head;
	printf("|\n");
	for (i=0;i<7;i++)
	{
		if (pilot->block_.type==property || pilot->block_.type==tax)
		    printf("|\t%d$ \t\t",pilot->block_.price);
		else if (strlen(pilot->block_.name)<8)
            printf("|\t     \t\t");
        else
            printf("|\t\t \t");
            
        pilot=pilot->next;
	}
	pilot=head;
	printf("|\n");
   for (i=0;i<7;i++)
    {
        space_flag=0;
        printf("|\t");
        if (i==player_one.current_block_id && i==player_two.current_block_id)
        {
            printf("%s, %s \t",player_one.player_name,player_two.player_name);
            space_flag=1;
        }
        else {
            if (i == player_one.current_block_id) {
                printf("%s \t\t", player_one.player_name);
                space_flag = 1;
            }
            if (i == player_two.current_block_id) {
                printf("%s \t\t", player_two.player_name);
                space_flag = 1;
            }
        }
        if (space_flag==0) {
            if (strlen(pilot->block_.name)<8)
                printf("     \t\t");
            else
                printf(" \t\t");
        }
        pilot=pilot->next;
    }
    printf("|\n");
    printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    struct link_block *final=head;
	struct link_block *plt=head;
	int j=0;
	while(j<7)
		{
			plt=plt->next;
			j++;
		}
		while(final->next!=NULL)
			final=final->next;
    for (i=0;i<5;i++)
    {
        //Names
		
		
		
        if (strlen(final->block_.name)<8)
            printf("|\t%s\t\t|",final->block_.name);
        else
            printf("|\t%s\t|",final->block_.name);
        printf("\t\t\t\t\t\t\t\t\t\t\t\t");
        if (strlen(plt->block_.name)<8)
            printf("\t\t\t|\t%s\t\t|",plt->block_.name);
        else
            printf("\t\t\t|\t%s\t|",plt->block_.name);
        printf("\n");
        //prices
        if (final->block_.type==property || final->block_.type==tax)
            printf("|\t%d$ \t\t|",final->block_.price);
        else if (strlen(final->block_.name)<8)
            printf("|\t     \t|");
        else
            printf("|\t\t \t|");


        printf("\t\t\t\t\t\t\t\t\t\t\t\t");

        if (plt->block_.type==property || plt->block_.type==tax)
            printf("\t\t\t|\t%d$ \t\t",plt->block_.price);
        else if (strlen(plt->block_.name)<8)
            printf("|\t     \t");
        else
            printf("\t\t\t|\t\t \t");

        printf("|\n");
        //spaces

        space_flag=0;
        printf("|\t");
        if (23-i==player_one.current_block_id && 23-i==player_two.current_block_id)
        {
            printf("%s, %s \t|",player_one.player_name,player_two.player_name);
            space_flag=1;
        }
        else {
            if (23 - i == player_one.current_block_id) {
                printf("%s \t\t|", player_one.player_name);
                space_flag = 1;
            }
            if (23- i == player_two.current_block_id) {
                printf("%s \t\t|", player_two.player_name);
                space_flag = 1;
            }
        }
        if (space_flag==0) {
            if (strlen(final->block_.name)<8)
                printf("\t\t|");
            else
                printf("    \t\t|");
        }

        printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t");
        space_flag=0;
        printf("\t|\t");
        if (7+i==player_one.current_block_id && 7+i==player_two.current_block_id)
        {
            printf("%s, %s \t",player_one.player_name,player_two.player_name);
            space_flag=1;
        }
        else {

            if (7+i==player_one.current_block_id)
            {
                printf("%s \t\t",player_one.player_name);
                space_flag=1;
            }
            if (7+i==player_two.current_block_id)
            {
                printf("%s \t\t",player_two.player_name);
                space_flag=1;
            }
        }

        if (space_flag==0) {
            if (strlen(plt->block_.name)<8)
                printf("\t\t");
            else
                printf("    \t\t");
        }

        printf("|\n");
        if (i!=4) {
            printf("-------------------------");
            printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t");
            printf("-------------------------");
            printf("\n");
        }
        plt=plt->next;
        final=final->prev;

    }
    
    printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    final=head;
    j=0;
    while(j<18)
    {
    	final=final->next;
    	j++;
	}
	pilot=final;
	for (i=17;i>=11;i--)
    {
        if (strlen(final->block_.name)<8)
            printf("|\t%s\t\t",final->block_.name);
        else
            printf("|\t%s\t",final->block_.name);
        final=final->prev;
    }
    printf("|\n");
    final=pilot;
    for (i=17;i>=11;i--)
    {
        if (final->block_.type==property || final->block_.type==tax)
            printf("|\t%d$ \t\t",final->block_.price);
        else if (strlen(final->block_.name)<8)
            printf("|\t     \t\t");
        else
            printf("|\t\t \t");
        final=final->prev;
    }
    printf("|\n");
    final=pilot;
    for (i=17;i>=11;i--)
    {
        space_flag=0;
        printf("|\t");
        if (i==player_one.current_block_id && i==player_two.current_block_id)
        {
            printf("%s, %s \t",player_one.player_name,player_two.player_name);
            space_flag=1;
        }
        else {
            if (i == player_one.current_block_id) {
                printf("%s \t\t", player_one.player_name);
                space_flag = 1;
            }
            if (i == player_two.current_block_id) {
                printf("%s \t\t", player_two.player_name);
                space_flag = 1;
            }
        }
        if (space_flag==0) {
            if (strlen(final->block_.name)<8)
                printf("     \t\t");
            else
                printf(" \t\t");
        }
        final=final->prev;

    }
    printf("|\n");
    printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    
    
    
}
void init_owned(player* current_player)
{
    int i;
    for (i=0;i<PROPERTY_COUNT;i++)
    {
        current_player->owned_blocks[i]=-1;
    }

}
void prev_cont(struct link_block **head)
{
	struct link_block *pilot_r=(*head)->next;
	struct link_block *pilot_l=(*head);
	while(pilot_r!=NULL&&pilot_l->next!=NULL)
	{
		pilot_r->prev=pilot_l;
		pilot_r=pilot_r->next;
		pilot_l=pilot_l->next;
	}
		
		
}
void show_properties(struct link_block *head)
{
	int ex_fl=0,i,selection;
	struct link_block *pilot=head;
    while (ex_fl==0)
    {
    	pilot=head;
        printf("Please select a property to see details:\n");
        for (i = 0; i < 20; ++i) {
            if (pilot->block_.type==property)
                printf("%d -\t%s \n",pilot->block_.id,pilot->block_.name);
            pilot=pilot->next;
        }
        pilot=head;
        printf("0 -\tExit\n");
        scanf("%d",&selection);
        if (selection==0)
            ex_fl=1;
        else {
        	int j=0;
        	while(j<selection)
        	{
        		pilot=pilot->next;
        		j++;
			}
            if (selection > 0 && selection < 20 && pilot->block_.type == property) {
                printf("\n\n---------------------------------\n");
                if (strlen(pilot->block_.name) < 8)
                    printf("|\t\t%s\t\t|\n", pilot->block_.name);
                else
                    printf("|\t    %s\t\t|\n", pilot->block_.name);
                printf("---------------------------------\n");
                printf("|\tRent \t\t%d$\t|\n", pilot->block_.rent);
                printf("|\tRent 1 H \t%d$\t|\n", pilot->block_.rent_1);
                printf("|\tRent 2 H \t%d$\t|\n", pilot->block_.rent_2);
                printf("|\tRent 3 H \t%d$\t|\n", pilot->block_.rent_3);
                printf("---------------------------------\n");
                printf("|\tHouse Price \t%d$\t|\n", pilot->block_.house_price);
                printf("|\tHouse count \t%d\t|\n", pilot->block_.h_count);
                printf("---------------------------------\n\n\n");
            } else printf("\nWrong Selection! Please Try Again.\n\n");
        }
    }
	
}

void add_to_owned(player* current_player)
{
	int i;
    for ( i = 0; i < PROPERTY_COUNT; ++i) {
        if (current_player->owned_blocks[i]==-1) {
            current_player->owned_blocks[i] = current_player->current_block_id;
            printf("Current block id %d\n",current_player->current_block_id);
            break;
        } else
            printf("%d ",current_player->owned_blocks[i]);
    }
    printf("\n");
}

void copy_owner(player* old, player* yeni)
{
    old->type=yeni->type;
    old->account=yeni->account;
    old->turn_to_wait=yeni->turn_to_wait;
    old->player_name=yeni->player_name;
    old->current_block_id=yeni->current_block_id;
    int i;
    for ( i= 0; i < PROPERTY_COUNT; ++i) {
        old->owned_blocks[i]=yeni->owned_blocks[i];
    }
}

void buy_property(block* current_block, player* current_player)
{
    if (current_block->price<=current_player->account)
    {
        current_player->account-=current_block->price;
        copy_owner(&current_block->owner,current_player);
        add_to_owned(current_player);

        printf("Congratiulations! You have buy %s.\n",current_block->name);
        printf("You left %d$ in your account.\n",current_player->account);

    }
    else
        printf("You don't have enough money to buy this property!\n");
}
int count_properties(player current_player)
{
    int i,count=0;
    for (i=0;i<PROPERTY_COUNT;i++)
    {
        if (current_player.owned_blocks[i]!=-1)
            count++;
    }
    return count;
}


void sell_property(struct link_block *head, player* current_player)
{
    int property_id,flag=0,is_owned=-1,i,index,counter=0;
        if (count_properties(*current_player)!=0)
        {
            for (i = 0; i < PROPERTY_COUNT; i++) {
                if (current_player->owned_blocks[i] != -1) {
                	struct link_block *pilot=head;
                	int j=0;
                	while(j<current_player->owned_blocks[i])
                	{
                		pilot=pilot->next;
                		j++;
					}
                    printf("%d - %s\n", pilot->block_.id,
                           pilot->block_.name);
                    counter++;
                }

            }
            printf("0 - Back\n");
            printf("Please select to sell the property:\n");

            scanf("%d",&property_id);
            if (property_id!=0)
            {
                for(i=0;i<PROPERTY_COUNT;i++)
                {
                    if (current_player->owned_blocks[i]==property_id)
                    {
                        is_owned=1;
                        index=i;
                        break;
                    }
                }
                if(is_owned!=-1)
                {
                	struct link_block *pilot=head;
                	int i=0;
                	while(i<property_id)
                	{
                		pilot=pilot->next;
                		i++;
					}
                    current_player->owned_blocks[index]=-1;
                    player temp;
                    pilot->block_.owner.type=none;
                    if(pilot->block_.h_count==0)current_player->account+=pilot->block_.price/2;
                    if(pilot->block_.h_count==1)
                    {
                        current_player->account+=(pilot->block_.price+pilot->block_.house_price)/2;
                    }
                    if(pilot->block_.h_count==2)
                    {
                        current_player->account+=(pilot->block_.price+(2*pilot->block_.house_price))/2;
                    }
                    if(pilot->block_.h_count==3)
                    {
                        current_player->account+=(pilot->block_.price+(3*pilot->block_.house_price))/2;
                    }
                }
            }
        } else
        {
            printf("You don't have any property to sell.\n");
        }

}
void show_player_properties(struct link_block *head, player current_player)
{
    int i,counter=0,selection;
    while (selection!=0) {
        printf("----------------------------------------\n");
        for (i = 0; i < PROPERTY_COUNT; i++) {
            if (current_player.owned_blocks[i] != -1) {
            	int j=0;
            	struct link_block *pilot=head;
            	while(j<current_player.owned_blocks[i])
            	{
            		pilot=pilot->next;
            		j++;
				}
                printf("%d - %s\n", pilot->block_.id,
                       pilot->block_.name);
                counter++;
            }

        }
        if (counter == 0)
        {
            printf("You have not owned any property yet.\n");
            printf("----------------------------------------\n");
            selection=0;
        }
        else
        {

            printf("0 - Back \n");
            printf("----------------------------------------\n");
            printf("Please select an property to see details.\n");
            scanf("%d", &selection);

            if (selection!=0) {
            	
            	struct link_block *pilot=head;
            	int j=0;
            	while(j<selection)
            	{
            		pilot=pilot->next;
            		j++;
				}
                if (pilot->block_.owner.type != current_player.type)
                    printf("You made a wrong selection!\n");
                else {
                    printf("\n\n---------------------------------\n");
                    if (strlen(pilot->block_.name) < 8)
                        printf("|\t\t%s\t\t|\n", pilot->block_.name);
                    else
                        printf("|\t    %s\t\t|\n", pilot->block_.name);
                    printf("---------------------------------\n");
                    printf("|\tRent \t\t%d$\t|\n", pilot->block_.rent);
                    printf("|\tRent 1 H \t%d$\t|\n", pilot->block_.rent_1);
                    printf("|\tRent 2 H \t%d$\t|\n", pilot->block_.rent_2);
                    printf("|\tRent 3 H \t%d$\t|\n", pilot->block_.rent_3);
                    printf("---------------------------------\n");
                    printf("|\tHouse Price \t%d$\t|\n", pilot->block_.house_price);
                    printf("|\tHouse count \t%d\t|\n", pilot->block_.h_count);
                    printf("---------------------------------\n\n\n");
                }
            }
        }


    }

}
int roll_dice()
{

    int i=rand()%6+1;
    return i;
}
int find_ort(struct link_block *head)
{
	struct link_block *pilot=head;
	int sum=0;
	while(pilot!=NULL)
	{
		if(pilot->block_.type==1)
			sum+=pilot->block_.price;
		pilot=pilot->next;
	}
	return sum/12;
}
int build_house(block* current_block, player* current_player)
{
    int flag=0;
    if (current_player->type==current_block->owner.type)
    {
        if (current_block->h_count<3)
        {
            if (current_block->house_price<=current_player->account)
            {
                flag=1;
                current_player->account-=current_block->house_price;
                current_block->h_count+=1;
            }
            else
                printf("You don't have enough money to build house!\n");
        }
        else
            printf("You can't buy more than 3 houses in a property!\n");
    }
    else
        printf("You don't have permission to build house on this property!\n ");
    return flag;
}
void com_arsa_sat(struct link_block *head,player *computer,int required_money)
{
	block b1;
	int flag=0;
	struct link_block *pilot=head->next;
	while(pilot!=NULL)
	{
		if(pilot->block_.type==property&&pilot->block_.owner.type==computer->type)
		{
			if(flag==0)
				b1=pilot->block_;
			else
				if(b1.price>pilot->block_.price)
					b1=pilot->block_;
		}
		pilot=pilot->next;
	}
	sell_property(head,computer);
}
void pay_rent(struct link_block *head, player* current_player,player * owner)
{
    int rent=0,owned_property_count;
    struct link_block *pilot=head;
    int j=0;
    while(j<current_player->current_block_id)
    {
    	pilot=pilot->next;
    	j++;
	}
    rent=pilot->block_.rent;
    if (pilot->block_.h_count==1)rent=pilot->block_.rent_1;
    if (pilot->block_.h_count==2)rent=pilot->block_.rent_2;
    if (pilot->block_.h_count==3)rent=pilot->block_.rent_3;
    if (rent>current_player->account)
    {
        owned_property_count=count_properties(*current_player);
        while(rent>current_player->account && owned_property_count!=0)
        {
            com_arsa_sat(head,current_player,rent);
            owned_property_count=count_properties(*current_player);
        }
    }
    if (rent<current_player->account)
    {
        current_player->account-=rent;
        owner->account+=rent;
    } else
        current_player->account=0;
}
void show_property_deed(struct link_block *head)
{
    int exit_flag=0,i,selection;
    struct link_block *pilot=head;
    while (exit_flag==0)
    {
        printf("Please select a property to see details:\n");
        for (i = 0; i < 20; ++i) {
            if (pilot->block_.type==property)
                printf("%d -\t%s \n",pilot->block_.id,pilot->block_.name);
            	pilot=pilot->next;
        }
        printf("0 -\tExit\n");
        scanf("%d",&selection);
        pilot=head;
        int j=0;
        while(j<selection)
        {
        	pilot=pilot->next;
        	j++;
		}
        if (selection==0)
            exit_flag=1;
        else {
            if (selection > 0 && selection < 20 && pilot->block_.type == property) {
                printf("\n\n---------------------------------\n");
                if (strlen(pilot->block_.name) < 8)
                    printf("|\t\t%s\t\t|\n", pilot->block_.name);
                else
                    printf("|\t    %s\t\t|\n", pilot->block_.name);
                printf("---------------------------------\n");
                printf("|\tRent \t\t%d$\t|\n", pilot->block_.rent);
                printf("|\tRent 1 H \t%d$\t|\n", pilot->block_.rent_1);
                printf("|\tRent 2 H \t%d$\t|\n", pilot->block_.rent_2);
                printf("|\tRent 3 H \t%d$\t|\n", pilot->block_.rent_3);
                printf("---------------------------------\n");
                printf("|\tHouse Price \t%d$\t|\n", pilot->block_.house_price);
                printf("|\tHouse count \t%d\t|\n", pilot->block_.h_count);
                printf("---------------------------------\n\n\n");
            } else printf("\nWrong Selection! Please Try Again.\n\n");
        }
    }
}
int insufficient_fund(struct link_block *head, player* current_player,int required_money)
{
    int selection,flag=1;
    while (selection!=4 && current_player->account<required_money && count_properties(*current_player)!=0)
    {
        printf("You don't have enough money to continue your transaction.You need %d$ more. Please select an option to continue: \n",required_money-current_player->account);
        printf("1- Sell Property\n");
        printf("2- Show my Properties\n");
        printf("3- Show my Account\n");
        printf("0- Back\n");
        scanf("%d",&selection);
        switch (selection)
        {
            case 1:
                sell_property(head,current_player);
                break;
            case 2:
                show_player_properties(head,*current_player);
                break;
            case 3:
                printf("\n\nThere are %d $ in your account.\n\n",current_player->account);
                break;
            case 0:
                flag=0;
                break;
            default:
                printf("You made a wrong selection!\n");
                break;

        }
    }
    return flag;

}
void house_dialog(struct link_block *head, player* current_player)
{
	struct link_block *pilot=head;
	int j=0;
	while(j<current_player->current_block_id)
	{
		pilot=pilot->next;
		j++;
	}
    int house_flag=1,selection,insuf_flag=1,build_flag=1;
    while (house_flag && build_flag) {
        printf("Do you want to build house on %s ?\n",
               pilot->block_.name);
        printf("1- Yes\n");
        printf("2- No\n");
        scanf("%d", &selection);
        if (selection == 1) {

            if (current_player->account < pilot->block_.house_price) {
                while (count_properties(*current_player)!=0 && current_player->account<pilot->block_.house_price && insuf_flag==1)
                    insuf_flag=insufficient_fund(head,current_player,pilot->block_.house_price);
            }
            if (current_player->account >= pilot->block_.house_price)
                build_flag=build_house(&pilot->block_, current_player);
            else
                house_flag=0;


        } else
            house_flag=0;
    }
}
void after_dice_menu(struct link_block *head, player* current_player, player* other)
{
	struct link_block *pilot=head;
	int j=0;
	while(j<current_player->current_block_id)
	{
		pilot=pilot->next;
		j++;
	}
    int selection,insuf_flag=1;
    switch (pilot->block_.type)
    {
        case property:
            printf("%s has arrived %s \n",current_player->player_name,pilot->block_.name);
            if (pilot->block_.owner.type==none)
            {
                printf("Do you want to buy %s ?\n",pilot->block_.name);
                printf("1- Yes\n");
                printf("2- No\n");
                scanf("%d",&selection);
                if (selection==1)
                {

                    if (current_player->account<pilot->block_.price)
                    {
                        while (count_properties(*current_player)!=0 && current_player->account<pilot->block_.price && insuf_flag==1 )
                        {
                            insuf_flag=insufficient_fund(head,current_player,pilot->block_.price);
                        }
                    }
                    buy_property(&pilot->block_,current_player);
                    if (current_player->type==pilot->block_.owner.type)
                    {
                        house_dialog(head,current_player);
                    }

                }

            } else
            {
                pay_rent(head,current_player,other);
            }
            break;
        case tax:
            printf("%s has arrived tax block(%s)\n",current_player->player_name,pilot->block_.name);
            while (count_properties(*current_player)!=0 && current_player->account<pilot->block_.price) {
                insuf_flag = insufficient_fund(head, current_player,
                                               pilot->block_.price);
                if (insuf_flag == 0 && current_player->account < pilot->block_.price)
                    printf("You must pay your tax!\n");
            }
            if (current_player->account>pilot->block_.price)
                current_player->account=current_player->account-pilot->block_.price;
            else
            {
                current_player->account=0;
            }
            break;
        case punish:
            printf("%s has punished for %d turn. \n",current_player->player_name,pilot->block_.price);
            current_player->turn_to_wait+=pilot->block_.price;
            break;
    }
}
void play_game(struct link_block *head, player* computer, player* me)
{
	int end_computer=0,end_me=0,zar,current_com,current_me,me_sira=0,com_sira=0;
	struct link_block *pilot=head;
	int i=0,j=0;
	printf("Welcome to Monopoly!\n");
	while(1)
	{
		printf("Computer turn\n");
		zar=roll_dice();
		printf("Computer rolled the dice: %d\n",zar);
		current_com=computer->current_block_id;
		while(i<zar+current_com)
		{
			pilot=pilot->next;
			i++;
		}
		computer->current_block_id+=zar;
		show_board(head,*computer,*me);
		if(computer->current_block_id>23)
		{
			computer->account+=10000;
			computer->current_block_id%=24;
		}
		if(pilot->block_.owner.type==none)
		{
			if(pilot->block_.price<find_ort(head))
				buy_property(&pilot->block_,computer);
			else
			{
				zar=rand()%6+1;
				printf("Computer rolled the dice: %d\n",zar);
				if(zar>=1&&zar<=3)
					buy_property(&pilot->block_,computer);
				else
					me_sira=1;
					
			}
		}
		else if(me_sira!=1&&pilot->block_.owner.type==cap)
		{
			if(count_properties(*computer)>=4)
			{
				zar=roll_dice();
				printf("Computer rolled the dice: %d\n",zar);
				if(zar>=1&&zar<=3)
				{
					if(build_house(&pilot->block_,computer)==1)
						printf("Computer build a house on this block!\n");
					else
						printf("Computer don't have permission to build house on this block!\n");
				}
				else
				{
					me_sira=1;
				}
			}
			else
			{
				me_sira=1;
			}
		}
		else if(me_sira!=1&&pilot->block_.owner.type==car)
		{
			pay_rent(head,computer,me);
			if(computer->account==0)
			{
				printf("YOU WIN!!!!!!\n");
				break;		
			}
		}
		else if(me_sira!=1&&pilot->block_.type==tax)
		{
			if(computer->account<pilot->block_.rent)
			{
				while(count_properties(*computer)!=0&&computer->account<pilot->block_.rent)
				{
					com_arsa_sat(head,computer,pilot->block_.rent);
				}
				if(computer->account>=pilot->block_.rent)
					computer->account-=pilot->block_.rent;
				else
				{
						printf("YOU WIN!!!!!!\n");
						break;
				}
			}
			
		}
		else if(me_sira!=1&&pilot->block_.type==fortune)
		{
			int kart_id=rand()%5+1;
			if(kart_id==1)
			{
				pilot=head->next;
				while(pilot!=NULL)
				{
					if(pilot->block_.owner.type==computer->type)
					{
						if(build_house(&pilot->block_,computer)==1)
						{
							computer->account+=pilot->block_.house_price;
							break;
						}
					}
					pilot=pilot->next;
				}
			}
			else	if(kart_id==2)
			{
				zar=roll_dice();
				printf("Computer rolled the dice: %d\n",zar);
				if(zar>=1&&zar<=3)
				{
					computer->current_block_id+=2;
					if(computer->current_block_id>23)
					{
						computer->current_block_id=computer->current_block_id%24;
						computer->account+=10000;
					}
						
					
				}
				else
				{
					computer->current_block_id-=2;
					if(computer->current_block_id<0)
						computer->current_block_id+=24;
				}
				
				
			}
			else if(kart_id==3)
			{
				computer->account-=5000;
				
			}
			else if(kart_id==4)
			{
				computer->account-=10000;
				me->account+=10000;
			}
			else if(kart_id==5)
			{
				computer->account+=20000;
			}
			
		}
		
		printf("Your turn\n");
		int selection,next_block,flag;
		printf("1 - Roll the dice\n");
        	printf("2 - Show my account\n");
        	printf("3 - Show my properties\n");
        	printf("4 - Show property deeds\n");
        	printf("5 - Buy Property\n");
        	printf("6 - Buy house \n");
        	printf("7 - Sell property\n");
        	printf("Please select an option to continue (%s):\n",me->player_name);
		scanf("%d",&selection);
        switch(selection)
        {
		case 1:
                if (me->turn_to_wait==0) {
                    next_block=(me->current_block_id + roll_dice());
                    if (next_block>=20)me->account+=10000;
                    me->current_block_id = next_block % 20;
                    after_dice_menu(head,me,computer);
                    flag = 0;
                } else
                {
                    printf("You need to wait %d turn to continue.\n",me->turn_to_wait);
                    me->turn_to_wait-=1;
                    flag=0;
                }
                break;
        case 2:
                printf("\n\nThere are %d $ in your account.\n\n",me->account);
                break;
        case 3:
                show_player_properties(head,*me);
                break;
        case 4:
                show_property_deed(head);
                break;
        case 5:
        		pilot=head;
        		j=0;
        		while(j<me->current_block_id)
        		{
        			pilot=pilot->next;
        			j++;
				}
                if (pilot->block_.type==property && pilot->block_.owner.type==-1)
                buy_property(&pilot->block_,me);
                else
                {
                    printf("You don't have permission to buy this block!\n");
                }

                break;
        case 6:
        		pilot=head;
        		j=0;
        		while(j<me->current_block_id)
        		{
        			pilot=pilot->next;
        			j++;
				}
                if (me->type==pilot->block_.owner.type) {
                    house_dialog(head,me);
                }else
                {
                    printf("You don't have permission to build house on this block!\n");
                }
                break;
        case 7:
                sell_property(head,me);
                break;
            default:
                printf("Wrong selection!\n");
	}		
}
}


int main()
{
	struct link_block *head;
	player computer,me;
	computer.player_name="Cap";
	computer.type=cap;
	computer.current_block_id=0;
    	computer.turn_to_wait=0;
	computer.account=100000;
   	init_owned(&computer);
	me.player_name="Car";
	me.type=car;
	me.current_block_id=0;
    	me.turn_to_wait=0;
	me.account=100000;
        init_owned(&me);
	init_board(&head);
	bubbleSort(&head,24);
	prev_cont(&head);
	show_board(head,computer,me);
	show_properties(head);
	buy_property(&head->next->block_,&computer);
	computer.current_block_id=2;
	buy_property(&head->next->next->block_,&computer);
	show_player_properties(head,computer);
	sell_property(head,&computer);
	show_player_properties(head,computer);
	play_game(head,&computer,&me);
	
	
}




