#include <std.h>
#include <daemons.h>

int checkDispel(object ob, int clevel, object caster)
{
    int roll, level_diff;
    object mycast, yourcast;

    if (!objectp(ob)) {
        return 0;
    }
    if (caster == ob->query_caster()) {
        return 1;
    }
    
    if(!caster)
        caster = previous_object()->query_caster();

    yourcast = ob->query_caster();
    
    if (!objectp(yourcast) || !objectp(caster)) {
        return 0;
    }

    level_diff = clevel - ob->query_clevel();

    roll = roll_dice(1, 12) - 6;

    if (FEATS_D->usable_feat(yourcast, "elusive spellcraft") &&
        !FEATS_D->usable_feat(caster, "elusive spellcraft")) {
        roll -= 4;
    }
    
    if(FEATS_D->usable_feat(yourcast, "mystic arcana"))
        roll -= ( ( yourcast->query_stats("charisma") - 10 ) / 5);

    if (yourcast->query_property("dispelling_buffer") > 0) {
        roll -= yourcast->query_property("dispelling_buffer");
    }

    if (roll + level_diff >= 0) {
        return 1;
    } else {
        return 0;
    }
}
