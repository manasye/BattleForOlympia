#ifndef _STRUCTS_h
#define _STRUCTS_h

#include "boolean.h"
#include "point.h"
#include "pcolor.h"
#include "unit.h"
#include "VilList.h"
#include "UnitList.h"

/* Player : structure to represent a player stats */
typedef struct {
    int Gold; // Amount of gold of a player
    UnitList Units;
    VilList Villages;
    int Income; // Amount of income per turn
    int Upkeep; // Cost of having several units
    POINT Base; // The position of this player's base/tower
    char *Color; // Color code of this player
} Player;

/* You can use these selectors to access "Player" data struct */
#define Gold(P) (P).Gold
#define Income(P) (P).Income
#define Upkeep(P) (P).Upkeep
#define Units(P) (P).Units
#define Villages(P) (P).Villages
#define Base(P) (P).Base
#define Color(P) (P).Color

/* Player data used for the game. Because it's known to be only 2 players, we define it statically */
extern Player P_Data[3];

/* *** PLAYER DATA STRUCT GROUP *** */
void InitPlayer(Player *P, int PN);
/* Initialize starting values of a player.
   PN (Player number, 1 <= PN <= 4) is used to assign a color to that player. */


#include "player.c"
#endif
