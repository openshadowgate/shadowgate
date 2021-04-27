#include <std.h>
#include "../ramius.h"
inherit "/std/lab.c";
int searched;
object obj;

void create() {
    ::create();
    set_property("indoors",1); 
    set_property("light",2);   
    set_terrain(WOOD_BUILDING);
    set_travel(PAVED_ROAD);
    set_name("Laboratory");
    set_short("%^BOLD%^%^BLUE%^Lab%^WHITE%^o%^BLUE%^rat%^WHITE%^o%^BLUE%^ry%^RESET%^");
    set_long("%^RESET%^This is a large circular room that serves as a %^BOLD%^%^RED%^"
        "mag%^BLUE%^i%^RED%^cal %^BLUE%^lab%^WHITE%^o%^BLUE%^rat%^WHITE%^o%^BLUE%^ry."
        "%^RESET%^  It has been made from the highest quality %^BOLD%^%^WHITE%^m%^BLUE%^"
        "a%^WHITE%^rble %^RESET%^that has been polished to an impeccable %^BOLD%^%^BLACK%^"
        "smoothness%^RESET%^.  There are no doors or windows here, which is probably "
        "appropriate for the %^BOLD%^%^RED%^dangerous experiments %^RESET%^carried on "
        "in such places.  A large %^RESET%^%^ORANGE%^oaken desk %^RESET%^sits against "
        "one of the walls along with a matching, comfortable looking chair.  Near another "
        "wall rests a stone pedestal topped by a %^BOLD%^%^BLUE%^water-filled %^BOLD%^"
        "%^WHITE%^mithril bowl%^RESET%^.  Various %^RESET%^%^ORANGE%^wooden tables "
        "%^RESET%^dot the room and each seems to be covered in a myriad of magical "
        "devices, components, and the like.  The very center of the room is dominated "
        "by an impressive %^BOLD%^%^RED%^arcane circle%^RESET%^.  The laboratory is lit "
        "from magical globes of %^YELLOW%^light %^RESET%^that float near the ceiling.\n");
    set_smell("default","%^RESET%^The smells of the %^BOLD%^%^WHITE%^bubbling experiments "
        "%^RESET%^waft throughout the room.");
    set_listen("default","%^RESET%^The only sound discernable in the stillness in the "
        "room comes from the %^BOLD%^%^WHITE%^bubbling apparati%^RESET%^.");
    set_items(([ ({"circle","summoning circle","arcane circle"}) : "The center of this room "
        "is dominated by an %^BOLD%^%^RED%^arcane summoning circle %^RESET%^that has been "
        "scribed into the %^BOLD%^%^WHITE%^m%^BLUE%^a%^WHITE%^rble %^RESET%^floor.  Two "
        "distinct rings form it, one set inside the other.  %^BOLD%^%^RED%^Arcane "
        "symbols %^RESET%^of warding have been inscribed into the %^BOLD%^%^BLACK%^stone "
        "%^RESET%^between the two rings.  It is roughly ten feet in diameter from outer "
        "ring to outer ring.   Everything else in the room is at least ten feet away "
        "from this %^BOLD%^%^RED%^circle%^RESET%^, probably for safety reasons.",
       ({"pedestal","basin", "mirror"}) : "%^RESET%^This %^BOLD%^%^BLACK%^stone %^RESET%^"
        "pedestal rests roughly five feet from the large wooden desk.  It stands about three "
        "feet tall and is roughly circular in shape.  The pedestal is comprised of %^BOLD%^"
        "%^WHITE%^an%^RESET%^c%^BOLD%^%^BLACK%^i%^RESET%^e%^BOLD%^%^WHITE%^nt, %^RESET%^"
        "well-worn %^BOLD%^%^BLACK%^fieldstone %^RESET%^covered in %^RESET%^%^GREEN%^green "
        "moss%^RESET%^.  It is topped by a shallow, well-shined %^BOLD%^%^WHITE%^mithril "
        "bowl %^RESET%^that has been filled with %^BOLD%^%^CYAN%^crystal clear water"
        "%^RESET%^.  Apparently this bowl serves as a %^BOLD%^%^BLUE%^scrying "
        "mirror%^RESET%^.",
       "marble" : "%^RESET%^This %^BOLD%^%^WHITE%^white marble %^RESET%^used to construct "
        "this laboratory is the highest one could possibly find.  Veins of %^BOLD%^%^BLUE%^"
        "rich blue %^RESET%^snake through the stone in an eye pleasing manner.  The marble "
        "is polished to an impeccable smoothness, though a few %^BOLD%^%^BLACK%^burn marks "
        "%^RESET%^or %^BOLD%^%^GREEN%^odd stains %^RESET%^reveal that a spell or experiment "
        "has gone awry here from time to time.",
       "looking glass" : "%^RESET%^This rectangular %^BOLD%^%^CYAN%^looking glass "
        "%^RESET%^rests on the large oaken desk.  It is of roughly average dimensions and has "
        "been constructed of impeccably %^BOLD%^%^WHITE%^polished glass%^RESET%^.  The "
        "elaborate %^YELLOW%^gold frame %^RESET%^has been inset with many %^RESET%^%^CYAN%^"
        "gemstones %^RESET%^that catch and reflect the %^BOLD%^%^WHITE%^l%^YELLOW%^i%^BOLD%^"
        "%^WHITE%^ght%^RESET%^.",
       "tables" : "%^RESET%^There are three tables scattered throughout the laboratory.  "
        "One is covered by neatly labeled %^BOLD%^%^BLACK%^stone jars %^RESET%^that appear "
        "to hold spell components.  Various %^BOLD%^%^GREEN%^chemical apparati %^WHITE%^"
        "bubbling %^RESET%^with experiments rest on another table.  A third one seems to be "
        "mostly empty and could probably be used for whatever necessity is at hand.",
       "desk" : "%^RESET%^ This is a large %^RESET%^%^ORANGE%^o%^RED%^a%^ORANGE%^k%^RED%^e"
        "%^ORANGE%^n desk %^RESET%^sitting along the circular wall.  It is cluttered with "
        "all manner of scrolls, books, parchments, inkwells and the like.  The drawers look "
        "equally cluttered with various materials.  A rectangular %^BOLD%^%^CYAN%^looking "
        "glass %^RESET%^sits atop the desk to perhaps give whoever seated a good view of "
        "the room behind them.  A comfortable looking padded chair of matching %^RESET%^"
        "%^ORANGE%^o%^RED%^a%^ORANGE%^k %^RESET%^sits nearby.  It's apparent that this "
        "desk gets quite a bit of use." ]));

    set_search("desk",(:TO,"search_desk":));
    searched = 1;
    setOwner("ramius");
    setLabId("Ramiushouse");
    new(OBJT+"basin")->move(TO);
}

void search_desk(){
   if(searched <= 0) {               
	tell_object(TP,"%^RESET%^%^ORANGE%^You open up an empty drawer.%^RESET%^");
      return 1;
   } 
   tell_object(TP,"You open up a drawer and pull out two things, an odd hat and a monocle%^RESET%^.");
   obj=new("/d/antioch/valley/obj/phat");
   obj->set_size(2);
   obj->move(TO);
   new("/d/avatars/istishia/RamMon.c")->move(TO);
   searched --;
   return 1;
}

void init()
{
    ::init();
    add_action("gaze_into","gaze");
    add_action("stare_into","stare");
    return;
}

int gaze_into(string str)
{
    if(!stringp(str)) { return 0; }
    if(lower_case(str) != "into glass" && lower_case(str) != "into looking glass") { return 0; }
    tell_object(TP,"%^RESET%^%^RED%^You step up to the looking glass and gaze into it to "
        "get a better look at yourself.  The mirror at first reflects you, then the scene "
        "changes from your reflection to that of an impressive %^RESET%^%^ORANGE%^library"
        "%^RESET%^.");
    tell_room(ETP,"%^RESET%^%^RED%^"+TPQCN+" gazes into the %^BOLD%^%^CYAN%^looking glass "
        "%^RESET%^%^RED%^at "+TP->QP+" reflection.%^RESET%^",TP);
    return 1;
}

int stare_into(string str)
{
    object ob;
    if(!stringp(str)) { return 0; }
    if(lower_case(str) != "into glass" && lower_case(str) != "into looking glass") { return 0; }
    tell_object(TP,"%^BOLD%^%^WHITE%^You stare into the %^CYAN%^looking glass%^WHITE%^, "
        "intent on getting a better look at scene before you and suddenly feel yourself "
        "moved to another place!");
    tell_room(ETP,"%^RESET%^%^CYAN%^"+TPQCN+" suddenly disappears in a %^BOLD%^%^WHITE%^"
        "flash %^RESET%^%^CYAN%^of %^YELLOW%^light!%^RESET%^",TP);
    ob = find_object_or_load("/d/player_houses/ramius/rooms/ram4.c");
    TP->move(ob);
    TP->force_me("look");
    tell_room(ob,"%^RESET%^%^CYAN%^"+TPQCN+" suddenly appears in a %^BOLD%^%^WHITE%^flash "
        "%^RESET%^%^CYAN%^of %^YELLOW%^light!%^RESET%^",TP);
    tell_object(TP,"%^CYAN%^When the light clears, you find yourself in another room!%^RESET%^");
    return 1;
}





