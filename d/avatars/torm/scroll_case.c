//reward by Torm for Mithras after the Daco-relic plot
//adapted from Ares' scroll case by Circe
#include <std.h>
#include <move.h>
inherit "/std/bag_logic";

void create() 
{
    set_id( ({"scroll case", "case"}) );
    set_name("scroll case");
    set_short("%^BOLD%^%^BLACK%^wo%^RESET%^%^ORANGE%^r%^BOLD%^"+
       "%^BLACK%^n le%^RESET%^%^ORANGE%^a%^BOLD%^%^BLACK%^the"+
       "%^RESET%^%^ORANGE%^r%^BOLD%^%^BLACK%^ tu%^RESET%^%^ORANGE%^"+
       "b%^BOLD%^%^BLACK%^e%^RESET%^");
    set_weight(5);
    set_long("%^BOLD%^%^BLACK%^Hard, sc%^RESET%^%^ORANGE%^r%^BOLD%^"+
       "%^BLACK%^atc%^RESET%^%^ORANGE%^h%^BOLD%^%^BLACK%^ed "+
       "leather has been formed to create this tube.  One end of the "+
       "tube is closed, but the other remains open.  The open end has "+
       "a matching le%^RESET%^%^ORANGE%^a%^BOLD%^%^BLACK%^ther cap that "+
       "can be sealed to prevent %^BLUE%^w%^RESET%^%^BLUE%^at%^BOLD%^e"+
       "%^RESET%^%^BLUE%^r %^BOLD%^%^BLACK%^from getting inside.  It "+
       "looks like the leather was died black at one point, but various "+
       "%^RESET%^%^ORANGE%^n%^BOLD%^%^BLACK%^i%^RESET%^%^ORANGE%^c"+
       "%^BOLD%^%^BLACK%^k%^RESET%^%^ORANGE%^s %^BOLD%^%^BLACK%^and "+
       "d%^RESET%^%^ORANGE%^i%^BOLD%^%^BLACK%^n%^RESET%^%^ORANGE%^g"+
       "%^BOLD%^%^BLACK%^s are now visible, revealing the %^RESET%^"+
       "%^ORANGE%^brown leather%^BOLD%^%^BLACK%^ beneath.  The effect "+
       "makes the tube look as if it's had much use.  %^RESET%^%^ORANGE%^"+
       "Inside, the tube is clean and unscratched, and looks as if it "+
       "could hold materials like paper easily, keeping them in "+
       "excellent shape.%^RESET%^");
    set_value(100);
    set_cointype("gold");
    set_max_internal_encumbrance(50);
    set_open_long( ""+TO->query_long()+"%^CYAN%^The cap is open.\n%^RESET%^");
    set_closed_long( ""+TO->query_long()+"%^CYAN%^The cap is closed.\n%^RESET%^");
    set_possible_to_close(1);
}

void init() 
{
   add_action("get_from","get");
   add_action("check_item","put");
   add_action("open_container","open");
   add_action("close_container","close");
   add_action("unlock_container", "unlock");
   add_action("lock_container", "lock");
   add_action("PickLock","pick");
   //left in all actions from /std/bag_logic.c for future use
}

void check_item(string str)
{

    string *stuff,tmp1,tmp2;
   // if(sscanf(str, "%s into ",tmp1)) return;
    sscanf(str,"%s in %s",tmp1,tmp2);
    if(member_array(tmp2,TO->query_id()) == -1) return;
    /*  add more stuff({}) to allow different items to be placed inside
    scroll cases. */
    stuff = ({ "scroll","paper","parchment" });



    if(member_array(tmp1, stuff) + 1)
    {
        put_into(str);
        return 1;
    }
             
    notify_fail("You can only put scrolls into this.\n");
    return;

}
