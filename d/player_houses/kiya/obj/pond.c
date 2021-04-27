#include <std.h>
inherit "/d/magic/obj/mirror.c";

create() {
   ::create();
   set_name("mirror");
   set_id(({"mirror","pond","pool","spring"}));
   set_short("");
   set_property("no animate", 1);
   set_long((:TO,"spring_desc":));
   set("value", 1001);
   set_weight(100000);
   set_no_clean(1);
   set_heart_beat(1);
}

int get() { return 0; }
int drop() { return 1; }

string spring_desc(){
   if(TO->query_property("magic mirror")) {
     if (season(time()) == "winter") {
       return("%^GREEN%^A small, %^CYAN%^%^BOLD%^icy-c%^WHITE%^o%^CYAN%^ld%^RESET%^%^GREEN%^ spring bubbles "
"up from within the rocky mountainside, forming a pool of water where it reaches the forest floor.  The "
"pool itself is partially frozen, but there are still a few holes through which you can see the water "
"beneath.  Long, slender %^BOLD%^reeds%^RESET%^%^GREEN%^ have grown up around the pool, draping their "
"leaves out over its clear surface.  A %^CYAN%^gently glowing aura%^GREEN%^ is present across the pool's icy "
"surface.%^RESET%^");
       }
     return("%^GREEN%^A small, %^CYAN%^%^BOLD%^icy-c%^WHITE%^o%^CYAN%^ld%^RESET%^%^GREEN%^ spring bubbles "
"up from within the rocky mountainside, forming a pool of water where it reaches the forest floor.  Long, "
"slender %^BOLD%^reeds%^RESET%^%^GREEN%^ have grown up around the pool, draping their leaves out over its "
"clear surface.  A %^CYAN%^gently glowing aura%^GREEN%^ is present across the pool's rippling "
"surface.%^RESET%^");
   }
   if(((int)TP->query_skill("spellcraft")+roll_dice(1,20)) > 40) { //very high DC check to realise the pond can scry
     if (season(time()) == "winter") {
       return("%^GREEN%^A small, %^CYAN%^%^BOLD%^icy-c%^WHITE%^o%^CYAN%^ld%^RESET%^%^GREEN%^ spring bubbles "
"up from within the rocky mountainside, forming a pool of water where it reaches the forest floor.  The "
"pool itself is partially frozen, but there are still a few holes through which you can see the water "
"beneath.  Long, slender %^BOLD%^reeds%^RESET%^%^GREEN%^ have grown up around the pool, draping their "
"leaves out over its clear surface.  The surface of the pond is so clear, you suspect it could be used "
"as a focus for arcane scrying attempts.%^RESET%^");
     }
     return("%^GREEN%^A small, %^CYAN%^%^BOLD%^icy-c%^WHITE%^o%^CYAN%^ld%^RESET%^%^GREEN%^ spring bubbles "
"up from within the rocky mountainside, forming a pool of water where it reaches the forest floor.  Long, "
"slender %^BOLD%^reeds%^RESET%^%^GREEN%^ have grown up around the pool, draping their leaves out over its "
"clear surface.  The surface of the pond is so clear, you suspect it could be used as a focus for arcane "
"scrying attempts.%^RESET%^");
   }
   if (season(time()) == "winter") {
     return("%^GREEN%^A small, %^CYAN%^%^BOLD%^icy-c%^WHITE%^o%^CYAN%^ld%^RESET%^%^GREEN%^ spring bubbles "
"up from within the rocky mountainside, forming a pool of water where it reaches the forest floor.  The "
"pool itself is partially frozen, but there are still a few holes through which you can see the water "
"beneath.  Long, slender %^BOLD%^reeds%^RESET%^%^GREEN%^ have grown up around the pool, draping their "
"leaves out over its clear surface.%^RESET%^");
   }
   return("%^GREEN%^A small, %^CYAN%^%^BOLD%^icy-c%^WHITE%^o%^CYAN%^ld%^RESET%^%^GREEN%^ spring bubbles "
"up from within the rocky mountainside, forming a pool of water where it reaches the forest floor.  Long, "
"slender %^BOLD%^reeds%^RESET%^%^GREEN%^ have grown up around the pool, draping their leaves out over its "
"clear surface.%^RESET%^");
}

void heart_beat() {
   if ((string)TO->query_short() != "") TO->set_short("");
}
