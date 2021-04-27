#include <std.h>
#include "../defs.h"
inherit ROOM;

void create() {
   ::create();
   set_property("indoors",1);
   set_property("light",1);
   set_terrain(BUILT_TUNNEL);
   set_travel(PAVED_ROAD);
   set_name("A large precipice high on the mountain");
   set_short("%^CYAN%^A large precipice high on the mountain%^RESET%^");
   set_long("%^CYAN%^After a hard climb you stand upon a large precipice before the tree covered summit of the southern "
"mountain. Beneath your feet the rock looks unnaturally scarred and in many places discolored. A general unnatural "
"wrongness permeates the air here emanating from a cluster of damaged trees, between the summit and the precipice, "
"trying their best to conceal what looks to be a %^ORANGE%^r%^BOLD%^%^BLACK%^o%^RESET%^%^WHITE%^u%^ORANGE%^gh%^WHITE%^l"
"%^ORANGE%^y h%^BOLD%^%^BLACK%^e%^RESET%^%^WHITE%^w%^ORANGE%^n b%^BOLD%^%^BLACK%^u%^RESET%^%^WHITE%^n%^ORANGE%^ke"
"%^WHITE%^r%^CYAN%^.%^RESET%^\n");
   set_smell("default","The faint odor of chemicals");
   set_listen("default","The laughing of the wind through the mountain and trees.");

   set_items(([
      ({"precipice","ground","rock"}) : "The rock of the precipice is scarred with oddly shaped dents and holes, perhaps "
"enough to serve as hand-holds to descend by. Strange colors paint the ground as well, some you recognize, some that hurt "
"your brain when you try to. And other parts of the ground seem to be warping and shifting. Strange.",
      ({"summit","mountain"}) : "It's the summit of the southern mountain and it's covered with lots of trees. A "
"%^BOLD%^%^BLACK%^whisper %^RESET%^voices 'Yep, you climbed all this way just for trees. Congratulations.' Wait, who said that?",
      ({"trees","cluster","wood_thingies" }) : "The trees in the cluster like the precipice are discolored and damaged in "
"strange and indescribable ways. Branches seem to grow in patterns that defy the third dimension. A %^BOLD%^%^BLACK%^whisper "
"%^RESET%^hisses 'You should probably stop looking at them, otherwise your brain may herniate. Unless you meant the trees on the "
"summit in which case... why?' Who just asked that?",
      ({"bunker", "rough hewn bunker","riddle" }) : ({"Once you get close to the bunker you can make out it's pretty large. "
"It rises about a foot above the ground and every visible inch of this bunker is scorched and uneven, you can see deep "
"black jagged lines running everywhere as if it had been blown to pieces and then glued back together. Very narrow slits "
"run just above the surface providing ventilation, but no apparent entrance makes itself known otherwise. In the very "
"center of the bunker is carved a riddle you can read.","\n%^ORANGE%^Know me and know the greatest acts of love and "
"taste the most vile fruits of hatred. See me and see the most compassionate heroes stand with and against the most "
"merciless villains. Accept me and accept destruction untold and creation unimagined. Experience me and experience all, "
"reject me and %^RED%^all%^RESET%^%^ORANGE%^ will crumble. I am as natural as the air, the fires, the waters and the "
"earth. Without me civilization cannot be. %^CYAN%^What am I?%^RESET%^\n\n"
"You see a black space where you might be able to <trace answer> and a warning to young adventurers that it may be best "
"not to guess.\n"}),
      ({"slits","windows"}) : "These slits are very narrow, only a few inches high. In addition the roughhewn edges are "
"so jagged that even a pixie would get eviscerated trying to slip in through them.",
   ]));

   set_climb_exits(([
      "descend":({"/d/shadow/room/ekibi/room/p1",15,roll_dice(2,10),40}),
   ]));
}

void init(){
   ::init();
   add_action("trace_fun","trace");
   if(userp(TP)) call_out("notify_me",1);
}

void notify_me() {
   tell_object(TP,"You shiver and sense a presence upon winds, watching you.");
}

int trace_fun(string str){
   object secondroom, mymon;
   secondroom = find_object_or_load(ROOMS+"lab");
   if(!str) return notify_fail("What are you trying to trace?");
   if(member_array("ladder",TO->query_exits()) != -1) {
      if(str == "life") {
        tell_object(TP,"You trace your answer again and the trap door slides closed.");
        tell_room(ETP,""+TP->QCN+" traces an answer in the space and the trap door slides closed.",TP);
        remove_exit("ladder");
        if(member_array("ladder",secondroom->query_exits()) != -1) {
          secondroom->remove_exit("ladder");
          tell_room(secondroom,"The trap door slides closed.");
        }
        return 1;
      }
      return notify_fail("You trace your answer in the space and hold your breath... but nothing happens.");
   }
   if(str == "life") {
      tell_object(TP,"You trace your answer in the space and hold your breath... as a trap door slides open, revealing "
"a ladder down into the bunker.");
      tell_room(ETP,""+TP->QCN+" traces an answer in the space and you hold your breath... as a trap door slides open, "
"revealing a ladder down into the bunker.",TP);
      add_exit(ROOMS+"lab","ladder");
      secondroom->add_exit(ROOMS+"precipice","ladder");
      tell_room(secondroom,"A trap door slides open at the top of the ladder.");
      return 1;
   }
   if(str == "war") {
      tell_object(TP,"You trace your answer in the space and hold your breath... as a heavily armed and armored "
"whirlwind swirls into existence before you.");
      tell_room(ETP,""+TP->QCN+" traces an answer in the space and you hold your breath... as a heavily armed "
"and armored whirlwind swirls into existence before "+TP->QO+".",TP);
      if((int)TP->query_level() < 20) {
        tell_room(ETP,"The whirlwind lets out a gust of mocking laughter, 'You are hardly worth my time. Begone, pitiful "
"creature!'");
        tell_room(ETP,"A sudden blast of air erupts across the precipice, knocking "+TP->QCN+" flying!",TP);
        tell_object(ETP,"A sudden blast of air erupts across the precipice, knocking you flying!");
        return 1;
      }
      tell_room(ETP,"The whirlwind howls, 'Should have chosen a less obvious solution, thief. PREPARE TO DIE!");
      mymon = new(MON"airelemental");
      mymon->move(TO);
      mymon->force_me("kill "+TP->query_name());
      return 1;
   }
   return notify_fail("You trace your answer in the space and hold your breath... but nothing happens.");
}

void reset(){
   object secondroom;
   ::reset();
   secondroom = find_object_or_load(ROOMS"lab");
   if(member_array("ladder",TO->query_exits()) != -1) {
      remove_exit("ladder");
      tell_room(TO,"The trap door slides closed.");
      if(member_array("ladder",secondroom->query_exits()) != -1) {
         secondroom->remove_exit("ladder");
         tell_room(secondroom,"The trap door slides closed.");
      }
   }
}