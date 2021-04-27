#include <std.h>
inherit "/std/armour";

void create(){
        ::create();
        set_name("gold gown");
        set_id(({ "gown", "dress", "dress of the dawn","silk dress"}));
        set_short("%^YELLOW%^Golden Gown of the %^MAGENTA%^D%^RED%^a%^RESET%^%^ORANGE%^w%^BOLD%^%^MAGENTA%^n%^RESET%^");
        set_obvious_short("%^YELLOW%^A golden gown%^RESET%^");
        set_long( "%^YELLOW%^Crafted from lightweight silk this dress "+
		"flows freely.  The bodice of the dress"+
		" fits close to the body, but not to tight.  The smooth "+
		"neckline fits flush with a lady's body, but not too"+
		" tight.  From the hips the dress flares out to create a two"+
		" tiered skirt.  The full skirt falls in gentle"+
		" folds as it flares out.  A weighted chain is hidden in each "+
		"tier of the dress, keeping the layers flowing"+
		" smoothly.  The golden silk seems to shimmer in the light, "+
		"reflecting %^MAGENTA%^d%^RED%^a%^RESET%^%^ORANGE%^w%^BOLD%^"+
		"%^MAGENTA%^n %^YELLOW%^colored hues.%^RESET%^\n");
        set_weight(5);
        set_value(700);
        set_lore( "The Golden Gown of the Dawn was blessed unto Thayil by "+
		"the Morninglord himself for her devotion to her faith and "+
		"seeking to lead those troubled souls away from the darkness "+
		"and to the glory of the dawn.");
        set_property("lore difficulty",14);
        set_type("clothing");
        set_limbs(({ "torso" }));
        set_size(2);
        set_property("enchantment",3);
        set_wear((:TO,"wear_func":));
        set_remove((:TO,"remove_func":));
}
void init()
{
::init();
        add_action("smile","smile");
}
        int wear_func(){
if((string)ETO->query_gender() == "male") {
                tell_object(ETO,"%^BOLD%^%^RED%^You rip the dress to shreds"+
		    "as you try to squeeze into it.");
                tell_room(environment(ETO),"%^BOLD%^%^RED%^"+ETO->QCN+""+
                " rips the dress to shreads as he tries to squeeze into it.",ETO);
		    TO->remove();
                return 0;
			}
        tell_room(environment(ETO),"%^BOLD%^%^RED%^"+ETOQCN+" is bathed in "+
		"the golden radiance of the gown.",ETO);
        tell_object(ETO,"%^BOLD%^%^RED%^You find yourself bathed in the golden"+
		" radiance of the gown.");
			ETO->add_sight_bonus(2);
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^MAGENTA%^"+ETOQCN+" slips off her gown, "+
		"the golden radiance fades in intensity!",ETO);
     	tell_object(ETO,"%^BOLD%^%^MAGENTA%^You slip off the golden gown, finding the"+
		" radiance that once bathed you fading away.");
			ETO->add_sight_bonus(-2);
        return 1;
}
int smile(string str)
{
        if(ETO->query_bound() || ETO->query_unconcious() || ETO->query_paralyzed()
|| ETO->query_tripped()) {
                TP->send_paralyzed_message("info",TP);
                return 1;
        }

        if(query_worn() && !str) {
                tell_object(ETO,"%^BOLD%^%^MAGENTA%^You smile brightly, letting "+
				"your inner radiance shine forth.");
                tell_room(environment(ETO),"%^BOLD%^%^MAGENTA%^"+ETO->QCN+" smiles"+
				" brightly, her face cast in a golden glow.",ETO);
                return 1;
        }
}