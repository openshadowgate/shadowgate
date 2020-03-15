//Coded by Bane//
// modified slightly to recharge while it's not in use
#include <std.h>
inherit ARMOUR;
int uses;

void create()
{
    ::create();
    set_id(({"ring","ring of regeneration","regen ring"}));
    set_name("Ring of Regeneration");
    set_obvious_short("%^BOLD%^%^GREEN%^An emerald ring%^RESET%^");
    set_short("%^BOLD%^%^GREEN%^A ring of regeneration%^RESET%^");
    set("lore",
	"This is a beautiful emerald ring.  It is known to most as a "+
	"ring of regeneration.  Wear this powerful ring and you will heal "+
	"at a phenomenal rate." );
    set_long("%^RESET%^%^BOLD%^%^YELLOW%^This ring has been created with remarkable craftsmanship.  Intricate "
		"runes are carved into a pure gold band that rises just high enough to encircle the edges of a large, "
		"square cut %^RESET%^%^BOLD%^%^GREEN%^emerald.%^RESET%^%^BOLD%^%^YELLOW%^  The ring is so well crafted "
		"that the %^RESET%^%^BOLD%^%^GREEN%^emerald%^RESET%^%^BOLD%^%^YELLOW%^ almost seems to be an extension "
		"of its golden band.%^RESET%^");
	//set_long("This is a beautiful golden ring that has a large rectangularly cut emerald set in the very center of it.");
	set_type("ring");
    set_ac(0);
    set_limbs( ({"right hand","left hand"}) );
    set_weight(5);
    set_value(7000);
    set_wear((:TO,"wer_me":));
    set_remove((:TO,"remov_me":));
    set_heart_beat(6);
    uses = 0;
}
void wer_me()
{
    tell_object(ETO,"Your skin begins to tingle and revitalize.");
    return 1;
}
void remov_me(){
    tell_object(ETO,"Your skin begins feels dry and normal again.");
    return 1;
}
void heart_beat()
{
	if(ETO && living(ETO))
	{
		if(TO->query_worn())
		{
			if(uses < 0) { uses = 0; }
			if(uses < 100000)
			{
				if((int)ETO->query_hp() >= (int)ETO->query_max_hp())
				{
					uses--;
					return;
				}
				ETO->add_hp(roll_dice(1,6));
				tell_room(ETO,"%^RESET%^%^GREEN%^Your skin heals itself.%^RESET%^");
				uses +=2;
			}
			if(uses >= 100000)
			{
				uses--;
				return 1;
			}
		}
    }
}
