
// enkahut.c

#include <std.h>
inherit NPC;
string *menu_items;

mapping menu;


void set_menu(string *item_names, string *types, int *strengths);
void set_my_mess(string *msg);
void set_your_mess(string *msg);
void set_empty_container(string *empty);
void set_menu_short(string *str);
void set_menu_long(string *str);
string *query_menu();
void create() {
  object obj;
  ::create();
  set_name("enkahut");
  set_id( ({ "bard", "enkahut", "host", "waiter", "server","enkahut the bard" }) );
  set_short("%^BOLD%^%^WHITE%^En%^RESET%^k%^BOLD%^%^CYAN%^a%^RESET%^h%^BOLD%^%^BLACK%^u%^WHITE%^t%^BOLD%^%^BLACK%^, the %^BLUE%^Bard%^RESET%^");
  set_level(30);
  set_long("%^BOLD%^%^BLACK%^Before you stands a male %^BLUE%^Drow%^BLACK%^, thin as a"
" whip and on the short side, but what he lacks in stature he more than accommodates for"
" with his %^MAGENTA%^flamboyant %^BLACK%^appearance. His %^WHITE%^sil%^BLACK%^v%^WHITE%^er"
" h%^BLACK%^a%^CYAN%^i%^WHITE%^r %^BLACK%^is long up top, spiked into a %^WHITE%^Mohawk"
"%^BLACK%^ and %^RESET%^shaved %^BOLD%^%^BLACK%^on the sides except for the sideburns which"
" have been allowed to grow long enough to %^WHITE%^br%^BLACK%^a%^RESET%^i%^BOLD%^%^WHITE%^d"
"%^BLACK%^ them together beneath his chin in a faux %^WHITE%^beard%^BLACK%^. His tapered"
" ears are decorated with %^RESET%^silver h%^CYAN%^o%^BOLD%^%^CYAN%^o%^RESET%^ps"
" %^BOLD%^%^BLACK%^and %^WHITE%^d%^RESET%^i%^BOLD%^%^CYAN%^a%^WHITE%^m%^ORANGE%^o%^WHITE%^nd"
" studs%^BLACK%^. He boasts sky-high cheekbones, slim lips and a hawk-like nose. His dusky"
" skin has a %^RESET%^%^MAGENTA%^purple hue %^BOLD%^%^BLACK%^and his almond-shaped"
" %^ORANGE%^amb%^RESET%^%^ORANGE%^e%^BOLD%^%^ORANGE%^r e%^RESET%^%^ORANGE%^y"
"%^BOLD%^%^ORANGE%^es gl%^RESET%^%^ORANGE%^o%^BOLD%^%^ORANGE%^w %^BLACK%^with dark vision,"
" lending him a %^RED%^devilish %^BLACK%^sort of appeal. Exquisite garments adhere to his"
" lithe form like a second skin; he wears a %^BLUE%^cerulean jacket %^BLACK%^with"
" %^RESET%^sil%^BOLD%^%^WHITE%^v%^RESET%^er embr%^BOLD%^%^CYAN%^o%^WHITE%^i%^RESET%^dered"
" dr%^BOLD%^%^BLACK%^a%^RESET%^gons%^BOLD%^%^BLACK%^, a high-collar and long coattails."
" Beneath that is an %^WHITE%^o%^MAGENTA%^p%^CYAN%^a%^WHITE%^le%^MAGENTA%^s%^RESET%^%^CYAN%^c"
"%^WHITE%^e%^BOLD%^%^WHITE%^nt silk shirt %^BLACK%^tucked into a pair of pristine"
" %^WHITE%^white breeches%^BLACK%^. He wears tall black leather boots that come up just"
" over his knees with %^WHITE%^di%^CYAN%^a%^WHITE%^m%^ORANGE%^o%^WHITE%^nd%^BLACK%^-studded"
" %^WHITE%^s%^BLACK%^i%^WHITE%^lver sp%^CYAN%^u%^WHITE%^rs %^BLACK%^on both heels. Various"
" charms hang from around his neck on chains of %^WHITE%^silver%^BLACK%^, %^ORANGE%^gold"
" %^BLACK%^and %^CYAN%^platinum %^BLACK%^and his dexterous-looking digits bear so many"
" %^CYAN%^r%^ORANGE%^i%^CYAN%^ngs%^BLACK%^ that he wears more than one on some of his"
" fingers.%^RESET%^");
  set_gender("male");
  set_exp(20);
set_alignment(8);
  set_race("drow");
  set_hd(10,0);
  set_hp(356);
  set_max_hp(query_hp());
  add_money("gold", random(1000));
  set_body_type("drow");
  set_menu(
    ({ "food for thought", "bounty of the deep", "finger lichen good", "wrong or rothe", "rolling in the deep", "spiderkisser surprise", "bloody good pudding", "crunchy cave delight", "eye of the beholder", "simple and clean","bazi tea", "black wine", "mother's milk", "deep abyssal ale", "drow azure wine", "spiderblood" }),
       ({ "food", "food", "food", "food", "food", "food", "food", "food", "food", "water", "soft drink", "soft drink", "soft drink", "alcoholic", "alcoholic", "alcoholic" }),
      ({15,15,15,30,45,45,30,30,45,15,15,15,15,15,15,15})
   );
   set_my_mess(({
       "%^RESET%^You dip a piece of %^ORANGE%^fried tentacle %^WHITE%^in the"
" %^BOLD%^%^RED%^sweet sauce %^RESET%^and pop it in your mouth. The batter is spiced with"
" Sse giving it delightful %^RED%^he%^BOLD%^%^RED%^a%^RESET%^%^RED%^t %^WHITE%^and the"
" tentacles are cooked to perfection, melting in your mouth.%^RESET%^\n",
       "%^BOLD%^%^BLACK%^You pile a piece of %^RESET%^bread %^BOLD%^%^BLACK%^with sliced"
" rothe %^ORANGE%^che%^WHITE%^e%^RESET%^%^ORANGE%^s%^BOLD%^%^ORANGE%^e %^BLACK%^and"
" m%^RESET%^%^ORANGE%^u%^BOLD%^%^ORANGE%^shro%^RESET%^o%^BOLD%^%^BLACK%^ms then mop up"
" the %^RESET%^%^ORANGE%^Oob'%^BOLD%^%^BLACK%^. The combination tantalizes your taste"
" buds!%^RESET%^\n",
       "%^BOLD%^%^WHITE%^You dig into the salad. The tender %^BLACK%^m%^RESET%^u"
"%^BOLD%^%^BLACK%^shrooms %^WHITE%^and springy %^CYAN%^l%^GREEN%^i%^CYAN%^ch"
"%^RESET%^%^CYAN%^e%^BOLD%^%^CYAN%^n %^WHITE%^create a delightful blend of textures"
" and flavors!%^RESET%^\n",
       "%^RESET%^The %^BOLD%^%^RED%^me%^RESET%^%^RED%^a%^BOLD%^%^RED%^t %^RESET%^literally"
" falls off the %^BOLD%^%^BLACK%^bone %^RESET%^and melts in your mouth. The %^ORANGE%^tangy"
" sauce %^WHITE%^leaves your fingers sticky.\n",
       "%^BOLD%^%^BLACK%^You pick up the %^RESET%^%^ORANGE%^wooden sticks"
" %^BOLD%^%^BLACK%^meant to serve as utensils, balance one of the %^MAGENTA%^c"
"%^ORANGE%^o%^MAGENTA%^l%^RED%^o%^MAGENTA%^rf%^WHITE%^u%^MAGENTA%^l r%^RED%^o%^MAGENTA%^lls"
" %^BLACK%^between them, and pop it in your mouth. Scrumptious!%^RESET%^\n",
       "%^BOLD%^%^BLACK%^You crack one of the sp%^RED%^i%^BLACK%^der legs in half"
" and suck the %^RESET%^%^GREEN%^me%^ORANGE%^a%^GREEN%^t %^BOLD%^%^BLACK%^out.%^RESET%^\n",
       "%^RESET%^You try a piece of the %^ORANGE%^br%^RED%^o%^ORANGE%^wn cake%^WHITE%^."
" It has a tangy, m%^BOLD%^%^BLACK%^e%^RESET%^t%^BOLD%^%^WHITE%^a%^RESET%^ll%^BOLD%^%^BLACK%^i%^RESET%^c taste. \n",
       "%^BOLD%^%^WHITE%^You enjoy a spoonful of the %^RESET%^ice cream %^BOLD%^%^WHITE%^and"
" %^RESET%^%^ORANGE%^caram%^RED%^e%^ORANGE%^lized %^BOLD%^%^BLACK%^crunchy topping%^WHITE%^."
" Just the right combination of %^MAGENTA%^sweet %^WHITE%^and %^RESET%^salty"
"%^BOLD%^%^WHITE%^!%^RESET%^\n",
       "%^BOLD%^%^BLACK%^You squeeze one of the %^GREEN%^t%^RESET%^%^GREEN%^a"
"%^BOLD%^%^GREEN%^rt %^RESET%^%^MAGENTA%^beh%^BOLD%^%^MAGENTA%^o%^RESET%^%^MAGENTA%^ld"
"%^BOLD%^%^BLACK%^e%^RESET%^%^MAGENTA%^r e%^BOLD%^%^MAGENTA%^y%^WHITE%^e%^RESET%^%^MAGENTA%^s"
" %^BOLD%^%^BLACK%^between your teeth until it pops and releases its %^MAGENTA%^jelly"
"%^BLACK%^. Here's looking at you!%^RESET%^\n",
       "%^RESET%^%^CYAN%^You sip at the %^WHITE%^glass %^CYAN%^of"
" c%^BOLD%^%^CYAN%^oo%^RESET%^%^CYAN%^l w%^BOLD%^%^CYAN%^a%^RESET%^%^CYAN%^t%^WHITE%^e%^CYAN%^r. Refreshing!%^RESET%^\n",
       "%^BOLD%^%^BLACK%^You carefully sip at the %^RESET%^ste%^BOLD%^%^BLACK%^a%^RESET%^ming"
" %^ORANGE%^tea %^BOLD%^%^BLACK%^and are surprised by how %^MAGENTA%^sweet %^BLACK%^it"
" is!%^RESET%^\n",
       "%^BOLD%^%^BLACK%^You pour some Rothe %^WHITE%^milk %^BLACK%^and %^RESET%^%^ORANGE%^sugar"
" %^BOLD%^%^BLACK%^into the %^RESET%^%^BLUE%^dark coffee %^BOLD%^%^BLACK%^and stir"
" before taking a sip. Still a bit %^ORANGE%^bitter %^BLACK%^but you can already feel"
" its affects as your pupils dilate and your %^RED%^p%^RESET%^%^RED%^u%^BOLD%^%^RED%^lse"
" ra%^RESET%^%^RED%^c%^BOLD%^%^RED%^es%^BLACK%^!%^RESET%^\n",
       "%^RESET%^You tilt the %^BOLD%^%^CYAN%^glass %^RESET%^and enjoy the"
" %^ORANGE%^warm %^WHITE%^thick %^BOLD%^%^WHITE%^milk%^RESET%^, immediately feeling more"
" %^CYAN%^r%^GREEN%^e%^CYAN%^lax%^BOLD%^%^CYAN%^e%^RESET%^%^CYAN%^d%^RESET%^.\n",
       "%^RESET%^%^BLUE%^You take a swig of the %^BOLD%^%^BLACK%^ale%^RESET%^%^BLUE%^,"
" your vision temporarily %^BOLD%^%^BLACK%^dark%^RESET%^e%^BOLD%^%^BLACK%^ning"
"%^RESET%^%^BLUE%^. You can taste remnants of dried %^ORANGE%^fig%^BLUE%^,"
" %^ORANGE%^m%^RED%^o%^ORANGE%^lass%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^s %^BLUE%^and"
" %^BOLD%^%^BLACK%^bl%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^ckberry%^RESET%^%^BLUE%^.%^RESET%^\n",
       "%^BOLD%^%^BLACK%^You sip the tart %^RESET%^%^CYAN%^a%^BOLD%^%^CYAN%^z%^WHITE%^u"
"%^CYAN%^r%^RESET%^%^CYAN%^e w%^BOLD%^%^CYAN%^i%^RESET%^%^CYAN%^ne %^BOLD%^%^BLACK%^and the room"
" s%^WHITE%^p%^RESET%^i%^BOLD%^%^BLACK%^ns and %^RED%^c%^RESET%^%^ORANGE%^o"
"%^BOLD%^%^ORANGE%^l%^GREEN%^o%^BLUE%^r%^MAGENTA%^s %^ORANGE%^brighten%^BLACK%^."
" You quickly down the rest of the drink and immediately feel like having another!%^RESET%^\n",
       "%^BOLD%^%^BLACK%^You've heard this wine is laced with sp%^RED%^i%^BLACK%^der"
" %^RESET%^%^GREEN%^ven%^BOLD%^%^RED%^o%^RESET%^%^GREEN%^m%^BOLD%^%^BLACK%^. Just a rumor,"
" you're certain, but all the same you sip it tentatively. The flavor is delightful!%^RESET%^\n",
       }));
   set_your_mess(
       ({
       "%^RESET%^dips a piece of %^ORANGE%^fried %^BOLD%^%^BLACK%^illith"
"%^RESET%^%^MAGENTA%^i%^BOLD%^%^BLACK%^d t%^WHITE%^e%^BLACK%^ntacle %^RESET%^in"
" %^BOLD%^%^RED%^sauce %^RESET%^before eating it.\n",
       "%^BOLD%^%^BLACK%^piles a piece of %^RESET%^bread %^BOLD%^%^BLACK%^with rothe"
" %^ORANGE%^che%^WHITE%^e%^RESET%^%^ORANGE%^s%^BOLD%^%^ORANGE%^e %^BLACK%^and"
" f%^RESET%^%^ORANGE%^u%^BOLD%^%^BLACK%^ngi and wolfs it down.%^RESET%^\n",
       "%^BOLD%^%^WHITE%^digs into the salad, popping a forkful of %^BLACK%^m%^RESET%^u"
"%^BOLD%^%^BLACK%^shroom %^WHITE%^and glowing %^CYAN%^l%^GREEN%^i%^CYAN%^ch"
"%^RESET%^%^CYAN%^e%^BOLD%^%^CYAN%^n %^WHITE%^into their mouth.%^RESET%^\n",
       "%^RESET%^ravages a rack of succulent %^BOLD%^%^RED%^r%^RESET%^%^RED%^i%^BOLD%^%^RED%^bs%^RESET%^.\n",
       "%^BOLD%^%^BLACK%^expertly maneuvers a slender pair of %^RESET%^%^ORANGE%^sticks"
" %^BOLD%^%^BLACK%^to pick up one of the rolls of %^MAGENTA%^r%^RED%^a%^MAGENTA%^w"
" f%^WHITE%^i%^MAGENTA%^sh %^BLACK%^and pop it into their mouth.%^RESET%^\n",
       "%^BOLD%^%^BLACK%^picks up one of the sp%^RED%^i%^BLACK%^der legs, cracks it in"
" half and sucks the %^RESET%^%^GREEN%^me%^ORANGE%^a%^GREEN%^t %^BOLD%^%^BLACK%^out.%^RESET%^\n",
       "%^RESET%^enjoys a small %^ORANGE%^br%^RED%^o%^ORANGE%^wn cake %^WHITE%^with"
" %^RED%^d%^BOLD%^%^BLACK%^a%^RESET%^%^RED%^rk r%^BOLD%^%^BLACK%^e%^RESET%^%^RED%^d"
" %^RESET%^lumps baked within.\n",
       "%^BOLD%^%^WHITE%^enjoys a %^MAGENTA%^sweet %^WHITE%^and %^RESET%^salty"
" %^BOLD%^%^WHITE%^treat - %^RESET%^ice cream %^BOLD%^%^WHITE%^topped with"
" %^RESET%^%^ORANGE%^caram%^RED%^e%^ORANGE%^lized %^BOLD%^%^BLACK%^cave crickets"
" %^WHITE%^and %^RESET%^%^ORANGE%^pean%^BOLD%^%^ORANGE%^u%^RESET%^%^ORANGE%^ts"
"%^BOLD%^%^WHITE%^!%^RESET%^\n",
       "%^BOLD%^%^BLACK%^bravely consumes one of the %^RESET%^%^MAGENTA%^beh"
"%^BOLD%^%^MAGENTA%^o%^RESET%^%^MAGENTA%^ld%^BOLD%^%^BLACK%^e%^RESET%^%^MAGENTA%^r"
" e%^BOLD%^%^MAGENTA%^y%^WHITE%^e%^RESET%^%^MAGENTA%^s%^BOLD%^%^BLACK%^.%^RESET%^ \n",
       "%^RESET%^%^CYAN%^sips at a %^WHITE%^glass %^CYAN%^of c%^BOLD%^%^CYAN%^oo"
"%^RESET%^%^CYAN%^l clear w%^BOLD%^%^CYAN%^a%^RESET%^%^CYAN%^t%^WHITE%^e%^CYAN%^r.%^RESET%^\n",
       "%^BOLD%^%^BLACK%^carefully sips at a mug full of piping "
"%^RESET%^%^RED%^h%^BOLD%^%^RED%^o%^RESET%^%^RED%^t %^ORANGE%^tea%^BOLD%^%^BLACK%^.%^RESET%^\n",
       "%^BOLD%^%^BLACK%^stirs some %^WHITE%^milk %^BLACK%^and %^RESET%^%^ORANGE%^sugar"
" %^BOLD%^%^BLACK%^into their %^RESET%^%^BLUE%^coffee %^BOLD%^%^BLACK%^but still makes a"
" %^ORANGE%^sour %^BLACK%^face after the first drink.\n",
       "%^RESET%^enjoys a %^BOLD%^%^CYAN%^glass %^RESET%^of thick %^ORANGE%^warm"
" %^WHITE%^Rothe %^BOLD%^%^WHITE%^milk%^RESET%^.\n",
       "%^RESET%^%^BLUE%^takes a swig from a tankard of %^BOLD%^%^BLACK%^dark ale"
" %^RESET%^%^BLUE%^that seems to %^BOLD%^%^BLACK%^damp%^RESET%^e%^BOLD%^%^BLACK%^n"
" %^RESET%^%^BLUE%^the very %^WHITE%^l%^BOLD%^%^WHITE%^i%^ORANGE%^g%^RESET%^ht %^BLUE%^around"
" it.%^RESET%^\n",
       "%^BOLD%^%^BLACK%^takes a sip of %^RESET%^%^CYAN%^gl%^BOLD%^%^CYAN%^o%^RESET%^%^CYAN%^"
"wing a%^BOLD%^%^CYAN%^z%^WHITE%^u%^CYAN%^r%^RESET%^%^CYAN%^e w%^BOLD%^%^CYAN%^i"
"%^RESET%^%^CYAN%^ne%^BOLD%^%^BLACK%^, their eyes growing wide. Within seconds they've"
" drank the rest!%^RESET%^\n",
       "%^BOLD%^%^BLACK%^swirls a glass of %^RESET%^d%^BOLD%^%^BLACK%^u%^RESET%^ll"
" gr%^BOLD%^%^BLACK%^e%^RESET%^y w%^BOLD%^%^RED%^i%^RESET%^ne %^BOLD%^%^BLACK%^and"
" sniffs it suspiciously before taking a tentative sip.%^RESET%^\n",
        })
    );
    set_menu_short(
        ({
        "food for thought",
        "bounty of the deep",
        "finger lichen good",
        "wrong or rothe",
        "rolling in the deep",
        "spiderkisser surprise",
        "bloody good pudding",
        "crunchy cave delight",
        "eye of the beholder",
        "simple and clean",
        "bazi tea",
        "black wine",
        "mother's milk",
        "deep abyssal ale",
        "drow azure wine",
        "spiderblood",
        })
    );
    set_menu_long(
        ({
       "%^RESET%^An %^BOLD%^%^BLACK%^on%^RESET%^y%^BOLD%^%^BLACK%^x platter %^RESET%^piled"
" with steaming %^BOLD%^%^BLACK%^illith%^RESET%^%^MAGENTA%^i%^BOLD%^%^BLACK%^d"
" t%^WHITE%^e%^BLACK%^ntacles%^RESET%^, lightly %^ORANGE%^battered %^WHITE%^and fried"
" to perfection and served with a sweet %^BOLD%^%^RED%^red sauce%^RESET%^.\n",
       " %^BOLD%^%^BLACK%^A rectangular %^WHITE%^porcelain plate %^BLACK%^piled with"
" sliced rothe %^ORANGE%^che%^WHITE%^e%^RESET%^%^ORANGE%^s%^BOLD%^%^ORANGE%^e%^BLACK%^,"
" f%^RESET%^%^ORANGE%^u%^BOLD%^%^BLACK%^ngi and %^RESET%^fresh bread %^BOLD%^%^BLACK%^drizzled"
" with %^RESET%^%^ORANGE%^Oob'%^BOLD%^%^BLACK%^.%^RESET%^\n",
"%^BOLD%^%^WHITE%^A %^BLACK%^black onyx bowl filled with fresh"
" %^BLACK%^f%^RESET%^u%^BOLD%^%^BLACK%^ngi %^WHITE%^and crumbled rothe"
" %^ORANGE%^che%^WHITE%^e%^RESET%^%^ORANGE%^s%^BOLD%^%^ORANGE%^e %^WHITE%^on a bed"
" of gl%^CYAN%^o%^WHITE%^wing %^CYAN%^l%^GREEN%^i%^CYAN%^ch%^RESET%^%^CYAN%^e%^BOLD%^"
"%^CYAN%^n%^WHITE%^, drizzled with an %^RESET%^%^ORANGE%^Oob' %^BOLD%^%^WHITE%^vinaigrette"
".%^RESET%^\n",
       " %^RESET%^A round %^BOLD%^%^BLACK%^on%^RESET%^y%^BOLD%^%^BLACK%^x plate"
" %^RESET%^holding half a rack of %^BOLD%^%^BLACK%^smoked %^RED%^r%^RESET%^%^RED%^o"
"%^BOLD%^%^RED%^the r%^RESET%^%^RED%^i%^BOLD%^%^RED%^bs %^RESET%^resting on a bed of"
" sauted %^GREEN%^vegetables%^RESET%^.\n",
       "%^BOLD%^%^BLACK%^A long rectangular %^WHITE%^porcelain plate %^BLACK%^adorned"
" with rolls of exotic %^MAGENTA%^r%^WHITE%^a%^MAGENTA%^w f%^RED%^i%^MAGENTA%^sh %^BLACK%^and"
" %^GREEN%^p%^RESET%^%^GREEN%^i%^BOLD%^%^GREEN%^ckled %^CYAN%^l%^GREEN%^i%^CYAN%^ch"
"%^RESET%^%^CYAN%^e%^BOLD%^%^CYAN%^n%^BLACK%^.%^RESET%^\n",
       "%^BOLD%^%^BLACK%^A %^WHITE%^porcelain bowl %^BLACK%^filled with %^RESET%^steaming"
" %^BOLD%^%^BLACK%^black sp%^RED%^i%^BLACK%^der legs.%^RESET%^\n",
       "%^RESET%^A small %^ORANGE%^br%^RED%^o%^ORANGE%^wn cake %^WHITE%^with lumps of"
" cl%^RED%^o%^WHITE%^tted Rothe %^RED%^bl%^BOLD%^%^RED%^oo%^RESET%^%^RED%^d %^WHITE%^baked"
" within.\n",
       "%^BOLD%^%^WHITE%^An %^BLACK%^on%^RESET%^y%^BOLD%^%^BLACK%^x bowl %^WHITE%^holding"
" two scoops of %^RESET%^vanilla ice cream %^BOLD%^%^WHITE%^topped with"
" %^RESET%^%^ORANGE%^caram%^RED%^e%^ORANGE%^lized %^BOLD%^%^BLACK%^cave crickets"
" %^WHITE%^and %^RESET%^%^ORANGE%^h%^BOLD%^%^ORANGE%^o%^RESET%^%^ORANGE%^ney"
" r%^BOLD%^%^ORANGE%^o%^RESET%^%^ORANGE%^asted pean%^BOLD%^%^ORANGE%^u"
"%^RESET%^%^ORANGE%^ts%^BOLD%^%^WHITE%^.%^RESET%^\n",
       "%^BOLD%^%^BLACK%^A %^WHITE%^porcelain bowl %^BLACK%^filled with"
" %^GREEN%^p%^RESET%^%^GREEN%^i%^BOLD%^%^GREEN%^ckled %^RESET%^%^MAGENTA%^beh"
"%^BOLD%^%^MAGENTA%^o%^RESET%^%^MAGENTA%^ld%^BOLD%^%^BLACK%^e%^RESET%^%^MAGENTA%^r"
" e%^BOLD%^%^MAGENTA%^y%^RESET%^%^MAGENTA%^es%^BOLD%^%^BLACK%^. Creepy!%^RESET%^\n",
       "%^RESET%^%^CYAN%^A %^WHITE%^tall glass %^CYAN%^of c%^BOLD%^%^CYAN%^oo"
"%^RESET%^%^CYAN%^l, clear %^CYAN%^w%^BOLD%^%^CYAN%^a%^RESET%^%^CYAN%^t%^BOLD%^%^WHITE%^e"
"%^RESET%^%^CYAN%^r.%^RESET%^\n",
       "%^BOLD%^%^BLACK%^A mug of piping %^RESET%^%^RED%^h%^BOLD%^%^RED%^o%^RESET%^%^RED%^t"
" %^ORANGE%^tea%^BOLD%^%^BLACK%^.%^RESET%^\n",
       " %^BOLD%^%^BLACK%^A mug of %^RESET%^%^BLUE%^inky black %^BOLD%^%^BLACK%^liquid"
" served with Rothe %^WHITE%^milk %^BLACK%^and %^RESET%^%^ORANGE%^sugar%^BOLD%^%^BLACK%^."
"%^RESET%^\n",
       "%^RESET%^A %^BOLD%^%^CYAN%^tall glass %^RESET%^of warm Rothe"
" %^BOLD%^%^WHITE%^milk%^RESET%^.\n",
       " %^RESET%^%^BLUE%^A tankard of %^BOLD%^%^BLACK%^black ale %^RESET%^%^BLUE%^that"
" seems to %^RESET%^dampen %^BLUE%^the very %^BOLD%^%^WHITE%^l%^RESET%^i%^BOLD%^%^ORANGE%^g"
"%^WHITE%^ht %^RESET%^%^BLUE%^around it.%^RESET%^\n",
       "%^BOLD%^%^BLACK%^A fluted %^WHITE%^crystal glass %^BLACK%^filled with"
" %^RESET%^%^CYAN%^gl%^BOLD%^%^CYAN%^o%^RESET%^%^CYAN%^wing a%^BOLD%^%^CYAN%^z%^WHITE%^u"
"%^CYAN%^r%^RESET%^%^CYAN%^e %^BOLD%^%^BLACK%^liquid.%^RESET%^\n",
       "%^BOLD%^%^BLACK%^A glass of %^RESET%^d%^BOLD%^%^BLACK%^u%^RESET%^ll"
" gr%^BOLD%^%^BLACK%^e%^RESET%^y w%^BOLD%^%^RED%^i%^RESET%^ne %^BOLD%^%^BLACK%^laced with"
" veins of %^RED%^cr%^RESET%^%^RED%^i%^BOLD%^%^RED%^ms%^RESET%^%^RED%^o%^BOLD%^%^RED%^n"
"%^BLACK%^.%^RESET%^\n",
        })
    );
set_emotes(4, ({"%^RESET%^%^MAGENTA%^A newcomer walks into the dining"
" hall and Enkahut places his hands on his hips and shouts joyfully,"
" %^BOLD%^%^WHITE%^'Welcome, welcome! So pleased you could join us."
" I was afraid we were going to run out of food!' "
"%^RESET%^%^MAGENTA%^The other patrons burst into %^RED%^la"
"%^BOLD%^%^RED%^u%^RESET%^%^RED%^ght%^BOLD%^%^RED%^e%^RESET%^%^RED%^"
"r%^MAGENTA%^.%^RESET%^","%^BOLD%^%^BLACK%^Enkahut whirls on a"
" %^RESET%^%^MAGENTA%^f%^BOLD%^%^MAGENTA%^e%^RESET%^%^MAGENTA%^male"
" patr%^BOLD%^%^MAGENTA%^o%^RESET%^%^MAGENTA%^n %^BOLD%^%^BLACK%^and"
" slaps at her hand, %^WHITE%^'Listen honeypot, we're not in"
" Darol'Dralych anymore. These days you gotta fill my coin purse"
" before you get to jingle it!'%^RESET%^","%^RESET%^%^ORANGE%^Enkahut comes running out of the kitchen, narrowly escaping a small ball"
" of %^BOLD%^%^RED%^f%^RESET%^%^RED%^i%^BOLD%^%^RED%^re"
" %^RESET%^%^ORANGE%^that dissipates at the doorway behind him."
" He cries, %^WHITE%^'You wouldn't have to try to cook the messenger"
" if you could cook a damned steak!'%^RESET%^","%^RESET%^%^RED%^"
"Enkahut places his arm around the shoulders of a"
" %^BOLD%^%^BLACK%^p%^RESET%^i%^BOLD%^%^BLACK%^tif%^WHITE%^u"
"%^BLACK%^l %^RESET%^%^RED%^looking male and says, %^WHITE%^'Give"
" it time darling, you'll forget all about him. You just haven't"
" met the right mindflayer yet.'%^RESET%^","%^BOLD%^%^BLACK%^With"
" a gleeful cry Enkahut leaps onto the stage, crosses his arms and"
" kicks his legs out in an %^CYAN%^e%^RESET%^%^CYAN%^n"
"%^BOLD%^%^CYAN%^erg%^ORANGE%^e%^CYAN%^tic %^BLACK%^mockery"
" of the %^RESET%^%^ORANGE%^Dwarvish %^BOLD%^%^BLACK%^style"
" of dance. The crowd %^ORANGE%^cheers %^BOLD%^%^BLACK%^and %^WHITE%^laughs"
" %^BLACK%^in response.%^RESET%^"}), 0);
}

void init() {
    ::init();
    add_action("buy", "buy");
   add_action("buy","order");
}
void set_menu(string *item_names, string *types, int *strengths) {
    int i;

    menu_items = item_names;
    if(!menu) menu = ([]);
    for(i=0; i<sizeof(menu_items); i++) {
        menu[menu_items[i]] = ([ "type": types[i], "strength": strengths[i] ]);
    }
}
void set_my_mess(string *msg) {
    int i;

    for(i=0; i<sizeof(menu_items); i++) {
        menu[menu_items[i]]["my message"] = msg[i];
    }
}
void set_your_mess(string *msg) {
    int i;

    for(i=0; i<sizeof(menu_items); i++) {

        menu[menu_items[i]]["your message"] = msg[i];
    }
}
void set_empty_container(string *container) {
    int i;

    for(i=0; i<sizeof(menu_items); i++) {
        menu[menu_items[i]]["empty container"] = container[i];
    }
}

void set_menu_short(string *str) {
    int i;

    for(i=0; i<sizeof(menu_items); i++) {
        menu[menu_items[i]]["short"] = str[i];
    }
}
void set_menu_long(string *str) {
    int i;

    for(i=0; i<sizeof(menu_items); i++) {
        menu[menu_items[i]]["long"] = str[i];
    }
}

void receive_given_item(object ob){
   if((string)ob->query_short() == "An empty bottle" ||
      (string)ob->query_name() == "bottle"){
      force_me("emote puts away the empty bottle.");
      ob->remove();
   }
}
int buy(string str) {
    int i, cost;
    object ob;
    if(!str) {
        notify_fail(query_cap_name()+" says: What is it you would like?\n");
        return 0;
    }
    if(!should_interact(TP)){
       force_me("emote taps on the bar and shakes "+query_possessive()+" head in refusal.");
       force_me("say I will not serve you here");
       return 1;
    }
    str = lower_case(str);
    if(member_array(str, menu_items) == -1) {
        notify_fail(query_cap_name()+" says: I don't serve that.\n");
        return 0;
    }


   force_me("emote takes an order from "+TP->query_cap_name()+" and soon delivers it.");
    if(menu[str]["type"] == "food") {
        ob = new("std/food");
        ob->set_name(str);
        ob->set_id( ({str, "food" }) );
    ob->set_value(0);
    }
    else {
        ob = new("std/drink");
        ob->set_name(str);
        ob->set_type(menu[str]["type"]);
        ob->set_id( ({ str, "drink" }) );
    }
    ob->set_strength(menu[str]["strength"]);
    ob->set_weight(1);
    i = menu[str]["strength"];
   ob->set_value(0);
    ob->set_destroy();
    if(menu[str]["short"]) ob->set_short(menu[str]["short"]);
    else ob->set_short(capitalize(str));
    if(menu[str]["long"]) ob->set_long(menu[str]["long"]);
    else ob->set_long(capitalize(str) + " from
"+(string)environment(this_object())->query_short()+".\n");
    if(menu[str]["empty container"]) ob->set_empty_name(menu[str]["empty container"]);
    if(menu[str]["my message"]) ob->set_my_mess(menu[str]["my message"]);
    if(menu[str]["your message"]) ob->set_your_mess(menu[str]["your message"]);
    if(ob->move(this_player())) {
        write("You cannot carry it!\nYou drop a "+str+".\n");
        say(this_player()->query_cap_name()+" drops a "+str+".\n", this_player());
        ob->move(environment(this_player()));
    }
    return 1;
}
string *query_menu() { return menu_items; }
