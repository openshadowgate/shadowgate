/*
   favored_types.h

   Definitions for favored terrain and favored enemy.

   -- Tlaloc -- 7.20
 */

#define VALID_TERRAIN ([ \
                           "jungle" : ({ "jungle", "dense jungle" }), \
                           "forest" : ({ "heavy forest", "light forest", "branches" }), \
                           "plains" : ({ "scrub lands", "grasslands", "savannah", "meadows" }), \
                           "desert" : ({ "desert", "desert dunes", "desert rocks" }), \
                           "swamp"  : ({ "swamp", "marsh" }), \
                           "snow"   : ({ "snow", "ice", "glacier" }), \
                           "water"  : ({ "shallow water", "deep water", "beach", "shore", "boats" }), \
                           "city"   : ({ "ruins", "city", "cemetary", "garden", "stone building", "wood building", "hut" }), \
                           "caves"  : ({ "nat cave", "built cave", "built tunnel", "nat tunnel" }), \
                           "hills"  : ({ "hills", "rocky", "old mounts", "new mounts" }), \
                       ])

#define VALID_ENEMY ([ \
                         "ogres"      : ({ "ogre", "ogre-mage", "half-ogre" }), \
                         "elves"      : ({ "elf", "half-elf", "drow", "half-drow", "szarkai" }), \
                         "goblins"    : ({ "goblin", "bugbear", "hobgoblin" }), \
                         "fey"        : ({ "nymph", "satyr", "dryad", "pixie", "brownie" }), \
                         "orcs"       : ({ "orc", "half-orc", "orog" }), \
                         "beastmen"   : ({ "beastkin", "wemic", "centaur", "ratkin", "minotaur", "gnoll", "kitsune", "pegataur", "alaghi" }), \
                         "humans"     : ({ "human", "shade", "half-elf", "half-orc", "half-ogre", "half-drow" }), \
                         "reptiles" : ({ "yuan-ti", "saurian", "serpent", "salamander" }), \
                         "undead"     : ({ "ghost", "skeleton", "lich", "zombie", "ghast", "entity", "spirit" }), \
                         "celestials" : ({ "deva", "solar" }), \
                         "abyssals"   : ({ "demon", "devil", "imp" }), \
                         "dragonkin"  : ({ "kobold", "draconian", "dragon", "elven-dragon", "dragonet", "pseudodragon", "drake", "wyvern" }), \
                         "giants"     : ({ "voadkyn", "firbolg", "giant", "titan" }), \
                         "smallfolk"  : ({ "gnome", "halfling", "kender", "dwarf" }), \
                         "elementals" : ({ "elemental" }), \
                         "aberrations" : ({ "beholder", "illithid", "mind flayer" }), \
                         "magical beasts" : ({ "owlbear", "grimlock", "jackalwere", "wolfwere", "ooze", "worm" }), \
                         "constructs" : ({ "construct", "golem", "sandman", "sandling" }), \
                     ])
