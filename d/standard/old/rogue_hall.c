inherit "std/room";

#include <config.h>
#include <council.h>
#include <daemons.h>

string get_new_title(object tp);
string get_male(int lev);
string get_female(int lev);
string previous_title(object tp);
int get_cost(string which, int lev);


void create() {
    object ob;

    ::create();
    set_property("no attack",1);
    set_property("light", 1);
    set_property("indoors", 1);
    set("short", "The heart of the rogue hideout");
    set("long",
	"Welcome into the rogue hideout!\n"+
	"Rogues come here to sharpen their fiendish skills.\n"+
	"The available commands are <cost>, <advance>, <list (number)>, "
	"<train skill amount>, <improve stat> and <roll stats>.  Up "
	"through a stairway guarded by a shimmering %^BLUE%^blue%^RESET%^ "
	"light is the entrance to the fortress. <help skills> will list "
	"all of the full names of skills.");
    set_exits( 
	      (["up" : "/d/standard/rogue_join",
		"east" : "/d/standard/rogue_vote"]) );

    ob = new("std/bboard");
    ob->set_name("board");
    ob->set_id( ({ "board", "rogue board" }) );
    ob->set_board_id("rogue_board");
    ob->set_max_posts(25);
    ob->set_edit_ok(ROGUE_COUNCIL);
    ob->set_location("/d/standard/rogue_hall");
    ob->set("short", "Rogue's Board of Fiendish Plots");
    ob->set("long", "On this rotting wood board, rogues come to post "
	    "of bounties dastardly deeds, and other fiendish foils "
	    "for other rogues to see.\n");
}

void init() {
    ::init();
    add_action("cost","cost");
    add_action("murder", "murder");
    add_action("roll","roll");
    add_action("train", "train");
    add_action("improve", "improve");
    add_action("advance","advance");
    add_action("list","list");
  }

int roll(string str) {
    if(str != "stats") return 0;
    call_other("/d/standard/setter", "do_rolls");
    return 1;
}

string get_new_title(object tp)
{
    int lev;
    string gen, title;

    lev = (int)this_player()->query_level();
    gen = (string)this_player()->query_gender();
    if(this_player()->query_guild()) {
	if(present((string)tp->query_guild()+"_ob", tp)) {
	    if(lev > 19) title = "High mortal";
	    else title = (string)present((string)tp->query_guild()+"_ob", tp)->query_title(tp);
	    title += " $N";
	}
	else {
	    if(lev > 19) title = "High mortal $N";
	    else title = "$N";
	}
    }
    else {
	if(lev > 20) title = "High mortal $N";
	else title = "$N";
    }
    if(lev > 20) title += previous_title(tp);
    else if(gen == "male") title += " "+get_male(lev);
    else title += " "+get_female(lev);
    return title;
}

string get_male(int lev) {
    switch(lev) {
        case 1:  return "the rascal";                break;
        case 2:  return "the little thug";           break;
        case 3:  return "the petty thief";           break;
        case 4:  return "the lurking swindler";      break;
        case 5:  return "the minor rogue";           break;
        case 6:  return "the creeping cutpurse";     break;
        case 7:  return "the nasty thug";            break;
        case 8:  return "the lurking criminal";      break;
        case 9:  return "the devious bandit";        break;
        case 10: return "the fearsome rogue";        break;
        case 11: return "the deceiving fiend";       break;
        case 12: return "the rich swindler";         break;
        case 13: return "the accomplished rogue";    break;
        case 14: return "the corrupt pick-pocket";   break;
        case 15: return "the cunning thief";         break;
        case 16: return "the spiteful con-artist";   break;
        case 17: return "the deceitful backstabber"; break;
        case 18: return "the perpetual thief";       break;
        case 19: return "the grand master rogue";    break;
        case 20: return "the high mortal rogue";     break;
	default: return ""; break;
    }
}

string get_female(int lev) {
    switch(lev) {
	case 8: return "the lesser murderess"; break;
	default: return get_male(lev); break;
    }
}

int advance() { return (int)ADVANCE_D->advance(); }

int train(string str) {
    string which, which_tmp;
    int amount;

    if(sscanf(str, "%s %s %d", which, which_tmp, amount) ==3) which = which + " "+ which_tmp;
    else if(sscanf(str, "%s %d", which, amount) !=2) {
	notify_fail("Correct syntax: <train skill amount>\n");
	return 0;
    }
    which = lower_case(which);
    if(!this_player()->skill_exists(which)) {
	notify_fail("No such skill.\n");
	return 0;
    }
    return (int)ADVANCE_D->train_player(this_player(), which, amount);
}

int improve(string str) {
    string *stats;
    int stat_cost;

    stats = ({ "strength", "intelligence", "wisdom", "dexterity", "constitution", "charisma" });
    str = lower_case(str);
    if(member_array(str, stats) == -1) {
	notify_fail("You have no such stat.\n");
	return 0;
    }
    stat_cost = get_cost(str, (int)this_player()->query_base_stats(str));
    if( (int)this_player()->query_exp()-stat_cost < (int)ADVANCE_D->get_exp( (int)this_player()->query_level() ) ) {
	notify_fail("You are not experienced enough to improve yourself in that way.\n");
	return 0;
    }
    this_player()->set_stats(str, (int)this_player()->query_base_stats(str) + 1);
    this_player()->add_exp(-stat_cost);
    write("You feel much ");
    say(this_player()->query_cap_name()+" looks much ");
    if(str == "strength") tell_room(this_object(), "stronger.\n");
    else if(str == "intelligence") tell_room(this_object(), "more intelligent.\n");
    else if(str == "wisdom") tell_room(this_object(), "wiser.\n");
    else if(str == "dexterity") tell_room(this_object(), "more nimble.\n");
    else if(str == "constitution") tell_room(this_object(), "sturdier.\n");
    else tell_room(this_object(), "more attractive.\n");
    return 1;
}

int get_cost(string stat, int lev) {
    switch(stat) {
  	case "intelligence": return (int)ADVANCE_D->get_stat_cost(1, lev); break;
	case "dexterity": return (int)ADVANCE_D->get_stat_cost(1, lev); break;
	case "charisma": return (int)ADVANCE_D->get_stat_cost(1, lev); break;
  	default: return (int)ADVANCE_D->get_stat_cost(2, lev); break;
    }
}

int cost(string str) {
    int bing;
 
    write("Costs for advancement, training, and improvement:\n");
    bing = (int)ADVANCE_D->get_exp( (int)this_player()->query_level() + 1 );
    if(bing < 1) write("level:\t\tIt will cost you nothing to advance.");
    else write("level:\t\t"+bing+"\n");
    write("skills: You train by spending the amount of experience you
desire.\n");
    write("strength:\t\t" + get_cost("strength",
(int)this_player()->query_base_stats("strength")) +
"\t\tconstitution:\t\t" + get_cost("constitution",
(int)this_player()->query_base_stats("constitution")) );
    write("intelligence:\t\t" + get_cost("intelligence",
(int)this_player()->query_base_stats("intelligence")) +
"\t\tdexterity:\t\t" + get_cost("dexterity",
(int)this_player()->query_base_stats("dexterity")) );
    write("wisdom:\t\t" + get_cost("wisdom",
(int)this_player()->query_base_stats("wisdom")) +
"\t\tcharisma:\t\t" + get_cost("charisma",
(int)this_player()->query_base_stats("charisma")) );
    return 1;
}
string previous_title(object tp) {

    string pre, post, str;

    str = (string)tp->getenv("TITLE");
    sscanf(str, "%s $N %s", pre, post);
    return post;
}

int list(string str) {
    int x;

    if(!str) "/d/standard/quest_room"->list_quests(this_player(), 0);
    else {
	if(sscanf(str, "%d", x) != 1) {
	     notify_fail("You must give the number of the quest you want listed.\n");
	    return 0;
	}
	if(x<1) {
	    notify_fail("No such quest.\n");
	    return 0;
	}
	"/d/standard/quest_room"->list_quests(this_player(), x);
    }
    return 1;
}

int murder() {
    if(this_player()->query_skill("murder")) return 0;
    this_player()->add_skill("murder", 3, 100);
    write("Done.\n");
    return 1;
}

