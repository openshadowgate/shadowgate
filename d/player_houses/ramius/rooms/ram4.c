//ram1
#include <std.h>
#include "../ramius.h"
inherit LIBRARY;
object obj;

void create() {
    ::create();
    set_property("indoors",1); 
    set_property("light",2);   
    set_terrain(WOOD_BUILDING);
    set_travel(PAVED_ROAD);  
    set_name("Library");
    set_short("%^RESET%^%^ORANGE%^Library%^RESET%^");
    set_long("%^RESET%^This entire floor of the house has been devoted to an impressive "
         "private library.  %^RESET%^%^ORANGE%^Oaken bookshelves %^RESET%^ring the "
         "entire room, except for a few %^BOLD%^%^CYAN%^windows %^RESET%^that are set "
         "into them.  These shelves are full of books, scrolls, and a few stone tablets.  "
         "A medium-sized round table rests in the middle of the room along with several "
         "chairs.  A %^RESET%^%^BLUE%^midnight blue rug %^RESET%^inset with "
         "%^BOLD%^%^WHITE%^white stars %^RESET%^covers the entire floor here.  The library "
         "is illuminated with globes of %^BOLD%^%^WHITE%^softly "
         "gl%^BOLD%^%^YELLOW%^o%^BOLD%^%^WHITE%^wing %^RESET%^magical light hanging "
         "from %^RESET%^%^GREEN%^v%^BOLD%^i%^RESET%^%^GREEN%^n%^BOLD%^e%^RESET%^%^GREEN%^s "
         "%^RESET%^that grow along the ceiling.  It is apparent that a great deal of "
         "%^RESET%^%^CYAN%^knowledge %^RESET%^is stored here.\n");
    set_smell("default","%^RESET%^The smells of %^BOLD%^%^BLACK%^musty parchment "
          "%^RESET%^and %^BOLD%^%^RED%^f%^BOLD%^%^BLUE%^l%^CYAN%^o%^RESET%^"
          "%^ORANGE%^w%^YELLOW%^e%^RESET%^%^BLUE%^r%^MAGENTA%^s %^RESET%^interweave "
          "themselves.");
    set_listen("default","%^RESET%^The room if quiet except for the faint sounds of "
           "the %^RESET%^%^GREEN%^forest %^RESET%^around you%^RESET%^.");
    set_items(([ ({"shelves","bookshelves"}) : " Massive shelves grown out of the "
                "%^RESET%^%^GREEN%^tree %^RESET%^itself ring the entire room here.  "
                "%^RESET%^%^RED%^Books%^RESET%^, %^RESET%^%^ORANGE%^scrolls%^RESET%^, "
                "and a few %^BOLD%^%^BLACK%^stone tablets %^RESET%^cover them completely.  "
                "However, there seems to be a %^BOLD%^%^CYAN%^looking glass %^RESET%^on the "
                "shelf as well that serves as a bookend.  The books appear to be on a wide "
                "array of subjects, but a great many of them focus on the study of "
                "%^BOLD%^%^BLUE%^magic%^RESET%^.  Conjuration seems to be the prime subject "
                "covered, but there are at least fifty books on each other school of magic.  "
                "The shelves and contents appear to be cleaned regularly and are void of dust.  "
                "At the four cardinal points there are round %^BOLD%^%^CYAN%^windows "
                "%^RESET%^set into the shelves themselves.",
             ({"globes","lights"}) : " Numerous %^BOLD%^%^CYAN%^glass globes %^RESET%^are "
                "suspended from the %^RESET%^%^GREEN%^v%^BOLD%^i%^RESET%^%^GREEN%^n%^BOLD%^"
                "e%^RESET%^%^GREEN%^s %^RESET%^that run along the ceiling.  They emit a soft, "
                "magical %^BOLD%^%^WHITE%^gl%^YELLOW%^o%^BOLD%^%^WHITE%^w%^RESET%^.",
             "rug" : "This plush, %^RESET%^%^BLUE%^midnight blue rug %^RESET%^stretches "
                "from one side of the room to another.  Numerous %^BOLD%^%^WHITE%^white "
                "stars %^RESET%^have been woven into it which seems appropriate for this "
                "place of %^RESET%^%^CYAN%^magical lore %^RESET%^as well as serving the "
                "utilitarian purpose of keeping the room quiet.",
             "ceiling" : "The ceiling is covered by a multitude of crisscrossing "
                "%^RESET%^%^GREEN%^v%^BOLD%^i%^RESET%^%^GREEN%^n%^BOLD%^e%^RESET%^"
                "%^GREEN%^s %^RESET%^that grow along it and down parts of the walls "
                "in this room.  Most of them appear to be %^BOLD%^%^BLUE%^f%^RED%^l"
                "%^YELLOW%^o%^CYAN%^w%^MAGENTA%^e%^RESET%^%^ORANGE%^r%^RED%^i%^BLUE%^"
                "n%^CYAN%^g %^RESET%^%^GREEN%^plants%^RESET%^, which gives the room "
                "a nice scent and attractive appearance.  Not much of the wood of the "
                "tree can be seen here.",
             "windows" : "%^RESET%^Round, %^YELLOW%^porthole-styled %^CYAN%^windows "
                "%^RESET%^are set at the four cardinal points around the room.  They "
                "allow clear vision into the surrounding forest and can be opened to "
                "let %^BOLD%^%^WHITE%^fresh %^BOLD%^%^BLUE%^a%^CYAN%^i%^BLUE%^r %^RESET%^"
                "into the room.",
             "looking glass" : "This rectangular %^BOLD%^%^CYAN%^looking glass %^RESET%^"
                "serves as a bookend on one of the many shelves in this library.  It is "
                "of roughly average dimensions and has been constructed of impeccably "
                "%^BOLD%^%^WHITE%^polished glass%^RESET%^.  The elaborate %^YELLOW%^gold "
                "frame %^RESET%^has been inset with many %^RESET%^%^CYAN%^gemstones "
                "%^RESET%^that catch and reflect the %^BOLD%^%^WHITE%^l%^YELLOW%^i%^BOLD%^"
                "%^WHITE%^ght%^RESET%^." ]));

   set_public_library(0);
   set_library_name("The_Darkholme_Collection");
}


void init(){
   ::init();
   add_action("open_it","open");
   add_action("close_it","close");
   add_action("gaze_into","gaze");
   add_action("stare_into","stare");
}

int gaze_into(string str)
{
    if(!stringp(str)) { return 0; }
    if(lower_case(str) != "into glass" && lower_case(str) != "into looking glass") { return 0; }
    tell_object(TP,"%^RESET%^%^RED%^You step up to the looking glass and "
        "gaze into it to get a better look at yourself.  The mirror at first "
        "reflects you, then the scene changes from your reflection to that of "
        "a %^BOLD%^%^RED%^mag%^BLUE%^i%^RED%^cal %^BLUE%^lab%^WHITE%^o%^BLUE%^"
        "rat%^WHITE%^o%^BLUE%^ry.%^RESET%^");
    tell_room(ETP,"%^RESET%^%^RED%^"+TPQCN+" gazes into the %^BOLD%^%^CYAN%^"
        "looking glass %^RESET%^%^RED%^at "+TP->QP+" reflection.%^RESET%^",TP);
    return 1;
}

int stare_into(string str)
{
    object ob;
    if(!stringp(str)) { return 0; }
    if(lower_case(str) != "into glass" && lower_case(str) != "into looking glass") { return 0; }
    tell_object(TP,"%^BOLD%^%^WHITE%^You stare into the %^CYAN%^looking glass%^WHITE%^, "
        "intent on getting a better look at scene before you and suddenly feel yourself "
        "moved to another place!%^RESET%^");
    tell_room(ETP,"%^RESET%^%^CYAN%^"+TPQCN+" suddenly disappears in a "
        "%^BOLD%^%^WHITE%^flash %^RESET%^%^CYAN%^of %^YELLOW%^light!%^RESET%^",TP);
    ob = find_object_or_load("/d/player_houses/ramius/rooms/ram5.c");
    TP->move(ob);
    TP->force_me("look");
    tell_object(TP,"%^CYAN%^When the light clears, you find yourself in another "
        "room!%^RESET%^");
    tell_room(ob,"%^RESET%^%^CYAN%^"+TPQCN+" suddenly appears in a %^BOLD%^%^WHITE%^"
        "flash %^RESET%^%^CYAN%^of %^YELLOW%^light!%^RESET%^",TP);
    return 1;
}

int close_it(string str) {
   if(!str) {
      tell_object(TP,"Close what?");
      return 1;
   }
   if((str == "trapdoor") || (str=="trap door")){
      if(member_array("down",TO->query_exits()) != -1) {
         tell_object(TP,"You carefully push the trapdoor down and latch it shut.\n");
         tell_room(ETP,""+TPQCN+" reaches down and closes the trapdoor.  It blends into the floor and disappears from view just as it shuts.\n",TP);
         tell_room(find_object_or_load(INRMS+"ram3"),"A hand reaches down and grabs the trap door, shutting it quietly and causing it to disappear from view.");
         remove_exit("down");
         (INRMS+"ram3")->remove_exit("up");
         return 1;
      }
   tell_object(TP,"The trap door is already closed!\n");
   return 1;
   }
}
int open_it(string str) {
  if(!str) {
     tell_object(TP,"Open what?");
     return 1;
  }
  if((str == "trapdoor") || (str=="trap door")){
     if(member_array("up",TO->query_exits()) != -1) {
        tell_object(TP,"The trap door is already open! \n");
        return 1;
     }
     tell_object(TP,"%^GREEN%^You unlatch and open the hidden trap door in the floor.\n");
     tell_room(ETP,"%^GREEN%^"+TPQCN+" unlatches and opens a hidden trap door in the floor.\n",TP);
     tell_room(find_object_or_load(INRMS+"ram3"),"The trap door suddenly opens!");
     add_exit(INRMS+"ram3","down");
     (INRMS+"ram3")->add_exit(INRMS+"ram4","up");
     return 1;
   }
}


