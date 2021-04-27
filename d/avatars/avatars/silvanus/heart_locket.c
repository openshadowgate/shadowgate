#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("Heart-Shaped Locket");
	set_id(({ "locket", "necklace", "chain", "heart shaped locket", "heart-shaped locket" }));
	set_short("%^RED%^Heart-Shaped Locket%^RESET%^");
	set_obvious_short("%^RED%^Heart-Shaped Locket%^RESET%^");
	set_long(
@AVATAR
%^YELLOW%^This is a beautiful gold necklace that has a heart shaped locket attached to the chain.  The chain itself is made out of delicate strands of gold that have been carefully woven together.  The locket is carved from the %^RED%^heart of a ruby %^YELLOW%^and on the inside of it, in small, fine elven script a message is written.  You could easily %^RED%^read%^YELLOW%^ it.%^RESET%^
AVATAR
	);
	set("read",
@AVATAR
                          %^RED%^Here I love you,
           %^RED%^In the dark pines the wind disentangles itself
       %^RED%^The moon glows like phosphorous on the vagrant waters
             %^RED%^Days, all one kind, go chasing each other
                            %^RED%^My beloved
                            
                        %^CYAN%^Kaeldora Carendore
AVATAR
	);
	set_weight(1);
	set_value(100);
	set_type("ring");
	set_limbs(({ "neck" }));
	set_size(2);
	set_property("enchantment",0);
	set_ac(0);
}


