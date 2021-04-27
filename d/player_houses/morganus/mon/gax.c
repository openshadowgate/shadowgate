#include <std.h>
#include "../morganus.h"
inherit "/std/barkeep";

int tracker;

void create() {
   ::create();
   set_name("gax");
   set_id(({"gax","barkeep","barkeeper"}));
   set_short("Gax, a short goblin barkeeper");
   set_long("%^BOLD%^%^GREEN%^A young goblin stands here with an odd smile upon his face. "
"Around his neck is a holy symbol of %^YELLOW%^Lathander%^BOLD%^%^GREEN%^. He stands "
"behind the makeshift bar serving food and preparing drinks. He seems friendly, yet "
"watches everyone with an odd glint in his eye.%^RESET%^");
   set_alignment(7);
   set_race("goblin");
   set_class("thief");
   set_body_type("human");
   set_hd(20,1);
   set_max_hp(200);
   set_hp(200);
   set_gender("male");
   set_exp(1);
   set_scrambling(1);

   set_currency("silver");
   set_menu(
     ({"roast pheasant","fresh escargot","steak and eggs","cucumber sandwiches","mushroom wine","water","hot chocolate","dwarven dark ale","horragh"}),
     ({"food","food","food","food","alcoholic","water","soft drink","alcoholic","alcoholic"}),
     ({15,25,10,15,30,2,15,25,10})
   );
   set_my_mess(({
     "Many exotic herbs and spices hit your taste buds as you eat the small bird.\n",
     "You pop the small snails in to your mouth one at a time. With the dipping sauce "
"they taste good.\n",
     "You gobble the food up rapidly using the toast to dip in the runny egg yoke. The "
"steak is seasoned in a strange, exotic fashion. You are fairly sure it is not cow.\n",
     "You quickly eat the plate of tiny sandwiches. They arent the best, but maybe the "
"second best cucumber sandwiches youve ever had.\n",
     "You down the glass of wine, it hits your pallet perfectly. Oddly, you think it "
"would go well with both surf and turf.\n",
     "The water is amazingly refreshing. It taste like it was taken straight from a fresh "
"water spring.\n",
     "The hot chocolate warms your body and gives you a comforting feeling.\n",
     "This ale is really strong. If your centre of gravity isnt just right, you may fall "
"over.\n",
     "You brave the impossible and down the foul brew. A few seconds later you emit a "
"horrible noise from your mouth in disgust, 'horragh'.\n"
   }));
   set_your_mess(({
     "gets an odd look in their eye as they eat the roast pheasant.\n",
     "has a strange look on their face as they dip and pop several tiny snails into their "
"mouth.\n",
     "seems to relish the steak and eggs as they eat every last bite.\n",
     "eat the little sandwiches, making even you feel hungry.\n",
     "seems to consider the taste of the odd hued wine. It seems to go down well.\n",
     "downs a glass of clean clear water.\n",
     "seems to relax ever so slightly as they drink the hot chocolate.\n",
     "gets an odd look as the dark ale is downed.\n",
     "makes a dreadful face and sputters out the noise 'horragh'.\n",
   }));
   set_menu_short(({
     "A roast pheasant",
     "Some fresh escargot",
     "A plate of steak and eggs",
     "A plate of small cucumber sandwiches",
     "A glass of strangely hued purple wine",
     "A glass of water",
     "A mug of hot chocolate with marshmallows",
     "A stout mug of dark ale",
     "A metal flagon of green brackish sludge",
   }));
   set_menu_long(({
     "he small bird is succulently roasted. It smells absolutely savoury.\n",
     "A small plate of carefully selected snails. There is a side dipping sauce as "
"well.\n",
     "This plate has two eggs, sunny side up and a nice rare steak. There is even a side "
"of toast.\n",
     "They seem to be made out of cucumbers on little wafers. There are toothpicks in "
"each one.\n",
     "This glass of odd wine has a remarkable smell. Its colour lends to its exotic "
"nature.\n",
     "A glass of clean water served in a questionably clean glass.\n",
     "This rich and creamy hot chocolate has white melting marshmallows in it.\n",
     "This stout mug holds a pint of a deep coloured ale with a strong scent.\n",
     "This metal flagon is partial corroded. The green sludge smells horrible.\n",
   }));
   force_me("speech say in a high squeak");
   tracker = 0;
}

void catch_say(string msg){
   call_out("reply_fun",1,msg,TP);
}

void reply_fun(string msg, object who){
   string name;
   name = who->query_name();
   if(!msg || !objectp(who)) return;
   if(strsrch(msg,"key please") != -1 || strsrch(msg,"Key please") != -1 || strsrch(msg,"key, please") != -1) {
     if(name != "morganus") {
       TO->force_me("say no no, youse not get key, no.");
       TO->force_me("emote goes back to his work, bustling around behind the bar.");
       return;
     }
     else {
       if(tracker) {
         TO->force_me("say already gave you key, yep.");
         TO->force_me("emote shrugs.");
         return;
       }
       TO->force_me("say yep, I gots key.");
       TO->force_me("emote reaches into a pocket and pulls out a little blue key, which he hands across.");
       new(OBJ"key")->move(TO);
       TO->force_me("give key to morganus");
       tracker = 1;
     }
   }
   return;
}
