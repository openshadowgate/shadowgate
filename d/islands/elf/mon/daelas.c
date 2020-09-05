//elf vampire coded by hades 9/5/20
#include <std.h>
#include "../elf.h"
inherit MONSTER;

int FLAG = 0;

void create()
{
    object ob;
    ::create();
    set_name("Daelas");
    set_id(({ "elf", "undead", "vampire", "daelas" }));
    set_short("%^BOLD%^%^RED%^Daelas, Elven Betrayer%^RESET%^");
    set_long("Daelas stands before you.  He is a noble looking "+
    "gold elf with amber eyes and golden hair.  He was once"+
    " known as a great elven weapons master who mastered both"+
    " blade and magic but was killed by vampires and forced"+
    " to become an evil vampire thrall.");
    set_race("elf");
    set_alignment(3);
    set_hd(59, 1000);
    set_class("mage");
    set_mlevel("mage", 50);
    set_mlevel("theif", 50);
    set_guild_level("mage", 50);
    set_guild_level("theif", 50);
    set_gender("male");
    add_search_path("/cmds/wizard");
    set("aggressive", 20);
    add_money("gold", random(10000) + 50000);
    set_stats("strength", 12);
    set_stats("constitution", 15);
    set_stats("dexterity", 16);
    set_stats("wisdom", 19);
    set_stats("intelligence", 30);
    set_stats("charisma", 17);
    set_body_type("human");
    set_max_hp(6500);
    set_max_level(47);
    set_hp(query_max_hp());
    set_size(2);
    set_attacks_num(6);
    set_func_chance(40);
    set_funcs(({ "special1" }));
    set_spell_chance(60);
    set_spells(({
        "eyebite",
        "dispel magic",
        "vampiric touch",
        "necrophage",
        "powerword stun"
    }));

    set_property("water breather", 1);
    set_property("full attacks", 1);
    set_property("weapon resistance", 5);
    set_property("no steal", 1);
    set_property("no paralyze", 1);
    set_property("no death", 1);
    set_monster_feats(({
        "spell penetration", "greater spell penetration",
        "scramble", "evasion","combat reflexes",
        "dodge","mobility",
    }));
    set_mob_magic_resistance("high");
    set_emotes(5, ({
        "Daelas says: I can't be blamed...I had no choice. " ,
        "Daelas says: I died for my people only to be brought back and forced to obey.",
        "Daelas says: The master vampire...the things I was forced to do.",
        "Daelas says: I don't even know how many years have passed.  Hundreds?  Thousands?",
        "Daelas says: They made me kill the prince and princess.  I had to obey... ",
        "Daelas wavers, like he has some great burden he is carrying.",
        "Daelas says: The heart of water sealed us for centuries... was it move?",
    }), 0);
    set_property("function and attack",1);
    add_attack_bonus(20);
    add_damage_bonus(20);


    ob = new("/d/magic/scroll");
    switch (random(4)) {
    case 0:
        ob->set_spell(6);
        break;

    case 1:
        ob->set_spell(7);
        break;

    case 2:
        ob->set_spell(8);
        break;

    case 3:
        ob->set_spell(9);
        break;
    }
    new(OBJ"knife")->move(TO);
    force_me("wield knife");
}


void special1(object targ)
{
 if(!"/daemon/saving_throw_d.c"->reflex_save(targ,-40)){
 
        tell_object(targ,
                    "%^BOLD%^%^RED%^The elf vampire bites into your neck!");
        tell_room(ETO,
                  "%^BOLD%^%^RED%^Daelas bites into "+targ->QCN+"'s neck!", targ);
        targ->cause_typed_damage(targ,0,roll_dice(10,10+200),"negative energy");
        TO->add_hp(200);
 }
 tell_room(ETO,"%^BOLD%^%^RED%^Dealas lunges for "+targ->QCN+"'s neck but misses.",targ);
 tell_object(targ,"%^BOLD%^%^RED%^Daelas lunges for your neck but you dodge.");
    return ;
}

void heart_beat()
{
    ::heart_beat();
    if (!objectp(TO)) {
        return;
    }
    if ((TO->query_hp() < 1000) && (FLAG != 1)) {
        FLAG = 1;
        TO->force_me("say %^BOLD%^%^RED%^I HAVEN'T BEEN HERE FOR CENTURIES TO DIE LIKE THIS!");
        new("/cmds/spells/b/_blink")->use_spell(TO, TO, 50, 100, "mage");
        TO->add_hp(random(500) + 675);
    }
    if (!TO->query_property("has_elemental")  {
        new("/cmds/spells/g/_gate")->use_spell(TO, "summoning", 50, 100, "mage"); 
    }
    if(present("corpse",ETO))
    new("/cmds/spells/mage/c/_create_greater_undead")->use_spell(TO, TO, 50, 100, "mage");
    return;
}
