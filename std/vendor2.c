//      /std/shop.c
//      a standard object that sells things in shops
//      created by Melnmarn @ ShadowGate

//	This file has been changed by Melnmarn@ShadowGate
//	Do *NOT* alter this file without permission from
//	Melnmarn or Aragorn @ Shadowgate!

#include <std.h>
#include <money.h>

#define MAX_ITEMS 50

inherit "/std/townsman";

mapping __Eco, __Values;

static int __SellAll();
int convert_money(string cointype,int amount);
mixed sort_items(object one, object two);
int check_allowed(object ob);
string types(object ob);

void init() {
   ::init();
   //add_action("__Buy", "buy");
   //add_action("__Sell", "sell");
   add_action("__Show", "show");
   add_action("__List", "list");
   //add_action("__Value", "value");
   add_action("__Help", "help");
   add_action("inventory", "inventory");
}

void heart_beat() {
   ::heart_beat();
}

void create() {
   ::create();
   __Eco = ([]);
   __Values = ([]);
}

int __Buy(string str) {
   object ob;
   string tmp;
   int cost, x;
   string cointype;

   if(!str) {
      write("Try 'buy <item> [#]'!");
      return 1;
   }
   if(!should_interact(TP)) {
      force_me("emote looks at you with disdain.");
      force_me("say leave my shop, scum, I will not serve you.");
      return 1;
   }
   if(!__Eco["storage object"]) {
      __Eco["storage object"] = find_object_or_load(__Eco["storage file"]);
   }
   if(!(ob = present(str, __Eco["storage object"])) && !(ob = parse_objects(__Eco["storage object"]))) {
      write("I don't have any "+str+"s to sell you!");
      return 1;
   }
   cost = (int)ob->query("value");
   if(ob->query_property("enchanted"))
      cost = cost * query_property("enchantment");
   cointype = (string)ob->query_cointype();
   if((int)this_player()->query_money(cointype) < cost) {
      convert_money(cointype,cost);
      if((int)this_player()->query_money(cointype) < cost) {
         write(TPQCN+", you don't have enough money!");
         write("You need "+cost+" "+ob->query_cointype()+".");
         return 1;
      }
   }
   if(ob->is_plate()) {
      if((int)TP->query_level() < 7) {
         write("The shop refuses by orders of the King to sell that item to someone as inexperienced as yourself!");
         return 1;
      } else {
         ob->check_plate(TP,ob);
         write("The armor is fitted to your body size and shape.");
      }
   }
   write("Here is your "+str+" for "+cost+" "+ob->query_cointype()+"!");
   message("other_action", query_cap_name()+" hands "+TPQCN+" "+(string)ob->query_short()+".", ETO, ({ TP,TO}));
   message("other_action", query_cap_name()+" hands you "+(string)ob->query_short()+".", TP);
   TP->add_money(ob->query_cointype(), -cost);
   if(ob->move(TP)) {
      message("my_action", "You drop it as fast as you get it!", TP);
      message("other_action", TPQCN+" drops "+(string)ob->query_short()+".", ETO,({ TP}));
      ob->move(ETO);
   }
   return 1;
}

int convert_money(string cointype,int cost) {
   int cp,sp,ep,gp,pp;
   int ocp,osp,oep,ogp,opp;
   int fail_flag;

   cp = (int)this_player()->query_money("copper");
   sp = (int)this_player()->query_money("silver");
   ep = (int)this_player()->query_money("electrum");
   gp = (int)this_player()->query_money("gold");
   pp = (int)this_player()->query_money("platinum");
   ocp=cp;osp=sp;oep=ep;ogp=gp;opp=pp;
   fail_flag = 0;

   this_player()->add_money("copper",-cp);
   this_player()->add_money("silver",-sp);
   this_player()->add_money("electrum",-ep);
   this_player()->add_money("gold",-gp);
   this_player()->add_money("platinum",-pp);

   if(cointype == "copper") {
      do {
         if(sp > 0) {cp += 10;sp -= 1;} else if(ep > 0) {cp += 10;sp += 4;ep -= 1;} else if(gp > 0) {cp += 10;sp += 4;ep += 1;gp -= 1;} else if(pp > 0) {cp += 10;sp += 4;ep += 1;gp += 4;pp -= 1;} else if(cp < cost) {fail_flag = 1;break;}
      }while( cp < cost);
   } else if(cointype == "silver") {
      do {
         if(cp > 10) {sp += cp/10;cp = cp%10;} else if(ep > 0) {sp += 5;ep -= 1;} else if(gp > 0) {sp += 5;ep += 1;gp -= 1;} else if(pp > 0) {sp += 5;ep += 1;gp += 4;pp -= 1;} else if(sp < cost) {fail_flag = 1;break;}
      }while( sp < cost);
   } else if(cointype == "electrum") {
      do {
         if(cp > 10) {sp += cp/10;cp = cp%10;} else if(sp > 5) {ep += sp/5;sp = sp%5;} else if(gp > 0) {ep += 2;gp -= 1;} else if(pp > 0) {ep += 2;gp += 4;pp -= 1;} else if(ep < cost) {fail_flag = 1;break;}
      }while( ep < cost);
   } else if(cointype == "gold") {
      do {
         if(cp > 10) {sp += cp/10;cp = cp%10;} else if(sp > 5) {ep += sp/5;sp = sp%5;} else if(ep > 2) {gp += ep/2;ep = ep%2;} else if(pp > 0) {gp += 5;pp -= 1;} else if(gp < cost) {fail_flag = 1;break;}
      }while( gp < cost);
   }

   else if(cointype == "platinum") {
      do {
         if(cp > 10) {sp += cp/10;cp = cp%10;} else if(sp > 5) {ep += sp/5;sp = sp%5;} else if(ep > 2) {gp += ep/2;ep = ep%2;} else if(gp > 5) {pp += gp/5;gp = gp%5;} else if(pp < cost) {fail_flag = 1;break;}
      }while( pp < cost);
   }

   if(fail_flag) {
      this_player()->add_money("copper",ocp);
      this_player()->add_money("silver",osp);
      this_player()->add_money("electrum",oep);
      this_player()->add_money("gold",ogp);
      this_player()->add_money("platinum",opp);
      return 1;
   } else {
      this_player()->add_money("copper",cp);
      this_player()->add_money("silver",sp);
      this_player()->add_money("electrum",ep);
      this_player()->add_money("gold",gp);
      this_player()->add_money("platinum",pp);
      return 1;
   }
}

int __Sell(string str) {
   object ob;
   string tmp;
   int value;

   if(!str) {
      write("Try 'sell <object>'!");
      return 1;
   }
   if(!should_interact(TP)) {
      force_me("emote looks at you with disdain.");
      force_me("say leave my shop, scum, I will not serve you.");
      return 1;
   }
   if(!__Eco["storage object"])
      __Eco["storage object"] = find_object_or_load(__Eco["storage file"]);
   if(sizeof(all_inventory(__Eco["storage object"])) >= MAX_ITEMS) {
      write("Sorry, I can't get rid of what I have now!");
      return 1;
   }
   if(!(ob = present(str, TP))) {
      write("You don't have any "+str+" to sell!");
      return 1;
   }
   if(check_allowed(ob) == 0) {
      write("Sorry, I don't deal in "+str+"s!");
      return 1;
   }
   if(!(value = (int)ob->query("value"))) {
      write("That "+str+" is worthless.");
      return 1;
   }
   if(ob->query_worn()) {
      write("Please remove that before selling it.\n");
      return 1;
   }
   if(ob->query_wielded()) {
      write("Please unwield that before selling it.\n");
      return 1;
   }
   if(member_array("Iron Fist",TP->query_guild()) < 0)
      value = value - (value/5);
   TP->add_money(ob->query_cointype(), value);
   message("other_action", TPQCN+" sells "+(string)ob->query_short()+".", ETO,({ TP}));
   message("my_action", "You sell "+(string)ob->query_short()+" for "+value + " " +ob->query_cointype()+".", TP);
   if(ob->query_destroy()) ob->remove();
   else {
      ob->move(__Eco["storage object"]);
      return 1;
   }
   if(ob) destruct(ob);
   return 1;
}

int __Show(string str) {
   object ob;

   if(!str) {
      write("Try 'show <object>'.");
      return 1;
   }
   if(!__Eco["storage object"])
      __Eco["storage object"] = find_object_or_load(__Eco["storage file"]);
   if(!(ob = present(str, __Eco["storage object"])) &&
      !(ob = parse_objects(__Eco["storage object"]))) {
      write("I don't have a "+str+" to show you.");
      return 1;
   }
   message("other_action", query_cap_name()+" shows you "+(string)ob->query_short()+".", TP);
   message("info", (string)ob->query_long(), TP);
   return 1;
}

int __List(string str) {
   object *inv;
   string *tmp;
   int i, x;

   while(!__Eco["storage object"]) {
      __Eco["storage object"] = find_object_or_load(__Eco["storage file"]);
   }
   i = sizeof(inv = filter_array(all_inventory(__Eco["storage object"]), "filter_list", TO, str));
   if(!i) {
//__Eco["storage object"]->reset();
      i = sizeof(inv = filter_array(all_inventory(__Eco["storage object"]),"filter_list", TO, str));
      if(!i) {
         write("I have nothing like that to sell.");
         return 1;
      }
   }
   inv = sort_array(inv,"sort_items",TO);
   write("%^YELLOW%^ Description			  Cost			 Type");
   write("%^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
   for(x=0, tmp = ({}); x<i; x++) {
      if(inv[x]->is_armour() || inv[x]->is_weapon()) {
         tmp +=({sprintf("%%^BOLD%%^%%^GREEN%%^%-30s %%^YELLOW%%^ %-5s",
                         inv[x]->query_short(), types(inv[x]))});
        // tmp +=({sprintf("%%^BOLD%%^%%^GREEN%%^%-30s %%^YELLOW%%^%4d %%^WHITE%%^%-20s %-5s",
       //                 inv[x]->query_short(),inv[x]->query_value(),inv[x]->query_cointype(), types(inv[x]))});
      } else {
         tmp +=({sprintf("%%^BOLD%%^%%^GREEN%%^%-30s ",
                         inv[x]->query_short())});
       //  tmp +=({sprintf("%%^BOLD%%^%%^GREEN%%^%-30s %%^YELLOW%%^%4d %%^WHITE%%^%s",
       //                  inv[x]->query_short(),inv[x]->query_value(),inv[x]->query_cointype())});
      }
      if(( ( x%17 ) == 0 ) && ( x > 15 ) ) {
         tmp += ({"%^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="});
         if(x == 17) tmp += ({" "});
         tmp += ({"%^YELLOW%^ Description			  Cost			 Type"});
         tmp += ({"%^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="});
      }
   }
   tmp += ({"%^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="});
   TP->more(tmp);
   return 1;
}

int __Value(string str) {
   object ob;
   string tmp, cn;
   int value;

   if(!str) {
      write("Try 'value <object>'.");
      return 1;
   }
   if(!should_interact(TP)) {
      force_me("emote looks at you with disdain.");
      force_me("say leave my shop, scum, I will not serve you.");
      return 1;
   }
   if(!(ob = present(str, TP))) {
      write("You don't have a "+str+"!");
      return 1;
   }
   if(check_allowed(ob) == 0) {
      write("Sorry, I don't deal in "+str+"s!");
      return 1;
   }
   message("other_action", TPQCN+" asks for an appraisal.", ETO, ({TO,TP}));
   if(!(value = (int)ob->query("value"))) {
      write("That "+str+" is worthless!");
      return 1;
   }
   if(member_array("Iron Fist",TP->query_guild()) < 0)
      value = value - (value/5);
   write(TPQCN+", I will offer you "+value+" "+ob->query_cointype()+" for it.");
   return 1;
}

int filter_list(object ob, string str) {
   if(!str || str == "") return 1;
   switch(str) {
   case "weapon":
   case "weapons": return(int)ob->is_weapon();
   case "armor":
   case "armour":
   case "armors":
   case "armours": return(int)ob->is_armour();
   case "bag":
   case "bags": return(int)ob->is_bag();
   case "other": return(!((int)ob->is_weapon()) && !((int)ob->is_armour()));
   default: return((string)ob->query_type() == str || ob->id(str));
   }
   return 0;
}

static int __SellAll() {
   object *inv;
   int i, value;
   int cp,sp,ep,gp,pp;
   string tmp;

   cp=0;sp=0;ep=0;gp=0;pp=0;
   if(!(i = sizeof(inv = all_inventory(TP)))) {
      write("You don't have anything to sell!");
      return 1;
   }
   while(i--) {
      if(check_allowed(inv[i]) == 0) {
         write("Sorry, I don't deal in those things!");
         continue;
      }
      if(!(value = (int)inv[i]->query("value"))) {
         write((string)inv[i]->query_short()+" is worthless.");
         continue;
      }
      if(member_array("Iron Fist",TP->query_guild()) < 0)
         value = value - (value / 5);
      switch((string)inv[i]->query_cointype()) {
      case "platinum":pp += value;break;
      case "gold"    :gp += value;break;
      case "electrum":ep += value;break;
      case "silver"  :sp += value;break;
      case "copper"  :cp += value;break;
      }
      TP->add_money(inv[i]->query_cointype(), value);
      message("my_action", "You sell "+(string)inv[i]->query_short()+" for "+value+" "+inv[i]->query_cointype()+".",TP);
      message("other_action", TPQCN+" sells "+(string)inv[i]->query_short()+".", ETO, ({ TP}));
      if(inv[i]->query_destroy()) inv[i]->remove();
      else inv[i]->move(__Eco["storage object"]);
   }
   write("\nWell, let's see here. That comes to:\n");
   if( pp > 0) write(" Total Platinum :"+pp+" pp");
   if( gp > 0) write(" Total Gold     :"+gp+" gp");
   if( ep > 0) write(" Total Electrum :"+ep+" ep");
   if( sp > 0) write(" Total Silver   :"+sp+" sp");
   if( cp > 0) write(" Total Copper   :"+cp+" cp");
   write("\nThank you for your business!");
   return 1;
}

mixed sort_items(object one,object two) {
   return strcmp(one->query_short(),two->query_short()); 
}

void set_storage_room(string str) {
   __Eco["storage object"] =find_object_or_load(__Eco["storage file"] = str);
   __Eco["storage object"]->set_property("no teleport",1);
}

object query_storage_room() {return __Eco["storage object"];}

void set_items_allowed( string str) {
   set("items_allowed",str);
}

string query_items_allowed() {
   if(!this_object()->query("items_allowed"))
      this_object()->set_items_allowed("all");
   return this_object()->query("items_allowed");
}

int check_allowed(object ob) {
   if(strcmp("all",(string)this_object()->query_items_allowed()) == 0)
      return 1;
   if(strcmp("misc",(string)this_object()->query_items_allowed()) == 0) {
      if(ob->is_weapon()) return 0;
      if(ob->is_armour()) return 0;
      if(member_array("potion",ob->query_id(),0) != -1) return 0;
      if(member_array("pet",ob->query_id(),0) != -1) return 0;
      if(member_array("food",ob->query_id(),0) != -1) return 0;
      if(member_array("drink",ob->query_id(),0) != -1) return 0;
      if(member_array("tobacco",ob->query_id(),0) != -1) return 0;
      return 1;
   }
   if(strcmp("armor",(string)this_object()->query_items_allowed()) == 0) {
      if(ob->is_armour()) return 1;
      else return 0; 
   }
   if(strcmp("weapon",(string)this_object()->query_items_allowed()) == 0) {
      if(ob->is_weapon()) return 1;
      else return 0; 
   }
   if(member_array((string)this_object()->query_items_allowed(),ob->query_id(),0) == -1)
      return 0;
   return 1;
}

void __Help(string str) {
   if(!str) return;
   if(strcmp("shop",str) != 0) return;
   this_player()->more("/std/shop.help");
   return 1;
}

void inventory() {
   object *inv;
   int i, value;
   string tmp;

   if(!(i = sizeof(inv = all_inventory(TP)))) {
      write("You don't have anything!");
      return 1;
   }
   write("%^CYAN%^The shop clerk looks over your inventory.");   
   while(i--) {
      tmp = "";
      if((check_allowed(inv[i]) == 0)||(!(value = (int)inv[i]->query("value")))) {
         if((string)inv[i]->query_short() == "") continue;
         tmp += arrange_string((string)inv[i]->query_short(),46);
         tmp += "0    -----";
         write(tmp);
         continue;
      }
      if(member_array("Iron Fist",TP->query_guild()) < 0)
         value = value - (value / 5);
      tmp += arrange_string((string)inv[i]->query_short(),46);
      tmp += arrange_string(value,6);
      tmp += (string)inv[i]->query_cointype();
      write(tmp);
   }
   return 1;
}

string types(object ob) {
   string type;
   string ret;

   type = ob->query_type();
   switch(type) {
   case "thiefslashing":
   case "thiefpiercing":
      ret = "thief";
      break;
   case "bludgeon":
      ret = "cleric";
      break;
   case "magepiercing":
   case "magebludgeon":
      ret = "mage";
      break;
   default:
      if(ob->is_weapon())
         ret = "fighter";
      else
         ret = type;
   }
   return ret;
}

int is_vendor() { return 1; }