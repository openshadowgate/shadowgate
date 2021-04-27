#include <std.h>
inherit "/d/common/obj/clothing/cloak";

void create() {
   ::create();
   set_name("amulet");
   set_id(({"amulet","platinum amulet"}));
   set_obvious_short("%^BOLD%^%^WHITE%^pl%^BOLD%^%^CYAN%^a%^BOLD%^%^WHITE%^ti%^RESET%^nu%^BOLD%^%^WHITE%^m am%^BOLD%^%^CYAN%^u%^BOLD%^%^WHITE%^let%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^Elegant in its simplicity, this teardrop amulet hangs from a chain of fine but sturdy %^BOLD%^%^CYAN%^platinum "
"%^BOLD%^%^WHITE%^links. The pendant itself is of the same %^YELLOW%^brilliant %^BOLD%^%^WHITE%^platinum metal, with softly curved edges and a "
"flattened back to rest against the wearer's chest. Upon the upper surface of the pendant, a single curved %^BOLD%^%^BLACK%^claw "
"%^BOLD%^%^WHITE%^has been printed into the metal and highlighted in some unknown crimson substance that %^RESET%^%^RED%^gl%^BOLD%^%^RED%^e"
"%^RESET%^%^RED%^ams %^BOLD%^%^WHITE%^with an unsettling light.%^RESET%^\n");
    while ((int)TO->query_property("enchantment") != 5) {
      TO->remove_property("enchantment");
      TO->set_property("enchantment",5);
    }
    set_size(-1);
    set_type("ring");
    set_value(500);
    set_wear((:TO,"wearme":));
    set_remove((:TO,"removeme":));
    set_property("death keep",1);
}

int wearme() {
    if((string)ETO->query_name() != "arvellon" && !avatarp(ETO)) {
      tell_object(ETO,"The amulet chain slips through your fingers like water when you try to clasp it.");
      return 0;
    }
    tell_object(ETO,"%^BOLD%^%^BLACK%^The amulet settles about your neck, its teardrop pendant surprisingly cold against your chest.%^RESET%^");
    tell_object(ETO,"%^BOLD%^%^WHITE%^You remember that you can resume your true fey'ri form if you <transform> yourself.%^RESET%^");
    return 1;
}

int removeme() {
    tell_object(ETO,"%^BOLD%^%^BLACK%^The amulet clasp slips free and the chain runs through your fingers like water.%^RESET%^");
    return 1;
}

void init() {
   ::init();
   add_action("glamer_fun","transform");
}

int glamer_fun(string str) {
   object shape;
   if(!objectp(TP)) return 0;
   if(!objectp(ETO)) return 0;
   if(!TO->query_worn()) return 0;
   if(objectp(shape = ETO->query_property("shapeshifted")) || objectp(shape = ETO->query_property("altered"))) {
     tell_object(ETO,"%^BOLD%^%^WHITE%^You are already changed!%^RESET%^");
     return 1;
   }
   new("/d/avatars/nienne/spells/_alter_self_feyri")->use_spell(TP,0,40,100,"mage");
   return 1;
}