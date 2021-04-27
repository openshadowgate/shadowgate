#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("knee high boots");
	set_id(({ "boots", "knee high boots", "colored boots", "colors of the dancer" }));
	set_short("%^RESET%^%^MAGENTA%^C%^BOLD%^%^BLACK%^o%^RESET%^%^CYAN%^l%^RESET%^o%^RED%^r%^MAGENTA%^s %^BOLD%^%^BLACK%^o%^RESET%^%^MAGENTA%^f %^RESET%^t%^CYAN%^h%^RED%^e %^MAGENTA%^D%^BOLD%^%^BLACK%^a%^RESET%^%^CYAN%^n%^RESET%^c%^RED%^e%^MAGENTA%^r%^RESET%^");
	set_obvious_short("%^RESET%^a set of %^MAGENTA%^c%^BOLD%^%^BLACK%^o%^RESET%^%^CYAN%^l%^RESET%^o%^RED%^r%^MAGENTA%^f%^RESET%^u%^CYAN%^l %^RESET%^knee high boots");
	set_long(
@AVATAR
%^RESET%^These knee high boots are designed in a fanciful manner complete with a flared top of %^MAGENTA%^c%^BOLD%^%^BLACK%^o%^RESET%^%^CYAN%^l%^RESET%^o%^RED%^r%^MAGENTA%^f%^RESET%^u%^CYAN%^l %^RESET%^suede.  Pretty strips of %^MAGENTA%^purple%^RESET%^, %^CYAN%^blue%^RESET%^, %^RED%^red%^RESET%^, %^RESET%^white and %^BOLD%^%^BLACK%^black %^RESET%^suede has been sewn together in a swirling pattern that climbs from the toes up to the top of the calves where it spills over in an unfinished flare.  %^ORANGE%^Brass buttons%^RESET%^ and %^BOLD%^%^BLACK%^rawhide %^RESET%^lace up the outside of the calf, so the boots can be adjusted to fit the wearer's leg shape.  Thin leather soles provide only some protection against the ground, though what they give up in %^MAGENTA%^protection%^RESET%^, they provide in %^CYAN%^maneuverability%^RESET%^, allowing flexibility and encouraging quick, easy movements, especially those that might be found in %^ORANGE%^stage work %^RESET%^or in swift moving %^RED%^battles%^RESET%^.

AVATAR
	);
	set_weight(4);
	set_value(3000);
	set_lore(
@AVATAR
Tipsen Topser, a gnomish rogue of some repute, was known for his flamboyant troubadour style, and some say womanizing ways. Blessed with a dancer's body, comely looks and a natural arrogance, he used his appearance to its best advantage, dressing to the height of fashion with bold colors and carefully tailored styles.  Though short, this never stopped him from flirting, nor from finding trouble.  Many report that Tipsen met his end after luring the wife a powerful official into his bed.  That she was a member of the giant races and that he perished during a rather delicate moment.  Others agree that it was this encounter which sealed Tipsen's fate, but swear he was able to escape by performing a dangerous balancing act along the very narrow window ledge.  In this last tale, most say the only thing Tipsen wore was a set of boots, having had no time to slip into anything else.

AVATAR
	);
	set_property("lore difficulty",18);
	set_type("clothing");
	set_limbs(({ "left foot", "right foot" }));
	set_size(1);
	set_property("enchantment",2);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}

int wear_func(){
	tell_room(environment(ETO),"%^RESET%^%^CYAN%^"+ETOQCN+" grins impishly as they draw their "+query_short()+" %^RESET%^%^CYAN%^on and tie off the laces.%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^CYAN%^As you lace your "+query_short()+" %^RESET%^%^CYAN%^up the side, you are over come with a sense that you could dance your way out of even the most delicate of situations. %^RESET%^");
	return 1;
}

int remove_func(){
	tell_room(environment(ETO),"%^RESET%^%^CYAN%^"+ETOQCN+" pulls their "+query_short()+" %^RESET%^%^CYAN%^free and flexes their freed feet.%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^CYAN%^With a few quick movements of your hands, you undo the laces of the "+query_short()+"%^RESET%^%^CYAN%^.%^RESET%^");
	return 1;
}

