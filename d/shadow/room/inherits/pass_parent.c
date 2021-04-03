//New rooms added by Circe 12/29/03 to fix mapping problems
#include <std.h>
#include "../pass.h"
inherit ROOM;

string desc_start;
string desc_charu_mountains;
string desc_dragon_pass_road;
string desc_foothills;
string desc_trees;
string desc_road_slow;
string desc_and_cumbersome;
string desc_road_easy;
string desc_road_narrow;
string desc_cliff;
string desc_cliff_north;
string desc_road_high;
string desc_road_high_nw;
string desc_plain_fade;
string desc_road_fade;
string desc_savannah_bush;
string desc_flat_plain;

void create(){
    ::create();


    desc_start = "%^BOLD%^You are walking on the Dragon Pass Road.%^RESET%^\n";
    desc_charu_mountains = "%^BOLD%^%^WHITE%^Ch%^RESET%^a%^BOLD%^r%^RESET%^u %^BOLD%^M%^RESET%^ou%^BOLD%^n%^RESET%^t%^BOLD%^a%^RESET%^i%^BOLD%^ns%^RESET%^";
    desc_foothills = "%^BOLD%^%^GREEN%^foo%^RESET%^%^GREEN%^t%^BOLD%^hi%^RESET%^%^GREEN%^l%^BOLD%^ls%^RESET%^";
    desc_dragon_pass_road = "%^CYAN%^D%^BOLD%^ra%^RESET%^%^CYAN%^g%^BOLD%^o%^RESET%^%^CYAN%^n P%^BOLD%^a%^RESET%^%^CYAN%^ss Ro%^BOLD%^a%^RESET%^%^CYAN%^d%^RESET%^";
    desc_flat_plain = "%^CYAN%^flat plain%^RESET%^";

    desc_trees = "%^ORANGE%^To the east is a %^BOLD%^%^GREEN%^sma%^RESET%^%^GREEN%^l%^BOLD%^l t%^RESET%^%^GREEN%^h%^BOLD%^ic%^RESET%^%^GREEN%^k%^BOLD%^et o%^RESET%^%^GREEN%^f %^BOLD%^t%^RESET%^%^GREEN%^re%^BOLD%^es %^RESET%^%^ORANGE%^which have somehow managed to survive along the edge of the inhospitable %^BOLD%^Shadow Desert%^RESET%^%^CYAN%^.%^RESET%^ ";
    // To the east is a small thicket of trees which have somehow managed to survive
    // along the edge of the inhospitable Shadow Desert.

    desc_road_slow = "%^ORANGE%^The " + desc_dragon_pass_road + " %^ORANGE%^is well kept here and is %^CYAN%^mostly flat%^ORANGE%^, but %^CYAN%^t%^ORANGE%^w%^CYAN%^i%^ORANGE%^s%^CYAN%^t%^ORANGE%^s a%^CYAN%^n%^ORANGE%^d %^CYAN%^t%^ORANGE%^u%^CYAN%^r%^ORANGE%^n%^CYAN%^s %^ORANGE%^making travel %^RED%^slower than in the surrounding "+ desc_foothills;
    // The Dragon Pass road is well kept here and is mostly flat, but twists
    // and turns making travel slower than in the surrounding foothills 

    desc_and_cumbersome = "%^ORANGE%^and at times %^RED%^c%^BOLD%^u%^RESET%^%^RED%^mbers%^BOLD%^o%^RESET%^%^RED%^me%^ORANGE%^.%^RESET%^ ";
    // and at times cumbersome.

    desc_road_easy = "%^ORANGE%^The " + desc_dragon_pass_road + " %^ORANGE%^is well kept here and is %^CYAN%^mostly flat%^ORANGE%^, making travel %^BOLD%^%^CYAN%^ea%^RESET%^%^CYAN%^s%^BOLD%^y %^RESET%^%^ORANGE%^despite the surrounding " + desc_foothills + "%^ORANGE%^. ";
    // The Dragon Pass road is well kept here and is mostly flat, making travel
    // easy despite the surrounding foothills.

    desc_road_narrow = "%^ORANGE%^The road is %^CYAN%^narrower %^ORANGE%^here as it %^CYAN%^snakes %^ORANGE%^between %^CYAN%^t%^BOLD%^%^WHITE%^w%^RESET%^%^CYAN%^o m%^BOLD%^%^WHITE%^o%^RESET%^%^CYAN%^unt%^BOLD%^%^WHITE%^a%^RESET%^%^CYAN%^ins %^ORANGE%^hugging to the western mountain.%^RESET%^ ";
    // The road is narrower here as it snakes between two mountains hugging
    // to the western mountain. 

    desc_road_high = "%^ORANGE%^To the north the road climbs higher along the edge of the " + desc_charu_mountains + "%^ORANGE%^.%^RESET%^ ";
    // To the north the road climbs higher along the edge of the Charu Mountains. 

    desc_road_high_nw =  "%^ORANGE%^To the northwest the road climbs higher along the " + desc_foothills + "%^ORANGE%^ and into the " + desc_charu_mountains + "%^ORANGE%^.%^RESET%^ ";
    //To the northwest the road climbs higher along the foothills and into the Charu Mountains. 

    desc_cliff = "%^ORANGE%^Directly to the east is %^BOLD%^the cliff of a mountain side %^RESET%^%^ORANGE%^making progress impossible in that direction and %^BOLD%^%^BLACK%^preventing %^RESET%^%^ORANGE%^the Shadow Desert from being seen.%^RESET%^ ";
    // Directly to the east is the cliff of a mountain side making progress impossible in
    // that direction and preventing the Shadow Desert from being seen.

    desc_cliff_north = "%^ORANGE%^Directly to the north is %^BOLD%^the cliff of a mountain side %^RESET%^%^ORANGE%^making progress impossible in that direction.";
    // Directly to the north is the cliff of a mountain side making progress impossible in that direction.

    desc_plain_fade = "%^ORANGE%^To the north a " + desc_flat_plain + " %^ORANGE%^and " + desc_foothills + " %^ORANGE%^fade into the intimidating " + desc_charu_mountains + "%^ORANGE%^ in the distance.%^RESET%^ ";
    // To the north a flat plain and foothills fade into the intimidating Charu Mountains in the distance.

    desc_road_fade = "%^ORANGE%^To the north the road climbs higher into the " + desc_foothills + " %^ORANGE%^which fade into the intimidating " + desc_charu_mountains + "%^ORANGE%^ in the near distance.%^RESET %^";
    // To the north the road climbs higher into the foothills which fade into the intimidating 
    // Charu Mountains in the near distance.

    desc_savannah_bush = "%^ORANGE%^A %^GREEN%^small %^BOLD%^s%^ORANGE%^a%^GREEN%^v%^RESET%^%^GREEN%^a%^BOLD%^n%^ORANGE%^n%^GREEN%^a b%^RESET%^%^GREEN%^u%^YELLOW%^s%^GREEN%^h %^RESET%^%^ORANGE%^has sprouted along the side of the road here.%^RESET%^";
    // A small savanna bush has sprouted along the side of the road here.


    set_terrain(ROCKY);
    set_travel(DIRT_ROAD);
    set_property("light",2);
    set_property("indoors",0);
    set_short("%^ORANGE%^On the %^BOLD%^%^CYAN%^D%^RESET%^%^CYAN%^r%^BOLD%^ag%^RESET%^%^CYAN%^o%^BOLD%^n P%^RESET%^%^CYAN%^a%^BOLD%^ss %^RESET%^%^ORANGE%^Road%^RESET%^");

    set_smell("default","%^BOLD%^%^CYAN%^You can smell the fresh mountain air.%^RESET%^");
    set_listen("default","You can hear the wind blowing through the valleys.");
    set_items(([
	"road":"A new road through the mountains.",
	"mountains":"They are impressive, even from here.",
      ]));
}



