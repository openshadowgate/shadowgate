//	/std/barkeep.c
//	from the Nightmare mudlib
//	an inheritable vendor of food and drink
//	created by Descartes of Borg October 1992

#include <std.h>

inherit NPC;

string *menu_items;

mapping menu;

string currency;

void set_menu(string *item_names, string *types, int *strengths);
void set_my_mess(string *msg);
void set_your_mess(string *msg);
void set_empty_container(string *empty);
void set_menu_short(string *str);
void set_menu_long(string *str);
void set_currency(string str);
int price(object tp, string strength);
int convert(int cost);
string *query_menu();

void create(){
     ::create();
//     add_dbs(({"barkeep"}));
// this is too spammy for them all, we've added it selectively and/or made specific ones
// *Styx*  12/7/02
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

void set_currency(string str) {
    currency = str;
}

int price(object tp, int strength) {
    int cost;
    cost = to_int(strength);
    if(!tp->query_funds(currency, cost)) return 0;
    tp->use_funds(currency, cost);
    return cost;
}

int convert(int x) {
    if(!x) return 0;
    else return 1+to_int(currency_rate(currency)*x);
}

void set_up_ids(object ob, string myName, string type)
{
    string *tmp;
    if(!objectp(ob)) return;
    ob->set_id(({myName, type}));
    if(stringp(myName))
    {
        tmp = explode(myName, " ");
        tmp -= ({"a", "an", "of", "the"});
        if(sizeof(tmp))
        {
            foreach(string myId in tmp)
            {
                ob->add_id(myId);
                continue;
            }
        }
    }
    return;
}

int buy(string str) {
    int i, cost;
    object ob;
    if(!objectp(TP) || !objectp(TO)) return 0;
    if(!str)
    {
        tell_object(TP, query_cap_name()+" says: What is it you would like?\n");
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
    if(!(cost = price(this_player(), menu[str]["strength"]))) {
	write(query_cap_name()+" says: You do not have enough "+currency+" for that!\n");
	say(query_cap_name()+" turns away "+this_player()->query_cap_name()+" for lack of money.\n", this_player());
	return 1;
    }
    write("You pay "+cost+" "+currency+" coins for a "+str+".\n");
    say(query_cap_name()+" collects some "+currency +" from "+this_player()->query_cap_name()+".\n", this_player());
    if(menu[str]["type"] == "food") {
	ob = new("/std/food");
	ob->set_name(str);
    set_up_ids(ob,str,"food");
    ob->set_value(0);
    }
    else {
	ob = new("/std/food");
	ob->set_name(str);
	ob->set_type(menu[str]["type"]);
	set_up_ids(ob,str,"drink");
    }
    ob->set_strength(menu[str]["strength"]);
    ob->set_weight(1);
    //1/2 RL day + 1/2 RL day from purchase to time it's spoiled
    //consuming when time+random(10000) > spoilTime a chance of getting sick
    i = menu[str]["strength"];
    set("cointype","silver");
    ob->set_value(0);
    ob->set_destroy();
    if(menu[str]["short"]) ob->set_short(menu[str]["short"]);
    else ob->set_short(capitalize(str));
    if(menu[str]["long"]) ob->set_long(menu[str]["long"]);
    else ob->set_long(capitalize(str) + " from "+(string)environment(this_object())->query_short()+".\n");
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

int get_price(string str) {
    int foo;
    foo = menu[str]["strength"];
    return foo;
}

string *query_menu() { return menu_items; }
