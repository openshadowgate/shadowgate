//ram1
#include <std.h>
#include "../ramius.h"
inherit ROOM;


void create()
{
    ::create();
    set_property("indoors", 0);
    set_property("light", 2);
    set_terrain(LIGHT_FOREST);
    set_travel(DECAYED_FLOOR);
    set_name("An Ancient Oak Tree");
    set_short("An Ancient Oak Tree");
    set_long((: TO, "ldesc" :));
    set_listen("default", "Birds and other forest creatures can be heard about you.");
    set_smell("default", "The earthy smell of the forest surrounds you.");
    set_climb_exits((["climb" : ({ INRMS + "ram2", 20, 4, 100 })]));
    set_exits(([
                   "west" : "/d/darkwood/camps/rooms/town/road18",
               ]));
    set_items(([
                   ({ "animals", "forest creatures" }) : (: TO, "lanimals" :),
                   "birds" : (: TO, "lbirds" :),
               ]));
}

string ldesc(string str)
{
    if (month(time()) == "Winterstime" || month(time()) == "Colddays") {
        return ("%^RESET%^%^GREEN%^The well hidden path ends here at the base of an %^BOLD%^%^WHITE%^ancient"
                " white oak tree%^RESET%^%^GREEN%^.  It towers some five hundred feet above you and appears to be more than"
                " forty feet in diameter.  Extending fifty feet in every direction, the limbs appear as if they would shade"
                " this location well.  The limbs of the tree are %^BOLD%^%^WHITE%^bare %^RESET%^%^GREEN%^and covered with a"
                " bit of %^BOLD%^%^WHITE%^sn%^BLUE%^o%^WHITE%^w %^RESET%^%^GREEN%^and"
                " %^BLUE%^f%^BOLD%^%^BLUE%^r%^WHITE%^o%^BLUE%^s%^RESET%^%^BLUE%^t%^RESET%^.  %^RESET%^%^GREEN%^The limbs appear"
                " to hold few to no animals except for an occasional bird or squirrel that pokes its head out of a protective"
                " hole in the trunk.  The sight of such an old tree gives you a sense of %^BOLD%^%^GREEN%^Nature�s"
                " %^RESET%^%^GREEN%^power and beauty here.\n%^RESET%^");
    }
    if (month(time()) == "Renewal" || month(time()) == "Springstime" || month(time()) == "Plantingdays") {
        return ("%^RESET%^%^GREEN%^The well hidden path ends here at the base of an %^BOLD%^%^WHITE%^ancient"
                " white oak tree%^RESET%^%^GREEN%^.  It towers some five hundred feet above you and appears to be more than"
                " forty feet in diameter.  The branches extend fifty feet in every direction shading this location well."
                "  The leaves are %^BOLD%^%^GREEN%^bright green %^RESET%^%^GREEN%^and numerous newgrowth acorns can be seen along"
                " the limbs.  Squirrels and other small animals can be seen high within its protective limbs and you get"
                " a sense of %^BOLD%^%^Nature�s %^RESET%^%^GREEN%^power and beauty here.\n");
    }
    if (month(time()) == "Sundays" || month(time()) == "Summerstime") {
        return ("%^RESET%^%^GREEN%^The well hidden path ends here at the base of an %^BOLD%^%^WHITE%^ancient"
                " white oak tree%^RESET%^%^GREEN%^.  It towers some five hundred feet above you and appears to be more than"
                " forty feet in diameter.  The branches extend fifty feet in every direction shading this location well."
                "  The leaves are %^BOLD%^%^GREEN%^deep green %^RESET%^%^GREEN%^and numerous fully developed acorns can be"
                " seen along the limbs.  Squirrels and other small animals can be seen high within its protective limbs and"
                " you get a sense of %^BOLD%^%^Nature�s %^RESET%^%^GREEN%^power and beauty here.\n");
    }
    if (month(time()) == "Growingdays" || month(time()) == "Harvestdays" || month(time()) == "Autumnstime") {
        return ("%^RESET%^%^GREEN%^The well hidden path ends here at the base of an %^BOLD%^%^WHITE%^ancient"
                " white oak tree%^RESET%^%^GREEN%^.  It towers some five hundred feet above you and appears to be more"
                " than forty feet in diameter.  The branches extend fifty feet in every direction shading this location well."
                "  %^BOLD%^%^YELLOW%^Bright%^RESET%^, %^BOLD%^%^RED%^m%^YELLOW%^u%^RED%^l%^YELLOW%^t%^RED%^i%^WHITE%^"
                "-%^RED%^c%^YELLOW%^o%^RED%^l%^YELLOW%^o%^RED%^r%^YELLOW%^e%^RED%^d %^RESET%^%^GREEN%^leaves in tones of"
                " %^YELLOW%^yellow%^RESET%^, %^BOLD%^%^RED%^red%^RESET%^, %^BOLD%^%^GREEN%^green%^RESET%^, %^GREEN%^and"
                " %^RESET%^%^ORANGE%^orange %^RESET%^%^GREEN%^adorn the tree and cover the forest floor here.  A few small"
                " forest creatures can be seen high within its protective limbs about their preparations for the coming"
                " %^BOLD%^%^WHITE%^winter. %^RESET%^%^GREEN%^You get a sense of %^BOLD%^Nature�s %^RESET%^%^GREEN%^power"
                " and beauty here.\n");
    }
}

string lanimals(string str)
{
    if (month(time()) == "Winterstime" || month(time()) == "Colddays") {
        return ("%^BOLD%^%^WHITE%^Very few animals can be seen except for the rare bird or squirrel that occassionally pokes its head out from a hole in the trunk.%^RESET%^");
    }
    if (month(time()) == "Renewal" || month(time()) == "Springstime" || month(time()) == "Plantingdays") {
        return ("%^BOLD%^%^GREEN%^A few forest creatures scamper about here and there and the occassional cry of a new hatchling calling its mother back to the nest can be heard.  If you look closely enough, once in a while you manage to even catch a glimpse of a doe and her fawn through the surrounding trees.%^RESET%^");
    }
    if (month(time()) == "Sundays" || month(time()) == "Summerstime") {
        return ("%^RESET%^%^GREEN%^Squirrels, chipmunks, birds, lizards and all sorts of animals can be seen scurrying about amongst the higher branches of the tree.  The energy coming from this tree feels magical and you realize that it is because this tree is brimming with life.%^RESET%^");
    }
    if (month(time()) == "Growingdays" || month(time()) == "Harvestdays" || month(time()) == "Autumnstime") {
        return ("%^RESET%^%^ORANGE%^High within the tree, forest creatures can be seen going about their preparations for the upcoming winter.%^RESET%^");
    }
}

string lbirds(string str)
{
    if (month(time()) == "Winterstime" || month(time()) == "Colddays") {
        return ("%^BOLD%^%^WHITE%^Not many birds are active this time of year... Save for the occassional %^BLUE%^blue jay %^WHITE%^or %^RED%^red robin %^WHITE%^that you can sometimes see frolicking in the white drifts of snow.%^RESET%^");
    }
    if (month(time()) == "Renewal" || month(time()) == "Springstime" || month(time()) == "Plantingdays") {
        return ("The calls of young hatchlings fill the air.  As you look at the %^BOLD%^%^GREEN%^tree"
                " %^RESET%^more closely you can see many %^ORANGE%^nests %^RESET%^with small %^BOLD%^%^WHITE%^white,"
                " f%^RESET%^l%^BOLD%^%^WHITE%^u%^RESET%^f%^BOLD%^%^WHITE%^fy heads %^RESET%^peeking out as they await for"
                " their mothers return.  Other birds can be seen flying high in the %^BOLD%^%^CYAN%^sky, %^RESET%^while"
                " even more are giving life to the %^GREEN%^bushes %^RESET%^as they search for that endless supply of food."
                "  A few birds land on the %^ORANGE%^ground %^RESET%^to pick at %^ORANGE%^s%^RESET%^e%^BOLD%^%^WHITE%^e"
                "%^RESET%^%^ORANGE%^d%^GREEN%^s %^RESET%^and small %^ORANGE%^insects %^RESET%^while others can be seen going"
                " about their daily lives within the %^BOLD%^%^GREEN%^tree %^RESET%^itself.");
    }
    if (month(time()) == "Sundays" || month(time()) == "Summerstime") {
        return ("%^BOLD%^%^BLUE%^The hatchlings that were once calling for their mothers in Springstime are now"
                " grown themselves and can now be seen soaring through the skies.  Daily activities are routine now and their"
                " merry chirps and calls flood the forest.%^RESET%^");
    }
    if (month(time()) == "Growingdays" || month(time()) == "Harvestdays" || month(time()) == "Autumnstime") {
        return ("%^RESET%^%^ORANGE%^Many different types of birds can be seen flying through the skies or lounging in the tree.  More often than not however, you find them picking up spare pieces of straw, twigs or other suitable items to reinforce their nests in preparation of the upcoming winter.");
    }
}
