#include <std.h>
#include <daemons.h>

inherit "/std/comp_vend.c";

string *killers;

void create() {
    ::create();
    set_name("Dean");
    set_id( ({ "dean", "clerk", "shop keeper", "shopkeeper"}) );
    set_short("Dean, the alchemist apprentice");
    set("aggressive", 0);
    set_long("This young human, possibly an apprentice to a local master alchemist or the store owner, is standing behind the counter watching over the store.  He seems overly curious about the people he meets.  He has %^YELLOW%^short, blonde hair %^RESET%^%^CYAN%^on his head and no signs of facial hair at all yet.  His face and nose are covered with pimples and all in all you guess he's in his early teens.  He is dressed as any school lad might be and wears his glasses on the end of his nose.\n"+
	"<help shop> will get you a list of shop commands.\n");
    set_gender("male");
    set_alignment(2);
    set_race("human");
    set_class("mage");
    set_hd(10,2);
    set_mlevel(10);
    set_guild_level("mage",10);
    set_body_type("human");
    set_hp(90+random(20));
    set_components(50);
    set_spell_chance(100);
    set_spells(({"fireball","lightning bolt","acid arrow","cone of cold"}));
    remove_std_db();
}

void init(){
    ::init();
    killers = SAVE_D->query_array("slore_shop_killers");
    if( (member_array(TPQN, killers) != -1) && !TP->query_invis() ){
      force_me("emote takes one look at "+TPQCN+", then screams in terror and runs for his life.");
      TO->move("/d/shadowgate/void");
      remove();
    }    
}

int kill_ob(object victim, int which){
    int hold;
    killers = SAVE_D->query_array("slore_shop_killers");
    hold = ::kill_ob(victim, which);
//    if(member_array(TPQN, killers) != -1) return hold;
    SAVE_D->set_value("slore_shop_killers", TPQN);
    command("say %^YELLOW%^The guards'll tell on you for pickin' on me!!");
    tell_object(TP,"%^BOLD%^The instant you make an aggressive move, a "
       "blindingly bright light flashes.%^RESET%^\nOnce you blink, you realize "
       "the young apprentice has disappeared.");
    tell_room(ETO,"%^BOLD%^The instant that "+TPQCN+" makes an aggressive "
       "move, a blindingly bright light flashes.%^RESET%^\nOnce you blink, you "
       "realize the young apprentice has disappeared.", TP);

    TO->move("/d/shadowgate/void.c");
    return hold;
    remove();
}

