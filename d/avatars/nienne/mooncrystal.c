#include <std.h>
#include <daemons.h>
inherit OBJECT;

int tracker, trackerb;

void create(){
   ::create();
   set_name("milky opal crystal");
   set_id(({"crystal","opal","milky opal","jagged crystal","milky opal crystal","shard","shard of lunar radiance"}));
   set_short("%^RESET%^%^CYAN%^Shard of %^BOLD%^%^WHITE%^L%^CYAN%^u%^WHITE%^nar Radi%^YELLOW%^a%^WHITE%^nce%^RESET%^");
   set_obvious_short("%^RESET%^%^CYAN%^a jagged crystal of %^RESET%^mi%^BOLD%^l%^RESET%^ky o%^CYAN%^p%^RESET%^al%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^This is a raw cut of %^RESET%^mi%^BOLD%^l%^RESET%^ky o%^CYAN%^p%^RESET%^al"
"%^BOLD%^%^BLACK%^, its pale color shot through with iridescent %^GREEN%^gr%^RESET%^%^GREEN%^ee%^BOLD%^n"
"%^BLACK%^, %^RED%^cr%^RESET%^%^RED%^i%^BOLD%^ms%^RESET%^%^RED%^o%^BOLD%^n %^BLACK%^and %^CYAN%^a%^RESET%^"
"%^CYAN%^z%^BOLD%^ure %^BLACK%^pinfire as light reflects off its crystalline edges.  Its edges remain jagged "
"and unpolished, as though it has remained in exactly the same shape as it was found.%^RESET%^");
   set_value(3400);
   set_lore("%^WHITE%^%^BOLD%^Many years ago, so the tales tell, a village existed on the outlying northern "
"borders of the Tsarven empire, near the city known as Azha.  The village, once peaceful, came under the "
"ravaging plague of an undead horde, and as one the villagers cried out for aid.  And aid came to them, "
"through the hands of a simple priest of Selune.  Alainn Daross was a young man, only recently arrived in the "
"village as a missionary, spreading the word of his Lady across the lands.  As night fell and the undead "
"descended upon the town, he cried out for the aid of the Moon Maiden, and she offered her blessings upon him "
"in the form of a scepter.  It appeared in his hands as he stood in the moonlight, and filled with hope, he "
"raised it against the monsters before him.  A brilliant light burst forth from the weapon, falling upon "
"undead and human alike, and the undead were shattered and fell to the ground.  Yet the villagers were "
"miraculously infused with healing, the slain among them returning to life, and the injured to wholeness.  "
"Never again did the creatures of darkness torment the village, and only the next day Alainn moved on with his "
"journey, and his tale is lost to history's pages.  But he left the scepter behind, and so it stayed within "
"the village, protected as a precious reminder of their salvation that night.%^RESET%^\n\n"
"Decades later, the scepter was lost to the clutches of a Maskarran, and woe fell upon the village.  It was "
"only through the efforts of two men of Selune, Xeranthos and Nhaernath, that the precious artifact was "
"restored to its rightful owners.  In a sign of Selune's favor, witnesses claimed the rod was infused with "
"radiance and split, with each gemstone coming free of the rod and appearing in the hands of those two favored "
"of the Moonmaiden - the crystal to Xeranthos, and the orb to Nhaernath.  The mithril rod remained protected "
"within the village, where it is said to reside to this day.  This is claimed to be that very same crystal "
"that once formed part of the rod, believed that when held in the right hands and under the light of the moon, "
"it could bestow the power of Selune herself to protect its bearer from harm.%^RESET%^");
   set_property("lore difficulty",22);
}

void init() {
   ::init();
   add_action("radiance_fun","invoke");
}

int radiance_fun(string str){
   object *myatk, mytarg;
   int mynum;
   if(TP->query_bound() || TP->query_unconscious()){
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   if(!str) {
     notify_fail("What do you want to invoke?\n");
     return 0;
   }
   if(str != "the crystal") {
     notify_fail("You can't invoke that.\n");
     return 0;
   }
   if((string)TP->query_name() != "xeranthos" && !avatarp(TP)) {
     notify_fail("You cannot figure out how to use this.\n");
     return 0;
   }
   if((string)TP->query_diety() != "selune") {
     notify_fail("You invoke the powers of the crystal, but nothing happens.\n");
     return 0;
   }
   if((string)EVENTS_D->query_time_of_day() != "night") {
     notify_fail("You invoke the powers of the crystal, but nothing happens.\n");
     return 0;
   }
   if(!sizeof(TP->query_attackers())) {
     notify_fail("You are not under attack!\n");
     return 0;
   }
   myatk = TP->query_attackers();
   mynum = random(sizeof(myatk));
   mytarg = myatk[mynum];
   if(trackerb) {
     new("/d/avatars/nienne/amulet/_moonfire")->use_spell(TP,mytarg,30);
     trackerb--;
     if(!trackerb) tracker = time() + 14400;
     return 1;
   }
   if(tracker > time()) {
     notify_fail("The crystal is still recharging.\n");
     return 0;
   }
   new("/d/avatars/nienne/amulet/_moonfire")->use_spell(TP,mytarg,25);
   trackerb = 2;
   return 1;
}