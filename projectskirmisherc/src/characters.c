#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include"header.h"




int human[100][17][2];



// Gonna have to speedrun this oh boy, and make it C O M P A C T
// don't have the time to make it take itself into account so enjoy your blonde haired blue eyed dark skinned chars
void chargen(int id, int faction) {

// Appearence
human[id][0][faction] = rand() % (1 + 1); // Gender - 0 F 1 M
human[id][1][faction] = rand() % (9 + 1); // Skintone - 0 Very pale (eg N European) 9 very dark (eg Equatorial Afr)
human[id][2][faction] = rand() % (9 + 1); // Hair color - 0 light blonde 9 black
human[id][3][faction] = rand() % (9 + 1); // Hair length - 0 buzzcut 9 very long
human[id][4][faction] = rand() % (3 + 1); // Eye Color - 0 blue 1 green 2 hazel 3 brown
human[id][5][faction] = rand() % (30 + 1) + 13; // Age - self explanatory, 13 to 30 since I can't make it weighted towards teen/young adults
if((human[id][5][faction] >= 20) && (human[id][0][faction] == 1)) {
human[id][6][faction] = rand() % (9 + 1);} // Beard gloriousness - 0-4 no beard, 5 stubble 9 full beard
human[id][7][faction] = rand() % (9 + 1); // Weight - 0 skinny as hecc 9 heccin chonker
human[id][8][faction] = rand() % (9 + 1); // Height - 0 short king/queen 9 palverikosalastair irl
dummyvalue[0][0] = rand() % (2 + 1);
if((human[id][5][faction] >= 18) && (faction == 0) && dummyvalue[0][0] == 2) { // 1/3 chance for a kiverian fac character that isn't a ch*ld to be kiverian culture
human[id][9][faction] = 7;} // Set culture to Kiverian
if((human[id][5][faction] <= 17) || faction == 1 || dummyvalue[0][0] != 2) {
human[id][9][faction] = rand() % (6 + 1);} // Culture - 0-4 Tzevian 5-6 Neos Kentrikos Piloupotos

// Attributes
human[id][10][faction] = rand() % (100 + 1) + 10; // Starting Morale
human[id][11][faction] = rand() % (100 + 1) + 60; // Starting Health
human[id][12][faction] = rand() % (10 + 1) + 1; // Equipment quality
human[id][13][faction] = rand() % (10 + 1) + 1; // Melee Skill
human[id][14][faction] = rand() % (10 + 1) + 1; // Ranged Skill
human[id][15][faction] = rand() % (300 + 1); // Leadership (will be added to army cohesion)

// Added later
human[id][16][faction] = rand() % (1 + 1); // Preferred weapon - 0 Axe 1 Sword 2 Spear (only Kiverian culture) - Cosmetic for now

if(kiverionskirm == 1) {
// Give Kiverian culture characters an extra Ranged Skill point at the cost of a Melee skill point if above 1
if((human[id][9][faction] == 7) && (human[id][13][faction] > 1)) {
--human[id][13][faction];
++human[id][14][faction];
}}

// Give Kiverian culture characters a spear
if(human[id][9][faction] == 7) {
human[id][16][faction] = 2;
}


}

void armygen(int kivnum, int xalnum) {
while(kivnum > -1) {
chargen(kivnum, 0);
--kivnum; }
while(xalnum > -1) {
chargen(xalnum, 1);
--xalnum; } 
}
