//Ryzan and Aunuit's House
//Coded by ~Circe~ 5/2/13

#include <std.h>
#include "aunuit.h"
#include <daemons.h>

inherit AUNUIT;

#define POSITIONS ({"enemies","guests","members","leaders","owners"})

string *enemies = SAVE_D->query_array("rilynath_enemies");
string *members = SAVE_D->query_array("rilynath_members");
string *owners = SAVE_D->query_array("rilynath_owners");
string *guests = SAVE_D->query_array("rilynath_guests");
string *leaders = SAVE_D->query_array("rilynath_leaders");

int help_em(string str);
int get_authority(object obj);
void update();
int is_enemy(string str); //attempted this way to see if it would avoid the need to update the room before the changes take place, but the delay is still there.

void create(){
   ::create();
   set_name("Pools of Reveries");
   set_short("%^BOLD%^%^BLACK%^Pools of Reveries%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^Envel%^CYAN%^o%^BLACK%^ped in unnatural "
      "%^RESET%^%^MAGENTA%^f%^BOLD%^%^RED%^l%^ORANGE%^o%^GREEN%^r"
      "%^BLUE%^a %^BLACK%^that winds throughout the cavern completely "
      "obscuring its st%^RESET%^o%^BOLD%^%^BLACK%^ne walls, this "
      "%^MAGENTA%^paradise %^BLACK%^is clearly the work of powerful "
      "%^BLUE%^magic %^BLACK%^and dedicated maintenance. The main source "
      "of %^CYAN%^l%^ORANGE%^i%^WHITE%^g%^CYAN%^ht %^BLACK%^provided comes "
      "from the central feature of this massive %^RESET%^%^MAGENTA%^ga"
      "%^GREEN%^r%^MAGENTA%^den%^BOLD%^%^BLACK%^, a bla%^WHITE%^c%^BLACK%^k "
      "gl%^RESET%^a%^BOLD%^%^WHITE%^s%^BLACK%^s like tree adorned in "
      "hanging leafy v%^CYAN%^i%^BLACK%^nes that %^CYAN%^gl%^RESET%^"
      "%^CYAN%^o%^BOLD%^%^CYAN%^w br%^WHITE%^i%^RESET%^%^CYAN%^g%^BOLD%^"
      "%^WHITE%^h%^CYAN%^t bl%^BLUE%^u%^CYAN%^e %^BLACK%^like the light of "
      "a %^CYAN%^star%^BLACK%^. The tree is exalted on a hill that rises "
      "out of one of many %^RESET%^%^CYAN%^p%^BOLD%^%^CYAN%^o%^RESET%^"
      "%^CYAN%^nds %^BOLD%^%^BLACK%^which are connected in turn by smaller "
      "%^WHITE%^streams%^BLACK%^. A small %^BLUE%^w%^CYAN%^a%^RESET%^%^CYAN%^"
      "t%^BOLD%^%^WHITE%^e%^BLUE%^r%^RESET%^%^CYAN%^f%^BOLD%^%^BLUE%^a"
      "%^CYAN%^l%^RESET%^%^CYAN%^l %^BOLD%^%^BLACK%^descends through the "
      "%^BLUE%^v%^CYAN%^i%^BLUE%^nes %^BLACK%^along the north wall feeding "
      "the %^WHITE%^streams %^BLACK%^with its %^RESET%^%^CYAN%^cr%^BOLD%^"
      "%^CYAN%^y%^RESET%^%^CYAN%^sta%^BOLD%^%^WHITE%^l%^RESET%^%^CYAN%^l"
      "%^BOLD%^%^GREEN%^i%^RESET%^%^CYAN%^ne w%^BLUE%^a%^CYAN%^ter%^BOLD%^"
      "%^BLACK%^. There are no paved paths interrupting the gr%^GREEN%^o"
      "%^BLACK%^wth and coiled %^RESET%^%^MAGENTA%^th%^ORANGE%^o%^MAGENTA%^"
      "rny v%^BOLD%^%^MAGENTA%^i%^RESET%^%^MAGENTA%^nes %^BOLD%^%^BLACK%^"
      "threaten any who delve too deeply into the %^RESET%^%^MAGENTA%^f"
      "%^BOLD%^%^MAGENTA%^o%^RESET%^%^MAGENTA%^l%^ORANGE%^i%^GREEN%^a"
      "%^MAGENTA%^ge%^BOLD%^%^BLACK%^. Near the opening to this chamber "
      "a %^RESET%^%^ORANGE%^dark wood trellis %^BOLD%^%^BLACK%^overgrown "
      "with similar th%^RESET%^%^MAGENTA%^o%^BOLD%^%^BLACK%^rny vines "
      "has been placed, %^RESET%^%^ORANGE%^messages %^BOLD%^%^BLACK%^"
      "hanging from it like leaves.%^RESET%^\n");
   set_smell("default","%^RESET%^%^CYAN%^The heady scent of the beautiful "
      "phosphorescent flowers fills the cave.%^RESET%^");
   set_listen("default","%^BOLD%^%^BLACK%^Except for the occasional "
      "shout or clash of metal the soft babbling of the waterfall masks "
      "the sounds of the main cavern.%^RESET%^");
   set_items(([
      "tree" : "%^BOLD%^%^BLACK%^Standing tall and casting its %^CYAN%^a"
         "%^WHITE%^z%^CYAN%^u%^RESET%^%^CYAN%^r%^BOLD%^%^CYAN%^e l"
         "%^RESET%^%^CYAN%^u%^BOLD%^%^CYAN%^min%^WHITE%^e%^RESET%^%^CYAN%^"
         "s%^BOLD%^%^WHITE%^c%^RESET%^%^CYAN%^e%^BOLD%^%^CYAN%^nce "
         "%^BLACK%^across the %^CYAN%^pools %^BLACK%^this tree is the "
         "defining feature of the %^RESET%^%^MAGENTA%^ga%^GREEN%^r"
         "%^MAGENTA%^den%^BOLD%^%^BLACK%^. Its obs%^RESET%^i%^BOLD%^"
         "%^BLACK%^d%^WHITE%^i%^RESET%^a%^BOLD%^%^BLACK%^n limbs stretch "
         "across half the cave and from them descend long %^CYAN%^le"
         "%^RESET%^%^CYAN%^a%^BOLD%^%^CYAN%^fy str%^WHITE%^a%^RESET%^"
         "%^CYAN%^n%^BOLD%^%^CYAN%^ds %^BLACK%^that create a breathtaking "
         "%^WHITE%^illumination %^BLACK%^that br%^CYAN%^i%^RESET%^%^CYAN%^"
         "g%^WHITE%^h%^CYAN%^t%^BOLD%^%^CYAN%^e%^BLACK%^ns the cavern. In "
         "some places they brush against the surface of the %^CYAN%^pools"
         "%^BLACK%^, sending soft %^CYAN%^r%^RESET%^%^CYAN%^i%^BLUE%^pp"
         "%^CYAN%^l%^BOLD%^%^CYAN%^es %^BLACK%^out across the %^BLUE%^w"
         "%^CYAN%^a%^RESET%^%^CYAN%^t%^BOLD%^%^BLUE%^e%^CYAN%^r%^BLACK%^"
         ". The bark of the tree is a smooth gl%^RESET%^a%^BOLD%^"
         "%^WHITE%^s%^BLACK%^sy pl%^WHITE%^a%^BLACK%^ne but for very "
         "fine lines %^RESET%^etched %^BOLD%^%^BLACK%^upon its surface. "
         "Upon closer inspection it is apparent that the l%^WHITE%^i"
         "%^BLACK%^nes form %^WHITE%^script %^BLACK%^that fl%^RESET%^"
         "%^CYAN%^o%^BOLD%^%^BLACK%^ws seamlessly into itself and before "
         "your very eyes the lettering %^WHITE%^s%^RESET%^h%^BOLD%^"
         "%^BLACK%^i%^WHITE%^f%^RESET%^t%^BOLD%^%^BLACK%^s into your own language:\n\n"
         "%^BOLD%^%^WHITE%^%^WHITE%^'In memory of all who fought to "
         "restore what was lost. May their passion be our guiding "
         "light on our darkest days.'\n\n"
         "%^BOLD%^%^BLACK%^Beneath the message, hundreds of %^WHITE%^"
         "names %^BOLD%^%^BLACK%^are also etched into the s%^RESET%^u"
         "%^BOLD%^%^BLACK%^rfa%^WHITE%^c%^BLACK%^e of the tree, paying "
         "homage to the fallen.%^RESET%^",
      ({"pond","stream","waterfall"}) : "%^RESET%^%^CYAN%^Wat%^BOLD%^"
         "%^CYAN%^e%^RESET%^%^CYAN%^r tri%^BLUE%^c%^CYAN%^kles d%^BOLD%^"
         "%^CYAN%^o%^RESET%^%^CYAN%^wn the n%^WHITE%^o%^CYAN%^rth fa"
         "%^BOLD%^%^BLUE%^c%^RESET%^%^CYAN%^e of the %^BOLD%^%^BLACK%^"
         "ca%^RESET%^%^BOLD%^%^BLACK%^vern w%^RESET%^a%^BOLD%^%^BLACK%^ll "
         "%^RESET%^%^CYAN%^w%^BOLD%^%^CYAN%^i%^RESET%^%^CYAN%^nd%^WHITE%^"
         "i%^CYAN%^ng its w%^BLUE%^a%^CYAN%^y betw%^GREEN%^e%^BOLD%^"
         "%^CYAN%^e%^RESET%^%^CYAN%^n %^BOLD%^%^CYAN%^vines %^RESET%^"
         "%^CYAN%^and o%^BOLD%^%^BLUE%^v%^RESET%^%^CYAN%^er l%^BOLD%^"
         "%^CYAN%^a%^RESET%^%^CYAN%^rge %^WHITE%^blooming %^CYAN%^"
         "flowers le%^BOLD%^%^GREEN%^a%^RESET%^%^CYAN%^ving e%^GREEN%^"
         "v%^CYAN%^eryth%^BOLD%^%^BLUE%^i%^RESET%^%^CYAN%^ng %^BOLD%^"
         "%^WHITE%^glistening %^RESET%^%^CYAN%^in its w%^BLUE%^a%^CYAN%^"
         "ke. The %^BOLD%^%^CYAN%^water fall %^RESET%^%^CYAN%^fe%^BOLD%^"
         "%^BLUE%^e%^RESET%^%^CYAN%^ds %^BOLD%^%^WHITE%^streams %^RESET%^"
         "%^CYAN%^th%^BOLD%^%^GREEN%^a%^RESET%^%^CYAN%^t cr%^BLUE%^i%^CYAN%^"
         "sscr%^GREEN%^o%^CYAN%^ss the %^BOLD%^%^BLACK%^ca%^RESET%^v%^BOLD%^"
         "%^BLACK%^ern flo%^WHITE%^o%^BLACK%^r %^RESET%^%^CYAN%^and c"
         "%^BOLD%^%^BLUE%^o%^RESET%^%^CYAN%^ll%^GREEN%^e%^CYAN%^cts in "
         "the n%^BOLD%^%^GREEN%^a%^RESET%^%^CYAN%^tu%^BOLD%^%^CYAN%^r"
         "%^RESET%^%^CYAN%^al %^BOLD%^%^BLACK%^valleys %^RESET%^%^CYAN%^"
         "of the %^BOLD%^%^BLACK%^sto%^RESET%^n%^BOLD%^%^BLACK%^e "
         "%^RESET%^%^CYAN%^to cr%^BLUE%^e%^CYAN%^ate s%^BOLD%^%^BLUE%^"
         "e%^RESET%^%^CYAN%^ve%^GREEN%^r%^CYAN%^al %^BOLD%^%^CYAN%^"
         "bathing pools%^RESET%^%^CYAN%^.%^RESET%^",
      ({"foliage","vines"}) : "%^RESET%^%^CYAN%^The foliage that exists "
         "within this cave is %^BOLD%^%^CYAN%^otherworldly%^RESET%^"
         "%^CYAN%^; the %^BOLD%^%^BLACK%^walls %^RESET%^%^CYAN%^and "
         "%^BOLD%^%^BLACK%^fl%^RESET%^o%^BOLD%^%^WHITE%^o%^BLACK%^rs "
         "%^RESET%^%^CYAN%^are a veritable smorgasbord of %^BOLD%^%^WHITE%^"
         "glow%^RESET%^i%^BOLD%^%^WHITE%^ng %^MAGENTA%^c%^ORANGE%^o%^RESET%^"
         "%^RED%^l%^GREEN%^o%^MAGENTA%^r%^BOLD%^%^RED%^s %^RESET%^%^CYAN%^"
         "that reflect off the %^BOLD%^%^CYAN%^water %^RESET%^%^CYAN%^and "
         "%^WHITE%^motes %^CYAN%^of prec%^BOLD%^%^CYAN%^i%^RESET%^%^CYAN%^"
         "pitat%^BOLD%^%^WHITE%^i%^RESET%^%^CYAN%^on to create a %^WHITE%^"
         "ph%^BOLD%^%^CYAN%^o%^RESET%^%^CYAN%^s%^BOLD%^%^CYAN%^p%^RESET%^"
         "hor%^BOLD%^%^CYAN%^e%^RESET%^%^CYAN%^s%^BOLD%^%^CYAN%^c%^RESET%^"
         "ent haze%^CYAN%^. %^GREEN%^Sp%^MAGENTA%^i%^GREEN%^ny%^CYAN%^, "
         "snake-like v%^BOLD%^%^CYAN%^i%^RESET%^%^CYAN%^nes gl%^WHITE%^o"
         "%^CYAN%^w br%^BOLD%^%^CYAN%^i%^WHITE%^g%^CYAN%^h%^RESET%^"
         "%^CYAN%^t bl%^BOLD%^%^BLUE%^u%^RESET%^%^CYAN%^e and %^BOLD%^"
         "%^WHITE%^illuminate %^RESET%^%^CYAN%^the %^BOLD%^%^BLACK%^nooks "
         "%^RESET%^%^CYAN%^and %^BOLD%^%^BLACK%^crannies %^RESET%^%^CYAN%^"
         "of the room. Large %^BOLD%^%^BLUE%^f%^RESET%^%^ORANGE%^l%^BOLD%^"
         "%^GREEN%^o%^RESET%^%^BLUE%^w%^MAGENTA%^e%^BOLD%^%^ORANGE%^r"
         "%^MAGENTA%^s %^RESET%^%^CYAN%^burst forth from the meandering "
         "v%^BLUE%^i%^CYAN%^nes, their stems bedecked in sharp %^MAGENTA%^"
         "th%^GREEN%^o%^MAGENTA%^rns%^CYAN%^. The petals of the flowers "
         "display a brilliant array of shapes and %^RED%^h%^ORANGE%^u"
         "%^GREEN%^e%^BOLD%^%^BLUE%^s%^RESET%^%^CYAN%^, from a star-shaped, "
         "%^MAGENTA%^deep purple fl%^BOLD%^%^MAGENTA%^o%^RESET%^%^MAGENTA%^"
         "wer %^CYAN%^with gl%^BOLD%^%^WHITE%^o%^RESET%^%^CYAN%^wing "
         "%^BOLD%^%^WHITE%^white flecks %^RESET%^%^CYAN%^to a %^BOLD%^"
         "%^ORANGE%^yell%^RESET%^%^ORANGE%^o%^BOLD%^%^ORANGE%^w %^RESET%^"
         "%^CYAN%^bell-shaped %^ORANGE%^bulb %^CYAN%^with %^ORANGE%^t%^BOLD%^"
         "%^ORANGE%^i%^BLACK%^g%^RESET%^%^ORANGE%^e%^BOLD%^%^ORANGE%^r"
         "%^RESET%^%^CYAN%^-%^BOLD%^%^BLACK%^s%^RESET%^%^ORANGE%^t%^BOLD%^"
         "%^ORANGE%^r%^BLACK%^i%^RESET%^%^ORANGE%^p%^BOLD%^%^ORANGE%^e"
         "%^BLACK%^s%^RESET%^%^CYAN%^. All are %^MAGENTA%^exotic%^CYAN%^, "
         "gorgeous and %^BOLD%^%^WHITE%^luminescent%^RESET%^%^CYAN%^.%^RESET%^",
      "trellis" : "%^RESET%^%^CYAN%^Snake-like v%^BOLD%^%^CYAN%^i%^RESET%^"
         "%^CYAN%^nes climb up a braided %^ORANGE%^dark wood trellis %^CYAN%^"
         "that extends from a %^BOLD%^%^BLACK%^st%^RESET%^o%^BOLD%^%^BLACK%^ne "
         "b%^WHITE%^a%^RESET%^s%^BOLD%^%^BLACK%^e%^RESET%^%^CYAN%^. Any "
         "passersby that wish to leave a%^ORANGE%^ message %^CYAN%^can by "
         "impaling their parchment on one of the many %^MAGENTA%^th%^GREEN%^"
         "o%^MAGENTA%^rns %^CYAN%^that extend from the fat, gl%^BOLD%^%^CYAN%^"
         "o%^RESET%^%^CYAN%^w%^WHITE%^i%^CYAN%^ng v%^BOLD%^%^CYAN%^i%^RESET%^"
         "%^CYAN%^n%^BOLD%^%^WHITE%^e%^RESET%^%^CYAN%^s.%^RESET%^"
   ]));
   set_property("silent update",1);
   set_exits(([
      "west": ROOMS"dragons_landing"
   ]));
}

void reset() {
   object ob;
   ::reset();
   if (!objectp(present(getuid(TO)+"_board"))) {
      ob = new("std/bboard");
      ob->set_name(getuid(TO)+"board");
      ob->set_id( ({ "board", getuid(TO)+"_board", "my board" }) );
      ob->set_board_id(geteuid(TO)+"_board");
      ob->set_short("%^RESET%^%^CYAN%^A v%^BOLD%^%^CYAN%^i%^RESET%^"
         "%^CYAN%^n%^BOLD%^%^WHITE%^e%^RESET%^%^CYAN%^-s%^BOLD%^t%^RESET%^%^CYAN%^re%^BOLD%^"
         "%^WHITE%^w%^RESET%^%^CYAN%^n message board%^RESET%^");
      ob->set_long("%^RESET%^%^CYAN%^Snake-like v%^BOLD%^%^CYAN%^i%^RESET%^"
         "%^CYAN%^nes climb up a braided %^ORANGE%^dark wood trellis %^CYAN%^"
         "that extends from a %^BOLD%^%^BLACK%^st%^RESET%^o%^BOLD%^%^BLACK%^ne "
         "b%^WHITE%^a%^RESET%^s%^BOLD%^%^BLACK%^e%^RESET%^%^CYAN%^. Any "
         "passersby that wish to leave a%^ORANGE%^ message %^CYAN%^can by "
         "impaling their parchment on one of the many %^MAGENTA%^th%^GREEN%^"
         "o%^MAGENTA%^rns %^CYAN%^that extend from the fat, gl%^BOLD%^%^CYAN%^"
         "o%^RESET%^%^CYAN%^w%^WHITE%^i%^CYAN%^ng v%^BOLD%^%^CYAN%^i%^RESET%^"
         "%^CYAN%^n%^BOLD%^%^WHITE%^e%^RESET%^%^CYAN%^s.%^RESET%^\n");
      ob->set_max_posts(20);
      ob->set_ooc_board(0);
      ob->set_location(base_name(TO));
      ob->move(TO);
      ob->set_property("no steal",1);
   }
   switch(random(3)){
      case 0: tell_room(TO,"%^BOLD%^%^BLUE%^A group of dark "
              "elves lowers their heads reverently towards the great tree%^RESET%^");
              break;
      case 1: tell_room(TO,"%^MAGENTA%^A group of dark elven children splash "
              "playfully in one of the pools%^RESET%^");
              break;
      default: tell_room(TO,"%^BOLD%^%^CYAN%^Luminesce mist coalesces into the "
              "form of an elven warrior kneeling at the edge of one of the "
              "pools. The image dissipates as quickly as it appeared.%^RESET%^");
              break;
   }
}

void init(){
   ::init();
   add_action("add_em","add");
   add_action("erase_em","erase");
   add_action("list_em","list");
   add_action("help_em","help");
}

int get_authority(object obj){
   int authority;
   if(member_array(obj->query_name(), owners) != -1){
      authority = 3;
   }else if(member_array(obj->query_name(), leaders) != -1){
      authority = 2;
   }else if(member_array(obj->query_name(), members) != -1){
      authority = 1;
   }else{
      authority = 0;
   }
   return authority;
}

int is_enemy(string str){
   int enemy;
   if(member_array(str,enemies) != -1){
      enemy = 1;
   }else{
      enemy = 0;
   }
   return enemy;
}

int add_em(string str){
   string name,position,real;
   int auth;
   if(!str){
      help_em("here");
      return 1;
   }
   if(sscanf(str,"%s to %s",name,position) != 2){
      help_em("here");
      return 1;
   }
   if(member_array(position,POSITIONS) == -1){
      help_em("here");
      return 1;
   }
   if(TP->isKnown(name)){ 
      real = name; 
   }else{ 
      real = (string)TP->realName(name); 
   }
   if(real == ""){
      tell_object(TP,"You don't seem to know anyone named "+name+".");
      return 1;
   }
   auth = get_authority(TP);
   switch(position){
      case "enemies": if(auth < 1){
                         tell_object(TP,"You don't have the authority to do that!");
                         return 1;
                      }
                      if(is_enemy(real)){
                         tell_object(TP,""+capitalize(name)+" is already an enemy of the House!");
                         break;
                      }else{
                         SAVE_D->set_value("rilynath_enemies",real);
                         tell_object(TP,""+capitalize(name)+" has been added to the list of House enemies.");
                         break;
                      }
      case "members": if(auth < 2){
                         tell_object(TP,"You don't have the authority to do that!");
                         return 1;
                      }
                      if(member_array(real,members) != -1){
                         tell_object(TP,""+capitalize(name)+" is already a member of the House!");
                         break;
                      }else{
                         SAVE_D->set_value("rilynath_members",real);
                         tell_object(TP,""+capitalize(name)+" has been added to the list of House members.");
                         break;
                      }
      case "guests": if(auth < 1){
                         tell_object(TP,"You don't have the authority to do that!");
                         return 1;
                      }
                      if(member_array(real,guests) != -1){
                         tell_object(TP,""+capitalize(name)+" is already a guest of the House!");
                         break;
                      }else{
                         SAVE_D->set_value("rilynath_guests",real);
                         tell_object(TP,""+capitalize(name)+" has been added to the list of House guests.");
                         break;
                      }
      case "leaders":  if(auth < 3){
                         tell_object(TP,"You don't have the authority to do that! Please talk to a House owner.");
                         break;
                      }
                      if(member_array(real,leaders) != -1){
                         tell_object(TP,""+capitalize(name)+" is already a leader of the House!");
                         break;
                      }else{
                         SAVE_D->set_value("rilynath_leaders",real);
                         tell_object(TP,""+capitalize(name)+" has been added to the list of House leaders.");
                         break;
                      }
      case "owners":  if(auth < 3){
                         tell_object(TP,"You don't have the authority to do that! Please talk to a House owner.");
                         break;
                      }
                      if(member_array(real,owners) == 1){
                         tell_object(TP,""+capitalize(name)+" is already an owner of the House!");
                         break;
                      }else{
                         SAVE_D->set_value("rilynath_owners",real);
                         tell_object(TP,""+capitalize(name)+" has been added to the list of House owners.");
                         break;
                      }
      default: tell_object(TP,"Something seems to have gone wrong! Please try again.");
               break;
   }
   update();
   return 1;
}


int erase_em(string str){
   string name,position,real;
   int auth;
   if(!str){
      help_em("here");
      return 1;
   }
   if(sscanf(str,"%s from %s",name,position) != 2){
      help_em("here");
      return 1;
   }
   if(member_array(position,POSITIONS) == -1){
      help_em("here");
      return 1;
   }
   if(TP->isKnown(name)){ 
      real = name; 
   }else{ 
      real = (string)TP->realName(name); 
   }
   if(real == ""){
      tell_object(TP,"You don't seem to know anyone named "+name+".");
      return 1;
   }
   auth = get_authority(TP);
   switch(position){
      case "enemies": if(auth < 1){
                         tell_object(TP,"You don't have the authority to do that!");
                         return 1;
                      }
                      if(is_enemy(real)){
                         SAVE_D->remove_name_from_array("rilynath_enemies",real);
                         tell_object(TP,""+capitalize(name)+" has been removed from the list of House enemies.");
                         break;
                      }else{
                         tell_object(TP,""+capitalize(name)+" is not an enemy of the House!");
                         break;
                      }
      case "members": if(auth < 2){
                         tell_object(TP,"You don't have the authority to do that!");
                         return 1;
                      }
                      if(member_array(real,members) == -1){
                         tell_object(TP,""+capitalize(name)+" is not a member of the House!");
                         break;
                      }else{
                         SAVE_D->remove_name_from_array("rilynath_members",real);
                         tell_object(TP,""+capitalize(name)+" has been removed from the list of House members.");
                         break;
                      }
      case "guests": if(auth < 1){
                         tell_object(TP,"You don't have the authority to do that!");
                         return 1;
                      }
                      if(member_array(real,guests) == -1){
                         tell_object(TP,""+capitalize(name)+" is not a guest of the House!");
                         break;
                      }else{
                         SAVE_D->remove_name_from_array("rilynath_guests",real);
                         tell_object(TP,""+capitalize(name)+" has been removed from the list of House guests.");
                         break;
                      }
      case "leaders":  if(auth < 3){
                         tell_object(TP,"You don't have the authority to do that! Please talk to a House owner.");
                         break;
                      }
                      if(member_array(real,leaders) == -1){
                         tell_object(TP,""+capitalize(name)+" is not a leader of the House!");
                         break;
                      }else{
                         SAVE_D->remove_name_from_array("rilynath_leaders",real);
                         tell_object(TP,""+capitalize(name)+" has been removed from the list of House leaders.");
                         break;
                      }
      case "owners":  if(auth < 3){
                         tell_object(TP,"You don't have the authority to do that! Please talk to a House owner.");
                         break;
                      }
                      if(member_array(real,owners) == -1){
                         tell_object(TP,""+capitalize(name)+" is not an owner of the House!");
                         break;
                      }else{
                         SAVE_D->remove_name_from_array("rilynath_owners",real);
                         tell_object(TP,""+capitalize(name)+" has been removed from the list of House owners.");
                         break;
                      }
      default: tell_object(TP,"Something seems to have gone wrong! Please try again.");
               break;
   }
   update();
   return 1;
}

int list_em(string str){
   string listtext, *listkeys, name;
   mapping list;
   int i,access,auth;

   list = ([]);

   if(!str){
      help_em("here");
      return 1;
   }
   if(member_array(str,POSITIONS) == -1){
      help_em("here");
      return 1;
   }
   auth = get_authority(TP);
   switch(str){
      case "enemies": if(auth < 1){
                         tell_object(TP,"You don't have the authority to do that!");
                         return 1;
                      }
                      list = SAVE_D->query_array("rilynath_enemies");
                      break;
      case "members": if(auth < 1){
                         tell_object(TP,"You don't have the authority to do that!");
                         return 1;
                      }
                      list = SAVE_D->query_array("rilynath_members");
                      break;
      case "owners": if(auth < 1){
                         tell_object(TP,"You don't have the authority to do that!");
                         return 1;
                      }
                      list = SAVE_D->query_array("rilynath_owners");
                      break;
      case "guests": if(auth < 1){
                         tell_object(TP,"You don't have the authority to do that!");
                         return 1;
                     }
                     list = SAVE_D->query_array("rilynath_guests");
                     break;
      case "leaders": if(auth < 1){
                         tell_object(TP,"You don't have the authority to do that!");
                         return 1;
                     }
                     list = SAVE_D->query_array("rilynath_leaders");
                     break;
   }
   listtext = "The following individuals are "+str+" of House Rilynath.\n";
   listtext += ""
   "%^BOLD%^%^BLACK%^====================================================================%^RESET%^\n";
   
   if(!list || list == ""){
      tell_object(TP,"There are no "+str+" for House Rilynath!");
      return 1;
   }
   for(i=0;i<sizeof(list);i++){
      name = list[i];
      if(TP->isKnown(name)){
         name = TP->knownAs(name);
      }else{
         name = name;
      }
      if(name == "circe") continue;
      listtext += ""+capitalize(name)+"\n";
   }
   listtext += ""
   "%^BOLD%^%^BLACK%^====================================================================%^RESET%^\n";
   TP->more(explode(listtext,"\n"));
   return 1;    
}

void update(){
   "/cmds/system/_update.c"->cmd_update();
   return 1;
}

int help_em(string str){
   if(!str || str == "here"){
      write("A member of House Rilynath may:\n"
         "   add [name] to [guests | enemies]\n"
         "   erase [name] from [guests | enemies]\n"
         "   list [enemies | guests | members | leaders | owners]\n\n"
         "In addition, a leader of House Rilynath may:\n"
         "   add [name] to [members]\n"
         "   erase [name] from [members]\n\n"
         "House owners may also:\n"
         "   add [name] to [leaders | owners]\n"
         "   erase [name] from [leaders | owners]\n");
      return 1;
   }
   return 0;
}
