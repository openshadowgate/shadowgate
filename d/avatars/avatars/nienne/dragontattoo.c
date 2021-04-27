#include <std.h>
inherit ARMOUR;

void create() {
   ::create();
   set_name("tattoo");
   set_id(({"tattoo","dragon tattoo","ornate tattoo","tattoo of a coiled dragon"}));
   set_short("%^RESET%^%^CYAN%^orn%^GREEN%^a%^CYAN%^te tattoo of a coi%^MAGENTA%^l%^CYAN%^ed d%^BOLD%^r%^RESET%^%^CYAN%^agon%^RESET%^");
   set_long("%^RESET%^%^CYAN%^This tattoo is impressive in its attention to %^MAGENTA%^det%^RED%^a%^MAGENTA%^il%^CYAN%^, "
"leaving you to wonder at the skill of any mortal hand able to create such a work of art.  It is fairly small, encircling "
"the wrist with the outline of a serpentine dragon with its bright eyes and scales marked in gleaming %^BOLD%^azure "
"%^RESET%^%^CYAN%^ink.  Its maw is slightly parted, revealing the sharp fangs of a predator and tendrils of %^BOLD%^"
"%^WHITE%^fros%^CYAN%^t%^WHITE%^ed %^RESET%^%^CYAN%^breath, while its claws are extended as though holding a grip upon "
"the skin itself.  A broad wingspan spreads above it, and its long tail extends to coil around the entire wrist.  Each "
"scale, claw and raised ridge are marked in startlingly %^GREEN%^l%^BOLD%^i%^RESET%^%^GREEN%^fel%^BOLD%^i%^RESET%^"
"%^GREEN%^ke %^CYAN%^detail, leaving you almost expecting the creature to rise from the wrist and take flight"
".%^RESET%^\n");
   set_weight(0);
   set_value(0);
   set_ac(1);
   set_property("enchantment",-1);
   set_property("death keep",1);
   set_limbs(({"left arm"}));
   set_type("ring");
   set("chabonus",1);
   set_property("no alter",1);
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
   set_heart_beat(1);
}

void init() {
   ::init();
   add_action("cast_echo","cast");
}

int wear_fun() {
   TO->set_overallStatus(100);
   ETO->set_property("spell penetration",5);
   return 1;
}

int remove_fun() {
   ETO->set_property("spell penetration",-5);
   return 1;
}

int cast_echo(string str) {
   if(!random(30)) {
     tell_room(ETP,"%^CYAN%^The tattoo at "+TP->QCN+"'s wrist seems to come to %^GREEN%^li%^BOLD%^f%^RESET%^%^GREEN%^e"
"%^CYAN%^, its wings lifting and its maw curling into a silent %^MAGENTA%^sna%^RED%^r%^MAGENTA%^l%^CYAN%^, as its eyes "
"gleam with %^BOLD%^a%^WHITE%^r%^CYAN%^ca%^WHITE%^n%^CYAN%^e %^RESET%^%^CYAN%^energy.%^RESET%^",TP);
     tell_object(TP,"%^CYAN%^The tattoo at your wrist seems to come to %^GREEN%^li%^BOLD%^f%^RESET%^%^GREEN%^e%^CYAN%^, "
"its wings lifting and its maw curling into a silent %^MAGENTA%^sna%^RED%^r%^MAGENTA%^l%^CYAN%^, as its eyes gleam with "
"%^BOLD%^a%^WHITE%^r%^CYAN%^ca%^WHITE%^n%^CYAN%^e %^RESET%^%^CYAN%^energy.%^RESET%^");
   }
   return 0;
}

int isMagic() { return 1; }

void heart_beat() {
    int xx,yy;
    if(!objectp(ETO)) return;
    if(!userp(ETO)) return;
    if(!TO->query_worn()) return;
    if(ETO->query_invis()) return;

    xx = random(1000);
    yy = random(50);
    
    if((xx > 995)) {
      switch(yy) {
        case 0..9:
          tell_room(EETO,"%^CYAN%^A sparkle of %^YELLOW%^l%^WHITE%^i%^YELLOW%^ght %^RESET%^%^CYAN%^plays across the "
"outline of the dragon tattoo at "+ETO->QCN+"'s wrist.%^RESET%^",ETO);
          tell_object(ETO,"%^CYAN%^A sparkle of %^YELLOW%^l%^WHITE%^i%^YELLOW%^ght %^RESET%^%^CYAN%^plays across the "
"outline of the dragon tattoo at your wrist.%^RESET%^");
          break;
        case 10..19:
          tell_room(EETO,"%^CYAN%^"+ETO->QCN+" shifts, and the slight movement of "+ETO->QP+" wrist seems to bring the "
"draconic tattoo there to %^GREEN%^li%^BOLD%^f%^RESET%^%^GREEN%^e%^CYAN%^, its wings lifting as though in flight"
".%^RESET%^",ETO);
          tell_object(ETO,"%^CYAN%^The slight movement of your wrist seems to bring the draconic tattoo to %^GREEN%^li"
"%^BOLD%^f%^RESET%^%^GREEN%^e%^CYAN%^, its wings lifting as though in flight.%^RESET%^");
          break;
        case 20..29:
          tell_room(EETO,"%^CYAN%^Light gleams momentarily in the sharp %^BOLD%^azu%^WHITE%^r%^CYAN%^e %^RESET%^%^CYAN%^"
"eyes of the dragon tattoo at "+ETO->QCN+"'s wrist.%^RESET%^",ETO);
          tell_object(ETO,"%^CYAN%^Light gleams momentarily in the sharp %^BOLD%^azu%^WHITE%^r%^CYAN%^e %^RESET%^%^CYAN%^"
"eyes of the dragon tattoo at your wrist.%^RESET%^");
          break;
        case 30..39:
          tell_room(EETO,"%^CYAN%^Glittering tendrils of %^BOLD%^f%^WHITE%^r%^CYAN%^ost %^RESET%^%^CYAN%^seem to breathe "
"forth from the draconic maw of the tattoo at "+ETO->QCN+"'s wrist, or perhaps it was just a reflection of the light"
"?%^RESET%^",ETO);
          tell_object(ETO,"%^CYAN%^Glittering tendrils of %^BOLD%^f%^WHITE%^r%^CYAN%^ost %^RESET%^%^CYAN%^seem to breathe "
"forth from the draconic maw of the tattoo at your wrist, or perhaps it was just a reflection of the light?%^RESET%^");
          break;
        case 40..49:
          tell_room(EETO,"%^CYAN%^A soft glow of %^GREEN%^a%^CYAN%^rc%^GREEN%^an%^CYAN%^e energy briefly outlines the "
"tattoo of a dragon at "+ETO->QCN+"'s wrist in stark focus.%^RESET%^",ETO);
          tell_object(ETO,"%^CYAN%^A soft glow of %^GREEN%^a%^CYAN%^rc%^GREEN%^an%^CYAN%^e energy briefly outlines the "
"tattoo at your wrist in stark focus.%^RESET%^");
          break;
      }
    }
}
