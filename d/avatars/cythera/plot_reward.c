//Plot reward 8/05\\
#include <std.h>
inherit ARMOUR;

#define COLORS ({"%^BOLD%^%^CYAN%^steel",\
"%^BOLD%^%^WHITE%^platinum",\
"%^YELLOW%^yellow gold", \
"%^BOLD%^%^WHITE%^m%^CYAN%^i%^WHITE%^thr%^CYAN%^i%^WHITE%^l",\
"%^BOLD%^%^RED%^fever iron",\
"%^ORANGE%^copper",\
"%^BOLD%^%^BLUE%^electrum",\
"%^YELLOW%^bronze",\
"%^BOLD%^%^CYAN%^adamantium",\
"%^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^l%^RESET%^v%^BOLD%^e%^RESET%^r",\
"%^BOLD%^%^WHITE%^white gold",\
"%^BOLD%^%^MAGENTA%^rose gold",\
"%^BOLD%^%^WHITE%^titanium",\
"%^MAGENTA%^darksteel",\
"%^BOLD%^%^WHITE%^a%^GREEN%^r%^WHITE%^and%^BLUE%^u%^WHITE%^r",\
"%^BOLD%^%^WHITE%^dl%^GREEN%^a%^WHITE%^r%^GREEN%^a%^WHITE%^n"})

void create(){
     	int j;
	string str, COLOR;
	::create();
	j = random(sizeof(COLORS));
      COLOR = COLORS[j];
   set_name("amulet");
   set_short("%^RESET%^%^CYAN%^A "+COLOR+" %^RESET%^%^CYAN%^amulet%^RESET%^");
   set_id(({"amulet","plot_amulet"}));
   set_long("%^CYAN%^Fashioned out of "+COLOR+""+
	" %^RESET%^%^CYAN%^this triangle amulet is strung on a matching chain."+
   	" The amulet features three images on its surface.  In the center there"+
	" is an image of a beautiful %^BOLD%^%^WHITE%^ivory%^RESET%^%^CYAN%^ "+
	"skinned woman with long flowing %^RED%^crimson%^CYAN%^ hair.  Below her"+
	" and to the left is the image of a male human with his %^RESET%^long hair"+
	"%^CYAN%^ and %^BOLD%^%^BLACK%^cloak%^RESET%^%^CYAN%^ blowing in the wind."+
	"  Across from him is the image of a %^BOLD%^%^WHITE%^white%^RESET%^%^CYAN%^"+
	" haired attractive female with a %^BOLD%^%^MAGENTA%^deranged%^RESET%^%^CYAN%^"+
	" and %^BOLD%^%^RED%^crazed%^RESET%^%^CYAN%^ look in her eyes.%^RESET%^");
   set_weight(2);
   set_type("ring");
   set_limbs(({"neck"}));
   set_value(0);
   set_property("enchantment",1);
   set_lore("This Amulet was constructed to reward those who helped free the three "+
	"gods imprisoned by Talos.  Sune Firehair, Shaundakul, and Beshaba were all set"+
	" free thanks to the hard work of a group of adventures.");
	set_property("lore",4);
   set_wear("The amulet feels light as a feather as you slip it on.");
   set_remove("You remove the amulet for now.");
}
