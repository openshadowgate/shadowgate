#include <std.h>
inherit WIZ;

void create() {
        ::create();
        set_property("indoors",1);  // is 0 if outdoors
        set_property("light",2);    // 2 is pretty much average lighting
        set_terrain(WIZ);
        set_travel(WIZ);
        set_name(" Atrium  ");    // should be the same as the set_short but without

        set_short(" %^BOLD%^%^BLACK%^A%^RESET%^%^MAGENTA%^t%^BOLD%^%^BLACK%^rium%^RESET%^%^ ");
        set_long("%^RESET%^%^RED%^A grand rectangular chamber opens up as the enormous double doors behind slam shut. A feeling of %^BOLD%^%^BLACK%^wr%^GREEN%^o%^BLACK%^ngn%^GREEN%^e%^BLACK%^ss%^RESET%^%^RED%^ fills the %^BOLD%^%^BLACK%^d%^BLUE%^a%^BLACK%^rk%^RESET%^%^RED%^, %^RESET%^bone-%^BOLD%^%^WHITE%^ch%^CYAN%^i%^WHITE%^ll%^CYAN%^i%^WHITE%^ng%^RESET%^%^RED%^ room. A %^BOLD%^%^BLACK%^f%^MAGENTA%^o%^BLACK%^nt%^RESET%^%^RED%^ lies directly in front of the entryway, surrounded by %^BOLD%^%^BLACK%^bl%^RESET%^a%^BOLD%^%^BLACK%^ck%^RESET%^e%^BOLD%^%^BLACK%^ned%^RESET%^%^RED%^ and shriveled fl%^MAGENTA%^o%^RED%^wer %^BOLD%^%^MAGENTA%^petals%^RESET%^%^RED%^. Jagged tiles %^BOLD%^%^BLACK%^m%^YELLOW%^o%^BLACK%^an%^RESET%^%^RED%^ as if in %^BOLD%^%^BLACK%^ag%^RESET%^o%^BOLD%^%^BLACK%^ny%^RESET%^%^RED%^ as the shriveled flower petals create serval paths leading further inward. Black and silver candles in the alcoves flicker in an %^BOLD%^%^GREEN%^eerie%^RESET%^%^RED%^ and %^CYAN%^unfelt wind%^RED%^ as they cast the %^BOLD%^%^BLACK%^sh%^BLUE%^a%^BLACK%^dows%^RESET%^%^RED%^ slightly aside with a %^RESET%^%^MAGENTA%^v%^BOLD%^%^MAGENTA%^io%^WHITE%^l%^MAGENTA%^e%^RESET%^%^MAGENTA%^t %^RESET%^%^RED%^hue. %^BOLD%^%^BLACK%^Chaotic%^RESET%^%^RED%^ and %^GREEN%^distorted %^BOLD%^%^WHITE%^m%^RESET%^oo%^BOLD%^%^WHITE%^nbeams%^RESET%^%^RED%^ pour into the room from an opening in the ceiling, lighting the view of a small altar, which rests in the direct center of the room. Exotic %^BOLD%^%^GREEN%^v%^RESET%^%^GREEN%^i%^BOLD%^%^GREEN%^nes%^RESET%^%^RED%^ weave their way out from the altar enveloping five %^BOLD%^%^WHITE%^st%^MAGENTA%^a%^WHITE%^tu%^MAGENTA%^e%^WHITE%^s%^RESET%^%^RED%^ in a strangle-like hold. The vines twist through the chamber, burying themselves into the oppressive and opaque black granite walls on which impressive %^BOLD%^%^CYAN%^m%^RESET%^%^CYAN%^u%^BOLD%^%^CYAN%^ra%^RESET%^%^CYAN%^l%^BOLD%^%^CYAN%^s%^RESET%^%^RED%^ are painted. %^RESET%^
  ");
        set_smell("default","  %^RESET%^%^ORANGE%^Burning candle wax permeates the air.%^RESET%^ ");
        set_listen("default","%^RESET%^%^GREEN%^An %^BOLD%^%^BLACK%^unnatural%^RESET%^%^GREEN%^ silence covers the area.    ");
// These are the things you can look at.  If you want more than one word or
words (oil lamp and lamp, chair and chairs) to work, all the words you want
to see the same thing go in the ({ }) like chair & chairs below.
        set_items(([
           ({"font"}) : "%^RESET%^%^RED%^A small %^BOLD%^%^BLACK%^black %^WHITE%^op%^MAGENTA%^a%^WHITE%^l%^RESET%^%^RED%^ encrusted font with various images of nightmares, undead and hawks encircling it, contains a black watery substance. %^RESET%^
.",
           ({"petals","tiles"}) : "%^RESET%^%^RED%^Haphazardly spread about the floor creating paths on the jagged, uneven %^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^%^WHITE%^l%^RESET%^v%^BOLD%^%^WHITE%^er%^RESET%^%^RED%^ tiles are dead, shriveled %^BOLD%^%^BLACK%^black %^RESET%^%^RED%^r%^MAGENTA%^o%^RED%^se petals. They appear a bit unusual compared to normal black rose petals as %^BOLD%^%^RED%^veins%^RESET%^%^RED%^ of a blood red substance streaks through the leaves. %^RESET%^
.",
           ({"alcoves","candles", shadows}) : "%^RESET%^%^RED%^Varying sized candles are scattered about the chamber ranging in color from %^BOLD%^%^BLACK%^b%^RESET%^%^MAGENTA%^l%^BOLD%^%^BLACK%^ack%^RESET%^%^MAGENTA%^i%^BOLD%^%^BLACK%^sh-purple%^RESET%^%^RED%^ and %^BOLD%^%^WHITE%^s%^CYAN%^i%^WHITE%^l%^CYAN%^v%^WHITE%^ery-white%^RESET%^%^RED%^, their flames flickering with a %^RESET%^%^MAGENTA%^v%^BOLD%^%^MAGENTA%^io%^WHITE%^l%^MAGENTA%^e%^RESET%^%^MAGENTA%^t%^RED%^ hue that distorts the %^BOLD%^%^BLACK%^sh%^BLUE%^a%^BLACK%^dows%^RESET%^%^RED%^ or perhaps illusions that look like they might flay one %^BOLD%^%^RED%^alive%^RESET%^%^RED%^.%^RESET%^
.",
           ({"moonbeams","ceiling" , altar}) : "%^RESET%^%^RED%^Silver rays of %^BOLD%^%^YELLOW%^l%^WHITE%^i%^YELLOW%^ght%^RESET%^%^RED%^ flow into the chamber from an opening within the ceiling. The beams are chaotic and jagged in appearance as they illuminate a small purple-tinged black altar composed out of %^MAGENTA%^purple %^MAGENTA%^j%^BOLD%^%^MAGENTA%^a%^RESET%^%^MAGENTA%^sp%^BOLD%^%^MAGENTA%^e%^RESET%^%^MAGENTA%^r%^RED%^ and %^BOLD%^%^BLACK%^ch%^RESET%^a%^BOLD%^%^BLACK%^rr%^RESET%^e%^BOLD%^%^BLACK%^d b%^RESET%^o%^BOLD%^%^BLACK%^ne%^RESET%^%^RED%^.%^RESET%^
",
           ({"vines","vine"}) : "%^RESET%^%^RED%^Hundreds, maybe thousands, of small %^MAGENTA%^purplish-%^BOLD%^%^BLACK%^black %^RESET%^%^GREEN%^v%^BOLD%^%^GREEN%^i%^RESET%^%^GREEN%^nes%^RESET%^%^RED%^ with %^BOLD%^%^BLACK%^r%^RED%^a%^BLACK%^z%^RESET%^o%^BOLD%^%^BLACK%^r-sharp%^RESET%^%^RED%^ thorns entwine themselves throughout the room. There seems to be little %^CYAN%^rhyme%^RED%^ or %^BOLD%^%^CYAN%^rhythm%^RESET%^%^RED%^ to their weaving as they streak out from the altar and into walls, floor, even going as far as to climb through the opening in the ceiling. %^RESET%^
",
           ({"mural,"walls"}) : "%^RESET%^%^RED%^Immense, intricate images cover each wall of this chamber. Each wall seems to represent a different theme or scene. The west wall is covered in what appears to be distorted holy symbols of the %^BOLD%^%^WHITE%^false%^RESET%^%^RED%^, while the northern wall depicts hordes of %^BOLD%^RED%^undead%^RESET%^%^RED%^ or %^BOLD%^%^BLUE%^assassins%^RESET%^%^RED%^ causing massive %^BOLD%^%^WHITE%^strife%^RESET%^%^RED%^ to countless cities. Images on the eastern wall depict conversion or corruption of the false along with the %^BOLD%^%^WHITE%^innocents%^RESET%^%^RED%^ within the realm. The last group of images might be the most important as glowing holy symbols of a %^BOLD%^%^BLACK%^jaw%^RED%^l%^BLACK%^ess sk%^RED%^u%^BLACK%^ll%^RESET%^%^RED%^  made out of silver seem to dance with all of the conceptual ideas at once in a chaotic display of %^RESET%^%^MAGENTA%^p%^BOLD%^%^BLACK%^o%^RESET%^%^MAGENTA%^werl%^BOLD%^%^BLACK%^e%^RESET%^%^MAGENTA%^ssn%^BOLD%^%^BLACK%^e%^RESET%^%^MAGENTA%^ss%^RED%^.%^RESET%^
",
           ({"statues"}) : %^RESET%^%^RED%^Five %^MAGENTA%^sh%^BOLD%^%^MAGENTA%^i%^RESET%^%^MAGENTA%^mmer%^BOLD%^%^MAGENTA%^i%^RESET%^%^MAGENTA%^ng %^BOLD%^%^BLUE%^e%^BOLD%^%^CYAN%^t%^BOLD%^%^BLUE%^hereal %^WHITE%^st%^MAGENTA%^a%^WHITE%^t%^MAGENTA%^u%^WHITE%^es%^RESET%^%^RED%^ surround the small altar in what appears to be an attack formation. This seems to be an odd mixing of powerful presences emanating from the scene itself. An older man with a long %^BOLD%^%^WHITE%^white%^RESET%^%^RED%^ beard is struggling against the %^GREEN%^v%^BOLD%^%^GREEN%^i%^RESET%^%^GREEN%^nes%^RED%^ wrapped about his left wrist, while a %^CYAN%^beautiful%^RED%^ young elven woman is attempting to aid him. At the same time she seems to struggle to see as %^BOLD%^%^RED%^bloody%^RESET%^%^RED%^ t%^CYAN%^e%^RED%^ars streak down her face, pouring into a %^RESET%^tarnished %^BOLD%^%^WHITE%^silver goblet%^RESET%^%^RED%^ wrapped in her hand by the %^GREEN%^v%^BOLD%^%^GREEN%^i%^RESET%^%^GREEN%^nes%^RED%^. To the left of the altar is a man rushing to a woman on the ground strangled to %^BOLD%^%^BLACK%^d%^RED%^e%^BLACK%^ath%^RESET%^%^RED%^ by %^GREEN%^v%^BOLD%^%^GREEN%^i%^RESET%^%^GREEN%^nes%^RED%^ with seven %^BOLD%^%^CYAN%^st%^RESET%^%^CYAN%^a%^BOLD%^%^CYAN%^rs%^RESET%^%^RED%^ embedded into her chest. As the man rushes toward her, his face cloaked by a %^RESET%^silver death mask%^RED%^, the %^BOLD%^%^WHITE%^silver%^RESET%^%^RED%^ and %^BOLD%^%^YELLOW%^gold%^RESET%^%^RED%^ scales carried in one of his skeletal hands dips dramatically towards the altar. Lastly, a %^BOLD%^%^BLACK%^sh%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^dowy-presence%^RESET%^%^RED%^ appears in front of the altar seemingly not concerned with the others. The shadowy-figure raises a %^BOLD%^%^BLACK%^g%^GREEN%^a%^BLACK%^untl%^GREEN%^e%^BLACK%^ted%^RESET%^%^RED%^ hand in what appears to be a blow intent on crushing the altar, before the figure can strike %^GREEN%^v%^BOLD%^%^GREEN%^i%^RESET%^%^GREEN%^nes%^RED%^ wrapped themselves about the mans hand and begin to crush. %^RESET%^
",








  "stove" : "It looks like a stove.",
           ({"   ", "  " }) : "    ",
        ]));
// For exits, just give us the directions (which can be enter, down, living
room, or whatever as well as north/south type directions.  Also put the
name (or short description) of the room they go to where I have filename,
we'll assign the actual filenames but that will help us keep track of how
you intend for things to connect.
        set_exits(([
           "south" : "WIZ (filename)",
        ]));
// if you want doors and there is more than one, they have to be unique, so
specify a color, wood type, or something.  Note:  all doors need an exit,
so even though you define the door here, you also have to include the exit
in set_exits above.
        set_door("","WIZ (filename)","",0);
        set_door_description("Double Doors", "%^BOLD%^%^BLACK%^Two massive granite doors %^BOLD%^%^WHITE%^fl%^BLACK%^i%^WHITE%^c%^BLACK%^k%^WHITE%^er%^BLACK%^ in the candle light.   ");
} There should be no direction. All they have to do is walk SOUTH!
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

Echo to Non-Cyricist or Faithless Player- Your breath becomes ragged and blistering welts begin to appear all over your body. As you struggle to fight off this invisible attacker, you hear the whispers of thousands of voices all at once. You fear that the words will forever leave a scar on your mind, You cant travel here without being tainted by the One True Way.

%^RESET%^%^RED%^Your breath becomes ra%^MAGENTA%^gg%^RED%^ed and %^BOLD%^%^RED%^blistering w%^RESET%^%^RED%^e%^BOLD%^%^RED%^lts%^RESET%^%^RED%^ begin to appear all over your body. As you struggle to fight off this invisible attacker, you hear the whispers of thousands of voices all at once. You %^BOLD%^%^BLACK%^f%^GREEN%^e%^BLACK%^ar%^RESET%^%^RED%^ that the words will forever leave a %^BOLD%^%^RED%^scar%^RESET%^%^RED%^ on your mind, %^BOLD%^%^WHITE%^"You can't travel here without being tainted by the One True Way".%^RESET%^%^RED%^.%^RESET%^
