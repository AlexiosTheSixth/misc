#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include"header.h"
#include<unistd.h>

// Due to deadlines using the old scrapped armydistance method from an old scrapped unfinished pre-alpha of sword of stelion before maps were a thing
int armydistance;

int armycohesion[2];
int oopsie; // Couldn't fix a big and I don't have time, bandaid solution time guess we getting hacked on morale mechanics lmao

// 0 - Hold ground and Skirmish, 1 - Charge, 2 - Riskily pull back
int armytactic[2];


// SKIRMISH PHASE
void skirmishphase() {

// Which team is attacking this turn?
dummyvalue[1][0] = rand() % (1 + 1);

// And which team is thus being attacked
if(dummyvalue[1][0] == 1) {
dummyvalue[1][1] = 0;}
if(dummyvalue[1][0] == 0) {
dummyvalue[1][1] = 1;}

// Pick a character by ID to fire
dummyvalue[0][0] = rand() % (units[2][dummyvalue[1][0]] + 1);

// Reroll if character is dead
while((human[dummyvalue[0][0]][11][dummyvalue[1][0]] <= 0) || oopsie >= 100) { 
if(debug == 1) {
printf("<INFO> [Fac ID: %d | Char ID: %d] isn't taking new orders as they are dead, rerolling...\n", dummyvalue[1][0], dummyvalue[0][0]);}
++oopsie;
if(oopsie >= 100) {
if(debug == 1) {
printf("<ERROR> Error code *thriller*\n");}
goto oh_crap_something_broke;}
dummyvalue[0][0] = rand() % (units[2][dummyvalue[1][0]] + 1);}

// Who is the target by ID
dummyvalue[0][1] = rand() % (units[2][dummyvalue[1][1]] + 1);

// Reroll if target is already dead
while((human[dummyvalue[0][1]][11][dummyvalue[1][1]] <= 0) || oopsie >= 100) {
if(debug == 1) {
printf("<INFO> Targeted character [Fac ID: %d | Char ID: %d] is already dead, rerolling...\n", dummyvalue[1][1], dummyvalue[0][1]);}
++oopsie;
if(oopsie >= 100) {
if(debug == 1) {
printf("<ERROR> Error code *thriller*\n");}
goto oh_crap_something_broke;} 
dummyvalue[0][1] = rand() % (units[2][dummyvalue[1][1]] + 1);}

if(oopsie < 100) {

oopsie = 0;

// Would give Kiverian culture characters fire-lances at a lower equipment value to represent them being used more widely by Kiverion but deadline rip

if(human[dummyvalue[0][0]][12][dummyvalue[1][0]] == 10) {
printf("*KABOOM!* *POP!* *CRACKLE!* ");}

if(dummyvalue[1][0] == 0) {
printf("Kiverian levy ");}
if(dummyvalue[1][0] == 1) {
printf("Xalnopolian warrior ");}
// Check if they actually have a ranged weapon
if(human[dummyvalue[0][0]][12][dummyvalue[1][0]] > 2) {
printf("%d has fired ", dummyvalue[0][0]);
if(human[dummyvalue[0][0]][0][dummyvalue[1][0]] == 0) {
printf("her ");}
if(human[dummyvalue[0][0]][0][dummyvalue[1][0]] == 1) {
printf("his ");}
if(human[dummyvalue[0][0]][12][dummyvalue[1][0]] < 10) {
printf("bow at ");}
if(human[dummyvalue[0][0]][12][dummyvalue[1][0]] == 10) {
printf("fire-lance at ");}
if(human[dummyvalue[0][0]][12][dummyvalue[1][0]] > 10) {
printf("gold plated fire-lance at ");}
if(dummyvalue[1][0] == 1) {
printf("Kiverian levy ");}
if(dummyvalue[1][0] == 0) {
printf("Xalnopolian warrior ");} 
printf("%d, ", dummyvalue[0][1]);


//Calculate random damage (will not be used if it is a miss)
dummyvalue[2][1] = ((rand() % (20 + 1) + 1) + ((human[dummyvalue[0][0]][14][dummyvalue[1][0]] + human[dummyvalue[0][0]][12][dummyvalue[1][0]])));

//Check if it is a miss
dummyvalue[2][0] = (human[dummyvalue[0][0]][14][dummyvalue[1][0]] + (rand() % (10 + 1)));

if(dummyvalue[2][0] < 10) {
printf("missing the target completely.\n");
}

if(dummyvalue[2][0] >= 10) {
// With a bow
if(human[dummyvalue[0][0]][12][dummyvalue[1][0]] < 10) {
//human[dummyvalue[0][1]][10][dummyvalue[1][1]] = human[dummyvalue[0][1]][10][dummyvalue[1][1]] -   // Morale Damage
human[dummyvalue[0][1]][11][dummyvalue[1][1]] = human[dummyvalue[0][1]][11][dummyvalue[1][1]] - dummyvalue[2][1];
printf("dealing %d damage.\n", dummyvalue[2][1]);}

// With a fire-lance (does a crap ton more damage)
if(human[dummyvalue[0][0]][12][dummyvalue[1][0]] >= 10) {
//human[dummyvalue[0][1]][10][dummyvalue[1][1]] = human[dummyvalue[0][1]][10][dummyvalue[1][1]] -   // Morale Damage
human[dummyvalue[0][1]][11][dummyvalue[1][1]] = human[dummyvalue[0][1]][10][dummyvalue[1][1]] - (dummyvalue[2][1] * 2);
printf("dealing %d damage and scaring the living daylights out of ", dummyvalue[2][1] * 2);
if(human[dummyvalue[0][1]][0][dummyvalue[1][1]] == 0) {
printf("her.\n");}
if(human[dummyvalue[0][1]][0][dummyvalue[1][1]] == 1) {
printf("him.\n");}
}}
}

// No ranged weapon L

if(human[dummyvalue[0][0]][12][dummyvalue[1][0]] <= 2) {
printf("%d, having no bow yells angrily at ", dummyvalue[0][0]); 
if(dummyvalue[1][0] == 1) {
printf("Kiverian levy ");}
if(dummyvalue[1][0] == 0) {
printf("Xalnopolian warrior ");}
printf("%d, who", dummyvalue[0][1]);
if(armydistance > 30) {
printf(" doesn't hear ");
if(human[dummyvalue[0][0]][0][dummyvalue[1][0]] == 0) {
printf("her");}
if(human[dummyvalue[0][0]][0][dummyvalue[1][0]] == 1) {
printf("him");}
printf(", but assumes ");
if(human[dummyvalue[0][0]][0][dummyvalue[1][0]] == 0) {
printf("she");}
if(human[dummyvalue[0][0]][0][dummyvalue[1][0]] == 1) {
printf("he");}
printf(" is insulting ");
if(human[dummyvalue[0][1]][0][dummyvalue[1][1]] == 0) {
printf("her");}
if(human[dummyvalue[0][1]][0][dummyvalue[1][1]] == 1) {
printf("him");}
printf(" and flips the bird in response.\n");}
if(armydistance <= 30) {
printf(" yells back with more insults.\n");}



}}
oh_crap_something_broke:}


// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------



// MELEE PHASE (copypasted from skirmish phase with some edits lol)
void meleephase() {

// Which team is attacking this turn?
dummyvalue[1][0] = rand() % (1 + 1);

// And which team is thus being attacked
if(dummyvalue[1][0] == 1) {
dummyvalue[1][1] = 0;}
if(dummyvalue[1][0] == 0) {
dummyvalue[1][1] = 1;}

// Pick a character by ID to fire
dummyvalue[0][0] = rand() % (units[2][dummyvalue[1][0]] + 1);

// Reroll if character is dead
while((human[dummyvalue[0][0]][11][dummyvalue[1][0]] <= 0) || oopsie >= 100) { 
if(debug == 1) {
printf("<INFO> [Fac ID: %d | Char ID: %d] isn't taking new orders as they are dead, rerolling...\n", dummyvalue[1][0], dummyvalue[0][0]);}
++oopsie;
if(oopsie >= 100) {
if(debug == 1) {
printf("<ERROR> Error code *thriller*\n");}
goto oh_crap_something_broke2;}
dummyvalue[0][0] = rand() % (units[2][dummyvalue[1][0]] + 1);}

// Who is the target by ID
dummyvalue[0][1] = rand() % (units[2][dummyvalue[1][1]] + 1);

// Reroll if target is already dead
while((human[dummyvalue[0][1]][11][dummyvalue[1][1]] <= 0) || oopsie >= 100) {
if(debug == 1) {
printf("<INFO> Targeted character [Fac ID: %d | Char ID: %d] is already dead, rerolling...\n", dummyvalue[1][1], dummyvalue[0][1]);}
++oopsie;
if(oopsie >= 100) {
if(debug == 1) {
printf("<ERROR> Error code *thriller*\n");}
goto oh_crap_something_broke2;} 
dummyvalue[0][1] = rand() % (units[2][dummyvalue[1][1]] + 1);}

if(oopsie < 100) {

oopsie = 0;

// First attack

if(dummyvalue[1][0] == 0) {
printf("Kiverian levy ");}
if(dummyvalue[1][0] == 1) {
printf("Xalnopolian warrior ");}
printf("%d has swung ", dummyvalue[0][0]);
if(human[dummyvalue[0][0]][0][dummyvalue[1][0]] == 0) {
printf("her ");}
if(human[dummyvalue[0][0]][0][dummyvalue[1][0]] == 1) {
printf("his ");}
if(human[dummyvalue[0][0]][16][dummyvalue[1][0]] == 1 ) {
printf("sword at ");}
if(human[dummyvalue[0][0]][16][dummyvalue[1][0]] == 2) {
printf("spear at ");}
if(human[dummyvalue[0][0]][16][dummyvalue[1][0]] == 0) {
printf("axe at ");}
if(dummyvalue[1][0] == 1) {
printf("Kiverian levy ");}
if(dummyvalue[1][0] == 0) {
printf("Xalnopolian warrior ");} 
printf("%d, ", dummyvalue[0][1]);


//Calculate random damage (will not be used if it is a miss)
dummyvalue[2][1] = ((rand() % (20 + 1) + 1) + ((human[dummyvalue[0][0]][13][dummyvalue[1][0]] + human[dummyvalue[0][0]][12][dummyvalue[1][0]])));

//Check if it is a miss
dummyvalue[2][0] = (human[dummyvalue[0][0]][13][dummyvalue[1][0]] + (rand() % (10 + 1)));

if((dummyvalue[2][0] < 10) && (human[dummyvalue[0][1]][12][dummyvalue[1][1]] > 2 )) {
printf("but they were blocked by their opponent's shield.\n");
}

if(dummyvalue[2][0] >= 10 || (human[dummyvalue[0][1]][12][dummyvalue[1][1]] <= 2)) {
//human[dummyvalue[0][1]][10][dummyvalue[1][1]] = human[dummyvalue[0][1]][10][dummyvalue[1][1]] -   // Morale Damage
human[dummyvalue[0][1]][11][dummyvalue[1][1]] = human[dummyvalue[0][1]][11][dummyvalue[1][1]] - dummyvalue[2][1];
printf("dealing %d damage.\n", dummyvalue[2][1]);}



// Enemy counterattack

if (human[dummyvalue[0][1]][11][dummyvalue[1][1]] > 0) {

if(dummyvalue[1][1] == 0) {
printf("Kiverian levy ");}
if(dummyvalue[1][1] == 1) {
printf("Xalnopolian warrior ");}
printf("%d then counters, swinging ", dummyvalue[0][1]);
if(human[dummyvalue[0][1]][0][dummyvalue[1][1]] == 0) {
printf("her ");}
if(human[dummyvalue[0][1]][0][dummyvalue[1][1]] == 1) {
printf("his ");}
if(human[dummyvalue[0][1]][16][dummyvalue[1][1]] == 1 ) {
printf("sword at ");}
if(human[dummyvalue[0][1]][16][dummyvalue[1][1]] == 2) {
printf("spear at ");}
if(human[dummyvalue[0][1]][16][dummyvalue[1][1]] == 0) {
printf("axe at ");}
if(dummyvalue[1][1] == 1) {
printf("Kiverian levy ");}
if(dummyvalue[1][1] == 0) {
printf("Xalnopolian warrior ");}
printf("%d, ", dummyvalue[0][0]);


//Calculate random damage (will not be used if it is a miss)
dummyvalue[2][1] = ((rand() % (20 + 1) + 1) + ((human[dummyvalue[0][1]][13][dummyvalue[1][1]] + human[dummyvalue[0][1]][12][dummyvalue[1][1]])));

//Check if it is a miss
dummyvalue[2][0] = (human[dummyvalue[0][1]][13][dummyvalue[1][1]] + (rand() % (10 + 1)));

if((dummyvalue[2][0] < 10) && (human[dummyvalue[0][0]][12][dummyvalue[1][0]] > 2 )) {
printf("but they were blocked by their opponent's shield.\n");
}

if(dummyvalue[2][0] >= 10 || (human[dummyvalue[0][0]][12][dummyvalue[1][0]] <= 2)) {
//human[dummyvalue[0][0]][10][dummyvalue[1][0]] = human[dummyvalue[0][0]][10][dummyvalue[1][0]] -   // Morale Damage
human[dummyvalue[0][0]][11][dummyvalue[1][0]] = human[dummyvalue[0][0]][11][dummyvalue[1][0]] - dummyvalue[2][1];
printf("dealing %d damage.\n", dummyvalue[2][1]);}
}



}
oh_crap_something_broke2:}
