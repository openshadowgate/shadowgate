#include <std.h>
inherit OBJECT;

void create(){
   ::create();
   set_name("blade");
   set_id(({"blade","titanium blade","glowing blade","blade of the dread talon"}));
   set_short("%^BLACK%^%^BOLD%^a %^RESET%^%^GREEN%^g%^BOLD%^lo%^WHITE%^w%^GREEN%^in%^RESET%^%^GREEN%^g %^BLACK%^%^BOLD%^titanium blade%^RESET%^");
   set_long("%^RED%^This is the blade of what must have been a massive sword.  It is easily more than six "
"feet long, impressive even by the standards of most two-handed blades, and crafted from what appears to be "
"titanium, though it has been %^BLACK%^%^BOLD%^blackened%^RESET%^%^RED%^ to the colour of a starless night "
"sky.  The entire blade pulses with a %^GREEN%^dark inner energy%^RED%^, filling you with a feeling of "
"dread.%^RESET%^");
   set_value(0);
   set_weight(1);
   set_lore("%^WHITE%^%^BOLD%^This is the blade of a greatblade named as the 'Dread Talon of the Hand'. It "
"was an artifact that was originally forged by the hand of the most powerful magi and priests in the command "
"of the Black Hand.  It was created with the intent to be the turning power in the battle of Morgrash, in "
"the hands of the Lord Knight Imperceptor, Dakhram Vilhon.  However, prior to the battle's completion the "
"blade was stolen and broken, and the pieces hidden from all attempts to locate them.%^RESET%^");
   set_property("lore difficulty",20);
   set_property("no offer",1);
}