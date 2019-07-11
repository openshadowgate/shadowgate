//	/adm/simul_efun/ansi.c
//	from the Nightmare mudlib
//	efuns for showing colours
//	created as an independent object by Melvaig@Nightmare
//	modified to be used as simul_efuns by Descartes of Borg
//	24 November 1992

#include <ansi.h>  // ansi.h contains the ansi color codes

string ansi_inventory(object ob);
string ansi_item(object item);
string ansi_str(string item, string def);

string ansi_str(string item, string def) {
/* This used to serve a purpose, but was removed due to being too CPU
   intensive.  Calls to it still exist though.
*/
    return item;
}

string ansi_inventory(object ob) {
    int i, womble;
    object *inv;
    string sh, tmp;

    if(ob && (inv = all_inventory(ob))) {
        for(i=0, sh = "", womble = sizeof(inv); i<womble; i++) {
	    if(inv[i] == previous_object()) continue;
	    if(!(tmp = (string)inv[i]->query_short())) {
		if(living(inv[i]) && !wizardp(inv[i]) &&
		  random(101) < (int)previous_object()->query_level())
			tmp = "A shadow";
	    }
	    if(!tmp) continue;
	    sh += ansi_item(inv[i])+tmp+NOR+"\n";
        }
    }
    else return "";
    return sh;
}

string ansi_item(object item) {
    float per, max, curr;
    string c;

    if(living(item)) {
        curr = to_float((int)item->query_hp());
        max = to_float((int)item->query_max_hp());
        per = (curr/max)*(100.0);
        if(per > 90.0) c = HIR;
        else if(per > 80.0) c = HIM;
        else if(per > 60.0) c = HIC;
        else if(per > 40.0) c = HIG;
        else if(per > 20.0) c = HIY;
        else c = HIW;
    }
    else {
	c=WHT;
	if (item->query_hit_func()) c=MAG;
 	else if (item->query_wc()) c=RED;
        else if (item->query_max_internal_encumbrance()) c=CYN;
        else  if (item->query_ac())  c=GRN;
        else  if (item->query_value()) c=YEL;
    }
    return c;
}

string inverse(string str) { return XCH+str+NOR; }

string bold(string str) { return HIN+str+NOR; }

string underscore(string str) { return ESC+"[4m"+str+NOR; }

string cls() { return ESC+"[H"+ESC+"[2J"; }

string clear_line() { return ESC+"[2K"; }

string cursor_up() { return ESC+"[A"; }

string red(string str) { return RED+str+NOR; }

string blue(string str) { return BLU+str+NOR; }

string green(string str) { return GRN+str+NOR; }

string yellow(string str) { return YEL+str+NOR; }

string cyan(string str) { return CYN+str+NOR; }

string magenta(string str) { return MAG+str+NOR; }
string erase_line() {
    return "\n";
/* hmmmm.... Some terms do not deal well with this one :( 
    return ESC+"]79D                                                                            "+ESC+"]79D";
*/
}

