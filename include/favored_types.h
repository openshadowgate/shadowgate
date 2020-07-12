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
                         "fey"        : ({ "nymph", "satyr", "dryad", "pixie", "brownie", "feytouched" }), \
                         "orcs"       : ({ "orc", "half-orc", "orog" }), \
                         "beastmen"   : ({ "beastkin", "wemic", "centaur", "ratkin", "minotaur", "gnoll", "kitsune", "werewolf", "wererat", "weretiger", "alaghi" }), \
                         "humans"     : ({ "human", "shade", "half-elf", "half-orc", "half-ogre", "half-drow" }), \
                         "reptiles" : ({ "yuan-ti", "saurian", "serpent", "salamander", "lizardman", "firenewt", "reptile" }), \
                         "undead"     : ({ "ghost", "skeleton", "lich", "zombie", "ghast", "entity", "spirit" }), \
                         "good outsiders" : ({ "deva", "solar", "aasimar" }), \
                         "evil outsiders"   : ({ "demon", "devil", "imp", "tiefling" }), \
                         "dragonkin"  : ({ "kobold", "draconian", "dragon", "elven-dragon", "dragonet", "pseudodragon", "drake", "wyvern" }), \
                         "giants"     : ({ "voadkyn", "firbolg", "giant", "titan" }), \
                         "smallfolk"  : ({ "gnome", "halfling", "kender", "dwarf", "derro" }), \
                         "elementals" : ({ "elemental", "genasi", "earth genasi", "air genasi", "water genasi", "air genasi", "efreet", "djinn", "marid" }), \
                         "aberrations" : ({ "beholder", "illithid", "mind flayer" }), \
                         "magical beasts" : ({ "owlbear", "grimlock", "jackalwere", "wolfwere", "ooze", "worm", "pegataur", "griffon", "hydra", "shadow", "shambling mound", "shambler" }), \
                         "constructs" : ({ "construct", "golem", "sandman", "sandling" }), \
                     ])
