#include <std.h>
inherit NPC;
// Masquerade Ball Doorkeeper
// Nienne Installed-Fixed, Lurue Wrote - November 2008

#define SAVE_D "/daemon/save_d"

void create() {
::create();
set_property("no bump", 1);
set_name("doorkeeper");
set_id( ({"fey","fey doorkeeper","Fey","Fey Doorkeeper"}) );
set_short("Fey Doorkeeper");
set_long("%^BOLD%^%^WHITE%^This fairy like creature is draped in a gown of %^RESET%^pale white silk %^BOLD%^%^WHITE%^that "
"begins in a delicate bodice and drops down into a flowing multi tiered gown ribboned with %^BLACK%^black satin lace"
"%^WHITE%^. Wide ruffled cuffs nearly hide her delicate gloved hands, while the sweep of the chemise leaves her pale "
"shoulders bare. Masked in a butterfly shaped %^RESET%^white satin mask%^BOLD%^%^WHITE%^, studded with tiny %^BLACK%^onyx "
"beads%^WHITE%^. A choker of matching beads circles her delicate neck and %^BLACK%^g%^WHITE%^l%^RESET%^i%^BOLD%^%^BLACK%^"
"mm%^WHITE%^e%^BLACK%^rs%^WHITE%^ with the same opalescent shades as her diaphanous butterfly wings. Holding the sweep of "
"her %^BLACK%^jet black hair %^WHITE%^up and out of her face is a sweeping owl feather pin. Holding a small velvet lined "
"pouch, she accepts entry donations and hands out the masquerade rings and bags to attendees.%^RESET%^\n"
"%^YELLOW%^You could %^WHITE%^<buy male key>%^YELLOW%^ or %^WHITE%^<buy female key>%^YELLOW%^ from her, to gain access to "
"a changing room with a disguise. They will cost 1000 gold each.%^RESET%^\n");
set_gender("female");
set_alignment(5);
set("race","fairy");
set_level(15);
set("aggressive", 0);
set_hd(12,2);
set_max_hp(query_hp());
add_money("copper", random(20));
set_exp(1);
set_body_type("human");
set_spoken("wizish");
command("speech announce in a musical lilt");
}

void init() {
   ::init();
   add_action("get_key","buy");
}

int get_key(string str) {
   string *keyset, currentkey;
   int j;
   if(!str) return notify_fail("What do you want to buy?\n");
   if(str == "male key") {
     if(!(int)TP->query_funds("gold",2000)) {
       tell_object(TP,"The doorkeeper turns you away for lack of money. You will need 2000 gold for a key.");
       return 1;
     }
     keyset = ({});
     keyset = (string *)SAVE_D->query_array("male_masq_keys");
     if(!sizeof(keyset)) return notify_fail("There are no male keys left, sorry. Try <buy female key>.\n");
     currentkey = keyset[0];
     TP->use_funds("gold",2000);
     tell_object(TP,"The doorkeeper hands you a key for a male disguise.");
     SAVE_D->remove_name_from_array("male_masq_keys",currentkey);
     new(currentkey)->move(TP);
     return 1;
   }
   if (str == "female key") {
     if(!(int)TP->query_funds("gold",2000)) {
       tell_object(TP,"The doorkeeper turns you away for lack of money. You will need 2000 gold for a key.");
       return 1;
     }
     keyset = ({});
     keyset = (string *)SAVE_D->query_array("female_masq_keys");
     if(!sizeof(keyset)) return notify_fail("There are no female keys left, sorry. Try <buy male key>.\n");
     currentkey = keyset[0];
     TP->use_funds("gold",2000);
     tell_object(TP,"The doorkeeper hands you a key for a female disguise.");
     SAVE_D->remove_name_from_array("female_masq_keys",currentkey);
     new(currentkey)->move(TP);
     return 1;
   }
   return notify_fail("Syntax: <buy male key> or <buy female key>.\n");
}
