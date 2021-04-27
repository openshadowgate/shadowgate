#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("%^RESET%^%^BOLD%^%^BLACK%^m%^RESET%^%^BOLD%^%^WHITE%^i%^RESET%^%^BOLD%^%^BLACK%^thril m%^RESET%^%^WHITE%^e%^RESET%^%^BOLD%^%^BLACK%^chani%^RESET%^%^WHITE%^c%^RESET%^%^BOLD%^%^BLACK%^al arm%^RESET%^");
	set_id(({ "arm", "mithril arm", "mechanical arm", "construct arm" }));
	set_short("%^RESET%^%^BOLD%^%^BLACK%^m%^RESET%^%^BOLD%^%^WHITE%^i%^RESET%^%^BOLD%^%^BLACK%^thril m%^RESET%^%^WHITE%^e%^RESET%^%^BOLD%^%^BLACK%^chani%^RESET%^%^WHITE%^c%^RESET%^%^BOLD%^%^BLACK%^al arm%^RESET%^");
	set_obvious_short("%^RESET%^%^BOLD%^%^BLACK%^m%^RESET%^%^BOLD%^%^WHITE%^i%^RESET%^%^BOLD%^%^BLACK%^thril m%^RESET%^%^WHITE%^e%^RESET%^%^BOLD%^%^BLACK%^chani%^RESET%^%^WHITE%^c%^RESET%^%^BOLD%^%^BLACK%^al arm%^RESET%^");
	set_long(
"%^RESET%^%^BOLD%^%^BLACK%^Constructed from %^RESET%^%^BOLD%^"
"%^WHITE%^m%^RESET%^%^WHITE%^i%^RESET%^%^BOLD%^%^WHITE%^thr"
"%^RESET%^%^BOLD%^%^BLACK%^i%^RESET%^%^BOLD%^%^WHITE%^l%^RESET%^"
"%^BOLD%^%^BLACK%^, this is less a replica of an arm, then a "
"construct to to the same work. A large ball joint dominates "
"the shoulder, %^RESET%^%^WHITE%^visible gears %^RESET%^%^BOLD%^"
"%^BLACK%^turn almost absently, running cogs and pistons within "
"the construct. The upper arm is a long cylinder of mithril "
"carved with several a%^RESET%^%^MAGENTA%^r%^RESET%^%^BOLD%^"
"%^BLACK%^ca%^RESET%^%^MAGENTA%^n%^RESET%^%^BOLD%^%^BLACK%^e "
"sy%^RESET%^%^MAGENTA%^m%^RESET%^%^BOLD%^%^BLACK%^bo%^RESET%^"
"%^MAGENTA%^l%^RESET%^%^BOLD%^%^BLACK%^s. it bulges at one point "
"as if %^RESET%^%^WHITE%^something %^RESET%^%^BOLD%^%^BLACK%^was "
"contained safely within. The Lower portion of the arm contains "
"many pistons and more gears. Small bursts of %^RESET%^%^BOLD%^"
"%^WHITE%^steam %^RESET%^%^BOLD%^%^BLACK%^hiss from the joints. "
"The most intricate work has been done with the hand itself, "
"where mithril has been covered in a %^RESET%^%^ORANGE%^s%^RESET%^"
"%^BOLD%^%^BLACK%^o%^RESET%^%^ORANGE%^ft fa%^RESET%^%^BOLD%^%^BLACK%^"
"b%^RESET%^%^ORANGE%^ric %^RESET%^%^BOLD%^%^BLACK%^for more delicate "
"work. Overall the arm is a work of art, and you wonder what the "
"power for this construct comes from.%^RESET%^"
	);
	set_weight(5);
	set_value(0);
	set_type("ring");
	set_limbs(({"left arm"}));
	set_size(2);
	set_property("enchantment",0);
      set_heart_beat(1); 
}

void heart_beat() {
  if (random (450)>448){
    tell_object(ETO, "%^RESET%^%^BOLD%^%^BLACK%^a small burst of %^RESET%^%^BOLD%^%^WHITE%^steam"
                    +" %^RESET%^%^BOLD%^%^BLACK%^erupts from the mechanical arm, and you hear gears"
                    +" and cogs realign with a click...%^RESET%^"); 

    tell_room(EETO, "%^BOLD%^%^BLACK%^" + (string)ETO->QCN 
                   + "%^RESET%^%^BOLD%^%^BLACK%^'s fingers twitch slightly as you hear pistons within"
                   +" the mechanical arm %^RESET%^%^WHITE%^fire %^RESET%^%^BOLD%^%^BLACK%^suddenly..."
                   +"%^RESET%^", ETO);
    if (ETO->query_invis() && random(2) ){
      ETO->set_invis(0);
    }
  }
}

