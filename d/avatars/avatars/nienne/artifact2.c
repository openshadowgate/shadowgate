#include <std.h>
inherit OBJECT;

void create(){
   ::create();
   set_name("hilt");
   set_id(({"hilt","ebony hilt","glowing hilt","sword-hilt","ebony sword-hilt","hilt of the dread talon"}));
   set_short("%^BLACK%^%^BOLD%^a %^RESET%^%^GREEN%^g%^BOLD%^lo%^WHITE%^w%^GREEN%^in%^RESET%^%^GREEN%^g %^BLACK%^%^BOLD%^ebony sword-hilt%^RESET%^");
   set_long("%^RED%^This is the hilt of what must have been a massive sword.  It is crafted of perfect "
"%^BLACK%^%^BOLD%^ebony%^RESET%^%^RED%^, sculpted in the form of a mighty black dragon.  The creature's "
"spread wings would form the crosspiece, its tail shaped to encircle a blade to secure it in place.  The "
"dragon's head shows its expression held in an eternal roar of fury, teeth bared, though its foreclaws are "
"held apart, leaving an empty space that is obviously designed to hold something of about the size of an "
"egg.  The entire hilt pulses with a %^GREEN%^dark inner energy%^RED%^, filling you with a feeling of "
"dread.%^RESET%^");
   set_value(0);
   set_weight(1);
   set_lore("%^WHITE%^%^BOLD%^This is the hilt of a greatblade named as the 'Dread Talon of the Hand'. It "
"was an artifact that was originally forged by the hand of the most powerful magi and priests in the command "
"of the Black Hand.  It was created with the intent to be the turning power in the battle of Morgrash, in "
"the hands of the Lord Knight Imperceptor, Dakhram Vilhon.  However, prior to the battle's completion the "
"blade was stolen and broken, and the pieces hidden from all attempts to locate them.%^RESET%^");
   set_property("lore difficulty",20);
   set_property("no offer",1);
}
