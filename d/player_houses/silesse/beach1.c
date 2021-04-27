
#include <std.h>
#include "sil.h"

inherit ROOM;

void create(){
  ::create();
set_post_exit_functions(({"forest"}),({"go_out1"}));
   set_terrain(BEACH);
  set_travel(FOOT_PATH);
  set_property("light",2);
  set_name("A tranquil beach");
  set_short("A tranquil beach");
  set_long((:TO,"ldesc":));
  set("night long","%^BOLD%^%^BLUE%^Several %^BOLD%^%^WHITE%^stars %^BLUE%^light up the night"
"sky over the %^BOLD%^%^CYAN%^spa%^RESET%^%^CYAN%^rkl%^BOLD%^ing %^BLUE%^and"
" %^RESET%^%^CYAN%^calm sou%^BOLD%^thea%^RESET%^%^CYAN%^stern %^BOLD%^sea %^BLUE%^that meets the"
" pristine %^RESET%^w%^BOLD%^hit%^RESET%^e %^BOLD%^sands %^BLUE%^of the beach here. To the"
" east, the %^RESET%^%^CYAN%^sea %^BOLD%^%^BLUE%^disappears into the horizon in a broad expanse of"
" %^CYAN%^tu%^RESET%^%^CYAN%^rq%^BOLD%^oise wa%^RESET%^%^CYAN%^t%^BOLD%^ers%^BLUE%^, while to"
" the west, the edges of a %^RESET%^%^GREEN%^magestic forest %^BOLD%^%^BLUE%^springs up"
" with each %^RESET%^%^GREEN%^tree %^BOLD%^%^BLUE%^seeming to raise its %^GREEN%^bows"
" %^BLUE%^towards the %^WHITE%^heavens %^BLUE%^above.  To the south, four"
" %^RESET%^%^GREEN%^cypress trees %^ORANGE%^twist %^BOLD%^%^BLUE%^and %^RESET%^%^ORANGE%^curl"
" %^BOLD%^%^BLUE%^towards each other to create a %^RESET%^%^ORANGE%^wooden bridge"
" %^BOLD%^%^BLUE%^that spans the %^RESET%^%^CYAN%^inlet %^BOLD%^%^BLUE%^separating this portion"
" of the beach from the rest.  Further to the south, a single %^RESET%^ivory building"
" %^BOLD%^%^BLUE%^sits at the southernmost tip of the beach and is nestled against a"
" %^BLACK%^rocky outcropping %^BLUE%^that juts far into the %^CYAN%^s%^RESET%^%^CYAN%^e%^BOLD%^a.%^RESET%^\n");
  set_smell("default","%^BOLD%^%^CYAN%^The %^RESET%^%^CYAN%^salty scent %^BOLD%^%^CYAN%^of"
" the %^RESET%^%^CYAN%^ea%^BOLD%^ste%^RESET%^%^CYAN%^%^rn sea %^BOLD%^mingles with the"
" %^RESET%^%^CYAN%^scent %^BOLD%^of %^RESET%^%^GREEN%^fresh forest%^RESET%^.\n");
  set_listen("default","%^RESET%^%^GREEN%^Above the lulling sounds of gently lapping waves upon"
" the shore, the muted roar of falling water along with the occassional cry of a bird can be"
" heard in the distance.%^RESET%^");
  set_items(([
  "lagoon":"%^RESET%^%^BLUE%^Past the %^CYAN%^inlet %^BLUE%^that separates the two"
" %^RESET%^%^BOLD%^beaches %^RESET%^%^BLUE%^and links %^BOLD%^lagoon %^RESET%^%^BLUE%^to"
" %^BOLD%^%^CYAN%^sea%^RESET%^%^BLUE%^, the %^BOLD%^dark waters %^RESET%^%^BLUE%^of this"
" inland body to the south is nearly always covered in a %^RESET%^thick shroud"
" %^BLUE%^of %^RESET%^mist.",
  "sea":"%^BOLD%^%^CYAN%^The vast expanse of sparkling blue waters disappears into the horizon%^RESET%^.",
  ({"building", "ivory building"}):"%^BOLD%^%^WHITE%^Far to the south is an ivory building at"
" the southernmost tip of the beach.%^RESET%^",
  ({"cliff", "outcropping", "rocky outcropping", "barrier"}):"%^BOLD%^%^BLACK%^To the south,"
" this rocky outcropping looms ominously over the %^WHITE%^ivory building %^BLACK%^nestled at"
" its base and disappears deep within the %^RESET%^%^GREEN%^forest %^BOLD%^%^BLACK%^to the"
" west.  Jutting further into the %^CYAN%^s%^RESET%^%^CYAN%^e%^BOLD%^a %^BLACK%^than the"
" %^WHITE%^beach %^BLACK%^itself, the cliff walls are not only sheer, but riddled with"
" unstable shale and large rocks that look impossible to climb.",
   "bridge":"%^RESET%^%^ORANGE%^To the south, a wooden bridge gently %^GREEN%^arches"
" %^ORANGE%^over the %^CYAN%^inlet %^ORANGE%^that links the %^BOLD%^%^CYAN%^sea"
" %^RESET%^%^ORANGE%^and the %^BLUE%^lagoon %^ORANGE%^to the west. Flanked by two veterern"
" %^GREEN%^Cupressus macrocarpa cypress trees %^ORANGE%^on either side, each %^GREEN%^support"
" %^ORANGE%^and %^GREEN%^railing %^CYAN%^curls %^ORANGE%^and %^CYAN%^twists %^ORANGE%^around"
" as though the bridge itself were grown from their %^GREEN%^living%^ORANGE%^, %^CYAN%^breathing"
" %^ORANGE%^efforts to reach one another.  At the base of each pair of %^GREEN%^trees"
"%^ORANGE%^, gnarled roots wrap around one another to form a set of steps that join bridge"
" and land, while hanging at even intervals upon the bridge itself are small"
" %^BOLD%^%^CYAN%^glo%^RESET%^%^CYAN%^wi%^BOLD%^ng %^RESET%^%^CYAN%^lanterns %^ORANGE%^that"
" %^BOLD%^%^CYAN%^illuminate %^RESET%^%^ORANGE%^the path across the bridge whether it is night"
" or day.",
  "lanterns":"%^RESET%^%^CYAN%^These small %^BOLD%^globes %^RESET%^%^CYAN%^hang in even"
" intervals over the bridge and seem to cast a gently"
" %^BOLD%^glo%^RESET%^%^CYAN%^wi%^BOLD%^ng light %^RESET%^%^CYAN%^upon it at all times, whether"
" it is night or day.",
  "forest":"%^RESET%^%^GREEN%^To the west, a %^BOLD%^magestic forest"
" %^RESET%^%^GREEN%^rises towards the %^CYAN%^heavens%^GREEN%^.  Multitudes of colors"
" ranging from the %^BOLD%^light green %^RESET%^%^GREEN%^of new %^BOLD%^forest growth"
" %^RESET%^%^GREEN%^to the %^BOLD%^da%^RESET%^%^GREEN%^rke%^BOLD%^r"
" g%^RESET%^%^GREEN%^ree%^BOLD%^n %^RESET%^%^GREEN%^of more mature trees form patterns"
" of %^CYAN%^health %^GREEN%^and %^CYAN%^radiance %^GREEN%^against the western horizon.",
  "trees":"%^RESET%^%^ORANGE%^The set of four trees on this %^RESET%^beach %^ORANGE%^could "
"well be near two thousand years old each.  They are twisted from centuries of blowing"
" %^RESET%^wind %^ORANGE%^and their effort to create the bridge that now spans the gap between"
" the two %^BOLD%^%^WHITE%^beaches%^RESET%^%^ORANGE%^.  They hold the trademark flat tops and"
" %^GREEN%^dense sprays %^ORANGE%^of %^BOLD%^%^GREEN%^bright green foliage"
" %^RESET%^%^ORANGE%^famous to their species, and backed by the canvas of"
" %^BOLD%^%^CYAN%^sparkling tu%^RESET%^%^CYAN%^rq%^BOLD%^ois waters %^RESET%^%^ORANGE%^to"
" the east, they are a piece of living art that is breathtaking to behold.",
  "inlet":"%^RESET%^%^CYAN%^Separating the northern end of the %^BOLD%^%^WHITE%^beach %^RESET%^%^CYAN%^from"
" the southern end, this wide, %^BOLD%^%^BLUE%^r%^CYAN%^i%^BLUE%^ver %^RESET%^%^CYAN%^like body of water connects the"
" %^BOLD%^s%^RESET%^%^CYAN%^e%^BOLD%^a %^RESET%^%^CYAN%^and the %^BLUE%^lagoon%^CYAN%^.",
   "mist":"%^BOLD%^%^WHITE%^Blanketing the surface of the %^RESET%^%^BLUE%^lagoon %^BOLD%^%^WHITE%^is a thick shroud of mist"
" that hangs regardless of weather or time of day.",
   ]));
  set_exits(([
"forest":SIL"forest1",
"north":"/d/shadow/virtual/sea/rilynath.dock.c",
  "bridge":SIL"beach2",
  ]));
}
string ldesc(string str){
   return("%^BOLD%^%^WHITE%^A %^CYAN%^spa%^RESET%^%^CYAN%^rkl%^BOLD%^ing %^WHITE%^and"
" %^RESET%^%^CYAN%^calm sou%^BOLD%^thea%^RESET%^%^CYAN%^stern %^BOLD%^sea %^WHITE%^meets the"
" pristine %^RESET%^w%^BOLD%^hit%^RESET%^e %^BOLD%^sands of the beach here, and gently laps"
" against its shore in a calm, hypnotic fashion.  To the east, the %^RESET%^%^CYAN%^sea"
" %^BOLD%^%^WHITE%^disappears into the horizon in a broad expanse of"
" %^CYAN%^tu%^RESET%^%^CYAN%^rq%^BOLD%^oise wa%^RESET%^%^CYAN%^t%^BOLD%^ers%^WHITE%^, while to"
" the west, the edges of a %^RESET%^%^GREEN%^magestic forest %^BOLD%^%^WHITE%^springs high into"
" into the air, with each %^RESET%^%^GREEN%^tree %^BOLD%^%^WHITE%^seeming to raise its"
" %^GREEN%^bows %^WHITE%^towards the heavens above.  To the south, four"
" %^RESET%^%^GREEN%^cypress trees %^ORANGE%^twist %^BOLD%^%^WHITE%^and %^RESET%^%^ORANGE%^curl"
" %^BOLD%^%^WHITE%^towards each other to create a %^RESET%^%^ORANGE%^wooden bridge"
" %^BOLD%^%^WHITE%^that spans the %^RESET%^%^CYAN%^inlet %^BOLD%^%^WHITE%^separating this portion"
" of the beach from the portion just to the south.  Further to the south, a single %^RESET%^ivory"
" building %^BOLD%^rests at the far end of the beach, nestled against a %^BLACK%^rocky"
" outcropping %^WHITE%^that juts far into the %^CYAN%^s%^RESET%^%^CYAN%^e%^BOLD%^a%^RESET%^.\n");
}
int go_out1(string str){
   if(avatarp(TP) || (string)TP->query_name()== "silesse" || (string)TP->query_name()== "vicdaerrysn") {
      tell_room(TP,"%^RESET%^%^CYAN%^A faint %^RESET%^gli%^BOLD%^mm%^RESET%^er %^CYAN%^in the %^BOLD%^%^WHITE%^m%^RESET%^is%^BOLD%^t %^RESET%^%^CYAN%^covered %^GREEN%^fo%^BOLD%^re%^RESET%^%^GREEN%^st floor %^CYAN%^reveals paths headed %^BOLD%^%^GREEN%^east %^RESET%^%^CYAN%^and %^BOLD%^%^GREEN%^west %^RESET%^%^CYAN%^to you.%^RESET%^",TO);
   return 1;
   }
return 1;
}
