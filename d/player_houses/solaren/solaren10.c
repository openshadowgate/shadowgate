// Laboratory
// Thorn@ShadowGate
// 001027
// Solaren's Player House
// solaren10.c

#include <std.h>
#include "../defines.h"

#define SAVE_FILE "/d/magic/comps/solaren/"

inherit "/std/lab";

int traps_enabled;

void create() {
  object ob;
  ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
  set_property("light", 2);
  set_property("indoors", 1);
     set_name("Laboratory");
  set_short("%^BOLD%^Laboratory%^RESET%^");
  set_long(
@THORN
%^BOLD%^Laboratory%^RESET%^
Within the room you find what you would imagine is a typical magic
user's laboratory and workspace.  Taking up nearly one quarter of the
room, there are shelves filled with all sorts of components used for
spell casting and experimentation.  Elsewhere, several work tables are
covered with alchemist's globes, glass tubes, balancing scales and the
like.  In the center of the room can be found the outlines of a series
of circles and mystical diagrams inlaid within the stone floor.  You
assume that these provide some measure of protection or power over
whatever creature a mage may choose to summon to this workspace.

There are a set of spiral steps in the corner of the room that you can
take up through a trapdoor to the roof or down into the lower levels.

There is a large sign on the wall which is written in strange mystic
characters and there seems to be a crystal that is hanging suspended in
mid-air above the center of the room.
THORN
  );
  set_items(([
    "sign" : "You can try and read the sign.",
    "crystal" : "%^RED%^The crystal in the center of the room is an angry red color.",
  ]));
  set_search("default","You look around the room and notice a green velvet curtain that is covering something.");
  set_search("curtain","There appears to be a rope that might operate the curtain.");
  set_search("rope","Just a cord made of wound thread-of-gold attached to the curtain.");
  set_exits(([
      "up" : "/d/player_houses/solaren/solaren11",
      "down" : "/d/player_houses/solaren/solaren9",
  ]));
  setOwner("none");
  setLabId("solaren");
  setAllowedStorage(50);
  set_door("trap door","/d/player_houses/solaren/solaren11","up","solaren house key");
  set_open("trap door",0);
  set_locked("trap door",1);
  "/d/player_houses/solaren/solaren11"->set_open("trap door",0);

  set_trap_functions(({"trap door", "rope", "rope twice", "", "curtain"}),
                     ({"poison_me", "blast_me", "blast_me", "jolt_me", "jolt_me"}),
                     ({"pick", "pull", "pull", "search", "search"}));
  traps_enabled = 1;
}

int open(string str) {
   string who;
   object account;
   if(!str) 
	return 0;
   if(strsrch(str, "account") == -1)
	return 0;   // to let other open functions work

   if(!avatarp(TP))
	return notify_fail("Sorry, this lab isn't open to the public.");

   if(sscanf(str, "account for %s", who) != 1)
      return notify_fail("Syntax is <open account for [playername]>\n");

   if(file_exists(SAVE_FILE+who+".comp.o") )
      return notify_fail(capitalize(who)+" already has an account here.\n");

   account = new ("/d/magic/compAccount");
   account->set_owner(lab_id,who);
   account->Save();
   account->remove();
   tell_object(TP, capitalize(who)+" now has a cubby in this laboratory.");
   return 1;
}

void reset(){
  ::reset();
}

void init() {
  ::init();
  add_action("read", "read");
  add_action("snap", "snap");
  add_action("pull", "pull");
  add_action("blink", "blink");
}

int read(string str) {
  if(!str) return 0;
//  if((string)TP->query_name() != "solaren" && !avatarp(TP)) {
  if(member_array(TP->query_name(), MAGE_MEMBERS) == -1 && !avatarp(TP)) {
    write("You try and read the sign, but the characters appear to be magically encoded.");
    return 1;
  }
  write("You can see how to operate this laboratory by typing <help laboratory>.");
  return 1;
}

int snap(string str) {
  object ob;
  object other;

  if(str != "twice") return 0;
//  if(((string)TP->query_name() != "solaren") && !avatarp(TP))
  if(member_array(TP->query_name(), MAGE_MEMBERS) == -1 && !avatarp(TP))
    return 0;
  other = find_object_or_load("/d/player_houses/solaren/solaren11");
  if(!query_locked("trap door")) {
    tell_room(TO,
      TP->query_cap_name()+" snaps "+TP->query_possessive()+
      " fingers twice and you hear a bolt slide home!",
      ({ TP }));
    tell_room(other,
      "You hear a bolt slide home on the trap door!",
      ({ TP }));
    write("You snap your fingers twice and the trap door locks itself!");
    TO->set_open("trap door",0);
    TO->set_locked("trap door",1);
    other->set_locked("trap door",1);
    other->set_open("trap door",0);
    return 1;
  }
  tell_room(TO,
    TP->query_cap_name()+" snaps "+TP->query_possessive()+
    " fingers twice and you hear a bolt slide as the trap door unlocks itself!",
    ({ TP }));
    tell_room(other,
      "You hear a bolt slide as the trap door unlocks!",
      ({ TP }));
  write("You snap your fingers twice and the trap door unlocks itself!");
  TO->set_locked("trap door",0);
  other->set_locked("trap door",0);
  return 1;
}

int blink(string str) {
  object ob;
  object other;

  if(str != "twice") return 0;
//  if(((string)TP->query_name() != "solaren") && !avatarp(TP))
  if(member_array(TP->query_name(), MAGE_MEMBERS) == -1 && !avatarp(TP))
    return 0;
  if(!traps_enabled) {
    write("You blink twice and you feel the traps arming!");
    tell_room(TO, "%^RED%^You see the crystal suddenly change color to red!");
    remove_item("crystal");
    add_item("crystal",
      "%^RED%^The crystal in the center of the room is an angry red color."
    );
    traps_enabled = 1;
  }
  else {
    write("You blink twice and you feel the traps arming!");
    tell_room(TO, "%^GREEN%^You see the crystal suddenly change color to green!");
    remove_item("crystal");
    add_item("crystal",
      "%^GREEN%^The crystal in the center of the room is an dim green color."
    );
    traps_enabled = 0;
  }
  return 0;
}

int pull(string str) {
  object ob;
  object other;

  if(str == "rope twice") {
    if(traps_enabled) return 0;
    if(ob = present("fine mirror", TO)) {
        tell_room(TO, "The curtain slides closed over the mirror.");
        ob->remove();
        return 1;
    }
    else {
        tell_room(TO, "The curtain slides open revealing a mirror!");
        ob=new("/d/magic/obj/mirror");
        ob->move(TO);
        return 1;
    }
  }
  return 0;
}

int poison_me(string str){
    int poison;

    if(!traps_enabled) return 0;
    poison = roll_dice(30,10);
    TP->add_poisoning(poison);
    TP->setPoisoner(TO);
    tell_object(TP,"You feel a sharp prick in your hand as you work "+
        "the lock.");
    TP->force_me("emote pulls his hand back in pain and shakes it slightly");
    return 1;
}

int blast_me(string str) {
    string sfile = "/cmds/wizard/_magic_missile";
    object spell;
    object curtain;
    int x;

    if(!traps_enabled) return 0;

    curtain = new("/std/Object");
    curtain->set_name("Crystal");
    curtain->set_invis();
    curtain->move(TO);

    x = random(20)+1;
    spell = new(sfile);
    spell->use_spell(curtain, TP->query_name(), x, 100);
    spell = new(sfile);
    spell->use_spell(curtain, TP->query_name(), x+1, 100);
    spell = new(sfile);
    spell->use_spell(curtain, TP->query_name(), x+2, 100);
    spell = new(sfile);
    spell->use_spell(curtain, TP->query_name(), x+3, 100);
    spell = new(sfile);
    spell->use_spell(curtain, TP->query_name(), x+4, 100);
    curtain->remove();
    return 1;
}

int jolt_me(string str){
    string sfile = "/cmds/wizard/_lightning_bolt";
    object spell;
    object curtain;
    int x;

    if(!traps_enabled) return 0;

    tell_room(TO, "Of its own accord, the crystal glows an electric blue color!");
    curtain = new("/std/Object");
    curtain->set_name("Crystal");
    curtain->set_invis();
    curtain->move(TO);

    x = random(20)+1;
    spell = new(sfile);
    spell->use_spell(curtain, TP->query_name(), x, 100);
    curtain->remove();
    return 1;
}

int help(string str){
   if (!str) {
      return 0;
   }
   if (str != "laboratory") {
      return 0;
   }
   if(member_array(TP->query_name(), MAGE_MEMBERS) == -1 && !avatarp(TP))
	return 0;

   write("       Laboratory help");
   write("<============================>");
//   write(" open account: opens a cubby for you, costs 10000 gold");
   write(" %^BOLD%^As one granted access to use of this lab, you can do the following:");
   write(" deposit <component> deposits all of the component you possess");
   write(" deposit <amount> <component>: deposits amount of the component");
   write(" withdraw <component>: withdraws all the component in your cubby");
   write(" withdraw <amount> <component>: withdraw the amount of component from your cubby");
   write(" list components: lists the contents of your cubby");
   write(" help laboratory: shows this screen.");
   if(avatarp(TP))
	write("%^BOLD%^Immortals can <open account for [name]> for this location as needed.\n");
   return 1;
}

