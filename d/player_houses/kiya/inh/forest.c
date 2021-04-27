#include <std.h>
#include "../defs.h"
inherit ROOM;

int getfood;

void create() {
        ::create();
        set_property("indoors",0);
        set_property("light",2);
        set_terrain(HEAVY_FOREST);
        set_travel(GAME_TRACK);
        set_name("Dense forest");
        set_short("%^GREEN%^Dense forest%^RESET%^");
        set_smell("default","The sharp, crisp scent of the forest fills the air.");
        set_listen("default","You can hear the quiet rustle of wind through the trees.");
   set_items(([
     ({"trees","forest"}) : (:TO,"tree_desc":),
     ({"ground","grass","plants","undergrowth"}) : (:TO,"ground_desc":),
     ({"flowers","vines"}) : (:TO,"flowers_desc":),
     ({"leaf","leaves"}) : (:TO,"leaves_desc":),
     "branches" : (:TO,"branches_desc":)
        ]));
   set_search("default","%^GREEN%^You think you might even be able to %^WHITE%^find fruit%^GREEN%^ around here.%^RESET%^");
}

void init() {
   ::init();
   add_action("find_fun","find");
}

void reset() {
   ::reset();
   getfood = 0;
}

string tree_desc() {
   if (season(time()) == "winter") {
     return("%^GREEN%^Most of these trees are several hundred feet tall, towering above you, with their "
"thick branches coated in %^WHITE%^snow%^GREEN%^.  They must be incredibly old to have grown so "
"large.%^RESET%^");
   }
   return("%^GREEN%^Most of these trees are several hundred feet tall, towering above you.  They must be "
"incredibly old to have grown so large.%^RESET%^");
}

string ground_desc() {
   if (season(time()) == "winter") {
     return("%^GREEN%^The ground is covered in a layer of %^WHITE%^deep snow%^GREEN%^, making it hard to "
"find a way through the forest.%^RESET%^");
   }
   if (season(time()) == "autumn") {
     return("%^GREEN%^The sparsely-grassed ground here is covered in %^ORANGE%^fal%^RED%^l%^ORANGE%^en "
"le%^GREEN%^a%^ORANGE%^ves%^GREEN%^ and scores of small plants, making it hard to find a way through the "
"forest.%^RESET%^");
   }
   return("%^GREEN%^The thick-grassed ground here is covered in scores of fresh, thriving plants, making "
"it hard to find a way through the forest.%^RESET%^");
}

string flowers_desc() {
   if (season(time()) == "winter") {
     return("%^GREEN%^Long, tangled vines drape their %^CYAN%^pa%^WHITE%^l%^CYAN%^e "
"fl%^WHITE%^o%^CYAN%^wers%^GREEN%^ over the branches above, filling the air with a %^MAGENTA%^gentle "
"scent%^GREEN%^.  A layer of %^WHITE%^snow%^GREEN%^ rests upon them, weighing them down a "
"little.%^RESET%^");
   }
   return("%^GREEN%^Long, tangled vines drape their %^CYAN%^pa%^WHITE%^l%^CYAN%^e "
"fl%^WHITE%^o%^CYAN%^wers%^GREEN%^ over the branches above, filling the air with a %^MAGENTA%^gentle "
"scent%^GREEN%^.%^RESET%^");
}

string leaves_desc() {
   if (season(time()) == "winter") {
     return("%^GREEN%^Only a handful of leaves still remain on the %^WHITE%^snowcovered%^GREEN%^ branches "
"above.%^RESET%^");
   }
   if (season(time()) == "autumn") {
     return("%^GREEN%^Mul%^ORANGE%^t%^GREEN%^ico%^BOLD%^l%^RESET%^%^GREEN%^ou%^RED%^r%^GREEN%^ed leaves "
"hang from the branches above, and litter the ground beneath your feet.%^RESET%^");
   }
   return("%^GREEN%^Mul%^ORANGE%^t%^GREEN%^ico%^BOLD%^l%^RESET%^%^GREEN%^ou%^RED%^r%^GREEN%^ed leaves "
"hang from the branches above.%^RESET%^");
}

string branches_desc() {
   if (season(time()) == "winter") {
     return("%^GREEN%^Thick, sturdy branches criss-cross above your head from the tall trees around you.  "
"%^WHITE%^Snow%^GREEN%^ rests in thick layers upon all the boughs, which only hold a handful of "
"leaves.%^RESET%^");
   }
   return("%^GREEN%^Thick, sturdy branches criss-cross above your head from the tall trees around you.  "
"%^GREEN%^Mul%^ORANGE%^t%^GREEN%^ico%^BOLD%^l%^RESET%^%^GREEN%^ou%^RED%^r%^GREEN%^ed leaves hang from "
"their ends.%^RESET%^");
}

int find_fun(string str) {
   object ob;
   if(str == "food" || str == "fruit") {
     if(getfood == 1) {
       notify_fail("You don't find anything to eat around here.\n");
       return 0;
     }
     tell_object(TP,"You manage to find some fruit to eat.");
     tell_room(ETP,""+TPQCN+" finds some fruit that looks quite tasty.",TP);
     ob = new(OBJ+"food");
     ob->move(TP);
     if(season(time()) == "spring") {
       switch(random(3)) {
         case 0:
         ob->set_id(({"food","fruit","berries","handful of berries"}));
         ob->set_short("%^BLACK%^%^BOLD%^h%^RESET%^%^BLUE%^an%^BLACK%^%^BOLD%^df%^RESET%^%^RED%^ul "
"%^BLACK%^%^BOLD%^of %^RESET%^%^BLUE%^be%^BLACK%^%^BOLD%^rr%^RESET%^%^RED%^ie%^BLACK%^%^BOLD%^s%^RESET%^");
         ob->set_long("%^WHITE%^%^BOLD%^A fair-sized handful of various ripe berries; "
"%^BLACK%^blackberries%^WHITE%^, %^BLUE%^blueberries%^WHITE%^ and %^RED%^raspberries%^WHITE%^.  They look "
"very sweet and juicy.%^RESET%^");
         ob->set_my_mess("You eat the handful of sweet berries.");
         ob->set_your_mess("eats a handful of the berries.");
         break;
         case 1:
         ob->set_id(({"food","fruit","strawberries","wild strawberries"}));
         ob->set_short("%^RESET%^%^RED%^w%^BOLD%^%^BLACK%^%^i%^RESET%^%^RED%^ld "
"st%^MAGENTA%^%^BOLD%^r%^RESET%^%^RED%^awber%^BOLD%^r%^RESET%^%^RED%^ies%^RESET%^");
         ob->set_long("%^WHITE%^%^BOLD%^A bunch of large %^RED%^red strawberries%^WHITE%^, ripe and ready "
"to eat.%^RESET%^");
         ob->set_my_mess("The strawberries are sweet, with a slight tangy taste.%^RESET%^");
         ob->set_your_mess("grins a little at the fruit's tangy taste.");
         break;
         case 2:
         ob->set_id(({"food","fruit","oranges","orange","sweet orange"}));
         ob->set_short("%^RESET%^%^ORANGE%^swe%^RED%^e%^ORANGE%^t or%^RED%^a%^ORANGE%^nge%^RESET%^");
         ob->set_long("%^WHITE%^%^BOLD%^The round orange is a little larger than your hand, with dark "
"skin of an almost %^RESET%^%^RED%^red%^WHITE%^%^BOLD%^ colour.  It feels very soft, and looks perfectly "
"ripe.%^RESET%^");
         ob->set_my_mess("You bite into the orange and taste the fruit's sweet, juicy flavour.");
         ob->set_your_mess("bites into the sweet orange.");
         break;
       }
     }
     if(season(time()) == "summer") {
       switch(random(3)) {
         case 0:
         ob->set_id(({"food","fruit","apricot","apricots","pale apricots","pale apricot"}));
         ob->set_short("%^RESET%^%^ORANGE%^p%^WHITE%^al%^ORANGE%^e "
"%^WHITE%^ap%^ORANGE%^ri%^WHITE%^co%^ORANGE%^t%^RESET%^");
         ob->set_long("%^WHITE%^%^BOLD%^The handful of fruits are very soft, and look too small to be filling unless you eat quite a few.  They are a pale %^RESET%^%^ORANGE%^orange%^WHITE%^%^BOLD%^ colour, with a thin skin protecting the soft flesh beneath.%^RESET%^");
         ob->set_my_mess("The soft, fleshy apricots are mildly flavoured.");
         ob->set_your_mess("slowly eats the soft fruits.");
         break;
         case 1:
         ob->set_id(({"food","fruit","grapes","bunch of grapes"}));
         ob->set_short("%^RESET%^%^MAGENTA%^bu%^BLACK%^%^BOLD%^n%^RESET%^%^MAGENTA%^ch of "
"gra%^BLACK%^%^BOLD%^p%^RESET%^%^MAGENTA%^es%^RESET%^");
         ob->set_long("%^WHITE%^%^BOLD%^This bunch of small %^RESET%^%^MAGENTA%^dark grapes "
"%^WHITE%^%^BOLD%^ are just ripe.  Each fruit looks plump and juicy.%^RESET%^");
         ob->set_my_mess("You pop a few juicy grapes into your mouth.");
         ob->set_your_mess("eats a bunch of dark grapes.");
         break;
         case 2:
         ob->set_id(({"food","fruit","peach","soft peach"}));
         ob->set_short("%^RESET%^%^ORANGE%^so%^YELLOW%^f%^RESET%^%^ORANGE%^t "
"p%^YELLOW%^e%^RESET%^%^ORANGE%^ach%^RESET%^");
         ob->set_long("%^WHITE%^%^BOLD%^This fruit is soft, to the point of ^RESET%^%^MAGENTA%^ "
"bruising%^WHITE%^%^BOLD%^ if you handle it too harshly.  It has a thin, %^RESET%^%^ORANGE%^orange "
"%^WHITE%^%^BOLD%^skin, to protect the soft insides.%^RESET%^");
         ob->set_my_mess("The soft peach practically dissolves in your mouth as you take a bite.");
         ob->set_your_mess("takes a bite from the juicy peach.");
         break;
       }
     }
     if(season(time()) == "autumn") {
       switch(random(3)) {
         case 0:
         ob->set_id(({"food","fruit","apple","green apple"}));
         ob->set_short("%^GREEN%^%^BOLD%^gr%^WHITE%^e%^GREEN%^en app%^WHITE%^l%^GREEN%^e%^RESET%^");
         ob->set_long("%^WHITE%^%^BOLD%^This fruit is very hard, and a little larger than your hand.  It "
"has bright %^GREEN%^green%^WHITE%^ skin, with a crunchy white interior.%^RESET%^");
         ob->set_my_mess("You bite into the apple with an audible crunch.");
         ob->set_your_mess("bites into the apple with an audible crunch.");
         break;
         case 1:
         ob->set_id(({"food","fruit","grapes","bunch of grapes"}));
         ob->set_short("%^RESET%^%^MAGENTA%^bu%^BLACK%^%^BOLD%^n%^RESET%^%^MAGENTA%^ch of "
"gra%^BLACK%^%^BOLD%^p%^RESET%^%^MAGENTA%^es%^RESET%^");
         ob->set_long("%^WHITE%^%^BOLD%^This bunch of small %^RESET%^%^MAGENTA%^dark grapes "
"%^WHITE%^%^BOLD%^are just ripe.  Each fruit looks plump and juicy.%^RESET%^");
         ob->set_my_mess("You pop a few juicy grapes into your mouth.");
         ob->set_your_mess("eats a bunch of dark grapes.");
         break;
         case 2:
         ob->set_id(({"food","fruit","persimmons","persimmon","wild persimmons","wild persimmon"}));
         ob->set_short("%^RESET%^%^RED%^wi%^WHITE%^l%^RED%^d "
"pe%^WHITE%^r%^RED%^sim%^WHITE%^m%^RED%^ons%^RESET%^");
         ob->set_long("%^WHITE%^%^BOLD%^These few wild fruits are shaped like overly large acorns, with a "
"%^RESET%^%^RED%^dark red%^WHITE%^%^BOLD%^ skin, under which is the %^RESET%^%^WHITE%^pale%^BOLD%^ "
"centre.%^RESET%^");
         ob->set_my_mess("The persimmons have a delightful flavour, but with a strange, slightly bitter "
"undertone.");
         ob->set_your_mess("eats the small, red fruits.");
         break;
       }
     }
     if(season(time()) == "winter") {
       switch(random(2)) {
         case 0:
         ob->set_id(({"food","fruit","pear","soft pear"}));
         ob->set_short("%^RESET%^%^WHITE%^soft pear");
         ob->set_long("%^WHITE%^%^BOLD%^The fruit is very soft, to the point of %^RESET%^%^MAGENTA%^ "
"bruising%^WHITE%^%^BOLD%^ if you handle it too harshly.  It has pale skin, beneath which is the juicy, "
"%^RESET%^%^WHITE%^pale%^BOLD%^ insides.%^RESET%^");
         ob->set_my_mess("You take a bite from the soft-textured fruit.");
         ob->set_your_mess("slowly eats the soft fruit.");
         break;
         case 1:
         ob->set_id(({"food","fruit","oranges","orange","sweet orange","sweet oranges"}));
         ob->set_short("%^RESET%^%^ORANGE%^swe%^RED%^e%^ORANGE%^t or%^RED%^a%^ORANGE%^nge%^RESET%^");
         ob->set_long("%^WHITE%^%^BOLD%^The round orange is a little larger than your hand, with dark "
"skin of an almost %^RESET%^%^RED%^red%^WHITE%^%^BOLD%^ colour.  It feels very soft, and looks perfectly "
"ripe.%^RESET%^");
         ob->set_my_mess("You bite into the orange and taste the fruit's sweet, juicy flavour.");
         ob->set_your_mess("bites into the sweet orange.");
         break;
       }
     }
     if(random(2)) getfood = 1;
     return 1;
   }
}
