//Octothorpe (2/15/10)
//Greater Mundanoid, created for Myrkul for a plot

#include <std.h>
#include <daemons.h>
inherit WEAPONLESS;

void create(){
   ::create();
   set_name("greater mundanoid");
   set_id(({"greater mundanoid","greater","mundanoid"}));
   set_short("%^RESET%^%^CYAN%^G%^BOLD%^%^BLUE%^r%^RESET%^%^CYAN%^"+
      "ea%^BOLD%^%^BLUE%^t%^RESET%^%^CYAN%^er M%^BOLD%^%^BLUE%^u"+
	  "%^RESET%^%^CYAN%^ndan%^BOLD%^%^BLUE%^o%^RESET%^%^CYAN%^"+
	  "id%^RESET%^");
   set_long("%^RESET%^%^CYAN%^This mundanoid looks nothing more than "+
      "a walking glob of %^BOLD%^%^BLACK%^g%^WHITE%^r%^BLACK%^e"+
	  "%^WHITE%^y%^BLACK%^-%^BLUE%^b%^BLACK%^l%^BLUE%^ue%^RESET%^"+
	  "%^CYAN%^ %^RED%^anti-magic%^CYAN%^ with a vaguely humanoid "+
	  "shape. This is an extremely powerful %^BOLD%^%^WHITE%^construct"+
	  "%^RESET%^%^CYAN%^ designed to feed on %^YELLOW%^magical energy"+
	  "%^RESET%^%^CYAN%^. Wherever these creatures go, magic is "+
	  "absorbed and transformed by to more and more powerful "+
	  "Mundanoids. These particular creatures are extremely %^BOLD%^"+
	  "%^BLACK%^ancient%^RESET%^%^CYAN%^ so much so that they have "+
	  "taken on %^BOLD%^%^WHITE%^intelligence %^RESET%^%^CYAN%^and "+
	  "%^BOLD%^%^MAGENTA%^personality%^RESET%^%^CYAN%^ from the "+
	  "amount of magic they have absorbed. They are extremely "+
	  "dangerous now, and their powers are %^BOLD%^%^RED%^devastating"+
	  "!%^RESET%^");
   set_race("outsider");
   set_gender("male");
   set_body_type("human");
   set_hd(40,1);
   set_size(3);
   set_class("fighter");
   set_class("mage");
   set_mlevel("fighter",40);
   set_mlevel("mage",40);
   set_guild_level("fighter",40);
   set_guild_level("mage",40);
   add_search_path("/cmds/fighter");
   set_exp(250000);
   set_max_hp(2500);
   set_hp(query_max_hp());
   set_attacks_num(6);
   set_damage(1,50);
   set_alignment(9);
   set_diety("myrkul");
   set("aggressive",20);
   set_property("swarm",1);
   set_mob_magic_resistance("average");
   add_money("gold",random(15000));
   set_spell_chance(25);
   set_func_chance(25);
   set_spells(({
      "greater shout",
	  "dispel magic",
	  "sonic orb",
	  "prismatic spray",
	  "powerword stun"
   }));
   set_funcs(({
      "nom",
	  "rushit",
	  "flashit"
   }));
}

void flashit(object targ){
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   TO->force_me("flash "+targ->query_name());
}

void rushit(object targ){
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   TO->force_me("rush "+targ->query_name());
}

/* The following is pulled from the mundanoid magic draining special (/d/stella/mon/mund_nw.c), with unique echoes made by Myrkul.  This is also used in the Weave Eater mob for the same plot.  Geez, this stuff is a mess. - Octothorpe 2/15/10 */
int nom(){
    object targ = TO->query_current_attacker();
    object *inv = deep_inventory(targ);
    int xx, newac, newhd, numinv = sizeof(inv);
    int hits = query_hp();
	if(!objectp(TO)) return 0;
    if(!objectp(targ)) return 0;
    if (numinv == 0) return 1;
    xx = random(numinv);
    if((inv[xx]->query_property("enchantment") &&
inv[xx]->query_property("enchantment")>0) ||
        inv[xx]->query_property("magic") ||
        ((member_array("ring",inv[xx]->query_id()) >=
0)&&(member_array("onyx",inv[xx]->query_id())==-1)) ||
        (member_array("well",inv[xx]->query_id()) >= 0) ||
        (member_array("staff",inv[xx]->query_id()) >= 0) ||
        (member_array("wand",inv[xx]->query_id()) >= 0) ||
        (member_array("key",inv[xx]->query_id()) >= 0))
      {
      tell_object(targ,"%^BOLD%^%^CYAN%^The %^RED%^Weave Eater%^CYAN%^ "+
	     "unbinds the magic of your items, %^YELLOW%^absorbing"+
		 "%^CYAN%^ its %^GREEN%^mystic strength!%^RESET%^");
      if (inv[xx]->query_property("enchantment")) {
        newhd = inv[xx]->query_property("enchantment");
        newhd = newhd*10;
      }
      else if (inv[xx]->query_property("enhancement")){
        newhd = inv[xx]->query_property("enhancement");
        newhd = newhd*10;
      }
      else newhd = 20;
    if(newhd < 1) newhd = 1;
      inv[xx]->remove();
      set_hp(hits+250);
   }
   return 1;
}