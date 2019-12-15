#include <std.h>
#include <daemons.h>
#include <magic.h>
inherit FEAT;

object *cur_players;
string mytype, myname;
int mod, duration;
void check();
void do_rally();

void create() {
    ::create();
    feat_type("instant");
    feat_category("Performance");
    feat_name("rally");
    feat_syntax("rally [melee|spells|defenses]");
    feat_prereq("Bard");
    feat_desc("This feat allows the bard to inspire their allies, improving their abilities in the area of choice - whether that be melee, casting or defensive prowess. The ability will last longer, and grow stronger, as the bard gains levels. Those affected by spells inducing a rage or berserker state will gain no benefit from rally.

<rally melee>

    Will increase chance to hit and damage

<rally spells>

    Will increase spell penetration and power

<rally defenses>

    Will improve all saving throws and increase armour class
");
    set_required_for(({"anger","calm","charm"}));
    set_target_required(0);
    allow_blind(1);
}

int allow_shifted() { return 1; }

int prerequisites(object ob){
    if(!objectp(ob)) return 0;
    if(!ob->is_class("bard")) {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

int cmd_rally(string str){
    object feat;
    if(!objectp(TP)) { return 0; }
    //if(!stringp(str)) { return 0; }
    feat = new(base_name(TO));
    feat->setup_feat(TP,str);
    return 1;
}

void execute_feat(){
    object *inven, *partied;
    int i;
    if((int)caster->query_property("using rally")) {
        tell_object(caster,"You can't try to rally your allies again yet!");
        dest_effect();
        return;
    }
    ::execute_feat();
    if((int)caster->query_property("using instant feat")) {
        tell_object(caster,"You are already in the middle of using a feat!");
        dest_effect();
        return;
    }
    if(arg != "melee" && arg != "spells" && arg != "defenses") {
        tell_object(caster,"You need to rally melee, spells or defenses!");
        dest_effect();
        return;
    }
    inven = ({});
    cur_players = ({});
    partied = PARTY_D->query_party_members(caster->query_party());
    if(!sizeof(partied)) partied = ({ caster });

    if(sizeof(all_living(ETP))) { inven += all_living(ETP); }
    for(i = 0;i<sizeof(inven);i++) {
        if(userp(inven[i]) && (member_array(inven[i],partied) != -1) && !inven[i]->query_true_invis())
          cur_players += ({inven[i]});
    }
    tell_object(caster,"%^BOLD%^%^WHITE%^You start rallying your comrades to fight better.");
    tell_room(place,""+caster->QCN+" starts to raise the spirits of "+caster->QP+" companions.",caster);
    mytype = arg;
    caster->set_property("using instant feat",1);
    caster->remove_property("using rally");
    call_out("do_rally",ROUND_LENGTH);
    return;
}

void do_rally(){
    int i;
    object *inv;
    if(!objectp(caster)) {
        dest_effect();
        return;
    }
    caster->remove_property("using instant feat");
    ::execute_attack();
    inv = ({});
    place = environment(caster);
    mod = (clevel +9)/10;
    duration = 150 + ((int)caster->query_guild_level("bard")*10);
    for(i=0;i<sizeof(cur_players);i++) {
        if(!objectp(cur_players[i])) continue;
        if(!present(cur_players[i],place)) continue;
        if(cur_players[i]->query_property("raged")) {
          tell_object(cur_players[i],"%^BOLD%^%^RED%^You are already in a frenzy and feel no different!");
          continue;
        }
   	  if(pointerp(cur_players[i]->query_property("rally")) && member_array(mytype,cur_players[i]->query_property("rally")) != -1) continue;
        inv += ({ cur_players[i] });
    }
    cur_players = inv;
    myname = (string)caster->query_name();

    for(i=0;i<sizeof(cur_players);i++){
      switch(mytype) {
        case "spells":
          cur_players[i]->set_property("spell penetration",(mod*5));
          cur_players[i]->set_property("empowered",mod);
        break;
        case "defenses":
          cur_players[i]->add_ac_bonus(mod);
          cur_players[i]->add_saving_bonus("all",mod);
        break;
        default:
          cur_players[i]->add_attack_bonus(mod);
          cur_players[i]->add_damage_bonus(mod);
        break;
      }
      cur_players[i]->set_property("rally",({ mytype }));
      tell_object(cur_players[i],"%^YELLOW%^You feel invigorated and ready for battle!%^RESET%^");
    }
    tell_object(caster,"%^BOLD%^%^WHITE%^You finish inspiring your comrades.%^RESET%^");
    caster->set_property("using rally", 1);
    call_out("check",ROUND_LENGTH);
    call_out("dest_effect",duration);
    caster->set_property("active_feats", ({TO}));
    return;
}

void check(){
    if(!objectp(caster)){
        dest_effect();
        return;
    }
    call_out("check",ROUND_LENGTH);
}

void dest_effect(){
    int i;
    string *holding;
    ::dest_effect();
    mod = -mod;
    if(objectp(caster)) caster->remove_property("using rally");
    if(!sizeof(cur_players))
    {
      remove_feat(TO);
      return;
    }
    for(i=0;i<sizeof(cur_players);i++){
      if(!objectp(cur_players[i])) continue;
      tell_object(cur_players[i],"%^BOLD%^%^CYAN%^You feel the effects of the bard's song wear off.%^RESET%^");
      switch(mytype) {
        case "spells":
          cur_players[i]->set_property("spell penetration",(mod*5));
          cur_players[i]->set_property("empowered",mod);
        break;
        case "defenses":
          cur_players[i]->add_ac_bonus(mod);
          cur_players[i]->add_saving_bonus("all",mod);
        break;
      default:
          cur_players[i]->add_attack_bonus(mod);
          cur_players[i]->add_damage_bonus(mod);
        break;
      }
      holding = cur_players[i]->query_property("rally");
      if(sizeof(holding)) {
        if(member_array(mytype,holding) != -1) holding -= ({ mytype });
      }
      cur_players[i]->remove_property("rally");
      if(sizeof(holding)) cur_players[i]->set_property("rally",holding);
    }
    remove_feat(TO);
    return;
}
