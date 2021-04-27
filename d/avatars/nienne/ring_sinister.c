#include <std.h>
inherit ARMOUR;

int tracker;

void create(){
   ::create();
   set_name("carved ring");
   set_id(({"ring","carved ring","obsidian ring","carved obsidian ring","ring of the sinister","Ring of the Sinister"}));
   set_short("%^BOLD%^%^BLACK%^Ri%^RESET%^%^MAGENTA%^n%^BOLD%^%^BLACK%^g of the Si%^RESET%^%^MAGENTA%^n%^BOLD%^%^BLACK%^is%^RESET%^t%^BOLD%^%^BLACK%^er%^RESET%^");
   set_obvious_short("%^BOLD%^%^BLACK%^car%^RESET%^%^BLUE%^v%^BOLD%^%^BLACK%^ed obsid%^RESET%^i%^BOLD%^%^BLACK%^an ri%^RESET%^%^MAGENTA%^n%^BOLD%^%^BLACK%^g%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^Carved from a single piece of %^BOLD%^%^BLACK%^ob%^RESET%^%^BLUE%^s%^BOLD%^%^BLACK%^idi%^RESET%^%^MAGENTA%^a"
"%^BOLD%^%^BLACK%^n %^BOLD%^%^WHITE%^with its edges rubbed to a %^RESET%^%^MAGENTA%^sm%^RED%^oo%^MAGENTA%^th %^BOLD%^%^WHITE%^finish, this "
"ring is ornately etched to create a striking work of fine jewelry. Remarkably detailed carvings run the full circuit of its outer edge, "
"marking out a series of %^RESET%^%^CYAN%^w%^BOLD%^%^CYAN%^a%^BOLD%^%^WHITE%^v%^BOLD%^%^BLUE%^e%^RESET%^%^BLUE%^s%^BOLD%^%^WHITE%^ that "
"play about each other in a %^YELLOW%^ch%^BOLD%^%^RED%^a%^BOLD%^%^WHITE%^o%^YELLOW%^t%^BOLD%^%^CYAN%^i%^YELLOW%^c %^BOLD%^%^WHITE%^whorl. "
"In the centre is a widened face, upon which is carved the delicate image of a %^RESET%^%^CYAN%^sinister%^BOLD%^%^WHITE%^. A distinctive "
"glyph is marked upon the underside, perhaps the identifying mark of its crafter.%^RESET%^%^RESET%^\n");
   set_lore("This ring bears the fine, delicate patterning commonly found in drow craftsmanship. Given the distinctive glyph "
"upon the underside, this must be one of a series of rings created by Zilvanna Phaeraan, an accomplished magess of "
"Darol'dralych. The rings were an unusual experiment, warped and empowered from a series of beastman-crafted rings of similar "
"design. Underdark creatures were instead invoked by Zilvanna's creations, with the imbued arcane magic harnessing their "
"favored attributes. Only a handful are said to exist.\n\n"
"The particular image upon this ring is of a sinister, a creature equally admired and feared by the drow. Native telepaths, they bear a "
"natural forcefield that helps protect them from harm.\n");
   set_property("lore difficulty",30);
   set_type("ring");
   set_limbs(({"right hand","left hand"}));
   set_weight(1);
   set_size(-1);
   set_value(300);
   set_item_bonus("armor bonus",2);
   set_property("magic nonstacking",1); // these are magical equipment for the non-rop ring slot!
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
}

int isMagic(){ return 1; }

int wear_fun() {
   if((string)ETO->query_name() != "ketami" && !avatarp(ETO)) {
     tell_object(ETO,"The ring doesn't seem to fit you.");
     return 0;
   }
   tell_object(ETO,"%^CYAN%^As the ring slides onto your finger, the knowledge touches your mind that you can <contact playername> with it.%^RESET%^");
   return 1;
}

int remove_fun() { return 1; }

void init(){
   ::init();
   add_action("telepathy_fun","contact");
}

int telepathy_fun(string str) {
   if(!objectp(TO)) return 0;
   if(!objectp(ETO)) return 0;
   if(!str) {
     notify_fail("Who do you want to contact?\n");
     return 0;
   }
   if(!TO->query_worn()) {
     notify_fail("You have to wear the ring first.\n");
     return 0;
   }
   if(tracker > time()) {
     tell_object(TP,"The ring cannot be used again until an hour has passed.");
     return 1;
   }
   tracker = time() + 3600;
   tell_object(TP,"Your invoke the enchantment within the ring.");
   new("/cmds/spells/t/_telepathic_bond")->use_spell(ETO,str,25,100,"mage"); 
   return 1;
}

void resetme() { tracker = 0; }
