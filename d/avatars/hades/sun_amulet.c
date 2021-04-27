//plot item for world getting turned all night
//coded by hades 7/18/20
#include <std.h>
inherit "/d/common/obj/jewelry/necklace";

void create()
{
    ::create();
    set_name("ray of sunlight");
    set_id(({ "necklace", "ray of sunlight", "ray","amulet" }));
    set_short("%^ORANGE%^r%^BOLD%^a%^RESET%^%^ORANGE%^y of sunlight%^RESET%^");
    set_obvious_short("%^ORANGE%^gl%^BOLD%^ow%^RESET%^%^ORANGE%^ing bottle on a chain%^RESET%^");
    set_lore("This is a bottle of sunshine.  It was one of the items"+
    " created to bring about edea's return.  One can <light> to create a light.");
    set_property("lore difficulty", 30);
    set_long("%^ORANGE%^This is a bottle of yellow glowing liquid that"+
    " glows with the brightness of the sun.   It has a gold chain"+
    " which can be clasped behind one's neck to secure it in place.%^RESET%^");

    set_size(-1);
    set_value(5000);
    set_wear((: TO, "wear_me" :));
 
}
void init(){
    ::init();
    add_action("light","light");
}

int wear_me()
{
    tell_object(ETO, "%^ORANGE%^You secure the amulet around your "+
    "neck and watch it glow %^BOLD%^brightly.");

    return 1;
}
int light(string str){
    if(str) return 0;
    if (TP->query_bound() || TP->query_unconscious()) {
       TP->send_paralyzed_message("info",TP);
       return 1;
    }

    if(query_worn()){
        write("%^BOLD%^You open the bottle and light comes out.");
        new("/cmds/spells/l/_light.c")->use_spell(TO,TP,10,100,"mage");
        return 1;
    }

    
    write("You must wear the amulet first.");
    return 1;
}
