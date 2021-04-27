#include <std.h>
#include "../defs.h"
inherit VAULT;

// The Bloody Scourage Inn (Innaeli & Anson's HM 'home')
// Design Work Written by Innaeli
// Put into game December 2008 :: Nienne
// Wizard assisted by Lurue
// door put in by hades feb 2010

int count;

void create()
{
    ::create();
    set_property("light", 1);
    set_property("indoors", 1);
    set_terrain(STONE_BUILDING);
    set_travel(SLICK_FLOOR);
    set_name("The Bloody Scourge Inn");
    set_short("%^BOLD%^%^BLACK%^The %^BOLD%^%^RED%^B%^RESET%^%^RED%^l" +
              "o%^BOLD%^%^RED%^od%^RESET%^%^RED%^y S%^BOLD%^%^RED%^c" +
              "o%^RESET%^%^RED%^ur%^BOLD%^%^RED%^g%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^ " +
              "Inn%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^The %^BOLD%^%^RED%^B%^RESET%^%^RED%^l" +
             "o%^BOLD%^%^RED%^od%^RESET%^%^RED%^y S%^BOLD%^%^RED%^co%^RESET%^%^RED%^u" +
             "r%^BOLD%^%^RED%^g%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^ Inn%^RESET%^ \n" +
             "%^BOLD%^%^BLACK%^Welcome to the Bloody Scourge Inn! Oil lamps covered " +
             "with %^RESET%^%^RED%^crimson shades%^BOLD%^%^BLACK%^ lend an eerie, " +
             "%^RESET%^f%^BOLD%^%^WHITE%^li%^RESET%^cke%^BOLD%^%^WHITE%^ri%^RESET%^n" +
             "g %^RESET%^%^RED%^red gl%^BOLD%^%^RED%^o%^RESET%^%^RED%^w" +
             "%^BOLD%^%^BLACK%^ to the atmosphere. The bare, cold stone walls reach " +
             "to dizzying heights, and the ceiling above is elaborately painted " +
             "with a grand mural of angels of d%^RESET%^a%^BOLD%^%^WHITE%^r" +
             "%^BOLD%^%^BLACK%^kne%^BOLD%^%^WHITE%^s%^RESET%^s%^BOLD%^%^BLACK%^ " +
             "and %^RESET%^li%^BOLD%^%^WHITE%^g%^BOLD%^%^BLACK%^h%^RESET%^t" +
             "%^BOLD%^%^BLACK%^ engaged in an eternal battle. Huge %^RESET%^%^RED%^" +
             "s%^MAGENTA%^t%^ORANGE%^a%^BOLD%^%^BLACK%^i%^RESET%^%^RED%^n%^ORANGE%^e" +
             "%^MAGENTA%^d-g%^BOLD%^%^BLACK%^l%^RESET%^%^RED%^a%^ORANGE%^s" +
             "%^MAGENTA%^s%^BOLD%^%^BLACK%^ windows allow dim light to filter in. " +
             "Below, dark wooden tables cover a part of the floor, their high-backed " +
             "chairs draped in %^RESET%^%^RED%^red silk%^BOLD%^%^BLACK%^. This " +
             "sitting area is marked by a %^RESET%^%^RED%^red sto%^BOLD%^%^BLACK%^n" +
             "%^RESET%^%^RED%^e fl%^BOLD%^%^RED%^o%^RESET%^%^RED%^or%^BOLD%^%^BLACK%^" +
             ". Another sitting area appears to be much better for casual lounging, " +
             "offering dark tables low to the floor, surrounded by %^BOLD%^%^RED%^c" +
             "%^RESET%^%^RED%^rim%^BOLD%^%^RED%^so%^RESET%^%^RED%^n v%^BOLD%^%^RED%^e" +
             "l%^RESET%^%^RED%^ve%^BOLD%^%^RED%^t c%^RESET%^%^RED%^us%^BOLD%^%^RED%^h" +
             "io%^RESET%^%^RED%^n%^BOLD%^%^RED%^s%^BOLD%^%^BLACK%^ for seating. A " +
             "black %^RESET%^hookah %^BOLD%^%^BLACK%^is nestled among some " +
             "comfortable cushions in the corner. This " +
             "area is also defined by a pattern of %^RESET%^%^RED%^red stones" +
             "%^BOLD%^%^BLACK%^, and an ebony walkway lazily snakes its way " +
             "throughout the room, dividing the two sections. At the far end of the " +
             "room, a rasied dais is home to a large black piano, and musicians can " +
             "often be heard here, providing light music to the patrons. Painted on " +
             "the wall behind the stage is a mural of a %^RESET%^%^RED%^bloody " +
             "scourge%^BOLD%^%^BLACK%^. In the center of the room is a grand circular " +
             "bar, its surface covered in reflective black marble, shot through with " +
             "%^RESET%^jag%^BOLD%^%^BLACK%^g%^RESET%^ed%^BOLD%^%^BLACK%^ lines of " +
             "%^RESET%^%^ORANGE%^g%^YELLOW%^o%^RESET%^%^ORANGE%^ld%^BOLD%^%^BLACK%^. " +
             "Comfortable stools covered in %^RESET%^%^RED%^crimson silk" +
             "%^BOLD%^%^BLACK%^ encircle its wide perimeter. A grand ebony staircase " +
             "leads to the guest rooms upstairs, while a %^RESET%^be%^BOLD%^%^WHITE%^" +
             "a%^BOLD%^%^BLACK%^d%^RESET%^ed%^BOLD%^%^BLACK%^ curtain leads west into " +
             "the kitchen, and to the south is a red door with %^BOLD%^%^RED%^f" +
             "%^RESET%^%^RED%^l%^ORANGE%^a%^MAGENTA%^m%^RED%^e%^BOLD%^%^RED%^s" +
             "%^BOLD%^%^BLACK%^ painted around its frame.%^RESET%^\n");

    set_smell("default", "%^RESET%^%^RED%^It smells like liquor, with an " +
              "underlying scent of blood.%^RESET%^");
    set_listen("default", "%^RESET%^%^MAGENTA%^Soft music is almost inaudible " +
               "over the riot of drunken patrons.%^RESET%^");

    set_items(([
                   ({ "lamp", "lamps" }) : "%^BOLD%^%^RED%^F%^RESET%^%^RED%^l%^BOLD%^%^BLACK%^a" +
                   "m%^YELLOW%^e%^RESET%^%^ORANGE%^s%^RESET%^ dance behind %^RESET%^" +
                   "%^RED%^crimson shades%^RESET%^, lending a %^RESET%^%^RED%^red " +
                   "%^BOLD%^%^RED%^g%^RESET%^%^RED%^lo%^BOLD%^%^RED%^w%^RESET%^ to the " +
                   "atmosphere. The lamps are rather large, providing plenty of %^YELLOW%^" +
                   "light%^RESET%^ as they hang from %^BOLD%^%^BLACK%^black chains%^RESET%^ " +
                   "anchored to the high ceiling. They loom overhead at even intervals." +
                   "%^RESET%^",

                   ({ "walls", "wall" }) : "%^RESET%^The walls are made from unfinished, " +
                   "%^BOLD%^%^BLACK%^gr%^RESET%^e%^BOLD%^%^BLACK%^y sto%^RESET%^n%^BOLD%^" +
                   "%^BLACK%^e%^RESET%^ that seems quite old. It is rough and cold beneath " +
                   "your fingers.%^RESET%^",

                   ({ "ceiling" }) : "%^RESET%^A %^BOLD%^%^BLACK%^da%^RESET%^%^MAGENTA%^r" +
                   "%^BOLD%^%^BLUE%^k%^BOLD%^%^BLACK%^ sky%^RESET%^ is painted on the " +
                   "ceiling, with even %^RESET%^%^MAGENTA%^d%^BOLD%^%^BLACK%^ar%^BOLD%^" +
                   "%^BLUE%^k%^BOLD%^%^BLACK%^e%^RESET%^%^MAGENTA%^r%^BOLD%^%^BLACK%^ " +
                   "clouds%^RESET%^ edged with light from the %^YELLOW%^g%^RESET%^" +
                   "%^ORANGE%^o%^YELLOW%^ld%^RESET%^%^ORANGE%^e%^YELLOW%^n li%^RESET%^" +
                   "g%^BOLD%^%^WHITE%^h%^YELLOW%^tn%^RESET%^i%^ORANGE%^n%^YELLOW%^g" +
                   "%^RESET%^ that splits the scene. %^BOLD%^%^WHITE%^An%^RESET%^g" +
                   "%^BOLD%^%^BLACK%^e%^BOLD%^%^WHITE%^ls%^RESET%^ with %^RESET%^%^RED%^" +
                   "flaming%^RESET%^ weapons of every variety are entwined in a %^RESET%^" +
                   "%^RED%^blo%^BOLD%^%^RED%^od%^RESET%^%^RED%^y b%^BOLD%^%^RED%^a" +
                   "%^RESET%^%^RED%^ttle%^RESET%^, some with %^BOLD%^%^BLACK%^ebony" +
                   "%^RESET%^ wings, others %^BOLD%^%^WHITE%^ivory%^RESET%^, and some " +
                   "with wings of %^RESET%^%^RED%^crimson%^RESET%^. %^BOLD%^%^BLACK%^" +
                   "Wraiths%^RESET%^ sweep through the battlefield, devouring the fallen " +
                   "angels. One could almost guess that the image is full of detail, but " +
                   "the ceiling reaches so far overhead, it is difficult to get a clear " +
                   "grasp of its depth.%^RESET%^",

                   ({ "window", "windows" }) : "%^RESET%^The windows are huge and old, some " +
                   "are quite cr%^BOLD%^%^BLACK%^a%^RESET%^ck%^BOLD%^%^BLACK%^e%^RESET%^d " +
                   "and frail. Colored panes depict %^RESET%^%^RED%^blo%^BOLD%^%^RED%^o" +
                   "%^RESET%^%^RED%^dy%^RESET%^ images of t%^BOLD%^%^BLACK%^or%^RESET%^t" +
                   "u%^BOLD%^%^BLACK%^r%^RESET%^e, mu%^BOLD%^%^BLACK%^t%^RESET%^i" +
                   "l%^BOLD%^%^BLACK%^at%^RESET%^ion and d%^BOLD%^%^BLACK%^e%^RESET%^ath. " +
                   "Its really rather disturbing.%^RESET%^",

                   ({ "table", "tables", "chair", "chairs", "cushion", "cushions" }) : "%^RESET%^In " +
                   "one section of the room, the %^BOLD%^%^BLACK%^ebony tables%^RESET%^ " +
                   "are circular and sit high off the ground. These are surrounded by " +
                   "matching %^BOLD%^%^BLACK%^ebony chairs%^RESET%^ covered in %^RESET%^" +
                   "%^RED%^crimson padding%^RESET%^ for comfort. In the center of each " +
                   "table, small, %^RESET%^%^RED%^red gla%^BOLD%^%^RED%^s%^RESET%^%^RED%^s " +
                   "bowls%^RESET%^ hold a single %^BOLD%^candle%^RESET%^ to provide some " +
                   "dim li%^BOLD%^gh%^RESET%^ti%^BOLD%^n%^RESET%^g. The other section " +
                   "features rather low, rectangular tables made from solid %^BOLD%^" +
                   "%^BLACK%^ebony%^RESET%^. These, too, have the small bowls as " +
                   "centerpieces, and theyre surrounded by plush %^RESET%^%^RED%^crimson " +
                   "pillows%^RESET%^ for sitting.%^RESET%^",

                   ({ "floor" }) : "%^RESET%^A %^BOLD%^%^BLACK%^black walkway%^RESET%^ cuts " +
                   "through the room and snakes around the perimeter of the two sitting " +
                   "areas, where the floor is %^RESET%^%^RED%^red%^RESET%^ and blends in " +
                   "seamlessly with the %^BOLD%^%^BLACK%^black%^RESET%^. The entire floor " +
                   "is mildly %^BOLD%^re%^RESET%^fl%^BOLD%^ect%^RESET%^iv%^BOLD%^e" +
                   "%^RESET%^, kind of s%^BOLD%^%^BLACK%^cu%^RESET%^ff%^BOLD%^%^BLACK%^e" +
                   "%^RESET%^d and rather s%^BOLD%^%^BLACK%^t%^RESET%^ic%^ORANGE%^k" +
                   "%^RESET%^y from drinks carelessly spilled by drunken patrons.%^RESET%^",

                   ({ "dais" }) : "%^RESET%^The dais is carved from the same %^BOLD%^%^BLACK%^black " +
                   "stone %^RESET%^as the floor, and stands only half a foot tall. It is mostly " +
                   "bare except for a large %^BOLD%^%^BLACK%^black piano%^RESET%^. A large mural " +
                   "of a %^RED%^blo%^BOLD%^o%^RESET%^%^RED%^dy s%^BOLD%^%^BLACK%^co" +
                   "%^RESET%^%^RED%^ur%^BOLD%^g%^RESET%^%^RED%^e %^RESET%^is painted on the wall " +
                   "behind the dais.",

                   ({ "curtain" }) : "%^RESET%^Carved from small %^BOLD%^b%^RESET%^o%^BOLD%^ne " +
                   "fr%^RESET%^ag%^BOLD%^me%^RESET%^n%^BOLD%^ts%^RESET%^, the curtain conceals " +
                   "the passage to the kitchen. Moving in or out of it causes the bones to click " +
                   "and titter.",

                   ({ "doorframe", "door" }) : "%^RESET%^The doorframe encircling the portal southwards " +
                   "is jagged and brightly painted to look as if %^BOLD%^%^RED%^f%^RESET%^%^RED%^l" +
                   "%^ORANGE%^a%^MAGENTA%^m%^RED%^e%^BOLD%^s %^RESET%^are licking across its surface.",

                   ({ "piano" }) : "%^RESET%^This is a traditional piano. Sitting on its " +
                   "%^BOLD%^%^BLACK%^black%^RESET%^ surface is a pretty, %^RESET%^%^RED%^" +
                   "red va%^RESET%^%^MAGENTA%^s%^RED%^e%^RESET%^ filled with %^RESET%^" +
                   "%^RED%^c%^BOLD%^%^RED%^r%^RESET%^%^RED%^im%^BOLD%^%^RED%^s%^MAGENTA%^" +
                   "o%^RESET%^%^RED%^n ros%^RESET%^%^MAGENTA%^e%^RESET%^%^RED%^s%^RESET%^. " +
                   "An %^BOLD%^%^BLACK%^ebony bench%^RESET%^ padded in %^RESET%^%^RED%^" +
                   "crimson silk%^RESET%^ is used for sitting and playing comfortably at " +
                   "the %^BOLD%^%^WHITE%^i%^BOLD%^%^BLACK%^v%^BOLD%^%^WHITE%^o%^BOLD%^" +
                   "%^BLACK%^r%^BOLD%^%^WHITE%^y%^RESET%^ keys.%^RESET%^",

                   ({ "mural" }) : "%^RESET%^The wall behind the dais is painted " +
                   "%^RESET%^%^RED%^dar%^BOLD%^%^BLACK%^k r%^RESET%^%^RED%^ed%^RESET%^ " +
                   "and features a large, coiled %^BOLD%^scourge%^RESET%^ made from " +
                   "%^BOLD%^%^BLACK%^black onyx%^RESET%^. The lash is lined with sharpened " +
                   "%^BOLD%^%^WHITE%^silver %^BOLD%^%^BLACK%^b%^RESET%^%^RED%^a" +
                   "%^BOLD%^%^BLACK%^rbs%^RESET%^ that actually protrude from the wall in " +
                   "malicious tiny spikes, and theyre coated in %^BOLD%^%^WHITE%^sp" +
                   "%^RESET%^a%^BOLD%^%^WHITE%^rk%^RESET%^li%^BOLD%^%^WHITE%^ng " +
                   "%^BOLD%^%^RED%^r%^RESET%^%^RED%^u%^BOLD%^%^RED%^bi%^RESET%^%^RED%^e" +
                   "%^BOLD%^%^RED%^s%^RESET%^. While simple, its masterfully painted and " +
                   "provides an interesting backdrop for the performance area, and it " +
                   "stands as a reminder of the bars namesake.%^RESET%^",

                   ({ "bar", "stools", "stool" }) : "%^RESET%^The bar is undoubtedly the " +
                   "centerpiece of the room. It is circular and made from %^BOLD%^" +
                   "%^BLACK%^ebony%^RESET%^, with a small access door on one side. The " +
                   "surface is covered with %^BOLD%^%^BLACK%^black marble%^RESET%^, " +
                   "streaked with %^BOLD%^%^BLACK%^ja%^RESET%^g%^BOLD%^%^BLACK%^ged" +
                   "%^RESET%^ lines of %^YELLOW%^gold%^RESET%^. Many fine %^CYAN%^liquors" +
                   "%^RESET%^ and %^MAGENTA%^wines%^RESET%^ are stocked beneath the bar, " +
                   "as well as clean glasses and a few %^RESET%^%^ORANGE%^casks%^RESET%^ " +
                   "of %^YELLOW%^ale%^RESET%^. Encircling the bar are %^BOLD%^%^BLACK%^" +
                   "ebony barstools%^RESET%^, covered with %^RESET%^%^RED%^crimson " +
                   "padding%^RESET%^.",

                   ({ "staircase" }) : "%^RESET%^The staircase is carved from heavy " +
                   "%^BOLD%^%^BLACK%^ebony%^RESET%^ and spirals up to the second floor " +
                   "of the inn. It is slightly steep, and falling down it would be a " +
                   "very painful voyage.%^RESET%^",

                   "hookah" : "%^BOLD%^%^BLACK%^Etched into the black, glass base of the " +
                   "hookah is the silhouette of a %^RESET%^%^RED%^r%^BOLD%^e%^RESET%^" +
                   "%^RED%^d %^BOLD%^dr%^RESET%^%^RED%^ag%^BOLD%^o%^RESET%^%^RED%^n " +
                   "%^BOLD%^%^BLACK%^with %^RESET%^%^RED%^r%^BOLD%^u%^RESET%^%^RED%^by " +
                   "ey%^BOLD%^e%^RESET%^%^RED%^s%^BOLD%^%^BLACK%^. The base is filled " +
                   "with water, and four slender tubes sprout out from the top. " +
                   "Comfortable %^RESET%^%^RED%^cushions %^BOLD%^%^BLACK%^surround the " +
                   "hookah to recline on while you smoke. If you'd like, you may <start " +
                   "smoking>.",
               ]));
    set_exits(([
                   "stairs" : ROOMS "bsb5",
                   "curtain" : ROOMS "bsb3",
                   "south" : ROOMS "bsb2",
                   "out" : "/d/dagger/tonovi/1path1",
               ]));
    set_pre_exit_functions(({ "curtain", "south", "out", "stairs" }), ({ "goto_kitchen", "goto_private", "leave_fun", "leave_fun" }));
    set_door("cathedral door", "/d/dagger/tonovi/1path1", "out", 0);
    set_locked("cathedral door", 0);
    lock_difficulty("cathedral door",  "/daemon/player_housing"->get_phouse_lock_dc("poor"), "lock");
    set_door_description("cathedral door",
                         "%^BOLD%^%^BLACK%^The doors are large and heavy and " +
                         "can be swung open to create a grand exit from the " +
                         "establishment. They have been painted a deep shade" +
                         " of crimson, resembling blood, and are lined with" +
                         " a black stone that faintly glitters in the dim" +
                         " lights of the bar.%^RESET%^");
}

void reset()
{
    ::reset();
    if (random(3)) {
        tell_room(TO, "A busboy wearing a uniform wanders through quietly " +
                  "and unobtrusively straightening the chairs and cleaning up " +
                  "the empty tables.");
        while (present("bottle", TO)) {
            present("bottle", TO)->remove();
        }
    }
    if (!present("barkeep")) {
        new(MON "bsbbartender")->move(TO);
    }
}

void init()
{
    ::init();
    add_action("read", "read");
    add_action("sneak_fun", "sneak");
    add_action("peer_fun", "peer");
    add_action("start", "start");
    add_action("smoke", "smoke");
    add_action("stop", "stop");
}

int leave_fun(string str)
{
    if ((int)TP->query_property("smoking hookah") == 1) {
        tell_object(TP, "You cannot leave while smoking the hookah!");
        return 0;
    }
    return 1;
}

int sneak_fun(string str)
{
    if ((int)TP->query_property("smoking hookah") == 1) {
        tell_object(TP, "You cannot leave while smoking the hookah!");
        return 1;
    }
    if (TP->query_true_invis()) {
        return 0;
    }
    if (!str) {
        return 0;
    }
    if (str != "south" && str != "s") {
        return 0;
    }
    tell_object(TP, "%^RESET%^%^RED%^The painted flames encircling the " +
                "doorframe briefly %^BOLD%^%^RED%^glow%^RESET%^%^RED%^ in warning. You " +
                "suspect trying to sneak through is a bad idea.");
    return 1;
}

int peer_fun(string str)
{
    string mystring, mystring2;
//   if(TP->query_true_invis()) return 0;
    if (!str) {
        return 0;
    }
    if (sscanf(str, "%s %s", mystring, mystring2) != 2) {
        mystring = str;
    }
    if (mystring != "south" && mystring != "s") {
        return 0;
    }
    tell_object(TP, "%^RESET%^%^RED%^The bright %^RED%^f%^RESET%^%^RED%^l"
                "%^ORANGE%^a%^MAGENTA%^m%^RED%^e%^BOLD%^s %^RESET%^%^RED%^licking the "
                "doorframe make it too difficult to see what lies beyond.%^RESET%^");
    return 1;
}

int goto_kitchen()
{
    if ((int)TP->query_property("smoking hookah") == 1) {
        tell_object(TP, "You cannot leave while smoking the hookah!");
        return 0;
    }
    if (!TP->query_true_invis()) {
        tell_room(TO, "%^BOLD%^%^WHITE%^The b%^RESET%^ea%^BOLD%^d" +
                  "%^RESET%^e%^BOLD%^d c%^RESET%^u%^BOLD%^rta%^RESET%^in%^BOLD%^" +
                  "%^WHITE%^s rattle as they are drawn aside.%^RESET%^");
        tell_room(ROOMS "bsb3", "%^BOLD%^%^WHITE%^The b%^RESET%^ea%^BOLD%^d" +
                  "%^RESET%^e%^BOLD%^d c%^RESET%^u%^BOLD%^rta%^RESET%^in%^BOLD%^%^WHITE%^" +
                  "s rattle as they are drawn aside.%^RESET%^");
    }
    return 1;
}

int goto_private()
{
    object myring;
    if ((int)TP->query_property("smoking hookah") == 1) {
        tell_object(TP, "You cannot leave while smoking the hookah!");
        return 0;
    }
    if (TP->query_true_invis()) {
        return 1;
    }
    myring = present("bsbrubyring", TP);
    if (myring) {
        tell_object(TP, "%^RESET%^%^RED%^The painted flames encircling the " +
                    "doorframe briefly %^BOLD%^%^RED%^glow%^RESET%^%^RED%^ as you pass " +
                    "through the door.");
        tell_room(TO, "%^RESET%^%^RED%^The painted flames encircling the " +
                  "doorframe %^BOLD%^%^RED%^glow%^RESET%^%^RED%^ as " + TP->QCN + " moves south.", TP);
        return 1;
    }
    tell_object(TP, "%^RESET%^%^RED%^The flames encircling the doorframe " +
                "%^BOLD%^%^RED%^glow%^RESET%^%^RED%^ and you smack into an invisible " +
                "barrier.");
    tell_room(TO, "%^RESET%^%^RED%^The flames encircling the doorframe " +
              "%^BOLD%^%^RED%^glow%^RESET%^%^RED%^, and " + TP->QCN + " bounces off the " +
              "invisible barrier!", TP);
    return 0;
}

int read(string str)
{
    object obj;
    int i;
    string* names;
    obj = present("barkeep");
    if (!obj) {
        return 0;
    }
    if (str == "drinks menu") {
        message("Ninfo", "You look over the drinks menu:\n" +
                "%^RESET%^%^RED%^~*~*~*~*~*~*~*~*~*~* %^BOLD%^%^BLACK%^DRINKS " +
                "MENU %^RESET%^%^RED%^*~*~*~*~*~*~*~*~*~%^RESET%^\n\n" +
                "%^BOLD%^%^WHITE%^Non-Alcoholic Drinks%^RESET%^\n\n", TP);

        message("Ninfo", "    %^BOLD%^%^CYAN%^Tyrs Tears \t\t\t" +
                " " + (int)obj->get_price("tyrs tears") + " silver pieces\n", TP);

        message("Ninfo", "    %^BOLD%^%^BLUE%^Water \t\t\t " +
                " " + (int)obj->get_price("water") + " silver pieces\n", TP);

        message("Ninfo", "    %^BOLD%^%^RED%^Bloody Virgin \t\t" +
                " " + (int)obj->get_price("bloody virgin") + " silver pieces\n\n", TP);

        message("Ninfo", "%^BOLD%^%^WHITE%^Mixed Drinks%^RESET%^\n\n", TP);

        message("Ninfo", "    %^BOLD%^%^BLACK%^Black Widow \t\t" +
                " " + (int)obj->get_price("black widow") + " silver pieces\n", TP);

        message("Ninfo", "    %^BOLD%^%^RED%^Death by Fire \t\t" +
                " " + (int)obj->get_price("death by fire") + " silver pieces\n", TP);

        message("Ninfo", "    %^RESET%^%^MAGENTA%^Dragons Blood \t\t" +
                " " + (int)obj->get_price("dragons blood") + " silver pieces\n", TP);

        message("Ninfo", "    %^RESET%^%^RED%^Bloody Scourge \t\t" +
                " " + (int)obj->get_price("bloody scourge") + " silver pieces\n\n", TP);

        message("Ninfo", "%^BOLD%^%^WHITE%^Shots%^RESET%^\n\n", TP);

        message("Ninfo", "    %^YELLOW%^Tequila \t\t\t" +
                " " + (int)obj->get_price("tequila") + " silver pieces\n", TP);

        message("Ninfo", "    %^RESET%^%^ORANGE%^Whiskey \t\t\t" +
                " " + (int)obj->get_price("whiskey") + " silver pieces\n", TP);

        message("Ninfo", "    %^BOLD%^%^BLACK%^Dark Rum \t\t\t" +
                " " + (int)obj->get_price("dark rum") + " silver pieces\n", TP);

        message("Ninfo", "    %^RESET%^%^MAGENTA%^Vodka \t\t\t" +
                " " + (int)obj->get_price("vodka") + " silver pieces\n\n", TP);

        message("Ninfo", "%^BOLD%^%^WHITE%^Beers%^RESET%^\n\n", TP);

        message("Ninfo", "    %^BOLD%^%^BLACK%^Talassan Black \t\t" +
                " " + (int)obj->get_price("talassan black") + " silver pieces\n", TP);

        message("Ninfo", "    %^RESET%^%^ORANGE%^Amber Lager \t\t" +
                " " + (int)obj->get_price("amber lager") + " silver pieces\n", TP);

        message("Ninfo", "    %^BOLD%^%^GREEN%^Noblemans Special \t\t" +
                " " + (int)obj->get_price("noblemans special") + " silver " +
                "pieces\n\n", TP);

        message("Ninfo", "%^BOLD%^%^WHITE%^Wines%^RESET%^\n\n", TP);

        message("Ninfo", "    %^BOLD%^%^MAGENTA%^Feywine \t\t       " +
                " " + (int)obj->get_price("feywine") + " silver pieces\n", TP);

        message("Ninfo", "    %^BOLD%^%^RED%^Blood Wine \t\t\t" +
                " " + (int)obj->get_price("blood wine") + " silver pieces\n", TP);

        message("Ninfo", "    %^BOLD%^%^BLACK%^Moon Wine \t\t\t" +
                " " + (int)obj->get_price("moon wine") + " silver pieces\n\n", TP);

        message("Ninfo", "%^RESET%^%^RED%^~*~*~*~*~*~*~*~*~*~*~*~*" +
                "~*~*~*~*~*~*~*~*~*~*~*~*~*~%^RESET%^\n", TP);

        return 1;
    }
    if (str == "food menu") {
        message("Ninfo", "You look over the food menu:\n" +
                "%^RESET%^%^RED%^~*~*~*~*~*~*~*~*~*~* %^BOLD%^%^BLACK%^FOOD " +
                "MENU %^RESET%^%^RED%^*~*~*~*~*~*~*~*~*~*~%^RESET%^\n\n" +
                "%^BOLD%^%^WHITE%^Appetizers%^RESET%^\n\n", TP);

        message("Ninfo", "    %^YELLOW%^Fried Cheese \t\t" +
                " " + (int)obj->get_price("fried cheese") + " silver pieces\n", TP);

        message("Ninfo", "    %^RESET%^%^ORANGE%^Soft Pretzel \t\t" +
                " " + (int)obj->get_price("soft pretzel") + " silver pieces\n", TP);

        message("Ninfo", "    %^BOLD%^%^RED%^Spicy Chicken Wings \t" +
                " " + (int)obj->get_price("spicy chicken wings") + " silver " +
                "pieces\n\n", TP);

        message("Ninfo", "%^BOLD%^%^WHITE%^Dinner%^RESET%^\n\n", TP);

        message("Ninfo", "    %^BOLD%^%^RED%^Bloody Steak \t\t" +
                " " + (int)obj->get_price("bloody steak") + " silver pieces\n", TP);

        message("Ninfo", "    %^RESET%^%^RED%^Flaming Chicken \t\t" +
                " " + (int)obj->get_price("flaming chicken") + " silver pieces\n", TP);

        message("Ninfo", "    %^RESET%^%^ORANGE%^Braised Ribs \t\t" +
                " " + (int)obj->get_price("braised ribs") + " silver pieces\n", TP);

        message("Ninfo", "    %^YELLOW%^Chefs Stew \t\t\t" +
                " " + (int)obj->get_price("chefs stew") + " silver pieces\n\n", TP);

        message("Ninfo", "%^BOLD%^%^WHITE%^Dessert%^RESET%^\n\n", TP);

        message("Ninfo", "    %^BOLD%^%^WHITE%^Vanilla Ice Cream  \t\t" +
                " " + (int)obj->get_price("vanilla ice cream") + " silver " +
                "pieces\n", TP);

        message("Ninfo", "    %^BOLD%^%^BLACK%^Chocolate Chip Cake \t" +
                " " + (int)obj->get_price("chocolate chip cake") + " silver " +
                "pieces\n", TP);

        message("Ninfo", "    %^RESET%^%^RED%^Chocolate Strawberries \t" +
                " " + (int)obj->get_price("chocolate strawberries") + " silver " +
                "pieces\n\n", TP);

        message("Ninfo", "%^RESET%^%^RED%^~*~*~*~*~*~*~*~*~*~*~*~*" +
                "~*~*~*~*~*~*~*~*~*~*~*~*~*~%^RESET%^\n", TP);

        return 1;
    }
    if (str == "menu") {
        tell_object(TP, "You can read the food menu or the drinks menu.");
        return 1;
    }
    return 0;
}

int start(string str)
{
    if (!str || str != "smoking") {
        tell_object(TP, "Try 'start smoking'.");
        return 1;
    }
    if (count > 3) {
        tell_object(TP, "There are no more pipes on the hookah.  " +
                    "Someone else will have to get up first.");
        return 1;
    }
    if (TP->query_property("smoking hookah")) {
        tell_object(TP, "Perhaps you've had enough!  You're already " +
                    "smoking the hookah.");
        return 1;
    }
    tell_object(TP, "%^BOLD%^You settle on the cushions near the far " +
                "corner and take up one of the pipes.  You inhale, drawing " +
                "in the sweet tumbak that tastes lightly of honey and fruit " +
                "mixed with tobacco.  You may <smoke> whenever you like or " +
                "<stop smoking> when you are finished.");
    tell_room(ETP, "%^BOLD%^" + TPQCN + " settles on one of the cushions " +
              "in the far corner and begins smoking the hookah.", TP);
    TP->force_me("pose sitting in the corner smoking the hookah");
    TP->set_property("smoking hookah", 1);
    count++;
    return 1;
}

int smoke(string str)
{
    if (!str || str == "hookah") {
        if (!TP->query_property("smoking hookah")) {
            tell_object(TP, "You have not started smoking the hookah!");
            return 1;
        }
        tell_object(TP, "%^BOLD%^You take a long drag off the hookah, " +
                    "enjoying the cool, lightly spiced smoke.");
        tell_room(ETP, "%^BOLD%^" + TPQCN + " takes a drag off the hookah " +
                  "with a smile, sending a small puff of smoke in the air.", TP);
        if (!random(4)) {
            switch (random(6)) {
            case 0:  tell_object(TP, "%^YELLOW%^You watch in " +
                                 "amazement as the puff of smoke turns into " +
                                 "a prancing cat.");
                break;

            case 1:  tell_object(TP, "%^BOLD%^%^BLUE%^You could swear " +
                                 "that puff of smoke looks just like a huge " +
                                 "ship sailing on the ocean.");
                break;

            case 2:  tell_object(TP, "%^BOLD%^You see many different " +
                                 "%^RESET%^%^CYAN%^c%^BLUE%^o%^MAGENTA%^l%^RED%^o" +
                                 "%^GREEN%^r%^YELLOW%^s %^WHITE%^swirling in " +
                                 "the smoke.");
                break;

            case 3:  tell_object(TP, "%^MAGENTA%^You watch the smoke " +
                                 "swirl in the air above your head.");
                break;

            case 4:  tell_object(TP, "%^CYAN%^You watch in " +
                                 "amazement as the puff of smoke turns into " +
                                 "a proud stallion.  Look...he's running " +
                                 "through the fields!");
                break;

            case 5:  tell_object(TP, "%^BOLD%^You look up at the mural " +
                                 "on the ceiling as the smoke relaxes you");
                break;
            }
            tell_room(ETP, "" + TPQCN + " stares at the ceiling with " +
                      "wide eyes.", TP);
        }
        return 1;
    }
    return 0;
}

int stop(string str)
{
    if (!str || str != "smoking") {
        tell_object(TP, "Try 'stop smoking'.");
        return 1;
    }
    if (!TP->query_property("smoking hookah")) {
        tell_object(TP, "You are not smoking the hookah.");
        return 1;
    }
    tell_object(TP, "%^BOLD%^You set the pipe aside and stand, " +
                "feeling slightly dizzy.");
    tell_room(ETP, "%^BOLD%^" + TPQCN + " puts the pipe aside and stands.", TP);
    TP->force_me("pose clear");
    TP->remove_property("smoking hookah");
    count = count - 1;
    return 1;
}
