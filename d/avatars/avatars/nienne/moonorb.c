#include <std.h>
#include <daemons.h>
inherit OBJECT;

int tracker, trackerb;

void create(){
   ::create();
   set_name("moonstone orb");
   set_id(({"moonstone orb","orb","orb of lunar radiance","gleaming orb","gleaming moonstone orb"}));
   set_short("%^RESET%^%^CYAN%^Orb of %^BOLD%^%^WHITE%^L%^CYAN%^u%^WHITE%^nar Radi%^YELLOW%^a%^WHITE%^nce%^RESET%^");
   set_obvious_short("%^RESET%^%^CYAN%^a %^BOLD%^%^WHITE%^gl%^YELLOW%^e%^WHITE%^aming moons%^RESET%^to%^BOLD%^ne%^RESET%^%^CYAN%^ orb%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^This is an orb of %^BOLD%^%^WHITE%^gl%^YELLOW%^e%^WHITE%^aming moons%^RESET%^to"
"%^BOLD%^ne%^BLACK%^, about the size of an egg.  The gemstone has been polished to perfection, revealing its distinct %^RESET%^%^CYAN%^bl%^BOLD%^u%^RESET%^%^CYAN%^e cha%^BOLD%^t%^RESET%^%^CYAN%^oya%^BOLD%^n%^RESET%^%^CYAN%^cy %^BOLD%^%^BLACK%^under light.  It is utterly flawless, without scratch or imperfection to mark its precisely spherical shape.%^RESET%^");
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
"within the village, where it is said to reside to this day.  This is claimed to be that very same orb "
"that once formed part of the rod, believed that when held in the right hands and under the light of the "
"moon, it could bestow the healing blessings of Selune herself.%^RESET%^");
   set_property("lore difficulty",22);
   set_property("no animate",1);
   tracker = 0;
   trackerb = 3;
}

void init() {
   ::init();
   add_action("radiance_fun","invoke");
}

int radiance_fun(string str){
   if(TP->query_bound() || TP->query_unconscious()){
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   if(!str) {
     notify_fail("What do you want to invoke?\n");
     return 0;
   }
   if(str != "the orb") {
     notify_fail("You can't invoke that.\n");
     return 0;
   }
   if(((int)TP->query_alignment() % 3) != 1) {
     notify_fail("You invoke the powers of the orb, but nothing happens.\n");
     return 0;
   }
   if((string)EVENTS_D->query_time_of_day() != "night") {
     notify_fail("You invoke the powers of the orb, but nothing happens.\n");
     return 0;
   }
   if(trackerb) {
     new("/d/avatars/nienne/amulet/_aura_of_radiance")->use_spell(TP,0,25);
     trackerb--;
     if(!trackerb) tracker = time() + 14400;
     return 1;
   }
   if(tracker > time()) {
     notify_fail("The orb is still recharging.\n");
     return 0;
   }
   new("/d/avatars/nienne/amulet/_aura_of_radiance")->use_spell(TP,0,30);
   trackerb = 2;
   return 1;
}

int isMagic() { return 1; }