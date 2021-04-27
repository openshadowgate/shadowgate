#include <std.h>
inherit "/d/common/obj/weapon/bastard.c";

void create() {
    ::create();
    set_name("golden blade");
    set_id(({"sword","blade","golden blade","brilliant blade","brilliant golden blade","bastard sword","bastard","golden bastard sword","sunblade","Sunblade","greater sunblade"}));
    set_short("%^YELLOW%^Gr%^RESET%^%^ORANGE%^eat%^YELLOW%^er Sun%^RESET%^%^ORANGE%^bl%^YELLOW%^ade%^RESET%^");
    set_obvious_short("%^YELLOW%^a brilliant go%^RESET%^%^ORANGE%^ld%^YELLOW%^en blade%^RESET%^");
    set_long("%^BOLD%^%^WHITE%^This %^RESET%^%^CYAN%^br%^BOLD%^il%^WHITE%^l"
"%^CYAN%^ia%^RESET%^%^CYAN%^nt %^BOLD%^%^WHITE%^sword glitters with even the "
"faintest touch of %^YELLOW%^l%^WHITE%^i%^YELLOW%^ght %^WHITE%^upon it.  Its "
"surface appears to be made of pure %^RESET%^%^ORANGE%^go%^YELLOW%^l%^RESET%^"
"%^ORANGE%^d%^BOLD%^%^WHITE%^, which surely is an impossibility given the "
"quality of the weapon; %^RESET%^%^GREEN%^ma%^BOLD%^gi%^RESET%^%^GREEN%^c "
"%^BOLD%^%^WHITE%^must have had a hand in its crafting.  The entire weapon is "
"more than five feet in length, nearly four of which form the blade itself.  "
"%^RESET%^%^CYAN%^Li%^GREEN%^ght%^CYAN%^er %^BOLD%^%^WHITE%^than its size would "
"suggest, the hollow-ground blade has been deliberately shaped for stregth "
"without weight.  Perfectly balanced, the blade has been honed to a "
"%^BOLD%^%^BLACK%^ra%^WHITE%^z%^YELLOW%^o%^BLACK%^r-s%^RED%^h%^BLACK%^arp "
"%^WHITE%^edge and tapers towards the point.  It seems to have been "
"deliberately designed with a shorter blade and longer hilt than a standard "
"longsword, allowing for a better grip and a more precise, reactive nature in "
"%^RED%^co%^RESET%^%^RED%^mb%^BOLD%^at%^WHITE%^.  Oddly, its thick blade "
"narrows abruptly to a thin neck just before the crossguard, which flares back "
"out again in several %^YELLOW%^go%^RESET%^%^ORANGE%^ld%^YELLOW%^en "
"%^WHITE%^ridges like tongues of %^RED%^f%^RESET%^%^RED%^l%^BOLD%^a%^YELLOW%^m"
"%^RED%^e%^WHITE%^.  No leather wraps the hilt, but the grip is smooth and "
"slightly ridged, intentionally shaped as a secure handhold.  At the centre of "
"the hilt, a single %^RESET%^%^RED%^st%^MAGENTA%^a%^RED%^r ruby "
"%^BOLD%^%^WHITE%^has been embedded, with spiderlike trails of %^RESET%^white "
"crys%^CYAN%^t%^RESET%^al %^BOLD%^%^WHITE%^marking the sparkling "
"%^RESET%^%^RED%^blo%^BOLD%^o%^RESET%^%^RED%^d-red %^BOLD%^%^WHITE%^surface of "
"the gem.%^RESET%^\n");
    set("lore","This sword was once used by the dedicated followers of Lathander who forged several of these weapons in order to combat a large force of undead creatures that threatened to crush his people. The swords were known as Sunblades, for they harness the power of the sun in order to fight evil. The strange mabion metal they are made of makes them much faster than normal weapons, and thus doubly effective against the normally slower undead monsters. From there other faiths started to adopt the ");
    set_property("lore",20);
    set_property("enchantment",5);
    set_weight(10);
    set_value(17600);
/*    set_hit((:TO,"hitme":));
    set_wield((:TO,"wieldme":));
    set_unwield((:TO,"removeme":));*/
}
