#include <std.h>
inherit PARMOUR;

void create(){
	::create();
	set_name("silver lining");
	set_id(({ "silver lining", "lining", "gown" }));
	set_short("%^BOLD%^%^WHITE%^S%^BLACK%^i%^RESET%^l%^BOLD%^%^BLACK%^v%^WHITE%^er L%^BLACK%^i%^RESET%^n%^BOLD%^%^BLACK%^i%^WHITE%^ng%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^S%^BLACK%^i%^RESET%^l%^BOLD%^%^BLACK%^v%^WHITE%^er L%^BLACK%^i%^RESET%^n%^BOLD%^%^BLACK%^i%^WHITE%^ng%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^Sh%^CYAN%^i%^WHITE%^m%^RESET%^m%^BOLD%^%^BLACK%^e%^WHITE%^ri%^BOLD%^%^BLACK%^n%^WHITE%^g %^RESET%^with an %^CYAN%^i%^BOLD%^%^WHITE%^r%^RESET%^%^MAGENTA%^i%^CYAN%^des%^BOLD%^%^WHITE%^c%^RESET%^%^CYAN%^ent %^RESET%^liquid sheen, this %^BOLD%^%^WHITE%^s%^BLACK%^i%^RESET%^l%^BOLD%^%^BLACK%^v%^WHITE%^er g%^RESET%^o%^BOLD%^%^BLACK%^w%^WHITE%^n%^RESET%^ curves and shapes to the body of the wearer like a second skin.  Woven from millions of tiny beads of %^BOLD%^%^BLUE%^w%^CYAN%^a%^BLUE%^ter %^RESET%^strung together like %^BOLD%^%^WHITE%^pearls%^RESET%^, the gown flows down from the scooped collar to brush the floor in a trailing spill of %^BOLD%^%^WHITE%^cl%^CYAN%^o%^WHITE%^udy va%^CYAN%^p%^WHITE%^ors%^RESET%^.  Like the skirt of the gown, the wide, draped sleeves turn %^CYAN%^m%^WHITE%^i%^BLUE%^s%^CYAN%^ty %^RESET%^at the elbow and trail down to cuff.  Gathering the loose material up before it hangs free are %^BOLD%^%^BLACK%^s%^WHITE%^i%^BLACK%^lver %^RESET%^ties that %^BOLD%^%^BLACK%^c%^WHITE%^r%^BLACK%^i%^WHITE%^s%^BLACK%^s%^WHITE%^c%^BLACK%^r%^WHITE%^o%^BLACK%^s%^WHITE%^s %^RESET%^ from the shoulder to elbow of each sleeve.  These ties are repeated along the back of the gown, causing the bodice portion to be snug to the body. Bands of %^YELLOW%^g%^RESET%^%^ORANGE%^o%^YELLOW%^lden s%^RESET%^%^ORANGE%^u%^YELLOW%^nli%^RESET%^%^ORANGE%^g%^YELLOW%^ht %^RESET%^glisten at the collar in a lacy pattern that %^BOLD%^%^WHITE%^g%^CYAN%^l%^WHITE%^im%^BLACK%^m%^CYAN%^e%^WHITE%^rs %^RESET%^and changes with every breath, occasionally %^BOLD%^%^WHITE%^il%^CYAN%^l%^WHITE%^um%^BLACK%^i%^CYAN%^n%^WHITE%^ati%^CYAN%^n%^WHITE%^g%^RESET%^ the whole gown with a %^RED%^r%^RESET%^%^ORANGE%^a%^YELLOW%^i%^GREEN%^n%^RESET%^%^CYAN%^b%^BLUE%^o%^BOLD%^%^MAGENTA%^w %^RESET%^glow.%^RESET%^

AVATAR
	);
	set_weight(5);
	set_value(0);
	set_lore(
@AVATAR
%^BOLD%^%^WHITE%^Woven from the very essences of air and water, this gown was made for a fluffy white cloud.  After all, what use is a cloud without a silver lining?%^RESET%^

AVATAR
	);
	set_property("lore difficulty",10);
	set_max_internal_encumbrance(100);
	set_type("clothing");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",10);
	set_ac(10);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
	set_struck((:TO,"strike_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^RESET%^A %^BOLD%^%^WHITE%^sp%^CYAN%^a%^RESET%^r%^BOLD%^%^WHITE%^k%^RESET%^l%^BOLD%^%^BLACK%^i%WHITE%^ng sh%^CYAN%^i%^WHITE%^m%^RESET%^m%^BOLD%^%^BLACK%^e%^WHITE%^r%^RESET%^ of %^BOLD%^%^RED%^r%^YELLOW%^a%^RESET%^%^ORANGE%^i%^BOLD%^%^GREEN%^n%^RESET%^%^GREEN%^b%^BOLD%^%^CYAN%^o%^BLUE%^w%^RESET%^%^MAGENTA%^s%^RESET%^ lights up the "+query_short()+" %^RESET%^as it is worn.%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^A %^BOLD%^%^WHITE%^sp%^CYAN%^a%^RESET%^r%^BOLD%^%^WHITE%^k%^RESET%^l%^BOLD%^%^BLACK%^i%^WHITE%^ng sh%^CYAN%^i%^WHITE%^m%^RESET%^m%^BOLD%^%^BLACK%^e%^WHITE%^r%^RESET%^ of %^BOLD%^%^RED%^r%^YELLOW%^a%^RESET%^%^ORANGE%^i%^BOLD%^%^GREEN%^n%^RESET%^%^GREEN%^b%^BOLD%^%^CYAN%^o%^BLUE%^w%^RESET%^%^MAGENTA%^s%^RESET%^ lights up the "+query_short()+" %^RESET%^as it is worn.%^RESET%^");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^RED%^R%^YELLOW%^a%^RESET%^%^ORANGE%^i%^BOLD%^%^GREEN%^n%^RESET%^%^GREEN%^b%^BOLD%^%^CYAN%^o%^BLUE%^w%^RESET%^%^MAGENTA%^s %^BOLD%^%^WHITE%^gl%^CYAN%^i%^WHITE%^s%^RESET%^t%^BOLD%^%^BLACK%^e%^WHITE%^n %^RESET%^as "+ETOQCN+" removes their "+query_short()+"%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^RED%^R%^YELLOW%^a%^RESET%^%^ORANGE%^i%^BOLD%^%^GREEN%^n%^RESET%^%^GREEN%^b%^BOLD%^%^CYAN%^o%^BLUE%^w%^RESET%^%^MAGENTA%^s %^BOLD%^%^WHITE%^gl%^CYAN%^i%^WHITE%^s%^RESET%^t%^BOLD%^%^BLACK%^e%^WHITE%^n %^RESET%^as you remove your "+query_short()+"%^RESET%^");
	return 1;
}
int strike_func(int damage, object what, object who){
	if(random(1000) < 100){
	tell_room(environment(query_worn()),"%^BOLD%^%^BLACK%^A little %^BLUE%^s%^BLACK%^t%^WHITE%^o%^BLACK%^r%^BLUE%^m c%^BLACK%^l%^WHITE%^o%^BLACK%^u%^BLUE%^d %^BLACK%^appears over "+who->QCN+"'s head, %^YELLOW%^f%^WHITE%^l%^RESET%^%^ORANGE%^i%^WHITE%^c%^YELLOW%^k%^WHITE%^e%^RESET%^%^ORANGE%^r%^WHITE%^i%^YELLOW%^n%^WHITE%^g %^BLACK%^with lightning. %^YELLOW%^B%^RESET%^%^ORANGE%^Z%^YELLOW%^ZT!%^RESET%^",({ETO,who}));
	tell_object(ETO,"%^BOLD%^%^BLACK%^A little %^BLUE%^s%^BLACK%^t%^WHITE%^o%^BLACK%^r%^BLUE%^m c%^BLACK%^l%^WHITE%^o%^BLACK%^u%^BLUE%^d %^BLACK%^appears over "+who->QCN+"'s head, %^YELLOW%^f%^WHITE%^l%^RESET%^%^ORANGE%^i%^WHITE%^c%^YELLOW%^k%^WHITE%^e%^RESET%^%^ORANGE%^r%^WHITE%^i%^YELLOW%^n%^WHITE%^g %^BLACK%^with lightning. %^YELLOW%^B%^RESET%^%^ORANGE%^Z%^YELLOW%^ZT!%^RESET%^");
	tell_object(who,"%^BOLD%^%^BLACK%^A little %^BLUE%^s%^BLACK%^t%^WHITE%^o%^BLACK%^r%^BLUE%^m c%^BLACK%^l%^WHITE%^o%^BLACK%^u%^BLUE%^d %^BLACK%^appears over your head, %^YELLOW%^f%^WHITE%^l%^RESET%^%^ORANGE%^i%^WHITE%^c%^YELLOW%^k%^WHITE%^e%^RESET%^%^ORANGE%^r%^WHITE%^i%^YELLOW%^n%^WHITE%^g %^BLACK%^with lightning. %^YELLOW%^B%^RESET%^%^ORANGE%^Z%^YELLOW%^ZT!%^RESET%^");
	}
}