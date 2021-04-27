#include <std.h>
inherit ARMOUR;

void create(){
        ::create();
        set_name("");
        set_id(({ "bracers", "ribbon tied bracers", "sparrows song" }));
        set_short("%^BLACK%^%^BOLD%^Spa%^RESET%^%^MAGENTA%^r"+
		"%^BLACK%^%^BOLD%^rows So%^RESET%^%^RED%^n"+
		"%^BLACK%^%^BOLD%^g%^RESET%^");
        set_obvious_short("%^BLACK%^%^BOLD%^ri%^RESET%^%^RED%^bb%^RESET%^%^MAGENTA%^"+
		"o%^BLACK%^%^BOLD%^n ti%^RESET%^%^RED%^e%^BLACK%^%^BOLD%^d b"+
		"r%^RESET%^%^MAGENTA%^a%^BOLD%^c%^BLACK%^%^BOLD%^ers%^RESET%^");
        set_long("%^RESET%^These bracers are a spectacular work of art, "+
		"obviously made by a master armorsmith. Forged from %^BOLD%^silver%^RESET%^, "+
		"they have been e%^BLACK%^%^BOLD%^ngr%^BLACK%^%^BOLD%^a%^RESET%^ved with a "+
		"series of et%^BLACK%^%^BOLD%^c%^RESET%^hings of %^BLACK%^%^BOLD%^wolves%^RESET%^ "+
		"and %^RESET%^%^ORANGE%^sparrows%^RESET%^ that flow over the entire surface. The "+
		"lifelikeness in the work is extraordinary and you swear you can see the animals "+
		"move places sometimes in an ever flowing scene. The bracers attach with "+
		"two %^BOLD%^silver clasps%^RESET%^ and %^BOLD%^white leather straps%^RESET%^. "+
		"A brace of %^MAGENTA%^purple%^RESET%^, %^RED%^red%^RESET%^ "+
		"and %^BLACK%^%^BOLD%^black%^RESET%^ ribbons hang from each bracer.");
        set_weight(13);
        set_value(1000);
        set_lore("%^BLACK%^%^BOLD%^These bracers were made by the armorsmith "+
		"Kiervalan Telkaror, known as Lord Wolf, though the reasons why are "+
		"unknown. What is known is that after creating them, they were blessed "+
		"by both Talos and Tymora, quite the feat considering the relations "+
		"those faiths have at times. It was rumored that the cost of the "+
		"blessing by Tymora was quite personal to the Lord Wolf, though no "+
		"one will ever ask what it was.");
        set_property("lore difficulty",23);
        set_type("bracer");
        set_limbs(({ "torso" }));
        set_size(1);
        set_property("enchantment",5);
        set_ac(1);
        set_wear((:TO,"wear_func":));
        set_remove((:TO,"remove_func":));
}
int wear_func(){
        tell_room(environment(ETO),"",ETO);
        tell_object(ETO,"%^BLACK%^%^BOLD%^As you slip the "+query_short()+"%^BLACK%^%^BOLD%^ "+
		"bracers on, you swear you hear a child laughing somewhere softly.%^RESET%^");
        ETO->set_property("magic resistance",10);
        return 1;
}
int remove_func(){
        tell_room(environment(ETO),"",ETO);

        tell_object(ETO,"%^BLACK%^%^BOLD%^You carefully arrange the ribbons as you remove "+
		"the "+query_short()+"%^BLACK%^%^BOLD%^.%^RESET%^");
        ETO->set_property("magic resistance",-10);
        return 1;
}
