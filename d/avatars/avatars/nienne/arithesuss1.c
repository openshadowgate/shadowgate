#include <std.h>
inherit "/d/common/obj/weapon/shortsword";

void create(){
	::create();
	set_name("arithesuss");
	set_id(({ "sword", "shortsword", "arithesuss" }));
	set_short("%^BOLD%^%^GREEN%^<%^RESET%^%^GREEN%^+%^BOLD%^%^GREEN%^}%^RESET%^%^ORANGE%^-%^BOLD%^%^WHITE%^ARITHESUSS%^RESET%^%^ORANGE%^-%^BOLD%^%^GREEN%^{%^RESET%^%^GREEN%^+%^BOLD%^%^GREEN%^>%^RESET%^");
      set_obvious_short("%^BOLD%^%^WHITE%^A finely crafted a%^RESET%^%^WHITE%^da%^BOLD%^ma%^RESET%^%^WHITE%^n%^BOLD%^%^BLACK%^t%^RESET%^i%^BOLD%^um shortsword%^RESET%^");
	set_long("%^RESET%^%^WHITE%^This short sword is of a fine craft. The blade is double edged and %^BOLD%^%^RED%^vi%^RESET%^%^RED%^ci%^BOLD%^%^BLACK%^o%^RESET%^%^RED%^us%^BOLD%^%^RED%^ly%^RESET%^%^WHITE%^ sharp. T"
	"he blade is heavily %^CYAN%^pol%^BOLD%^%^CYAN%^ish%^WHITE%^ed%^RESET%^%^WHITE%^, so much so that any%^YELLOW%^ light%^RESET%^%^WHITE%^ that touches the blade is reflected back perfectly. The blade could"
	" almost function as a mirror, save the sublet curve of it warps any image slightly. The hilt is made of a polished %^BOLD%^%^WHITE%^silver%^RESET%^%^WHITE%^ and wrapped in a %^ORANGE%^deep brown %^RED"
	"%^l%^ORANGE%^e%^RED%^a%^ORANGE%^t%^RED%^h%^ORANGE%^e%^RED%^r%^RESET%^%^WHITE%^. The pommel is shaped like a leaf of a %^RED%^m%^GREEN%^a%^ORANGE%^p%^RED%^l%^GREEN%^e %^BOLD%^%^GREEN%^tree%^RESET%^%^WH"
	"ITE%^ and cut elaborately with the veins of such a leaf. %^BOLD%^%^GREEN%^E%^RESET%^%^GREEN%^l%^BOLD%^%^GREEN%^v%^RESET%^%^GREEN%^e%^BOLD%^%^GREEN%^n%^RESET%^%^WHITE%^ characters have been etched into"
	" the %^BOLD%^%^WHITE%^silver%^RESET%^%^WHITE%^ hilt reading, %^BOLD%^%^GREEN%^'%^RESET%^%^GREEN%^ARITHESUSS%^BOLD%^%^GREEN%^'%^RESET%^%^WHITE%^. This is believed to be the blades name.%^RESET%^\n"
	);
	set_value(235);
      set_hit((:TO,"hit_func":));
      set_property("enchantment",1);
      while(query_property("enchantment") != 1){
        remove_property("enchantment");
        set_property("enchantment",1);
      }
      set_lore("This stunning blade was crafted in the year 696SG by the elven scout Aellyon, and blessed with minor "
"enchantments from the lives of two fey he aided to free from the grasp of Yuan-ti.");
}

int hit_func(object targ){
   if(!objectp(TO)) return 1;
   if(!objectp(ETO)) return 1;
   if(!objectp(targ)) return 1;
   targ = ETO->query_current_attacker();
   if(random(1000) < 150){
      tell_room(EETO,"%^BOLD%^%^WHITE%^Droplets of blood follow the arc of "+ETOQCN+"'s blade as it slashes %^BOLD%^%^RED%^vi%^RESET%^%^RED%^ci%^BOLD%^%^BLACK%^o%^RESET%^%^RED%^us%^BOLD%^%^RED%^ly%^BOLD%^%^WHITE%^ through "+targ->QCN+"'s skin!%^RESET%^",({ETO,targ}));
      tell_object(ETO,"%^BOLD%^%^WHITE%^Droplets of blood follow the arc of your blade as it slashes %^BOLD%^%^RED%^vi%^RESET%^%^RED%^ci%^BOLD%^%^BLACK%^o%^RESET%^%^RED%^us%^BOLD%^%^RED%^ly%^BOLD%^%^WHITE%^ through "+targ->QCN+"'s skin!%^RESET%^");
      tell_object(targ,"%^BOLD%^%^WHITE%^Droplets of blood follow the arc of "+ETOQCN+"'s blade as it slashes %^BOLD%^%^RED%^vi%^RESET%^%^RED%^ci%^BOLD%^%^BLACK%^o%^RESET%^%^RED%^us%^BOLD%^%^RED%^ly%^BOLD%^%^WHITE%^ through your skin!%^RESET%^");
      set_property("magic",1);
      targ->do_damage(targ->return_target_limb(),(random(20)+10));
      remove_property("magic");
   }
   return 1;
}