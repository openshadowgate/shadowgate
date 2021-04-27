#include <std.h>
#include "../defs.h"
inherit VAULT;
 
void create() {
        ::create();
        set_property("indoors",1);
        set_property("light",2);
        set_terrain("barren");
        set_travel("paved road");
        set_name("Dithas Greets You");
        set_short("%^BOLD%^%^BLACK%^Elder Dithas %^RED%^Greets %^GREEN%^You");
        set_long(" %^RESET%^%^BLUE%^As you enter this room your entire body fills with loss.  You want to just lay down "
"and cry right where you stand.  In every direction you look there is just vast empty dark space defined by nothing. The "
"one exception is an barely glowing white stone path that stretches out to the north.  At the end of the barely "
"discernable path in the vast darkness stands an old man.\n");
        set_smell("default","%^RESET%^%^GREEN%^...strange there is NOTHING to smell, not even yourself.");
        set_listen("default","%^BOLD%^%^BLACK%^An old man's voice chuckling to himself.");
        set_items(([
           ({"path","stone path"}) : "%^RESET%^%^ORANGE%^This barely discernable bath heads right too and old man not far "
"from where you stand..",
           ({"man", "old man","Man","Old Man"}) : "%^RESET%^%^GREEN%^This man %^MAGENTA%^appears %^GREEN%^as a well "
"dressed %^ORANGE%^noble %^GREEN%^though few walking around are this %^BOLD%^%^BLACK%^old%^GREEN%^. He wears crisp "
"%^YELLOW%^new %^RESET%^%^GREEN%^clothing. His skin hangs loose on his poorly fed arms.%^BOLD%^%^BLUE%^ veins%^RESET%^"
"%^GREEN%^ are evident everywhere you can see his actual body. His%^BOLD%^%^WHITE%^ s%^RESET%^h%^BOLD%^i%^RESET%^n%^BOLD%^"
"y white %^RESET%^%^MAGENTA%^ eyes%^GREEN%^ stare out of sunken sockets that have %^BOLD%^%^BLACK%^dark discoloration "
"%^RESET%^%^GREEN%^around the lid and under eye. His %^BOLD%^%^WHITE%^white bushy eye-brows%^RESET%^%^GREEN%^ sometimes "
"run into his eyes they are so long. His long, straight %^BOLD%^%^WHITE%^white hair %^RESET%^%^GREEN%^cascades down his "
"back. His hands if revealed are different one from the other. His right hand has %^BOLD%^%^BLACK%^dark %^YELLOW%^yellow "
"%^WHITE%^fingernails%^RESET%^%^GREEN%^, that though are kept fairly neat but still seem... %^BOLD%^%^BLACK%^u%^GREEN%^n"
"%^BLACK%^n%^GREEN%^a%^BLACK%^t%^GREEN%^u%^BLACK%^r%^GREEN%^a%^BLACK%^l%^GREEN%^.%^BLUE%^ The %^RESET%^%^RED%^left%^BOLD%^"
"%^BLUE%^ however is far stranger. It is %^BLACK%^b%^RESET%^%^RED%^u%^BOLD%^%^BLACK%^r%^RESET%^%^RED%^n%^BOLD%^%^BLACK%^t "
"and curled up as if flexing it was out of the question%^RESET%^%^RED%^ (%^BLUE%^does %^BOLD%^%^GREEN%^i%^RESET%^%^GREEN%^"
"t %^BOLD%^%^GREEN%^g%^BLACK%^l%^GREEN%^o%^BLACK%^w%^RESET%^%^BLUE%^ slightly%^RED%^)%^GREEN%^. He has no real beard to "
"speak of but where one might grow is some kind of gray-white scruff similar in consistency to a boy of 13 trying to "
"achieve facial hair for the first time. A few pouches that have the scent of %^ORANGE%^herbs%^RESET%^%^GREEN%^ hang from "
"his belt.  He does not look long for this world.  You might think one good fall down some stairs would be the end of his "
"mortal trek.  %^BOLD%^%^CYAN%^You have the impression by the way he looks at you that he wants to give you a %^RESET%^"
"%^RED%^kiss%^BOLD%^%^CYAN%^.%^RESET%^",
        ]));
        set_exits(([
          "south" : ROOMS"foyer",
        ]));
        set_door("double doors",ROOMS"foyer","south",0);
        set_door_description("double doors", "To the north you see 20 foot high %^RESET%^%^RED%^double doors%^BOLD%^"
"%^BLACK%^ made of thick %^WHITE%^white %^RESET%^%^ORANGE%^pine %^BOLD%^%^BLACK%^which has been saturated in some kind of "
"%^BLUE%^black pitch%^BLACK%^.  The double doors are reinforced by a %^WHITE%^s%^RESET%^i%^BOLD%%^WHITE%^l%^RESET%^v"
"%^BOLD%^%^WHITE%^e%^RESET%^r%^BOLD%^%^BLACK%^ alloy that bands the wood together.  The bands are covered in %^BLUE%^r"
"%^MAGENTA%^u%^GREEN%^n%^WHITE%^e%^CYAN%^s %^BLACK%^and sigils.");
}

// syntax: kiss man/kiss dithas/Kiss Dithas/kiss old man - teleport you to lava room.
// Ok this is the "first" exit.  What is in this room is a permanent Greater Illusion of Dithas.  If you kiss him you get 
//teleported back to the last room before you enter his house.  When you kiss him He says "Thank you for visiting my Home.  
//Night's Blessings upon you" then casts an illusionary (but looks real to the visitor) "blight" spell on the person doing 
//the kissing.
