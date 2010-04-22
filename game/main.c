/*
 *project "game"
 *by DarkNik
 *version 0.0.03
 *Alages:
	0.0.03:
		1.pio euxristo perivalon sto game.
		2.diorthosi tis eksodou apo ta menu..
	0.0.02:
		1.diorthosi tou "exit" apo tin maxi.
		2.antikatastasi printf me puts.
		3.efanisi pliroforion tou damage.
	0.0.01:
		1.proti ekdosi tou game.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define epipedo 1
#define xp 20

char name[20];
int lvl=1,hp=10,str=10,xpxara=0,maxhp=10,pnti=5,dmg;	/*arxikes times*/

void menu(int);
void lvlup();
int addpoint();
void plirofories();
int egiriepithesi(int);
void save();
void load();

int main () {
	srand(time(NULL));
	int flag,epilogi,temp;
	int antlvl,anthp,antstr;
	float antdmg;
	system("clear");
	puts("Kalosorisate sto Game...\n"
		 "pieste ena koumpi gia sinexia...");
	getchar();
	do {
		flag=0;
		menu(4);
		scanf("%d",&epilogi);
		system("clear");
		if (epilogi==1) {
			puts("pliktrologiste to onoma sas:");
			scanf("%s",&name[0]);
			save();
			flag=1;
		}
		else if(epilogi==2){
			load();
			flag=1;
		}
	} while (flag==0);
	do {
		flag=0;
		menu(0);
		scanf("%d",&epilogi);
		system("clear");
		getchar();
		switch (epilogi) {
			case 0:
				menu(1);
				break;
			case 1:
				plirofories();
				getchar();
				break;
			case 2:
				antlvl=rand()%((lvl+1)+epipedo)+1;
				anthp=rand()%((antlvl+1)*10+epipedo)+5;
				antstr=rand()%((antlvl+1)+epipedo)+2;
				printf(
					"***** Euresi exthrou *****\n"
					"lvl antipalou:%d\n"
					"Hp antipalou:%d\n"
					"Dinami antipoalou:%d\n"
					"***************************\n"
					"Enarksi maxis....\n"
					"pieste ena koumpi gia sinexia...",antlvl,anthp,antstr);
				getchar();
				do {
					do {
						menu(2);
						scanf("%d",&epilogi);
					}while(egiriepithesi(epilogi)==0);
					switch (epilogi) {
						case 0:
							flag=1;
							break;
						default:
							system("clear");
							puts("Epithesi...");
							anthp-=dmg;
							antdmg=(float)((rand()%10+7.0)/10.0)*antstr;
							hp-=antdmg;
							if (anthp<0) {
								anthp=0;
							}
							if (hp<0) {
								hp=0;
							}
							getchar();
							system("clear");
							printf("***** Plirofories meta tin epithesi *****\n"
								   "Hp	:%d\n"
								   "Dmg:%d\n"
								   "Hp Antipalou:%d\n"
								   "Dmg Antipalou:%.0f\n"
								   "******************************************\n"
								   "pieste ena koumpi gia sinexia...\n",hp,dmg,anthp,antdmg);
							
							if (anthp<=0) {
								flag=1;
								system("clear");
								puts("***** Sixaritiria kerdisate!!! *****\n"
									 "pieste ena koumpi gia sinexia...\n");
								if ((antlvl*3)+hp<=maxhp) {
									hp+=antlvl*3;
								}
								else {
									hp=maxhp;
								}
								xpxara+=antlvl*xp/epipedo;
								lvlup();
							}
							if (hp<=0) {
								flag=1;
							}
							break;
					}
					getchar();
				} while (flag==0);
				epilogi=1;
				break;
			case 3:
				while (flag==0) {
					menu(3);
					scanf("%d",&epilogi);
					system("clear");
					switch (epilogi) {
						case 1:
							temp=addpoint();
							maxhp+=temp;
							hp+=temp;
							break;
						case 2:
							str+=addpoint();
							break;
						case 9:
							system("clear");
							plirofories();
							getchar();
							break;
						case 0:
							flag=1;
							break;
						default:
							break;
					}
					getchar();
					if (pnti==0) {
						flag=1;
						system("clear");
						puts("Den iparxoun aloi ponti gia prosthiki...\n"
							 "pieste ena koumpi gia sinexia...");
						getchar();
					}
				}
				epilogi=1;
				break;
			case 9:
				system("clear");
				puts("apothikeusi dedomenon....");
				save();
				puts("ta dedomena apothikeutikan...\n"
					 "pieste ena koumpi gia sinexia...\n");
				getchar();
				break;

			default:
				break;
		}
		if (hp<=0) {
			puts("***** Game Over *****");
			
			epilogi=0;
		}
	}while(epilogi!=0);
    return 0;
}

void lvlup(){
	int metritis=100,level=1;
	while (xpxara>=metritis) {
		level++;
		metritis*=2;
	}
	if (level!=lvl) {
		pnti+=(level-lvl)*5;
		system("clear");
		printf("**********\n"
			   "Level Up!!!\n"
			   "New lvl:%d\n"
			   "pontoi pou menoun:%d\n"
			   "**********\n"
			   "pieste ena koumpi gia sinexia...",level,pnti);
	}
	lvl=level;
}

int addpoint(){
	int	point;
	do {
	puts("Posous pontous thelete na prosthesete:");
	scanf("%d",&point);
	} while (point<=0);
	if (point>pnti) {
		system("clear");
		printf("Den exete %d postous...\n"
			   "sas exoun mini:%d pontoi\n"
			   "pieste ena koumpi gia sinexia...",point,pnti);
		getchar();
		return 0;
	}
	else {
		system("clear");
		puts("Prosthiki ponton...\n"
			 "pieste ena koumpi gia sinexia...");
		pnti-=point;
		getchar();
		return point;
	}
}

void menu(int epilogi){
	system("clear");
	switch (epilogi) {
		case 0:
			puts("********** MENU **********\n"
				   "0->Exit\n"
				   "1->Efanisi pliroforion\n"
				   "2->Maxi\n"
				   "3->Prosthiki ponton\n"
				   "9->Save Game\n"
				   "**************************\n"
				   "epilekste ena apo ta parapano:");
			break;
		case 1:
			puts("Euxaristoume pou peksate to Game!\n"
				   "\nCredits:\n"
				   "\n\tDeveloper: Darknik\n"
				   "\tProduction Manager: Etern4L\n"
				   "\n\tOfficial Production\n"		
				   "\t\tTei Larisas\n"
				   "\n\nApothikeusi dedomenon....");
			save();
			puts("ta dedomena apothikeutikan...\n"
				 "pieste ena koumpi gia sinexia...");
			getchar();
			break;
		case 2:
			puts("********** Epithesis **********\n"
				   "1->1h epithesi");
			if(lvl>=3){ puts("2->2h epithesi");}
			puts("0->apoxorisi\n"
				   "*******************************\n"
				   "epelekse ena apo ta parapano:");
			break;
		case 3:
			printf("***** Prosthiki Ponton *****\n"
				   "Sas exoun mini %d pontoi...\n"
				   "1->Hp\n"
				   "2->Dinami\n"
				   "0->Exit\n"
				   "9->Plirofories xaraktira\n"
				   "*****************************\n"
				   "Epilekste pou thelete na prosthesete pontous:",pnti);
			break;
		case 4:
			puts("***** Save Data *****\n"
				   "1->newgame\n"
				   "2->loadgame\n"
				   "*********************\n"
				   "Epilekste ena pao ta parapano:");
			break;
		default:
			break;
	}
}

void plirofories(){
	system("clear");
	printf("***** Plirofories Xaraktira *****\n"
		   "Name	:%s\n"
		   "lvl	:%d\n"
		   "Hp	:%d\n"
		   "Dinami	:%d\n"
		   "Pontoi	:%d\n"
		   "*********************************\n"
		   "pieste ena koumpi gia sinexia...",name,lvl,hp,str,pnti);
}

int egiriepithesi(int epilogi){
	int flag=0;
	switch (epilogi) {
		case 0:
			flag=1;
			break;
		case 1:
			flag=1;
			dmg=str;
			break;
		case 2:
			if (lvl>=3) {
				flag=1;
				dmg=str*1.5;
			}
			break;
		default:
			break;
	}
	return	flag;
}

void save(){
	FILE *save;
	save=fopen(name, "w");
	fprintf(save, "%d\n%d\n%d\n%d\n%d\n",lvl,hp,maxhp,str,pnti);
	fclose (save);
}

void load(){
	FILE *load;
	system("clear");
	do {
		system("clear");
		printf("pliktrologiste to onoma sas:");
		scanf("%s",&name[0]);
	} while (fopen(name, "r")==NULL);
	load=fopen(name, "r");
	fscanf(load, "%d %d %d %d %d",&lvl,&hp,&maxhp,&str,&pnti);
	fclose(load);
}
