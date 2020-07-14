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
                           "cold"   : ({ "snow", "ice", "glacier" }), \
                           "water"  : ({ "shallow water", "deep water", "beach", "shore", "boats" }), \
                           "city"   : ({ "ruins", "city", "cemetary", "garden", "stone building", "wood building", "hut" }), \
                           "caves"  : ({ "nat cave", "built cave", "built tunnel", "nat tunnel" }), \
                           "hills"  : ({ "hills", "rocky", "old mounts", "new mounts" }), \
                       ])

#define VALID_ENEMY ([ \
                         "aberrations" : ({ "aberrations", "beholder", "illithid", "mind flayer", }), \
                         "animals" : ({ "animals", "snake", "serpent", "warthog", "jaguar", "wolf", "rat", "tiger", "reptile", "dinosaur", "dino", "spider", "deer", "snake", "horse", "mare", "stallion" }), \
                         "constructs" : ({ "constructs", "construct", "golem", "sandman", "sandling" }), \
                         "dwarves"  : ({ "dwarf", "dwarves", "duergar" }), \
                         "dragonkin"  : ({ "dragonkin", "kobold", "draconian", "dragon", "elven-dragon", "dragonet", "pseudodragon", "drake", "wyvern" }), \
                         "elementals" : ({ "elementals", "elemental", "genasi", "earth genasi", "air genasi", "water genasi", "air genasi", "efreet", "djinn", "marid", "genie" }), \
                         "elves"      : ({ "elf", "elves", "half-elf", "drow", "half-drow", "szarkai" }), \
                         "fey"        : ({ "fey", "nymph", "satyr", "dryad", "pixie", "brownie", "feytouched", "fey" }), \
                         "giants"     : ({ "giants", "voadkyn", "firbolg", "giant", "titan", "troll" }), \
                         "goblins"    : ({ "goblins", "goblin", "bugbear", "hobgoblin", "goblinoid" }), \
                         "humans"     : ({ "humans", "human", "shade", "half-elf", "half-orc", "half-ogre", "half-drow", "genasi", "feytouched", "aasimar", "tiefling" }), \
                         "lizardfolk" : ({ "lizardfolk", "yuan-ti", "saurian", "salamander", "lizardman", "firenewt" }), \
                         "magical beasts" : ({ "magical beasts", "owlbear", "grimlock", "jackalwere", "wolfwere", "ooze", "worm", "pegataur", "griffon", "hydra", "shadow", "magical beast" }), \
                         "monstrous humanoids"   : ({ "monstrous humanoids", "beastkin", "wemic", "centaur", "ratkin", "minotaur", "gnoll", "kitsune", "werewolf", "wererat", "weretiger", "alaghi", "monstrous humanoid", }), \
                         "ogres"      : ({ "ogres", "ogre", "ogre-mage", "half-ogre", "ogroid", }), \
                         "orcs"       : ({ "orcs", "orc", "half-orc", "orog", "tanarukk", "orcoid", }), \
                         "outsiders"  : ({ "outsiders", "deva", "solar", "aasimar", "angel", "demon", "devil", "imp", "tiefling", "githyanki", "githzerai", "outsider"  }), \
                         "plants" : ({ "shambler", "shambling mound", "tree", "vine", "plant", "plants", }), \
                         "smallfolk"  : ({ "gnome", "halfling", "kender", "derro", "pech", "smallfolk", }), \
                         "undead"     : ({ "ghost", "skeleton", "lich", "zombie", "ghast", "entity", "spirit", "undead", "wraith", "wight" }), \
                     ])
