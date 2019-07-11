// Offline Simul-efuns
// Gets the player object for those pesky people who are not logged in
// when you need them to be.
// Thorn@ShadowGate -- 950606
// Based on code by Melnmarn for _players.c

#include <std.h>
#include <objects.h>
#include <dirs.h>
#include <daemons.h>
#include <config.h>

inherit OB_USER;

object get_player_object(string str);
object *get_all_player_objects(string str);

void create() {
	::create();
}

string *list_all_players(string str) {
    int debug;
    string *players,name,who,*alpha,melnmarn,lastcall,party;
    object ob, offline;
    string *player_names;
    int total,inc,level,line,my_level;
    string month,temp;
    int day,year,plines,hold;
    mapping play;

        player_names = ({});
        if(str == "debug") debug = 1;
        hold = to_int(TP->getenv("LINES"));
        plines = (hold > 0) ? hold - 3 : 17;
        play = ([]);
        alpha = ({"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o",
        "p","q","r","s","t","u","v","w","x","y","z" });
        players = get_dir("/adm/save/users/" + alpha[0] + "/*.o");
        for(inc = 1; inc < sizeof(alpha);inc ++){
                if(get_dir("/adm/save/users/" + alpha[inc] + "/*.o") == 0 )
                        continue;
                players += get_dir("/adm/save/users/" + alpha[inc] + "/*.o");
        }
        total = sizeof(players);
        line = 0;
        for(inc = 0;inc < total;inc++){
                sscanf(players[inc],"%s.o",name);
                if(debug == 1) write("Trying .....'"+name+"'!");
                who = sprintf("%s/%s/%s", "/adm/save/users", name[0..0], name);
                ob = find_player(name);
                if(!ob) {
			offline = TO;
                        offline->restore_object(who);
			temp = (string)offline->query_name();
                        player_names += ({ temp });
                }
                else player_names += ({ (string)ob->query_name() });
        }
        return player_names;
}


