#include <std.h>
inherit ARMOUR;

string where;

void create() {
    ::create();
    set_name("bandage");
    set("id", ({ "bandage" }) );
    set("short", "A cloth bandage");
    set("long", "This is a strip of soft, absorbent cloth that can be used "
       "to bandage a limb, covering it for healing or to contain the bleeding.  "
       "Sometimes a cleric or healer will use them to apply healing "
       "ointments or poultices.  You should prepare the bandage to wrap "
       "a particular body part before trying to wear it." );
    set_weight(2);
    set("value", 4);
    set_type("ring");
    set_limbs( ({ "torso" }) );
    set_ac(1);
    set_property("enchantment",-1);
    set_property("wrapped", "right arm");
    set_wear((:TO,"wear_fun":));
    set_remove((:TO,"remove_fun":));
}

void init() {
  ::init();
  if (ETO!=TP)     return;
  add_action("set_bandage","prepare");
  add_action("set_bandage","bandage");
}

string query_short() {
    string str;
    str = ::query_short();
    if(TO->query_worn())  str = str+" wrapping the "+TO->query_property("wrapped");
    return str;
}

int set_bandage(string str) {
  string this;
  object ob;
  if ( (!stringp(str)) || (sscanf(str,"%s for %s", this, where) != 2))
    return notify_fail("Prepare <which bandage> for <what body part>?\n");
  else {
  ob = present(this,TP);
    if(ob != TO) return 0;
    if (member_array(where,TP->query_limbs()) == -1)
      return notify_fail("You don't have a "+where+" body part so you can't wrap it!\n");
    if (TO->query_worn())
      return notify_fail("You would have to take it off first!\n");
    set_limbs(({where}));
    remove_property("wrapped");
    set_property("wrapped", where);
    write("You ready the bandage to wrap your "+where+".");
    tell_room(ETP,TPQCN+" seems to prepare a bandage to wrap something.",TP);
    set_value(0);
    return 1;
  }
}

int wear_fun() {
   ETO->add_stat_bonus("dexterity",-2);
   return 1;
}

int remove_fun() {
   ETO->add_stat_bonus("dexterity",2);
   return 1;
}
