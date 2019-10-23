//based on Smite, for psywarriors ~Circe~ 9/22/15
//This is the greater version, doing more damage with a reverb the next round for half damage.

#include <std.h>
#include <daemons.h>
#include <magic.h>
inherit FEAT;

object *targets;
void smack_em(object ob);

#define FEATTIMER 35

void create() {
    ::create();
    feat_type("instant");
    feat_category("Psionics");
    feat_name("greaterpsionicweapon");
    feat_syntax("greaterpsionicweapon");
    feat_prereq("Psionicweapon, Psywarrior L15, or Psion L15");
    feat_desc("As the psionic character is attacked, psychic energy builds to a low growl within his mind. Through this feat, the psionic individual releases pure mental energy, sending forth a tempest that ransacks the minds of those who dare attack him and leaves the least intelligent struggling to recover. The greater version lingers in the victim's mind, unleashing a second attack.");
    psionic(1);
}

int allow_shifted() { return 0; }

int prerequisites(object ob){
    if(!objectp(ob)) return 0;
    if(ob->query_class_level("psywarrior") < 15 && ob->query_class_level("psion") < 15){
        dest_effect();
        return 0;
    }
    if(!FEATS_D->has_feat(ob,"psionicweapon")){
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

int cmd_greaterpsionicweapon(string str) {
    object feat;
    if(!objectp(TP)) return 0;
    feat = new(base_name(TO));
    feat->setup_feat(TP,"");
    return 1;
}

void execute_feat() {
    mapping tempmap;
    int delay;
    ::execute_feat();
    if((int)caster->query_property("using smite") > time()) { //keeping the same variable to avoid stacking
        tell_object(caster,"You are not prepared to exert such mental force again so soon!");
        dest_effect();
        return;
    }
    if((int)caster->query_property("using instant feat")) {
        tell_object(caster,"You are already in the middle of using a feat!");
        dest_effect();
        return;
    }
    if(!sizeof(caster->query_attackers())) {
        tell_object(caster,"You're not under attack!");
        dest_effect();
        return;
    }

    tell_object(caster,"%^RESET%^%^BOLD%^You focus your mind, preparing to unleash a psionic attack.");

    delay = time() + FEATTIMER;
    delay_messid_msg(FEATTIMER,"%^BOLD%^%^WHITE%^You can %^CYAN%^greaterpsionicweapon%^WHITE%^ again.%^RESET%^");
    caster->set_property("using instant feat",1);
    caster->remove_property("using smite");
    caster->set_property("using smite",delay);
    return;
}

void execute_attack() {
    int chamod, i, dmg, myint, yourint, extra;

    if(!objectp(caster)) {
        dest_effect();
        return;
    }
    caster->remove_property("using instant feat");
    ::execute_attack();

    if(caster->query_unconscious()) {
        dest_effect();
        return;
    }

    if(FEATS_D->usable_feat(caster,"mind wave")) { extra = 4; } // might need tweaking, will have to watch

    chamod = ((int)caster->query_stats("intelligence") - 10)/2;
    chamod = chamod -1 + extra;
    targets = caster->query_attackers();
    if(!sizeof(targets)) {
        tell_object(caster,"You are not under attack, and your mental force dissipates harmlessly!");
        dest_effect();
        return;
    }
    caster->set_property("magic",1);
    targets += ({ caster });
    tell_object(caster,"%^RESET%^%^MAGENTA%^The power within you grows to a "
       "fever pitch, and you release a psionic tempest that slices through your enemies!");
    tell_room(place,"%^RESET%^%^MAGENTA%^A low hum resonates throughout the area before "
       ""+caster->QCN+" unleashes a psionic tempest that slices through "+caster->QP+" enemies!",targets);
    targets -= ({ caster });
    for(i=0;i<sizeof(targets);i++) {
        if(targets[i] == caster) continue;
        if(!objectp(targets[i])) continue;
   	  tell_object(targets[i],"%^BOLD%^%^MAGENTA%^"+caster->QCN+" releashes a psionic "
           "tempest that slices through your mind like countless blades!%^RESET%^");
        dmg = roll_dice(clevel,chamod);
        dmg += clevel; //dmg wasn't that impressive on rolldice randomness; adding some static reliable dmg base. -N, 9/10
        caster->cause_damage_to(targets[i],"head",dmg);
        caster->add_attacker(targets[i]);
        targets[i]->add_attacker(caster);
        myint = caster->query_stats("intelligence");
        yourint = targets[i]->query_stats("intelligence");
        if((myint + random(6)) > (yourint + random(6))) //intelligence comparison, giving a slight random chance (plus or minus up to 5)
          targets[i]->set_paralyzed((random(chamod)+(clevel/5)+5),"%^BOLD%^%^CYAN%^The "
             "psionic assault leaves you babbling incoherently!%^RESET%^");
        call_out("smack_em",ROUND_LENGTH,targets[i]);
    }
    caster->set_property("magic",-1);
    return;
}

void smack_em(object ob){
    int chamod, i, dmg, extra;
    if(!objectp(caster)) {
        dest_effect();
        return;
    }
//    ::execute_attack();
    if(FEATS_D->usable_feat(caster,"mind wave")) { extra = 4; } // might need tweaking, will have to watch
    chamod = ((int)caster->query_stats("intelligence") - 10)/2;
    chamod = chamod -1 + extra;
    caster->set_property("magic",1);
    tell_object(ob,"%^BOLD%^%^CYAN%^The psychic energy unleashed "
       "by "+caster->QCN+" ravages your mind once more!%^RESET%^");
    dmg = roll_dice(clevel,chamod);
    dmg += clevel;
    dmg = dmg/2;
    caster->cause_damage_to(ob,"head",dmg);
    caster->set_property("magic",-1);
    dest_effect();
    return;
}

void dest_effect(){
    ::dest_effect();
    remove_feat(TO);
    return;
}
