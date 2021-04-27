#include <std.h>
inherit "/d/common/obj/weapon/longsword";

void create(){
	::create();
	set_name("a sword");
	set_id(({ "sword", "longsword", "mithril longsword", "telamus's blade" }));
	set_short("%^YELLOW%^T%^RESET%^%^ORANGE%^ela%^BOLD%^m%^RESET%^%^ORANGE%^us%^BOLD%^'%^RESET%^%^ORANGE%^s %^BOLD%^%^BLACK%^B%^RESET%^l%^BOLD%^a%^RESET%^d%^BOLD%^%^BLACK%^e%^RESET%^");
	set_obvious_short("%^BOLD%^%^GREEN%^A %^BLACK%^m%^RESET%^it%^BOLD%^h%^RESET%^ri%^BOLD%^%^BLACK%^l %^GREEN%^longsword%^RESET%^");
	set_long("%^RESET%^%^CYAN%^This longsword has been crafted of that rare silvery metal, %^BOLD%^%^BLACK%^m%^RESET%^it%^BOLD%^h%^RESET%^ri%^BOLD%^%^BLACK%^l%^RESET%^%^CYAN%^. Exquisite in its simplicity, the long"
	" thin blade flows into a simple crossbar hilt. The grip has been wound in cords of supple %^ORANGE%^leather%^CYAN%^. Along the flat of the blade, strange %^YELLOW%^r%^RESET%^%^ORANGE%^u%^BOLD%^n%^RESE"
	"T%^%^ORANGE%^e%^BOLD%^s %^RESET%^%^CYAN%^have been engraved.%^RESET%^
"
	);
	set_value(2500);
	set_lore("%^RESET%^%^CYAN%^This mithril blade was crafted for Zathery through the gratitude of Telamus Daherrin. It was due to the actions of Zathery that Telamus was able to establish his claim on a seam of mi"
	"thril within the Echoes Caverns, and permitted his rise within the Daherrin clan.%^RESET%^
"
	);
    set_property("lore difficulty",10);
	set_property("enchantment",2);
	set_hit((:TO,"hit_func":));
}



int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
        if(random(1000) < 100){
	tell_room(environment(query_wielded()),"%^RESET%^"+ETOQCN+" %^BOLD%^%^GREEN%^attacks quickly with %^RESET%^"+query_short()+"%^BOLD%^%^GREEN%^, slicing deep into "+targ->QCN+"!%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^RESET%^"+query_short()+" %^BOLD%^%^GREEN%^swings with ease, slicing cleanly through "+targ->QCN+"!%^RESET%^");
	tell_object(targ,"%^RESET%^"+ETOQCN+" %^BOLD%^%^GREEN%^brings %^RESET%^"+query_short()+" %^BOLD%^%^GREEN%^in a quick arc, slicing deeply into you!%^RESET%^");
		return roll_dice(3,4)+2;	}

}
