#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("garnet");
	set_id(({ "gem", "blood", "tempus\' blood", "tempus", "garnet" }));
	set_short("A large Garnet");
	set_obvious_short("A large Garnet");
	set_long(
@AVATAR
%^RED%^A large garnet glitters in the light.  The gem is about the
size of two hands put together.  The many faucets of the gem glitter
in the light.  Looking deeper into the gem there seems to be some
liquid of somekind.  A large gash has been cut into the gem.  It looks
as if it might break in half anytime soon

AVATAR
	);
	set_weight(5);
	set_value(0);
	set_lore(
@AVATAR
The Heart's Blood, or Tempus\' Blood was gathered by followers of
Tempus when his avatar was last seen 75 years ago doing combat with
Bane over Graez.  The faithful collected these sacred drops of blood
and stored them in gems to keep them fresh.  They say Tempus' blood
has a variety of diffrent effects

AVATAR
	);
}

void init() {

  ::init();
  add_action("break_gem","break");

}

int break_gem(string str) {
  object ob;
  int maxhpint,randomval;
  
  if (!objectp(TP))
    return 0;
  ob=present(str,ETP);
  if (!objectp(ob))
    ob=present(str,TP);
  if (ob != TO)
    return notify_fail("You can\'t break that!\n");
  tell_object(TP,"%^BOLD%^%^RED%^You break the gem and the liquid within spills out and stains your fingers, absorbing quickly.");
  randomval=random(10)+random(10)+random(10)+6;
  maxhpint=TP->query_max_hp();
  TP->set_max_hp(maxhpint+randomval);
  TP->heal(randomval);
  tell_object(TP,"You feel the blood strengthen and regenerate your body, making it better than before as the gem crumbles into dust.");
  return 1+TO->remove();
}
