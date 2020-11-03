/**
 * Definitions for weapon enhancements for magus, paladin and whatever might come later.
 * Venger
 */

#define VALID_ENHANCEMENTS ([ \
                                "flaming" : ([ "property" : "fire", "cost" : 1 ]), \
                                "frost" : ([ "property" : "cold", "cost" : 1 ]), \
                                "shock" : ([ "property" : "electricity", "cost" : 1 ]), \
                                "flaming burst" : ([ "property" : "fire burst", "cost" : 2 ]), \
                                "icy burst" : ([ "property" : "cold burst", "cost" : 2 ]), \
                                "shocking burst" : ([ "property" : "electricity burst", "cost" : 2 ]), \
                                "holy" : ([ "property" : "alignment 147", "cost" : 2 ]), \
                                "unholy" : ([ "property" : "alignment 369", "cost" : 2 ]), \
                                "axiomatic" : ([ "property" : "alignment 123", "cost" : 2 ]), \
                                "anarchic" : ([ "property" : "alignment 789", "cost" : 2 ]), \
                                "keen" : ([ "property" : "keen weapon", "cost" : 1 ]), \
                                "speed" : ([ "property" : "speedy weapon", "cost" : 3 ]), \
                            ]);

#define MAGUS_ENHANCEMENTS ({ "flaming", "frost", "shock", "flaming burst", "icy burst", "shocking burst", "keen" });
//magus pending: dancing, vorpal, speedy.

#define PALADIN_ENHANCEMENTS ({ "flaming", "flaming burst", "holy", "unholy", "axiomatic", "anarchic", "keen" });
//paladin pending: brilliant energy, defending, disruption, merciful, speedy.
//antipaladin pending: vicious, wounding, vorpal