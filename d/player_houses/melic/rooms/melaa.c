//Coded by Diego//

#include <std.h>
#include "../melic.h"
inherit VAULT;

void worshipping(object tp, int num);
void desecrating(object tp, int num);
int FLAG;

void create(){
    ::create();
   set_terrain(BUILT_TUNNEL);
   set_travel(PAVED_ROAD);
    set_short("Altar room");
    set_long(
    "%^BOLD%^%^RED%^"+
    "A large altar made out of a single block of %^BOLD%^%^BLACK%^obsidian%^RED%^ is set "+
    "against the west wall.  Atop the altar stands 2 lit candles.  Candles are also placed "+
    "all around the room along with censers burning fragrant incense.  The incense is "+
    "quite thick in the air and makes you feel somewhat dizzy.  Light flows from the "+
    "high windows adding further illumination to the room.  The room is otherwise plain "+
    "and clean.\n"+
    "%^RESET%^"
    );
    set_property("indoors",1);
    set_property("light",2);
    set_smell("default","Your nose is filled with the smell of the incense.");
    set_listen("default","It is quiet.");
    set_items(([
	"altar":"The altar is made out of a single huge, smooth block of %^BOLD%^%^BLACK%^"+
		"obsidian%^RESET%^.  There are no symbols, markings or scratches of any kind "+
		"and the surface is very clean.  Atop the altar stand 2 lit candles.",
	({"candles","candle"}):"Placed about the room, the lit candles provide "+
		"subtle lighting",
	({"censer","censers"}):"Metal bowls on stands placed about the room to hold the "+
		"burning incense."
	]));

    set_door("door",MROOMS+"mel6","east","mithril key");
    set_door_description("door","A normal %^ORANGE%^wooden%^RESET%^ door.");
    set_string("door","open","The door swings open allowing you back into the hallway.\n");

    set_exits(([
	"east" :MROOMS+"mel6"
    ]));
}
void init(){
    ::init();
    add_action("worship","worship");
    add_action("desecrate","desecrate");
}
int worship(string str) {
    if (str == "malar")
        	{TP->set_paralyzed(5000,"You are worshipping and unable to do that!");
        	worshipping(TP,0);
        	return 1;}
        else
        	{tell_object(TP,"%^BOLD%^%^BLACK%^Growling and snarling claw at the corners of "+
        		"your mind.\n"+
        		"The candles flare brightly then wink out as one.\n"+
        		"The room grows cold suddenly and you feel a strong urge to "+
			"leave.%^RESET%^\n");
        	tell_room(ETP,"%^BOLD%^%^BLACK%^"+TPQCN+" bows down to pray.  The candles "+
        		"flare brightly and then wink out at the same time and the room grows "+
			"suddenly and noticeably cooler.%^RESET%^",TP);
	  	set_property("light",0);
        	return 1;}
}
int desecrate(string str) {
    	if (str == "altar"){
    		TP->set_paralyzed(5000,"You are doing unspeakable things to the altar "+
    			"and unable to do that!");
        	desecrating(TP,0);
        	return 1;
  	}
}
void desecrating(object tp,int num){
            switch(num){
                case(0):tell_object(TP,"%^BOLD%^%^BLACK%^Growling and snarling claw "+
                			"at the corners of your mind.\n"+
        				"The candles flare brightly then wink out as one.\n"+
        				"The room grows cold suddenly and you feel a strong urge to "+
					"leave.%^RESET%^\n");
				tell_room(ETP,"%^BOLD%^%^RED%^The room is filled with noise "+
					"and wind suddenly and the candles flare the go out as "+
					"one. \n",TP);
                        break;
                case(1):tell_room(ETP,"%^BOLD%^%^RED%^The room is filled with a "+
                			"howling that builds to such a crescendo that you are "+
                			"sure your ears are bleeding.\n");
				break;
                case(2):tell_object(TP,"%^BOLD%^%^RED%^You feel as if eyes are "+
                			"burning holes into your soul and that you have gained "+
                			"the unwanted attention of a god.\n");
                        break;
                case(3):tell_room(ETP,"%^BOLD%^%^RED%^The room suddenly goes quiet "+
					"and dark.\n");
			  	set_property("light",0);
				TP->set_paralyzed(0);
                        break;
                case(4):tell_room(ETP,"%^BOLD%^%^RED%^The air gets thicker and hotter "+
                			"and a form starts to grows above the altar.%^RESET%^");
                		break;
                case(5):tell_room(ETP,"%^BOLD%^%^RED%^With a loud report the "+
					"being is suddenly in the room with you standing atop "+
					"the altar.%^RESET%^");
                        break;
                case(6):if(FLAG == 1){
                			new(MMONS+"shound")->move(TO);
                			return;
                		}
                		new(MMONS+"jubal")->move(TO);
                		FLAG = 1;
                        return;
                }
    num++;
    call_out("desecrating",0,tp,num);
    return;
}
void worshipping(object tp,int num){
            switch(num){
                case(0):tell_object(TP,"%^BOLD%^%^RED%^You bow down reverently and start "+
					"praying to Malar, Lord of the hunt!\n");
				tell_room(ETP,"%^BOLD%^%^RED%^"+TPQCN+" bows down reverently and "+
					"starts praying to his god. \n",TP);
                        break;
                case(1):tell_object(TP,"%^BOLD%^%^RED%^The room seems to grow distant and "+
					"you feel and hear the sounds of the great hunt.\n");
				tell_room(ETP,"%^BOLD%^%^RED%^The room seems to grow distant and "+
					"you feel and hear sounds of the great hunt.\n",TP);
				break;
                case(2):tell_object(TP,"%^BOLD%^%^RED%^Hounds and other tracking beasts "+
                			"bay behind you.\n");
                		tell_room(ETP,"%^BOLD%^%^RED%^Hounds and other tracking beasts "+
                			"bay behind you.\n",TP);
                        break;
                case(3):tell_object(TP,"%^BOLD%^%^RED%^A stirring in your chest and loins "+
					"calls you to join the hunt and you can almost smell the "+
					"blood and fear of the prey.\n");
				tell_room(ETP,"%^BOLD%^%^RED%^A stirring in your chest and loins "+
					"calls you to join the hunt and you can almost smell the "+
					"blood and fear of the prey.\n",TP);
                        break;
                case(4):tell_object(TP,"%^BOLD%^%^RED%^Primal urges and hungers flow "+
                			"through you and into the room as you give praise to your "+
                			"god.\n");
                		tell_room(ETP,"%^BOLD%^%^RED%^Primal urges and hungers flow "+
                			"through you as "+TPQCN+" prays.%^RESET%^",TP);
                		break;
                case(5):tell_object(TP,"%^BOLD%^%^RED%^You feel invigorated and "+
					"strengthened by the glorious Malar. %^RESET%^\n");
                        break;
                case(6):TP->set_paralyzed(0);
                        return;
                }
    num++;
    call_out("worshipping",0,tp,num);
    return;
}
