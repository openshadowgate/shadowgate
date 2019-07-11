//adapted from comp_vend by Circe
//if something changes here, please check /std/comp_vend
//to see if the changes are needed there as well.

#include <std.h>
#include <money.h>
#include <psi_components.h>
#include <move.h>

#define MAX_COMPONENTS 40
#define COMP_PATH "/d/magic/store_psi_comp"
inherit NPC;

string *Available;
mapping Amount = ([]);

mixed sort_items(object one, object two);
int get_amount(int price);
void sell_comp(int number, int amount);

void create(){
     ::create();
}

void init() {
   ::init();
   add_action("__Buy", "buy");
   add_action("__List", "list");
   add_action("__Help", "help");
}

int __Buy(mixed str) {
   object ob;
   int number, cost;
   string *not_allowed, response;
    not_allowed = ({ "bound", "disabled" });
    if(disabled(TP, not_allowed))  
	return 1;
    if(disabled(TO, not_allowed)){
      write("Do you really expect someone who cannot move to sell you something?");  
	return 1;
    }
   response = "%^MAGENTA%^"+TOQCN+" says:  %^RESET%^";
//   if(!str) return notify_fail("%^BOLD%^Syntax: buy <itemname> || <itemnumber>\n");
   if(!str) return notify_fail("Syntax: buy <itemname> || <itemnumber>\n");
//changed above because return notify_fail seems to mangle color codes.
//Circe 12/23/04
   if(!sscanf(str,"%d",number)) {
      if(member_array(str,Available) == -1) {
	tell_room(ETO, response+"Sorry, I'm afraid I don't have any "+str+".");
	return 1;
      } else {
         number = member_array(str,Available);
      }
      if(Amount[Available[number]] <= 0) {
	tell_room(ETO, response+"Sorry, I'm afraid I don't have any "+str+".");
	return 1;
      }
   }
   if(number > sizeof(Available))
      return notify_fail("There is no crystal number%^BOLD%^ "+number+"\n");
    tell_room(ETO, response+"%^ORANGE%^You'd like to buy some %^BOLD%^"+Available[number]+"%^RESET%^%^ORANGE%^?");

    cost = adjust_cost(PSI_COMPONENTS[Available[number]]);

   tell_room(ETO, response+"%^ORANGE%^How many %^BOLD%^"+Available[number]+"s%^RESET%^%^ORANGE%^ would you like for "+"%^YELLOW%^"+cost+"%^RESET%^%^ORANGE%^ gold apiece?");
   input_to("buy_quantity",0,number);
   return 1;
}

buy_quantity(string str, int number){
   int temp,pgold,cost;
   int cost1;
   object ob;
   string response;

   if(!str) input_to("buy_quantity");
   if((!sscanf(str,"%d",temp)) || (temp < 1)) {
      write("Sale Cancelled");
      return;
   }
   response = "%^MAGENTA%^"+TOQCN+" says:  %^RESET%^";
   if(temp > 100) {
      tell_room(ETO, response+"%^ORANGE%^I cannot sell that many at once.");
      return 1;
   }
   if(temp > Amount[Available[number]]) {
      tell_room(ETO, response+"%^ORANGE%^I don't have that many in stock.  "+
         "I have %^YELLOW%^"+Amount[Available[number]]+" "+Available[number]+" %^RESET%^%^ORANGE%^available right now.");
      temp = Amount[Available[number]];
   }
   cost = adjust_cost(PSI_COMPONENTS[Available[number]]);
   cost1 = cost*temp;
   if(!TP->query_funds("gold",cost1)) {
      if(!TP->query_funds("gold", cost))
         tell_room(ETO, response+"%^ORANGE%^I'm sorry, but you don't have "+
            "enough money for even one "+Available[number]+"!");
      else
         tell_room(ETO, response+"%^ORANGE%^You can only afford %^BOLD%^%^RED%^"+(int)TP->query_gold_equiv()/cost+"%^GREEN%^ " +Available[number]+"'s!");
      return;
   }
   TP->use_funds("gold",cost1);
   tell_room(ETO, response+"%^ORANGE%^Here you are then, %^YELLOW%^"+temp+" "+Available[number]+"s %^RESET%^%^ORANGE%^it is!");
   ob = new(COMP_PATH);
   ob->set_name(Available[number]);
   ob->set_id(({Available[number],"component","crystal","psi_component"}));
   ob->set_short(capitalize(Available[number])+" (a psionic crystal)");
   ob->set_long("             %^BOLD%^" + temp + " " +capitalize(Available[number]) + ". \n" + ob->query_long());
   ob->set_comp_quantity(temp);
   sell_comp(number,temp);
   if((int)(ob->move(TP)) != MOVE_OK ) {
      tell_room(ETO, response+"%^YELLOW%^You cannot carry the crystal.  I will drop it on the floor.");
      ob->move(ETP);
   }
}

int __List(string str) {
   string melnmarn, *not_allowed;
   int inc,lines;
    not_allowed = ({ "disabled" });
    if(disabled(TP, not_allowed))  
	return 1;
   lines = to_int(TP->getenv("LINES"));
   lines -= 2;
   if(!str) return notify_fail("List what?\n");
   if((strsrch(str,"crystal") == -1) && (strsrch(str,"comp") == -1)) return notify_fail("I don't sell those!\n");
   tell_room(ETO, TPQCN+" studies the list of crystals available.", TP);
   Available = sort_array(Available,"sort_strings",TO);
   melnmarn = "%^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-%^RESET%^\n";
   for(inc = 0; inc < sizeof(Available);inc++) {
      melnmarn += sprintf("%3d: ",inc);
      melnmarn += sprintf("%%^GREEN%%^%-35s %%^YELLOW%%^%5d %%^RESET%%^%%^CYAN%%^gold%%^YELLOW%%^%6d %%^RESET%%^%%^CYAN%%^available\n",capitalize(Available[inc]),adjust_cost(PSI_COMPONENTS[Available[inc]]),Amount[Available[inc]]);
      if(((inc+1)%lines == 0) &&(inc > 1)) {
         melnmarn += "%^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-%^RESET%^\n";
         melnmarn += "%^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-%^RESET%^\n";
      }
   }
   melnmarn += "%^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-%^RESET%^\n";
   TP->more(explode(melnmarn,"\n"));
   return 1;
}

string sort_strings(string one,string two) {
   return strcmp(one,two); 
}

int set_components(int total) {
   int inc,temp;
   string *str;
    int number;
   number = total;
   if(!number) return 0;
   if(number < 1) number = 1;
   if(number > MAX_COMPONENTS) number = MAX_COMPONENTS;
   Available = allocate(number);
   str = keys(PSI_COMPONENTS);
   for(inc = 0;inc < number;inc ++) {
      temp = random(sizeof(PSI_COMPONENTS));
      if(member_array(str[temp],Available) == -1) {
         Available[inc] = str[temp];
         Amount[str[temp]] = get_amount(PSI_COMPONENTS[Available[inc]]);
      }
      else {
         inc --;
      }
   }
   return 1;
}

string *query_components() {return Available;}

mixed sort_items(object one,object two) {
   return strcmp(one->query_short(),two->query_short()); 
}

int __Help(string nothing) {
   if(nothing != "shop") return 0;
   tell_room(ETO, TPQCN+" seems to be asking the shopkeeper for help.", TP);
   write(
@MELNMARN
        %^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-%^RESET%^
        %^BOLD%^%^GREEN%^Crystal Shop Help
        %^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-%^RESET%^
        %^RESET%^%^CYAN%^There are 3 commands in the crystals shop. The shopkeeper 
        understands 'help', 'buy' and 'list'. 
        %^BOLD%^%^BLUE%^syntax: %^YELLOW%^'list crystals'
        %^RESET%^%^CYAN%^The list command will list the crystals available in his 
        shop.
        %^BOLD%^%^BLUE%^syntax: %^YELLOW%^'buy <# || name>'
        %^RESET%^%^CYAN%^This will allow you to buy a crystal. You may either enter 
        the item number, or the item name. Once you have made the 
        request to buy an item, you will be asked how many of that 
        crystal you wish to purchase.
        IE: buy 14 (will buy item # 14)
        IE: buy candle (will buy a candle)
        %^BOLD%^%^BLUE%^syntax: %^YELLOW%^'help shop'
        %^RESET%^%^CYAN%^Displays this text.
        %^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-%^RESET%^
MELNMARN
        );
   return 1;
}

int get_amount(int price) {
   return 1+random(100);
}

void sell_comp(int number, int amount) {
   Amount[Available[number]] = Amount[Available[number]] - amount;
   if(Amount[Available[number]] == 0) {
      map_delete(Amount,Available[number]);
      Available -= ({Available[number]});
   }
}
