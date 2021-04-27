#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("cup");
	set_id(({ "cup", "seneca cup" }));
	set_short("%^BOLD%^%^CYAN%^The %^RED%^S%^BLUE%^e%^RED%^n%^BLUE%^e%^RED%^c%^BLUE%^a%^CYAN%^ Cup%^RESET%^");
	set_obvious_short("%^BOLD%^%^CYAN%^The %^RED%^S%^BLUE%^e%^RED%^n%^BLUE%^e%^RED%^c%^BLUE%^a%^CYAN%^ Cup%^RESET%^");
	set_long("%^BOLD%^%^CYAN%^This %^YELLOW%^chalice%^CYAN%^ stands about 3 feet high with a %^RESET%^%^ORANGE%^wooden base%^BOLD%^%^CYAN%^ and %^WHITE%^two enormouse handles%^CYAN%^ on either side. Engraved on the"
	" base is the motto of the lists %^YELLOW%^<--Victory to the Honorable and Valorous-->%^RESET%^
"
	);
	set_value(10000);
	set_weight(1);
	set_lore("%^YELLOW%^This cup is awarded to the strongest knight to do battle at the Lists in Seneca. It is renowned to have magical powers. <use cup on target>%^RESET%^
");
    set_property("lore difficulty",10);
}
