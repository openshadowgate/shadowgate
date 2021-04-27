#include <std.h>
#include <daemons.h>
inherit WEAPON;

void throwing(object tp, int num);

void create() {
    	::create();
    	set_id(({ "snowball" }));
    	set_name("snowball");
    	set_short("%^BOLD%^%^WHITE%^snowball%^RESET%^");
    	set_weight(5);
    	set_long("%^BOLD%^%^WHITE%^"+
    		"This is a lump of snow formed into an irregular sphere, but it looks "+
    		"basically aerodynamically sound.  Knowing the person that threw it at "+
    		"you it probably has a rock on the inside."+
    		"%^RESET%^"
    	);
    	set_value(0);
}
void init(){
::init();
	add_action("fling_em","fling");
}
int fling_em(string str) {
	object ob;
	if(!str) {
       	notify_fail("What?\n");
        	return 0;
    	}
	ob = find_player(str);
    	if(!ob) {
        	notify_fail("That person is nowhere to be found!\n");
        	return 0;
    	}
     	throwing(ob,0);
    	return 1;
}
void throwing(object tp,int num){
     	object vic;
     	vic = tp;
     	switch(num){
      	case(0):tell_object(TP,"You give the snowball a mighty heave and "+
      			"stand back to watch the fun.\n");
      		tell_room(environment(vic),"%^BOLD%^%^WHITE%^You hear a distant "+
      			"whistling sound. \n");
                  break;
            case(1):tell_room(environment(vic),"%^BOLD%^%^WHITE%^The whistling grows "+
				"louder.\n");
			break;
            case(2):tell_room(environment(vic),"%^BOLD%^%^CYAN%^"+TPQCN+" recoils as "+
            		"a shiny white snowball comes flying out of nowhere and "+
            		"smacks into their face.\n%^RESET%^",vic);
            	tell_object(tp,"%^BOLD%^%^WHITE%^A snowball comes "+
            		"flying out of nowhere and splats against the side of your face.\n");
                  //tp->force_me("emote recoils as a snowball flies in hard and cold.");
			break;
            case(3):tell_object(vic,"%^BOLD%^%^BLUE%^Ice cold snow "+
            		"dribbles down your face, under your collar and freezes "+
            		"you inside your shirt.\n");
            	tp->force_me("emote shivers uncontrollably for a moment");
                  break;
            case(4):tell_room(environment(vic),"%^BOLD%^%^BLUE%^Demonic laughter can "+
            		"be heard in the distance.\n");
            	tell_object(TP,"%^BOLD%^%^WHITE%^You smile with satisfaction "+
            		"knowing another good deed has been done.\n%^RESET%^");
	      	TO->move(vic);
                	return;
    	}
    	num++;
    	call_out("throwing",0,vic,num);
    	return;
}
