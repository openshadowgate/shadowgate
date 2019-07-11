//Grumbar Weapon Spell
#include <std.h>
inherit "/d/magic/obj/weapons/godwpns";

void create()
{
   ::create();
        set_name("%^RESET%^%^ORANGE%^Fi%^WHITE%^s%^ORANGE%^t"+
                " of St%^BOLD%^%^BLACK%^o%^RESET%^%^ORANGE%^ne%^RESET%^");
        set_short("%^RESET%^%^ORANGE%^Fi%^WHITE%^s%^ORANGE%^t"+
                " of St%^BOLD%^%^BLACK%^o%^RESET%^%^ORANGE%^ne%^RESET%^");
        set_id(({"hammer","fist of stone","weapon","fist"}));
        set_long("This is possibly the most sturdy, bulky hammer you've "+
               "ever seen.  Formed of %^BOLD%^%^WHITE%^adamantium%^RESET%^, "+
               "it carries a wide flattened head upon one side, "
               "counterbalanced by a blunted conical spike upon the opposing "
               "side.  Tracings of %^YELLOW%^fine golden metal %^RESET%^line "
               "where the head meets the handle of the hammer, which is "
               "crafted of the same metal as the rest of the weapon.  "
               "Embedded within the upper handle, between the head and the "
               "spike, are two flawless sardonyx gemstones of a %^RED%^deep "
               "earthy hue%^RESET%^, set upon either face of the handle.");
        set_value(0);
        set_hit((:TO,"hit_func":));
}
int hit_func(object targ){
        targ = ETO->query_current_attacker();
        if(!objectp(ETO)) return 1;
        if(!objectp(targ)) return 1;

        if(!random(10)) {
        tell_object(ETO,"%^ORANGE%^You slam "+targ->QCN+" with a solid, "+
                        "forceful blow of your hammer.%^RESET%^");
        tell_object(targ,"%^ORANGE%^"+ETO->QCN+" slams you with a solid, "+
                        "forceful blow of "+ETO->QP+" hammer.%^RESET%^");
        tell_room(environment(ETO),"%^ORANGE%^"+ETO->QCN+" slams "+targ->QCN+
                        " with a solid, forceful blow of "+ETO->QP+
                        " hammer.%^RESET%^",({ETO,targ}));
                targ->do_damage("torso",random(4)+4);
        return 1;
   }
}
