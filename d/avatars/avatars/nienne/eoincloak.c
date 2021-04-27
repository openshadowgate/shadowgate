#include <std.h>
inherit "/d/common/obj/clothing/cloak";

void create() {
   ::create();
   set_name("cloak");
   set_id(({"cloak","whispy cloak","ashen cloak","hooded cloak","ashen hooded cloak","whispy ashen hooded cloak","whispy hooded cloak","mantle","Glamered Mantle","glamered mantle"}));
   set_short("%^BOLD%^%^BLACK%^Gl%^RESET%^am%^BOLD%^%^BLACK%^er%^RESET%^e%^BOLD%^%^BLACK%^d Ma%^RESET%^n%^BOLD%^%^BLACK%^tle%^RESET%^");
   set_obvious_short("%^BOLD%^%^BLACK%^whi%^RESET%^sp%^BOLD%^%^BLACK%^y a%^RESET%^sh%^BOLD%^%^BLACK%^en hooded cloak%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^This garment seems almost impossibly delicate, as likely woven of %^BOLD%^%^BLACK%^smoke "
"%^BOLD%^%^WHITE%^and %^RESET%^mist %^BOLD%^%^WHITE%^as of a real and tangible fabric. It holds roughly to the outline of "
"a long cloak, with a hood that could be lifted to conceal the wearer's features. The garment itself is of a mottled shade "
"of %^RESET%^a%^BOLD%^%^BLACK%^sh%^RESET%^en g%^BOLD%^%^BLACK%^ra%^RESET%^y%^BOLD%^%^WHITE%^, which seems somehow to slowly "
"change across its surface with movement and changes in ambient light, like a creature slinking from shadow to shadow. "
"Despite its visibly ethereal appearance, it shrouds what lies behind or beneath it in a %^BOLD%^%^BLACK%^pall of shadow"
"%^BOLD%^%^WHITE%^, through which is impossible to perceive. No hem lines the cloak, which trails off at the edges to become "
"mere whisps of %^BOLD%^%^CYAN%^air%^BOLD%^%^WHITE%^. The most substantial parts of the entire cloak are the hooks at either "
"side of the throat, forged of some %^RESET%^%^BLUE%^darkened %^BOLD%^%^WHITE%^and unreflective metal, which together clasp "
"it about the wearer's throat.%^RESET%^\n");
    while ((int)TO->query_property("enchantment") != 5) {
      TO->remove_property("enchantment");
      TO->set_property("enchantment",5);
    }
    set_lore("%^BOLD%^%^WHITE%^Such an item as this, crafted as if from the stuff of nature itself, could only bear the touch of "
"the fey. Such is both their command of, and their bond to, the natural living world that even their possessions and equipment may "
"be drawn straight from the substance of the world around them. They are often imbued with traits of the wilderness, although some "
"instead are laced with the deceptive magicks that the fey so highly prize.");
    set_value(7500);
    set_item_bonus("stealth",4);
    set_wear((:TO,"wearme":));
    set_remove((:TO,"removeme":));
}

int wearme() {
    if((string)ETO->query_name() != "eoin" && !avatarp(ETO)) {
      tell_object(ETO,"The cloak won't settle easily around your shoulders, constantly slipping away to one side or another like water.");
      tell_room(EETO,""+ETO->QCN+" can't get the cloak to settle into place.",ETO);
      return 0;
    }
    tell_object(ETO,"%^BOLD%^%^BLACK%^The cloak settles easily about your shoulders, falling into place as though it belongs there.%^RESET%^");
    tell_room(EETO,"%^BOLD%^%^BLACK%^The whispy cloak settles easily about "+ETO->QCN+"'s shoulders, falling into place as though it belongs there.%^RESET%^",ETO);
    tell_object(ETO,"%^BOLD%^%^WHITE%^The cloak's embrace makes you feel as though you could <glamer> yourself to go completely unnoticed.%^RESET%^");
    return 1;
}

int removeme() {
    tell_object(ETO,"%^BOLD%^%^BLACK%^The whispy cloak slips free with ease.%^RESET%^");
    return 1;
}

void init() {
   ::init();
   add_action("glamer_fun","glamer");
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
   new("/cmds/spells/g/_glamer")->use_spell(TP,0,40,100,"warlock");
   return 1;
}