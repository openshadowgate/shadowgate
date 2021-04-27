#include <std.h>
inherit "/d/common/obj/armour/hide";

int tracker;

void create() {
   ::create();
   set_name("mithril chainmail");
   set_id(({"chain","chainmail","elven chain","elven chainmail","mithril chain","mithril chainmail","suit of chain","suit","ornate suit","suit of chainmail","suit of mithril chainmail"}));
   set_short("%^RESET%^%^GREEN%^E%^BOLD%^lv%^RESET%^%^GREEN%^en Ch%^CYAN%^ai%^GREEN%^nma%^BOLD%^i%^RESET%^%^GREEN%^l%^RESET%^");
   set_obvious_short("%^RESET%^%^GREEN%^an %^GREEN%^o%^BOLD%^rn%^RESET%^%^GREEN%^ate %^GREEN%^suit of %^CYAN%^mith%^BOLD%^%^GREEN%^r%^RESET%^%^CYAN%^il %^GREEN%^chainmail%^RESET%^");
   set_long("%^RESET%^%^CYAN%^This breathtaking suit of chain is crafted of %^BOLD%^%^WHITE%^mith%^YELLOW%^r"
"%^WHITE%^il%^RESET%^%^CYAN%^, treated and polished to give a %^BOLD%^%^WHITE%^br%^RESET%^il%^BOLD%^%^WHITE%^"
"liant whi%^YELLOW%^t%^WHITE%^e shine %^RESET%^%^CYAN%^that reflects its surroundings like a mirror.  It seems "
"precisely shaped to fit a %^MAGENTA%^sl%^RED%^e%^MAGENTA%^nder %^CYAN%^frame, and would certainly not be tall "
"enough to fit a normal human.  A delicately fitted suit of %^ORANGE%^padding %^CYAN%^resides underneath the "
"armor itself, to protect the wearer from discomfort.  The armor itself is formed of countless %^BOLD%^"
"%^WHITE%^mith%^YELLOW%^r%^WHITE%^il%^RESET%^%^CYAN%^ links, so finely interlinked as to almost appear to be a "
"mesh rather than individual pieces.  They shape a full-sleeved shirt with a high collar to protect the neck, "
"and are adorned at throat, shoulder and wrist with elaborately shaped metal %^GREEN%^lea%^BOLD%^ve%^RESET%^"
"%^GREEN%^s %^CYAN%^with ragged edges.  Flowing further downwards, the chainmail forms a close-fitting layer "
"to shield the legs, with further matching %^GREEN%^fo%^BOLD%^li%^RESET%^%^GREEN%^age %^CYAN%^embossed at the "
"ankles.  This has been overlaid with a second layer from each hip formed of a few light metallic plates, that "
"fall downwards in a mirrored gesture of drooping %^GREEN%^lea%^BOLD%^ve%^RESET%^%^GREEN%^s%^CYAN%^.  The "
"suit gives a striking effect of being, at the same time, both %^RESET%^ine%^BOLD%^%^BLACK%^r%^RESET%^t "
"metal %^CYAN%^and %^RED%^living art%^BOLD%^wo%^RESET%^%^RED%^rk%^CYAN%^.  It could certainly be called "
"nothing short of %^BOLD%^ma%^BLUE%^g%^CYAN%^nifi%^GREEN%^c%^CYAN%^ent%^RESET%^%^CYAN%^, and undoubtably both "
"magic and a mastery of smithing had a hand in its creation.\n%^RESET%^");
   set_lore("Such armor could only be the work of elvenkind, and these suits are extremely rare, crafted by "
"their most skilled artisans and only given to those of high standing among their kin.  Most elves prefer the "
"lighter weight and easier movement that chainmail allows, as opposed to heavier armors such as platemail.  "
"These armor suits combine the greatest of smithcraft with the fine and delicate artwork that the elves are "
"famous for, and they are usually patterned in various natural themes that the elves so greatly treasure.  "
"Each suit is considered priceless among elvenkind, and many are passed down from one generation to the next "
"as cherished heirlooms.  Some sages believe that they are even imbued with secret elven magics, allowing "
"them to be worn and used with ease even by those usually accustomed to lighter forms of armor.");
   set_property("lore",12);
   set_value(20000);
   set_property("enchantment",4);
   set_ac(5);
   set_item_bonus("attack bonus",3);
   set_item_bonus("damage bonus",3);
   set_wear((:TO,"wearme":));
   set_remove((:TO,"removeme":));
   tracker = 0;
}

int wearme() {
   if((string)ETO->query_race() != "elf") {
     tell_object(ETO,"%^BOLD%^%^WHITE%^The beautiful chainmail is obviously not designed to fit one such as "
"you.%^RESET%^");
     tell_room(EETO,"%^BOLD%^%^WHITE%^The beautiful chainmail was obviously designed for someone other than "
+ETO->QCN+"%^BOLD%^%^WHITE%^, as it simply does not fit "+ETO->QO+".%^RESET%^",ETO);
     return 0;
   }
   tell_object(ETO,"%^BOLD%^%^WHITE%^The chainmail settles comfortably into place, as if it were made to fit "
"you. You remember that you can %^YELLOW%^<mark>%^WHITE%^ an enemy to secretly track them.%^RESET%^");
   tell_room(EETO,"%^BOLD%^%^WHITE%^The suit of chainmail settles into place around "+ETO->QCN+"%^BOLD%^"
"%^WHITE%^, as if it were made to fit "+ETO->QO+" perfectly.%^RESET%^",ETO);
   return 1;
}

int removeme() {
   tell_object(ETO,"%^BOLD%^%^WHITE%^You feel a reluctance to remove the ornate chainmail.%^RESET%^");
   return 1;
}

void init() {
   ::init();
   add_action("markem","mark");
}

int markem(string str){
   string mytarg;
   if(TP->query_bound() || TP->query_unconscious()){
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   if(!TO->query_worn()) {
     tell_object(TP,"You must be wearing the armor to activate it.");
     return 1;
   }
   if(!str) {
     tell_object(TP,"You can only use <mark target>.");
     return 1;
   }
   if(tracker > time()) {
     tell_object(TP,"You've already used the armor's enhancement today.");
     return 1;
   }
   if(!present(str,ETP)) {
     tell_object(TP,"You don't see any "+str+" here to cast that on.");
     return 1;
   }
   mytarg = present(str,ETP);
   tracker = time() + 28800;
   new("/cmds/spells/m/_mark_of_justice")->use_spell(TP,mytarg,30,100,"paladin");
   return 1;
}

void resetme() { tracker = 0; }
