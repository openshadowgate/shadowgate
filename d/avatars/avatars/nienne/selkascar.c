#include <std.h>
#include <daemons.h>
inherit ARMOUR;

int uses, open, tracker, trackerb;
object ob, user, to, from;
string short;
string file;

int duskgate(string str);
int open_gate();
int close_gate();

void create(){
   ::create();
   set_name("scar");
   set_id(({ "scar","small scar" }));
   set_short("%^RESET%^%^RED%^a small scar%^RESET%^");
   set_long("This is a small, long-healed scar on the hand.\n%^YELLOW%^Your "
"commands are:%^RESET%^ summon selka, duskgate (open/close/set).\n");
   set_weight(0);
   set_value(0);
   set_type("ring");
   set_limbs(({"right hand","left hand"}));
   set_size(2);
   set_ac(1);
   set_property("enchantment",-1);
   set_wear((:TO,"wear_fun":));
   set_property("death keep",1);
   set_hidden(1);
   set_property("rift key", 1);
   uses = 0;
   open = 0;
   tracker = 0;
   trackerb = 0;
}

int is_detectable() { return 0; }

void init(){
   ::init();
   add_action("summon_fun","summon");
   add_action("duskgate","duskgate");
}

int wear_fun(){
    if((string)TP->query_name() != "aynetta" && !avatarp(TP)) {
      tell_object(TP,"You can't wear that.");
      return 0;
    }
    TO->set_hidden(1);
    return 1;
}

int summon_fun(string str) {
    if(!str) {
      notify_fail("Summon what?");
      return 0;
    }
    if(str != "selka" && str != "Selka") {
      notify_fail("Nothing happens.");
      return 0;
    }
    if(present("selka")) {
      tell_object(TP,"That is already here!");
      return 1;
    }
    if(!TO->query_worn()) {
      tell_object(TP,"You need to have the scar on you.");
      return 1;
    }
    tell_room(EETO,"%^RESET%^%^BLUE%^"+TP->QCN+" calls quietly to something "
"unseen, and from a scar on "+TP->QP+" hand emerges a small, %^BOLD%^%^BLACK%^"
"shadowy %^RESET%^%^BLUE%^object.%^RESET%^",TP);
    tell_object(TP,"%^BLUE%^You call quietly to the selka, and it emerges "
"from the scar on your hand.%^RESET%^");
    ob=find_object_or_load("/d/avatars/nienne/selka");
    ob->move(EETO);
    return 1;
}

int duskgate(string str){
   int i, all;
   string temp;

   if(TP->query_bound() || TP->query_unconscious()){
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   if(!TO->query_worn()) {
     tell_object(TP,"You need to have the scar on you.");
     return 1;
   }
   switch(str) {
   case "close":
      if(!open) return 0;
      tell_object(user, "You will the selka to close the duskgate.");
      close_gate();
      break;
   case "open":
      if((!file) || (!short)) {
        tell_object(TP, "The little selka has nowhere memorized.");
        return 1;
      }
      if(!present("selka",ETP)) {
        tell_object(TP, "The little selka is not here!");
        return 1;
      }
      if(open) break;
      if(environment(TP)->query_property("no teleport")) {
         tell_object(TP, "There is too much magical interference here.");
         return 1;
      }
      else {
         from = environment(TP);
         to = find_object_or_load(file);
         if(to == from) {
            tell_object(TP, "There's no point making a gate to this place, "
"you are already here!");
            return 1;
         }
         if (to->query_property("no teleport")) {
            tell_object(TP, "There is too much magical interference.");
            return 1;
         }
         if(tracker > time()) {
            tell_object(TP,"The selka is too weary to open another gate now.");
            return 1;
         }
         if(trackerb) {
            tracker = time() + 28800;
            trackerb = 0;
         }
         else { trackerb = 1; }
         user = TP;
         open_gate();
      }
      break;
   case "set":
      if(environment(TP)->query_property("no teleport")) {
        tell_object(TP,"There is too much magical interference here.");
        return 0;
      }
      if(!present("selka",ETP)) {
        tell_object(TP, "The little selka is not here!");
        return 1;
      }
      else
         file = base_name(environment(TP));
         short = environment(TP)->query_short();
         tell_object(TP,"The selka remembers "+short+"%^RESET%^ as its "
"location.\n");
         return 1;
      break;
   default:
      if(!present("selka",ETP)) {
        tell_object(TP, "The little selka is not here!");
        return 1;
      }
      if((!file) || (!short)) {
        tell_object(TP,"The selka has nowhere remembered.");
        return 1;
      }
      tell_object(TP,"The selka remembers "+short+"%^RESET%^ as its "
"location.");
      break;
   }
   return 1;
}

int open_gate(){
   tell_room(from,"%^BLUE%^The little selka spins and whirls through the air, "
"as traces of shadow follow its path. The traces drift together to form a "
"hazy mass of shadow before you, which shimmers a little, and then opens to "
"reveal a %^BOLD%^%^BLACK%^gate %^RESET%^%^BLUE%^to another place!%^RESET%^");
   tell_room(to, "%^BLUE%^A hazy mass of shadow comes into being before you, "
"shimmers a little, and then opens to reveal a %^BOLD%^%^BLACK%^gate "
"%^RESET%^%^BLUE%^to another place!%^RESET%^");
   to->add_exit(base_name(from), "gate");
   from->add_exit(base_name(to), "gate");
   open = 1;
   uses = random(4)+3;
   set_heart_beat(5);
   return 1;
}

int close_gate(){
   set_heart_beat(0);
   tell_room(to,"%^BLUE%^The hazy %^BOLD%^%^BLACK%^duskgate%^RESET%^%^BLUE%^ "
"shimmers and then dissipates before your eyes!%^RESET%^");
   tell_room(from,"%^BLUE%^The hazy %^BOLD%^%^BLACK%^duskgate%^RESET%^"
"%^BLUE%^ shimmers and then dissipates before your eyes!%^RESET%^");
   to->remove_exit("gate");
   from->remove_exit("gate");
   to = 0; from = 0; open = 0; uses = 0;
   return 1;
}

int heart_beat(){
   if(uses <= 0) {
     set_heart_beat(0);
     close_gate();
     return 1;
   }
   uses--;
   return 1;
}
