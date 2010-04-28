#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "uf.h"


int epipedo=1;
int xp=20;

char name[20],itemname[20];
int iteminstore,itemid,itemcoins,dmg,i,j,id,restPrice=1,secanazoogonisis=60;
int lvl=1,hp=10,str=5,def=5,xpxara=0,maxhp=10,pnti=3,coins=10,tsanta[20],tsantalast=0;	/*arxikes times*/

void menu(int);
void lvlup();
int addpoint();
void useitems();
void plirofories();
void store();
int egiriepithesi(int);
void valitsa();
void taksinomistsantas();
void save();
void agora();
void load();

int main (int argc, char *argv[]) {
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
				anthp=rand()%((antlvl+1)*10+epipedo)+2;
				antstr=rand()%((antlvl+1)+epipedo)+2;
				printf(
					"***** Euresi exthrou *****\n"
					"lvl antipalou:%d\n"
					"Hp antipalou:%d\n"
					"Dinami antipalou:%d\n"
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
							antdmg=(float)(((rand()%10+7.0)-def)/10.0)*antstr;
							if(antdmg<0)
								antdmg=(-1)*antdmg;
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
								printf("***** Sigxaritiria kerdisate %d nomismata!!! *****\n"
									 "pieste ena koumpi gia sinexia...\n",antlvl+antstr);
								if ((antlvl*3)+hp<=maxhp) {
									hp+=antlvl*2;
								}
								else {
									hp=maxhp;
								}
								xpxara+=antlvl*xp/epipedo;
								coins+=lvl*antstr/epipedo;
								lvlup();
							}		
							if (hp<=0) {
								flag=1;
								system("clear");
								puts("Xasate...");
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
						case 3:
							def+=addpoint();
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
						puts("Den iparxoun alloi pontoi gia prosthiki...\n"
							 "pieste ena koumpi gia sinexia...");
						getchar();
					}
				}
				epilogi=1;
				break;
			case 4:
				while (flag==0) {
					menu(5);
					scanf("%d",&epilogi);
					system("clear");
					switch (epilogi) {
						case 1:
							system("clear");
							if (tsantalast!=0) {
								valitsa();
								puts("pieste ena koumpi gia sinexia...\n");
							}
							else {
								puts("Den uparxoun antikimena stin tsanta\n"
								 "pieste ena koumpi gia sinexia...\n");
							}
							getchar();
							break;
						case 2:
							system("clear");
							if (tsantalast!=0) {
								do {
									valitsa();
									printf("Epelekse pio antikimeno thes na xrisimopiisis:");
									scanf("%d",&id);
									system("clear");
								} while (id>tsantalast);
								itemid=tsanta[id-1];
								useitems();
							}
							else {
								puts("Den uparxoun antikimena stin tsanta\n"
								"pieste ena koumpi gia sinexia...\n");
							}
							getchar();
							break;
						case 3:
							system("clear");
							store();
							scanf("%d",&id);
							agora();
							puts("pieste ena koumpi gia sinexia...\n");
							getchar();
							break;

						case 0:
							flag=1;
							break;
					}
					getchar();
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
		pnti+=(level-lvl)*3;
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
				   "4->Antikimena\n"
				   "9->Save Game\n"
				   "**************************\n"
				   "epilekste ena apo ta parapano:");
			break;
		case 1:
			puts("Euxaristoume pou peksate to Game!\n"
				   "\nCredits:\n"
				   "\n\tDeveloper: Darknik & ragecryx\n"
				   "\tManager: Etern4L\n"
				   "\n\tOfficial Production\n"		
				   "\t\tLinuxTeam - ATEI Larisas\n"
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
				   "3->Amyna\n"
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
		case 5:
			puts("********** Antikimena **********\n"
				 "0->Exit\n"
				 "1->Emfanisi tsantas\n"
				 "2->Xrisi atnikimenou\n"
				 "3->Agora antikimenou\n"
				 "*********************************\n"
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
		   "Amina	:%d\n"
		   "Pontoi	:%d\n"
		   "Xrimata	:%d\n"
		   "*********************************\n"
		   "pieste ena koumpi gia sinexia...",name,lvl,hp,str,def,pnti,coins);
}

void store(){
	FILE *store;
	store=fopen("store", "r");
	system("clear");
	puts("********** Antikimena Magaziou **********\n"
		 "ID\tCOINS\tNAME");
	fscanf(store, "%d",&iteminstore);
	for (i=1; i<=iteminstore; i++) {
		fscanf(store, "%d %d %s \n",&itemid,&itemcoins,&itemname[0]);
		printf("%d\t%d\t%s\n",itemid,itemcoins,replaceChar(itemname));
	}
	fclose(store);
	puts("******************************************\n"
		 "Epilekste ti thelete na agorasete");
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

void valitsa(){
	FILE *store;
	puts("********** Tsanta **********\n"
		 "ID\tNAME");
	for (i=0; i<tsantalast; i++) {
		store=fopen("./store", "r");
		fscanf(store, "%d",&iteminstore);
		do {
			fscanf(store, "%d %d %s \n",&itemid,&itemcoins,&itemname[0]);
		} while (itemid!=tsanta[i]);
		printf("%d\t%s\n",i+1,replaceChar(itemname));
		fclose(store);
	}
	puts("****************************\n");
}

void useitems(){
	system("clear");
	switch (itemid) {
		case 001:
			system("clear");
			hp+=5;
			if (hp>maxhp) {
				hp=maxhp;
			}
			puts("Prostethikan 5 Hp"
				 "pieste ena koumpi gia sinexia...");
			break;
		case 002:
			system("clear");
			hp+=15;
			if (hp>maxhp) {
				hp=maxhp;
			}
			puts("Prostethikan 15 Hp"
				 "pieste ena koumpi gia sinexia...");
			break;
		case 003:
			system("clear");
			hp+=50;
			if (hp>maxhp) {
				hp=maxhp;
			}
			puts("Prostethikan 50 Hp"
				 "pieste ena koumpi gia sinexia...");
			break;
		default:
			break;
	}
	taksinomistsantas();
}

void taksinomistsantas(){
	for (i=id-1; i<=tsantalast; i++) {
		tsanta[i]=tsanta[i+1];
	}
	tsantalast-=1;
}

void agora(){
	FILE *store;
	store=fopen("./store", "r");
	fscanf(store, "%d",&iteminstore);
	do {
		fscanf(store, "%d %d %s \n",&itemid,&itemcoins,&itemname[0]);
	} while (itemid!=id);
	if (itemcoins>coins) {
		puts("Den Exete Arketa xrimata gia na agorasete to items\n");
	}
	else {
		coins-=itemcoins;
		tsanta[tsantalast]=itemid;
		tsantalast+=1;
		puts("To antikimeno agorastike me epitixia...\n");
	}
	
}

void save(){
	FILE *save;
	save=fopen(name, "w");
	fprintf(save, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",lvl,hp,maxhp,str,def,pnti,coins,tsantalast);
	for (i=0; i<tsantalast; i++) {
		fprintf(save, "%d\n",tsanta[i]);
	}
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
	fscanf(load, "%d %d %d %d %d %d %d %d ",&lvl,&hp,&maxhp,&str,&def,&pnti,&coins,&tsantalast);
	for (i=0; i<tsantalast; i++) {
		fscanf(load, "%d ",&tsanta[i]);
	}
	fclose(load);
}
