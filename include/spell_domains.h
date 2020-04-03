#include <std.h>

#define SPELL_DOMAINS (([\
    "jarmila"          : ({ "good", "renewal", "sun", "protection", "fire" }) ,\
    "callamir"         : ({ "good", "charm", "air", "trickery", "travel", "chaos"}), \
    "kreysneothosies"  : ({ "protection", "vigilance", "strength", "good", "war", "law"}) , \
    "nilith"           : ({ "war", "strength", "destruction", "evil", "chaos"}), \
    "lord shadow"      : ({ "evil", "cold", "tyranny", "suffering", "darkness", "law"}) , \
    "the faceless one" : ({ "trickery", "illusion", "cavern", "darkness", "evil",}) , \
    "kismet"           : ({ "creation", "knowledge", "mentalism", "magic", "law"}) , \
    "lysara"           : ({ "travel", "fate", "repose", "moon", "water" }) ,\
    "nimnavanon"       : ({ "storms", "plant", "animal", "earth", "destruction" }) , \
    "ryorik"           : ({ "air", "fire", "earth", "water", "chaos"}) ,\
]))

// order of spells is important
#define DOMAIN_SPELLS ([\
"plant":({"1:entangle", "2:barkskin", "4:thorn body", "5:wall of thorns", "7:animate plants", "7:liveoak", "8:mind blank", "9:shambler"}),\

])
