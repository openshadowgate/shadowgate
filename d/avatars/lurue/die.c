#include <std.h>

inherit OBJECT;

int number,loaded;
int *shave;

void create()
{
	::create();

    	set_name("6 sided die");
    	set_id(({"die","dice","6-sided dice"}));
    	set_short("six-sided die");
    	set_long("This is a carved cube made of animal bone.  There are "+
	"six sides, each with dots carved into it, they number one "+
	"through six.");	
    	number = 1;
    	set_value(2);
    	set_weight(2);
	set_property("lore difficulty", 5);
	set_lore("This six sided bone die was once the property of a man known "+
	"as Naramis.  What might have befallen him is something lost to the annuals "+
	"of history.  It is believed that he had some way to "+
	"%^RED%^prepare%^RESET%^ the die before he rolled it "+
	"and some means to %^RED%^check%^RESET%^ and %^RED%^"+
	"clear%^RESET%^ it so that it's true nature might "+
	"not be easily discerned.  Perhaps in the end "+
	"his methods failed him.");
}

string query_short(){
    string sshort;
    sshort = ::query_short();
    if(!living(ETO)) {
        sshort += ", %^CYAN%^<"+number+">%^RESET%^%^BOLD%^%^MAGENTA%^ up%^RESET%^";
    }
    return sshort;
}

init(){
    ::init();

    	add_action("roll","roll");
	add_action("load","prepare");
	add_action("clear","clear");
	add_action("check","check");
	
}

int check(string str) {
	if(!str) return 0;
	if(str == "die") 
	{
		if(loaded == 1) {
			write("You check your die and determine it "+
			"will always land with %^CYAN%^" +number+ "%^RESET%^ up.");
			return 1;
		}
		if(loaded == 0) {
			write("You check your die and realize you can't "+
			"tell which number will land up.");
			return 1;
		}
	}
	else {
		return 0;
	}

}

int clear(string str) 
{
	if(!str) return 0;
	if(str == "die") 
	{
		if(loaded == 1) {
			write("You fiddle with your die and even "+
			"it out, letting fate once again determine the "+
			"number on which it will land.");
   			if(!ETO->query_invis()) 
			{
   				tell_room(EETO,ETO->QCN+
				" rolls "+ETO->QP+	
				" die idly between "+ETO->query_possessive()+ " fingers.",ETO);
   			}
			loaded = 0;
			return 1;
		}
		if(loaded == 0) {
			write("There is no need to do that.");
			return 1;
		}

	}
	else 
	{
		return 0;
	}

}


int load(string str,string what,string amount) {
	int x;
	string *people;
	if(!str) return 0;
	if(sscanf(str,"%s %s",what,amount)) 
	{
		if(amount != "1" && amount != "2" && 
		amount != "3" && amount != "4" && 
		amount != "5" && amount != "6") 
		{
			write("You may prepare the die to land on a number 1 - 6");
			return 1;
		}
		loaded = 1;
		number = amount;
		write("You prepare the die, making sure it will land on " +amount);
		people = all_living(EETO);
  		people -= ({ETO});
		if(!ETO->query_invis()) 
		{
			for(x = 0;x < sizeof(people);x++) 
			{
				if(random(31) + 1 <= people[x]->query_stats("wisdom")) 
				{
     					tell_object(people[x],"You notice " + 
					ETO->query_cap_name() + 
					" suspiciously touching " + 
					ETO->query_possessive() + 
					" die!%^RESET%^");
     					continue;
				}
			}
		}
   
		return 1;
	}
	tell_object(ETO,"You want to try to prepare the die?");
 	return 1;
}


int roll(string str)
{
 	if(ETO != TP || !id(str))
	{
  		return notify_fail("Roll what?\n");
 	}
 
 	tell_room(ETP, TPQCN+" throws the dice out and watches them roll",TP);
 	tell_object(TP,"You throw the dice out and watch them roll.");

	if(loaded == 0) 
	{
		number = random(6)+1;
	}
	
 	tell_room(ETP,"The die rolls, and stops with "+number+" up.");
 	move(ETP);
	loaded = 0;
 	return 1;
}
