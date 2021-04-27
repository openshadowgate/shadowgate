#include <std.h>
inherit ARMOUR;

int tracker;

void create() {
   ::create();
   set_name("mithril necklace");
   set_id(({"necklace","mithril necklace","delicate necklace","delicate mithril necklace"}));
   set_short("%^RESET%^%^GREEN%^Ver%^BOLD%^da%^RESET%^%^GREEN%^nt Em%^MAGENTA%^br%^GREEN%^ace%^RESET%^");
   set_obvious_short("%^RESET%^%^GREEN%^a delicate %^CYAN%^mith%^WHITE%^r%^CYAN%^il %^GREEN%^necklace%^RESET%^");
   set_long("%^ORANGE%^Shaped from %^BOLD%^%^WHITE%^mith%^YELLOW%^r%^WHITE%^il%^RESET%^%^ORANGE%^, this "
"delicate necklace has been treated and polished to give a %^BOLD%^%^WHITE%^br%^RESET%^il%^BOLD%^%^WHITE%^"
"liant whi%^YELLOW%^t%^WHITE%^e %^RESET%^%^ORANGE%^shine that reflects its surroundings like a mirror.  It "
"seems to have originally consisted of several strands of the metal, which have been interwoven in a complex "
"%^MAGENTA%^da%^RED%^nc%^MAGENTA%^e %^ORANGE%^to form the resulting jewelry.  Each is made in the image of a "
"%^GREEN%^vi%^ORANGE%^n%^GREEN%^e%^ORANGE%^, with creeping tendrils winding their way down its length and "
"snaking around the metallic %^BOLD%^%^GREEN%^l%^RESET%^%^GREEN%^eav%^BOLD%^es %^RESET%^%^ORANGE%^that "
"occasionally reach outward from the shining stems.  At the front, the strands of the necklace dip forward to "
"meet together in the middle, where a single mithril %^MAGENTA%^orchid b%^BOLD%^lo%^RESET%^%^MAGENTA%^ssom "
"%^ORANGE%^spreads its petals.  No gemstones or decorations have been inset into the metal, but each leaf, "
"vine and petal has been tinted with an odd glittering substance that adds a faint sheen of color to the "
"metal.  It gives a %^GREEN%^pale e%^BOLD%^m%^RESET%^%^GREEN%^erald g%^YELLOW%^l%^RESET%^%^GREEN%^ow %^ORANGE%^"
"to the leaves and tendrils, like a hint of life breathed into the otherwise %^RESET%^ine%^BOLD%^%^BLACK%^r"
"%^RESET%^t metal%^ORANGE%^, and the orchid has been tinted with a %^RED%^dusky ro%^MAGENTA%^s%^RED%^e "
"%^ORANGE%^shade, like the blush of health on a living flower.  The subtle effect only adds to the jewelry's "
"already delicate, yet stunning appearance, and you wonder at the crafting that must have gone into such a "
"piece.\n%^RESET%^");
   set_lore("Such an item could only be the work of elvenkind, renowned for their artistry in all of their "
"craftwork.  While mithril is usually the domain of the dwarves, it is less known that the elves are equally "
"skilled at its working, they only choose to use it differently.  The metal is often worked into armor and "
"jewelry, and each piece is a mastery of artwork and crafting, often taking years to make only a single "
"piece.  They often echo natural themes that the elves hold dear, such as animals and plants.");
   set_property("lore",12);
   set_value(20000);
   set_property("enchantment",3);
   set_item_bonus("empowered",1);
   set_weight(5);
   set_ac(0);
   set_type("clothing");
   set_limbs(({"neck"}));
   set_size(2);
   set_wear((:TO,"wearme":));
   set_remove((:TO,"removeme":));
   tracker = 0;
}

int wearme() {
   if((string)ETO->query_name() != "illusen" && (string)ETO->query_name() != "narylfiel" && !avatarp(ETO)) {
     tell_object(ETO,"%^BOLD%^%^WHITE%^The necklace is obviously not designed to fit one such as "
"you.%^RESET%^");
     tell_room(EETO,"%^BOLD%^%^WHITE%^The necklace was obviously designed for someone other than "
+ETO->QCN+"%^BOLD%^%^WHITE%^, as it simply does not fit "+ETO->QO+".%^RESET%^",ETO);
     return 0;
   }
   tell_object(ETO,"%^BOLD%^%^WHITE%^The necklace sparkles as you settle it around your neck, and you're sure "
"for a second that it seemed almost alive.%^RESET%^");
   tell_room(EETO,"%^BOLD%^%^WHITE%^The necklace sparkles as "+ETO->QCN+" %^BOLD%^%^WHITE%^settles it around "
+ETO->QP+" neck, and you're sure for a second that it seemed almost alive.%^RESET%^",ETO);
   ETO->set_property("good item",1);
   return 1;
}

int removeme() {
   tell_object(ETO,"%^BOLD%^%^WHITE%^You already miss the light touch of the beautiful necklace.%^RESET%^");
   ETO->set_property("good item",-1);
   return 1;
}

void init() {
   ::init();
   add_action("healem","healme");
}

int healem(string str){
   if(TP->query_bound() || TP->query_unconscious()){
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   if(!TO->query_worn()) {
     tell_object(TP,"You must be wearing the necklace to activate it.");
     return 1;
   }
   if(str) {
     tell_object(TP,"Just <healme> to activate the necklace.");
     return 1;
   }
   if(tracker > time()) {
     tell_object(TP,"The necklace is still recharging for another use.");
     return 1;
   }
   tracker = time() + 28800;
   new("/cmds/priest/_heal")->use_spell(TP,TP->query_name(),30);
   return 1;
}

void resetme() { tracker = 0; }
