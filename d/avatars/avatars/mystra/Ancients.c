//file 

#include <std.h>

inherit OBJECT;

void create(){
    ::create();
    set_property("no_offer",1);
    set_property("no_steal",1);
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
}
void init() {
  if (ETO==TP) {
    add_action("read_me","read");
  }
}

int read_me(string str) {
  if (TO->id(str))
    if (TO!=present(str,TP))
      return 0;
  ETO->more("/d/avatars/mystra/ancient-spells");
  return 1;
}

int drop() {
  object ob;
  if (objectp(ob = present("mystra",ETP)) ||objectp(ob = present("aaron",ETP)) )
    return 0;
  write("The divine book fails to allow you to release it!");
  return 1;
}
