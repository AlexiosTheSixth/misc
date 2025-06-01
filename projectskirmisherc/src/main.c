#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include"header.h"

int dummyvalue[5][5];
int dummychar;
int numchoice;
int commandsenabled;
int kiverionskirm;

// 0 - Kiverion, 1 - Xalnopoli
int turn = 0;

int debug;

// 0 - Kiverion's first turn, 1 - Xalnopoli first turn, 2 - the end of the era of first turns
// This is basically just for some first turn flavor messages
int firstturn = 0; 

// Scrapping location mechanics until later version

// 1st axis: 0 - current 1 - start of turn 2 - start of battle
// 2nd axis: 0 - Kiverion, 1 - Xalnopoli
int units[3][2];


void saninput() {
while((dummychar = getchar()) != '\n' && dummychar != EOF) {}
}




int main() {

srand(time(NULL));

printf("Project Skirmisher: C Prototype Edition\n\n\n");

printf("How many levies will Kiverion raise? (Max 100 Rec ~10 for lore reasons.)\n\n>");

scanf("%d", &units[0][0]);

saninput();

printf("How many warriors does Xalnopoli have available? (Max 100 Rec ~10 for lore reasons.)\n\n>");
 
scanf("%d", &units[0][1]);
 
saninput();

printf("Should Kivian culture (not faction, culture) characters be slightly stronger in skirmishing but slightly weaker in melee? (0 for no 1 for yes)\n\n>");

scanf("%d", &kiverionskirm);

saninput();


printf("How far away should the armies start from eachother? (Just turns of skirmishing phase for now.)\n\n>");

scanf("%d", &armydistance);

saninput();

printf("Enable debug mode? (0 for no 1 for yes)\n\n>");

scanf("%d", &debug);

saninput();

printf("Enable issuing commands to the armies? (0 for no 1 for yes, unfinished currently and won't let you mash enter to rapidly sim)\n\n>");

scanf("%d", &commandsenabled);

saninput();


units[2][0] = units[0][0];
units[2][1] = units[0][1];
armygen(units[0][0], units[0][1]);


printf("You and your opponent both arrive to the battlefield, looking upon the armies at your command...\n\n");

while((units[0][0] > 0) && (units[0][1] > 0) && oopsie < 100) {

while(turn == 0) {
while(firstturn == 0) {
printf("<Dekarchos Niketas> Alas my Megalos Vasilias...\n");
firstturn = 1;
}

printf("Army distance: %d\n", armydistance);
printf("[Kiverion's Turn]\n\n<Dekarchos Niketas> Our army is %d strong against the enemy's %d.\n", units[0][0], units[0][1]);

if(commandsenabled == 1) {
printf("Select a command? (Put any other char for no) - 1. Census  2.  3. 4. 5.\n\n>");

scanf("%d", &numchoice);

switch(numchoice) {

case 1:
census(0);
break;

default:

}

saninput();}

units[1][0] = units[0][0];


if(armydistance > 0) {
skirmishphase();
--armydistance;}

if(armydistance <= 0) {
meleephase();}


if (human[dummyvalue[0][1]][11][dummyvalue[1][1]] <= 0) {
printf("Target has fallen!\n");
--units[0][dummyvalue[1][1]];
}

saninput();

turn = 1;
}
 

while(turn == 1) {
while(firstturn == 1) {
printf("<Henry> POGGERS lets go pillage some stuff!\n");
firstturn = 2;
}

printf("Army distance: %d\n", armydistance);

printf("[Xalnopoli's turn]\n\n<Henry> Yo we have %d guys and the kiverians have %d.\n", units[0][1], units[0][0]);

if(commandsenabled == 1) {
printf("Select a command? (Put any other char for no) - 1. Census  2.  3. 4. 5.\n\n>");

scanf("%d", &numchoice);

switch(numchoice) {    

case 1:
census(1);
break;

default:

}

saninput();}


units[1][1] = units[0][1];


if(armydistance > 0) {
skirmishphase();
--armydistance;}

if(armydistance <= 0) {
meleephase();}


if (human[dummyvalue[0][1]][11][dummyvalue[1][1]] <= 0) {
printf("Target has fallen!\n");
--units[0][dummyvalue[1][1]];
}


saninput();

turn = 0;
}

}

if (oopsie >= 100) {
if (units[0][0] > units[0][1]) {
printf("<Dekarchos Niketas> The swine of Xalnopoli flee the battle! There will be no plunder for them.\n");
}

if (units[0][1] > units[0][0]) {
printf("<Henry> LMAO the Kiverians are running away! Lets plunder their stupid city!\n");
}
}

if (units[0][1] <= 0) {
printf("<Dekarchos Niketas> My Megalos Vasilias, Kiverion has utterly won. We have defeated every last one of the vile raiders of Xalnopoli.\n");
}

if (units[0][0] <= 0) {
printf("<Henry> We won! Screw kiverion! PLUNDER TIME LETS GOOOOO!.\n");
}


}
