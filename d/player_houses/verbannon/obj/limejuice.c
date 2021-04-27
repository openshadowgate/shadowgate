inherit "/std/drink";

void create(){
   ::create();
   set_name("lime juice");
   set_id(({"lime juice","juice","drink"}));
   set_short("%^BOLD%^%^GREEN%^li%^RESET%^%^GREEN%^m%^BOLD%^e j%^RESET%^%^GREEN%^u%^BOLD%^ice%^RESET%^");
   set_long("Well this looks tasty. It's bright green liquid with all the texture and consistency of thick paint. You suspect it probably could be used as paint.");
   set_my_mess("HOLY MOLY! That is some sour stuff! But dont worry, your facial contortions should subside within the hour.\n");
   set_your_mess("drinks the lime juice and makes the ultimate sour face.\n");
   set_destroy();
   set_value(0);
   set_weight(0);
   set_type("soft drink");
   set_strength(10);
}
