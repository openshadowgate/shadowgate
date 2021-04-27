// based off original by Asmodeus, Verbie seems addicted to them so ramping them up a little. N, 4/15.
#include <std.h>
inherit "/d/common/obj/clothing/magerobe";

void create(){
	::create();
	set_name("blood red robes");
	set_id(({ "robes","red robes","robe","blood red robes","magerobes","robes of the warmage" }));
	set_short("%^YELLOW%^R%^RED%^o%^YELLOW%^b%^RED%^e%^YELLOW%^s%^RED%^ of the %^YELLOW%^W%^RED%^a%^YELLOW%^r%^RED%^m%^YELLOW%^a%^RED%^g%^YELLOW%^e%^RESET%^");
	set_obvious_short("%^BOLD%^%^RED%^bl%^RESET%^%^RED%^oo%^BOLD%^%^RED%^d r%^RESET%^%^RED%^e%^BOLD%^%^RED%^d r%^RESET%^%^RED%^ob%^BOLD%^%^RED%^es%^RESET%^");
	set_long("%^BOLD%^%^RED%^These robes have been dyed a shade of deep blood-red. The robes are heavy, and are padded with extra "
"layers of cloth for protection, without hindering the wearer's mobility. The robe is sleeveless, leaving the wearer with quick access "
"to weapons or spellcasting. Sewn into the folds of the robe are several large hidden pockets, which seem to have more roo inside than "
"they possibly could hold. An elaborate scene has been stitched onto the back of the garment, depicting a large armored man riding with "
"one leg on a %^YELLOW%^f%^RED%^ie%^YELLOW%^r%^RED%^y %^BOLD%^%^BLACK%^black stallion %^BOLD%^%^RED%^and the other on a %^WHITE%^gr"
"%^MAGENTA%^a%^WHITE%^ce%^CYAN%^f%^WHITE%^ul white stallion%^BOLD%^%^RED%^. Behind this rises a backdrop of a greatsword with %^YELLOW%^f"
"%^RED%^l%^YELLOW%^a%^RED%^m%^YELLOW%^e%^RED%^s %^BOLD%^%^RED%^engulfing it. The image has been sewn with %^WHITE%^si%^BOLD%^%^BLACK%^l"
"%^WHITE%^ver %^BOLD%^%^RED%^and %^YELLOW%^golden %^BOLD%^%^RED%^threads that gleam with movement, making the image seem almost alive.%^RESET%^\n");
	set_value(3200);
	set_lore("%^BOLD%^%^RED%^Legends holds that the Robes of the Warmage belonged to a half-elf wizard called %^BOLD%^%^MAGENTA%^'Drognaki "
"Balshrun'%^BOLD%^%^RED%^. Droganki was one of the first %^RESET%^%^CYAN%^mages %^BOLD%^%^RED%^seen fighting in the front-ranks during the "
"battles of the Godswars. People never expected the half-elf to survive, but in the end he was one of the few left standing. It is said that "
"just before the last cataclysmic battle of the Godswars, the knight called 'Red' appeared before Drognaki and bestowed the blessing of battle "
"on his only armor... these robes. It is unknown what happened to Drognaki after the Godswars. But many ancient paintings has detailed a half-"
"elf only dressed in these robes holding his own against a mass of enemies.%^RESET%^");
	set_property("lore difficulty",25);
	set_size(2);
	set_property("enchantment",5);
      set_item_bonus("intelligence",2);
      set_item_bonus("influence",3);
      set_value(25000);
      set_wear((:TO,"wearme":));
      set_remove((:TO,"removeme":));
}

int wearme() {
      if((string)ETO->query_name() != "verbannon" && !avatarp(ETO)) {
          tell_object(ETO,"The magnificent robes seem not to fit you.");
          return 0;
      }
      tell_object(ETO,"%^BOLD%^%^RED%^The robes feel like a part of you as you slip the trusted garment on.%^RESET%^");
      tell_room(EETO,"%^BOLD%^%^RED%^"+ETO->QCN+" seems more powerful after slipping on "+ETO->QP+" robes.%^RESET%^",ETO);
      return 1;
}

int removeme() {
      tell_object(ETO,"%^BOLD%^%^RED%^You feel power slip from you as you remove your wonderful robes.%^RESET%^");
      return 1;
}