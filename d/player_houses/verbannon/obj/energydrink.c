inherit "/std/drink";

void create(){
   ::create();
   set_name("energy drink");
   set_id(({"energy drink","drink"}));
   set_short("%^BOLD%^%^MAGENTA%^energy drink%^RESET%^");
   set_long("Pretty sure this stuff is glowing. And when you set it down the glass to slide across the table. Bottom's up!");
   set_my_mess("Your stomach roils, the world spins, you start hearing voices and your taste buds begin chanting for the apocalypse. It really tastes that bad, but afterwards you feel like you could stay awake three days straight! And when you set down the glass it slides across the table.\n");
   set_your_mess("drinks the glowing liquid and begins to vibrate with pure energy!\n");
   set_destroy();
   set_value(0);
   set_weight(0);
   set_type("caffeine");
   set_strength(10);
}
