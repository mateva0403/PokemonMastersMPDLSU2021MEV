#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "string.h" // FOR STRINGS, WATCHED YOUTUBE TUTORIAL FOR STRINGS

/*
	strikeAttack is used to deduct a random number of health points between 10 and 20 from a target
	@param *ptrnTarget - a pointer for the int containing the target's health
	@param *ptrnStrikeDamage - a pointer for the int containing the strike damage of the attack
	@param nEnemyType - an integer containing the enemy type of the attacker
*/

void strikeAttack (int *ptrnTarget, int *ptrnStrikeDamage, int nEnemyType){
	
	switch (nEnemyType){
		case 1:
			*ptrnStrikeDamage = 15 + rand() % 15;
			break;
		case 2:
			*ptrnStrikeDamage = 15 + rand() % 10;
			break;
		case 3:
			*ptrnStrikeDamage = 10 + rand() % 10;
			break;
		case 4: // Note: Player counts as type 4 as enemy basic trainer and player trainer have the same stats
			*ptrnStrikeDamage = 10 + rand() % 10;
			break;
		default:
			break;
	}
	
	*ptrnTarget -= *ptrnStrikeDamage;
	
}

/*
	techAttack is used to randomly decide whether the target's flinch status is increased.
	@param *ptrnTargetFlinchStatus - a pointer for the int containing the target's flinch status.
	@param nEnemyType - an integer containing the enemy type of the attacker
*/

void techAttack (int *ptrnTargetFlinchStatus, int nEnemyType){
	
	int nFlinchChance = rand() % 100;
	
	// Flinch chance change per enemy type
	switch(nEnemyType){
		case 1:
			if (nFlinchChance <= 15) {
				*ptrnTargetFlinchStatus = 2;
			}
			break;
		case 2:
			if (nFlinchChance <= 30) {
				*ptrnTargetFlinchStatus = 2;
			}
			break;
		case 3:
			if (nFlinchChance <= 20) {
				*ptrnTargetFlinchStatus = 2;
			}
			break;
		case 4:
			if (nFlinchChance <= 20) {
				*ptrnTargetFlinchStatus = 2;
			}
		default:
			break;
	}
	
	
}

/*
	nSupportHeal is an int containing a random number from 8 to 15 which will be added to ally sync pairs' health points.
*/

int nSupportHeal(){
	return 8 + rand() % 7;
}

/*
	getReward gives out gems per floor range the player is in.
	@param *ptrnBattleVillaFloor - pointer for integer containing the current floor of the player
	@param *ptrnGens - pointer for integer containing the amount of gems the player has		
*/

void getReward(int *ptrnBattleVillaFloor, int *ptrnGems){
	if (*ptrnBattleVillaFloor <= 10){
		*ptrnGems += 50;
		printf("\n [SYSTEM MESSAGE]: Obtained 50 Gems.\n");
	}
	else if (*ptrnBattleVillaFloor > 10 && *ptrnBattleVillaFloor <= 15){
		*ptrnGems += 80;
		printf("\n [SYSTEM MESSAGE]: Obtained 80 Gems.\n");
	}
	else if (*ptrnBattleVillaFloor > 15 && *ptrnBattleVillaFloor <= 19){
		*ptrnGems += 100;
		printf("\n [SYSTEM MESSAGE]: Obtained 100 Gems.\n");
	}
	else if (*ptrnBattleVillaFloor == 20){
		*ptrnGems += 500;
		printf("\n [SYSTEM MESSAGE]: Obtained 500 Gems.\n");
	}
}
/*
	getEliteReward gives the player the choice to choose between 3 rewards for defeating the elite trainer on every 5th floor/
	@param *ptrnGens - pointer for integer containing the amount of gems the player has
	@param *ptrnStkHealth - pointer for integer containing the amount of health the current Strike Sync Pair the player is using
	@param *ptrnTechHealth - pointer for integer containing the amount of health the current Tech Sync Pair the player is using
	@param *ptrnSupHealth - pointer for integer containing the amount of health the current Support Sync Pair the player is using
*/
void getEliteReward(int *ptrnGems, int *ptrnStkHealth, int *ptrnTechHealth, int *ptrnSupHealth){
	
	int nEliteRewardInput = -1;
	int nRandomGems = 100 + rand() % 900;
	
	printf("\n     ======================================");
	printf("\n     |             ELITE REWARD           |");
	printf("\n     ======================================");
	printf("\n     | FULL HEAL | 500 GEMS | RANDOM GEMS |");
	printf("\n     =====[1]=========[2]==========[3]=====");
	printf("\n\n [Choose one Elite Reward.]");
	
	while (nEliteRewardInput > 3 || nEliteRewardInput < 1){
		printf("\n [INPUT]: ");
		scanf("%d", &nEliteRewardInput);
	}
	
	switch (nEliteRewardInput){
		
		case 1:
			
			*ptrnStkHealth = 100;
			*ptrnTechHealth = 100;
			*ptrnSupHealth = 100;
			printf("\n [SYSTEM MESSAGE]: Obtained a FULL HEAL and restored all Sync Pairs' Health to 100.\n");
			break;
			
		case 2:
			
			*ptrnGems += 500;
			printf("\n [SYSTEM MESSAGE]: Obtained 500 Gems.");
			break;
			
		case 3:
			
			*ptrnGems += nRandomGems;
			printf("\n [SYSTEM MESSAGE]: Obtained %d Gems.", nRandomGems);
			break;
	}
	
}

/*
	randomTrainer is used to return a random Trainer name string.
*/

char* randomTrainer(){ // Used char* to return strings
	
	int nTrainerSelector = 1 + rand() % 9;	
	
	switch (nTrainerSelector){
		case 1:
			return "Youngster Nunu & Wailmer";
			break;
		case 2:
			return "Biker David & Jynx";
			break;
		case 3:
			return "Camper Hernest & Snorlax";
			break;
		case 4:
			return "Bedan Rocco & Metalgarurumon";
			break;
		case 5:
			return "Expert Luigi & Herdier";
			break;
		case 6:
			return "Sailor Twift & Finneon";
			break;
		case 7:
			return "Rising Star Star and Starly";
			break;
		case 8:
			return "Cyclist Eric & Vaporeon";
			break;
		case 9:
			return "Officer Yellows & Ponyta";
			break;
		case 10:
			return "Idol Raffy & Turtwig";
			break;
		default:
			return "Pokemon";
			break;
	}
	
}

/*
	eliteTrainer is used to return an Elite Trainer's name based on player's selection
	@param nEliteTrainerSelection - an integer containing the selected elite trainer
*/

char* eliteTrainer(int nEliteTrainerSelection){ // Used char* to return strings
	
	switch (nEliteTrainerSelection){
		case 1:
			return "Will & Xatu";
			break;
		case 2:
			return "Karen & Houndoom";
			break;
		case 3:
			return "Glacia & Walrein";
			break;
		case 4:
			return "Flint & Infernape";
			break;
		case 5:
			return "Grimsley & Bisharp";
			break;
		case 6:
			return "Shauntal & Chandelure";
			break;
		case 7:
			return "Acerola & Palossand";
			break;
		case 8:
			return "Siebold & Barbarcle";
			break;
		default:
			return "Pokemon";
			break;
	}
	
}

/*	batleVillaStart is used to start or continue a Battle Villa run.
	@param *ptrnGems - a pointer for the int containing the amount of gems the player has.
	@param *ptrnPlayerStkPairs - a pointer for the int containing the amount of strike pairs the player has.
	@param *ptrnPlayerTechPairs - a pointer for the int containing the amount of tech pairs the player has.
	@param *ptrnPlayerSupPairs - a pointer for the int containing the amount of support pairs the player has.
*/


void battleVillaStart(int *ptrnGems, int *ptrnPlayerStkPairs, int *ptrnPlayerTechPairs, int *ptrnPlayerSupPairs, int *ptrnBattleVillaFloor, int *ptrnStkHealth, int *ptrnTechHealth, int *ptrnSupHealth, int *ptrnNewGame) {
	
	
	// Initialization of Variables
	int nBattleMenuInput = -1, nBattleInput = -1, i = 0, nEnemyHealth, nEndScreenInput = -1, nEliteTrainerInput = -1, nEliteTrainerSelection = -1;
	int nStkFlinch = 0, nTechFlinch = 0, nSupFlinch = 0, nEnemyFlinch = 0;
	int nStrikeDamage = 0, nHeal = 0;
	int nEnemyRandChoice, nEnemyType, nEnemyInput;
	
	char cTrainer[25];
	
	while (nBattleMenuInput != 0){
		
		nBattleMenuInput = -1;
		nStkFlinch = 0; nTechFlinch = 0; nSupFlinch = 0; nEnemyFlinch = 0;
		
		system("cls");
		printf("\n     ============================");
		printf("\n     |       BATTLE VILLA       |");
		printf("\n     ============================");
		printf("\n\n [GEMS: %d]", *ptrnGems);
		printf("\n\n [NEXT FLOOR: %d]\n", *ptrnBattleVillaFloor);
		
		if (*ptrnBattleVillaFloor == 1){
			printf("\n [1] Begin new Battle Villa run");
			printf("\n [0] Return to the Main Menu\n");
		}
		else {
			printf("\n [1] Continue Battle Villa run");
			printf("\n [0] Take a break\n");
		}
		
		while (nBattleMenuInput != 0 && nBattleMenuInput != 1) {
			printf("\n[INPUT]: ");
			scanf("%d", &nBattleMenuInput);
		}
		
		// Battle Event
		if (nBattleMenuInput == 1){
			
			// Decides if Elite Four or Basic Trainer based on floor
			
			if (*ptrnBattleVillaFloor % 5 == 0){ // ELITE FOUR 
				
				system("cls");
				nEliteTrainerInput = -1; nEliteTrainerSelection = -1;
				
				printf("\n     ==============================");
				printf("\n     |        ELITE TRAINER       |");
				printf("\n     ==============================");
				
				printf("\n\n     [Choose 1 Elite Trainer to fight.]");
				
				// Elite Trainer Decider
				switch (*ptrnBattleVillaFloor){
					case 5:
						
						printf("\n\n     [1] [%s]", eliteTrainer(1));
						printf("\n\n     [2] [%s]\n", eliteTrainer(2));
						while (nEliteTrainerInput != 2 && nEliteTrainerInput != 1){
							printf("\n [INPUT]: ");
							scanf("%d", &nEliteTrainerInput);
						}
						if (nEliteTrainerInput == 1){
							nEnemyType = 2; nEliteTrainerSelection = 1;
							strcpy(cTrainer, eliteTrainer(nEliteTrainerSelection));
						}
						else if (nEliteTrainerInput == 2){
							nEnemyType = 1; nEliteTrainerSelection = 2;
							strcpy(cTrainer, eliteTrainer(nEliteTrainerSelection));
						}
						break;
					case 10:
						
						printf("\n\n     [1] [%s]", eliteTrainer(3));
						printf("\n\n     [2] [%s]\n", eliteTrainer(4));
						while (nEliteTrainerInput != 2 && nEliteTrainerInput != 1){
							printf("\n [INPUT]: ");
							scanf("%d", &nEliteTrainerInput);
						}
						if (nEliteTrainerInput == 1){
							nEnemyType = 3; nEliteTrainerSelection = 3;
							strcpy(cTrainer, eliteTrainer(nEliteTrainerSelection));
						}
						else if (nEliteTrainerInput == 2){
							nEnemyType = 1; nEliteTrainerSelection = 4;
							strcpy(cTrainer, eliteTrainer(nEliteTrainerSelection));
						}
						break;
					case 15:
						
						printf("\n\n     [1] [%s]", eliteTrainer(5));
						printf("\n\n     [2] [%s]\n", eliteTrainer(6));
						while (nEliteTrainerInput != 2 && nEliteTrainerInput != 1){
							printf("\n [INPUT]: ");
							scanf("%d", &nEliteTrainerInput);
						}
						if (nEliteTrainerInput == 1){
							nEnemyType = 2; nEliteTrainerSelection = 5;
							strcpy(cTrainer, eliteTrainer(nEliteTrainerSelection));
						}
						else if (nEliteTrainerInput == 2){
							nEnemyType = 3; nEliteTrainerSelection = 6;
							strcpy(cTrainer, eliteTrainer(nEliteTrainerSelection));
						}
						break;
					case 20:
						
						printf("\n\n     [1] [%s]", eliteTrainer(7));
						printf("\n\n     [2] [%s]\n", eliteTrainer(8));
						while (nEliteTrainerInput != 2 && nEliteTrainerInput != 1){
							printf("\n [INPUT]: ");
							scanf("%d", &nEliteTrainerInput);
						}
						if (nEliteTrainerInput == 1){
							nEnemyType = 3; nEliteTrainerSelection = 7;
							strcpy(cTrainer, eliteTrainer(nEliteTrainerSelection));
						}
						else if (nEliteTrainerInput == 2){
							nEnemyType = 1; nEliteTrainerSelection = 8;
							strcpy(cTrainer, eliteTrainer(nEliteTrainerSelection));
						}
						break;
				}
				// End of Elite Trainer Decider
				
			}
			
			else if (*ptrnBattleVillaFloor % 5 != 0){ // BASIC TRAINER
				
				nEnemyType = 4;
				strcpy(cTrainer, randomTrainer());
	
			}
			
			// Enemy Health based on Type
			
			switch (nEnemyType){
				case 1:
					nEnemyHealth = 100;
					break;
				case 2:
					nEnemyHealth = 150;
					break;
				case 3:
					nEnemyHealth = 200;
					break;
				case 4:
					nEnemyHealth = 100;
					break;
			}
			
			system("cls");
			
							
			// New Game Plus Health Added
			for (i = 0; i < *ptrnNewGame; i++){
					nEnemyHealth += 25;
			}
				
			do {
				nBattleInput = -1;
				
				// Flinching Statuses
				if (nEnemyFlinch > 0){
					nEnemyFlinch -= 1;
				}
				else if (nStkFlinch > 0){
					nStkFlinch -= 1;
				}
				else if (nTechFlinch > 0){
					nTechFlinch -= 1;
				}
				else if (nSupFlinch > 0){
					nSupFlinch -= 1;
				}
				// End of Flinching Statuses

				// Replenish Sync Pairs
				if (*ptrnStkHealth == 0 && *ptrnPlayerStkPairs > 0){
					*ptrnPlayerStkPairs -= 1;
					*ptrnStkHealth = 100;
					printf("\n [SYSTEM MESSAGE]: Replenished 1 Strike Sync Pair.\n");
				}
				if (*ptrnTechHealth == 0 && *ptrnPlayerTechPairs > 0){
					*ptrnPlayerTechPairs -= 1;
					*ptrnTechHealth = 100;
					printf("\n [SYSTEM MESSAGE]: Replenished 1 Tech Sync Pair.\n");
				}
				if (*ptrnSupHealth == 0 && *ptrnPlayerSupPairs > 0){
					*ptrnPlayerSupPairs -= 1;
					*ptrnSupHealth = 100;
					printf("\n [SYSTEM MESSAGE]: Replenished 1 Support Sync Pair. \n");
				}
				
				// Display			
				printf("\n             =============");
				printf("\n             |     O     |");
				printf("\n             |    |||_o  |");
				printf("\n             |     ||    |");
				printf("\n             =============\n");
				printf("\n              ");
					
				// Enemy Health Bar
				for (i = 0; i < nEnemyHealth; i += 25){
					printf("[] ");
				}
				printf("\n\n               [HP: %d]", nEnemyHealth);
					
				printf("\n\n      [ENEMY: %s]\n", cTrainer);
				printf("\n      ==[1]==   ==[2]==   ==[3]==");
				printf("\n      | STK |   | TEC |   | SUP |");
				printf("\n      =======   =======   =======");
				printf("\n      | %03d |   | %03d |   | %03d |", *ptrnPlayerStkPairs, *ptrnPlayerTechPairs, *ptrnPlayerSupPairs);
				printf("\n      =======   =======   =======\n");
				printf("\n                [4] Run");
				
				// Player Sync Pair Health Bars	
				printf("\n\n [STRIKE PAIR HEALTH:] : ");
				for (i = 0; i < *ptrnStkHealth; i += 25){
					printf("[] ");
				}
				printf("[%d]", *ptrnStkHealth);
					
				printf("\n\n [TECH PAIR HEALTH]   : ");
				for (i = 0; i < *ptrnTechHealth; i += 25){
					printf("[] ");
				}
				printf("[%d]", *ptrnTechHealth);
					
				printf("\n\n [SUPPORT PAIR HEALTH]: ");
				for (i = 0; i < *ptrnSupHealth; i += 25){
					printf("[] ");
				}
				printf("[%d]", *ptrnSupHealth);		
				printf("\n");
				// End of Player Sync Pair Health Bars
				// End of Display
				
				// Input Menu Loops
				while (nBattleInput > 4 || nBattleInput < 1){
						
					printf("\n [INPUT]: ");
					scanf("%d", &nBattleInput);
					if (nBattleInput > 4 || nBattleInput > 1){
						printf("\n [SYSTEM MESSAGE]: Invalid Input.\n");
					}
					switch (nBattleInput){
						case 1:
							if (*ptrnPlayerStkPairs == 0 && *ptrnStkHealth == 0){
								nBattleInput = -1;
								printf("\n [SYSTEM MESSAGE]: All Strike Sync Pairs have fainted!\n");
							}
							break;
						case 2:
							if (*ptrnPlayerTechPairs == 0 && *ptrnTechHealth == 0){
								nBattleInput = -1;
								printf("\n [SYSTEM MESSAGE]: All Tech Sync Pairs have fainted!\n");
							}
							break;
						case 3:
							if (*ptrnPlayerSupPairs == 0 && *ptrnSupHealth == 0){
								nBattleInput = -1;
								printf("\n [SYSTEM MESSAGE]: All Support Sync Pairs have fainted!\n");
							}
							break;
					}
					
						
				}
				// End of Input Menu Loops
					
				// Player's Turn
					
				switch (nBattleInput){
					case 1:
						system("cls");
						strikeAttack(&nEnemyHealth, &nStrikeDamage, 4);
						if (nEnemyHealth < 0){
							nEnemyHealth = 0;
						}
						printf("\n [SYSTEM MESSAGE]: Your Strike Pair attacked the enemy sync pair for %d damage!", nStrikeDamage);
						break;
					case 2:
						system("cls");
						if (nEnemyFlinch > 0){
							printf("\n [SYSTEM MESSAGE]: The enemy is already flinching!");
						}
						else {
							techAttack(&nEnemyFlinch, 4);
							if (nEnemyFlinch > 0){
								printf("\n [SYSTEM MESSAGE]: The enemy was succesfully flinched!");
							}
							else if (nEnemyFlinch == 0){
								printf("\n [SYSTEM MESSAGE]: The tech attack failed and the enemy didn't flinch.");
							}
						}
						break;
					case 3:
						system("cls");
						
						nHeal = nSupportHeal();
						
						if (*ptrnStkHealth != 0){
							*ptrnStkHealth += nHeal;
						}
						if (*ptrnTechHealth != 0){
							*ptrnTechHealth += nHeal;
						}
						if (*ptrnSupHealth != 0){
							*ptrnSupHealth += nHeal;
						}
						
						if (*ptrnStkHealth > 100){
							*ptrnStkHealth = 100;
						}
						if (*ptrnTechHealth > 100 ){
							*ptrnTechHealth = 100;
						}	
						if (*ptrnSupHealth > 100){
							*ptrnSupHealth = 100;
						}
						
						printf("\n [SYSTEM MESSAGE]: All sync pairs have been healed for %d health points.", nHeal);
						
						break;
					case 4:
						system("cls");
						break;
				}
				
				printf("\n [SYSTEM MESSAGE]: The player's turn ends.\n");
					
				// Enemy's Turn
				
				// Enemy Choice Randomizer based on Type
				nEnemyRandChoice = 1 + rand() % 99;
				switch(nEnemyType){
					case 1:
						if (nEnemyRandChoice <= 85){
							nEnemyInput = 1;
						}
						else if (nEnemyRandChoice <= 95 && nEnemyRandChoice > 85){
							nEnemyInput = 2;
						}
						else if (nEnemyRandChoice >= 96){
							nEnemyInput = 3;
						}
						break;
					case 2:
						if (nEnemyRandChoice <= 60){
							nEnemyInput = 1;
						}
						else if (nEnemyRandChoice > 60){
							nEnemyInput = 2;
						}
						break;
					case 3:
						if (nEnemyRandChoice <= 60){
							nEnemyInput = 1;
						}
						else if (nEnemyRandChoice <= 95 && nEnemyRandChoice > 60){
							nEnemyInput = 2;
						}
						else if (nEnemyRandChoice >= 96){
							nEnemyInput = 3;
						}
						break;
					case 4:
						if (nEnemyRandChoice <= 50){
							nEnemyInput = 1;
						}
						else if (nEnemyRandChoice <= 90 && nEnemyRandChoice > 50){
							nEnemyInput = 2;
						}
						else if (nEnemyRandChoice >= 91){
							nEnemyInput = 3;
						}
						break;
				} 	
				// End of Enemy Choice Randomizer
				
				// Enemy Attacks and Moves
				if (nEnemyFlinch > 0 || nBattleInput == 4){
					printf("\n [SYSTEM MESSAGE:] The enemy is flinching!");
				}
				else if (nEnemyFlinch == 0) {
					// Strike Attack
					if (nEnemyInput == 1){
						if (nBattleInput == 1){
							strikeAttack(ptrnStkHealth, &nStrikeDamage, nEnemyType);
							if (*ptrnStkHealth < 0){
								*ptrnStkHealth = 0;
							}
							printf("\n [SYSTEM MESSAGE]: The enemy attacks your Strike Sync Pair for %d damage!", nStrikeDamage);
						}
						else if (nBattleInput == 2){
							strikeAttack(ptrnTechHealth, &nStrikeDamage, nEnemyType);
							if (*ptrnTechHealth < 0){
								*ptrnTechHealth = 0;
							}
							printf("\n [SYSTEM MESSAGE]: The enemy attacks your Tech Sync Pair for %d damage!", nStrikeDamage);
						}
						else if (nBattleInput == 3){
							strikeAttack(ptrnSupHealth, &nStrikeDamage, nEnemyType);
							if (*ptrnSupHealth < 0){
								*ptrnSupHealth = 0;
							}
							printf("\n [SYSTEM MESSAGE]: The enemy attacks your Support Sync Pair for %d damage!", nStrikeDamage);
						}
					}
					// Tech Attack
					else if (nEnemyInput == 2){
						if (nBattleInput = 1){ // This conditional chooses a target based on last valid input of player or last Sync Pair used.
							techAttack(&nStkFlinch, nEnemyType);
								if (nStkFlinch > 0){
									printf("\n [SYSTEM MESSAGE]: Your Strike Sync Pair flinched due to the enemy's Tech Attack!");
								}
								else if (nEnemyFlinch == 0){
									printf("\n [SYSTEM MESSAGE]: The enemy's Tech Attack failed!");
								}
						}
						else if (nBattleInput == 2){
							techAttack(&nTechFlinch, nEnemyType);
								if (nTechFlinch > 0){
									printf("\n [SYSTEM MESSAGE]: Your Tech Sync Pair flinched due to the enemy's Tech Attack!");
								}
								else if (nEnemyFlinch == 0){
									printf("\n [SYSTEM MESSAGE]: The enemy's Tech Attack failed!");
								}
						}
						else if (nBattleInput == 3){
							techAttack(&nSupFlinch, nEnemyType);
								if (nSupFlinch > 0){
									printf("\n [SYSTEM MESSAGE]: Your Support Sync Pair flinched due to the enemy's Tech Attack!");
								}
								else if (nEnemyFlinch == 0){
									printf("\n [SYSTEM MESSAGE]: The enemy's Tech Attack failed!");
								}
						}
					}
					// Support Heal
					else if (nEnemyInput == 3){
						nHeal = nSupportHeal();
						nEnemyHealth += nHeal;
						if (nEnemyHealth > 100){
							nEnemyHealth = 100;
						}
						printf("\n [SYSTEM MESSAGE]: The enemy healed for %d health points!", nHeal);
					}
				
				}
				
				printf("\n [SYSTEM MESSAGE]: The enemy ends their turn.\n");
				// End of Enemy Attacks		
			} while (nEnemyHealth > 0 && nBattleInput != 4);
			
			// End Screen
			
			nEndScreenInput = -1;
			
			if (nEnemyHealth == 0){
				system("cls");
				
				printf("\n [SYSTEM MESSAGE]: %s has fainted.", cTrainer);
				printf("\n [SYSTEM MESSAGE]: You win!");
				
				getReward(ptrnBattleVillaFloor, ptrnGems);
				
				if (*ptrnBattleVillaFloor % 5 == 0){
					getEliteReward(ptrnGems, ptrnStkHealth, ptrnTechHealth, ptrnSupHealth);
				}
				*ptrnBattleVillaFloor += 1;
				
				if (*ptrnBattleVillaFloor > 20){
					printf("\n     ====================================================");
					printf("\n     |       You have completed the Battle Villa!       |");
					printf("\n     ====================================================");
					nBattleMenuInput = 0;
					*ptrnBattleVillaFloor = 1;
					*ptrnNewGame += 1;
				}
				
				
			}
			
			
			
			else if (*ptrnStkHealth == 0 && *ptrnTechHealth == 0 && *ptrnSupHealth == 0 || nBattleInput == 4){
				system("cls");
				
				if (*ptrnStkHealth == 0 && *ptrnTechHealth == 0 && *ptrnSupHealth == 0) {
					printf("\n [SYSTEM MESSAGE]: All your Sync Pairs fainted!");
				}
				else if (nBattleInput == 4){
					printf("\n [SYSTEM MESSAGE]: You ran away!");
				}
				
				printf("\n [SYSTEM MESSAGE]: You lose!");
				*ptrnBattleVillaFloor = 1;
			}
			
			printf("\n\n [0] Continue");
			
			while (nEndScreenInput != 0){
				printf("\n [INPUT]: ");
				scanf("%d", &nEndScreenInput);
			}
			
				
		}
				
	}
}

/*	syncPairs is used to display the amount of Sync Pairs the player owns. 
	@param nGems - an int containing the amount of gems the player has.
	@param nPlayerStkPairs - an int containing the amount of strike pairs the player has.
	@param nPlayerTechPairs - an int containing the amount of tech pairs the player has.
	@param nPlayerSupPairs - an int containing the amount of support pairs the player has.
*/
void syncPairs(int nGems, int nPlayerStkPairs, int nPlayerTechPairs, int nPlayerSupPairs){
	
	system("cls");
	int nSyncMenuInput = -1;
	
	printf("\n     ==========================");
	printf("\n     |       SYNC PAIRS       |");
	printf("\n     ==========================");
	printf("\n");
	printf("\n      ======= ======= =======");
	printf("\n      | %03d | | %03d | | %03d |", nPlayerStkPairs, nPlayerTechPairs, nPlayerSupPairs);
	printf("\n      ======= ======= =======");
	printf("\n      | STK | | TEC | | SUP |");
	printf("\n      ======= ======= =======\n\n");
	printf("\n [0] EXIT\n");
	
	while (nSyncMenuInput != 0){
		printf("\n[INPUT]: ");
		scanf("%d", &nSyncMenuInput);
	}
	system("cls");

}

/*	pokeMart is used to display the shop.
	@param nGems - an int containing the amount of gems the player has.
	@param nPlayerStkPairs - an int containing the amount of strike pairs the player has.
	@param nPlayerTechPairs - an int containing the amount of tech pairs the player has.
	@param nPlayerSupPairs - an int containing the amount of support pairs the player has.
*/
void pokeMart(int *ptrnGems, int *ptrnPlayerStkPairs, int *ptrnPlayerTechPairs, int *ptrnPlayerSupPairs){
	
	system("cls");
	int nMartMenuInput = -1; // This variable is initialized here because it is only used in this function
	
	do {
		
		printf("\n     =====================================");
		printf("\n     |       POKEMART       |            |");
		printf("\n     =====================================");
		printf("\n [1] | Strike Pair:     200 | OWNED: %03d |", *ptrnPlayerStkPairs);
		printf("\n [2] | Tech Pair:       200 | OWNED: %03d |", *ptrnPlayerTechPairs);
		printf("\n [3] | Support Pair:    200 | OWNED: %03d |", *ptrnPlayerSupPairs);
		printf("\n     =====================================\n");
		
		printf("\n [GEMS: %d]", *ptrnGems);
		printf("\n\n [0] EXIT");
		
		printf("\n\n [INPUT]: ");
		scanf("%d", &nMartMenuInput);
		
		// PokeMart Input Evaluation	
		if (nMartMenuInput == 1){
			if (*ptrnGems >= 200){ // If amount of gems is more than or equal to price
				*ptrnGems = *ptrnGems - 200;
				*ptrnPlayerStkPairs = *ptrnPlayerStkPairs + 1;
				system("cls");
				printf(" [SYSTEM MESSAGE]: 1 Strike Pair purchased.\n");
			}
			else { // If amount of gems is less than set price
				system("cls");
				printf(" [SYSTEM MESSAGE]: Insufficient amount of gems. %d more needed.\n", 200 - *ptrnGems);
			}
		}
		else if (nMartMenuInput == 2){
			if (*ptrnGems >= 200){
				*ptrnGems = *ptrnGems - 200;
				*ptrnPlayerTechPairs = *ptrnPlayerTechPairs + 1;
				system("cls");
				printf(" [SYSTEM MESSAGE]: 1 Tech Pair purchased.\n");
			}
			else {
				system("cls");
				printf(" [SYSTEM MESSAGE]: Insufficient amount of gems. %d more needed.\n", 200 - *ptrnGems);
			}
		}
		else if (nMartMenuInput == 3){
			if (*ptrnGems >= 200){
				*ptrnGems = *ptrnGems - 200;
				*ptrnPlayerSupPairs = *ptrnPlayerSupPairs + 1;
				system("cls");
				printf(" [SYSTEM MESSAGE]: 1 Support Pair purchased.\n");
			}
			else {
				system("cls");
				printf(" [SYSTEM MESSAGE]: Insufficient amount of gems. %d more needed.\n", 200 - *ptrnGems);
			}
		}
		else {
			system("cls");
			printf(" [SYSTEM MESSAGE]: Invalid Input.\n");
		}
		// End of Mart Menu Evaluation
		
 	} while (nMartMenuInput != 0);
	system("cls");
	
}

// MAIN

int main(){
	
	// Initialization of variables
	srand(time(NULL));
	
	int nMenuInput =- 1;
	int nGems = 200; // Starter amount of Gems
	int nPlayerStkPairs = 500; int nPlayerTechPairs = 1; int nPlayerSupPairs = 1; // Starter amount of Sync Pairs
	int nTrainerSelector;
	int nNewGame = 0; // this variable increases every time the 20th floor of the battle villa is completed
	
	int nBattleVillaFloor = 15;
	int nStkHealth = 100, nTechHealth = 100, nSupHealth = 100;
	
	// Main menu loops while input is not valid
	while (nMenuInput = -1){
		
		int nMenuInput = -1;
		system("cls");
		printf("\n     =================================================");
		printf("\n\n             POKEMON MASTERS EX: BATTLE VILLA\n");
		printf("\n     =================================================\n");
		
		if (nNewGame > 0){
			printf("\n\n [NEW GAME: %d]", nNewGame);
		}
		
		printf("\n\n [GEMS]: %d\n", nGems);
		printf("\n [1] Battle Villa Run");
		printf("\n [2] PokeMart");
		printf("\n [3] Sync Pairs");
		printf("\n\n [0] EXIT\n");
		
		// main menu input is checked and asks again if input is invalid
		while (nMenuInput > 3 || nMenuInput < 0){
			
			printf("\n [INPUT]: ");
			scanf("%d", &nMenuInput);
			
			switch (nMenuInput){
				case 1: // Menu Option 1: Battle Villa
					battleVillaStart(&nGems, &nPlayerStkPairs, &nPlayerTechPairs, &nPlayerSupPairs, &nBattleVillaFloor, &nStkHealth, &nTechHealth, &nSupHealth, &nNewGame);
					break;
				case 2: // Menu Option 2: Shop or PokeMart
					pokeMart(&nGems, &nPlayerStkPairs, &nPlayerTechPairs, &nPlayerSupPairs);
					break;
				case 3: // Menu Option 3: Show a list of Sync Pairs
					syncPairs(nGems, nPlayerStkPairs, nPlayerTechPairs, nPlayerSupPairs);
					break;
				case 0: // Menu Option 0: Exit the Program
					return 0;
				default:
					break;
					
			}
			
		}
	}

	return 0;
}
