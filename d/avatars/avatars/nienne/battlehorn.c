#include <std.h>
inherit ARMOUR;

void create() {
   ::create();
   set_name("battlehorn");
   set_id(({"horn","dwarven horn"}));
   set_short("%^BLACK%^%^BOLD%^battlehorn%^RESET%^");
   set_obvious_short("%^BLACK%^%^BOLD%^battlehorn%^RESET%^");
   set_long("%^CYAN%^This is a horn. Yaaaaaaay.%^RESET%^\n");
   set_lore("%^WHITE%^%^BOLD%^This great horn was crafted by the dwarven warrior Nalthic StoneAxe, on "
"<date>.  It was taken by his own hand from a slain demon, and crafted with ancient dwarven arts.");
   set_property("lore difficulty",15);
   set_weight(2);
   set_value(0);
   set_ac(0);
   set_size(1);
   set_type("ring");
   set_limbs(({"neck"}));
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
   set_language("dwarvish");
   set_read("Blah blah blow the horn, etc.");
}

void init() {
   ::init();
   add_action("blow_fun","blow");
}

int wear_fun() {
   tell_object(ETO,"%^ORANGE%^You drape the horn around your neck on its leather strap.");
   tell_room(EETO,"%^ORANGE%^"+ETOQCN+" drapes the leather strap of the horn around "+ETO->QP+" neck.",ETO);
   return 1;
}

int remove_fun() {
   tell_object(ETO,"%^ORANGE%^You remove the strap of the horn from around your neck.");
   tell_room(EETO,"%^ORANGE%^"+ETOQCN+" lifts the strap of the horn from around "+ETO->QP+" neck.",ETO);
   return 1;
}

int blow_fun(string str) {
   object *inven, *my_party;
   int i;
   string thisparty;
   my_party = ({});
   if (TP->query_bound() || TP->query_unconscious() || TP->query_paralyzed()) {
     TP->send_paralyzed_message("info",TP);
     return 0;
   }
   if (TP->query_gagged()) {
     return notify_fail(TP->query_gagged_message());
     return 0;
   }
   if (!str) {
     notify_fail("What do you want to blow?");
     return 0;
   }
   if (str != "horn" && str != "battlehorn") {
     notify_fail("You can't blow that.");
     return 0;
   }
   if (!TO->query_worn()) {
     tell_object(TP,"You should probably wear that first to secure it.");
     return 1;
   }
   if ((string)TP->query_race() != "dwarf") {
     tell_object(TP,"You can't seem to make sense of how to sound the battlehorn.");
     return 1;
   }
   if (sizeof(TP->query_attackers()) > 0) {
     tell_object(TP,"You can't do that in the middle of a fight!");
     return 1;
   }
   tell_object(TP,"%^BLUE%^You raise the horn to your lips and blow with all your might!%^RESET%^");
   message("info","%^BLUE%^The sound of a great battlehorn echoes throughout the area!%^RESET%^",nearbyRoom(ETP,3));

   inven = ({});
   inven += all_living(ETP);

   if (!TP->query_party()) { my_party += TP; }
   else {
     for(i=0;i<sizeof(inven);i++) {
       if(member_array(inven[i],"daemon/party_d"->query_party_members((string)TP->query_party()) != -1) {
         my_party += ({inven[i]});
       }
     }
   }

   call_out("sound_fun",10,TP,my_party);
   TP->set_paralyzed(30,"You are still blowing the horn!");
   return 1;
}

void sound_fun(object player, object *my_party){
   object ob, *tmp_players;
   int i, time;
   string name;

   name = (string)player->query_name();
   tmp_players = ({});

   for(i=0;i<sizeof(my_party);i++) {
     if(ob = present(my_party[i],environment(player))) {
       if(pointerp(ob->query_property("rally")) && member_array(name,ob->query_property("rally")) != -1)
         continue;
       if(!objectp(ob)) continue;
       ob->add_saving_bonus("all",1);
       ob->add_attack_bonus(1);
       ob->add_stat_bonus("strength",1);
       ob->add_stat_bonus("dexterity",1);
       ob->set_property("rally",({player->query_name()}));
       tell_object(ob,"You feel the fury of battle coming over you!");
       continue;
     }
     tmp_players += ({my_party[i]});
     continue;
   }

   time = ((int)player->query_highest_level()*10);
   my_party -= tmp_players;
   call_out("reset_player",time,name,my_party);
   player->remove_paralyzed();
   tell_object(player,"%^BLUE%^You finish blowing on the great battlehorn%^RESET%^.");
}

void reset_player(string name, object *players_listen){
   int i;
   string *tmp;
  
   for(i=0;i<sizeof(players_listen);i++){
     if(!objectp(players_listen[i])) continue;
     if(!pointerp(players_listen[i]->query_property("rally"))) continue;
     if(member_array(name,players_listen[i]->query_property("rally")) == -1) continue;
        
     tell_object(players_listen[i],"%^BLUE%^You feel the effects of the battlefury wear off.%^RESET%^");
     players_listen[i]->add_saving_bonus("all",(-1));
     players_listen[i]->add_attack_bonus((-1));
     players_listen[i]->add_stat_bonus("strength",-1);
     players_listen[i]->add_stat_bonus("dexterity",-1);
     tmp = players_listen[i]->query_property("rally");
     tmp -= ({name});
     players_listen[i]->remove_property("rally");
     players_listen[i]->set_property("rally",tmp);
   }
}
