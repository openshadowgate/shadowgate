#include <std.h>
#include <daemons.h>
#define WAIT_TIME 1200

inherit "/d/common/obj/jewelry/necklace";

int used_time;
void create()
{
    ::create();
    set_name("stag pendant");
    set_id(({ "necklace", "stag pendant","black stag pendant",
    "pendant", "stag necklac" }));

    set_short("%^BOLD%^%^BLACK%^K%^BLUE%^ee%^BOLD%^%^BLACK%^p%^BLUE%^e%^BOLD%^%^BLACK%^r of T%^CYAN%^ri%^BOLD%^%^BLACK%^b%^CYAN%^e"
			  " %^BOLD%^%^BLACK%^Bl%^RESET%^%^MAGENTA%^ac%^BOLD%^%^BLACK%^k St%^MAGENTA%^a%^BLACK%^g%^RESET%^");
    set_obvious_short("%^BOLD%^%^BLACK%^A b%^MAGENTA%^ea%^BOLD%^%^BLACK%^u%^MAGENTA%^t%^BOLD%^%^BLACK%^i%^MAGENTA%^fu%^BOLD%^%^BLACK%^l"
					  " st%^RESET%^%^MAGENTA%^a%^BOLD%^%^BLACK%^g p%^MAGENTA%^en%^BOLD%^%^BLACK%^d%^MAGENTA%^a%^BOLD%^%^BLACK%^nt%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^A small s%^WHITE%^n%^BLACK%^o%^WHITE%^w%^BLACK%^f%^WHITE%^l%^BLACK%^a%^WHITE%^k%^BLACK%^e o%^WHITE%^b%^BLACK%^s%^WHITE%^i%^BLACK%^d%^WHITE%^i%^BLACK%^a%^WHITE%^n %^BLACK%^carved"
    " into an image of a bla%^RESET%^%^MAGENTA%^c%^BOLD%^%^BLACK%^k st%^RESET%^%^MAGENTA%^a%^BOLD%^%^BLACK%^g. Exquisite detail went into the st%^MAGENTA%^a%^BLACK%^g,"
    " almost %^RESET%^%^ORANGE%^l%^BOLD%^i%^RESET%^%^ORANGE%^fe %^BOLD%^%^BLACK%^like in appearance with massive %^RESET%^%^ORANGE%^antlers %^BOLD%^%^BLACK%^and a"
    " shiny bl%^MAGENTA%^ac%^BLACK%^k co%^CYAN%^a%^BLACK%^t. The %^RESET%^%^RED%^hoves %^BOLD%^%^BLACK%^of the %^WHITE%^stag %^BLACK%^is %^RED%^red beryl %^BLACK%^and"
    " positioned as the st%^RESET%^%^MAGENTA%^a%^BOLD%^%^BLACK%^g is mid %^GREEN%^jump%^BLACK%^. The p%^MAGENTA%^en%^BLACK%^d%^MAGENTA%^an%^BLACK%^t hangs from a %^WHITE%^silver rope%^BLACK%^."
    " %^BOLD%^%^BLACK%^An %^CYAN%^inscription%^BOLD%^%^BLACK%^ is written in orcish on the underside of the p%^MAGENTA%^en%^BOLD%^%^BLACK%^d%^RESET%^%^MAGENTA%^a%^BOLD%^%^BLACK%^nt.%^RESET%^");

    set_read("%^BOLD%^%^BLACK%^I, %^RED%^Warchief %^BLACK%^of T%^CYAN%^ri%^BLACK%^b%^CYAN%^e %^BLACK%^Bl%^MAGENTA%^ac%^BLACK%^k St%^MAGENTA%^a%^BLACK%^g - %^RESET%^%^MAGENTA%^Kogan Black Stag %^BOLD%^%^BLACK%^grant all"
    " my %^WHITE%^authority %^BLACK%^to the %^RESET%^%^CYAN%^beholder %^BOLD%^%^BLACK%^of this p%^MAGENTA%^en%^BLACK%^d%^MAGENTA%^a%^BLACK%^nt.%^RESET%^");

    set_lore("%^BOLD%^%^BLACK%^Legend says this was forged by %^RESET%^%^MAGENTA%^Kogan %^BOLD%^%^BLACK%^of Tribe - Bl%^MAGENTA%^a%^BLACK%^c%^MAGENTA%^k %^BLACK%^S%^MAGENTA%^t%^BLACK%^a%^MAGENTA%^g %^BLACK%^for his beloved"
    " %^RESET%^%^MAGENTA%^Raika%^BOLD%^%^BLACK%^. It symbolized her %^WHITE%^high station %^BLACK%^to other %^RESET%^%^RED%^orcs %^BOLD%^%^BLACK%^and whom should have it would be regarded as"
    " someone whom other orcs should %^CYAN%^respect%^BLACK%^. It is believed that %^RESET%^%^CYAN%^Ketami %^BOLD%^%^BLACK%^pried the pendant from the"
    " %^RED%^d%^RESET%^%^RED%^e%^BOLD%^ad %^BLUE%^c%^CYAN%^o%^BLUE%^l%^CYAN%^d %^BLACK%^hands of %^RESET%^%^MAGENTA%^Raika %^BOLD%^%^BLACK%^herself.%^RESET%^");

    set_language("orcish");
    set_weight(4);
    set_value(50000);
    set_size(-1);
    set_property("enchantment",6);
    set_item_bonus("mage resistance", 25);
    set_item_bonus("charisma",4);
    set_item_bonus("wisdom",3);
    set_wear((:TO,"wear_me":));
}

int wear_me()
{
    tell_object(ETO,"%^BOLD%^%^BLACK%^You hear the %^BOLD%^%^CYAN%^clashing%^BOLD%^%^BLACK%^ of %^RESET%^%^ORANGE%^antlers%^BOLD%^%^BLACK%^.%^RESET%^");
    if(!ETO->query_invis())
    {
        tell_room(EETO,"%^BOLD%^%^BLACK%^The p%^MAGENTA%^en%^BOLD%^%^BLACK%^d%^MAGENTA%^a%^BOLD%^%^BLACK%^nt on "+
        ETO->QCN+"%^BOLD%^%^BLACK%^'s necklace begins a %^CYAN%^quick%^BOLD%^%^BLACK%^ "+
        "and %^BOLD%^%^MAGENTA%^beautiful%^BOLD%^%^BLACK%^ spin.%^RESET%^",ETO);
    }
    return 1;
}

