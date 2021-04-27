//Added kits to increase average fight length Octothorpe 5/25/09
#include <std.h>
#define VHAND "/d/dagger/marsh/tower/obj/hand.c"

inherit MONSTER;
string *handsp;
int Gbl;

void create() {
    object ob;
    ::create();
    handsp = ({"caress", "healing", "web", "bolt", "flame"});
    set_name("vecna");
    set_id( ({"lich","arch lich","arch lich vecna", "vecna"}) );
    set_short("%^BOLD%^%^BLACK%^Vecna, Arch Lich of Deepingdale%^RESET%^");
    set_long("The apparation that stands before you is a humanoid creature that appears to be undead. "
"Its snarling lips show a jagged row of bony teeth. Its single eye blazes with a black hatred that stares "
"deep into your soul. Judging by its incredibly evil appearance and surroundings, this can only be Vecna.");
    set_race("undead");
    set_alignment(9);
    set_hd(30,6);
    set_class("fighter");
    set_mlevel("fighter",30);
    set_class("mage");
    set_mlevel("mage",30);
    set_guild_level("mage",30);
    set_gender("male");
    set("aggressive",200);
    add_money("gold",random(15000)+5000);
    set_stats("strength", 25);
    set_stats("constitution", 25);
    set_stats("dexterity", 14);
    set_stats("wisdom", 25);
    set_stats("intelligence", 25);
    set_stats("charisma", 25);
    set_body_type("humanoid");
    set_max_hp(5000);
    set_hp(query_max_hp());
    set_size(2);
//   new("/d/dagger/marsh/tower/obj/speedboots.c")->move(TO);
//   new("/d/laerad/obj/bracers8.c")->move(TO);
    ob = new(VHAND);
    ob->move(TO);
    ob->set_property("monsterweapon",1);
    TO->force_me("attach hand");
    force_me("wearall");
    set_property("knock unconscious",1);
    set_funcs( ({"special", "special", "use_hand", "cast_spells"}) );
    set_func_chance(100);
    set_exp(5000);
    set_max_level(36);
    set_property("full attacks", 1);
    set_property("weapon resistance", 1);
    set_property("no steal", 1);
    set_property("no paralyze", 1);
    set_property("no tripped",1);
    set_property("magic", 1);
    set_property("no death", 1);
    set_property("no hold", 1);
    set_property("no bows", 1);
    set_mob_magic_resistance("average");
    set_emotes(10, ({
      "%^MAGENTA%^Vecna yells out: %^BOLD%^%^RED%^CARESS%^RESET%^ while pointing a mummified finger at you!",
      "%^MAGENTA%^Vecna yells out: %^BOLD%^%^RED%^HEALING%^RESET%^ while pointing a mummified finger at you!",
      "%^MAGENTA%^Vecna yells out: %^BOLD%^%^RED%^BOLT%^RESET%^ while pointing a mummified finger at you!",
      "%^MAGENTA%^Vecna yells out: %^BOLD%^%^RED%^FLAME%^RESET%^ while pointing a mummified finger at you!",
      "%^MAGENTA%^Vecna yells out: %^BOLD%^%^RED%^WEB%^RESET%^ while pointing a mummified finger at you!",
      "%^BOLD%^%^RED%^Vecna rubs a great bloody hand across your chest, causing you to scream in pain!",
      "%^BLUE%^%^BOLD%^Vecna spits a moldy tooth at you.",
      "%^BOLD%^%^BLACK%^Your heart is crushed by the deepest of despair!",
    }), 1);

//    new("/d/avatars/ares/orb_of_scrying.c")->move(TO);
    ob = new("/d/common/obj/brewing/herb_special_inherit");
    ob->set_herb_name("lich dust");
    ob->move(TO);
}

void init(){
    ::init();
   if(!query_property("blinking")) {
   new("/cmds/spells/b/_blink.c")->use_spell(TO,TO,30,100,"mage");
   }
      if(!query_property("Gflagprop")) {
   new("/cmds/spells/s/_stoneskin")->use_spell(TO, TO->query_name(),30,100,"mage");
      Gbl = 40;
      set_property("Gflagprop", 1);
    }
    if(!wizardp(TP)&&!TP->query_true_invis()){
      kill_ob(TP, 1);
    }
}

void special(object targ){
    int dam;

    TO->force_me( "say Now I shall bring about your enslavement!");
    TO->force_me( "say Once I am finished with you, all shall perish!");
    TO->force_me("watch");
    tell_object(targ, "%^BOLD%^%^BLUE%^Vecna drains the life force of your soul!%^RESET%^");
    tell_room(ETO, "%^BOLD%^%^BLUE%^Vecna drains the life force of "+targ->query_cap_name()+"'s soul!%^RESET%^", targ);
    dam = roll_dice(20,10) + 30;
    targ->do_damage("torso",dam);
    targ->set_paralyzed(random(20)+10,"%^MAGENTA%^You are stunned by the blow and unable to move!%^RESET%^");
    TO->force_me("cackle "+targ->query_name());
    return 1;
}

void use_hand(object targ){
    string str;

    if(sizeof(handsp)) {
      str = handsp[random(sizeof(handsp))];
    } else {
      str = "default";
    }
    if((TO->query_hp() < 500) && member_array("healing", handsp))
      str = "healing";

    switch(str){
      case "caress":
        force_me("caress "+targ->query_name());
        handsp -= ({"caress"});
        break;
      case "heal":
        force_me("healing vecna");
        handsp -= ({"healing"});
        break;
      case "bolt":
        force_me("bolt "+targ->query_name());
        handsp -= ({"bolt"});
        break;
      case "flame":
        force_me("flame "+targ->query_name());
        handsp -= ({"flame"});
        break;
      case "web":
        force_me("web "+targ->query_name());
        handsp -= ({"web"});
        break;
      default:
        tell_room(ETO, "%^BOLD%^Vecna glows as his wounds seem to recover of their own accord.");
        add_hp(random(100));
        break;
    }
}

void cast_spells(object targ){
    int X;
    X = 5;

    switch(random(X)){
      case 0:
   new("/cmds/spells/m/_magic_missile")->use_spell(TO,targ->query_name(),30,100,"mage");
        break;
      case 1:
   new("/cmds/spells/c/_chain_lightning")->use_spell(TO,targ->query_name(),30,100,"mage");
        break;
      case 2:
   new("/cmds/spells/l/_lightning_bolt")->use_spell(TO,targ->query_name(),30,100,"mage");
        break;
      case 3:
   new("/cmds/spells/s/_stoneskin")->use_spell(TO, TO->query_name(),30,100,"mage");
        break;
      case 4:
   new("/cmds/spells/f/_fireball")->use_spell(TO,targ->query_name(),30,100,"mage");
        break;
      case 5:
        tell_room(ETO, "%^BOLD%^Vecna starts to move around the room at an inhuman speed.");
        Gbl = 30;
        break;
      default:
        tell_room(ETO, "%^BOLD%^%^RED%^Vecna chants a small spell, causing his wounds to heal.");
   add_hp(random(400));
    }
}

void heart_beat() {
    ::heart_beat();
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(query_hp() < query_max_hp())
      add_hp(random(20));
    if(Gbl > 0)
      Gbl--;
}

void set_paralyzed(int time,string message){return;}

int query_blinking() { return Gbl; }

void die(object ob) {
   tell_room(ETO,"%^CYAN%^Vecna shrieks, an ear-splitting cry of agony as the last of his strength fades.");
   tell_room(ETO,"%^GREEN%^'I will not be banished! Not again!'");
   ::die(ob);
}