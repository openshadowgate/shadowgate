inherit "/std/drink";

void create(){
   ::create();
   set_name("water");
   set_id(({"fortified water","water","drink"}));
   set_short("%^BOLD%^%^BLACK%^f%^RESET%^%^BLUE%^o%^BOLD%^%^BLACK%^rt%^RESET%^%^BLUE%^i%^BOLD%^%^BLACK%^f%^RESET%^%^BLUE%^ie%^BOLD%^%^BLACK%^d w%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^t%^RESET%^%^BLUE%^e%^BOLD%^%^BLACK%^r%^RESET%^");
   set_long("Is water supposed to be grey? And turn the glass yellow?");
   set_my_mess("Judging by the taste of the water, you got a lifetime supply of iron.\n");
   set_your_mess("drinks the water, was that a 'clunk!' sound when it hit the bottom?\n");
   set_destroy();
   set_value(0);
   set_weight(0);
   set_strength(10);
   set_type("water");
}
