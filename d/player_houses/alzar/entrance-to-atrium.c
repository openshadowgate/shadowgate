#include <std.h>
inherit WIZ;

void create() {
        ::create();
        set_property("outdoors",0);  // is 0 if outdoors WANT IT DARK and outdoors!
        set_property("light",4);    //        set_terrain(WIZ);
        set_travel(WIZ);
        set_name(" Entrance to the Atrium ");    // should be the same as the set_short but without
colors
        set_short(" %^RESET%^%^RED%^Entrance to the %^BOLD%^%^BLACK%^A%^RESET%^%^MAGENTA%^t%^BOLD%^%^BLACK%^rium%^RESET%^");  
        set_long(%^GREEN%^The dense, %^BOLD%^%^BLUE%^dark%^RESET%^%^GREEN%^ forest opens up to some sort of %^BOLD%^%^WHITE%^complex%^RESET%^%^GREEN%^ surrounded by the deteriorated %^BOLD%^%^BLACK%^bl%^RESET%^ac%^BOLD%^%^BLACK%^k g%^RESET%^ra%^BOLD%^%^BLACK%^ni%^RESET%^te%^GREEN%^ wall, trimmed with %^BOLD%^%^GREEN%^hedges%^RESET%^%^GREEN%^ visible through a %^RESET%^steel gate%^GREEN%^. The %^RESET%^%^ORANGE%^cobblestone%^GREEN%^ path continues through the archway, %^RESET%^%^MAGENTA%^ornamented%^GREEN%^ with a %^BOLD%^%^BLACK%^jaw%^RED%^l%^BLACK%^ess sk%^RED%^u%^BLACK%^ll%^RESET%^%^GREEN%^ and two %^RESET%^tarnished %^BOLD%^%^WHITE%^s%^CYAN%^i%^WHITE%^lv%^CYAN%^e%^WHITE%^r %^BOLD%^%^BLACK%^n%^RED%^i%^BLACK%^ght%^RED%^m%^BLACK%^are%^RESET%^%^GREEN%^ statues on either side. A %^BOLD%^%^YELLOW%^s%^GREEN%^i%^YELLOW%^ck%^GREEN%^e%^YELLOW%^ni%^GREEN%^n%^YELLOW%^g%^RESET%^%^GREEN%^ feeling pulls at your %^BOLD%^%^GREEN%^stomach%^RESET%^%^GREEN%^ as you peer through the entry way realizing there are %^ORANGE%^bu%^BOLD%^%^BLACK%^r%^RESET%^%^ORANGE%^nt %^BOLD%^%^BLACK%^corpses%^RESET%^%^GREEN%^ and a few piles of %^RESET%^ash%^RESET%^%^GREEN%^ lying just beyond the gate. %^RESET%^
");
        set_smell("default","%^RESET%^ORANGE%^You smell %^RED%^e%^MAGENTA%^x%^RED%^otic%^ORANGE%^ plant life with an underlying smell of %^RED%^blood%^ORANGE%^. %^RESET%^   ");
        set_listen("default","%^RESET%^%^GREEN%^An unknown creature %^BOLD%^%^WHITE%^howls%^RESET%^%^GREEN%^ in the distance. %^RESET%^");
// These are the things you can look at.  If you want more than one word or
words (oil lamp and lamp, chair and chairs) to work, all the words you want
to see the same thing go in the ({ }) like chair & chairs below.
        set_items(([
           ({"corpses","ashes"}) : "%^RED%^The walls are composed of smooth thick %^BOLD%^%^BLACK%^bl%^RESET%^ac%^BOLD%^%^BLACK%^k g%^RESET%^ra%^BOLD%^%^BLACK%^ni%^RESET%^te%^RED%^ stone with fl%^BOLD%^%^MAGENTA%^e%^RESET%^%^RED%^cks of a %^BOLD%^%^BLACK%^dark%^RESET%^%^RED%^ red crystallized substance speckled through them
. %^RESET%^",
           ({"forest","trees"}) : "%^BOLD%^%^GREEN%^A dense %^BLACK%^dark%^GREEN%^ forest surrounds the area youre currently standing in. The trees %^RESET%^twist%^BOLD%^%^GREEN%^ and %^RESET%^%^GREEN%^snake%^BOLD%^%^GREEN%^ their way towards the %^BLUE%^sky%^GREEN%^ swaying gently in an unfelt, but %^RESET%^bone %^BOLD%^%^CYAN%^chilling br%^WHITE%^ee%^CYAN%^z%^WHITE%^e%^GREEN%^. %^RESET%^%^GREEN%^Vines%^BOLD%^%^GREEN%^ from the forest creep towards the pathway, but never seem to reach it. Various %^BLACK%^black%^GREEN%^, %^RESET%^%^MAGENTA%^violet%^BOLD%^%^GREEN%^ and %^BOLD%^%^WHITE%^silver %^BLACK%^fl%^RESET%^%^MAGENTA%^o%^BOLD%^%^BLACK%^w%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^rs%^GREEN%^ chaotically spread though the %^RESET%^%^GREEN%^vegetation%^BOLD%^%^GREEN%^.%^RESET%^",
	

	({"wall") : %^RESET%^%^RED%^A wall of thick, oppressive %^BOLD%^%^BLACK%^bl%^RESET%^ac%^BOLD%^%^BLACK%^k g%^RESET%^ra%^BOLD%^%^BLACK%^ni%^RESET%^te%^RED%^ runs along each side of the pathway. It appears to be ten feet or higher with thick chunks, chips, and scraps missing from its exterior and doesnt appear to be maintained for %^BOLD%^%^WHITE%^centuries%^RESET%^%^RED%^.%^RESET%^",

({"hedges"}) : "%^BOLD%^%^BLACK%^Ch%^CYAN%^a%^BLACK%^otically trimmed %^RESET%^%^GREEN%^hedges%^BOLD%^%^BLACK%^ of vi%^RESET%^%^MAGENTA%^o%^BOLD%^%^BLACK%^let, bla%^BOLD%^%^BLUE%^c%^BLACK%^k, and gr%^GREEN%^e%^BLACK%^en can be seen through the steel gate. They appear to be arranged in such a way that if one could appear down on them from the %^BLUE%^sky%^BLACK%^ they would represent something, but what?%^RESET%^",

({"skull"}) : "%^RESET%^%^RED%^A %^BOLD%^%^BLACK%^jaw%^RED%^l%^BLACK%^ess sk%^RED%^u%^BLACK%^ll%^RESET%^%^RED%^ with soft %^RESET%^%^CYAN%^glowing%^RED%^ vi%^MAGENTA%^o%^RED%^let%^RED%^ eyes rests on the archway above the steel gate. Its %^BOLD%^%^MAGENTA%^gaze%^RESET%^%^RED%^ seems to peer into your very %^BOLD%^%^CYAN%^soul%^RESET%^%^RED%^ and a feeling of complete %^BOLD%^%^BLACK%^dread%^RESET%^%^RED%^ flows through your body. %^RESET%^",
({"nightmares"}) : "%^BOLD%^%^BLACK%^Two tarnished silver n%^RED%^i%^BLACK%^ght%^RED%^m%^BLACK%^are statues reside on each side of the gate. The %^BOLD%^%^BLACK%^n%^RED%^i%^BLACK%^ght%^RED%^m%^BLACK%^ares appear to move and pawn at the ground as you grow closer to the gate, but that could be an %^WHITE%^i%^CYAN%^l%^WHITE%^lus%^CYAN%^i%^WHITE%^on%^BOLD%^%^BLACK%^ of the %^BOLD%^%^BLUE%^eye%^BOLD%^%^BLACK%^.%^RESET%^",
({"gate","steel gate"}) : "%^RESET%^A %^ORANGE%^r%^RED%^u%^ORANGE%^s%^RED%^t%^ORANGE%^y%^RESET%^ steel %^BOLD%^%^BLACK%^gate%^RESET%^ with a thick, tarnished chain and a sturdy iron padlock wrapped about it prevents your %^BOLD%^%^RED%^entry%^RESET%^ beyond this place. %^RESET%^",

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
        set_door_description(   ");
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

No exit north but one can still walk there as the gate is an illusion. I would like two echoes one if the person is a Cyricist and one if they arent.

Cyricist Echo%^BOLD%^%^BLACK%^ A %^RED%^m%^WHITE%^u%^RED%^r%^WHITE%^d%^RED%^e%^WHITE%^r%^RED%^o%^WHITE%^u%^RED%^s%^BLACK%^ rage %^GREEN%^s%^RESET%^%^GREEN%^ee%^BOLD%^%^GREEN%^ps%^BLACK%^ into your %^RESET%^%^RED%^ve%^BOLD%^%^RED%^i%^RESET%^%^RED%^ns%^BOLD%^%^BLACK%^ as you pass underneath the skull's %^MAGENTA%^gaze%^BLACK%^. You know that %^WHITE%^Lord Cyric%^BLACK%^ is watching and you will forever be his %^WHITE%^slave%^BLACK%^.%^RESET%^)

False Echo- %^RESET%^%^MAGENTA%^The skull's eyes glow%^RESET%^%^MAGENTA%^ a %^BOLD%^%^BLACK%^dark vi%^RESET%^%^MAGENTA%^o%^BOLD%^%^BLACK%^let%^RESET%^%^MAGENTA%^.  Your very %^BOLD%^%^CYAN%^soul%^RESET%^%^MAGENTA%^ feels on f%^BOLD%^%^WHITE%^i%^MAGENTA%^r%^RESET%^%^MAGENTA%^e%^.%^RESET%^

Roll verus will if fail take minor amounts of damage nothing over forty and arent able to pass through?

If succeed they are able to pass through and get the following message

%^BOLD%^%^WHITE%^You arrive at an %^RESET%^%^MAGENTA%^atrium%^BOLD%^%^WHITE%^. What could be its purpose? %^RESET%^