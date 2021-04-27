#include <std.h> 
#include "../defs.h" 
inherit VAULT; 

// The Bloody Scourage Inn (Innaeli & Anson's HM 'home')
// Design Work Written by Innaeli 
// Put into game December 2008 :: Nienne 
// Wizard assisted by Lurue 

void create(){ 
   ::create(); 
   set_property("light",1); 
   set_property("indoors",1); 
   set_terrain(STONE_BUILDING); 
   set_travel(PAVED_ROAD); 
   set_name("Guestroom"); 
   set_short("%^RESET%^%^MAGENTA%^Guestroom%^RESET%^"); 
   set_long("%^RESET%^%^MAGENTA%^A dozen small %^BOLD%^%^WHITE%^"+
"oil lanterns%^RESET%^%^MAGENTA%^ are placed around the room, each "+
"providing its own small light and creating a rather %^RESET%^"+
"%^RED%^r%^MAGENTA%^o%^RESET%^%^RED%^ma%^MAGENTA%^nt%^RESET%^"+
"%^RED%^ic%^RESET%^%^MAGENTA%^ atmosphere. The lamps are situated "+
"around the large bed that takes up a majority of the room, and "+
"looks to be quite comfortable. Above the bed, decorating the "+
"%^BOLD%^%^BLACK%^stone wall%^RESET%^%^MAGENTA%^, hangs a %^BOLD%^"+
"%^BLACK%^c%^RESET%^o%^BOLD%^%^BLACK%^il%^RESET%^e%^BOLD%^"+
"%^BLACK%^d whip%^RESET%^%^MAGENTA%^ that actually appears to be "+
"quite functional. Small %^RESET%^%^ORANGE%^nightstands%^RESET%^"+
"%^MAGENTA%^ flank the bed, and an %^RESET%^ornate %^BOLD%^"+
"%^WHITE%^mirror%^RESET%^%^MAGENTA%^ decorates the wall across "+
"from it. The %^RESET%^%^ORANGE%^wooden floor%^RESET%^%^MAGENTA%^ "+
"is covered by a decorative %^BOLD%^%^RED%^cr%^RESET%^%^RED%^ims"+
"%^BOLD%^%^RED%^o%^RESET%^%^RED%^n r%^BOLD%^%^RED%^u%^RESET%^"+
"%^RED%^g%^RESET%^%^MAGENTA%^, and there is a %^BOLD%^%^BLACK%^"+
"cozy chair%^RESET%^%^MAGENTA%^ in the corner of the room. A "+
"small, %^RESET%^%^RED%^curtained window%^RESET%^%^MAGENTA%^ "+
"allows some natural light to seep into the room. A %^BOLD%^"+
"%^BLACK%^black%^RESET%^%^MAGENTA%^, porcelain wash basin sits at "+
"the base of the bed upon an %^RESET%^ornate %^BOLD%^%^BLACK%^"+
"iron%^RESET%^ pedestal%^RESET%^%^MAGENTA%^.%^RESET%^ ");

   set_smell("default","%^BOLD%^%^MAGENTA%^A mild aroma fills the "+
"air from the scented oil lamps.%^RESET%^"); 
   set_listen("default","%^BOLD%^%^RED%^Light music from "+
"downstairs creates a pleasant backdrop.%^RESET%^"); 

   set_items(([ 
({"lamp","lamps","lanterns"}):"%^RESET%^A few %^BOLD%^%^WHITE%^iron lanterns"+
"%^RESET%^ hang by thin %^YELLOW%^g%^RESET%^%^ORANGE%^o%^YELLOW%^ld"+
"%^RESET%^%^ORANGE%^e%^YELLOW%^n c%^RESET%^%^ORANGE%^h%^YELLOW%^ai"+
"%^RESET%^%^ORANGE%^n%^YELLOW%^s%^RESET%^, while others are placed "+
"on the tables all around the room. The lanterns are small as such "+
"things go, and they have %^BOLD%^fr%^RESET%^o%^BOLD%^ste%^RESET%^d "+
"p%^BOLD%^a%^RESET%^ne%^BOLD%^%^WHITE%^s%^RESET%^ covered with "+
"tiny %^BOLD%^stars%^RESET%^. While they do not create much light "+
"individually, together they fill the room with a %^BOLD%^soft "+
"light%^RESET%^.",

({"bed"}):"%^RESET%^Draped in %^BOLD%^%^BLACK%^black sheets"+
"%^RESET%^, this bed looks very comfortable. Half a dozen "+
"fe%^BOLD%^at%^RESET%^h%^BOLD%^er%^RESET%^y, %^BOLD%^s%^RESET%^"+
"il%^BOLD%^k-c%^RESET%^ov%^BOLD%^er%^RESET%^e%^BOLD%^d%^RESET%^ "+
"pillows, %^BOLD%^%^RED%^cr%^RESET%^%^RED%^im%^BOLD%^%^RED%^s"+
"%^RESET%^%^RED%^on%^RESET%^ and %^BOLD%^%^BLACK%^black%^RESET%^, "+
"are placed against the %^BOLD%^%^BLACK%^ebony headboard%^RESET%^. "+
"The bed features four posts, each of which appears a bit, "+
"%^BOLD%^curiously%^RESET%^, worn.%^RESET%^",

({"whip"}):"%^RESET%^This is certainly an interesting wall "+
"adornment. The %^BOLD%^%^BLACK%^whip%^RESET%^ is made from "+
"%^RESET%^%^RED%^r%^BOLD%^%^BLACK%^e%^RESET%^%^RED%^d l%^BOLD%^"+
"%^BLACK%^ea%^RESET%^%^RED%^th%^BOLD%^%^BLACK%^e%^RESET%^%^RED%^r"+
"%^RESET%^ with a %^BOLD%^%^WHITE%^b%^RESET%^o%^BOLD%^%^WHITE%^ne "+
"g%^RESET%^r%^BOLD%^%^WHITE%^ip%^RESET%^. While it appears "+
"functional, and %^BOLD%^used%^RESET%^ for that matter, it is "+
"nailed to the wall in a perfect spiral.%^RESET%^",

({"nightstands","stands"}):"%^RESET%^The nightstands are "+
"%^BOLD%^%^BLACK%^ebony%^RESET%^ and have a single, small drawer "+
"at the top. An %^BOLD%^%^WHITE%^oil lantern%^RESET%^ sits atop "+
"each one, but they are otherwise left bare.%^RESET%^",

({"mirror"}):"%^RESET%^Cast in %^BOLD%^%^BLACK%^iron%^RESET%^, "+
"this oval mirror, while reflective as one would suppose a mirror "+
"to be, is curiously cracked. %^BOLD%^%^BLACK%^S%^RESET%^p"+
"%^BOLD%^%^BLACK%^id%^RESET%^e%^BOLD%^%^BLACK%^r-w%^RESET%^e"+
"%^BOLD%^%^BLACK%^b%^RESET%^ lines creep along its surface, "+
"di%^BOLD%^st%^RESET%^or%^BOLD%^ti%^RESET%^ng your reflection. "+
"The antiqued frame depicts %^BOLD%^%^BLACK%^ivy%^RESET%^ and "+
"%^BOLD%^%^BLACK%^blossoming flowers%^RESET%^.",

({"rug"}):"%^RESET%^The bed rests upon this rather simple, thin "+
"%^BOLD%^%^RED%^c%^RESET%^%^RED%^rim%^BOLD%^%^RED%^so%^RESET%^"+
"%^RED%^n r%^BOLD%^%^RED%^u%^RESET%^%^RED%^g%^RESET%^. It is lined "+
"with small %^RESET%^%^RED%^crimson%^RESET%^ tassels.%^RESET%^",

({"chair"}):"%^RESET%^The chair is large enough to fit two "+
"average-sized people, if they wanted to be snug. Not surprising, "+
"it is %^BOLD%^%^RED%^c%^RESET%^%^RED%^rims%^BOLD%^%^RED%^o"+
"%^RESET%^%^RED%^n%^RESET%^. Its plush cushions are made to be "+
"sunk into and curled up upon. It looks quite cozy.%^RESET%^",

({"curtains","window"}):"%^RESET%^The window is small but allows "+
"some natural light to spill into the room. The heavy %^BOLD%^"+
"%^RED%^c%^RESET%^%^RED%^rim%^BOLD%^%^RED%^so%^RESET%^%^RED%^n "+
"c%^BOLD%^%^RED%^ur%^RESET%^%^RED%^tai%^BOLD%^%^RED%^n%^RESET%^"+
"%^RED%^s%^RESET%^ are lined with pretty %^BOLD%^%^BLACK%^black "+
"l%^RESET%^a%^BOLD%^c%^BOLD%^%^BLACK%^e%^RESET%^, and they can "+
"be opened or closed, blocking out all the %^BOLD%^sunlight"+
"%^RESET%^.",

({"wash basin","basin","pedestal"}):"%^RESET%^The pedestal is "+
"a %^MAGENTA%^mastery%^RESET%^ of metal work. The %^BOLD%^"+
"%^BLACK%^blackened iron%^RESET%^ is twisted in the front to "+
"create the image of a %^BOLD%^%^BLACK%^coiled whip%^RESET%^. "+
"%^BOLD%^%^BLACK%^Black marble%^RESET%^ shot through with "+
"%^BOLD%^%^BLACK%^j%^RESET%^a%^BOLD%^%^BLACK%^gg%^RESET%^e"+
"%^BOLD%^%^BLACK%^d%^YELLOW%^ g%^RESET%^%^ORANGE%^o%^YELLOW%^ld "+
"lin%^RESET%^%^ORANGE%^e%^YELLOW%^s%^RESET%^ sits upon the "+
"slender iron legs. A basin is carved into the surface and is "+
"replaced daily by %^BOLD%^fresh %^RESET%^%^CYAN%^water%^RESET%^ "+
"for which to clean with. A small %^YELLOW%^g%^RESET%^%^ORANGE%^"+
"old%^YELLOW%^e%^RESET%^%^ORANGE%^n tr%^YELLOW%^a%^RESET%^"+
"%^ORANGE%^y%^RESET%^ holds a bar of %^BOLD%^%^MAGENTA%^l"+
"%^RESET%^%^MAGENTA%^av%^BOLD%^%^MAGENTA%^en%^RESET%^%^MAGENTA%^"+
"de%^RESET%^%^MAGENTA%^r-s%^BOLD%^%^MAGENTA%^ce%^RESET%^"+
"%^MAGENTA%^nt%^BOLD%^%^MAGENTA%^ed%^BOLD%^%^WHITE%^ soap"+
"%^RESET%^ and a soft %^BOLD%^%^BLACK%^black cloth%^RESET%^ "+
"for scrubbing.%^RESET%^",
   ])); 
   set_exits(([ 
"north":ROOMS"bsb5", //ebony door
   ])); 

   set_door("ebony door",ROOMS"bsb5","north",0);
   set_locked("ebony door", 0);
   lock_difficulty("ebony door", "/daemon/player_housing"->get_phouse_lock_dc("poor"), "lock");
   set_door_description("ebony door","%^RESET%^This is a simple "+
"%^BOLD%^%^BLACK%^ebony door%^RESET%^ with %^YELLOW%^b"+
"%^RESET%^%^ORANGE%^ras%^YELLOW%^s k%^RESET%^%^ORANGE%^nob"+
"%^YELLOW%^s%^RESET%^. A %^RESET%^%^MAGENTA%^grotesque%^RESET%^ "+
"face, its mouth wide in an anguished scream leaps out from the "+
"center of each door. A small handle indicates that this "+
"%^BOLD%^interesting%^RESET%^ ornament is probably a knocker. ");
   set_string("ebony door", "open", "The door swings open.");
   set_string("ebony door", "close", "The door swings shut.");
} 


