int checkDispel(object ob, int clevel)
{
    int roll, level_diff;
    object mycast;

    if (!objectp(ob)) {
        return 0;
    }
    if (TO->query_caster() == ob->query_caster()) {
        return 1;
    }

    mycast = ob->query_caster();
    if (!objectp(mycast)) {
        return 0;
    }

    level_diff = (int)ob->query_clevel() - clevel;

    roll = 6 - roll_dice(1, 12);

    if (FEATS_D->usable_feat(ob->query_caster(), "elusive spellcraft") &&
        !FEATS_D->usable_feat(TO->query_caster(), "elusive spellcraft")) {
        roll += 4;
    }

    if (mycast->query_property("dispelling_buffer") > 0) {
        roll += mycast->query_property("dispelling_buffer");
    }

    if (roll + level_diff < 0) {
        return 1;
    } else {
        return 0;
    }
}
