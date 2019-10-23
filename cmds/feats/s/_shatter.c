#include <std.h>
#include <daemons.h>
#include <magic.h>
inherit FEAT;

int fired;

#define FEATTIMER 35

void create() {
    ::create();
    feat_type("instant");
    feat_category("MeleeDamage");
    feat_name("shatter");
    feat_syntax("shatter TARGET");
    feat_prereq("powerattack");
    feat_desc("The character can attempt to shatter layers of  an opponent's magical defenses, including stoneskin and iron body.

%^BOLD%^See also:%^RESET%^ shatter *spells");
    set_target_required(1);
}

int allow_shifted() { return 1; }

int prerequisites(object ob){
    if(!objectp(ob)) return 0;
    if(!FEATS_D->has_feat(ob,"powerattack")) {
      dest_effect();
      return 0;
    }
    return ::prerequisites(ob);
}

int cmd_shatter(string str) {
    object feat;
    if(!objectp(TP)) return 0;
    if(!stringp(str)) return 0;
    feat = new(base_name(TO));
    feat->setup_feat(TP,str);
    return 1;
}

void execute_feat() {
    mapping tempmap;
    object ammo, *weapons;
    ::execute_feat();
    if(!objectp(target)) {
        dest_effect();
        return;
    }
    tempmap = caster->query_property("using shatter");
    if(mapp(tempmap)) {
        if(tempmap[target] > time()) {
          tell_object(caster,"That target is still wary of such an attack!");
          dest_effect();
          return;
        }
    }
    if((int)caster->query_property("using instant feat")) {
        tell_object(caster,"You are already in the middle of using a feat!");
        dest_effect();
        return;
    }
    if(!sizeof(caster->query_wielded()) && !caster->query_property("shapeshifted")) {
        tell_object(caster,"How can you shatter anyone's defenses without a weapon?");
        dest_effect();
        return;
    }
    weapons = caster->query_wielded();
    if(sizeof(weapons) && weapons[0]->is_lrweapon() && !caster->query_property("shapeshifted")) {
        ammo = present(weapons[0]->query_ammo(),caster);
        if(FEATS_D->usable_feat(caster,"point blank shot") && objectp(ammo) && ammo->use_shots()) fired = 1;
    }
    if(!caster->query_property("shapeshifted"))
    {
        if(fired) {
            tell_object(caster,"%^BOLD%^%^CYAN%^You aim a series of rapid shots at "+target->QCN+"!%^RESET%^");
            tell_object(target,"%^BOLD%^%^CYAN%^"+caster->QCN+" aims a series of rapid shots at you!");
            tell_room(place,"%^BOLD%^%^CYAN%^"+caster->QCN+" aims a series of rapid shots at "
                +target->QCN+"!%^RESET%^",({target,caster}));
        }
        else {
            tell_object(caster,"%^BOLD%^%^CYAN%^You lunge forward at "+target->QCN+" with your "
                "weapon at the ready!%^RESET%^");
            tell_object(target,"%^BOLD%^%^CYAN%^"+caster->QCN+" lunges forward at you with "
                +caster->QP+" weapon at the ready!");
            tell_room(place,"%^BOLD%^%^CYAN%^"+caster->QCN+" lunges forward at "+target->QCN+
                " with "+caster->QP+" weapon at the ready!%^RESET%^",({target,caster}));
        }
    }
    else
    {
        tell_object(caster,"%^BOLD%^%^CYAN%^You snarl and lunge forward at "+target->QCN+" with "
            "your teeth bared!%^RESET%^");
        tell_object(target,"%^BOLD%^%^CYAN%^"+caster->QCN+" snarls and lunges forward at you with "
            +caster->QP+" teeth bared!");
        tell_room(place,"%^BOLD%^%^CYAN%^"+caster->QCN+" snarls and lunges forward at "+target->QCN+
            " with "+caster->QP+" teeth bared!%^RESET%^",({target,caster}));
    }
    caster->use_stamina(roll_dice(1,6));
    caster->set_property("using instant feat",1);
    spell_kill(target,caster);
    return;
}

void execute_attack() {
    int skinned, mod, i, timerz;
    object *keyz, myspl;
    mapping tempmap, newmap;

    if(!objectp(caster)) {
        dest_effect();
        return;
    }
    caster->remove_property("using instant feat");
    ::execute_attack();
    if(!objectp(target) || !present(target,place)) {
        tell_object(caster,"Your target is no longer here!");
        dest_effect();
        return;
    }
    if(!sizeof(caster->query_wielded()) && !caster->query_property("shapeshifted")) {
        tell_object(caster,"How can you shatter anyone's defenses without a weapon?");
        dest_effect();
        return;
    }
    if(!skinned = target->query_stoneSkinned()) {
        tell_object(caster,"%^RED%^You rain down a hail of light blows upon "
            +target->QCN+", but they seem to have no effect!%^RESET%^");
        tell_object(target,"%^BOLD%^%^GREEN%^"+caster->QCN+" rains down a hail "
            "of light blows on you, which have no visible effect!%^RESET%^");
        tell_room(place,"%^BOLD%^"+caster->QCN+" rains down a hail of light blows "
            "upon "+target->QCN+", but they have no visible effect!%^RESET%^",({target,caster}));
        dest_effect();
        return;
    }
    tempmap = caster->query_property("using shatter"); // adding per-target tracking. -N, 9/10.
    if(!mapp(tempmap)) tempmap = ([]);
    if(tempmap[target]) map_delete(tempmap,target);
    newmap = ([]);
    keyz = keys(tempmap);
    if(sizeof(keyz)) {
      for(i=0;i<sizeof(keyz);i++) { if(objectp(keyz[i])) newmap += ([ keyz[i] : tempmap[keyz[i]] ]); }
    }
    timerz = time() + FEATTIMER;
    newmap += ([ target : timerz ]);
    delay_msg(FEATTIMER,"%^BOLD%^%^WHITE%^"+target->QCN+" can be %^CYAN%^shattered%^WHITE%^ again.%^RESET%^");
    caster->remove_property("using shatter");
    caster->set_property("using shatter",newmap);

    if(!thaco(target)) {
        tell_object(caster,"%^RED%^"+target->QCN+" twists away quickly, leaving "
            "you off balance!%^RESET%^");
        tell_object(target,"%^BOLD%^%^GREEN%^You twist away quickly, leaving "
            +caster->QCN+" off balance!%^RESET%^");
        tell_room(place,"%^BOLD%^"+target->QCN+" twists away quickly, leaving "
            ""+caster->QCN+" off balance!%^RESET%^",({target,caster}));
        caster->set_paralyzed(roll_dice(2,6),"%^MAGENTA%^You're getting back into position.%^RESET%^");
        dest_effect();
        return;
    }
    tell_object(caster,"%^BOLD%^%^CYAN%^You rain down a hail of light blows upon "
        +target->QCN+", and layers of "+target->QP+" defenses shatter under the onslaught!");
    tell_object(target,"%^BOLD%^%^CYAN%^"+caster->QCN+" rains down a hail of light "
        "blows upon you, and layers of your defenses shatter under the onslaught!");
    tell_room(place,"%^BOLD%^%^CYAN%^"+caster->QCN+" rains down a hail of light blows "
        "upon "+target->QCN+", and layers of "+target->QP+" defenses shatter under the "
        "onslaught!",({target,caster}));

    mod = clevel+roll_dice(1,4);
    	if (skinned > mod) target->set_stoneSkinned(skinned - mod);
    	else
	{
		target->set_stoneSkinned(0);
		//following hijacked from body.c to actually get rid of stoneskin
		//or iron body if the target has those spells cast on them - Saide
		if(target->query_property("spelled"))
		{
			while(objectp(myspl = MAGIC_D->get_spell_from_array(target->query_property("spelled"), "stoneskin")) ||
			objectp(myspl = MAGIC_D->get_spell_from_array(target->query_property("spelled"), "iron body")))
            	{
            		target->remove_property_value("spelled", ({myspl}));
            		myspl->dest_effect();
			}
		}
	}
    	dest_effect();
}

void dest_effect(){
    ::dest_effect();
    remove_feat(TO);
    return;
}
