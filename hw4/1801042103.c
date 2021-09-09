//OZAN GECKIN
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum pokemon {Charmander, Pikachu, Squirtle, Bulbasaur, Pidgeotto, Ratata, Mug, Caterpie, Zubat, Krabby};
enum attack_type {quadratic, linear};
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
void pokedex(char *Pokemon_name[], int range[], enum attack_type type[], int attack_power[], int stamina[]){
	char buf[20];
	printf("Please type name of the Pokémon (type exit to close Pokedex):\n");
	scanf(" %[^\n]s", buf);		//Takes Pokemon name
	enum pokemon i;
	int found = 0;
	for (i = Charmander; i <= Krabby; i = i + 1){		//Finds Pokemon in the Pokemon_name array and prints the data
		if(compare_chars(buf, Pokemon_name[i]) == 1){
			printf("Name	: %s\n", Pokemon_name[i]);
			if(type[i] == 0)
				printf("A. Type : Quadratic\n");
			else
				printf("A. Type : Linear\n");
			printf("Range	: %d\n", range[i]);
			printf("A. Power: %d\n", attack_power[i]);
			printf("Stamina : %d\n", stamina[i]);
			found = 1;
			break;
		}
	} 
	if(found == 0){						//If the pokemon is not in the pokedex
		printf("There is no such pokemon in pokedex\n");
	}
}

void show_Pokemons(char *Pokemon_name[], enum pokemon Pokemons[], int pokemon_count){
	int i, d, counter = 0;
	if(pokemon_count == 4){							//Prints the user's pokemon
		printf("Your Pokemon pocket");
		for(i = 0; i < 4; i = i + 1){				//Counts the number of user's pokemons
			if(Pokemons[i] != -1)
				counter = counter + 1;
		}
		if(counter == 0)
			printf(" is empty. \n");
		else
			printf(":\n");
	}
	else
		counter = 10;
		
	for(i = 0; i < pokemon_count; i = i + 1){		//Prints the pokemons
		if(Pokemons[i] != -1){
			d = Pokemons[i];
			printf("%d - %s\n", d, Pokemon_name[d]);
		}
	}
}

void catch_a_pokemon(char *Pokemon_name[], enum pokemon Pokemons[], enum pokemon *my_pocket){
	int id, i;
	int catched = 0, count = 0;
	printf("Enter the pokemon id that you want to catch: ");
	scanf("%d", &id);				//Takes pokemon id from user
	if(id <=9 && id >=0){			//If pokemon id is valid
		for(i = 0; i < 4; i = i + 1){
			if(my_pocket[i] == id)		//Checks whether the pokemon is already in user's pocket or not
				catched = 1;
			if(my_pocket[i] != -1)
				count += 1;
		}
		if(catched != 1 && count < 4)   //If pokemon is not catched yet and user has not catched 4 pokemons, catch the pokemon
			my_pocket[count] = id;
		if(catched == 1)				//If the pokemon is catched already prints error message
			printf("%s is already catched\n", Pokemon_name[id]);
		if(count == 4)					//If user catched 4 pokemons already, function prints error message
			printf("You already catched 4 Pokemons\n");
	}
	else
		printf("Invalid pokemon id\n");
}

void release_a_pokemon(char *Pokemon_name[], enum pokemon Pokemons[], enum pokemon *my_pocket){
	int id, i, counter = 0, released = 0, j;
	for(i = 0; i < 4; i = i + 1){		//Counts the number of user's pokemons
		if(my_pocket[i] != -1)
			counter = counter + 1;
	}
	if(counter == 0){					//If user has no pokemon in his/her pocket, func prints error message
		printf("You don't have any Pokemons to release.\n");
	}
	else{
		printf("Enter the pokemon id that you want to release: ");
		scanf("%d", &id);				//Takes pokemon id from user to release
		if(id <=9 && id >=0){
			for(i = 0; i < 4; i = i + 1){
				if(my_pocket[i] == Pokemons[id]){		//Pokemon is released
					my_pocket[i] = -1;				
					released = 1;
					counter = counter - 1;
					for(j = i; j < 4; j = j + 1){		//User's pocket is arranged again. Pokemons are slided into the empty slots.
						if(j < counter)
							my_pocket[j] = my_pocket[j+1];
						else
							my_pocket[j] = -1;	
					}			
					break;
				}
			}
			if(released != 1)							//Function prints error message if the pokemon is not in the user's pocket
				printf("%s is not in your pocket.\n", Pokemon_name[id]);
		
			else
				printf("%s is released successfully.\n", Pokemon_name[id]);
		}
		else									//Funtion prints error message if pokemon id is not valid
			printf("Invalid pokemon id\n");
	}	
	
 }

void oaks_laboratory(char *Pokemon_name[], enum pokemon Pokemons[], enum pokemon *my_Pokemons){
	int selection = 0, pokemon_count = 0;
	while(selection != 5){
		printf("Welcome to Laboratory of Professor Oak. How can I help you?\n");
		printf("\t1) Show Pokémons\n");
		printf("\t2) Catch a Pokémon\n");
		printf("\t3) Release a Pokémon\n");
		printf("\t4) Show my pocket\n");
		printf("\t5) Back\n");
		printf("Enter the number for selection: ");
		scanf("%d", &selection);						//Takes selection from user
		switch (selection){
			case 1:										//show_Pokemons function is called to show pokedex
				show_Pokemons(Pokemon_name, Pokemons, 10);
				break;
			case 2:										//show_Pokemons and catch_a_pokemon functions are called
				show_Pokemons(Pokemon_name, Pokemons, 10);
				catch_a_pokemon(Pokemon_name, Pokemons, my_Pokemons);
				pokemon_count++;
				break;
			case 3:										//show_Pokemons and release_a_pokemon functions are called
				show_Pokemons(Pokemon_name, my_Pokemons, 4);
				release_a_pokemon(Pokemon_name, Pokemons, my_Pokemons);
				pokemon_count--;
				break;
			case 4:										//show_Pokemons function is called to show user's pokemons
				show_Pokemons(Pokemon_name, my_Pokemons, 4);
				break;
			case 5:
				printf("Oak's lab is closed\n");
		}
	}	
}
void show_area(char *Pokemon_name[],int area[8][8],int pokemon_staminas_view[8][8]){
	int i, j;
	int n = 0, s = 0;
	for(i = 0; i < 25; i = i + 1){			//Area is printed out
		if(i % 3 == 0)
			printf("-----------------------------------------------------------------\n");
		else if(i % 3 == 1){
			printf("|");
			for(j = 0; j < 8; j = j + 1){
				if(area[n][j] == -1)
					printf("\t|");
				else{
					int buff = area[n][j];
					printf(" %c%c\t|", Pokemon_name[buff][0], Pokemon_name[buff][1]);
				}	
			}
			printf("\n");
			n += 1;
		}
		else{
			printf("|");
			for(j = 0; j < 8; j = j + 1){	
				if(pokemon_staminas_view[s][j] <= 0)
					printf("\t|");
				else
					printf("(%d) |", pokemon_staminas_view[s][j]);					
			}
			s += 1;
			printf("\n");
		}
	}	
}
void battle(char *Pokemon_name[], int range[], enum attack_type type[], int attack_power[], int stamina[], enum pokemon user_Pokemons[]){
	int rid, pok, i, j, uRow, uColm, counter = 0, aic = 4, aipok;
	int urows[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
	int ucols[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
	int arows[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
	int acols[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
	int pokemon_staminas_view[8][8] = {0};
	srand(time(NULL));
	enum pokemon ai_Pokemons[4] = {-1, -1, -1, -1};
	int area[8][8] = {{-1, -1, -1, -1, -1, -1, -1, -1},{-1, -1, -1, -1, -1, -1, -1, -1},{-1, -1, -1, -1, -1, -1, -1, -1},{-1, -1, -1, -1, -1, -1, -1, -1},{-1, -1, -1, -1, -1, -1, -1, -1},{-1, -1, -1, -1, -1, -1, -1, -1},{-1, -1, -1, -1, -1, -1, -1, -1},{-1, -1, -1, -1, -1, -1, -1, -1}};
	for(i = 0; i < 4; i = i + 1){			//User's pokemons are counted
		if(user_Pokemons[i] != -1)
			counter = counter + 1;
	}
	printf("Locate your Pokemons\n");
	for(i = 0; i < counter; i = i + 1){
		int located = 0;
		while(located != 1){
			printf("Locate %s to row (0 or 1): ", Pokemon_name[user_Pokemons[i]]);
			scanf("%d", &uRow);				//Row number is taken from user
			while(uRow != 0 && uRow != 1){	//If row number is against to rules, a valid row number is asked to user
				printf("Enter valid row number: ");
				scanf("%d", &uRow);
			}
			printf("Locate %s to column (0-7): ", Pokemon_name[user_Pokemons[i]]);
			scanf("%d", &uColm);			//Column number is taken from user
			while(uColm < 0 || uColm > 7){	//If column number is against to rules, a valid column number is asked to user
				printf("Enter valid column number: ");
				scanf("%d", &uColm);
			}
			if(area[uRow][uColm] == -1){		//If the desired location is empty, then pokemons is located into there.
				area[uRow][uColm] = user_Pokemons[i];
				urows[user_Pokemons[i]] = uRow;			//Row number is written to the userrows array
				ucols[user_Pokemons[i]] = uColm;		//Column number is written to the usercolumns array
				pokemon_staminas_view[uRow][uColm] = stamina[user_Pokemons[i]];		//Stamina array is arranged
				located = 1;
				printf("%s is located to area[%d][%d] successfully\n", Pokemon_name[user_Pokemons[i]], uRow, uColm);
			}
			else								//If there is another pokemon in the location, function prints warning message
				printf("There is another Pokemon in that location.\n");
		}
	}
	for(i = 0; i < 4; i = i + 1){				//AI selects pokemon randomly
		int catched = 0, loc = 0;
		while(catched == 0){
			int dif = 0;
			rid = rand() % 10;
			for(j = 0; j < counter; j = j + 1){		//User's pokemons are checked to not select same pokemons with user
				if(user_Pokemons[j] != rid)
					dif = dif + 1;
			}
			for(j = 0; j < i; j = j + 1){			//AI's pokemons are checked to not select same pokemons that are already selected		
				if(ai_Pokemons[j] != rid)
					dif = dif + 1;
			}
			if(dif == counter + i){					//If the pokemon is not selected by AI or user yet, pokemon is selected 
				catched = 1;
				ai_Pokemons[i] = rid;
				while(loc == 0){					//Pokemon is located randomly into the area
					int r, c;
					r = rand() % 2;
					r = r + 6;
					c = rand() % 8;
					if(area[r][c] == -1){
						area[r][c] = ai_Pokemons[i];
						arows[ai_Pokemons[i]] = r;
						acols[ai_Pokemons[i]] = c;
						pokemon_staminas_view[r][c] = stamina[ai_Pokemons[i]];
						loc = 1;
					}
				}
			}
		}
		
	}
		show_area(Pokemon_name, area, pokemon_staminas_view);
	while(aic > 0 && counter > 0){				//Until AI or user has no pokemon in the area
		int ruled, b, sbuf;
		int violated = 0;
		char dir;
		do{										//User's turn
			for(i = 0; i < counter; i = i + 1)
				printf("%d - %s\n", i, Pokemon_name[user_Pokemons[i]]); 
			printf("Select Pokemon to rule: ");
			scanf("%d", &ruled);				//User selects pokemon to rule
			pok = user_Pokemons[ruled];
			printf("Select direction to move the Pokemon (u,d,l,r):\n");
			scanf(" %c", &dir);
			printf("Select amount of block to move the Pokemon (1 or 2): ");
			scanf("%d", &b);					//User selects direction and amount of blocks
			if(dir == 'u'){						//Up direction
				if(urows[pok] - b < 0){
					printf("Area borders are violated\n");
					violated = 1;
				}
				else if(area[urows[pok] - b][ucols[pok]] != -1){
					printf("Another pokemon is there!!\n");
					violated = 1;
				}
				else{							//Move the pokemon
					violated = 0;
					sbuf = pokemon_staminas_view[urows[pok]][ucols[pok]];
					pokemon_staminas_view[urows[pok]][ucols[pok]] = 0;		//Stamina array is rearranged
					area[urows[pok]][ucols[pok]] = -1;
					urows[pok] = urows[pok] - b;
					area[urows[pok]][ucols[pok]] = pok;						//Area is rearranged
					pokemon_staminas_view[urows[pok]][ucols[pok]] = sbuf;
				}					
			}
			else if(dir == 'd'){				//Down direction
				if(urows[pok] + b > 7){
					printf("Area borders are violated\n");
					violated = 1;
				}
				else if(area[urows[pok] + b][ucols[pok]] != -1){
					printf("Another pokemon is there!!\n");
					violated = 1;
				}
				else{							//Move the pokemon
					violated = 0;
					sbuf = pokemon_staminas_view[urows[pok]][ucols[pok]];		//Stamina array is rearranged
					pokemon_staminas_view[urows[pok]][ucols[pok]] = 0;
					area[urows[pok]][ucols[pok]] = -1;
					urows[pok] = urows[pok] + b;
					area[urows[pok]][ucols[pok]] = pok;							//Area is rearranged
					pokemon_staminas_view[urows[pok]][ucols[pok]] = sbuf;
				}		
			}
			else if(dir == 'l'){				//Left direction
				if(ucols[pok] - b < 0){
					printf("Area borders are violated\n");
					violated = 1;
				}
				else if(area[urows[pok]][ucols[pok] - b] != -1){
					printf("Another pokemon is there!!\n");
					violated = 1;
				}
				else{							//Move the pokemon
					violated = 0;
					sbuf = pokemon_staminas_view[urows[pok]][ucols[pok]];
					pokemon_staminas_view[urows[pok]][ucols[pok]] = 0;			//Stamina array is rearranged
					area[urows[pok]][ucols[pok]] = -1;
					ucols[pok] = ucols[pok] - b;
					area[urows[pok]][ucols[pok]] = pok;							//Area is rearranged
					pokemon_staminas_view[urows[pok]][ucols[pok]] = sbuf;
				}					
			}
			else if(dir == 'r'){				//Right direction
				if(ucols[pok] + b > 7){
					printf("Area borders are violated\n");
					violated = 1;
				}
				else if(area[urows[pok]][ucols[pok] + b] != -1){
					printf("Another pokemon is there!!\n");
					violated = 1;
				}
				else{							//Move the pokemon
					violated = 0;
					sbuf = pokemon_staminas_view[urows[pok]][ucols[pok]];
					pokemon_staminas_view[urows[pok]][ucols[pok]] = 0;			//Stamina array is rearranged
					area[urows[pok]][ucols[pok]] = -1;
					ucols[pok] = ucols[pok] + b;
					area[urows[pok]][ucols[pok]] = pok;							//Area is rearranged
					pokemon_staminas_view[urows[pok]][ucols[pok]] = sbuf; 
				}
			}
			else
				printf("Invalid direction\n");
		}while(violated == 1);					//Until user enters a valid movement
		
		if(type[pok] == 0){						//If attack type is quadratic
			for(i = 0; i < aic; i = i + 1){
				int apok = ai_Pokemons[i];
				int dist = abs(arows[apok] - urows[pok]) + abs(acols[apok] - ucols[pok]);		//Calculate distance
				if(range[pok] >= dist){				//Attack all the pokemons of AI that are in the range of user's ruled pokemon
					pokemon_staminas_view[arows[apok]][acols[apok]] -= attack_power[pok];
					if(pokemon_staminas_view[arows[apok]][acols[apok]] <= 0){		//If pokemon's stamina is less than or equal to 0
						area[arows[apok]][acols[apok]] = -1;				//Remove it from area
						aic--;
						for(j = i; j < 4; j = j + 1){						//Remove it from ai's pokemon pocket
							if(j < aic)
								ai_Pokemons[j] = ai_Pokemons[j+1];
							else
								ai_Pokemons[j] = -1;	
						}
						arows[apok] = -1;					//Remove the coordinates from airows and aicolumns arrays
						acols[apok] = -1;
					}
				}		
			}		
		}
		else if(type[pok] == 1){			//If attack type is linear
			int mdist = 99;
			for(i = 0; i < aic; i = i + 1){		//Find the minimum distance
				int apok = ai_Pokemons[i];
				int dist = abs(arows[apok] - urows[pok]) + abs(acols[apok] - ucols[pok]);
				if(dist < mdist)
					mdist = dist;
			}
			for(i = 0; i < aic; i = i + 1){
				int apok = ai_Pokemons[i];
				int dist = abs(arows[apok] - urows[pok]) + abs(acols[apok] - ucols[pok]);
				if(dist <= mdist && range[pok] >= dist){		//Attack the pokemons with minimum distance if they are in the range of ruled pokemon 
					pokemon_staminas_view[arows[apok]][acols[apok]] -= attack_power[pok];
					if(pokemon_staminas_view[arows[apok]][acols[apok]] <= 0){		//If pokemon's stamina is less than or equal to 0
						area[arows[apok]][acols[apok]] = -1;						//Remove it from area
						aic--;
						for(j = i; j < 4; j = j + 1){								//Remove it from ai's pokemon pocket
							if(j < aic)
								ai_Pokemons[j] = ai_Pokemons[j+1];
							else
								ai_Pokemons[j] = -1;	
						}
						arows[apok] = -1;							//Remove the coordinates from airows and aicolumns arrays
						acols[apok] = -1;
					}
				}
			}
		}
		show_area(Pokemon_name, area, pokemon_staminas_view);		//Shows the are after user's turn
		violated = 0;
		if(aic > 0){				//If ai has pokemon to rule
			do{								//AI's turn
				int rpok = rand() % aic;				//Selects random pokemon to rule
				pok = ai_Pokemons[rpok];
				int rdir = rand() % 4;					//Selects direction randomly
				b = rand() % 2;							//Selects amount of blocks randomly
				b += 1;
				if(rdir == 0){							//Up direction
					if(arows[pok] - b < 0)				//Checks the border violation
						violated = 1;
					else if(area[arows[pok] - b][acols[pok]] != -1)		//Checks whether there is a pokemon or not
						violated = 1;
					else{								//AI moves the pokemon and rearranges area and staminas arrays 
						violated = 0;
						sbuf = pokemon_staminas_view[arows[pok]][acols[pok]];
						pokemon_staminas_view[arows[pok]][acols[pok]] = 0;
						area[arows[pok]][acols[pok]] = -1;
						arows[pok] = arows[pok] - b;
						area[arows[pok]][acols[pok]] = pok;	
						pokemon_staminas_view[arows[pok]][acols[pok]] = sbuf;
					}					
				}
				else if(rdir == 1){				//Down direction
					if(arows[pok] + b > 7){		//Checks the border violation
						violated = 1;
					}
					else if(area[arows[pok] + b][acols[pok]] != -1)		//Checks whether there is a pokemon or not
						violated = 1;
					else{						//AI moves the pokemon and rearranges area and staminas arrays 
						violated = 0;
						sbuf = pokemon_staminas_view[arows[pok]][acols[pok]];
						pokemon_staminas_view[arows[pok]][acols[pok]] = 0;
						area[arows[pok]][acols[pok]] = -1;
						arows[pok] = arows[pok] + b;
						area[arows[pok]][acols[pok]] = pok;	
						pokemon_staminas_view[arows[pok]][acols[pok]] = sbuf;
					}		
				}
				else if(rdir == 2){			//Left direction
					if(acols[pok] - b < 0){		//Checks the border violation
						violated = 1;
					}
					else if(area[arows[pok]][acols[pok] - b] != -1)	//Checks whether there is a pokemon or not
						violated = 1;
					else{						//AI moves the pokemon and rearranges area and staminas arrays 
						violated = 0;
						sbuf = pokemon_staminas_view[arows[pok]][acols[pok]];
						pokemon_staminas_view[arows[pok]][acols[pok]] = 0;
						area[arows[pok]][acols[pok]] = -1;
						acols[pok] = acols[pok] - b;
						area[arows[pok]][acols[pok]] = pok;
						pokemon_staminas_view[arows[pok]][acols[pok]] = sbuf;
					}					
				}
				else if(rdir == 3){			//Right direction
					if(acols[pok] + b > 7){		//Checks the border violation
						violated = 1;
					}
					else if(area[arows[pok]][acols[pok] + b] != -1)		//Checks whether there is a pokemon or not
						violated = 1;
					else{									//AI moves the pokemon and rearranges area and staminas arrays 
						violated = 0;
						sbuf = pokemon_staminas_view[arows[pok]][acols[pok]];
						pokemon_staminas_view[arows[pok]][acols[pok]] = 0;
						area[arows[pok]][acols[pok]] = -1;
						acols[pok] = acols[pok] + b;
						area[arows[pok]][acols[pok]] = pok;	
						pokemon_staminas_view[arows[pok]][acols[pok]] = sbuf;
					}
				}
			}while(violated == 1);		//Until AI finds a valid move
			int apok = pok; 
			if(type[apok] == 0){			//If attack type is quadratic, the ruled pokemon attacks the all pokemons of user that are in the range
				for(i = 0; i < aic; i = i + 1){
					pok = user_Pokemons[i];
					int dist = abs(arows[apok] - urows[pok]) + abs(acols[apok] - ucols[pok]);
					if(range[apok] >= dist){
						pokemon_staminas_view[urows[pok]][ucols[pok]] -= attack_power[apok];
						if(pokemon_staminas_view[urows[pok]][ucols[pok]] <= 0){		//If pokemon's stamina is less than or equal to 0, remove it from area and user's pocket.
							area[urows[pok]][ucols[pok]] = -1;
							counter--;
							for(j = i; j < 4; j = j + 1){
								if(j < counter)
									user_Pokemons[j] = user_Pokemons[j+1];
								else
									user_Pokemons[j] = -1;	
							}
							urows[pok] = -1;
							ucols[pok] = -1;
						}
					}		
				}		
			}
			else if(type[apok] == 1){		//If attack type is linear, the ruled pokemon attacks the all pokemons of user with min distance that are in the range of it
				int mdist = 99;
				for(i = 0; i < counter; i = i + 1){			//Calculate min distance
					pok = user_Pokemons[i];
					int dist = abs(arows[apok] - urows[pok]) + abs(acols[apok] - ucols[pok]);
					if(dist < mdist)
						mdist = dist;
				}
				for(i = 0; i < aic; i = i + 1){
					pok = user_Pokemons[i];
					int dist = abs(arows[apok] - urows[pok]) + abs(acols[apok] - ucols[pok]);
					if(dist <= mdist && range[apok] >= dist){				
						pokemon_staminas_view[urows[pok]][ucols[pok]] -= attack_power[apok];
						if(pokemon_staminas_view[urows[pok]][ucols[pok]] <= 0){		//If pokemon's stamina is less than or equal to 0, remove it from area and user's pocket.
							area[urows[pok]][ucols[pok]] = -1;
							counter--;
							for(j = i; j < 4; j = j + 1){
								if(j < counter)
									user_Pokemons[j] = user_Pokemons[j+1];
								else
									user_Pokemons[j] = -1;	
							}
							urows[pok] = -1;
							ucols[pok] = -1;
						}
					}
				}
			}
		}
		show_area(Pokemon_name, area, pokemon_staminas_view);			//Area is printed after AI's turn
	}
	if(aic <= 0)						//Checks the result
		printf("User wins\n");
	else
		printf("User loses\n");
}

void print_menu(char *Pokemon_name[], int range[], enum attack_type type[], int attack_power[], int stamina[], enum pokemon Pokemons[], enum pokemon *my_Pokemons){
	int sel = 5;
	while(sel != 0){
		printf("Please select an option to continue: (0 to exit)\n\n");
		printf("1) Open Pokedex\n");
		printf("2) Go to Oak’s Laboratory\n");
		printf("3) Enter the tournament\n");
		printf("Selection: ");
		scanf("%d", &sel);			//Takes selection from user
		
		if(sel == 0)
			break;
		else if(sel == 1)
			pokedex(Pokemon_name, range, type, attack_power, stamina);
		else if(sel == 2)
			oaks_laboratory(Pokemon_name, Pokemons, my_Pokemons);
		else if(sel == 3)
			battle(Pokemon_name, range, type, attack_power, stamina, my_Pokemons);
		else
			printf("Selection you made is not valid.\n");
		 
	}
	
}

int main(){
	char *Pokemon_name[10] = {"Charmander", "Pikachu", "Squirtle", "Bulbasaur", "Pidgeotto", "Ratata", "Mug", "Caterpie", "Zubat", "Krabby"};
	int range[10] = {1, 3, 4, 3, 2, 2, 1, 2, 3, 2};
	enum attack_type type[10] = {quadratic, linear, linear, linear, quadratic, linear, quadratic, quadratic, linear, linear};
	int attack_power[10] = {500, 350, 300, 400, 250, 250, 350, 200, 350, 300};
	int stamina[10] = {2200, 1500, 1700, 2500, 1900, 2500, 3000, 1200, 1250, 2600};
	enum pokemon Pokemons[10] = {Charmander, Pikachu, Squirtle, Bulbasaur, Pidgeotto, Ratata, Mug, Caterpie, Zubat, Krabby};
	enum pokemon my_Pokemons[4] = {-1, -1, -1, -1};
	print_menu(Pokemon_name, range, type, attack_power, stamina, Pokemons, my_Pokemons); 
	return 0;
}
