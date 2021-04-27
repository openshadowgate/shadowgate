// Added Belendithas as HM shop assistant. Nienne, 05/08.
#include <std.h>
#include "/d/player_houses/defines.h"
#define LSTOR "/d/player_houses/lusell/"
#define LROOMS "/d/player_houses/lusell/rooms/"

#define MAX_ITEMS 8

inherit "/std/pstore";

void create() {
   ::create();
   set_property("indoors",1);
   set_property("light",2);
   set_travel(PAVED_ROAD);
   set_terrain(CITY);
   set_drop_deposit(400);
   set_storage(LSTOR+"sell");
   set_drop_storage(LSTOR+"repairs");
   set_items_allowed(({"clothing","leather","material"}));
   set_owners(({"lusell","saide","styx","cythera","belendithas"}));
   set_short("Small Tailor Shop");
   set("long",
      "%^RESET%^%^ORANGE%^There is relative silence in this shop.  Shelves line three of"+
      " the walls.  A counter lines the fourth, covered in sales receipts, cloth"+
      " pieces and adorned with a small sign.  The floor looks as if it hasn't been cleaned"+
      " since the place was built and the walls don't look much better.  Every now"+
      " and then an attendant wanders into the room and stocks the shelves"+
      " with items.  There is a small brown door behind the counter to the north.%^RESET%^");
   set_smell("default","%^RESET%^%^GREEN%^The smell of dyes and sweat linger in the air.");
   set_listen("default","%^RESET%^%^BLUE%^The silence is almost deafening.");
   set_items(([
    "shelves" : "%^RESET%^%^ORANGE%^The shelves reach from the floor to the ceiling and cover three of the four walls.  They appear to be fully stocked with all types of clothing.%^RESET%^",
    "counter" : "%^RESET%^%^ORANGE%^You can't tell what the counter is made of because of all the receipts and cloth remnants laying on it.  A small sign adorns the center of the front of it.  It is absolutely a mess.",
    "sign" : "%^BOLD%^%^WHITE%^Clothier Shop:  Prices %^BOLD%^%^YELLOW%^non-negotiable%^BOLD%^%^WHITE%^ and set by management.\nAll sales final.\nYou must pay a deposit of %^YELLOW%^"+TO->query_deposit()+" gold%^BOLD%^%^WHITE%^ to drop off items you want repaired.\n\n%^RED%^Please see <help shop> for help on using this store.%^RESET%^",
   ]));
   set_exits(([
    "south" : LROOMS+"shop_entrance",
    "north" : LROOMS+"shop_closet",
   ]));
   set_door("old pine door","/d/player_houses/lusell/rooms/shop_entrance","south",0,"lock");
     set_locked("old pine door",0,"lock");
     set_lock_description("old pine door","lock","%^MAGENTA%^This is a strangely designed lock.  The keyhole is thin and is horizontal rather than vertical.  Several small holes line the edge of it, suggesting that whatever key fits this lock is quite complex.%^RESET%^");
     set_door_description("old pine door", "%^GREEN%^This door is made from several thick and aged pine slabs.  The slabs have been woven together with a thick rope.  A knob sets on one side of it with a horizontal keyhole in the center of it.%^RESET%^");
   set_door("brown door",LROOMS+"shop_closet","north","lusell_shop_key","lock");
     set_door_description("brown door", "%^MAGENTA%^This door is made from a dark brown wood that has an oddly shaped keyhole inset into the right side of it.%^RESET%^");
     set_locked("brown door",1,"lock");
     set_lock_description("brown door","lock","%^MAGENTA%^This is a strangely designed lock.  The keyhole is thin and is horizontal rather than vertical.  Several small holes line the edge of it, suggesting that whatever key fits this lock is quite complex.%^RESET%^");
     lock_difficulty("brown door",10,"lock");
}

void init() {
  ::init();
  add_action("request_new_key","request");
  /*
  Taken out for now - until I figure out a way to make
  the deposit change save through boot OR styx makes
  changing deposit an ability of a player_store
  add_action("adjust_deposit","adjust");
  */
}

void reset() {
  ::reset();
  if(!present("ceruta sol")) {
    if(!objectp(environment(find_object_or_load(CLERKS+"lusell_clerk"))))
       find_object_or_load(CLERKS+"lusell_clerk")->move(TO);
  }
}

int request_new_key(string str) {
  object ob;
  if(!str) return 0;
  if(str == "ring") {
   if(ob = present("ceruta sol")) {
    ob->force_me("speak common");
    if(member_array(TPQN,query_owners()) == -1) {
     ob->force_me("emote shakes her head");
     ob->force_me("say I don't know you, you've no business with a ring.");
     return 1;
    }
    if(!present("lusell_shop_key",ob)) {
      ob->force_me("emote hmms");
      ob->force_me("say I seem to have misplaced my ring... you'll have to wait until I get a new one.");
       return 1;
    }
    ob->force_me("say okay, but don't lose this ring, it's the only one I've got until I can get a new one made.");
    ob->force_me("remove ring");
    ob->force_me("give lusell_shop_key to "+TPQN);
    return 1;
   }
   return 0;
  }
  return 0;
}

/*
int adjust_deposit(string str) {
  object ob;
  int x;
  if(!str) return 0;
  if(ob = present("ceruta sol")) {
    ob->force_me("speak common");
    if(member_array(TPQN,query_owners()) == -1) {
      ob->force_me("emote shakes her head");
      ob->force_me("say I don't know you and you've no place "+
      "in the way the shop is run.");
      return 1;
    }
    if(sscanf(str,"%d",x) != 1) {
      ob->force_me("emote hmms");
      ob->force_me("say I'm afraid I need a value, not a word");
      return 1;
    }
    ob->force_me("say okay, I'll now require customers to pay "+
    x+ " gold pieces as a deposit to getting items repaired.");
    TO->set_drop_deposit(x);
    return 1;
  }
  return 0;
}
*/
