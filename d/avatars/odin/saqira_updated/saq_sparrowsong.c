//Updated to match player crafted gear 3/25/2020 - Odin
#include <std.h>
inherit "/d/common/obj/weapon/scimitar.c";

void create()
{
    ::create();
    set_name("sparrow's song");
    set_id(({ "sword", "song", "sparrow's song", "sparrowsong", "sparrows song", "scimitar" }));
    set_short("%^CYAN%^Sp%^BOLD%^a%^WHITE%^r%^CYAN%^r%^RESET%^%^CYAN%^ow%^BOLD%^%^WHITE%^'%^RESET%^%^CYAN%^s S%^BOLD%^o%^RESET%^%^CYAN%^ng%^RESET%^");
    set_obvious_short("%^RESET%^%^CYAN%^dragon claw shaped scimitar%^RESET%^");
    set_long("%^RESET%^%^CYAN%^Wro%^BOLD%^ugh%^RESET%^%^CYAN%^t out of the t%^BOLD%^al%^RESET%^%^CYAN%^on of a %^BOLD%^%^BLACK%^d%^BLUE%^r%^BLACK%^a%^BLUE%^g%^BLACK%^o%^BLUE%^n%^RESET%^%^CYAN%^, this s%^BOLD%^cim%^RESET%^%^CYAN%^itar is a sample of true e%^BOLD%^xc%^RESET%^%^CYAN%^ell%^BOLD%^enc%^RESET%^%^CYAN%^e. Its bl%^BOLD%^ad%^RESET%^%^CYAN%^e is carefully curved in re%^BOLD%^sem%^RESET%^%^CYAN%^ble%^BOLD%^nc%^RESET%^%^CYAN%^e of its %^BOLD%^%^BLACK%^d%^BLUE%^r%^BLACK%^a%^BLUE%^g%^BLACK%^o%^BLUE%^n%^RESET%^%^CYAN%^ claw form, enhanced with a razor sharp e%^BOLD%^dg%^RESET%^%^CYAN%^erunning all the way to the bent po%^BOLD%^in%^RESET%^%^CYAN%^t. Sashes of %^BOLD%^%^BLUE%^blue %^RESET%^%^CYAN%^and %^MAGENTA%^purple %^ORANGE%^leather %^CYAN%^are wound around the deli%^BOLD%^cat%^RESET%^%^CYAN%^e handle, which is cle%^BOLD%^arl%^RESET%^%^CYAN%^y made to fit a sle%^BOLD%^nde%^RESET%^%^CYAN%^r hand. The colors are well mat%^BOLD%^che%^RESET%^%^CYAN%^d to the %^BOLD%^bl%^BLUE%^uis%^CYAN%^h %^RESET%^%^CYAN%^tint of the semi %^RESET%^tr%^BOLD%^ans%^CYAN%^lu%^WHITE%^ce%^RESET%^nt %^RESET%^%^CYAN%^blade, giving it an %^BOLD%^a%^YELLOW%^u%^CYAN%^r%^YELLOW%^a %^RESET%^%^CYAN%^of stylish simpl%^BOLD%^ici%^RESET%^%^CYAN%^ty. Encased within the ta%^BOLD%^lo%^RESET%^%^CYAN%^n in breatht%^BOLD%^aki%^RESET%^%^CYAN%^ng detail is a likeness of a %^BOLD%^%^GREEN%^s%^MAGENTA%^p%^GREEN%^a%^MAGENTA%^r%^GREEN%^r%^MAGENTA%^o%^GREEN%^w %^RESET%^%^CYAN%^in full flight. A %^BOLD%^%^YELLOW%^golden %^RESET%^%^CYAN%^dice has been for%^BOLD%^ge%^RESET%^%^CYAN%^d onto e%^BOLD%^ith%^RESET%^%^CYAN%^er end of the swir%^BOLD%^lin%^RESET%^%^CYAN%^g %^BOLD%^%^WHITE%^p%^YELLOW%^l%^WHITE%^a%^YELLOW%^t%^WHITE%^i%^YELLOW%^n%^WHITE%^u%^YELLOW%^m %^RESET%^%^CYAN%^cross piece as a tribute to %^BOLD%^%^MAGENTA%^Tymora%^RESET%^%^CYAN%^.%^RESET%^");
    set_language("common");
    set_read("%^BOLD%^%^CYAN%^To fly and to soar, to sing upon the wind. %^BOLD%^%^CYAN%^A song lifts us like no other.%^RESET%^");
    set_value(5000);
    set_lore("The Man of Many Names is said to have fashioned this blade from the claw of the blue dragon slain by his lover, the Sparrow, when the beast beset the town of Shadow.  After its defeat the pair sought to have a weapon forged from the claw as a reminder of the battle and the luck that stood on their side.  But luck was needed in forging the sword and it is rumored that the crafting of this weapon was one of the Mastersmith's greatest challenges. Taming not only the power of the dragon's magic, but the storm of emotions that brewed during its creation.");
    set_property("lore difficulty", 20);
    set_property("enchantment", 6);
    set_item_bonus("caster level", 2);
    set_wield((: TO, "wield_func" :));
    set_unwield((: TO, "unwield_func" :));
    set_hit((: TO, "hit_func" :));
}

int wield_func()
{
    tell_room(environment(ETO), "%^BOLD%^%^WHITE%^The thrill of a %^GREEN%^s%^MAGENTA%^p%^GREEN%^a%^MAGENTA%^r%^GREEN%^r%^MAGENTA%^o%^GREEN%^w %^WHITE%^cuts through the air as " + ETOQCN + " takes hold of the %^RESET%^" + query_short() + ".%^RESET%^", ETO);
    tell_object(ETO, "%^BOLD%^%^WHITE%^Taking the %^RESET%^" + query_short() + " %^BOLD%^%^WHITE%^into your hand you feel an %^YELLOW%^el%^WHITE%^e%^YELLOW%^ct%^WHITE%^ri%^YELLOW%^cal %^WHITE%^current of %^GREEN%^em%^MAGENTA%^o%^GREEN%^t%^MAGENTA%^i%^GREEN%^on %^WHITE%^thrill through you like a bird's song as it takes to flight.%^RESET%^");
    return 1;
}

int unwield_func()
{
    tell_room(environment(ETO), "%^BOLD%^%^WHITE%^A twitter of %^GREEN%^b%^MAGENTA%^i%^GREEN%^r%^MAGENTA%^d %^GREEN%^s%^MAGENTA%^o%^GREEN%^n%^MAGENTA%^g %^WHITE%^catches your attention as " + ETOQCN + " unwields the " + query_short() + ".%^RESET%^", ETO);
    tell_object(ETO, "%^BOLD%^%^WHITE%^As you unwield the %^RESET%^" + query_short() + " %^BOLD%^%^WHITE%^you feel as though its %^YELLOW%^p%^WHITE%^o%^YELLOW%^w%^WHITE%^e%^YELLOW%^r %^WHITE%^is only resting for now.%^RESET%^");
    return 1;
}

int hit_func(object targ)
{
    if (!objectp(targ)) {
        return 0;
    }
    if (!objectp(ETO)) {
        return 0;
    }
    if (random(1000) < 300) {
        tell_room(environment(query_wielded()), "%^BOLD%^%^CYAN%^From the scimitar in " + ETOQCN + "'s hand, the pure, sweet sound of a %^GREEN%^s%^MAGENTA%^p%^GREEN%^a%^MAGENTA%^r%^GREEN%^r%^MAGENTA%^o%^GREEN%^w%^MAGENTA%^'%^GREEN%^s %^CYAN%^song erupts, stunning " + targ->QCN + " with its beauty.%^RESET%^", ({ ETO, targ }));
        tell_object(ETO, "%^BOLD%^%^CYAN%^The song of the %^GREEN%^s%^MAGENTA%^p%^GREEN%^a%^MAGENTA%^r%^GREEN%^r%^MAGENTA%^o%^GREEN%^w %^CYAN%^fills the air.  It's pure, %^MAGENTA%^heart-wrenching melody %^CYAN%^captivating " + targ->QCN + " with its %^GREEN%^beauty %^CYAN%^and leaving them open for easy attack.%^RESET%^");
        tell_object(targ, "%^BOLD%^%^CYAN%^The song of a %^GREEN%^s%^MAGENTA%^p%^GREEN%^a%^MAGENTA%^r%^GREEN%^r%^MAGENTA%^o%^GREEN%^w %^CYAN%^lifts from " + ETOQCN + "'s %^RESET%^" + query_short() + " %^BOLD%^%^CYAN%^and fills the air with its pure, heart-wrenching beauty.  You stand captivated by the aria as the melody, both %^GREEN%^sad %^CYAN%^and %^MAGENTA%^hopeful%^CYAN%^, plays upon your emotions.%^RESET%^");
        targ->set_paralyzed(roll_dice(5, 0) + 0);
        return 0;
    }
}
