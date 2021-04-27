#include <std.h>
#include "/d/antioch/antioch2/antioch.h"
inherit OBJECT;

object ob;
string tobacco_type, short_name="%^RESET%^fat %^BOLD%^chewed %^RESET%^on %^ORANGE%^cigar%^RESET%^";
int lit, packed, tobacco, light_time, sp_adjust, con_req;

void create()
{
  ::create();
  set_name("%^RESET%^fat %^BOLD%^chewed %^RESET%^on %^ORANGE%^cigar%^RESET%^");
  set_id(({ "cigar", "stogie", "blunt", "%^RESET%^fat %^BOLD%^chewed %^RESET%^on %^ORANGE%^cigar%^RESET%^" }));
  set_short(short_name);
  set_long("%^RESET%^This %^ORANGE%^cigar %^WHITE%^is brown and fat with %^ORANGE%^tobacco %^WHITE%^rolled in a %^ORANGE%^tobacco %^WHITE%^leaf.  The %^ORANGE%^stogie %^WHITE%^has seen much use and is %^BOLD%^%^CYAN%^"
    "wet %^RESET%^on %^BOLD%^%^CYAN%^chewed %^RESET%^on one end and %^BOLD%^%^BLACK%^blackened %^RESET%^on the other.  The %^BOLD%^%^RED%^cherry %^RESET%^of %^RED%^f%^BOLD%^i%^ORANGE%^r%^RESET%^%^RED%^"
    "e %^WHITE%^can be seen when the %^ORANGE%^blunt %^WHITE%^is puffed and a long section of %^BOLD%^%^BLACK%^a%^RESET%^s%^BOLD%^%^BLACK%^h %^RESET%^just seems to refuse to fall from the end.%^RESET%^");
  set_lore("%^RESET%^This %^ORANGE%^cigar %^WHITE%^is brown and fat with %^ORANGE%^tobacco %^WHITE%^rolled in a %^ORANGE%^tobacco %^WHITE%^leaf.  The %^ORANGE%^stogie %^WHITE%^has seen much use and is %^BOLD%^%^CYAN%^"
    "wet %^RESET%^on %^BOLD%^%^CYAN%^chewed %^RESET%^on one end and %^BOLD%^%^BLACK%^blackened %^RESET%^on the other.  The %^BOLD%^%^RED%^cherry %^RESET%^of %^RED%^f%^BOLD%^i%^ORANGE%^r%^RESET%^%^RED%^"
    "e %^WHITE%^can be seen when the %^ORANGE%^blunt %^WHITE%^is puffed and a long section of %^BOLD%^%^BLACK%^a%^RESET%^s%^BOLD%^%^BLACK%^h %^RESET%^just seems to refuse to fall from the end.%^RESET%^");
  set_property("lore difficulty",26);
  set_weight(1);
  set_value(20);
  tobacco = 0;
  packed = 0;
  lit = 0;
  con_req = 0;
  sp_adjust = 0;
}

void init()
{
  ::init();
  add_action("extinguish","douse");
  add_action("smoke","smoke");
  add_action("pack_pipe","pack");
  add_action("pack_pipe","fill");
}

int smoke(string str)
{
  if(!id(str)) {
    notify_fail("Smoke what?\n");
    return 0;
  }
  if(!packed) {
    notify_fail("You can't smoke an empty cigar, try packing it first.");
    return 0;
  }
  if(lit) {
    notify_fail("You're already smoking it!");
    return 0;
  }
  if(con_req > TP->query_stats("constitution")) {
    write("The tobacco is too strong for you to smoke.\n"+
    " You unpack the cigar, dropping the contents on the ground.\n");
    packed = 0;
    return 1;
  }
  else {
    write("%^BOLD%^You begin smoking your cigar.");
    say("%^BOLD%^"+TP->query_cap_name()+" begins smoking "+TP->query_possessive()+""+
    " cigar.");
    call_out("go_out",tobacco);
    call_out("take_drag",5);
    light_time = time();
    set_short(short_name+" (%^BOLD%^%^RED%^lit%^RESET%^)");
    lit = 1;
    return 1;
  }
}

int extinguish(string str)
{
  if(!id(str)) {
    notify_fail("Douse what?\n");
    return 0;
  }
  if(!lit) {
    notify_fail("Your cigar isn't lit.");
    return 0;
  }
  else {
    write("%^BOLD%^%^BLUE%^You douse your cigar.");
    say(""+TP->query_cap_name()+" douses "+TP->query_possessive()+""+
    " cigar.");
    tobacco -= (light_time - time());
    remove_call_out("go_out");
    remove_call_out("take_drag");
    set_short(short_name+" (%^RESET%^%^ORANGE%^packed%^ORANGE%^)");
    lit = 0;
    return 1;
  }
}

void go_out()
{
  tobacco = 0;
  if(living(ETO)) {
    tell_room(environment(ETO),""+TP->query_cap_name()+"'s cigar goes out.",ETO);
    tell_object(ETO,"Your cigar goes out.");
  }
  remove_call_out("take_drag");
  set_short(short_name);
  lit = 0;
  packed = 0;
}

void take_drag()
{
  if(living(ETO)) {
    write("%^GREEN%^You take a very deep drag on your cigar.");
    say("%^GREEN%^"+TP->query_cap_name()+" takes a very deep drag"+
    " on "+TP->query_possessive()+" cigar.");
  }
  if(tobacco_type == "afgan") {
    TP->add_intox(7);
    write("%^BOLD%^%^MAGENTA%^You start to feel a little strange"+
    " and your mind begins to wander.");
  }
  say("%^GREEN%^"+TP->query_cap_name()+" giggles and stares off"+
    " into the distance.");
  TP->set_sp(TP->query_sp()+sp_adjust);
  call_out("take_drag",50,TO);
}

int pack_pipe(string str)
{
  string pipe;
  if(packed) {
    notify_fail("Your cigar is already packed!\n");
    return 0;
  }
  if(!str) return 0;
  if((sscanf(str, "%s with %s", pipe, tobacco_type)) !=2) return 0;
  if(pipe != "cigar") return 0;
  if(tobacco_type == "tobacco") {
    notify_fail("That is not a valid type of tobacco!\n");
    return 0;
  }
  if(!(ob = present(tobacco_type,TP))) {
    notify_fail("You can't pack your cigar with "+tobacco_type+"!\n");
    return 0;
  }
  if(ob->id("tobacco")) {
    con_req = (int)ob->query_con_check();
    write("\n%^BOLD%^You pack your cigar with "+tobacco_type+""+
    " tobacco.\n");
    say("\n%^BOLD%^"+TP->query_cap_name()+" packs "+TP->query_possessive()+""+
    " cigar with some "+tobacco_type+" tobacco.\n");
    set_short(short_name+" (%^RESET%^%^ORANGE%^packed%^ORANGE%^)");
    tobacco = 500;
    packed = 1;
    sp_adjust = ob->set_uses();
    return 1;
  }
}

remove()
{
  if(lit) {
    lit = 0;
    packed = 0;
    remove_call_out("take_drag");
    remove_call_out("go_out");
  }
  if(packed) packed = 0;
  TO->set_short(short_name);
  return ::remove();
}
