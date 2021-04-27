#include <std.h>
inherit "/d/deku/keep/monster/werewolf";

void create(){
   ::create();

   set_name("massive werewolf");
   set_short("%^BOLD%^%^BLACK%^Massive Werewolf%^RESET%^");
   set_id(({"Werewolf","werewolf","massive werewolf","Massive Werewolf"}));
   
   set_long("%^BOLD%^%^WHITE%^This creature towers nearly ten feet "+
   "tall, a hybrid of some massive wolf and an ugly ogre.  "+
   "Its body is covered with a thick and dark fur.  The legs of "+
   "this creature are those of a powerful wolf and each of its arms "+
   "end in clawed appendages.  The face of this creature "+
   "resembles a strange mixture between wolf and ogre, something "+
   "both unnatural and fear inspiring.%^RESET%^");
	   
   set_hd(25,1);
   set_hp(300 + random(41));
   set_overall_ac(-4);
   set_size(3);
   set_stats("strength", 18);
   set_stats("dexterity", 18);
   set_stats("constitution", 18);
   set_stats("intelligence", 14);
   set_stats("charisma", 6);
   set_stats("wisdom", 12);
   set_funcs( ({"bite","maim"}) );
   set_damage(1,8);
   set_attacks_num(2);
	  set_exp(5000);
  new("/d/avatars/nienne/goldring")->move(TO);
  command("wear ring");
  new("/d/avatars/nienne/sapp_short")->move(TO);
  command("wield sword");
   set_exp(query_max_hp() * 20);
}
