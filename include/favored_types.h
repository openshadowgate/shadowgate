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
                         "aberrations" : ({ "beholder", "illithid", "mind flayer" }), \
                         "animals" : ({ "snake", "serpent", "warthog", "jaguar", "wolf", "rat", "tiger", "reptile", "dinosaur", "dino", "spider", "deer", "snake", "horse", "mare", "stallion" }), \
                         "constructs" : ({ "construct", "golem", "sandman", "sandling" }), \
                         "dwarves"  : ({ "dwarf", "duergar" }), \
                         "dragonkin"  : ({ "kobold", "draconian", "dragon", "elven-dragon", "dragonet", "pseudodragon", "drake", "wyvern" }), \
                         "elementals" : ({ "elemental", "genasi", "earth genasi", "air genasi", "water genasi", "air genasi", "efreet", "djinn", "marid", "genie" }), \
                         "elves"      : ({ "elf", "half-elf", "drow", "half-drow", "szarkai" }), \
                         "evil outsiders"   : ({ "demon", "devil", "imp", "tiefling", "githyanki", "githzerai" }), \
                         "fey"        : ({ "nymph", "satyr", "dryad", "pixie", "brownie", "feytouched", "fey" }), \
                         "giants"     : ({ "voadkyn", "firbolg", "giant", "titan" }), \
                         "goblins"    : ({ "goblin", "bugbear", "hobgoblin", "goblinoid" }), \
                         "good outsiders" : ({ "deva", "solar", "aasimar", "angel" }), \
                         "humans"     : ({ "human", "shade", "half-elf", "half-orc", "half-ogre", "half-drow", "genasi", "feytouched", "aasimar", "tiefling" }), \
                         "lizardfolk" : ({ "yuan-ti", "saurian", "salamander", "lizardman", "firenewt" }), \
                         "magical beasts" : ({ "owlbear", "grimlock", "jackalwere", "wolfwere", "ooze", "worm", "pegataur", "griffon", "hydra", "shadow", "magical beast" }), \
                         "monstrous humanoids"   : ({ "beastkin", "wemic", "centaur", "ratkin", "minotaur", "gnoll", "kitsune", "werewolf", "wererat", "weretiger", "alaghi", "monstrous humanoid", "troll" }), \
                         "ogres"      : ({ "ogre", "ogre-mage", "half-ogre", "ogroid" }), \
                         "orcs"       : ({ "orc", "half-orc", "orog", "tanarukk", "orcoid" }), \
                         "plants" : ({ "shambler", "shambling mound", "tree", "vine", "plant" }), \
                         "smallfolk"  : ({ "gnome", "halfling", "kender", "derro", "pech", }), \
                         "undead"     : ({ "ghost", "skeleton", "lich", "zombie", "ghast", "entity", "spirit", "wraith", "wight" }), \
                     ])
