#include <std.h>
#include <daemons.h>
inherit FEAT;

int hits;
void display_messages(object targ,object player);

void create() {
    ::create();
    feat_type("instant");
    feat_category("RangedCombat");
    feat_name("manyshot");
    feat_syntax("manyshot");
    feat_prereq("Point blank shot");
    feat_desc("Manyshot can be used in combat to fire a number of projectiles at each target within the immediate vicinity, and will quickly eat through ammunition. It will fail if there is not at least one target within range, and will use a small amount of stamina.");
    set_target_required(0);
    set_required_for(({"deadeye","preciseshot","shot on the run"}));
}

int allow_shifted() { return 0; }

int prerequisites(object ob){
    if(!objectp(ob)) { return 0; }
    if(!FEATS_D->has_feat(ob,"point blank shot")) {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

int cmd_manyshot(string str) {
    object feat;
    if(!objectp(TP)) { return 0; }
    feat = new(base_name(TO));
    feat->setup_feat(TP,str);
    return 1;
}

void execute_feat(){
    int ammoleft, i;
    object *weapons, ammo;
       
    if((int)caster->query_property("using manyshot") > time()) {
        tell_object(caster,"You can't try to fire so many arrows again so soon!");
        dest_effect();
        return;
    }
    if (caster->query_bound() || caster->query_tripped() || caster->query_paralyzed()) {
        caster->send_paralyzed_message("info",TP);
        dest_effect();
        return;
    }
    ::execute_feat();
    if(!objectp(caster)) { 
        dest_effect();
        return;
    }
    if((int)caster->query_property("using instant feat")) {
        tell_object(caster,"You are already in the middle of using a feat!");
        dest_effect();
        return;
    }
    if(!hits = sizeof(caster->query_attackers())){
      tell_object(caster,"%^YELLOW%^You're not fighting anyone!\n");
      dest_effect();
      return;
    }
    weapons = caster->query_wielded();
    if(!sizeof(weapons)) {
      tell_object(caster,"%^YELLOW%^You can't use this feat unless you are wielding a ranged weapon!\n");
      dest_effect();
      return;
    }
    if(!weapons[0]->is_lrweapon()) {
      tell_object(caster,"%^YELLOW%^You can't use this feat unless you are wielding a ranged weapon!\n");
      dest_effect();
      return;
    }
    if(sizeof(weapons) > 1 && weapons[0] != weapons[1]) {
      tell_object(caster,"%^YELLOW%^You can't dualwield ranged weapons!\n");
      dest_effect();
      return;
    }
    if(!ammo = present(weapons[0]->query_ammo(),caster)) {
      tell_object(caster,"%^YELLOW%^You don't have any ammunition for that weapon!\n");
      dest_effect();
      return;
    }
    if(!ammoleft = (int)ammo->query_shots()) {
      tell_object(caster,"%^YELLOW%^You're out of ammunition for that weapon!\n");
      dest_effect();
      return;
    }
    if((ammoleft > 0) && (hits > ammoleft)) hits = ammoleft; // if they don't have enough arrows to hit all targets, only as many hits as arrows left.
    for(i=0;i<hits;i++) ammo->use_shots(); // burn off an arrow for each hit they're about to attempt.
    
    tell_object(caster,"%^BOLD%^You grasp for a handful of arrows, ready to unleash a rapid barrage!\n%^RESET%^");
    tell_room(environment(caster),"%^MAGENTA%^"+caster->QCN+" grasps a handful of arrows and begins unleashing them in a rapid barrage!\n%^RESET%^",caster);
    caster->use_stamina(roll_dice(1,6));
    caster->set_property("using instant feat",1);
    spell_kill(target,caster);
    return;
}

void execute_attack(){
    object *weapons,*attackers;
    int i,dam,num,enchant,hit;

    if(!objectp(caster)) {
        dest_effect();
        return;
    }
    caster->remove_property("using instant feat");
    ::execute_attack();
    if (caster->query_bound() || caster->query_tripped() || caster->query_paralyzed()) {
        caster->send_paralyzed_message("info",TP);
        dest_effect();
        return;
    }

    attackers = (object *)caster->query_attackers();
    weapons = caster->query_wielded();
    if(!sizeof(attackers)){
      tell_object(caster,"%^YELLOW%^You're not fighting anyone!\n");
      dest_effect();
      return;
    }
    if(!sizeof(weapons)) {
      tell_object(caster,"%^YELLOW%^You can't use this feat unless you are wielding a ranged weapon!\n");
      dest_effect();
      return;
    }
    if(!weapons[0]->is_lrweapon()) {
      tell_object(caster,"%^YELLOW%^You can't use this feat unless you are wielding a ranged weapon!\n");
      dest_effect();
      return;
    }
    if(sizeof(weapons) > 1 && weapons[0] != weapons[1]) {
      tell_object(caster,"%^YELLOW%^You can't dualwield ranged weapons!\n");
      dest_effect();
      return;
    }

    caster->remove_property("using manyshot");
    caster->set_property("using manyshot", time() + 35 );

    if(hits > sizeof(attackers)) hits = sizeof(attackers); // if some targets have since died, don't bother hitting them.
    for(i=0;i<sizeof(attackers);i++) {
        if(!objectp(attackers[i])) continue;
        enchant = weapons[0]->query_property("enchantment");
        dam = weapons[0]->query_damage();
        dam += weapons[0]->query_property("enchantment");
        dam += caster->query_damage_bonus();

        dam += roll_dice((int)caster->query_level(),5)+roll_dice(2,8); // this is copied per whirl; please modify if changed.

        if(!present(attackers[i],environment(caster))) { 
            tell_object(caster,"%^RED%^That target is no longer in range!%^RESET%^"); 
            continue; 
        }
        if(!thaco(attackers[i]))
        {
        //if((int)caster->Thaco(0,attackers[i],weapons[0]) >= roll_dice(1,20)) {
            tell_object(attackers[i],"%^CYAN%^"+caster->QCN+" sends a barrage of attacks your way, but you dodge quickly out of the way!%^RESET%^");
            continue;
        }
        if(attackers[i]->query_property("weapon resistance")) { 
            if(enchant < attackers[i]->query_property("weapon resistance")) {
                tell_object(attackers[i],"%^BOLD%^"+caster->QCN+" hits you with an ineffective barrage of attacks.%^RESET%^");
                continue;
            }
        }
        display_messages(attackers[i],caster);
        caster->cause_damage_to(attackers[i], attackers[i]->return_target_limb(), dam);
        hit = 1;
    }
    if(!hit) {
	  tell_object(caster,"%^BOLD%^You fumble with your bow and fail to hit a single target!");
	  tell_room(environment(caster),"%^BOLD%^"+caster->QCN+" fumbles with "+caster->QP+" bow and fails to hit a single target!",caster);
	  caster->set_paralyzed(roll_dice(1,6),"%^BOLD%^You are trying to grip your weapon!");
    }
    else {
        switch(random(5)) {
          case 0:
          tell_object(caster,"%^BOLD%^%^CYAN%^You unleash a flurry of arrows upon your foes!");
          tell_room(environment(caster),"%^BOLD%^%^CYAN%^"+caster->QCN+" unleashes a flurry of arrows on "+caster->QP+" foes!",({target,caster}));
        break;
          case 1:
          tell_object(caster,"%^BOLD%^%^YELLOW%^You drop to one knee and loose a barrage of arrows!");
          tell_room(environment(caster),"%^BOLD%^%^YELLOW%^"+caster->QCN+" drops to one knee and looses a barrage of arrows!",({target,caster}));
        break;
          case 2:
          tell_object(caster,"%^RESET%^%^GREEN%^You centre your focus and time seems to slow, as you fire again and again at each opponent!");
          tell_room(environment(caster),"%^RESET%^%^GREEN%^"+caster->QCN+" seems to pick up speed, firing again and again at "+caster->QP+" opponents!",({target,caster}));
        break;
          case 3:
          tell_object(caster,"%^BOLD%^%^MAGENTA%^A hail of arrows is loosed from your bow, striking target after target!");
          tell_room(environment(caster),"%^BOLD%^%^MAGENTA%^A hail of arrows is loosed from "+caster->QCN+"'s bow, striking target after target!",({target,caster}));
        break;
          case 4:
          tell_object(caster,"%^RESET%^%^RED%^You move faster than the eye can follow, firing a volley of projectiles that hit their marks with deadly accuracy!");
          tell_room(environment(caster),"%^RESET%^%^BLUE%^"+caster->QCN+" moves faster than the eye can follow, firing a volley of projectiles that hit their marks with deadly accuracy!",({target,caster}));
        break;
          default:
        break;
        }
    }
    dest_effect();
}

void dest_effect() {
    ::dest_effect();
    remove_feat(TO);
    return;
}

void display_messages(object targ,object player) {
    if(!objectp(targ)) return;
    if(!objectp(player)) return;
   
    switch(random(5)) {
    case 0:
        tell_object(targ,"%^BOLD%^%^GREEN%^"+player->QCN+" unleashes a volley of arrows at you!");
        break;
     
    case 1:
        tell_object(targ,"%^BOLD%^%^BLUE%^"+player->QCN+" drops to one knee and launches a rapid series of shots at you!");
        break;
     
    case 2:
        tell_object(targ,"%^RESET%^%^GREEN%^"+player->QCN+"'s bowstring hums as "+player->QS+" fires shot after shot at you!");
        break;
     
    case 3:
        tell_object(targ,"%^BOLD%^%^MAGENTA%^"+player->QCN+" becomes a blur of movement, another arrow nocked even as the first leaves "+player->QP+" bowstring!");
        break;
     
    case 4:
        tell_object(targ,"%^RESET%^%^BLUE%^"+player->QCN+" moves faster than you can follow, firing a hail of shots your way!");
        break;
    default:
        break;
    }
}
