#define DISCIPLINESPELLS ({ "animal affinity","clairvoyance","thicken skin","hypercognition", "sending","chameleon","energy cone","call crystals","aura sight","animate object", "psionic teleport","hail of crystals","astral construct","speak with dead","mindnet","tornado blast","planar portal","planar sending","reddopsi","energy current","domination","prying eyes","modify memory"});

#define DISCIPLINESPELLSBYLEVEL ([\
    0:({}),\
    1:({"thicken skin","dissonance","minor creation","animate object","expeditious retreat","command"}),\
    2:({"animal affinity","clairvoyance","astral construct","energy emanation","leaps and bounds","charm monster"}),\
    3:({"chameleon","hypercognition","ectoplasmic cocoon","energy cone","trace teleport","hostile empathic transfer"}),\
    4:({"deathward","escape detection","creation","hold person","dimensional anchor","modify memory"}),\
    5:({"breath of life","remote viewing","hail of crystals","energy current","psionic teleport","domination"}),\
    6:({"restoration","legend lore","ruin","bolt of force","planar sending","serenity"}),\
    7:({"lesser transformation","prying eyes","rebirth","reddopsi","planar portal","visions from within"}), \
    8:({"shadow double","fortune fate","create demiplane","crushing hand","astral projection","mindnet"}), \
    9:({"shadow body","foresight","implosion","tornado blast","timestop","overwhelming presence"}),\
]);

// The only improtant array as of 2020
#define DISCIPLINESPELLSBYDISCIPLINE ([\
    "egoist":({"thicken skin","animal affinity","chameleon","deathward","breath of life","restoration","lesser transformation","shadow double","shadow body"}),\
    "seer":({"dissonance","clairvoyance","hypercognition","escape detection","remote viewing","legend lore","prying eyes","fortune fate","foresight"}),\
    "shaper":({"minor creation","astral construct","ectoplasmic cocoon","creation","hail of crystals","ruin","rebirth","create demiplane","implosion"}),\
    "kineticist":({"animate object","energy emanation","energy cone","hold person","energy current","bolt of force","reddopsi","crushing hand","tornado blast"}),\
    "nomad":({"expeditious retreat","leaps and bounds","trace teleport","dimensional anchor","psionic teleport","planar sending","planar portal","astral projection","timestop"}),\
    "telepath":({"command","charm monster","hostile empathic transfer","modify memory","domination","serenity","visions from within","mindnet","overwhelming presence"}),\
]);

#define DISCIPLINEFILES ([\
    "egoist":({1: "t/_thicken_skin", 2: "a/_animal_affinity", 3: "c/_chameleon", 4: "d/_deathward", 5: "b/_breath_of_life", 6: "r/_restoration", 7: "l/_lesser_transformation", 8: "s/_shadow_double", 9: "s/_shadow_body"}), \
    "seer":({1: "d/_dissonance", 2: "c/_clairvoyance", 3: "h/_hypercognition", 4: "e/_escape_detection", 5: "r/_remote_viewing", 6: "l/_legend_lore", 7: "p/_prying_eyes", 8: "f/_fortune_fate", 9: "f/_foresight"}), \
    "shaper":({1: "m/_minor_creation", 2: "a/_astral_construct", 3: "e/_ectoplasmic_cocoon", 4: "c/_creation", 5: "h/_hail_of_crystals", 6: "r/_ruin", 7: "r/_rebirth", 8: "c/_create_demiplane", 9: "i/_implosion"}), \
    "kineticist":({1: "a/_animate_object", 2: "e/_energy_emanation", 3: "e/_energy_cone", 4: "h/_hold_person", 5: "e/_energy_current", 6: "b/_bolt_of_force", 7: "r/_reddopsi", 8: "c/_crushing_hand", 9: "t/_tornado_blast"}),\
    "nomad":({ 1: "e/_expeditious_retreat", 2: "l/_leaps_and_bounds", 3: "t/_trace_teleport", 4: "d/_dimensional_anchor", 5: "p/_psionic_teleport", 6: "p/_planar_sending", 7: "p/_planar_portal", 8: "a/_astral_projection", 9: "t/_timestop"}),\
    "telepath":({1: "c/_command", 2: "c/_charm_monster", 3: "h/_hostile_empathic_transfer", 4: "m/_modify_memory", 5: "d/_domination", 6: "s/_serenity", 7: "v/_visions_from_within", 8: "m/_mindnet", 9: "o/_overwhelming_presence"}),\
]);

#define DISCIPLINESBYLEVEL ([\
   "egoist": ({1: "thicken skin", 2: "animal affinity", 3: "chameleon", 4: "deathward", 5: "breath of life", 6: "restoration", 7: "lesser transformation", 8: "shadow double", 9: "shadow body"}), \
   "seer": ({1: "dissonance", 2: "clairvoyance", 3: "hypercognition", 4: "escape detection", 5: "remote viewing", 6: "legend lore", 7: "prying eyes", 8: "fortune fate", 9: "foresight"}), \
   "shaper": ({1: "minor creation", 2: "astral construct", 3: "ectoplasmic cocoon", 4: "creation", 5: "hail of crystals", 6: "ruin", 7: "rebirth", 8: "create demiplane", 9: "implosion"}), \
   "kineticist": ({1: "animate object", 2: "energy emanation", 3: "energy cone", 4: "hold person", 5: "energy current", 6: "bolt of force", 7: "reddopsi", 8: "crushing hand", 9: "tornado blast"}),\
   "nomad": ({1: "expeditious retreat", 2: "leaps and bounds", 3: "trace teleport", 4: "dimensional anchor", 5: "psionic teleport", 6: "planar sending", 7: "planar portal", 8: "astral projection", 9: "timestop"}),\
   "telepath": ({1: "command", 2: "charm monster", 3: "hostile empathic transfer", 4: "modify memory", 5: "domination", 6: "serenity", 7: "visions from within", 8: "mindnet", 9: "overwhelming presence"}),\
]);
