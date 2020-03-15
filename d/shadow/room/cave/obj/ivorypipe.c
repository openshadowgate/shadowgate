//ivorypipe.c
#include <std.h>

inherit OBJECT;

object ob; 
string tobacco_type;
int lit, packed, tobacco, light_time, sp_adjust, con_req;
 
void create() {
  ::create();
    set_name("ivory cave pipe");
    set_id( ({ "pipe","ivory pipe","cave pipe","ivory cave pipe" }) );
    set_short("%^BOLD%^%^WHITE%^An ivory pipe%^RESET%^");
    set_long("This aged pipe is made of stark white ivory carved "+
       "with various symbols.  Most of them seem to be family crests "+
       "and have been filled with a smokey gray ink, causing them to "+
       "stand out in relief.  The stem of the pipe is very long and "+
       "protected by blackened ivory.\n"+
       "      %^BOLD%^You could pack or fill the pipe with tobacco, then smoke it.\n"+
       "              When you are finished, you could douse it.%^RESET%^"
    	    );
    set_weight(0);
    set_value(0);
    tobacco = 0;
    packed = 0;
    lit = 0;
    con_req = 0;
    sp_adjust = 0;
}
 
void init() {
    add_action("extinguish", "douse");
    add_action("smoke","smoke");
    add_action("pack_pipe","pack");
    add_action("pack_pipe","fill");
}
 
int smoke(string str) {
    if(!id(str)) {
        notify_fail("Smoke what?\n");
        return 0;
    }
    if(!packed) {
        notify_fail("Why would you want to smoke an empty pipe?\n");
        return 0;
    }
    if(lit) {
        notify_fail("You're already smoking it!\n");
        return 0;
    }
    if(con_req > this_player()->query_stats("constitution")){
  	write("You can't smoke this tobacco, it is too strong for you!");
	write("You unpack the pipe, and drop the contents on the ground.");	
	packed = 0;
	return 1;
    }
    write ("%^BOLD%^You begin smoking your pipe.\n");
    say("%^BOLD%^"+TP->query_cap_name()+" begins smoking a pipe.\n", TP);
    call_out("go_out", tobacco);
    call_out("take_drag", 5);
    light_time = time();
    set_short("A lit ivory pipe");
    lit = 1; 
    return 1;
}
 
int extinguish(string str) {
    if(!id(str)) {
        notify_fail("Douse what?\n");
        return 0;
    }
    if(!lit) {
        notify_fail("Your pipe is not lit!\n");
        return 0;
    }
    write("%^BOLD%^%^BLUE%^You douse your pipe.");
    say(this_player()->query_cap_name()+" douses a pipe.\n",
        this_player());
    tobacco -= (light_time - time());
    remove_call_out("go_out");
    remove_call_out("take_drag");
    set_short("An ivory pipe packed with tobacco");
    lit = 0;
    return 1;
}
 
void go_out() {
    tobacco = 0;
    if(living(ETO)){
	tell_room(environment(ETO), ""+TP->query_cap_name()+"'s pipe goes out.",ETO);
	tell_object(ETO, "Your pipe goes out.");
    remove_call_out("take_drag");
    set_short("An ivory pipe");
    lit = 0;
    packed = 0;
    }
}

void take_drag() {
    if(living(ETO)) {
	write("%^YELLOW%^You take a long, deep drag on your pipe.");
      say("%^YELLOW%^"+TP->query_cap_name()+" takes a long, deep drag on "+TP->query_possessive()+" pipe.",TP);
        }
    if(tobacco_type == "afgan") {
	this_player()->add_intox(7);
	write("%^BOLD%^%^MAGENTA%^You start to feel strange, and your mind begins to wander.");
    }
    say("%^YELLOW%^"+TP->query_cap_name()+
        " giggles and stares off into the distance.%^RESET%^",TP);
    this_player()->set_sp(this_player()->query_sp()+sp_adjust);
    call_out("take_drag", 50, this_object());
 
}
 
int pack_pipe(string str){
    string pipe;

    if(packed){
	notify_fail("Your pipe is already packed!\n");
	return 0;
	}
    if(!str) return 0;
    if((sscanf(str, "%s with %s", pipe, tobacco_type)) !=2) return 0;
    if(pipe != "pipe") return 0;
    if(tobacco_type == "tobacco") {
	notify_fail("That is not a valid type of tobacco!\n");
	return 0;}
    if(!(ob = present(tobacco_type,TP))){
       	notify_fail("You can't pack your pipe with "+tobacco_type+"!!!\n");
	return 0;
        }
    if(ob->id("tobacco")){ 

	con_req = (int)ob->query_con_check();
	write("\n%^BOLD%^You pack your pipe with "+tobacco_type+" tobacco.\n");
    say("\n%^BOLD%^"+TP->query_cap_name()+" packs "+TP->query_possessive()+" pipe with some "+tobacco_type+" tobacco.\n");
	set_short("An ivory pipe packed with tobacco");
     	tobacco=500;
	packed=1;
	sp_adjust = ob->set_uses();
	return 1;
        }
}

remove()
{
   if (lit) {
	lit = 0;
	packed = 0;
        remove_call_out("take_drag");
        remove_call_out("go_out");

   }
 
   if(packed) packed = 0;
   this_object()->set_short("An ivory pipe");
   return ::remove();  
}
