/*
   favored_types.h

   Definitions for favored terrain and favored enemy.

   -- Tlaloc -- 7.20
 */

#define VALID_TERRAIN ([ \
                           "road"   : ({ "paved road", "dirt road", "foot path", "rutted track", "game track" }), \
                           "jungle" : ({ "jungle", "dense jungle" }), \
                           "forest" : ({ "heavy forest", "light forest", "branches" }), \
                           "plains" : ({ "scrub lands", "grasslands", "savannah", "meadows" }), \
                           "desert" : ({ "desert", "desert dunes", "desert rocks" }), \
                           "swamp"  : ({ "swamp", "marsh" }), \
                           "snow"   : ({ "snow", "ice", "glacier" }), \
                           "water"  : ({ "shallow water", "deep water", "beach", "shore", "boats" }), \
                           "city"   : ({ "back alley", "stairway", "ledge", "ruins", "city", "cemetary", "garden", "stone building", "wood building", "hut" }), \
                           "caves"  : ({ "nat cave", "built cave", "built tunnel", "nat tunnel" }), \
                           "hills"  : ({ "hills", "rocky" }), \
                       ])

#define VALID_ENEMY ([ \
                         "ogres"      : ({ "ogre", "ogre-mage", "half-ogre" }), \
                         "elves"      : ({ "elf", "half-elf", "drow", "half-drow", "szarkai" }), \
                         "goblins"    : ({ "goblin", "bugbear", "hobgoblin" }), \
                         "fey"        : ({ "nymph", "satyr", "dryad" }), \
                         "orcs"       : ({ "orc", "half-orc" }), \
                         "beastmen"   : ({ "beastkin", "wemic", "centaur", "ratkin", "minotaur", "gnoll", "kitsune", "pegataur", "alaghi" }), \
                         "humans"     : ({ "human", "shade", "half-elf", "half-orc", "half-ogre" }), \
                         "lizardfolk" : ({ "yuan-ti", "saurian" }), \
                         "undead"     : ({ "ghost", "skeleton", "lich", "zombie", "ghast", "entity", "spirit" }), \
                         "celestials" : ({ "deva" }), \
                         "abyssals"   : ({ "demon", "devil" }), \
                         "dragonkin"  : ({ "kobold", "draconian", "dragon", "elven-dragon", "dragonet" }), \
                         "giants"     : ({ "voadkyn", "firbolg", "giant", "titan" }), \
                         "smallfolk"  : ({ "gnome", "halfling", "kender", "dwarf" }), \
                         "elementals" : ({ "elemental", "golem" }), \
                         "aberations" : ({ "beholder", "illithid", "mind flayer" }), \
                         "magical beasts" : ({ "owlbear" }), \
                     ])
