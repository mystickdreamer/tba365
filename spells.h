/**
 * @file spells.h
 * Constants and function prototypes for the spell system.
 *
 * Part of the core tbaMUD source code distribution, which is a derivative
 * of, and continuation of, CircleMUD.
 *
 * All rights reserved.  See license for complete information.
 * Copyright (C) 1993, 94 by the Trustees of the Johns Hopkins University
 * CircleMUD is based on DikuMUD, Copyright (C) 1990, 1991.
 */
#ifndef _SPELLS_H_
#define _SPELLS_H_

#define DEFAULT_STAFF_LVL	12
#define DEFAULT_WAND_LVL	12

#define CAST_UNDEFINED	(-1)
#define CAST_SPELL	0
#define CAST_POTION	1
#define CAST_WAND	2
#define CAST_STAFF	3
#define CAST_SCROLL	4

#define MAG_DAMAGE	(1 << 0)
#define MAG_AFFECTS	(1 << 1)
#define MAG_UNAFFECTS	(1 << 2)
#define MAG_POINTS	(1 << 3)
#define MAG_ALTER_OBJS	(1 << 4)
#define MAG_GROUPS	(1 << 5)
#define MAG_MASSES	(1 << 6)
#define MAG_AREAS	(1 << 7)
#define MAG_SUMMONS	(1 << 8)
#define MAG_CREATIONS	(1 << 9)
#define MAG_MANUAL	(1 << 10)
#define MAG_ROOMS   (1 << 11)

#define TYPE_UNDEFINED               (-1)
#define SPELL_RESERVED_DBC            0  /* SKILL NUMBER ZERO -- RESERVED */

/* PLAYER SPELLS -- Numbered from 1 to MAX_SPELLS */
#define SPELL_ARMOR                   1 /* Reserved Skill[] DO NOT CHANGE */
#define SPELL_TELEPORT                2 /* Reserved Skill[] DO NOT CHANGE */
#define SPELL_BLESS                   3 /* Reserved Skill[] DO NOT CHANGE */
#define SPELL_BLINDNESS               4 /* Reserved Skill[] DO NOT CHANGE */
#define SPELL_BURNING_HANDS           5 /* Reserved Skill[] DO NOT CHANGE */
#define SPELL_CALL_LIGHTNING          6 /* Reserved Skill[] DO NOT CHANGE */
#define SPELL_CHARM                   7 /* Reserved Skill[] DO NOT CHANGE */
#define SPELL_CHILL_TOUCH             8 /* Reserved Skill[] DO NOT CHANGE */
#define SPELL_CLONE                   9 /* Reserved Skill[] DO NOT CHANGE */
#define SPELL_COLOR_SPRAY            10 /* Reserved Skill[] DO NOT CHANGE */
#define SPELL_CONTROL_WEATHER        11 /* Reserved Skill[] DO NOT CHANGE */
#define SPELL_CREATE_FOOD            12 /* Reserved Skill[] DO NOT CHANGE */
#define SPELL_CREATE_WATER           13 /* Reserved Skill[] DO NOT CHANGE */
#define SPELL_CURE_BLIND             14 /* Reserved Skill[] DO NOT CHANGE */
#define SPELL_CURE_CRITIC            15 /* Reserved Skill[] DO NOT CHANGE */
#define SPELL_CURE_LIGHT             16 /* Reserved Skill[] DO NOT CHANGE */
#define SPELL_CURSE                  17 /* Reserved Skill[] DO NOT CHANGE */
#define SPELL_DETECT_ALIGN           18 /* Reserved Skill[] DO NOT CHANGE */
#define SPELL_DETECT_INVIS           19 /* Reserved Skill[] DO NOT CHANGE */
#define SPELL_DETECT_MAGIC           20 /* Reserved Skill[] DO NOT CHANGE */
#define SPELL_DETECT_POISON          21 /* Reserved Skill[] DO NOT CHANGE */
#define SPELL_DISPEL_EVIL            22 /* Reserved Skill[] DO NOT CHANGE */
#define SPELL_EARTHQUAKE             23 /* Reserved Skill[] DO NOT CHANGE */
#define SPELL_ENCHANT_WEAPON         24 /* Reserved Skill[] DO NOT CHANGE */
#define SPELL_ENERGY_DRAIN           25 /* Reserved Skill[] DO NOT CHANGE */
#define SPELL_FIREBALL               26 /* Reserved Skill[] DO NOT CHANGE */
#define SPELL_HARM                   27 /* Reserved Skill[] DO NOT CHANGE */
#define SPELL_HEAL                   28 /* Reserved Skill[] DO NOT CHANGE */
#define SPELL_INVISIBLE              29 /* Reserved Skill[] DO NOT CHANGE */
#define SPELL_LIGHTNING_BOLT         30 /* Reserved Skill[] DO NOT CHANGE */
#define SPELL_LOCATE_OBJECT          31 /* Reserved Skill[] DO NOT CHANGE */
#define SPELL_MAGIC_MISSILE          32 /* Reserved Skill[] DO NOT CHANGE */
#define SPELL_POISON                 33 /* Reserved Skill[] DO NOT CHANGE */
#define SPELL_PROT_FROM_EVIL         34 /* Reserved Skill[] DO NOT CHANGE */
#define SPELL_REMOVE_CURSE           35 /* Reserved Skill[] DO NOT CHANGE */
#define SPELL_SANCTUARY              36 /* Reserved Skill[] DO NOT CHANGE */
#define SPELL_SHOCKING_GRASP         37 /* Reserved Skill[] DO NOT CHANGE */
#define SPELL_SLEEP                  38 /* Reserved Skill[] DO NOT CHANGE */
#define SPELL_STRENGTH               39 /* Reserved Skill[] DO NOT CHANGE */
#define SPELL_SUMMON                 40 /* Reserved Skill[] DO NOT CHANGE */
#define SPELL_VENTRILOQUATE          41 /* Reserved Skill[] DO NOT CHANGE */
#define SPELL_WORD_OF_RECALL         42 /* Reserved Skill[] DO NOT CHANGE */
#define SPELL_REMOVE_POISON          43 /* Reserved Skill[] DO NOT CHANGE */
#define SPELL_SENSE_LIFE             44 /* Reserved Skill[] DO NOT CHANGE */
#define SPELL_ANIMATE_DEAD           45 /* Reserved Skill[] DO NOT CHANGE */
#define SPELL_DISPEL_GOOD            46 /* Reserved Skill[] DO NOT CHANGE */
#define SPELL_GROUP_ARMOR            47 /* Reserved Skill[] DO NOT CHANGE */
#define SPELL_GROUP_HEAL             48 /* Reserved Skill[] DO NOT CHANGE */
#define SPELL_GROUP_RECALL           49 /* Reserved Skill[] DO NOT CHANGE */
#define SPELL_INFRAVISION            50 /* Reserved Skill[] DO NOT CHANGE */
#define SPELL_WATERWALK              51 /* Reserved Skill[] DO NOT CHANGE */
#define SPELL_IDENTIFY               52 /* Reserved Skill[] DO NOT CHANGE */
#define SPELL_FLY                    53 /* Reserved Skill[] DO NOT CHANGE */
#define SPELL_DARKNESS               54
/** Total Number of defined spells */
#define NUM_SPELLS                   54

/* Insert new spells here, up to MAX_SPELLS */
#define TOP_SPELL           391
#define MAX_SPELLS		    130

/* PLAYER SKILLS - Numbered from MAX_SPELLS+1 to MAX_SKILLS */
#define SKILL_BACKSTAB              131 /* Reserved Skill[] DO NOT CHANGE */
#define SKILL_BASH                  132 /* Reserved Skill[] DO NOT CHANGE */
#define SKILL_HIDE                  133 /* Reserved Skill[] DO NOT CHANGE */
#define SKILL_KICK                  134 /* Reserved Skill[] DO NOT CHANGE */
#define SKILL_PICK_LOCK             135 /* Reserved Skill[] DO NOT CHANGE */
#define SKILL_WHIRLWIND             136 
#define SKILL_RESCUE                137 /* Reserved Skill[] DO NOT CHANGE */
#define SKILL_SNEAK                 138 /* Reserved Skill[] DO NOT CHANGE */
#define SKILL_STEAL                 139 /* Reserved Skill[] DO NOT CHANGE */
#define SKILL_TRACK		              140 /* Reserved Skill[] DO NOT CHANGE */




//Weapon Skills:
#define SK_UNDEFINED 0
#define SK_PARRY    1
#define SK_SMALL_EDGED 2
#define SK_MEDIUM_EDGED 3
#define SK_HEAVY_EDGED 4
#define SK_SMALL_BLUNT 5
#define SK_MEDIUM_BLUNT 6 
#define SK_HEAVY_BLUNT 7
#define SK_STAFF 8
#define SK_SLING 9
#define SK_SHORT_BOW 10
#define SK_LONG_BOW 11
#define SK_LIGHT_CROSSBOW 12
#define SK_HEAVY_CROSSBOW 13
#define SK_POLEARM 14
#define SK_LIGHT_THROWN 15
#define SK_HEAVY_THROWN 16
#define SK_BACKSTAB 17
//Survival:
#define SK_EVASION 18
#define SK_CLIMBING 19
#define SK_SWIMMING 20
#define SK_PERCEPTION 21
#define SK_TRACKING 22
#define SK_HIDING 23
#define SK_SNEAKING 24
#define SK_LOCKPICKING 25
#define SK_DISARMING 26
#define SK_STEALING 27
#define SK_FIRST_AID 28
//Lore:
#define SK_SCHOLARSHIP 29
#define SK_MUSIC 30
//Instrumental Lore: (Bards)
#define SK_PERCUSSION 31
#define SK_STRINGED 32
#define SK_WIND 33
#define SK_VOCAL 34
#define SK_APPRAISE 35
#define SK_HANDLE_ANIMAL 36
#define SK_ASTROLOGY 37
//Magic:
#define SK_PRIMARY 38
#define SK_HARNESS 39
#define SK_MANA_PERCEIVE 40
#define SK_MAGIC_DEVICES 41
#define SK_TARGETED 42
//Armor:
#define SK_SHIELD 43
#define SK_LEATHER 44
#define SK_CHAIN 45
#define SK_PLATE 46
//Crafting:
#define SK_MINING 47
#define SK_FORAGING 48
#define SK_SKINNING 49
#define SK_HERBALISM 50
#define SK_FORESTRY 51
#define SK_COOKING 52
#define SK_BLACKSMITHING 53
#define SK_TAILORING 54
#define SK_TANNING 55
#define SK_GOLDSMITHING 56
#define SK_WOODWORKING 57
#define SK_TINKERING 58
#define SK_FORGING  59//(weaponsmithing and armorsmithing)
#define SK_ALCHEMY 60
#define SK_ENCHANTING 61
#define SK_RUNECRAFTING 62

#define NUM_SKILLS 63


#define SKILL_LOW_SKILL SK_UNDEFINED
#define SKILL_HIGH_SKILL SK_RUNECRAFTING

#define SKILL_LANG_COMMON       601
#define SKILL_LANG_THIEVES_CANT 602
#define SKILL_LANG_ELVEN        603
#define SKILL_LANG_DWARVEN      604
#define SKILL_LANG_DRACONIC     605

#define SKILL_LANG_LOW SKILL_LANG_COMMON
#define SKILL_LANG_HIGH SKILL_LANG_DRACONIC

#define MIN_LANGUAGES     SKILL_LANG_LOW
#define MAX_LANGUAGES     SKILL_LANG_HIGH

#define SKTYPE_NONE   0
#define SKTYPE_SPELL    (1 << 0)
#define SKTYPE_WEAPON   (1 << 1)
#define SKTYPE_LANG   (1 << 2)
#define SKTYPE_SURVIVAL   (1 << 3)
#define SKTYPE_LORE    (1 << 4)
#define SKTYPE_MAGIC    (1 << 5)
#define SKTYPE_ARMOR    (1 << 6)
#define SKTYPE_CRAFTING (1 << 7)
#define SKTYPE_SKILL    (1 << 8)

#define SKFLAG_CRAFT    (1 << 9)

/* New skills may be added here up to MAX_SKILLS (200) */

#define SKLEARN_CANT    0 /* This class can't learn this skill */
#define SKLEARN_CLASS   1 /* Class skill for this class */
#define SKLEARN_BOOL    2 /* Skill is known or not */


/* NON-PLAYER AND OBJECT SPELLS AND SKILLS: The practice levels for the spells
 * and skills below are _not_ recorded in the players file; therefore, the
 * intended use is for spells and skills associated with objects (such as
 * SPELL_IDENTIFY used with scrolls of identify) or non-players (such as NPC
 * only spells). */

/* To make an affect induced by dg_affect look correct on 'stat' we need to
 * define it with a 'spellname'. */
#define SPELL_DG_AFFECT              298

#define TOP_SPELL_DEFINE	     299
/* NEW NPC/OBJECT SPELLS can be inserted here up to 299 */

/* WEAPON ATTACK TYPES */
#define TYPE_HIT        300
#define TYPE_STING      301
#define TYPE_WHIP       302
#define TYPE_SLASH      303
#define TYPE_BITE       304
#define TYPE_BLUDGEON   305
#define TYPE_CRUSH      306
#define TYPE_POUND      307
#define TYPE_CLAW       308
#define TYPE_MAUL       309
#define TYPE_THRASH     310
#define TYPE_PIERCE     311
#define TYPE_BLAST		  312
#define TYPE_PUNCH		  313
#define TYPE_STAB		    314
/** The total number of attack types */
#define NUM_ATTACK_TYPES  15

/* new attack types can be added here - up to TYPE_SUFFERING */
#define TYPE_SUFFERING		     399

#define SAVING_PARA   0
#define SAVING_ROD    1
#define SAVING_PETRI  2
#define SAVING_BREATH 3
#define SAVING_SPELL  4

/***
 **Possible Targets:
 **  TAR_IGNORE    : IGNORE TARGET.
 **  TAR_CHAR_ROOM : PC/NPC in room.
 **  TAR_CHAR_WORLD: PC/NPC in world.
 **  TAR_FIGHT_SELF: If fighting, and no argument, select tar_char as self.
 **  TAR_FIGHT_VICT: If fighting, and no argument, select tar_char as victim (fighting).
 **  TAR_SELF_ONLY : If no argument, select self, if argument check that it IS self.
 **  TAR_NOT_SELF  : Target is anyone else besides self.
 **  TAR_OBJ_INV   : Object in inventory.
 **  TAR_OBJ_ROOM  : Object in room.
 **  TAR_OBJ_WORLD : Object in world.
 **  TAR_OBJ_EQUIP : Object held.
 ***/
#define TAR_IGNORE      (1 << 0)
#define TAR_CHAR_ROOM   (1 << 1)
#define TAR_CHAR_WORLD  (1 << 2)
#define TAR_FIGHT_SELF  (1 << 3)
#define TAR_FIGHT_VICT  (1 << 4)
#define TAR_SELF_ONLY   (1 << 5) /* Only a check, use with i.e. TAR_CHAR_ROOM */
#define TAR_NOT_SELF   	(1 << 6) /* Only a check, use with i.e. TAR_CHAR_ROOM */
#define TAR_OBJ_INV     (1 << 7)
#define TAR_OBJ_ROOM    (1 << 8)
#define TAR_OBJ_WORLD   (1 << 9)
#define TAR_OBJ_EQUIP	  (1 << 10)

struct spell_info_type {
    byte min_position; /* Position for caster	 */
    int mana_min; /* Min amount of mana used by a spell (highest lev) */
    int mana_max; /* Max amount of mana used by a spell (lowest lev) */
    int mana_change; /* Change in mana used by spell from lev to lev */

    int min_level[NUM_CLASSES];
    int routines;
    byte violent;
    int targets; /* See below for use with TAR_XXX  */
    const char *name; /* Input size not limited. Originates from string constants. */
    const char *wear_off_msg; /* Input size not limited. Originates from string constants. */
    byte can_learn_skill[NUM_CLASSES];
    int skilltype; /* Is it a spell, skill, art, feat, or what? used as bitvector */
    int flags;
    int artisan_type;
};

/* Possible Targets:
   bit 0 : IGNORE TARGET
   bit 1 : PC/NPC in room
   bit 2 : PC/NPC in world
   bit 3 : Object held
   bit 4 : Object in inventory
   bit 5 : Object in room
   bit 6 : Object in world
   bit 7 : If fighting, and no argument, select tar_char as self
   bit 8 : If fighting, and no argument, select tar_char as victim (fighting)
   bit 9 : If no argument, select self, if argument check that it IS self. */
#define SPELL_TYPE_SPELL   0
#define SPELL_TYPE_POTION  1
#define SPELL_TYPE_WAND    2
#define SPELL_TYPE_STAFF   3
#define SPELL_TYPE_SCROLL  4

#define ASPELL(spellname) \
void	spellname(int level, struct char_data *ch, \
		  struct char_data *victim, struct obj_data *obj)

#define MANUAL_SPELL(spellname)	spellname(level, caster, cvict, ovict);

ASPELL(spell_create_water);
ASPELL(spell_recall);
ASPELL(spell_teleport);
ASPELL(spell_summon);
ASPELL(spell_locate_object);
ASPELL(spell_charm);
ASPELL(spell_information);
ASPELL(spell_identify);
ASPELL(spell_enchant_weapon);
ASPELL(spell_detect_poison);

/* basic magic calling functions */

int find_skill_num(char *name, int sktype);

int mag_damage(int level, struct char_data *ch, struct char_data *victim,
        int spellnum, int savetype);

void mag_affects(int level, struct char_data *ch, struct char_data *victim,
        int spellnum, int savetype);

void mag_groups(int level, struct char_data *ch, int spellnum, int savetype);

void mag_masses(int level, struct char_data *ch, int spellnum, int savetype);

void mag_areas(int level, struct char_data *ch, int spellnum, int savetype);

void mag_rooms(int level, struct char_data *ch, int spellnum);

void mag_summons(int level, struct char_data *ch, struct obj_data *obj,
        int spellnum, int savetype);

void mag_points(int level, struct char_data *ch, struct char_data *victim,
        int spellnum, int savetype);

void mag_unaffects(int level, struct char_data *ch, struct char_data *victim,
        int spellnum, int type);

void mag_alter_objs(int level, struct char_data *ch, struct obj_data *obj,
        int spellnum, int type);

void mag_creations(int level, struct char_data *ch, int spellnum);

int call_magic(struct char_data *caster, struct char_data *cvict,
        struct obj_data *ovict, int spellnum, int level, int casttype);

void mag_objectmagic(struct char_data *ch, struct obj_data *obj,
        char *argument);

int cast_spell(struct char_data *ch, struct char_data *tch, struct obj_data *tobj, int spellnum);

/* other prototypes */
void spell_level(int spell, int chclass, int level);
void init_spell_levels(void);
const char *skill_name(int num);
void skill_class(int skill, int chclass, int learntype);
int skill_type(int skill);

/* From magic.c */
int mag_savingthrow(struct char_data *ch, int type, int modifier);
void affect_update(void);

/* from spell_parser.c */
ACMD(do_cast);
void unused_spell(int spl);
void mag_assign_spells(void);

/* Global variables exported */
#ifndef __SPELL_PARSER_C__

extern struct spell_info_type spell_info[];
extern char cast_arg2[];
extern const char *unused_spellname;

#endif /* __SPELL_PARSER_C__ */

#endif /* _SPELLS_H_ */
