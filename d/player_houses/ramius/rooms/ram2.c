//ram1
#include <std.h>
#include "../ramius.h"
inherit VAULT;


void create()
{
    ::create();
    set_property("indoors", 0);
    set_property("light", 2);
    set_terrain(LIGHT_FOREST);
    set_travel(DECAYED_FLOOR);
    set_name("The Limbs of An Ancient Oak Tree");
    set_short("%^RESET%^%^GREEN%^The Limbs of an Anc%^BOLD%^%^WHITE%^i%^RESET%^%^GREEN%^ent Oak Tree%^RESET%^");
    set_long((: TO, "ldesc" :));
    set_smell("default", "%^RESET%^The smell of %^GREEN%^leaves %^RESET%^and %^ORANGE%^wood %^RESET%^is strong here.");
    set_listen("default", "%^GREEN%^The sounds of the forest creatures permeate the air.");
    set_items(([({ "trunk", "treetrunk" }) : "The trunk of the tree is no less massive here than when you were on the ground. Slick, %^BOLD%^%^WHITE%^white bark %^RESET%^is covered in places by a thin %^RESET%^%^GREEN%^green moss %^RESET%^that spirals its way around the tree.  As you look at the trunk clearly, you can see what appears to be a wooden door built into it above the limb on which you now stand."]));
    set_exits((["down" : INRMS + "ram1", "tree" : INRMS + "ram3"]));
    set_door("door", INRMS "ram3", "tree", "wood_key");
    set_door_description("door", "This rectangular door has exactly the same color and texture as the %^GREEN%^tree %^RESET%^itself, making it difficult to see unless you are looking directly at it.  Looking close, you can see what appear to be a small keyhole and a knot which appears to serve as a doorknob.");
    set_locked("door", 1);
    lock_difficulty("door",  "/daemon/player_housing"->get_phouse_lock_dc("legendary"), "lock");
    set_search("default", "You notice that this is no ordinary tree.  The trunk itself looks peculiar.");
}

string ldesc(string str)
{
    if (month(time()) == "Winterstime" || month(time()) == "Colddays") {
        return ("%^RESET%^%^GREEN%^You stand on a huge limb of the tree some fifty feet above the ground."
                "  The thick, %^BOLD%^%^WHITE%^white %^RESET%^%^GREEN%^limbs are bare and covered with a thin layer"
                " of %^BOLD%^%^WHITE%^sn%^BLUE%^o%^WHITE%^w.  %^RESET%^%^GREEN%^The surrounding area is clearly viewable and"
                " you can see much of the surrounding %^BOLD%^Elven village %^RESET%^%^GREEN%^from here.  Gazing around at"
                " the tree you can see several holes and cracks which are most likely occupied by forest creatures in their"
                " %^BOLD%^%^WHITE%^wintery slumber%^RESET%^.\n");
    }
    if (month(time()) == "Renewal" || month(time()) == "Springstime" || month(time()) == "Plantingdays") {
        return ("%^RESET%^%^GREEN%^You stand on a huge limb of the tree some fifty feet above the ground."
                "  The bright %^BOLD%^newgrowth green leaves %^RESET%^%^GREEN%^and thick, %^BOLD%^%^WHITE%^white"
                " %^RESET%^%^GREEN%^limbs make it difficult to see the surrounding area with much clarity.  Forest"
                " dwelling animals such as %^BOLD%^%^GREEN%^lizards %^RESET%^%^GREEN%^and %^BOLD%^%^BLUE%^birds"
                " %^RESET%^%^GREEN%^scamper around you.\n");
    }
    if (month(time()) == "Sundays" || month(time()) == "Summerstime") {
        return ("%^RESET%^%^GREEN%^You stand on a huge limb of the tree some fifty feet above the ground"
                ".  The deep %^BOLD%^green leaves %^RESET%^%^GREEN%^and thick, %^BOLD%^%^WHITE%^white"
                " %^RESET%^%^GREEN%^limbs make it difficult to see the surrounding area with much clarity.  Forest dwelling"
                " animals such as %^BOLD%^%^GREEN%^lizards %^RESET%^%^GREEN%^and %^BOLD%^%^BLUE%^birds"
                " %^RESET%^%^GREEN%^scamper around you.\n");
    }
    if (month(time()) == "Growingdays" || month(time()) == "Harvestdays" || month(time()) == "Autumnstime") {
        return ("%^RESET%^%^GREEN%^You stand on a huge limb of the tree some fifty feet above the ground."
                "  The bright %^BOLD%^%^RED%^m%^YELLOW%^u%^RED%^l%^YELLOW%^t%^RED%^i%^WHITE%^-%^RED%^c%^YELLOW%^o%^RED%^l"
                "%^YELLOW%^o%^RED%^r%^YELLOW%^e%^RED%^d %^RESET%^%^GREEN%^leaves that still cling to the thick,"
                " %^BOLD%^%^WHITE%^white %^RESET%^%^GREEN%^limbs make it difficult to see the surrounding area with much"
                " clarity.  Forest dwelling animals such as %^BOLD%^%^GREEN%^lizards %^RESET%^%^GREEN%^and"
                " %^BOLD%^%^BLUE%^birds %^RESET%^%^GREEN%^scamper around you in their preparations for the coming"
                " %^BOLD%^%^WHITE%^winter.\n%^RESET%^");
    }
}
