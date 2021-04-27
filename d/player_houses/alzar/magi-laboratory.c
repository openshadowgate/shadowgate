#include <std.h>
inherit WIZ;

void create() {
        ::create();
        set_property("indoors",1);  // is 0 if outdoors
        set_property("light",4);    // Pretty Bright for a lab? People need to see? I dont want it hugely bright, but decent 
        set_terrain(WIZ);
        set_travel(WIZ);
        set_name(" Laboratory ");    // should be the same as the set_short but without
colors
        set_short(" %^BOLD%^%^BLACK%^L%^RESET%^%^MAGENTA%^a%^BOLD%^%^BLACK%^boratory%^RESET%^");  
        set_long%^RESET%^%^RED%^This enormous, circular chamber is enclosed by oppressive walls of %^BOLD%^%^BLACK%^bl%^RESET%^ac%^BOLD%^%^BLACK%^k g%^RESET%^ra%^BOLD%^%^BLACK%^ni%^RESET%^te%^RED%^ lined with some %^MAGENTA%^cry%^BOLD%^%^MAGENTA%^s%^RESET%^%^MAGENTA%^tal%^BOLD%^%^MAGENTA%^l%^RESET%^%^MAGENTA%^ize%^BOLD%^%^MAGENTA%^d%^RESET%^%^RED%^ substance. Across from the entrance to this room is an %^BOLD%^%^RED%^immense%^RESET%^%^RED%^ mural of a %^BOLD%^%^BLACK%^jaw%^RED%^l%^BLACK%^ess sk%^RED%^u%^BLACK%^ll%^RESET%^%^RED%^%^RESET%^%^RED%^ against a %^MAGENTA%^vi%^BOLD%^%^MAGENTA%^o%^RESET%^%^MAGENTA%^let sunburst%^RED%^. The %^BOLD%^%^BLACK%^d%^CYAN%^a%^BLACK%^rk %^RESET%^%^RED%^eye sockets of the skull seem to follow your every move leaving you with the overwhelming feelings of %^BOLD%^%^BLACK%^f%^GREEN%^e%^BLACK%^ar%^RESET%^%^RED%^ and %^BOLD%^%^WHITE%^ens%^RESET%^l%^BOLD%^%^WHITE%^avement%^RESET%^%^RED%^. Resting in the direct center of the chamber is a %^RESET%^dull, %^BOLD%^%^WHITE%^s%^CYAN%^i%^WHITE%^l%^CYAN%^v%^WHITE%^er%^RESET%^%^RED%^ bowl perched on a dark pedestal. Scattered throughout the lab are numerous %^ORANGE%^bookshelves%^RED%^ and various sized %^MAGENTA%^cages%^RED%^. A %^BOLD%^%^RED%^tang%^YELLOW%^i%^RED%^ble%^RESET%^%^RED%^ magical aura oo%^BOLD%^%^BLACK%^z%^RESET%^%^RED%^es from the chamber due in part to the pro%^BOLD%^%^MAGENTA%^f%^RESET%^%^RED%^usion of sparkling %^MAGENTA%^cry%^BOLD%^%^BLACK%^s%^RESET%^%^MAGENTA%^tals%^RED%^ and components stored on %^ORANGE%^cabinets%^RED%^ and dark %^ORANGE%^wood desks%^RED%^. The room is kept immaculately clean, perhaps to accommodate the chaotically arranged %^BOLD%^%^RED%^r%^BLUE%^u%^RED%^n%^BLUE%^e%^RED%^s%^RESET%^%^RED%^ carved into all surfaces of the chamber. %^RESET%^ ");
        set_smell("default","%^RESET%^ORANGE%^Many strange smells assault the air. %^RESET%^");
        set_listen("default","%^RESET%^%^GREEN%^The whisper of magical incantations and bubbling of potions fills the room. %^RESET%^ ");
// These are the things you can look at.  If you want more than one word or
words (oil lamp and lamp, chair and chairs) to work, all the words you want
to see the same thing go in the ({ }) like chair & chairs below.
        set_items(([
           ({"walls","granite walls"}) : "%^RED%^The walls are composed of smooth thick %^BOLD%^%^BLACK%^bl%^RESET%^ac%^BOLD%^%^BLACK%^k g%^RESET%^ra%^BOLD%^%^BLACK%^ni%^RESET%^te%^RED%^ stone with fl%^BOLD%^%^MAGENTA%^e%^RESET%^%^RED%^cks of a %^BOLD%^%^BLACK%^dark%^RESET%^%^RED%^ red crystallized substance speckled through them. %^RESET%^",
           ({"substance","crystal substance"}) : "%^RESET%^%^RED%^This %^BOLD%^%^BLACK%^dark%^RESET%^%^RED%^ red substance appears to be %^BOLD%^%^RED%^blood%^RESET%^%^RED%^, %^BOLD%^%^%^MAGENTA%^crystallized%^RESET%^%^RED%^ somehow, which %^BOLD%^%^CYAN%^gushes%^RESET%^%^RED%^ from the clear tubes built into the walls. %^RESET%^",
	
({"tube","tubes"}) : "%^BOLD%^%^WHITE%^The clear, thick tubes built inside the dark walls of this chamber seem to carry %^RED%^blood%^WHITE%^ from some unknown place. %^RESET%^",
	({"mural","sunburst",skull}) : %^RESET%^%^RED%^The mural is flawless and masterfully-crafted on the wall  where it resides. It depicts a %^BOLD%^%^BLACK%^jaw%^RED%^l%^BLACK%^ess sk%^RED%^u%^BLACK%^ll%^RESET%^%^RED%^%^RESET%^%^RED%^ resting against a large %^MAGENTA%^violet%^RED%^ sunburst. The %^BOLD%^%^BLACK%^sockets%^RESET%^%^RED%^ of the %^BOLD%^%^WHITE%^skull%^RESET%^%^RED%^ glow with %^BOLD%^%^BLACK%^ma%^WHITE%^l%^BLACK%^ice%^RESET%^%^RED%^ an involuntary %^BOLD%^%^CYAN%^shiver%^RESET%^%^RED%^ runs down your %^BOLD%^%^RED%^spine%^RESET%^%^RED%^ as you stare at the mural leaving you with the feeling of %^BOLD%^%^WHITE%^ens%^RESET%^l%^BOLD%^%^WHITE%^avement%^RESET%^%^RED%^ and %^MAGENTA%^he%^BOLD%^%^BLACK%^l%^RESET%^%^MAGENTA%^p%^BOLD%^%^BLACK%^l%^RESET%^%^MAGENTA%^essness%^RESET%^%^MAGENTA%^.%^RESET%^",

({"silver bowl","bowl"}) : %^RESET%^%^RED%^The %^RESET%^dull%^RED%^, %^BOLD%^%^WHITE%^s%^CYAN%^i%^WHITE%^l%^CYAN%^v%^WHITE%^er%^RESET%^%^RED%^ bowl seems to be resting on an outstretched %^RESET%^skeletal%^RED%^ hand which extends from the pedestal. A dried, caked on %^BOLD%^%^RED%^blood%^RESET%^%^RED%^ red substance can be found inside the bowl. %^RESET%^",
({"dark pedestal","pedestal"}) : "%^RESET%^%^RED%^A %^BOLD%^%^BLACK%^black %^WHITE%^o%^MAGENTA%^p%^WHITE%^al%^RESET%^%^RED%^ pedestal rises from the direct center of the chamber. A %^RESET%^skeletal%^RED%^ hand holding a %^RESET%^dull%^RED%^,%^BOLD%^%^WHITE%^s%^CYAN%^i%^WHITE%^l%^CYAN%^v%^WHITE%^er%^RESET%^%^RED%^ bowl is attached to the pedestal. %^RESET%^",
({"bookshelves"}) : "%^BOLD%^%^BLACK%^Dark%^RESET%^%^ORANGE%^ oak%^RED%^ bookshelves are lined against the wall with hundreds of books, notes and other reading material contained on their shelves. A %^RESET%^%^MAGENTA%^violet%^RED%^ covered book near the entrance catches your attention. %^RESET%^",

({"book"}) : "%^RESET%^%^RED%^The book doesn't have any writing on its cover and feels light, almost hollow. Perhaps you should %^BOLD%^%^WHITE%^take%^RESET%^%^RED%^ the book. %^RESET%^",
({"cages"}) : "%^RED%^These varying sized cages seem to contain many different types of creatures ranging from human %^RESET%^children%^RED%^ to elementals of %^BOLD%^%^RED%^f%^YELLOW%^i%^RED%^re%^RESET%^%^RED%^.%^RESET%^ ",
({"runes"}) : "%^RESET%^%^MAGENTA%^M%^BOLD%^%^BLACK%^y%^RESET%^%^MAGENTA%^st%^BOLD%^%^BLACK%^i%^RESET%^%^MAGENTA%^cal %^BOLD%^%^CYAN%^runes%^RESET%^%^MAGENTA%^ are carved into the chamber walls. The %^BOLD%^%^CYAN%^runes %^YELLOW%^glow%^RESET%^%^MAGENTA%^ slightly as the crystallized %^BOLD%^%^RED%^blood%^RESET%^%^MAGENTA%^ passes by and you can only wonder at their use for this otherwise smooth and polished room. %^RESET%^",

({"crystals","components"}) : "%^RED%^Along the desks and on the cabinets are %^BOLD%^%^CYAN%^crystals%^RESET%^%^RED%^ and %^BOLD%^%^MAGENTA%^gems%^RESET%^%^RED%^ of various sizes, ranging in size from small %^BOLD%^%^WHITE%^pe%^MAGENTA%^a%^WHITE%^rls%^RESET%^%^RED%^ to massive r%^BOLD%^%^RED%^u%^RESET%^%^RED%^bies. Also strewn around the storage areas are pouches filled with %^BOLD%^%^WHITE%^silver%^RESET%^%^RED%^, miscellaneous %^BOLD%^%^BLACK%^rods%^RESET%^%^RED%^ and %^RESET%^spell books%^RED%^.%^RESET%^",
({"cabinets","desk"}) : "%^RED%^Along the desks and on the cabinets are %^BOLD%^%^CYAN%^crystals%^RESET%^%^RED%^ and %^BOLD%^%^MAGENTA%^gems%^RESET%^%^RED%^ of various sizes, ranging in size from small %^BOLD%^%^WHITE%^pe%^MAGENTA%^a%^WHITE%^rls%^RESET%^%^RED%^ to massive r%^BOLD%^%^RED%^u%^RESET%^%^RED%^bies. Also strewn around the storage areas are pouches filled with %^BOLD%^%^WHITE%^silver%^RESET%^%^RED%^, miscellaneous %^BOLD%^%^BLACK%^rods%^RESET%^%^RED%^ and %^RESET%^spell books%^RED%^.%^RESET%^",

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
        set_door("Black Granite Door","WIZ (filename)","east",0);
        set_door_description(""%^RESET%^%^RED%^A thick slab of %^BOLD%^%^YELLOW%^j%^RESET%^a%^BOLD%^%^BLACK%^g%^RESET%^ge%^BOLD%^%^RED%^d%^RESET%^ %^BOLD%^%^BLACK%^bl%^RESET%^ac%^BOLD%^%^BLACK%^k g%^RESET%^ra%^BOLD%^%^BLACK%^ni%^RESET%^te%^RED%^ serves as the entrance for this otherwise smooth and polished room. %^RESET%^
", "   ");
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
Echo for when they take the book! 
%^RESET%^%^RED%^You attempt to take the book from the shelf a soft %^BOLD%^%^WHITE%^click%^RESET%^%^RED%^ can be heard. Moments later a %^BOLD%^%^BLACK%^gushing%^RESET%^%^RED%^ sound can be heard and a %^BOLD%^%^RED%^blood%^RESET%^%^RED%^ red substances begins to %^BOLD%^GREEN%^ooze%^RESET%^%^RED%^ out from the pedestal and fills the %^RESET%^dull%^RESET%^%^RED%^,%^BOLD%^%^WHITE%^s%^CYAN%^i%^WHITE%^l%^CYAN%^v%^WHITE%^er%^RESET%^%^RED%^ bowl. %^RESET%^

Echos
%^RESET%^%^RED%^The smell of %^ORANGE%^sulfur%^RESET%^%^RED%^ and %^BOLD%^%^BLACK%^burnt%^RESET%^%^RED%^ flesh waft through the air. %^RESET%^
%^RESET%^%^RED%^You hear loud sc%^BOLD%^%^RED%^r%^RESET%^%^RED%^ea%^BOLD%^%^RED%^m%^RESET%^%^RED%^s and the %^BOLD%^%^BLACK%^ratt%^WHITE%^l%^BLACK%^ing%^RESET%^RED%^ of cages. %^RESET%^
%^BOLD%^%^BLACK%^The dark eye sockets %^RED%^b%^RESET%^%^RED%^l%^BOLD%^%^RED%^az%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^ with a %^RESET%^%^MAGENTA%^v%^BOLD%^%^WHITE%^i%^RESET%^%^MAGENTA%^ol%^BOLD%^%^WHITE%^e%^RESET%^MAGENTA%^t%^ f%^BOLD%^%^MAGENTA%^l%^WHITE%^a%^MAGENTA%^m%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^ sending a %^CYAN%^chill%^BLACK%^ down your %^WHITE%^spine%^RESET%^.%^RESET%^
%^BOLD%^%^WHITE%^A %^BLACK%^hooded%^WHITE%^ figure with %^GREEN%^m%^RESET%^GREEN%^a%^BOLD%^%^GREEN%^liciou%^RESET%^%^GREEN%^s%^BOLD%^%^WHITE%^, %^RED%^bl%^WHITE%^oo%^RED%^dshot%^WHITE%^ eyes %^RESET%^%^ORANGE%^sweeps%^BOLD%^%^WHITE%^ the chamber. %^RESET%^


Octothorpe could we have a random search for psion/magi components or scrolls, gems? Would be an interesting addition for someone who wanted to RP stealing from the temple! Also dont forget to make the bowl able to be used by psions or magi!)

The bowl should BE AN ACTIVATE SCRYING DEVICE FOR PSIONS AND MAGI! However! It cant be used without pulling the book!