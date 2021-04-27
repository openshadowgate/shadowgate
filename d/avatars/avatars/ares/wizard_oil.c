#include <std.h>

inherit OBJECT;

void create()
{
    ::create();

    set_id(({"jar","liquid","oil","wizard oil"}));

    set_obvious_short("%^CYAN%^A softly glowing jar of liquid%^RESET%^");
    set_short("%^CYAN%^W%^RESET%^i%^BOLD%^z%^CYAN%^a%^RESET%^r%^BOLD%^d%^RESET%^%^BOLD%^%^BLUE%^ oil%^RESET%^");

    set_long("%^RESET%^%^BOLD%^This jar is nearly as large as a small human head.  It is a "
        "square shape with a narrow neck that tapers up to a corked top.  "
        "Inside the jar an oozing %^CYAN%^blue liquid%^RESET%^%^BOLD%^ rolls back and forth as it is "
        "tilted.  The %^BLUE%^liquid%^RESET%^%^BOLD%^ seems to never actually touch the insides of the "
        "fortified glass but is kept apart from it by forces unknown.%^RESET%^");

    set_lore("%^CYAN%^It was said that the human mage Glanderia Linstad was so impressed by "
        "the tactics of an elven blade master that she witnessed in battle that she spent "
        "the next several years of her life researching a spell that would allow her "
        "to mimic their abilities.  She was never fully successful in her endeavor but she "
        "was able to create a magical oil, that when applied to a weapon, would impart the "
        "wielder with the ability to make the necessary gestures with their free hand which "
        "are necessary in shaping many divine, arcane and even psionic abilities.");

    set_weight(10);
    set_value(75000);
}

void init()
{
    ::init();
    add_action("apply","apply");
    return;
}

int apply(string str)
{
    object target;

    if(!stringp(str))
    {
        tell_object(TP,"You must pick something to apply the oil to.");
        return 1;
    }

    str = replace_string(str,"to ","");

    if(!objectp(target=present(str,TP)))
    {
        tell_object(TP,"You aren't carrying a "+str+"");
        return 1;
    }

    if(!target->is_weapon())
    {
        tell_object(TP,"The magic of the oil will only work on a weapon.");
        return 1;
    }

    tell_object(TP,"%^CYAN%^You turn the jar up and the fluid seems to ooze out "
        "onto your "+target->query_short()+" of it's own accord.");
    tell_room(ETP,"%^CYAN%^"+TP->QCN+" pours some glowing blue liquid out of a "
        "jar and onto "+TP->QP+" "+target->query_short()+".",TP);

    tell_object(TP,"%^BLUE%^Your "+target->query_short()+" is completely coated "
        "in the glowing goo before the liquid is absorbed into the material.");
    tell_room(ETP,"%^BLUE%^The liquid on "+TP->QCN+"'s "+target->query_short()+" "
        "is quickly absorbed into the material.");

    target->set_property("able to cast",1);

    TO->remove();
    return 1;
}


    