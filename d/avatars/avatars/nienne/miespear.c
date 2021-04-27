#include <std.h>
inherit "/d/common/obj/weapon/mspear";

object myamulet;

void create() {
   ::create();
   set_name("%^ORANGE%^wooden spear%^RESET%^");
   set_id(({"spear","miespear","wooden spear","etched spear","etched wooden spear","spire","spire of the forest warden","Spire of the Forest Warden"}));
   set_short("%^RESET%^%^RED%^Spi%^MAGENTA%^r%^RED%^e of the %^GREEN%^F%^CYAN%^o%^GREEN%^rest War%^CYAN%^d%^GREEN%^en%^RESET%^");
   set_obvious_short("%^RESET%^%^RED%^orn%^MAGENTA%^a%^RED%^te wooden spear%^RESET%^");
   set_long("This is one of the most unique weapons you've seen. The entire "
"spear is made of %^RED%^wood%^RESET%^, with no metal head - yet carved to "
"such a %^BOLD%^%^CYAN%^ke%^WHITE%^e%^CYAN%^n%^RESET%^ tip that it could only "
"be magically sharpened. The wood itself is of a beautiful %^RED%^deep "
"reddish tone%^RESET%^, with the grain running parallel to the spear's shaft. "
"What makes the weapon most outstanding, though, are the "
"%^MAGENTA%^el%^RED%^a%^MAGENTA%^bora%^RED%^t%^MAGENTA%^e%^RESET%^ etchings "
"from its base to the very tip, detailing all kinds of "
"%^ORANGE%^wi%^BOLD%^%^BLACK%^l%^RESET%^%^ORANGE%^d creatures%^RESET%^ "
"amongst a swirling trail of %^GREEN%^lea%^BOLD%^v%^RESET%^%^GREEN%^es "
"%^RESET%^and %^BOLD%^%^GREEN%^vines %^RESET%^that run the length of the "
"wood. They are so %^MAGENTA%^i%^RED%^n%^MAGENTA%^tric%^RED%^a%^MAGENTA%^tely "
"%^RESET%^carved that, were the spear not so unnaturally sturdy, you would "
"fear that using the spear in combat would easily ruin them. A few "
"%^CYAN%^br%^GREEN%^il%^YELLOW%^li%^RESET%^%^ORANGE%^an%^RED%^t-%^MAGENTA%^hu"
"%^BLUE%^ed %^RESET%^feathers from some unknown bird have been secured near "
"the tip of the spear, giving the weapon somewhat of a tribal appearance.\n");
   set_wc(1,8);
   set_value(0);
   set_property("enchantment",5);
   set_weapon_speed(5);
//   set_hit((:TO,"hit_fun":));
}

void set_amulet(object ob1) { myamulet = ob1; }

/*void __ActuallyUnwield() {
   ::__ActuallyUnwield();
   if(objectp(myamulet)) {
     if((int)myamulet->query_status()) { myamulet->do_reset(); }
   }
   tell_room(ETO,"%^ORANGE%^The spear shimmers and disappears!%^RESET%^");
   TO->remove();
} */
