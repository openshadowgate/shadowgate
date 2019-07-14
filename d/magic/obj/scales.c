// Dragon Scales coded by Bane
// removed cha bonus on discussion; no real need and too much of a downside for sorcs. N, 09/07.
// set to innate AC, non-enchanted bracer; these will stack with clothing (for mages) but not with armor. N, 7/12.
#include <std.h>
inherit ARMOUR;

int desting, mr;
object ob;
string owner;
void create() {
    ::create();
    set_id(({"dragon scales","scales","xxxscales"}));
    set_name("dragon scales");
    set_short("%^RESET%^%^GREEN%^ripp%^BOLD%^%^GREEN%^l%^YELLOW%^i%^RESET%^%^GREEN%^ng layer of dr%^BOLD%^%^GREEN%^a%^RESET%^%^GREEN%^gon sca%^CYAN%^l%^GREEN%^es%^RESET%^");
    set_long("%^GREEN%^This layer of scales clings like a perfectly-fitted second skin.  The overlapping emerald scales gleam as light catches on their countless glossy surfaces.%^RESET%^");
    set_size(-1);
    set_weight(0);
    set_decay_rate(600);
    set_value(0);
    set_type("bracer");
    set_property("magicarmor",1);
    set_ac(0);
    set_property("no animate",1);
    set_limbs(({"torso"}));
    set_wear((:TO,"wear_me":));
    set_remove((:TO,"remove_me":));
    set_heart_beat(1);
}

void init() {
    ::init();
    if(owner && owner != (string)TPQN) { 
        TO->remove(); 
	  return;
    }
    if (living(ETO))
    {
        TO->set_worn(ETO);
        TO->set_actual_limbs(ETO);
    }
    if (living(TP) && !owner) owner = TPQN;
}

void dest_me() {
    tell_object(ETO,"The scales lose their magic power and turn to dust.");
     set_property("combat_remove",1);
    if (TO->query_worn()) ETO->force_me("remove scales");
    TO->remove();
    return;
}

int set_mr(int x) {
    return mr = x;
}

string set_owner(string name) {
    return owner = name;
}

void wear_me() {
    if(owner == (string)ETO->query_name()) {
        ETO->set_property("magic resistance",mr);
    }
    return 1;
}

void remove_me() {
    if(owner == (string)ETO->query_name()) {
        ETO->set_property("magic resistance",-mr);
    }
    return 1;
}


void save_me(string file) {
    return 1;
}
int isMagic() { return 3;}

int decay() { return 0; }

int drop(){ return 1;}

int wearable() { return 1; }
