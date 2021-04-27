#include <std.h>
inherit WIZ;

void create() {
        ::create();
        set_property("outdoors",0);  // is 0 if outdoors barely visible for humans!
        set_property("light",4);    // 
        set_terrain(WIZ);
        set_travel(WIZ);
        set_name(" Cobblestone Pathway ");    // should be the same as the set_short but without
colors
        set_short("%^RESET%^%^ORANGE%^Cobblestone%^GREEN%^ pathway%^RESET%^);  
        set_long(%^RESET%^%^GREEN%^The %^BOLD%^%^BLACK%^dark %^RESET%^%^ORANGE%^cobblestone%^GREEN%^ pathway leads outside of the temple proper. It is surrounded by a dense, %^BOLD%^%^BLACK%^dark %^GREEN%^forest%^RESET%^%^GREEN%^ of %^RESET%^twisted%^GREEN%^ trees that sway gently in an unfelt %^BOLD%^%^CYAN%^wind%^RESET%^%^GREEN%^. The pathway is composed of %^BOLD%^%^BLACK%^bl%^RESET%^ac%^BOLD%^%^BLACK%^k g%^RESET%^ra%^BOLD%^%^BLACK%^ni%^RESET%^te%^GREEN%^ with jagged uncut %^MAGENTA%^purple %^MAGENTA%^j%^BOLD%^%^MAGENTA%^a%^RESET%^%^MAGENTA%^sp%^BOLD%^%^MAGENTA%^e%^RESET%^%^MAGENTA%^r%^GREEN%^ and %^BOLD%^%^BLACK%^black %^WHITE%^o%^MAGENTA%^p%^WHITE%^als%^RESET%^%^GREEN%^ embedded within its surface. An old deteriorated %^BOLD%^%^BLACK%^bl%^RESET%^ac%^BOLD%^%^BLACK%^k g%^RESET%^ra%^BOLD%^%^BLACK%^ni%^RESET%^te%^GREEN%^ wall %^BOLD%^%^GREEN%^snakes%^RESET%^%^GREEN%^ through the forest with uneven edges and deep chips on its exterior. Resting every few feet on the wall are %^RESET%^gargoyles%^GREEN%^, %^BOLD%^%^BLACK%^nightmares%^RESET%^%^GREEN%^, and an assortment of %^RED%^undead creatures%^GREEN%^ in realistic detail. %^RESET%^
");
        set_smell("default","%^RESET%^ORANGE%^%^RESET%^ORANGE%^You smell %^RED%^e%^MAGENTA%^x%^RED%^otic%^ORANGE%^ plant life with an underlying smell of %^RED%^blood%^ORANGE%^.  %^RESET%^  ");
        set_listen("default","%^RESET%^%^GREEN%^An unknown creature %^BOLD%^%^WHITE%^howls%^RESET%^%^GREEN%^ in the distance.");
// These are the things you can look at.  If you want more than one word or
words (oil lamp and lamp, chair and chairs) to work, all the words you want
to see the same thing go in the ({ }) like chair & chairs below.
        set_items(([
           ({"jasper","opal",pathway}) : "%^RESET%^%^ORANGE%^Thick, %^BOLD%^%^BLACK%^bl%^RESET%^ac%^BOLD%^%^BLACK%^k g%^RESET%^ra%^BOLD%^%^BLACK%^ni%^RESET%^te%^ORANGE%^ wall %^BOLD%^%^GREEN%^snakes%^RESET%^%^ORANGE%^ embedded with an assorted sizes of %^MAGENTA%^purple %^MAGENTA%^j%^BOLD%^%^MAGENTA%^a%^RESET%^%^MAGENTA%^sp%^BOLD%^%^MAGENTA%^e%^RESET%^%^MAGENTA%^r%^ORANGE%^, and %^BOLD%^%^BLACK%^black %^WHITE%^o%^MAGENTA%^p%^WHITE%^als%^RESET%^%^ORANGE%^ lines this twisting pathway to an unknown %^CYAN%^destination%^ORANGE%^.%^RESET%^
",
           ({"forest","trees"}) : "%^BOLD%^%^GREEN%^A dense %^BLACK%^dark%^GREEN%^ forest surrounds the area youre currently standing in. The trees %^RESET%^twist%^BOLD%^%^GREEN%^ and %^RESET%^%^GREEN%^snake%^BOLD%^%^GREEN%^ their way towards the %^BLUE%^sky%^GREEN%^ swaying gently in an unfelt, but %^RESET%^bone %^BOLD%^%^CYAN%^chilling br%^WHITE%^ee%^CYAN%^z%^WHITE%^e%^GREEN%^. %^RESET%^%^GREEN%^Vines%^BOLD%^%^GREEN%^ from the forest creep towards the pathway, but never seem to reach it. Various %^BLACK%^black%^GREEN%^, %^RESET%^%^MAGENTA%^violet%^BOLD%^%^GREEN%^ and %^BOLD%^%^WHITE%^silver %^BLACK%^fl%^RESET%^%^MAGENTA%^o%^BOLD%^%^BLACK%^w%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^rs%^GREEN%^ chaotically spread though the %^RESET%^%^GREEN%^vegetation%^BOLD%^%^GREEN%^.%^RESET%^
",
	({"wall"}) : "%^RESET%^%^RED%^A wall of thick, oppressive %^BOLD%^%^BLACK%^bl%^RESET%^ac%^BOLD%^%^BLACK%^k g%^RESET%^ra%^BOLD%^%^BLACK%^ni%^RESET%^te%^RED%^ runs along each side of the pathway. It appears to be ten feet or higher with thick chunks, chips, and scraps missing from its exterior and doesnt appear to be maintained for %^BOLD%^%^WHITE%^centuries%^RESET%^%^RED%^.%^RESET%^
",
	({"gargoyles"}) : %^BOLD%^%^BLACK%^A black stone g%^RED%^a%^BLACK%^rg%^RED%^o%^BLACK%^yl%^RED%^e%^BLACK%^ is perched every few feet along the wall. Its %^RESET%^%^MAGENTA%^purple %^MAGENTA%^j%^BOLD%^%^MAGENTA%^a%^RESET%^%^MAGENTA%^sp%^BOLD%^%^MAGENTA%^e%^RESET%^%^MAGENTA%^r%^BOLD%^%^%^BLACK%^ eyes %^RED%^glow%^BLACK%^ a %^RESET%^soft %^MAGENTA%^violet%^BOLD%^%^BLACK%^ enhancing the look of sheer %^GREEN%^m%^RESET%^%^GREEN%^a%^BOLD%^%^GREEN%^l%^RESET%^%^GREEN%^i%^BOLD%^%^GREEN%^c%^RESET%^%^GREEN%^e%^BOLD%^%^BLACK%^ upon its face. %^RESET%^",

	({"undead creatures","creatures"}) : %^BOLD%^%^BLACK%^Black %^WHITE%^o%^MAGENTA%^p%^WHITE%^al%^RESET%^%^MAGENTA%^ n%^BOLD%^%^BLACK%^i%^RESET%^%^MAGENTA%^ght%^BOLD%^%^BLACK%^m%^RESET%^%^MAGENTA%^are%^BOLD%^%^BLACK%^s%^RESET%^%^MAGENTA%^ rise on their hind legs every few feet with some cry%^BOLD%^%^MAGENTA%^s%^RESET%^%^MAGENTA%^tal%^BOLD%^%^MAGENTA%^l%^RESET%^%^MAGENTA%^ize%^BOLD%^%^MAGENTA%^d %^RESET%^%^RED%^red substance %^MAGENTA%^colorizing their %^RESET%^hooves%^MAGENTA%^ and %^GREEN%^nostrils%^MAGENTA%^ ,giving the %^BOLD%^%^WHITE%^i%^CYAN%^l%^WHITE%^lus%^CYAN%^i%^WHITE%^on%^RESET%^%^MAGENTA%^ of %^RED%^b%^RESET%^u%^RED%^rn%^RESET%^i%^RED%^ng %^BOLD%^%^RED%^fl%^YELLOW%^a%^RED%^mes%^RESET%^%^MAGENTA%^ carved into its detailed features. %^RESET%^",
({"dark pedestal","pedestal"}) : "%^RESET%^%^RED%^A %^BOLD%^%^BLACK%^black %^WHITE%^o%^MAGENTA%^p%^WHITE%^al%^RESET%^%^RED%^ pedestal rises from the direct center of the chamber. A %^RESET%^skeletal%^RED%^ hand holding a %^RESET%^dull%^RED%^,%^BOLD%^%^WHITE%^s%^CYAN%^i%^WHITE%^l%^CYAN%^v%^WHITE%^er%^RESET%^%^RED%^ bowl is attached to the pedestal. %^RESET%^",

           ({"   ", "  " }) : "    ",
        ]));
// For exits, just give us the directions (which can be enter, down, living
room, or whatever as well as north/south type directions.  Also put the
name (or short description) of the room they go to where I have filename,
we'll assign the actual filenames but that will help us keep track of how
you intend for things to connect.
        set_exits(([
           "east" : "WIZ (filename)",
        ]));
// if you want doors and there is more than one, they have to be unique, so
specify a color, wood type, or something.  Note:  all doors need an exit,
so even though you define the door here, you also have to include the exit
in set_exits above.
        set_door("","WIZ (filename)","east",0);
        set_door_description("" ", "   ");
}
- - and that's the end of what goes into the very basics of a room

--More-- (93%)
If you want a key, give us a description for the key and some idea of how
it's going to be hidden and how you'll get it, etc.  Also make sure the
room has some indication of the item it's hidden in/behind, or whatever
that can be looked at.  Generally we'll want keys to fit all doors within a
house/shop.

Traps and other special room effects as well as guards and mobs are the
most time consuming for wizzes, but also add more to what the rooms
contribute to the game.  If you want guards or it's a shop and you need
clerks, etc. we'll also appreciate descriptions for them as well as race
and alignment for starters.  How far we go after that depends on time
available and suitability/balance.
->

I need 4 of these before the entrance to the atrium!:)