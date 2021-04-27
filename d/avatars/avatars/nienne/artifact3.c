#include <std.h>
inherit OBJECT;

void create(){
   ::create();
   set_name("gemstone");
   set_id(({"gemstone","black sapphire","sapphire","glowing sapphire","glowing black sapphire","gem of the dread talon"}));
   set_short("%^BLACK%^%^BOLD%^a %^RESET%^%^GREEN%^g%^BOLD%^lo%^WHITE%^w%^GREEN%^in%^RESET%^%^GREEN%^g %^BLACK%^%^BOLD%^black sa%^RESET%^%^WHITE%^p%^BLACK%^%^BOLD%^phire%^RESET%^");
   set_long("%^RED%^This is an absolutely perfect %^BLACK%^%^BOLD%^black "
"sa%^RESET%^%^WHITE%^p%^BLACK%^%^BOLD%^phire%^RESET%^%^RED%^, about the size of an egg.  The brilliant-cut "
"gemstone is shaped as a spheroid, though it has a groove along each edge, as though it were shaped to fit "
"into something.  The entire gem pulses with a %^GREEN%^dark inner energy%^RED%^, filling you with a feeling "
"of dread.%^RESET%^");
   set_value(0);
   set_weight(1);
   set_lore("%^WHITE%^%^BOLD%^This is the gem that was originally set within the hilt of a greatblade named "
"as the 'Dread Talon of the Hand'. It was an artifact that was originally forged by the hand of the most "
"powerful magi and priests in the command of the Black Hand.  It was created with the intent to be the "
"turning power in the battle of Morgrash, in the hands of the Lord Knight Imperceptor, Dakhram Vilhon.  "
"However, prior to the battle's completion the blade was stolen and broken, and the pieces hidden from all "
"attempts to locate them.%^RESET%^");
   set_property("lore difficulty",20);
   set_property("no offer",1);
   set_heart_beat(1);
}

void heart_beat() {
   if(!random(90)) {
     if(ETO->is_room()) {
       tell_room(ETO,"%^WHITE%^%^BOLD%^A pulse of malignant energy runs through the room, filling you with a feeling of %^BLACK%^dread%^WHITE%^.  It seems to come from the %^RESET%^%^GREEN%^g%^BOLD%^lo%^WHITE%^w%^GREEN%^in%^RESET%^%^GREEN%^g%^WHITE%^%^BOLD%^ item before you.%^RESET%^");
       return;
     }
     if(EETO->is_room()) {
       if(userp(ETO)) {
         tell_object(ETO,"%^WHITE%^%^BOLD%^A pulse of malignant energy runs through you from the glowing "
"item you carry, filling you with a feeling of %^BLACK%^dread%^WHITE%^.%^RESET%^");
         if (!ETO->query_invis()) tell_room(EETO,"%^WHITE%^%^BOLD%^A pulse of malignant energy runs through the room, filling you with a feeling of %^BLACK%^dread%^WHITE%^.  It seems to come from "+ETO->QCN+".%^RESET%^",ETO);
         else tell_room(EETO,"%^WHITE%^%^BOLD%^A pulse of malignant energy runs through the room, filling you with a feeling of %^BLACK%^dread%^WHITE%^.%^RESET%^",ETO);
         return;
       }
       tell_room(EETO,"%^WHITE%^%^BOLD%^A pulse of malignant energy runs through the room, filling you with a feeling of %^BLACK%^dread%^WHITE%^.  It seems to come from somewhere very close to you.%^RESET%^");
       return;
     }
     if(userp(EETO)) {
       tell_object(EETO,"%^WHITE%^%^BOLD%^A pulse of malignant energy runs through you from the hidden "
"item you carry, filling you with a feeling of %^BLACK%^dread%^WHITE%^.%^RESET%^");
       if (!EETO->query_invis()) tell_room(environment(EETO),"%^WHITE%^%^BOLD%^A pulse of malignant energy runs through the room, filling you with a feeling of %^BLACK%^dread%^WHITE%^.  It seems to come from "+EETO->QCN+".%^RESET%^",EETO);
       else tell_room(environment(EETO),"%^WHITE%^%^BOLD%^A pulse of malignant energy runs through the room, filling you with a feeling of %^BLACK%^dread%^WHITE%^.%^RESET%^",EETO);
       return;
     }
   }
}
