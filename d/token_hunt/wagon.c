#include <std.h>
#include "token_hunt.h"

inherit OBJECT;

void create()
{
    ::create();
    set_id(({"wagon",}));

    set_name("wagon");

    set_short("%^MAGENTA%^A small wagon, rounded with goods");

    set_long("%^BOLD%^%^WHITE%^This small wagon comes complete with four thick walls "
        "to keep all the supplies it is hauling safe and secure. Four large wheels "
        "provide a sturdy means of transport and you notice that a fifth wheel is "
        "strapped under the belly to provide for a quick repair should one of the "
        "first four break. At the front a wide, flat seat provides a spot for the "
        "driver to sit and guide the large, lumbering %^YELLOW%^triceratops %^WHITE%^that "
        "pulls the wagon. Beside the driver's seat is a secure looking %^BLUE%^iron "
        "chest %^WHITE%^with several %^MAGENTA%^magical runes %^WHITE%^decorating it. "
        "More of these enchanted chests are located in the back of the wagon and every "
        "one of them appears to be very well maintained. Draped over the sides of the "
        "wagon are a number of %^MAGENTA%^%^BOLD%^b%^BLUE%^r%^MAGENTA%^igh%^BLUE%^t%^MAGENTA%^ly%^WHITE%^ "
        "colored banners, each proclaiming that this is the fabled %^YELLOW%^Emporium "
        "of Exotic Wares%^WHITE%^: A traveling warehouse of rare, fabulous things "
        "that have been brought back from all over the realm and sold to the small "
        "gnome that tends the traveling shop. %^RESET%^\n"
        "You can see a list posted on the side of the wagon, maybe you "
        "can 'read list'.  There's also a slot near the wagon wheel with a box "
        "protruding from it.  You could probably 'retrieve box'");
    set_weight(100000000);
}

int read_list(string str)
{
    object ob,token_ob;
    int i;

    string *shorts=({}),*locations=({}),type;


    if(!stringp(str) || str != "list") { return 0; }
    if(!objectp(TP)) { return 0; }

    if(!objectp(ob=present("shopkeeper",ETO)))
    {
        tell_object(TP,"This list is covered with blood!");
        return 1;
    }
    type = ob->query_store_type();

    token_ob = find_object_or_load(TOKEN_D);

    token_ob->check_population();

    shorts      = token_ob->monster_locations(type);
    locations   = token_ob->true_locations(type);

    tell_object(TP,"%^RESET%^%^BOLD%^Last known locations.%^RESET%^");
    tell_object(TP,"%^MAGENTA%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-%^RESET%^");
    for(i=0;i<sizeof(shorts);i++)
    {
        tell_object(TP,"    "+shorts[i]+"");
    }
    tell_object(TP,"%^MAGENTA%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-%^RESET%^");

    if(avatarp(TP))
    {
        tell_object(TP,"%^RESET%^%^BOLD%^True locations for all.%^RESET%^");
        tell_object(TP,"%^MAGENTA%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-%^RESET%^");
        for(i=0;i<sizeof(locations);i++)
        {
            tell_object(TP,"    "+locations[i]+"");
        }
        tell_object(TP,"%^MAGENTA%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-%^RESET%^");
    }
    if(objectp(ob=present("shopkeeper",ETO)))
    {
        if(!avatarp(TP))
        {
            ob->force_me("say If you're thinking about going after one of those "
                "shapechangers for the tokens, then be careful.  They are some "
                "of the strongest creatures you'll ever face.");
        }
    }
    return 1;
}

int retrieve_box(string str)
{
    if(!stringp(str)) { return 0; }
    if(str != "box" && str != "Box") { return 0; }

    tell_object(TP,"You pull a box from the dispenser and it falls "
        "onto the ground.");
    new(FILE_PATH"tokens")->move(ETO);
    return 1;
}

int request_marker(string str)
{
    if(!objectp(TP)) { return 0; }
    if(!avatarp(TP)) { return 0; }
    if(!stringp(str)) { return 0; }
    if(str != "marker" && str != "Marker") { return 0; }
    tell_object(TP,"You retrieve a marker.");
    new(FILE_PATH"token_marker")->move(TP);
    return 1;
}

void init()
{
    ::init();
    add_action("read_list","read");
    add_action("retrieve_box","retrieve");
    add_action("request_marker","request");
    if(!objectp(TP)) { return; }
    if(avatarp(TP)) 
    {
        tell_object(TP,"%^GREEN%^Type <request marker> to get a marker that will let "
            "you add additional directories to the places where mobs are allowed to "
            "spawn");
    }    
}

