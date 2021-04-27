#include <std.h>
#include <daemons.h>
inherit ARMOUR;

int timer;

void create() {
   ::create();
   set_name("helm");
   set_id(({"helm","torm helm","guise of the golden lion","guise","guise of golden lion","golden helm"}));
   set_short("%^WHITE%^%^BOLD%^Guise of the %^RESET%^%^ORANGE%^G%^YELLOW%^o%^RESET%^%^ORANGE%^ld%^YELLOW%^e%^RESET%^%^ORANGE%^n L%^YELLOW%^i%^RESET%^%^ORANGE%^on%^RESET%^");
   set_obvious_short("%^RESET%^%^ORANGE%^or%^YELLOW%^n%^RESET%^%^ORANGE%^ate gol%^YELLOW%^d%^RESET%^%^ORANGE%^en h%^YELLOW%^e%^RESET%^%^ORANGE%^lm%^RESET%^");
   set_long("%^CYAN%^This light, ornate helm is indeed an impressive piece of armor to behold.  Fine "
"%^ORANGE%^gol%^YELLOW%^d%^RESET%^%^ORANGE%^en%^CYAN%^ metal has been flawlessly crafted into smooth "
"contours that would comfortably fit the head, and despite the usual, rather weak consistency of gold, "
"somehow this helm seems impervious to even the heaviest of blows.  The face has been left partly open, to "
"allow the wearer an easy field of vision, while the metal has been worked in an ornamental style of border "
"up around each side of the face.  Upon the back of the helm, near where it would meet the base of the head, "
"has been etched an elaborate image of a %^ORANGE%^lion%^CYAN%^, its mouth opened in a silent roar.  Upon "
"the underside of the helm are a few small %^WHITE%^%^BOLD%^etchings%^RESET%^%^CYAN%^, that seem to spell "
"something out.%^RESET%^\n");
   set_lore("%^WHITE%^%^BOLD%^A helm such as this is only ever gifted to the knighthood of the church of "
"Torm.  It is said that they are blessed by the hand of the True himself, bestowed to the most loyal among "
"his clergy.");
   set_property("lore difficulty",12);
   set_weight(5);
   set_value(6800);
   set_ac(1);
   set_type("armor");
   set_property("enchantment",2);
   set_limbs(({"head"}));
   set_wear((:TO,"wear_fun":));
   set_remove("%^WHITE%^%^BOLD%^You feel the protection of the Loyal Fury recede as you remove the helm.");
}

int wear_fun() {
   if((string)TP->query_diety()!= "torm") {
     tell_object(ETO,"%^WHITE%^%^BOLD%^The helm refuses to fit you!");
     tell_room(EETO,"%^WHITE%^%^BOLD%^"+ETOQCN+" tries to force the helm on, but fails.",ETO);
     return 0;
   }
   tell_object(ETO,"%^WHITE%^%^BOLD%^You are filled with confidence as you slide the helm over your "
"head.");
   tell_room(EETO,"%^WHITE%^%^BOLD%^"+ETOQCN+" slides the helm over "+ETO->QP+" head with a confident "
"smile.",ETO);
   return 1;
}

void init() {
   ::init();
   add_action("read_fun","read");
   add_action("roar_fun","roar");
}

int read_fun(string str) {
   if(!str) {
     tell_object(TP,"What do you want to read?");
     return 0;
   }
   if(str != "helm" && str != "guise") {
     tell_object(TP,"You can't read that.");
     return 0;
   }
   if((string)TP->query_diety()!= "torm") {
     tell_object(TP,"%^WHITE%^%^BOLD%^You try to read the markings upon the underside of the helm, but they "
"make no sense to you at all.%^RESET%^");
     tell_room(ETP,"%^WHITE%^%^BOLD%^"+TP->QCN+" tries to read the markings upon the underside of the helm, "
"but just ends up looking confused by them.%^RESET%^",TP);
   return 1;
   }
   tell_object(TP,"%^WHITE%^%^BOLD%^The markings upon the underside of the helm seem to shift into "
"understandable words:\n%^RESET%^%^ORANGE%^'Simply call upon the aid of the Loyal Fury, when you are most in "
"need. Torm the True will grant his divine power to the faithful once each day, bestowed as the lion's %^YELLOW%^<roar>%^RESET%^%^ORANGE%^'%^RESET%^");
   tell_room(ETP,"%^WHITE%^%^BOLD%^"+TP->QCN+" reads over the markings upon the underside of the "
"helm.%^RESET%^",TP);
   return 1;
}

int roar_fun() {
   object *inven, *my_party;
   int i;
   if (TP->query_bound() || TP->query_unconscious() || TP->query_paralyzed()) {
     TP->send_paralyzed_message("info",TP);
     return 0;
   }
   if (TP->query_gagged()) {
     return notify_fail(TP->query_gagged_message());
     return 0;
   }
   if(!TO->query_worn()) {
     tell_object(TP,"You should be wearing the helm before you try that.");
     return 1;
   }
   if(timer < time()) {
     timer = time() + 86400;
     tell_object(TP,"%^WHITE%^%^BOLD%^You concentrate upon the power of your god.%^RESET%^");
     message("info","%^WHITE%^%^BOLD%^The sound of a mighty lion's %^YELLOW%^roar%^WHITE%^ echoes throughout "
"the area!%^RESET%^",nearbyRoom(ETP,2));

     inven = ({});
     my_party = ({});
     inven += all_living(ETP);

     for(i=0;i<sizeof(inven);i++) {
       if((string)inven[i]->query_diety() == "torm") { my_party += ({inven[i]}); }
     }
     call_out("roar2_fun",2,TP,my_party);
     return 1;
   }
   tell_object(TP,"%^WHITE%^%^BOLD%^The helm does not respond, you should be careful not to needlessly call "
"upon the power of your Lord too often.");
   return 1;
}

void roar2_fun(object player, object *my_party){
   object ob, *tmp_players;
   int i, time;
   string name;

   name = (string)player->query_name();
   tmp_players = ({});

   for(i=0;i<sizeof(my_party);i++) {
     if(ob = present(my_party[i],environment(player))) {
       if(!objectp(ob)) continue;
       ob->add_saving_bonus("all",1);
       ob->add_attack_bonus(1);
       ob->add_damage_bonus(1);
       ob->add_stat_bonus("strength",1);
       tell_object(ob,"%^WHITE%^%^BOLD%^You feel confidence rush through you!%^RESET%^");
       continue;
     }
     tmp_players += ({my_party[i]});
     continue;
   }

   time = ((int)player->query_highest_level()*10);
   my_party -= tmp_players;
   call_out("reset_player",time,name,my_party);
}

void reset_player(string name, object *players_listen){
   int i;
  
   for(i=0;i<sizeof(players_listen);i++){
     if(!objectp(players_listen[i])) continue;
     tell_object(players_listen[i],"%^WHITE%^%^BOLD%^You feel yourself calm again.%^RESET%^");
     players_listen[i]->add_saving_bonus("all",(-1));
     players_listen[i]->add_attack_bonus((-1));
     players_listen[i]->add_damage_bonus((-1));
     players_listen[i]->add_stat_bonus("strength",-1);
   }
}