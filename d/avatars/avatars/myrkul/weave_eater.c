//Octothorpe (2/14/10)
//Weave Eater, created for Myrkul for a plot

#include <std.h>
#include <daemons.h>
inherit WEAPONLESS;

void create(){
   ::create();
   set_name("weave eater");
   set_id(({"weave eater","weave","eater"}));
   set_short("%^RESET%^%^CYAN%^W%^RED%^e%^CYAN%^a%^RED%^v%^CYAN%^e "+
      "%^RED%^E%^CYAN%^at%^RED%^e%^CYAN%^r%^RESET%^");
   set_long("%^RESET%^%^CYAN%^Before you is a twisted looking "+
      "%^MAGENTA%^sp%^RED%^i%^MAGENTA%^der%^CYAN%^. It is enormous "+
	  "with standing maybe six feet tall with long stilted legs and "+
	  "bristling %^BOLD%^%^BLACK%^black%^RESET%^%^CYAN%^ fur. Many "+
	  "bright %^BOLD%^shimmering%^RESET%^%^CYAN%^ eyes stare out "+
	  "with %^RED%^ravenous%^CYAN%^ hunger, not just for %^ORANGE%^"+
	  "meat%^CYAN%^ but the very stuff of %^BOLD%^%^BLUE%^magic"+
	  "%^RESET%^%^CYAN%^. A %^MAGENTA%^v%^BOLD%^%^BLACK%^o%^RESET%^"+
	  "%^MAGENTA%^rt%^BOLD%^%^BLACK%^e%^RESET%^%^MAGENTA%^x%^CYAN%^ "+
	  "surrounding the spider seems to %^RED%^pull%^CYAN%^ on the "+
	  "very fabric of reality, %^RED%^cutting%^CYAN%^ the very "+
	  "threads of the weave before your eyes.%^RESET%^");
   set_race("outsider");
   set_gender("female");
   set_body_type("arachnid");
   set_hd(50,1);
   set_size(3);
   set_class("psion");
   set_class("cleric");
   set_class("mage");
   set_mlevel("psion",50);
   set_mlevel("cleric",50);
   set_mlevel("mage",50);
   set_guild_level("psion",50);
   set_guild_level("cleric",50);
   set_guild_level("mage",50);
   set_exp(1000000);
   set_max_hp(12000);
   set_hp(query_max_hp());
   set_attacks_num(6);
   set_damage(1,50);
   set_alignment(9);
   set_diety("myrkul");
   set("aggressive",20);
   set_property("swarm",1);
   set_mob_magic_resistance("average");
   add_money("gold",random(100000));
   set_spell_chance(100);
   set_func_chance(25);
   set_spells(({
      "cause blindness",
	  "catapsi",
	  "ultrablast",
	  "earth reaver",
	  "mass cause critical wounds",
	  "timeless body",
	  "greater dispel magic"
   }));
   set_funcs(({
      "nom",
	  "timestop",
	  "fuck_mystrans"
   }));
}

/* The following borrows a lot from the timestop spell (/d/cmds/wizard/_timestop.c).  Creating a separate function for the effect because it completely removes attackers, and the mob won't auto afterwards.  Going to run the same queries and turn the timestopping effect into a stun and still have the targets set as attackers. - Octothorpe 2/14/10 */
int timestop(object targ){
   object *attackers,room;
   int i;
   attackers = TO->query_attackers();
   attackers = filter_array(attackers,"is_non_immortal",FILTERS_D);
   if(!objectp(TO)) return 0;
   if(!objectp(targ)) return 0;
   for(i=0;i<sizeof(attackers);i++){      
      tell_room(ETO,"%^BOLD%^%^GREEN%^All of the sudden, everything "+
	     "in the surrounding area seems to freeze in "+
		 "place!%^RESET%^",attackers[i]);
      attackers[i]->set_paralyzed(2,"%^BOLD%^The world around "+
	     "you has slowed nearly to a stop!%^RESET%^");
   }
   return 1;
}

/* The following is pulled from the mundanoid magic draining special (/d/stella/mon/mund_nw.c), with unique echoes made by Myrkul.  This is also being used in the Greater Mundanoid mob for the same plot.  Geez, this stuff is a mess. - Octothorpe 2/14/10 */
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
      set_hp(hits+500);
   }
   return 1;
}

int fuck_mystrans(object targ){
   if(!objectp(TO)) return 0;
   if(!objectp(targ)) return 0;
   if((string)targ->query_diety() == "mystra"){
      tell_room(ETO,"%^BOLD%^%^CYAN%^The %^RED%^Weave Eater%^CYAN%^ "+
	     "directs a blast of %^GREEN%^magical feedback%^CYAN%^ at "+
		 "her hated %^BLUE%^Mystran%^CYAN%^ foes!!%^RESET%^");
	  tell_object(targ,"%^BOLD%^%^CYAN%^The %^RED%^Weave Eater%^CYAN%^ "+
	     "directs a blast of %^GREEN%^magical feedback%^CYAN%^ at "+
		 "you!%^RESET%^");
	  targ->do_damage("torso",150);
	  return 1;
   }
   return 1;
}