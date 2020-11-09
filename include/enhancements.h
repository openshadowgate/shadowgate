/**
 * Definitions for weapon and armor enhancements for magus, paladin and whatever might come later.
 * Venger
 */

#define VALID_WEAPON_ENHANCEMENTS ([ \
                                "flaming" : ([ "property" : "fire", "cost" : 1 ]), \
                                "frost" : ([ "property" : "cold", "cost" : 1 ]), \
                                "shock" : ([ "property" : "electricity", "cost" : 1 ]), \
                                "thundering" : ([ "property" : "sonic", "cost" : 1 ]), \
                                "corrosive" : ([ "property" : "acid", "cost" : 1 ]), \
                                "flaming burst" : ([ "property" : "fire burst", "cost" : 2 ]), \
                                "icy burst" : ([ "property" : "cold burst", "cost" : 2 ]), \
                                "shocking burst" : ([ "property" : "electricity burst", "cost" : 2 ]), \
                                "thundering burst" : ([ "property" : "sonic burst", "cost" : 2 ]), \
                                "corrosive burst" : ([ "property" : "acid burst", "cost" : 2 ]), \
                                "holy" : ([ "property" : "alignment 147", "cost" : 2 ]), \
                                "unholy" : ([ "property" : "alignment 369", "cost" : 2 ]), \
                                "axiomatic" : ([ "property" : "alignment 123", "cost" : 2 ]), \
                                "anarchic" : ([ "property" : "alignment 789", "cost" : 2 ]), \
                                "keen" : ([ "property" : "keen weapon", "cost" : 1 ]), \
                                "speed" : ([ "property" : "speedy weapon", "cost" : 3 ]), \
                            ]);

#define MAGUS_WEAPON_ENHANCEMENTS ({ "flaming", "frost", "shock", "flaming burst", "icy burst", "shocking burst", });
#define THUNDERING_ENHANCEMENTS ({ "thundering", "thundering burst", });
#define CORROSIVE_ENHANCEMENTS ({ "corrosive", "corrosive burst", });
#define ALIGNMENT_ENHANCEMENTS ({ "holy", "unholy", "axiomatic", "anarchic", });
//magus pending: dancing, vorpal, speedy, keen.

#define PALADIN_WEAPON_ENHANCEMENTS ({ "flaming", "flaming burst", "holy", "unholy", "axiomatic", "anarchic", });
//paladin pending: brilliant energy, defending, disruption, merciful, speedy, keen.
//antipaladin pending: vicious, wounding, vorpal, keen.

#define VALID_ARMOR_ENHANCEMENTS ([ \
                                "light fortification" : ([ "property" : "fortification 25", "cost" : 1 ]), \
                                "moderate fortification" : ([ "property" : "fortification 50", "cost" : 3 ]), \
                                "heavy fortification" : ([ "property" : "fortification 75", "cost" : 5 ]), \
                                "invulnerability" : ([ "property" : "invulnerability", "cost" : 3 ]), \
                                "acid energy resistance" : ([ "property" : "acid energy resistance", "cost" : 4 ]), \
                                "cold energy resistance" : ([ "property" : "cold energy resistance", "cost" : 4 ]), \
                                "electricity energy resistance" : ([ "property" : "electricity energy resistance", "cost" : 4 ]), \
                                "fire energy resistance" : ([ "property" : "fire energy resistance", "cost" : 4 ]), \
                                "sonic energy resistance" : ([ "property" : "sonic energy resistance", "cost" : 4 ]), \
                            ]);

#define MAGUS_ARMOR_ENHANCEMENTS ({ "light fortification", "moderate fortification", "heavy fortification", "invulnerability", \
                                    "acid energy resistance", "cold energy resistance", "electricity energy resistance", "fire energy resistance", "sonic energy resistance", });

#define PALADIN_ARMOR_ENHANCEMENTS ({ "light fortification", "moderate fortification", "heavy fortification", "invulnerability", \
                                    "acid energy resistance", "cold energy resistance", "electricity energy resistance", "fire energy resistance", "sonic energy resistance", });