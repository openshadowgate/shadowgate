//file 

#include <std.h>

inherit OBJECT;

static int fail = 0;

void create(){
    ::create();
    set_property("no offer",1);
    set_property("no steal",1);
    set_name("Book of the Ancients");
    set_id(({"book of the ancients","book","Book of the Ancients",}));
    set_short("Book of the Ancients");
    set_long(
@ITEM
A powerful and mysterious portal to the weave, this book has been long
hidden in a Mystraan temple on the outer reaches of the realm.  Many
Dweomerkeepers have researched this book in their studies.  Before 
them, ancient wizards scribed down their findings of great power 
in here and handed this over to Mystra.  Spells hidden in these pages 
have long been thought too powerful for everyday wizards and given 
unto her for safety.  If you are reading this, consider yourself fortunate.
ITEM
        );
    set_weight(10);
    set_value(0);
    set_heart_beat(3);
}
void init() {
  if (ETO==TP) {
    add_action("read_me","read");
    if (!avatarp(ETO))
      add_action("cast_block","cast");
  }
}
int cast_block(string str) {
  if (!fail)
    return 0;
  write("%^YELLOW%^The book of Ancient Spells causes a your spell to short out.\n");
  tell_room(environment(ETO),"%^YELLOW%^"+ETO->query_cap_name()+"'s spell arcs and shorts out in a spectacular failure.",ETO);
  return 1;
}
int read_me(string str) {
  if ((stringp(str)) && (TO->id(str)) && (TO==present(str,TP))) {
    ETO->more("/d/avatars/mystra/ancient-spells");
    return 1;
  } else return 0;
}

int drop() {
  object ob;
  object around;
  object let_go;
  if (objectp(environment(ETO))) around = environment(ETO);
  else around = ETO;
  //  write(identify(around));
  if (member_array(TP->query_name(), ({"aaron", "mystra" })) != -1)
    return 0;
  if (objectp(find_player("mystra"))) let_go=find_player("mystra");
  else if (objectp(find_player("aaron"))) let_go=find_player("aaron");
  if (objectp(let_go) && objectp(ob = present(let_go,around))) {
    //    write(identify(ob));
    return 0;
  }
  write("The divine book fails to allow you to release it!");
  return 1;
}

void heart_beat() {
  if (fail)
     fail = 0;
  else
   fail = 1;
  //  ::heart_beat();
  return;
}


