#include <std.h>
inherit MONSTER;

int CALL;

void create()
{
  ::create();
  set_name("wererat");
  set_id(({"wererat","were rat","lycanthrope","monster","ratman","sneaky wererat","monster"}));
  set_short("A massive wererat");
  set_long("The wererat stands more than five feet tall with his shoulders"+
  " slightly hunched. He is covered in brownish-black wiry fur and has a"+
  " long pink tail. He has the face of a rat, with red beady eyes, fury"+
  " ears, and whiskers. His arms and hands are still mostly human and he"+
  " wields two short swords. A few tattered remenants of clothing still"+
  " cling to him.  He is a good bit larger and stronger-looking than his companions."
  );
  set_hd(14,5);
  set_race("wererat");
  set_body_type("human");
  set_gender("male");
  set_size(1);
  set("aggressive",25);
  set_property("swarm",1);
  //set_level(14);
  set_class("ranger");
   set_mlevel("ranger",14);
  set_hp(random(25)+200);
  set_stats("strength",15 + random(2));
   //set_exp(400);
   set_exp(1650);
  set_property("full attacks",1);
  add_limb("tail","torso",0,0,0);
//  set_property("weapon resistance",1);  not appropriate now that it's a lowbie area
  new("/d/common/obj/weapon/shortsword")->move(TO);
  command("wield sword");
  new("/d/common/obj/weapon/dagger")->move(TO);
  command("wield dagger");
    new("/d/shadow/room/meadows/obj/leather")->move(TO);
    command("wear leather");
    new("/d/avatars/nienne/viaghgreaves")->move(TO);
    command("wear greaves");
  set_overall_ac(-2);
  set_funcs(({"call","slash"}));
  set_func_chance(40);
  set_alignment(5);
  add_money("gold",random(100)+50);
  set_max_level(12);
   set_property("knock unconscious",1);
}

void call(object targ)
{
  int num,mons;
  object mon;
  mons=random(3)+2;
  if(CALL > 2) return;
  for(num=1;num<=mons;num++)
  {
    mon=new("/d/newbie/rooms/keep/mon/rat");
    mon->move(ETO);
    mon->command("protect wererat");
  }
  tell_room(ETO,"%^YELLOW%^The wererat lifts his head up and "+
	"issues a series of loud squeeks and clicking sounds.\n"+
	"Suddenly, several rats rush out of the surroundings "+
	"to his aid!%^RESET%^");
   CALL += 1;
   return;
}

void reset()
{
   ::reset();
   CALL = 0;
   if(!random(3) && !present("jewelry")) {
      new("/d/antioch/valley/obj/jewelry")->move(TO);
   }
   if(!random(4) && !present("gem")) {
      new("/d/antioch/valley/obj/gem")->move(TO);
   }
}

void slash(object targ){
  tell_object(targ,"%^RED%^The wererat lunges at you, claws extended, and you stumble off balance!%^RESET%^");
  tell_room(environment(targ),"%^RED%^The wererat lunges at "
+targ->query_cap_name()+", who stumbles off balance!%^RESET%^",targ);
  targ->do_damage("torso",random(15)+15);
  targ->set_paralyzed(random(5)+5,"You're trying to get your balance back!");
}
