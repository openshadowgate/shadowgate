#include <std.h>
#include "sil.h"

inherit ROOM;

void create(){
  ::create();
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
" the west, the edges of a %^RESET%^%^GREEN%^magestic forest %^BOLD%^%^BLUE%^springs up past a"
" %^RESET%^%^BLUE%^dark lagoon %^RESET%^shrouded %^BOLD%^%^BLUE%^in %^RESET%^mist%^BOLD%^%^BLUE%^,"
" with each %^RESET%^%^GREEN%^tree %^BOLD%^%^BLUE%^seeming to raise its %^GREEN%^bows"
" %^BLUE%^towards the %^WHITE%^heavens %^BLUE%^above.  To the north, four"
" %^RESET%^%^GREEN%^cypress trees %^ORANGE%^twist %^BOLD%^%^BLUE%^and %^RESET%^%^ORANGE%^curl"
" %^BOLD%^%^BLUE%^towards each other to create a %^RESET%^%^ORANGE%^wooden bridge"
" %^BOLD%^%^BLUE%^that spans the %^RESET%^%^CYAN%^inlet %^BOLD%^%^BLUE%^separating this portion"
" of the beach from the rest.  To the south, a single %^RESET%^ivory building"
" %^BOLD%^%^BLUE%^is nestled against a %^BLACK%^rocky outcropping %^BLUE%^that protects this"
" beach from the south.\n");
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
" inland body is nearly always covered in a %^RESET%^thick shroud %^BLUE%^of %^RESET%^mist.",
  "sea":"%^BOLD%^%^CYAN%^The vast expanse of sparkling blue waters disappears into the horizon%^RESET%^.",
  ({"building", "ivory building"}):"%^BOLD%^%^WHITE%^Flanked by the cliffs to the south,"
" this ivory building is ancient by most standards and sets well above the sandy beach atop"
" a four foot tall base, it's entrance reached by the set of four steps leading towards it."
"  Large, carved columns support the twenty foot roof, but the building is otherwise open-air"
", with no walls to speak of.  Oddly, the two columns that support the entrance look to have"
" been recently replaced by a set of marble statues turned to face one another with their"
" joined hands creating an arch over the entrance that supports the portion of roof directly"
" above.%^RESET%^",
  ({"statues","marble statues"}):"%^BOLD%^%^WHITE%^The statue on the right is carved in the"
" image of a nude female elf standing on the balls of her feet, her slender calves flexed in"
" her effort to join hands with the male elf across from her.  The statue is incredibly life"
" like, with every sinewy, corded muscle and soft, feminine curve carved out in exquisite"
" detail.  She has wispy long hair that tumbles over  her shoulders towards the small of her"
" back, and the faint tracings of a tattoo can be seen etched into the marble form of her left"
" arm, snaking its way over her shoulder and down her back.  She smiles across the entrance to"
" the statue on the left, which depects a nude male who also stands on the balls of his feet in"
" his effort to reach her.  Carved in as much detail as the other, subtle traces of patterned"
" scarring and ritualistic branding cover much of his body, and his hair falls behind him in"
" a multitude of braids secured by carved marble beads.  This statue seems to smile back at"
" the female as well, but the smile upon this one is almost predatory in nature.  Where their"
" hands join beneath the roof, an inscription is carved above the entrance%^RESET%^.",
  ({"cliff", "outcropping", "rocky outcropping", "barrier"}):"%^BOLD%^%^BLACK%^To the south,"
" this rocky outcropping looms ominously over the %^WHITE%^ivory building %^BLACK%^nestled at"
" its base and disappears deep within the %^RESET%^%^GREEN%^forest %^BOLD%^%^BLACK%^to the"
" west.  Jutting further into the %^CYAN%^s%^RESET%^%^CYAN%^e%^BOLD%^a %^BLACK%^than the"
" %^WHITE%^beach %^BLACK%^itself, the cliff walls are not only sheer, but riddled with"
" unstable shale and large rocks that look impossible to climb.",
   "bridge":"%^RESET%^%^ORANGE%^To the north, a wooden bridge gently %^GREEN%^arches"
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
  "forest":"%^RESET%^%^GREEN%^To the west, and past the %^BLUE%^lagoon %^GREEN%^shrouded"
" in %^RESET%^mists%^GREEN%^, a %^BOLD%^magestic forest %^RESET%^%^GREEN%^rises towards"
" the %^CYAN%^heavens%^GREEN%^.  Multitudes of colors ranging from the %^BOLD%^light green"
" %^RESET%^%^GREEN%^of new %^BOLD%^forest growth %^RESET%^%^GREEN%^to the"
" %^BOLD%^da%^RESET%^%^GREEN%^rke%^BOLD%^r g%^RESET%^%^GREEN%^ree%^BOLD%^n"
" %^RESET%^%^GREEN%^of more mature trees form patterns of %^CYAN%^health %^GREEN%^and"
" %^CYAN%^radiance %^GREEN%^against the western horizon.",
  "trees":"%^RESET%^%^ORANGE%^The set of four trees on this %^RESET%^beach %^ORANGE%^could "
"well be near two thousand years old each.  They are twisted from centuries of blowing"
" %^RESET%^wind %^ORANGE%^and their effort to create the bridge that now spans the gap between"
" the two %^BOLD%^%^WHITE%^beaches%^RESET%^%^ORANGE%^.  They hold the trademark flat tops and"
" %^GREEN%^dense sprays %^ORANGE%^of %^BOLD%^%^GREEN%^bright green foliage"
" %^RESET%^%^ORANGE%^famous to their species, and backed by the canvas of"
" %^BOLD%^%^CYAN%^sparkling tu%^RESET%^%^CYAN%^rq%^BOLD%^ois waters %^RESET%^%^ORANGE%^to"
" the east, they are a piece of living art that is breathtaking to behold.",
    "inlet":"%^RESET%^%^CYAN%^Separating the northern end of the %^BOLD%^%^WHITE%^beach %^RESET%^%^CYAN%^from the southern end, this"
" wide, %^BOLD%^%^BLUE%^r%^CYAN%^i%^BLUE%^ver %^RESET%^%^CYAN%^like body of water connects the %^BOLD%^s%^RESET%^%^CYAN%^e%^BOLD%^a "
"%^RESET%^%^CYAN%^and the %^BLUE%^lagoon%^CYAN%^.",
   "mist":"%^BOLD%^%^WHITE%^Blanketing the surface of the %^RESET%^%^BLUE%^lagoon %^BOLD%^%^WHITE%^is a thick shroud of mist"
" that hangs regardless of weather or time of day.",
   ]));
  set_exits(([
   "steps":SIL"ivorybuilding",
  "bridge":SIL"beach1",
  ]));
}

void init() {
  ::init();
  add_action("read", "read");
}
int read(string str) {
  if(!str) return 0;
   if((string)TP->query_name() != "silesse" && (string)TP->query_name() !="vicdaerrysn" && !avatarp(TP)) {
    write("None but the true are welcome.");
        return 1;
  }
   write("%^BOLD%^%^BLUE%^U'Aestar'Kess - 'One Heart, One Mind, One Breath' ");
  return 1;
} 

string ldesc(string str){
   return("%^BOLD%^%^WHITE%^A %^CYAN%^spa%^RESET%^%^CYAN%^rkl%^BOLD%^ing %^WHITE%^and"
" %^RESET%^%^CYAN%^calm sou%^BOLD%^thea%^RESET%^%^CYAN%^stern %^BOLD%^sea %^WHITE%^meets the"
" pristine %^RESET%^w%^BOLD%^hit%^RESET%^e %^BOLD%^sands of the beach here, and gently laps"
" against its shore in a calm, hypnotic fashion.  To the east, the %^RESET%^%^CYAN%^sea"
" %^BOLD%^%^WHITE%^disappears into the horizon in a broad expanse of"
" %^CYAN%^tu%^RESET%^%^CYAN%^rq%^BOLD%^oise wa%^RESET%^%^CYAN%^t%^BOLD%^ers%^WHITE%^, while to"
" the west, the edges of a %^RESET%^%^GREEN%^magestic forest %^BOLD%^%^WHITE%^springs up past a"
" %^RESET%^%^BLUE%^dark lagoon %^RESET%^shrouded %^BOLD%^in %^RESET%^mist%^BOLD%^, with each"
" %^RESET%^%^GREEN%^tree %^BOLD%^%^WHITE%^seeming to raise its %^GREEN%^bows %^WHITE%^towards"
" the heavens above.  To the north, four %^RESET%^%^GREEN%^cypress trees %^ORANGE%^twist"
" %^BOLD%^%^WHITE%^and %^RESET%^%^ORANGE%^curl %^BOLD%^%^WHITE%^towards each other to create a"
" %^RESET%^%^ORANGE%^wooden bridge %^BOLD%^%^WHITE%^that spans the %^RESET%^%^CYAN%^inlet"
" %^BOLD%^%^WHITE%^separating this portion of the beach from the rest.  To the south, a single"
" %^RESET%^ivory building %^BOLD%^is nestled against a %^BLACK%^rocky outcropping"
" %^WHITE%^that protects this beach from the south.\n");
}
