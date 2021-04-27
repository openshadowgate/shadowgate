#include <std.h>
inherit OBJECT;

int charges;

void create() {
    ::create();
    set_name("banded onyx prism");
    set_short("%^BOLD%^%^BLACK%^Prism of M%^RESET%^%^ORANGE%^en%^BOLD%^%^BLACK%^d%^RESET%^%^ORANGE%^in%^BOLD%^%^BLACK%^g%^RESET%^");
    set_obvious_short("%^BOLD%^%^BLACK%^b%^RESET%^a%^BOLD%^%^BLACK%^nded on%^RESET%^%^ORANGE%^y%^BOLD%^%^BLACK%^x p%^RESET%^%^ORANGE%^r%^BOLD%^%^BLACK%^ism%^RESET%^");
    set_id(({"prism","onyx prism","banded onyx prism","prism of mending","Prism of Mending"}));
    set_long("%^RED%^This small, solid piece of %^BOLD%^%^BLACK%^ban%^RESET%^%^ORANGE%^d%^BOLD%^%^BLACK%^ed "
"onyx %^RESET%^%^RED%^would fit comfortably in the hand, with bluntly tapered ends at four points. Three of "
"these form the triangular base, equally spaced from its centre, while the fourth lies at the peak of the "
"prism. Thin veins of %^WHITE%^c%^ORANGE%^o%^WHITE%^l%^ORANGE%^o%^WHITE%^r %^RED%^break up its dark, nearly "
"%^BOLD%^%^BLACK%^black %^RESET%^%^RED%^surface, giving it a softly mottled appearance.%^RESET%^");
    set_lore("%^WHITE%^%^BOLD%^As a highly prized artifact of ancient high-elven society, this item was "
"devised over many centuries of arcane research. The elves did create, among their many other inventions, a "
"means by which to trap the spell of mending within an item. Such items were often given to those going on "
"long and harsh journeys, as a means to maintain their equipment without repairs. Following the crown wars "
"and the many centuries since, most of these items are now lost, though you're fairly sure you could still "
"activate this one if you tried to %^YELLOW%^<mend item>%^WHITE%^.%^RESET%^\n");
    set_property("lore difficulty",25);
    set_weight(1);
    set_value(6500);
    charges = 25;
}

void init() {
    ::init();
    add_action("mend_me","mend");
}

void mend_me(string str) {
    object mytarg;
    if(!userp(ETO)) {
      notify_fail("You must be holding the prism to activate it.\n");
      return 0;
    }
    if(!str) {
      notify_fail("What do you want to mend?\n");
      return 0;
    }
    if(!mytarg = present(str,ETO)){
      notify_fail("You aren't carrying a "+str+".\n");
      return 0;
    }
    if(!charges){
      notify_fail("The prism doesn't react. It seems to be out of charges.\n");
      return 0;
    }
    tell_object(ETO,"%^ORANGE%^You concentrate upon the prism in your hand, and it pulses briefly with a "
"%^WHITE%^dull glow%^ORANGE%^. Looking over the "+str+", you realise all the damages upon it have been "
"mended!%^RESET%^");
    tell_room(EETO,"%^ORANGE%^"+ETO->QCN+" concentrates upon the prism in "+ETO->QP+" hand, and it pulses "
"briefly with a %^WHITE%^dull glow%^ORANGE%^. Looking over the "+str+", you realise all the damages upon it "
"have been mended!%^RESET%^",ETO);
    mytarg->set_overallStatus(100);
    charges--;
    return 1;
}

int isMagic(){ return 1; }
