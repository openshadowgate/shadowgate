#include <std.h>
#include <daemons.h>
inherit "/std/fence";

string *killers;
int powdertrack, flag, flag2;

void create() {
    object ob;
    ::create();
    killers = ({});
    set_id(({"feyd","Feyd","half-elf"}));
    set_name("feyd");
    set_short("%^BOLD%^%^BLACK%^Feyd Rautha%^RESET%^%^ORANGE%^, %^CYAN%^the "
"%^ORANGE%^D%^BOLD%^e%^RESET%^%^ORANGE%^s%^BOLD%^e%^RESET%^%^ORANGE%^r%^BOLD%^t "
"%^RESET%^%^CYAN%^Wind%^RESET%^");
    set_long("%^BOLD%^%^BLUE%^Feyd stands before you, smiling wryly, as always. His bold, %^GREEN%^ma%^RESET%^"
"%^GREEN%^la%^BOLD%^%^BLACK%^c%^RESET%^%^GREEN%^hi%^BOLD%^te green eyes %^BLUE%^are a stark contrast against "
"the dark features of his %^RESET%^%^ORANGE%^ever-sunbathed skin. Straight, %^RESET%^lust%^BOLD%^%^BLACK%^ro"
"%^WHITE%^us%^BLUE%^, %^BLACK%^raven black hair %^BLUE%^flows freely about his nape, down to his capacious "
"shoulders, cut in a layered fashion, but appear to be fighting against having been trained to be pulled back"
". Sinewy, and corded with muscle, with no trace of water-fat, his lithe frame seems to have been built for "
"speed and endurance. The more angular features of his face and ears clearly mark his mixed racial heritage. A "
"graced man, he is immaculately kept, clean shaven, and smells faintly of jasmine. A disparate assortment of "
"clothing adorns his body. He keeps his body, legs, and arms wrapped in a thin, breathable looking %^BLACK%^"
"black cloth material%^BLUE%^, almost in fashion with that of a mummy. Over this are robes of %^RESET%^"
"%^ORANGE%^sa%^BOLD%^nd%^RESET%^%^ORANGE%^y b%^BOLD%^ro%^RESET%^%^ORANGE%^wn%^BOLD%^%^BLUE%^, and accentuating "
"it all are various shades of %^RESET%^gray%^BOLD%^%^BLUE%^, strips of %^WHITE%^white %^BLUE%^here and there, "
"and a %^BLACK%^dark kerchief%^BLUE%^, or mask, hanging about his neck. It appears this man, for all intents, "
"is agile and aware.%^RESET%^");
    set_race("half-elf");
    set_body_type("human");
    set_gender("male");
    set_alignment(6);
    set_diety("mask");
    set_class("thief");
    set_hd(37,6);
    set_guild_level("thief",45); //bumped him up to level 45 so he can wield his second dagger - Lujke
    set_mlevel("thief",45);      // July 2019
    add_search_path("/cmds/thief");
    set_max_hp(2000);
    set_hp(2000);
    set_exp(28000);
    set_overall_ac(-4);
    set_stats("dexterity",18);
    set_stats("strength",18);
    set_stats("constitution",16);
    set_stats("intelligence",13);
    set_stats("wisdom",15);
    set_stats("charisma",16);
    set_stats("exceptional_strength",-1);
    set_property("full attacks",1);
        set_skill("stealth",45);
    set_skill("athletics",45);
    add_attack_bonus(8);
        add_damage_bonus(8);
    set_wielding_limbs(({"left hand","right hand"}));
    command("message in sweeps in silently.");
    command("message out melts $D like sand upon the wind.");
    command("speech drawl in a thick desert accent");
    set_emotes(1, ({"Feyd pops some cardamom seeds in his mouth and chews thoughtfully.",
"Feyd stretches, rolling his shoulders, and pops his knuckles.",
"Feyd offers a lady passing by a radiant smile.",
"%^RESET%^%^MAGENTA%^Feyd drawls in a thick desert accent%^RESET%^: %^YELLOW%^\"%^RESET%^%^ORANGE%^Something "
"you're looking to sell? Trade? Surely there's some bargain we might strike.%^YELLOW%^\"%^RESET%^",
"%^RESET%^%^MAGENTA%^Feyd drawls in a thick desert accent%^RESET%^: %^YELLOW%^\"%^RESET%^%^ORANGE%^G'day, "
"traveller. Heard any interesting news?%^YELLOW%^\"%^RESET%^",
"%^RESET%^%^MAGENTA%^Feyd drawls in a thick desert accent%^RESET%^: %^YELLOW%^\"%^RESET%^%^ORANGE%^Being the "
"simple merchant that I am, it never hurts to know the happenings of the lands.%^YELLOW%^\"%^RESET%^",
"%^RESET%^%^MAGENTA%^Feyd drawls in a thick desert accent%^RESET%^: %^YELLOW%^\"%^RESET%^%^ORANGE%^I have "
"heard of late that some people are having trouble with certain...undesirables. 'Tis a pity the authorities "
"can't offer more protection. Might you have any problems of the sort?%^YELLOW%^\"%^RESET%^", }), 0);
    add_money("gold", random(100)+400);
    add_money("platinum", random(30)+200);
    add_money("electrum", random(100)+500);
    ob = new("/d/laerad/parnelli/cguild/assassin/rings/aring");
    ob->move(TO);
    ob->set_property("monsterweapon",1);
    command("wear ring");
    ob = new("/d/islands/pirates/armor/demonskin");
    ob->move(TO);
    ob->set_property("monsterweapon",1);
    ob->remove_property("enchantment");
//removing the enchantment so he can wear it with the robes
//~Circe~ 4/27/13
    command("wear demonskin");
    ob = new("/d/antioch/ruins/obj/demon_boots");
    ob->move(TO);
    ob->set_property("monsterweapon",1);
    command("wear boots");
    ob = new("/d/retired/obj/feydmask");
    ob->move(TO);
    ob->set_property("monsterweapon",1);
    command("wear mask");
    ob = new("/d/barriermnts/lothwaite/obj/impcloak");
    ob->move(TO);
    ob->set_property("monsterweapon",1);
    command("wear cloak");
    ob = new("/d/retired/obj/feydrobes");
    ob->move(TO);
    command("wear robe");
    ob = new("/d/attaya/obj/screamer");
    ob->move(TO);
    ob->set_property("monsterweapon",1);
    command("wield dagger");
    ob = new("/d/islands/dallyh/marsh/obj/barbed");
    ob->move(TO);
    ob->set_property("monsterweapon",1);
    command("wield dagger");
    set_funcs(({"my_attack"}));
    set_func_chance(100);
    set_property("add kits",50);
    set_property("no steal",1);
    set_scrambling(999);
    set("is_assassin",1);
    add_search_path("/cmds/assassin");
    powdertrack = 0;
    flag = 0;
    flag2 = 0;
    remove_random_act_dbs( ({ "/d/db/armorsrandom" }) );
    remove_std_db();
    set_storage_room("/d/retired/obj/feyd_storage");
        set_monster_feats(({
            "dodge",
                "mobility",
                "evasion",
                "scramble",
                "spring attack",
                "toughness",
                "improved toughness",
                "damage resistance",
                "improved damage resistance",
                "regeneration"
    }));
}

void my_attack(object targ) {
    object myob;
    if(!objectp(TO) || !objectp(targ)) return;
    if(!present(targ->query_name(),ETO)) return;
    if(!powdertrack) {
      myob = new("/d/tharis/obj/bpowder");
      myob->move(TO);
      force_me("toss powder at "+targ->query_name());
      myob->remove();
      powdertrack = 1;
      return;
    }
    switch(random(200)) {
      case 0..99:
      tell_room(ETO,"%^BOLD%^%^BLACK%^Feyd sidesteps suddenly and spins around "
"behind "+targ->QCN+". Flipping both daggers overhand, he stabs them straight "
"down into "+targ->QP+" exposed back!%^RESET%^",targ);
      tell_object(targ,"%^BOLD%^%^BLACK%^Feyd sidesteps suddenly and spins around "
"behind you.  For a second he is out of your sight, and instantly your back is a "
"searing blaze of pain!%^RESET%^");
      targ->do_damage(targ->return_target_limb(),roll_dice(15,10));
      break;
      case 100..199:
      flag2 = 1;
      TO->cease_all_attacks();
      if(!targ->query_property("gutted"))
        TO->force_me("crit "+targ->query_name());
      else
        TO->force_me("stab "+targ->query_name());
      TO->force_me("kill "+targ->query_name());
      call_out("rem_flag",10);
      break;
    }
}

void heart_beat() {
    ::heart_beat();
    if(!TO->query_scrambling()) TO->set_scrambling(999);
    if(flag && !sizeof(TO->query_attackers())) flag = 0;
    return;
}

int kill_ob(object victim, int which){
    killers = SAVE_D->query_array("DDguild_killers");
    if(member_array((string)victim->query_name(), killers) == -1) {
      SAVE_D->set_value("DDguild_killers", (string)victim->query_name());
      ETO->remove_member((string)victim->query_name());
    }
    if(!flag && !flag2 && !sizeof(TO->query_attackers())) {
      command("speech intimate with reticent menace");
      TO->force_me("say %^RESET%^%^BLUE%^\"%^BOLD%^Soon, shall you realize the depth of your
folly!%^RESET%^%^BLUE%^\"%^RESET%^");
      flag = 1;
      TO->force_me("stab "+victim->query_name());
      TO->force_me("kill "+victim->query_name());
      command("speech drawl in a thick desert accent");
    }
    return ::kill_ob(victim, which);
}
