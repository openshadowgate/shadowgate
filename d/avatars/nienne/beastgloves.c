#include <std.h>
inherit ARMOUR;

int keeper;
object claw1,claw2;

void create() {
   ::create();
   set_name("rugged gloves");
   set_short("%^RESET%^%^ORANGE%^Fer%^WHITE%^a%^ORANGE%^l Paws of the Be%^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^st%^RESET%^");
   set_obvious_short("%^RESET%^%^ORANGE%^rugged hide gloves%^RESET%^");
   set_id(({"gloves","hide gloves","rugged gloves","rugged hide gloves","paws","paws of the beast","beast paws","feral paws","feral paws of the beast"}));
   set_long("%^GREEN%^These rather bulky gloves are, at a closer look, surprisingly well made - if there are "
"any stitches or seams upon them, they are so well hidden as to be unnoticable.  %^ORANGE%^Thick leather "
"%^GREEN%^has been used to make them, so well prepared that it almost feels like living hide.  The inner "
"surface is smooth, and shaped to fit snugly, while the outside has been left covered with a thick coat of "
"%^ORANGE%^shaggy russet fur%^GREEN%^, resembling that of some %^RED%^wild beast%^GREEN%^.  Extra thickened "
"pads have been added to the palm and fingers of each, perhaps for further protection for the hands, or "
"only to further the already strong similarity that the gloves show to an animal's paws.%^RESET%^\n");
   set_weight(5);
   set_value(1025);
   set_ac(0);
   set_type("clothing");
   set_limbs(({"left hand","right hand"}));
   set_lore("%^BOLD%^%^WHITE%^One of the popular legends among the church of the Beastlord follows the tale of "
"Nalresh, a half-orcish shaman.  He was greatly famed and feared in his time, particularly in the lands "
"southeast of Tharis, which were said to be his favored hunting grounds.  One of the more prominent tales "
"recounts his hunt of many days against the great lion Aiyek'sha, whom he finally tracked down and slew "
"barehanded.  For his dedication to the hunt, the legend tells that Malar granted Nalresh the lion's own paws "
"as his own, granting him the strength and fury of the beast.  Or so the tales say.%^RESET%^\n");
   set_property("lore difficulty",9);
   while((int)TO->query_property("enchantment") != 1) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",1);
   }
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
   keeper = 0;
}

void init(){
    ::init();
    if(!objectp(TP)) return;
    if(!objectp(ETO)) return;
    if(TP != ETO) return;
    if(interactive(TP) && !avatarp(TP)) { set_size(TP->query_size()); }
    add_action("activate_fun","activate");
}

int wear_fun() {
/*   if((string)TP->query_diety() != "malar") {
     tell_object(ETO,"%^ORANGE%^The gloves don't seem to fit you.%^RESET%^");
     tell_room(EETO,"%^ORANGE%^The gloves don't seem to fit "+ETO->QCN+".%^RESET%^",ETO);
     return 0;
   } */
   tell_object(ETO,"%^ORANGE%^As you slide the gloves on, an odd thought touches your mind to %^GREEN%^activate"
"%^ORANGE%^ them.%^RESET%^");
   tell_room(EETO,"%^ORANGE%^"+ETO->QCN+" slides the gloves over "+ETO->QP+" hands and clenches "+ETO->QP+
" fists.%^RESET%^",ETO);
   return 1;
}

int remove_fun() {
   if(!keeper) {
     tell_object(ETO,"%^ORANGE%^You remove the gloves, knowing it will soon come time again to return to the "
"%^RED%^hunt%^ORANGE%^.%^RESET%^");
     tell_room(EETO,"%^ORANGE%^"+ETO->QCN+" removes the gloves with a predatory smile.%^RESET%^",ETO);
   }
   else {
     keeper = 0;
     tell_object(ETO,"%^ORANGE%^The %^WHITE%^claws%^ORANGE%^ slide away as you remove the gloves.%^RESET%^");
     tell_room(EETO,"%^ORANGE%^The %^WHITE%^claws%^ORANGE%^ slide away as "+ETO->QCN+" removes the gloves"
".%^RESET%^",ETO);
     if(objectp(claw1)) { claw1->__ActuallyUnwield(); }
   }
   return 1;
}

int activate_fun(string str) {
   object ob,*names;
   int i;
   if (!str) {
     notify_fail("Activate what?\n");
     return 0;
   }
   if (member_array(str,TO->query_id()) == -1) {
     notify_fail("Nothing happens.\n");
     return 0;
   }
   if (!TO->query_worn()) {
     notify_fail("You feel you should be wearing the gloves before you try that.\n");
     return 0;
   }
   if(ETO->query_lowest_level() < 20) {
     notify_fail("Nothing happens.");
     return 0;
   }
   if(keeper > 0) {
     notify_fail("You sense that they are already active.");
     return 0;
   }
   if(sizeof(TP->query_wielded()) > 0) {
     notify_fail("You feel the need to empty your hands first...");
     return 0;
   }
   tell_object(ETO,"%^ORANGE%^A snarl escapes your lips as you will the gloves to activate, and a pair of "
"%^WHITE%^razor-sharp claws %^ORANGE%^spring forth over the top of your hands!%^RESET%^");
   tell_room(EETO,"%^ORANGE%^"+ETO->QCN+" snarls fiercely, as a pair of %^WHITE%^razor-sharp claws%^ORANGE%^ "
"spring forth over the top of "+ETO->QP+" gloved hands!%^RESET%^",ETO);
   claw1 = new("/d/avatars/nienne/beastclaws");
   claw1->move(ETO);
   while((int)claw1->query_property("enchantment") != 4) {
     claw1->remove_property("enchantment");
     claw1->set_property("enchantment",4);
   }
   if (TO->query_identified()) {
     names = TO->query_identified();
     for (i=0;i<sizeof(names);i++) {
       claw1->add_identified(names[i]);
     }
   }
   ETO->force_me("wield beastclaw");
   claw2 = new("/d/avatars/nienne/beastclaws");
   claw2->move(ETO);
   while((int)claw2->query_property("enchantment") != 4) {
     claw2->remove_property("enchantment");
     claw2->set_property("enchantment",4);
   }
   if (TO->query_identified()) {
     names = TO->query_identified();
     for (i=0;i<sizeof(names);i++) {
       claw2->add_identified(names[i]);
     }
   }
   ETO->force_me("wield beastclaw");
   claw1->set_claw(claw2);
   claw2->set_claw(claw1);
   claw1->set_glove(TO);
   claw2->set_glove(TO);
   ETO->set_property("magic",1);
   keeper = 1;
   return 1;
}

void do_reset() { keeper = 0; }
int query_status() { return keeper; }
