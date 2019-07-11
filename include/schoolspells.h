#define SCHOOL_OPPOSITION ([ "abjuration":"conjuration_summoning","alteration":"conjuration_summoning","conjuration_summoning":"alteration","divination":"illusion","invocation_evocation":"conjuration_summoning","necromancy":"divination","enchantment_charm":"illusion"])

#define SCHOOLSPELLS ({"shield","summon swarm","daze","shocking grasp","darkvision","clairvoyance","misdirection","blindness", \
"heroism","haste","black tentacles","fire shield","greater invisibility","bestow curse","break curse","telepathic bond",\
"planar beacon","mind fog","resonating word","foresight","spell turning","mages sword","project image","deny the reaper",\
"dimensional lock","timestop","gate","prying eyes","powerword kill","sunburst","phantasmal killer","animus blast"})

#define SCHOOLSPELLSBYLEVEL ([\
    0:({}),\
    1:({ "shield", "summon swarm", "daze", "shocking grasp" }),\
    2:({ "darkvision", "clairvoyance", "misdirection", "blindness" }),\
    3:({ "heroism", "haste" }),\
    4:({ "black tentacles", "fire shield", "greater invisibility", "bestow curse" }),\
    5:({ "break curse", "telepathic bond" }),\
    6:({ "planar beacon", "mind fog" }),\
    7:({ "resonating word", "foresight", "spell turning", "mages sword", "project image", "deny the reaper" }),\
    8:({}),\
    9:({ "dimensional lock", "timestop", "gate", "prying eyes", "powerword kill", "sunburst", "phantasmal killer", "animus blast" }),\
])

#define SCHOOLSPELLSBYSCHOOL ([\
    "abjuration":({ "shield", "break curse", "spell turning", "dimensional lock" }),\
    "alteration":({ "darkvision", "haste", "resonating word", "timestop" }),\
    "conjuration_summoning":({ "summon swarm", "black tentacles", "planar beacon", "gate" }),\
    "greater divination":({ "clairvoyance", "telepathic bond", "foresight", "prying eyes" }),\
    "enchantment_charm":({ "daze", "heroism", "mind fog", "powerword kill" }),\
    "illusion":({ "misdirection", "greater invisibility", "project image", "phantasmal killer" }),\
    "invocation_evocation":({ "shocking grasp", "fire shield", "mages sword", "sunburst" }),\
    "necromancy":({ "blindness", "bestow curse", "deny the reaper", "animus blast" }),\
])

#define SCHOOLFILES ([\
    "abjuration":([ 1: "s/_shield", 5: "b/_break_curse", 7: "s/_spell_turning", 9: "d/_dimensional_lock" ]),\
    "alteration":([ 2: "d/_darkvision.c", 3: "h/_haste", 7: "r/_resonating_word", 9: "t/_timestop" ]),\
    "conjuration_summoning":([ 1: "s/_summon_swarm", 4: "b/_black_tentacles", 6: "p/_planar_beacon", 9: "g/_gate" ]),\
    "greater divination":([ 2: "c/_clairvoyance", 5: "t/_telepathic_bond", 7: "f/_foresight", 9: "p/_prying_eyes" ]),\
    "enchantment_charm":([ 1: "d/_daze", 3: "h/_heroism", 6: "m/_mind_fog", 9: "p/_powerword_kill" ]),\
    "illusion":([ 1: "m/_misdirection", 4: "g/_greater_invisibility", 7: "p/_project_image", 9: "p/_phantasmal_killer" ]),\
    "invocation_evocation":([ 1: "s/_shocking_grasp", 4: "f/_fire_shield", 7: "m/_mages_sword", 9: "s/_sunburst" ]),\
    "necromancy":([ 2: "b/_blindness", 4: "b/_bestow_curse", 7: "d/_deny_the_reaper", 9: "a/_animus_blast" ]),\
])
