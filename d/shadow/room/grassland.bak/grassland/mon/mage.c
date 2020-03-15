#include "/std.h";

inherit MONSTER;

create() {
    ::create();
   set_name("mage");
set_id( ({ "mage" }));
	set("race", "human");
	set_gender("male");
   set_short("The mage lord");
	set_long(
         "He is the lord of all mages, and could probably tear"
          " you to pieces in a matter of seconds with his magical orb"
	);
   set_level(20);
	enable_commands();   
	set_body_type("human");
  	set("aggressive",5);
  	set_alignment(9);
  	set_size(2);
   	set_stats("intelligence",18);
   	set_stats("wisdom",18);
   	set_stats("strength",13);
   	set_stats("charisma",3);
   	set_stats("dexterity",16);
   	set_stats("constitution",13);
   	set_max_mp(0);
   	set_mp(query_max_mp());
	set_hd(15, 5);
	set_class("mage");
	set_max_hp(query_hp());
	set_max_sp(query_hp());
	set_sp(query_max_sp());
	set_wielding_limbs( ({ "right hand", "left hand" }) );
          new("/d/shadow/obj/weapon/quarter_staff")->move(this_object());
      	command("wield staff in right hand");
       new("/d/shadow/obj/armor/robe")->move(this_object());
      	command("wear armor");
 //      new("/d/shadow/room/grassland/obj/orb1.c")->move(this_object());

add_money("silver",random(10));
	add_money("copper",random(20));
set_exp(1000);
set_hp(200);
}
