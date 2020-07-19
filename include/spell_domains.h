#include <std.h>

// Must correspond to deities.h

// Occult gods are in this file for multiclassing only. People that MC
// with cleric will have to deal with domain disbalance on their own
// unless someone looks at it.
#define SPELL_DOMAINS (([\
    "callamir"         : ({ "good", "charm", "air", "trickery", "travel", "chaos",}), \
    "cevahir"          : ({ "knowledge", "mentalism", "renewal", "strength", "war" }) , \
    "dream"            : ({ "chaos", "madness", "void", "stars", "evil", "good"}),\
    "jarmila"          : ({ "good", "renewal", "sun", "protection", "fire", "martyr" }) ,\
    "khyron"           : ({ "fire", "storms", "destruction", "suffering", "chaos", }) , \
    "kismet"           : ({ "creation", "knowledge", "magic", "stars"}) , \
    "kreysneothosies"  : ({ "protection", "vigilance", "strength", "good", "war", "law"}) , \
    "lord shadow"      : ({ "evil", "cold", "tyranny", "suffering", "darkness", "law"}) , \
    "lysara"           : ({ "travel", "fate", "repose", "moon", "water", "void"}) , \
    "nilith"           : ({ "war", "strength", "destruction", "evil", "chaos", "undeath"}), \
    "nimnavanon"       : ({ "storms", "plant", "animal", "earth", "destruction", "plague" }) , \
    "seija"            : ({ "elements", "sun", "moon", "cavern", "law"}) , \
    "the faceless one" : ({ "trickery", "illusion", "cavern", "darkness", "evil", "madness"}) , \
]))
