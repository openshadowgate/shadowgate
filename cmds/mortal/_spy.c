//Adjusted by Circe 6/4/07 so you cannot use blind
#include <move.h>
#include <std.h>
inherit DAEMON;

int cmd_spy(string str) {
    int check,silly;
    object ob;
    
    if(!str) {
    	notify_fail("Spy who?\n");
    	return 0;
    }

    if(TP->query_ghost()) {
        notify_fail("You cannot do that in your immaterial state.\n");
        return 0;
    }
//below added by Circe
    if (TP->query_blind()) {
        notify_fail("You are blind and cannot see anything.\n");
        return 0;
    }
    if (silly=TP->light_blind(0)) {
        notify_fail(TP->light_blind_fail_message(silly)+"\n");
        return 0;
    }
//end Circe's addition
    if(ETP->query_property("no steal")) {
        notify_fail("A magic force prevents you from doing that.\n");
        return 0; 
    }

    if(TP->query_current_attacker()) {
        notify_fail("You can't do that while in combat!\n");
        return 0;
    }

    ob = present(str, ETP);
    
    if(!ob) ob = parse_objects(ETP, str);

    if(!ob) {
        notify_fail("No "+str+" here!\n");
        return 0;     
    }
    
    if((ob->query_hidden() || ob->query_magic_hidden()) && !TP->detecting_invis()) {
        return notify_fail("No "+str+" here!\n");
    }
    
    if(!living(ob)) {
	    notify_fail("Don't you feel silly?!?\n");
	    return 0;
    }

    if(wizardp(ob) && ob->query_invis()){
        notify_fail("No "+str+" here!\n");
        return 0;                                                              
    }

    if(wizardp(ob)){
        return notify_fail("This gonna get you killed!\n");
    }

    if(ob->is_player() && !interactive(ob)) return 0;

    if(ob==TP) {
        notify_fail("You stubborn fool, that is stupid to do!\n");
        return 0;
    }

    if(!TP->is_class("thief") && !TP->is_class("bard")){
        notify_fail("You are not trained in such stealthy ways.\n");
        return 0;
    }

//    if(TP->query_lowest_level()<6 && interactive(ob)){
//        notify_fail("You haven't learned enough to try that yet.\n");
//        return 0;
//    }
    
    if(!wizardp(this_player())) {
        check = (int)TP->query_skill("stealth") + roll_dice(1,20);
    } else {
        check = 100;
    }

    if(20 > check) {
	    message("mine",
	        "%^BOLD%^%^CYAN%^You fail to view "+ob->query_cap_name()+"'s "
	        "possessions.%^RESET%^"
	    ,this_player());
	    
        message("ob",
	        "%^BOLD%^%^CYAN%^You notice "+this_player()->query_cap_name()+" admiring "
	        "your shiny possessions.%^RESET%^"
	    ,ob);
	    
        message("env",
	        "%^BOLD%^%^CYAN%^You notice "+this_player()->query_cap_name()+" admiring "
	        +ob->query_cap_name()+"'s possessions.%^RESET%^"
	    ,environment(this_player()),({this_player(),ob}));
        return 1;
    }

	message("mine",
	    "%^BOLD%^%^CYAN%^Unknown to "+ob->query_cap_name()+", "
	    "you survey "+ob->query_possessive()+" possessions.%^RESET%^"
	,this_player());

    /*if(ob->id(str)) {
        if(this_player()->query_ansi())
            write(ansi_str( (string)ob->query_long(str) ));
        else
            write((string)ob->query_long(str));
        return 1;
    }*/

    //Less code and should do exactly the same thing.... Saide

    if(ob = present(str,ob) || ob = present(str,TP) 
    || ob = present(str,ETP) || ob->id(str)) {
        if(this_player()->query_ansi())
            write(ansi_str( (string)ob->query_long(str) ));
        else
          write((string)ob->query_long(str));
          return 1;
    }
    
    //What in the world??
    /*ob = present(str, this_player());
    if(ob) {
        if(this_player()->query_ansi())
            write(ansi_str( (string)ob->query_long(str) ));
        else
          write((string)ob->query_long(str));
          return 1;
    }*/   

    write("%^BOLD%^%^RED%^You fail to glimpse anything!%^RESET%^");
    return 1;
}

void help() {
  write("Syntax: <spy [living]>\n\n"+
        "Allows the thief to survey their victim's possessions undetected.\n");
}


