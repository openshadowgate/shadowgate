#include <std.h>
inherit "/d/common/obj/jewelry/ring";
int FeatFlag;

void create(){
	::create();
	set_name("Ring of Venom Immunity");
	set_id(({ "ring", "ceramic ring", "ring of venom immunity", "engraved ring" }));
	set_short("%^RESET%^%^BOLD%^Ring of %^GREEN%^V%^RESET%^%^GREEN%^e%^BOLD%^n%^RESET%^%^GREEN%^o%^BOLD%^m I%^RESET%^%^GREEN%^m%^BOLD%^m%^RESET%^%^GREEN%^u%^BOLD%^%^CYAN%^n%^GREEN%^i%^RESET%^%^GREEN%^t%^BOLD%^y%^RESET%^");
	set_obvious_short("%^RESET%^%^BOLD%^an %^RESET%^%^GREEN%^e%^BOLD%^n%^RESET%^%^GREEN%^g%^BOLD%^r%^CYAN%^a%^RESET%^%^GREEN%^v%^BOLD%^e%^RESET%^%^GREEN%^d %^BOLD%^%^WHITE%^ceramic ring%^RESET%^");
	set_long("%^BOLD%^This smooth ceramic ring is an o%^RESET%^%^ORANGE%^f%^BOLD%^%^WHITE%^f-w%^RESET%^h%^ORANGE%^i%^WHITE%^t%^BOLD%^e in color, and is polished to a bright %^BLACK%^s%^RESET%^h%^BOLD%^e%^RESET%^e%^"
	"BOLD%^%^BLACK%^n%^WHITE%^. It bears the engraving of a %^RESET%^%^GREEN%^s%^CYAN%^e%^GREEN%^r%^CYAN%^p%^GREEN%^e%^CYAN%^n%^GREEN%^t%^BOLD%^%^WHITE%^, inlaid with %^RESET%^%^GREEN%^r%^BOLD%^i%^RESET%^%"
	"^GREEN%^ch g%^BOLD%^r%^RESET%^%^GREEN%^e%^BOLD%^e%^RESET%^%^GREEN%^n s%^BOLD%^t%^RESET%^%^GREEN%^o%^BOLD%^n%^RESET%^%^GREEN%^e%^BOLD%^%^WHITE%^, that coils around the length of the ring, its jaws unhi"
	"nged and bearing two sharp-looking %^BLACK%^fangs%^WHITE%^. Something, likely some form of enchantment, seems to ward this delicate ring from damage, and it remains just slightly %^RESET%^%^RED%^warm "
	"%^BOLD%^%^WHITE%^to the touch at all times.%^RESET%^
"	);
	set_value(10000);
	set_lore("%^BOLD%^The origin of these rings has been lost to history, though over the years the magic contained within has been successfully replicated by spellcasters of multiple disciplines. This Ring of Veno"
	"m Immunity is imbued with a spell of purification that attunes with the blood of the wearer, rendering them immune to standard poisons, as well as lending an increased resistance to most corrosive eff"
	"ects.
"	);
	set_property("lore difficulty",15);
	set_size(2);
	set_property("enchantment",0);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
    set_item_bonus("acid resistance", 10);
}

int wear_func(){
	tell_room(environment(ETO),"%^BOLD%^The %^RESET%^%^GREEN%^serpent %^BOLD%^%^WHITE%^upon the band %^BLACK%^d%^RESET%^%^GREEN%^a%^BOLD%^%^BLACK%^r%^RESET%^%^GREEN%^k%^BOLD%^%^BLACK%^e%^RESET%^%^GREEN%^n%^BOLD%^%^BLACK%^s %^WHITE%^as "+ETOQCN+" slips on the ceramic ring.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^The %^RESET%^%^GREEN%^serpent %^BOLD%^%^WHITE%^upon the band %^BLACK%^d%^RESET%^%^GREEN%^a%^BOLD%^%^BLACK%^r%^RESET%^%^GREEN%^k%^BOLD%^%^BLACK%^e%^RESET%^%^GREEN%^n%^BOLD%^%^BLACK%^s %^WHITE%^as you slip on the ceramic ring, and you feel a faint %^RED%^w%^RESET%^%^ORANGE%^a%^MAGENTA%^r%^RED%^m%^ORANGE%^t%^BOLD%^%^RED%^h %^WHITE%^run through your veins.%^RESET%^");
    if(member_array("venom immunity",(string*)ETO->query_temporary_feats()) == -1) 
    {
        ETO->add_temporary_feat("venom immunity");
        FeatFlag = 1;
    }
	return 1;
}

int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^"+ETOQCN+" slips off the ceramic ring.",ETO);
	tell_object(ETO,"%^BOLD%^You slip off the ceramic ring, feeling just a bit %^RESET%^colder%^BOLD%^.%^RESET%^");
    
    if(FeatFlag) 
    {
        ETO->remove_temporary_feat("venom immunity");
        FeatFlag = 0;
    }
    
	return 1;
}

