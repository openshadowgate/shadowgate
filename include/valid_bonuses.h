//Doing it this way per garrett's suggestion - this way, if somewhere down the
//road we want specific bonuses to only work on specific types of
//equipment/items - Saide - June 2008
//shieldMiss added by ~Circe~ 2/28/13 to support new shield function.
// removed invalid energy types per notes in damage_types.h; removing percentages altogether. N, 8/15
//score -bonuses - will let players see all bonuses from items that they have
//identified - so make sure to update this file whenever any new bonuses get added
//Saide - February 2017
// removing 'temporary feats' option until someone wants to code it properly. It's doing nothing but
// sitting as a string on the item right now and costing the enchant anyway. N, 11/17.

#define VALID_ARMOR_BONUSES ({"armor bonus", \
    "attack bonus", \
    "damage bonus", \
    "max hp bonus", \
    "light", \
    "sight bonus", \
    "magic resistance", \
    "spell damage resistance",\
    "damage resistance", \
    "caster level", \
    "spell penetration", \
    "bonus_spell_slots", \
    "bonus_spell_slots_1", \
    "bonus_spell_slots_2", \
    "bonus_spell_slots_3", \
    "bonus_spell_slots_4", \
    "bonus_spell_slots_5", \
    "bonus_spell_slots_6", \
    "bonus_spell_slots_7", \
    "bonus_spell_slots_8", \
    "bonus_spell_slots_9", \
    "shieldMiss", \
    "fire resistance", \
    "cold resistance", \
    "electricity resistance", \
    "acid resistance", \
    "sonic resistance", \
    "bludgeoning resistance", \
    "piercing resistance", \
    "slashing resistance", \
    "silver resistance", \
    "cold iron resistance", \
    "positive energy resistance", \
    "negative energy resistance", \
    "force resistance", \
    "divine resistance", \
    "untyped resistance", \
    "mental resistance", \
    "strength", \
    "dexterity", \
    "constitution", \
    "intelligence", \
    "wisdom", \
    "charisma",\
    "reflex", \
    "fortitude", \
    "will", \
    "academics", \
    "athletics", \
    "craft, armorsmith", \
    "craft, jeweller", \
    "craft, leatherwork", \
    "craft, tailor", \
    "craft, weaponsmith", \
    "craft, woodworker", \
    "disguise", \
    "dungeoneering", \
    "endurance", \
    "healing", \
    "influence", \
    "perception", \
    "rope use", \
    "stealth", \
    "spellcraft", \
    "survival", \
    "thievery", \
    })

#define VALID_WEAPON_BONUSES ({ })

#define VALID_OTHER_BONUSES ({ })

#define VALID_BONUSES (VALID_ARMOR_BONUSES + VALID_WEAPON_BONUSES + VALID_OTHER_BONUSES)
