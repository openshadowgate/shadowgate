//Octothorpe (7/29/10)
//Amberly's HM house, Grotto

#include <std.h>
#include "../amberly.h"
inherit ROOM;

int lube;

void create()
{
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set_property("teleport proof",  "/daemon/player_housing"->get_phouse_tp_proof("epic"));
    set_terrain(NAT_CAVE);
    set_travel(SLICK_FLOOR);
    lube = 2;
    set_name("A damp grotto");
    set_short("A damp grotto");
    set_long("%^BOLD%^%^BLACK%^Strewn randomly across the %^GREEN%^damp " +
             "grotto %^BLACK%^are piles of large, comfortable pillows in " +
             "%^GREEN%^m%^MAGENTA%^y%^CYAN%^r%^BLUE%^i%^CYAN%^a%^GREEN%^d " +
             "%^BLACK%^of colors, their surfaces embroidered with varying " +
             "%^RESET%^%^MAGENTA%^feminine designs. %^BOLD%^%^BLACK%^A few " +
             "smaller pillows, are scattered among the others, dyed an " +
             "amazing shade of %^CYAN%^s%^GREEN%^e%^RESET%^%^GREEN%^a %^CYAN%^" +
             "g%^BOLD%^%^GREEN%^r%^CYAN%^e%^GREEN%^e%^RESET%^%^CYAN%^n " +
             "%^BOLD%^%^BLACK%^with %^WHITE%^p%^RESET%^e%^BOLD%^a%^RESET%^" +
             "r%^BOLD%^l %^RESET%^a%^BOLD%^cc%^RESET%^e%^BOLD%^n%^RESET%^t" +
             "%^BOLD%^s %^BOLD%^%^BLACK%^embroidered in the shapes of " +
             "%^CYAN%^winged creatures %^BLACK%^in flight. A large %^RESET%^" +
             "%^CYAN%^bathing pool %^BOLD%^%^BLACK%^occupies one end of " +
             "the room, %^WHITE%^smooth s%^BLACK%^t%^WHITE%^one steps " +
             "%^BLACK%^descending into its shallow curves. The floor of " +
             "the pool is %^BLUE%^tiled %^BLACK%^in shades of %^RESET%^" +
             "%^MAGENTA%^i%^CYAN%^n%^WHITE%^d%^BLUE%^i%^CYAN%^g%^MAGENTA%^" +
             "o %^BOLD%^%^BLACK%^with intricate patterns displayed clearly. " +
             "The waters within are %^CYAN%^c%^WHITE%^h%^RESET%^i%^CYAN%^l" +
             "%^BOLD%^l%^WHITE%^e%^CYAN%^d %^BOLD%^%^BLACK%^with the exception " +
             "of a section that veers off next to some %^RESET%^%^RED%^" +
             "steaming rocks. %^BOLD%^%^BLACK%^%^A %^GREEN%^rainbow %^BOLD%^" +
             "%^BLACK%^of %^WHITE%^light %^BOLD%^%^BLACK%^is reflected from " +
             "the %^CYAN%^c%^GREEN%^r%^WHITE%^y%^MAGENTA%^s%^CYAN%^t%^GREEN%^" +
             "a%^WHITE%^l shards %^BOLD%^%^BLACK%^lined haphazardly across " +
             "the walls while %^WHITE%^clean air %^BLACK%^is constantly " +
             "circulating. At times the soft %^CYAN%^hissing breeze %^BOLD%^" +
             "%^BLACK%^whistles past the %^BLUE%^holes %^BLACK%^in the " +
             "ceiling, causing the %^GREEN%^g%^CYAN%^a%^GREEN%^u%^CYAN%^z" +
             "%^GREEN%^y %^CYAN%^s%^GREEN%^i%^CYAN%^l%^GREEN%^k curtains " +
             "%^BLACK%^that divide the room to shift.%^RESET%^\n");
    set_smell("default", "%^MAGENTA%^The scent of %^WHITE%^j%^MAGENTA%^" +
              "a%^WHITE%^smine %^MAGENTA%^and a few %^CYAN%^notes %^MAGENTA%^of " +
              "%^YELLOW%^honey %^RESET%^%^MAGENTA%^waft through.%^RESET%^");
    set_listen("default", "%^CYAN%^The wind hisses through the holes ever so softly.");
    set_items(([
                   "pillows" : "%^BOLD%^%^GREEN%^The pillows, somehow %^CYAN%^" +
                   "waterproofed, %^GREEN%^are scattered all around the area " +
                   "in all shapes and sizes. They look comfortable enough to " +
                   "%^RED%^sit %^GREEN%^on %^YELLOW%^rest %^GREEN%^against.",
                   "pool" : "%^BOLD%^%^WHITE%^The water is clear enough to see the " +
                   "varying %^MAGENTA%^images %^WHITE%^in the bottom of the " +
                   "%^CYAN%^pool. %^WHITE%^One has the choice to %^YELLOW%^bathe " +
                   "%^WHITE%^in either the %^CYAN%^chilly depths %^WHITE%^where " +
                   "the steps descend or by swimming closer to the steamy rocks " +
                   "for a %^RED%^warmer %^WHITE%^soak.",
                   "crystals" : "%^GREEN%^A da%^BOLD%^z%^BLACK%^z%^WHITE%^l%^GREEN%^i" +
                   "%^RESET%^%^GREEN%^ng display of %^YELLOW%^color s%^RESET%^" +
                   "%^ORANGE%^pa%^YELLOW%^rk%^RESET%^%^ORANGE%^l%^YELLOW%^es " +
                   "%^RESET%^%^GREEN%^through the area, caused by the %^WHITE%^" +
                   "light %^GREEN%^bouncing off the j%^CYAN%^a%^WHITE%^g%^GREEN%^" +
                   "ge%^CYAN%^d %^GREEN%^c%^CYAN%^r%^WHITE%^y%^GREEN%^s%^CYAN%^t" +
                   "%^GREEN%^a%^CYAN%^l %^GREEN%^shards %^GREEN%^in the walls.",
               ]));
    set_exits(([
                   "out" : ROOMS "pond"
               ]));
    set_search("default", (: TO, "find_oil" :));
}

void reset()
{
    object ob;
    switch (random(2)) {
    case 0:
        tell_room(TO, "%^BOLD%^%^GREEN%^A rush of %^WHITE%^air %^GREEN%^" +
                  "from the ceiling plays with the %^CYAN%^s%^GREEN%^h%^CYAN%^" +
                  "eer %^GREEN%^c%^CYAN%^u%^GREEN%^rtains spread across the " +
                  "cavern.%^RESET%^");
        break;

    case 1:
        tell_room(TO, "%^CYAN%^The %^WHITE%^haunting %^CYAN%^sound of " +
                  "a %^GREEN%^f%^BOLD%^l%^RESET%^u%^GREEN%^t%^BOLD%^e %^RESET%^" +
                  "%^CYAN%^carries over the %^BOLD%^wind %^RESET%^%^CYAN%^from " +
                  "somewhere distant.");
        break;
    }
    if (!present("crystal ball")) {
        ob = new("/d/magic/obj/crystal_ball");
        ob->move(TO);
        ob->set_short("%^BOLD%^%^BLACK%^A d%^WHITE%^a%^BLACK%^rk " +
                      "c%^RESET%^r%^BOLD%^y%^BLACK%^stal b%^WHITE%^a%^BLACK%^ll%^RESET%^");
        ob->set_long("%^BOLD%^%^BLACK%^The d%^WHITE%^a%^RESET%^r%^BOLD%^" +
                     "%^BLACK%^k b%^WHITE%^a%^BLACK%^ll is cradled within what " +
                     "appears to be %^WHITE%^silver crow's feet. %^BLACK%^While " +
                     "%^CYAN%^ancient %^BLACK%^in appearance, it has been very " +
                     "well cared for over the years. The strange globe appears " +
                     "be continuously assaulted by some w%^WHITE%^i%^RESET%^l" +
                     "%^BOLD%^%^BLACK%^d s%^WHITE%^t%^RESET%^o%^BOLD%^%^BLACK%^rm " +
                     "beneath the surface of the %^WHITE%^glass. %^BLACK%^It sits " +
                     "on a low table, handcarved from the finest %^RESET%^%^RED%^" +
                     "cherry wood %^BOLD%^%^BLACK%^and surrounded by %^GREEN%^p" +
                     "%^CYAN%^i%^RESET%^%^CYAN%^l%^GREEN%^l%^BOLD%^o%^CYAN%^w" +
                     "%^GREEN%^s %^BLACK%^to sit on.%^RESET%^");
    }
    if (!lube) {
        lube = 2;
    }
}

void init()
{
    ::init();
    add_action("bathe", "bathe");
    add_action("sit_pillow", "sit");
    add_action("rest_pillow", "rest");
}

int find_oil()
{
    object ob;
    if (lube > 1) {
        tell_object(TP, "%^BOLD%^You search around the pillows strewn " +
                    "about and find a sculpted bottle.%^RESET%^");
        tell_room(ETP, "%^BOLD%^" + TPQCN + " searches among the pillows " +
                  "and finds something interesting.", TP);
        ob = new("/d/barriermnts/ruins/obj/oils");
        ob->move(TO);
        lube--;
    }else {
        tell_object(TP, "%^BOLD%^You search around and under the " +
                    "pillows to no avail.%^RESET%^");
        tell_room(ETP, "%^BOLD%^" + TPQCN + " rummages around the " +
                  "pillows, but finds nothing of interest.%^RESET%^", TP);
        return 1;
    }
    return 1;
}

int bathe()
{
    string long;
    tell_object(TP, "%^CYAN%^You slip deep into the pool to bathe, " +
                "and begin to feel refreshed.%^RESET%^");
    tell_room(ETP, "%^CYAN%^" + TPQCN + " slips deeper into the pool to " +
              "bathe, looking refreshed for the effort.%^RESET%^", TP);
    long = TP->query_long();
    TP->set("long", "%^BOLD%^%^CYAN%^" + capitalize(TP->QS) + " is surrounded " +
            "by a clean, refreshing scent.%^RESET%^");
    TP->force_me("pose bathing in the pool");
    return 1;
}

int sit_pillow(string str)
{
    if (str == "pillow" || str == "pillows") {
        tell_object(TP, "%^MAGENTA%^You settle against a few of the " +
                    "comfy pillows.%^RESET%^");
        tell_room(ETP, "%^MAGENTA%^" + TPQCN + " settles against a few of " +
                  "the comfy pillows.%^RESET%^", TP);
        TP->force_me("pose sitting in a pile of pillows");
        return 1;
    }
    return 1;
}

int rest_pillow()
{
    tell_object(TP, "%^MAGENTA%^You lay back against the colorful " +
                "pillows.%^RESET%^");
    tell_room(ETP, "%^MAGENTA%^" + TPQCN + " lays back against the colorful " +
              "pillows.%^RESET%^", TP);
    TP->force_me("pose laying in a pile of pillows");
    return 1;
}
