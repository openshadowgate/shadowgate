#include <std.h>
inherit "/std/flying_mount";

void create(){
   ::create();
   set_riding_level(20);
   set_name("skeletal mount");
   set_id(({"wyvern","skeleton","skeletal mount","mount","skeletal wyvern","wyvern shaped skeleton"}));
   set_short("%^BOLD%^%^BLUE%^sk%^BLACK%^ele%^BLUE%^tal wy%^BLACK%^ve%^BLUE%^rn%^RESET%^");
   set_long("%^BOLD%^%^BLUE%^This large %^WHITE%^skeletal creature %^BLUE%^stands an imposing ten feet tall. Supported on "
"two thick, powerful hind legs that taper to %^BLACK%^razor sharp claws%^BLUE%^, the unholy beast stalks forward with a "
"sensuous, deadly gait. Rising from the wide, barrel chest, two great wings draped in the thinnest layer of %^GREEN%^de"
"%^RESET%^%^GREEN%^c%^BOLD%^%^BLACK%^r%^RESET%^%^GREEN%^e%^BOLD%^pi%^RESET%^%^GREEN%^t %^BOLD%^h%^BLACK%^i%^RESET%^"
"%^GREEN%^d%^BOLD%^e%^BLUE%^ extend, each tipped with vicious bone claws. The wings, twice as large as the beast's body, "
"give it additional height and width as well as a constant odor of %^RESET%^%^ORANGE%^decay %^BOLD%^%^BLUE%^and %^BLACK%^"
"rot%^BLUE%^. The spine of the creature travels in sharp, deadly ridges from the crown of its reptilian head to the end "
"of its long spike tipped tail. These deadly spines are missing only over the shoulders where a thickly padded, %^BLACK%^"
"black leather saddle %^BLUE%^rests. The spines before the saddle have likewise been capped with %^BLACK%^leather %^BLUE%^"
"to prevent their tips from driving into the rider's body should the creature buck. %^GREEN%^G%^RESET%^%^GREEN%^l%^BOLD%^"
"%^BLACK%^o%^GREEN%^w%^RESET%^%^GREEN%^in%^BOLD%^g e%^BLACK%^y%^RESET%^%^GREEN%^e%^BOLD%^s%^BLUE%^, dark as the abyss and "
"filled with unholy energy gleam from within the %^WHITE%^white skull %^BLUE%^of the beast, just as a %^BLACK%^murky haze "
"%^BLUE%^constantly coils outward from its elongated muzzle. Bits of flesh hang from between the sharp teeth that snap "
"and bite at anything this beast might find tasty, from small animals and children to larger prey or enemies.%^RESET%^");
   set_race("wyvern");
   set_body_type("dragon");
   add_limb("teeth","head",0,0,0);
   remove_limb("left foreleg");
   remove_limb("right foreleg");
   set_attack_limbs( ({"teeth","left foreclaw","right foreclaw"}) );
   set_hit_funcs((["teeth":(:TO,"mouth":),]));
   set_base_damage_type("slashing");
   set_damage(1,10);
   set_attacks_num(2);
   set_overall_ac(-14);
   set_stats("strength",18);
   set_hd(10+random(15),10);
   set_hp(query_hd()*16);
   set_exp(1);
   set_funcs(({"breath_wep"}));
   set_func_chance(25);
   command("message in %^BOLD%^%^BLACK%^enters screeching an %^GREEN%^un%^RESET%^%^GREEN%^na%^BLACK%^%^BOLD%^t%^GREEN%^ur"
"%^RESET%^%^GREEN%^a%^BOLD%^l %^BLACK%^cry.%^RESET%^");
   command("message out %^BOLD%^%^BLACK%^leaps up %^GREEN%^f%^RESET%^%^GREEN%^l%^BOLD%^%^BLACK%^y%^GREEN%^i%^RESET%^%^GREEN%^n%^BOLD%^g %^BLACK%^toward the $D.%^RESET%^");
   set_flight_delay(1800);
   set_flying_prof(30);
   set_ward_pass(15);
}

int mouth(object targ){
   return random(10);
}

void breath_wep(object targ){
   int i;
   if(!objectp(targ)) return;
   i = random(sizeof(query_attackers()));
   if(objectp(query_attackers()[i]))
   new("/cmds/psionics/_breath_of_the_black_dragon")->use_spell(TO,query_attackers()[i]->query_name(), 15);
   tell_room(ETO,"%^BOLD%^%^BLACK%^The skeletal wyvern's eyes gleam with an %^GREEN%^u%^RESET%^%^GREEN%^nh%^BOLD%^"
"%^BLACK%^o%^GREEN%^l%^RESET%^%^GREEN%^y l%^BOLD%^i%^BLACK%^g%^RESET%^%^GREEN%^ht %^BLACK%^%^BOLD%^as the thick haze of "
"%^GREEN%^ot%^RESET%^%^GREEN%^h%^BOLD%^%^BLACK%^e%^RESET%^%^GREEN%^r%^BOLD%^wo%^BLACK%^r%^GREEN%^l%^RESET%^%^GREEN%^dl"
"%^BOLD%^y e%^BLACK%^n%^RESET%^%^GREEN%^er%^BOLD%^%^BLACK%^g%^GREEN%^y %^BLACK%^spills from its mouth and encompasses "
+query_attackers()[i]->query_name()+"%^BOLD%^%^BLACK%^.%^RESET%^");
}

int enter(string str){
    if(query_owner() != this_player()) {
      tell_room(ETP,"The skeletal wyvern hisses in warning at "+TP->QCN+".", TP);
      return notify_fail("The skeletal wyvern hisses in warning as you approach. It's probably not wise to bother it.\n");
    }
    return ::enter(str);
}

int handle_critter(string str) {
    tell_room(ETP,"The skeletal wyvern hisses in warning at "+TP->QCN+".", TP);
    return notify_fail("The skeletal wyvern hisses in warning as you approach. It's probably not wise to bother it.\n");
}

int give_me_away(string str){
    return notify_fail("Your mount refuses to heed the instructions of anyone but you!\n");
    return 0;
}
int save_me(string file) {return 0;}
int restore_me(string file) { TO->remove(); return 0;}
