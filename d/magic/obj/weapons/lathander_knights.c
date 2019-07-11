//Selune Weapon Spell
#include <std.h>
inherit "/d/magic/obj/weapons/godwpns_knights.c";
void create()
{
   ::create();
   	set_name("%^BOLD%^%^MAGENTA%^M%^WHITE%^o%^MAGENTA%^rn"+
		"%^YELLOW%^i%^MAGENTA%^ng %^YELLOW%^Glory%^MAGENTA%^"+
		" Sword%^RESET%^");
   	set_short("%^BOLD%^%^MAGENTA%^M%^WHITE%^o%^MAGENTA%^rn"+
		"%^YELLOW%^i%^MAGENTA%^ng %^YELLOW%^Glory%^MAGENTA%^"+
		" Sword%^RESET%^");
   	set_id(({"sword","blade","morning glory sword","weapon"}));
   	set_long("Gleaming in the light proudly, this blade is created"+
		" out of %^YELLOW%^gold%^RESET%^.  The brilliant "+
		"%^YELLOW%^yellow%^RESET%^ shades of the gold glimmers "+
		"and shines like the sun.  A large orb of %^BOLD%^%^MAGENTA%^"+
		"rose quartz%^RESET%^ is set into the blade.  A bright"+
		" %^BOLD%^light%^RESET%^ shines from inside the %^BOLD%^%^MAGENTA%^"+
		"rose quartz orb%^RESET%^, causing the orb to glow with a "+
		"%^BOLD%^%^MAGENTA%^rose-%^RED%^red%^RESET%^ aura.  Precious"+
		" %^BOLD%^%^RED%^g%^RESET%^%^ORANGE%^e%^RED%^m%^BOLD%^%^WHITE%^s"+
		"%^RESET%^ are imbedded into the pommel of the blade.");
	set_value(0);
	set_hit((:TO,"hit_func":));
}
int hit_func(object targ){
  	targ = ETO->query_current_attacker();
  	if(!objectp(ETO)) return 1;
  	if(!objectp(targ)) return 1;

	if(!random(10)) {
      	tell_object(ETO,"%^YELLOW%^A warm burst of light flares out from"+
			" the blade, burning "+targ->QCN+".");
      	tell_object(targ,"%^YELLOW%^A warm burst of bright light flares"+
			" out of "+ETO->QCN+"'s blade, burning you!");
      	tell_room(environment(ETO),"%^YELLOW%^A warm burst of bright "+
			"light flares out of "+ETO->QCN+"'s blade, burning"+
			" "+targ->QCN+".",({ETO,targ}));
      		targ->do_damage("torso",random(4)+4);
      	return 1;
   }
}