//Coded by Bane//
#include <std.h>
inherit NPC;
object ob;
string *intro_msgs;

void create(){
    ::create();

    intro_msgs = ({"Golly, I hope you are here to help my people defeat the evil that has moved to our lands.",
	"Did you want to %^BOLD%^%^CYAN%^ask %^RESET%^me about the evil that has come?",
    "I sense terrible times ahead my friends...",
    "A powerful force of evil will destroy our world if we don't stop it soon."});

   set_nwp("forage",15,500);
    set_id(({"sage","man","old man","old sage"}));
    set_name("sage");
    set_short("An old sage");
    set_long(
	"Standing before you is a man easily a century old.  His white beard reaches "+
	"past his waist and he grips a cane to support his frail body."
    );
    set_body_type("human");
    set_race("human");
    set_size(2);
    set_gender("male");
    set_hd(1,0);
    set_hp(6);
    set_exp(-5000);
    set_emotes(5,({"%^MAGENTA%^Sage says%^RESET%^: " + intro_msgs[0],
    "%^MAGENTA%^Sage says%^RESET%^: " + intro_msgs[1], 
    "%^MAGENTA%^Sage says%^RESET%^: " + intro_msgs[2], 
    "%^MAGENTA%^Sage says%^RESET%^: " + intro_msgs[3]
    }),0);
}
void init(){
    ::init();
    add_action("ask","ask");
    add_action("bring","bring");
}

void ask(string str){
    string tmp;
    if(!str) return notify_fail("Ask what?\n");
    if(!sscanf(str,"sage about %s",tmp)) return notify_fail("Ask whom about what?\n");
    write("%^MAGENTA%^Sage says%^RESET%^: Ah yes, the quest...."
	"\nThere is a powerful undead force that has moved into our realms dear one.  "+
	"If it is not destroyed soon his armies will overrun our realms and that would "+
	"be disastrous.  I need you to defeat him and bring his life source to me so "+
	"I can put an end to his evil forever.\n\n%^MAGENTA%^Sage says%^RESET%^:"
        "  To do this you must hunt the beast out "+
	"and destroy it in its lair.  Defeating it outside its lair is useless!  "
	"I have a reward for the brave soul who actually kills this "
	"undead sorcerer in the caverns north of the Parnelli forest and will "
        "%^BOLD%^%^RED%^<bring> %^RESET%^its life force to me!"
    );
    return 1;
}

void bring(string str){
    object tooth;
    if(!str) return notify_fail("Bring what?\n");
    if(objectp(TP) && tooth = present("tooth",TP)){
        if(member_array("Killed Hansoth",TP->query_mini_quests()) == -1){
        command("say Ah but I asked you to kill this beast yourself!  "
            "Coward leave here!");
    //	    write("%^MAGENTA%^Sage says%^RESET%^:  Ah but I asked you to kill this beast yourself!  Coward leave here!");
    //	    tooth->remove();
            return 1;
        }
        if(member_array("Legacy of Hansoth",TP->query_quests()) != -1){
            write("%^MAGENTA%^Sage says%^RESET%^:  Thank you for helping me yet again, here is a reward for your efforts.");
            tooth->remove();
            ob = new("/d/laerad/obj/boots_speed");
            ob->move(TO);
                ob->set_size(TP->query_size());
            force_me("give boots to "+TP->query_name());
            return 1;
        }
        write("%^MAGENTA%^Sage says%^RESET%^:  Yes, you have the tooth!");
        tell_object(TP,"The Sage takes the tooth from you.");
        tell_room(ETO,"The Sage takes the tooth from "+TP->query_cap_name()+".",TP);
        tooth->move(TO);
        force_me("offer tooth");
        force_me("offerall");
        tell_object(TP,"You have completed the Legacy of Hansoth quest!");
        TP->set_quest("Legacy of Hansoth");
        TP->fix_exp(1000000,TP);
        return 1;
    }
    write("%^MAGENTA%^Sage says%^RESET%^:  You don't have the Lich's life source fool!");
    return 1;
}

void catch_say(string msg){

    if(!userp(TP)){
        return;
    }

    // if (TP->query_invis()) return;

   ::catch_say(msg);
   call_out("reply_func",1,msg,TP);
}

void reply_func(string msg, object who){
   object current;
   object obj;
   string name;
   set_spoken("wizish");
   name = who->query_name();

   if(!msg || !objectp(who)) return;

    if(strsrch(msg,"Hi") != -1 || strsrch(msg,"hail") != -1 ||
      strsrch(msg,"reeting") != -1 || strsrch(msg,"ello") != -1 ||
      strsrch(msg,"Hail") != -1)  {
      write("%^MAGENTA%^Sage says%^RESET%^:  Hello adventurer. ");

      for (int i = 0; i<sizeof(intro_msgs); i++) {
        call_out("sage_says", 1+2*i, intro_msgs[i]);
      }
    }

    if(strsrch(msg,"ask") != -1 || strsrch(msg,"Ask") != -1 ||
        strsrch(msg,"evil") != -1 || strsrch(msg,"Evil") != -1 ||    
        strsrch(msg,"quest") != -1 || strsrch(msg,"Quest") != -1 ||
        strsrch(msg,"help") != -1 || strsrch(msg,"Help") != -1 
    )  
    {
  
        call_out("sage_says", 1, "Ah yes, the quest....");
        call_out("sage_says", 3, "There is a powerful undead force that has moved into our realms dear one.  "+
        "If it is not destroyed soon his armies will overrun our realms and that would "+
        "be disastrous.  I need you to defeat him and bring his life source to me so "+
        "I can put an end to his evil forever.");
        call_out("sage_says", 5, "To do this you must hunt the beast out "+
        "and destroy it in its lair.  Defeating it outside its lair is useless!  "
        "I have a reward for the brave soul who actually kills this "
        "undead sorcerer in the caverns north of the Parnelli forest and will "
            "%^BOLD%^%^RED%^<bring> %^RESET%^its life force to me!");


    }

   if(strsrch(msg,"bring") != -1 || strsrch(msg,"Bring") != -1 )  {
        call_out("sage_says", 1, "When you have the life force, %^BOLD%^%^RED%^<bring> %^RESET%^it to me!");
   }

}

void sage_says(string msg) {
    write("%^MAGENTA%^Sage says%^RESET%^:  " + msg);    
}