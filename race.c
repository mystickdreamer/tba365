/**************************************************************************
 *  File: race.c                                           Part of tbaMUD *
 *  Usage: Source file for class-specific code.                            *
 *                                                                         *
 *  All rights reserved.  See license for complete information.            *
 *                                                                         *
 *  Copyright (C) 1993, 94 by the Trustees of the Johns Hopkins University *
 *  CircleMUD is based on DikuMUD, Copyright (C) 1990, 1991.               *
 **************************************************************************/

/** Help buffer the global variable definitions */
#define __RACE_C__

/* This file attempts to concentrate most of the code which must be changed
 * in order for new race to be added.  If you're adding a new class, you
 * should go through this entire file from beginning to end and add the
 * appropriate new special cases for your new race. */

#include "conf.h"
#include "sysdep.h"
#include "structs.h"
#include "utils.h"
#include "db.h"
#include "spells.h"
#include "interpreter.h"
#include "constants.h"
#include "act.h"
#include "comm.h"

/*Names First*/
const char *race_abbrevs[] = {
    "Hu",
    "El",
    "Dw",
    "\n"
};

const char *pc_race_types[] = {
    "Human",
    "Elf",
    "Dwarf",
    "\n"
};
/* Race Menu in Interpreter.c*/
const char *race_menu =
        "\r\n"
        "+------------------+\r\n"
        "|       Race       |\r\n"
        "+------------------+\r\n"
        "| H) Human         |\r\n"
        "| E) Elf           |\r\n"
        "| D) Dwarf         |\r\n"
        "+------------------|\r\n";

/* The code to interpret a race letter -- used in interpreter.c when a new
 * character is selecting a race and by 'set race' in act.wizard.c. */
int parse_race(char arg) {
    arg = LOWER(arg);

    switch (arg) {
        case 'H':
        case 'h': return RACE_HUMAN;
        case 'E':
        case 'e': return RACE_ELF;
        case 'D':
        case 'd': return RACE_DWARF;
        default: return RACE_UNDEFINED;
    }
}


/* Taken from the SRD under OGL, see ../doc/srd.txt for information */
int racial_ability_mods[][7] = {
/*                      Str,Con,Int,Wis,Dex,Cha Per*/
/* RACE_HUMAN       */ {  0,  0,  0,  0,  0,  0, 0 },
/* RACE_ELF         */ {  0, -2,  0,  0,  2,  0, 0 },
/* RACE_GNOME       */ //{ -2,  2,  0,  0,  0,  0, 0 },
/* RACE_DWARF       */ {  0,  2,  0,  0,  0, -2, 0 },
/* RACE_HALF_ELF    */ //{  0,  0,  0,  0,  0,  0, 0 },
/* RACE_HALFLING    */ //{ -2,  0,  0,  0,  2,  0, 0 },
/* RACE_DROW_ELF    */ //{  0, -2,  2,  0,  2,  2, 0 },
/* RACE_HALF_ORC    */ //{  2,  0, -2,  0,  0, -2, 0 },
/* RACE_ANIMAL      */ //{  0,  0,  0,  0,  0,  0, 0 },
/* RACE_CONSTRUCT   */ //{  0,  0,  0,  0,  0,  0, 0 },
/* RACE_DEMON       */ //{  0,  0,  0,  0,  0,  0, 0 },
/* RACE_DRAGON      */ //{  0,  0,  0,  0,  0,  0, 0 },
/* RACE_FISH        */ //{  0,  0,  0,  0,  0,  0, 0 },
/* RACE_GIANT       */ //{ 14,  8, -4,  0, -2, -4, 0 },
/* RACE_GOBLIN      */ //{ -2,  0,  0,  0,  2, -2, 0 },
/* RACE_INSECT      */ //{  0,  0,  0,  0,  0,  0, 0 },
/* RACE_ORC         */ //{  4,  0, -2, -2,  0, -2, 0 },
/* RACE_SNAKE       */ //{  0,  0,  0,  0,  0,  0, 0 },
/* RACE_TROLL       */ //{ 12, 12, -4, -2,  4, -4, 0 },
/* RACE_MINOTAUR    */ //{  8,  4, -4,  0,  0, -2, 0 },
/* RACE_KOBOLD      */ //{ -4, -2,  0,  0,  2,  0, 0 },
/* RACE_LIZARDFOLK  */ //{  0,  0,  0,  0,  0,  0, 0 },
/* RACE_WARHOST     */ //{  0,  0,  0,  0,  0,  0, 0 },
/* RACE_FAERIE      */ //{  0,  0,  0,  0,  0,  0, 0 },
{ 0, 0, 0, 0, 0}
};

void racial_ability_modifiers(struct char_data *ch)
{
  int chrace = 0;
  if (GET_RACE(ch) >= NUM_RACES || GET_RACE(ch) < 0) {
    log("SYSERR: Unknown race %d in racial_ability_modifiers", GET_RACE(ch));
  } else {
    chrace = GET_RACE(ch);
  }

  ch->real_abils.str += racial_ability_mods[chrace][0];
  ch->real_abils.con += racial_ability_mods[chrace][1];
  ch->real_abils.intel += racial_ability_mods[chrace][2];
  ch->real_abils.wis += racial_ability_mods[chrace][3];
  ch->real_abils.dex += racial_ability_mods[chrace][4];
  ch->real_abils.per += racial_ability_mods[chrace] [5];
}

bitvector_t find_race_bitvector(const char *arg) {
    size_t rpos, ret = 0;

    for (rpos = 0; rpos < strlen(arg); rpos++)
        ret |= (1 << parse_race(arg[rpos]));

    return (ret);
}

/* Invalid wear flags */
int invalid_race(struct char_data *ch, struct obj_data *obj) {
    if ((OBJ_FLAGGED(obj, ITEM_ANTI_HUMAN) && IS_HUMAN(ch)) ||
            (OBJ_FLAGGED(obj, ITEM_ANTI_ELF) && IS_ELF(ch)) ||
            (OBJ_FLAGGED(obj, ITEM_ANTI_DWARF) && IS_DWARF(ch)))
        return 1;
    else
        return 0;
}