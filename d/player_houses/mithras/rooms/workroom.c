#include <std.h>
#include <daemons.h>
#include "../defs.h"
//#define SAVE_D "/daemon/save_d"
inherit "/std/library.c";

int randecho, clothstore;

void create() {
    ::create();
    set_public_library(0);
    set_library_name("mithras_library");
    set_deposit(0);
    set_property("indoors",1);
    set_property("light",2);
    set_terrain(BRANCHES);
    set_travel(LEDGE);
    set_name("A tidy workroom");
    set_short("%^RESET%^%^ORANGE%^A ti%^GREEN%^d%^ORANGE%^y wo%^GREEN%^rk%^ORANGE%^room%^RESET%^");
    set_long((:TO,"long_desc":));
    set_smell("default","%^RESET%^%^ORANGE%^The air bears the clean, %^GREEN%^e%^ORANGE%^ar%^GREEN%^thy %^ORANGE%^smell of fresh herbs.%^RESET%^");
    set_listen("default","%^RESET%^%^GREEN%^Sound is %^MAGENTA%^mut%^BOLD%^e%^RESET%^%^MAGENTA%^d %^GREEN%^by the tree's thick trunk, leaving it very %^CYAN%^q%^GREEN%^uie%^CYAN%^t %^GREEN%^here.%^RESET%^");

    set_items(([
      ({"walls","roof","floor"}) : (:TO,"walls_desc":),
      "bench" : "%^ORANGE%^A flat wooden bench sits against one of the walls, with several shelves mounted above it.  Upon the bench itself sit a case of %^CYAN%^empty vials%^ORANGE%^, beside a "
"mortar and pestle made of %^RESET%^s%^BOLD%^%^BLACK%^t%^RESET%^o%^BOLD%^%^BLACK%^n%^RESET%^e%^ORANGE%^.  A small burner sits off to the side, unlit, along with several empty bowls, and one "
"filled with %^BOLD%^%^CYAN%^wat%^BLUE%^e%^CYAN%^r%^RESET%^%^ORANGE%^.  A case sitting at the very end of the bench opens to reveal folded lengths of clean %^RESET%^gauze%^ORANGE%^, several "
"sharp scalpels, needles and thread, and a pair of scissors.%^RESET%^",
      ({"shelves","herbs","containers","clippings","flowers"}) : "%^ORANGE%^Several long %^RESET%^w%^BOLD%^%^BLACK%^oo%^RESET%^d%^BOLD%^%^BLACK%^e%^RESET%^n %^ORANGE%^shelves have been mounted "
"upon the wall above the bench.  Upon them sit numerous jars, bottles and sachets.  Many of them lie empty, while others are filled with %^CYAN%^li%^GREEN%^qu%^CYAN%^ids %^ORANGE%^and %^RESET%^"
"po%^BOLD%^%^WHITE%^w%^RESET%^ders %^ORANGE%^both unfamiliar and known.  Hanging from the lowest shelf are several samples of %^GREEN%^he%^ORANGE%^rb%^GREEN%^s %^ORANGE%^and %^RED%^f%^BOLD%^l"
"%^MAGENTA%^o%^RESET%^%^MAGENTA%^w%^RED%^e%^BOLD%^r%^RESET%^%^RED%^s%^ORANGE%^, suspended there to dry out for later use.%^RESET%^",
      ({"table","fabric","needles","thread","scissors","tape","measuring tape"}) : (:TO,"table_desc":),
      ({"bookshelf","shelf"}) : "%^ORANGE%^Against the back wall stands a large bookshelf of %^RESET%^pa%^BOLD%^%^BLACK%^l%^RESET%^e bi%^BOLD%^%^BLACK%^rc%^RESET%^hwo%^BOLD%^%^BLACK%^o%^RESET%^d"
"%^ORANGE%^, not nearly full, but still well stocked with a variety of tomes.  A few appear to have seen better days, but most look %^CYAN%^new %^ORANGE%^and freshly bound, as though whoever "
"stocked the collection was more inclined to make copies of them, rather than procure an original.%^RESET%^",
      ({"chair","chairs"}) : "%^ORANGE%^Two chairs sit in this room, both of %^RESET%^p%^BOLD%^%^BLACK%^a%^RESET%^le %^ORANGE%^wooden frames set with comfortable %^CYAN%^p%^GREEN%^ad%^CYAN%^di"
"%^GREEN%^n%^CYAN%^g%^ORANGE%^.  They look fairly new, only a little worn from use.  One lies close to the bookshelf, while the other is tucked in by the long table.%^RESET%^",
      "lanterns" : "%^ORANGE%^Twin lanterns stand one at each side of the room.  Consisting of single small cages, they are carved with %^GREEN%^e%^CYAN%^le%^GREEN%^ga%^CYAN%^n%^GREEN%^t "
"%^ORANGE%^simplicity, though no candle or oil lies within, leaving you to surmise that the soft %^YELLOW%^gl%^WHITE%^o%^YELLOW%^w%^RESET%^%^ORANGE%^ emitted by each is raised by some form of "
"spellcraft.  Each is supported upon a curved stand of %^RESET%^g%^BOLD%^%^BLACK%^r%^RESET%^ay bi%^BOLD%^%^BLACK%^rc%^RESET%^hwo%^BOLD%^%^BLACK%^o%^RESET%^d%^ORANGE%^, matched with the rest of "
"the room's furnishings.%^RESET%^",
      "stairs" : "%^ORANGE%^A series of simple, smooth wooden stairs follow the curve of the wall, leading up through a small hole in the roof to a room above.%^RESET%^",
    ]));
    randecho = random(12);
    clothstore = 0;
    set_exits(([
      "up" : ROOMS"tree",
    ]));
}

void init() {
   string myname,myadj;
   ::init();
   add_action("sense_it","sense");
   add_action("purge_it","purge");
   add_action("cloth_func","retrieve");
   if(!objectp(TP)) return;
   if(!userp(TP)) return;
   if(TP->query_invis()) return;
   if(sscanf((string)TP->query_short(),"%s, %s", myname, myadj) != 2)
     myadj = (string)TP->query_short();
   if(member_array(myadj,(string *)SAVE_D->query_array("mithras_tree")) == -1) {
     if((string)TP->query_name() != "marie" && (string)TP->query_name() != "mithras")
       SAVE_D->set_value("mithras_tree",myadj);
   }
   if(userp(TP) && !present("eldathynwardxxx",TP)) new(OBJ"eldathynward")->move(TP);
}

string long_desc() {
   return("%^RESET%^%^ORANGE%^This room is of an uneven shape, neither square nor properly circular, with the smooth floor and tapering walls all formed of pale %^RESET%^s%^BOLD%^%^WHITE%^i"
"%^RESET%^lv%^BOLD%^%^BLACK%^e%^RESET%^r-g%^BOLD%^%^WHITE%^r%^RESET%^a%^BOLD%^%^BLACK%^y %^RESET%^%^ORANGE%^wood that seems to have grown naturally into shape.  Simple, solid furnishings take "
"up much of the space here, with one wall dominated by a flat wooden bench and several shelves above.  They are set about with a variety of %^RESET%^co%^CYAN%^n%^RESET%^tai%^CYAN%^ne%^RESET%^rs"
"%^ORANGE%^, while several clippings of %^GREEN%^h%^ORANGE%^er%^GREEN%^bs %^ORANGE%^and %^RED%^f%^BOLD%^l%^MAGENTA%^o%^RESET%^%^MAGENTA%^w%^RED%^e%^BOLD%^r%^RESET%^%^RED%^s %^ORANGE%^hang from "
"beneath to dry.  Opposite this stands a long table, set about with lengths of folded fabric in a %^MAGENTA%^m%^RED%^y%^ORANGE%^r%^GREEN%^i%^CYAN%^a%^BLUE%^d %^ORANGE%^colors and weaves, with a "
"comfortable chair resting beside it.  Needles and thread, scissors and measuring tape all lie neatly organized upon the table itself, easily within reach.  Against the rear wall stands a "
"single broad bookshelf, far from full but still set about with a variety of %^BLUE%^tomes%^ORANGE%^, while a second chair sits off to the side.  A pair of softly %^YELLOW%^glow%^WHITE%^i"
"%^YELLOW%^ng %^RESET%^%^ORANGE%^lanterns are supported by curved stands, shedding clear illumination about the room.  A set of simple wooden stairs lead along the line of the wall, up into "
"another room above.%^RESET%^\n");
}

string walls_desc() {
   if((string)TP->query_name() == "marie" || (string)TP->query_name() == "mithras" || avatarp(TP)) 
     return "%^ORANGE%^The uneven shape of the room's walls is caused perhaps by the growth of the tree it resides in.  It seems impossible that the tree could've grown this precisely without "
"some kind of direction, though, for the floor is surprisingly flat underfoot.  Both it and the walls are of a pale %^RESET%^s%^BOLD%^%^WHITE%^i%^RESET%^lv%^BOLD%^%^BLACK%^e%^RESET%^r-g"
"%^BOLD%^%^WHITE%^r%^RESET%^a%^BOLD%^%^BLACK%^y %^RESET%^%^ORANGE%^wood, smooth to the touch.  It seems that this room is likely near the base of the tree, for only thick wooded trunk seems to "
"enclose the area, with no branches apparent to leave gaps for %^RESET%^l%^BOLD%^i%^YELLOW%^g%^WHITE%^h%^RESET%^t %^ORANGE%^or %^CYAN%^w%^BLUE%^e%^CYAN%^a%^BOLD%^t%^BLUE%^he%^RESET%^%^BLUE%^r "
"%^ORANGE%^to slip through.  Your inner connection to the tree itself leaves you knowing that you could %^RESET%^sense trespassers%^ORANGE%^ that have been here, or %^RESET%^purge trespassers"
"%^ORANGE%^ to soothe the tree of its recollections.%^RESET%^";
   return "%^ORANGE%^The uneven shape of the room's walls is caused perhaps by the growth of the tree it resides in.  It seems impossible that the tree could've grown this precisely without "
"some kind of direction, though, for the floor is surprisingly flat underfoot.  Both it and the walls are of a pale %^RESET%^s%^BOLD%^%^WHITE%^i%^RESET%^lv%^BOLD%^%^BLACK%^e%^RESET%^r-g"
"%^BOLD%^%^WHITE%^r%^RESET%^a%^BOLD%^%^BLACK%^y %^RESET%^%^ORANGE%^wood, smooth to the touch.  It seems that this room is likely near the base of the tree, for only thick wooded trunk seems to "
"enclose the area, with no branches apparent to leave gaps for %^RESET%^l%^BOLD%^i%^YELLOW%^g%^WHITE%^h%^RESET%^t %^ORANGE%^or %^CYAN%^w%^BLUE%^e%^CYAN%^a%^BOLD%^t%^BLUE%^he%^RESET%^%^BLUE%^r "
"%^ORANGE%^to slip through.%^RESET%^";
}

string table_desc() {
   if(((string)TP->query_name() == "marie" || (string)TP->query_name() == "mithras" || avatarp(TP)) && !clothstore)
     return "%^ORANGE%^A long, plain table of %^RESET%^pa%^BOLD%^%^BLACK%^l%^RESET%^e bi%^BOLD%^%^BLACK%^rc%^RESET%^hwo%^BOLD%^%^BLACK%^o%^RESET%^d%^ORANGE%^ takes up a decent portion of one "
"side of the room.  Upon it lie lengths of %^MAGENTA%^fo%^RED%^lde%^ORANGE%^d c%^GREEN%^l%^CYAN%^ot%^BLUE%^h%^ORANGE%^, and scraps here and there as testament to pieces already used.  A cushion "
"of needles sits further back, along with several spools of thread, a measuring tape and a pair of fine, sharp scissors.  You could %^RESET%^retrieve cloth%^ORANGE%^ to get the best piece of "
"those remaining.%^RESET%^";
     return "%^ORANGE%^A long, plain table of %^RESET%^pa%^BOLD%^%^BLACK%^l%^RESET%^e bi%^BOLD%^%^BLACK%^rc%^RESET%^hwo%^BOLD%^%^BLACK%^o%^RESET%^d%^ORANGE%^ takes up a decent portion of one "
"side of the room.  Upon it lie lengths of %^MAGENTA%^fo%^RED%^lde%^ORANGE%^d c%^GREEN%^l%^CYAN%^ot%^BLUE%^h%^ORANGE%^, and scraps here and there as testament to pieces already used.  A cushion "
"of needles sits further back, along with several spools of thread, a measuring tape and a pair of fine, sharp scissors.%^RESET%^";
}

int cloth_func(string str) {
   if(!str) return 0;
   if(str != "cloth") return 0;
   if((string)TP->query_name() != "marie" && (string)TP->query_name() != "mithras" && !avatarp(TP)) {
     tell_object(TP,"%^BOLD%^%^WHITE%^You rummage around the worktable but find nothing of use.%^RESET%^");
     tell_room(TO, "%^BOLD%^%^WHITE%^"+TPQCN+" rummages around the worktable, but doesn't seem to find anything useful.%^RESET%^",TP);
     return 1;
   }
   if(clothstore) {
     tell_object(TP,"%^BOLD%^%^WHITE%^The best of the cloth here has already been taken.%^RESET%^");
     return 1;
   }
   tell_object(TP,"%^BOLD%^%^WHITE%^You rummage around the worktable and find some serviceable cloth.%^RESET%^");
   tell_room(TO,"%^BOLD%^%^WHITE%^"+TP->QCN+" rummages around the worktable and finds a length of serviceable cloth.%^RESET%^",TP);
   new("/std/obj/cloth")->move(TO);
   clothstore = 1;
   return 1;
}

int sense_it(string str) {
   string *observed, mymessage;
   int i;
   if(!str) return 0;
   if(str != "trespassers") return 0;
   if(!avatarp(TP) && (string)TP->query_name() != "marie" && (string)TP->query_name() != "mithras") {
     tell_object(TP,"%^CYAN%^You try as you might to attune your senses to the tree, but you cannot sense any trespassers.%^RESET%^");
     tell_room(TO,"%^CYAN%^"+TP->QCN+" closes "+TP->QP+" eyes and concentrates briefly.%^RESET%^",TP);
     return 1;
   }
   observed = ({});
   observed += (string *)SAVE_D->query_array("mithras_tree");
   if(!sizeof(observed)) {
     tell_object(TP,"%^CYAN%^You grow still and attune yourself to the tree, but its peaceful nature tells you it has sensed noone here.%^RESET%^");
     tell_room(TO,"%^CYAN%^"+TP->QCN+" closes "+TP->QP+" eyes and concentrates briefly.%^RESET%^",TP);
     return 1;
   }
   mymessage = observed[i];
   for(i = 1;i<sizeof(observed);i++) {
     mymessage += ", ";
     mymessage += observed[i];
   }
   tell_object(TP,"%^CYAN%^You grow still and attune yourself to the tree, and you can sense those that have walked here. It has felt the presence of %^RESET%^"+mymessage+"%^CYAN%^.%^RESET%^");
   tell_room(TO,"%^CYAN%^"+TP->QCN+" closes "+TP->QP+" eyes and concentrates briefly.%^RESET%^",TP);
   return 1;
}

int purge_it(string str) {
   if(!str) return 0;
   if(str != "trespassers") return 0;
   if(!avatarp(TP) && (string)TP->query_name() != "marie" && (string)TP->query_name() != "mithras") {
     tell_object(TP,"%^CYAN%^You attune your senses to the tree, but nothing happens.%^RESET%^");
     tell_room(TO,"%^CYAN%^"+TP->QCN+" closes "+TP->QP+" eyes and concentrates briefly.%^RESET%^",TP);
     return 1;
   }
   if(!sizeof((string *)SAVE_D->query_array("mithras_tree"))) {
     tell_object(TP,"%^CYAN%^You attune your senses to the tree, but its peaceful nature tells you it has nothing to forget.%^RESET%^");
     tell_room(TO,"%^CYAN%^"+TP->QCN+" closes "+TP->QP+" eyes and concentrates briefly.%^RESET%^",TP);
     return 1;
   }
   tell_object(TP,"%^CYAN%^You attune your senses to the tree, soothing it until its recollections fade.%^RESET%^");
   tell_room(TO,"%^CYAN%^"+TP->QCN+" closes "+TP->QP+" eyes and concentrates briefly.%^RESET%^",TP);
   SAVE_D->remove_array("mithras_tree");
   return 1;
}

int not_allowed_func(object player) {
   tell_object(player,"As you reach out for the bookshelf, some uneasy feeling suddenly has you pulling back your hand. How odd!");
   return 0;
}

void trigger_eldathyn_ward() {
   object *combatants, destroom, MyWard;
   int i, flag, MyFlag;
   string *mayberooms, *mayberooms2, pickedroom;

   combatants = all_living(TO);
   if(!sizeof(combatants)) return;

   mayberooms = get_dir(BASE);
   mayberooms2 = ({});
   for (i=0;i<sizeof(mayberooms);i++) { mayberooms2 += ({BASE + mayberooms[i]}); }
   mayberooms2 -= NOTROOMS;
   pickedroom = mayberooms2[random(sizeof(mayberooms2))];
   destroom = new(pickedroom);

   for(i = 0;i< sizeof(combatants); i++) {
     if(!objectp(combatants[i])) continue;
     MyWard = present("eldathynwardxxx", combatants[i]);
     MyFlag = 0;
     if(objectp(MyWard)) MyFlag = (int)MyWard->is_combatant();

     if(sizeof(combatants[i]->query_attackers()) || MyFlag) {
       if(!flag) flag = 1;
       tell_object(combatants[i],"%^BOLD%^%^CYAN%^The air s%^RESET%^%^CYAN%^hi%^BOLD%^mm%^RESET%^%^CYAN%^er%^BOLD%^s around you, "
"and suddenly you find yourself elsewhere!%^RESET%^");
       combatants[i]->move(pickedroom);
     }
   }

   if(flag)
     tell_room(TO,"%^BOLD%^%^CYAN%^The air s%^RESET%^%^CYAN%^hi%^BOLD%^mm%^RESET%^%^CYAN%^er%^BOLD%^s around those striking out, "
"and suddenly they are gone!%^RESET%^");
}

int is_lab() { return 1; } // set up for brewing to work.