#include <std.h>
inherit ARMOUR;
int FLAG;

void create(){
	::create();
	set_name("wide brim hat");
	set_id(({ "hat", "wide brim hat", "wide brimmed gray", "wide brimmed gray hat" }));
	set_short("%^BOLD%^%^BLACK%^w%^WHITE%^i%^RESET%^d%^BOLD%^%^BLACK%^e b%^WHITE%^r%^RESET%^im%^BOLD%^%^WHITE%^m%^BLACK%^ed g%^WHITE%^r%^RESET%^a%^BOLD%^%^BLACK%^y%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^wide brimmed hat%^RESET%^");
	set_long("%^RESET%^This light gray hat is made up of closely woven strands of %^BOLD%^%^WHITE%^white"
"%^RESET%^, gray and %^BOLD%^%^BLACK%^black %^RESET%^wool that blends together into a soft %^BOLD%^%^BLACK%^c"
"%^WHITE%^l%^RESET%^ou%^WHITE%^%^BOLD%^d%^BLACK%^y g%^WHITE%^r%^RESET%^a%^BOLD%^%^BLACK%^y %^RESET%^coloring.  "
"A wide flexible brim provides protection for the face and sheds water off the collar instead of down one's "
"back.  In the sunlight, the brim provides a little %^BOLD%^%^BLACK%^shade %^RESET%^for the eyes, making it "
"easier to see, though the brim could be put up so that this shade isn't so intense.  A narrow strip of "
"%^ORANGE%^brown leather%^RESET%^, similar to the leather lining inside, wraps around the inner edge of the "
"brim, providing a little contrast as well as a place to secure a %^BOLD%^%^WHITE%^feather %^RESET%^or other "
"such %^ORANGE%^token%^RESET%^.  Depending on how the brim is folded, this semi-protective hat could be made "
"into almost any %^BOLD%^%^BLACK%^style %^RESET%^the wearer favored.");
	set_weight(3);
	set_value(500);
	set_lore("These soft, leather-lined woven hats were first worn by docksmen and other seafarers who "
"required a bit of protection from the sun as well as rain.  Though made of wool, the material breathes well, "
"and even when wet, stays warm, making it an all around useful item.  Though found in many styles, the 'wide "
"brimmed gray' as it was called, was the most popular by far.  Enough so that many sailors who found "
"themselves fighting pirates had their hats enchanted to provide as much protection in a fight as it did "
"against weather conditions.");
	set_property("lore difficulty",18);
	set_type("leather");
	set_limbs(({ "head" }));
	set_size(2);
	set_property("enchantment",2);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
      FLAG = 0;
}

int wear_func(){
	tell_room(EETO,"%^RESET%^%^ORANGE%^With a flick of their hair, "+ETOQCN+" sets their "+query_short()+" %^RESET%^%^ORANGE%^atop their head.%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^ORANGE%^With a flick of the hair, you set your "+query_short()+" %^RESET%^%^ORANGE%^atop your head.%^RESET%^");
	return 1;
}

int remove_func(){
      if(FLAG) {
        tell_object(ETO,"You start to remove the hat, and the brim lifts from your field of vision, allowing "
"you to see clearly again.");
        ETO->add_sight_bonus(3);
        FLAG = 0;
      }
	tell_room(EETO,"%^RESET%^%^ORANGE%^"+ETOQCN+" folds up and tucks away their "+query_short()+" %^RESET%^%^ORANGE%^after taking it off.%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^ORANGE%^You take the warm "+query_short()+" %^RESET%^%^ORANGE%^from your head and tuck it away.%^RESET%^");
	return 1;
}

void init() {
   ::init();
   add_action("dark_func","lower");
   add_action("light_func","lift");
}

int dark_func(string str) {
   if(!objectp(ETO)) return 0;
   if(!userp(ETO)) return 0;
   if(!str) {
     notify_fail("What do you want to lower?\n");
     return 0;
   }
   if(str != "hat" && str != "brim") {
     notify_fail("You could try <lower brim>.\n");
     return 0;
   }
   if(!TO->query_worn()) {
     notify_fail("You should wear the hat first.\n");
     return 0;
   }
   if(FLAG) {
     notify_fail("The brim is already down, any further and you wouldn't be able to see!\n");
     return 0;
   }
   tell_object(ETO,"You tilt the hat's brim down to shade your eyes.");
   tell_room(EETO,""+ETOQCN+" tilts the brim of "+ETO->QP+" hat down to shade "+ETO->QP+" eyes.",ETO);  
   ETO->add_sight_bonus(-3);
   FLAG = 1;
   return 1;
}

int light_func(string str) {
   if(!objectp(ETO)) return 0;
   if(!userp(ETO)) return 0;
   if(!str) {
     notify_fail("What do you want to lift?\n");
     return 0;
   }
   if(str != "hat" && str != "brim") {
     notify_fail("You could try <lower brim>.\n");
     return 0;
   }
   if(!FLAG) {
     notify_fail("You can already see just fine.\n");
     return 0;
   }
   tell_object(ETO,"You lift the brim of the hat back up, so you can see clearly.");
   tell_room(EETO,""+ETOQCN+" lifts the brim of "+ETO->QP+" hat back up to see clearly.",ETO);  
   ETO->add_sight_bonus(3);
   FLAG = 0;
   return 1;
}