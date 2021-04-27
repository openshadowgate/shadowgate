#include <std.h>
inherit OBJECT;

void create(){
    ::create();    
    set_name("cracked jawless skull");    
    set_id(({"skull","jawless skull","cracked skull","sinister skull"}));
    
    set_short("%^RESET%^%^WHITE%^cr%^BOLD%^a%^BLACK%^c"
        "%^RESET%^%^WHITE%^ked j%^BOLD%^a%^RESET%^wle%^BOLD%^s%^RESET%^s"
        " s%^BOLD%^k%^RESET%^ull%^RESET%^");
    
    set_long("%^BOLD%^%^WHITE%^About the size of an adult "
        "human's, this skull seems, physically, rather unremarkable"
        " beyond a jagged %^BLACK%^hole %^WHITE%^in the right side. "
        "Pale as moonstone, the bone itself is devoid of any flesh, "
        "evidently cleaned quite recently. As mundane as it appears, "
        "an aura of %^RESET%^%^RED%^hat%^BOLD%^%^RED%^r"
        "%^RESET%^%^RED%^ed %^BOLD%^%^WHITE%^hangs around it like "
        "a dense fog, almost tangible. The dark, empty eye sockets "
        "almost seem to wield %^RESET%^%^MAGENTA%^ma%^RED%^l"
        "%^BOLD%^%^RED%^i%^RESET%^%^MAGENTA%^gn in%^GREEN%^t"
        "%^MAGENTA%^ent %^BOLD%^%^WHITE%^as you stare into them, "
        "however long or briefly that may be.%^RESET%^");
   
    set_weight(1);
    set_value(0);
    set_heart_beat(1);
}


void heart_beat()
{
    
    if(!userp(ETO)) return;
    if(!interactive(ETO)) return;
     if((string)ETO->query_name() != "vaser"){
        tell_object(ETO,"%^BOLD%^%^BLACK%^Something about the skull's "
            "very presence casts a %^RESET%^%^CYAN%^shiver %^BOLD%^%^BLACK%^down "
            "your spine. The feeling only grows worse upon touching it, spreading "
            "into outright %^RESET%^%^RED%^fear %^BOLD%^%^BLACK%^as the truth "
            "of its foul existence touches your mind, terror and panic "
            "consuming you utterly--"
            "\n%^RESET%^%^BLUE%^And then the feeling abruptly vanishes. As your"
            " vision returns, you notice the skull at your feet...seems you've "
            "dropped it. You can't for the life of you remember why, or what's "
            "transpired in the past moments.");
        tell_room(EETO,"%^RESET%^%^RED%^"+ETO->QCN+"'s face becomes a mask of "
            "horror as they take up the skull, a soundless scream tearing from their "
            "gaping lips - then apruptly, "+ETO->QP+" eyes gloss over and "+ETO->QP+" "
            "arms fall loosely to the side, the skull dropping to "+ETO->QP+" "
            "feet.",ETO);
        ETO->force_me("drop cracked jawless skull");
        return;
    }
    
    switch(random(1001))
    {
        case 0..994:
            break;
       
        case 995..996:
       
            tell_object(ETO,"%^RESET%^%^RED%^A faint incoherent "
                "%^CYAN%^wh%^WHITE%^i%^CYAN%^spe%^WHITE%^ri%^CYAN%^ng "
                "%^RED%^echoes from the skull's depths, almost seeming to "
                "%^BOLD%^%^BLACK%^m%^WHITE%^o%^GREEN%^c%^BLACK%^k "
                "%^RESET%^%^RED%^you. Impossible, though - he is dead, "
                "couldn't have survived, gone, CAN'T still be here, gone"
                "deadgonedead, GONE, DEAD--"
                "\n%^RESET%^%^BLUE%^Your grasp on reality returns with a "
                "sense of relief, madness retreating into the recesses of "
                "your mind.");
                
            if(!ETO->query_invis())
            {
                tell_room(EETO,"%^RESET%^%^RED%^"+ETO->QCN+" freezes "
                    "suddenly, staring off into the unknown. A look of wild-eyed,"
                    " anguished fury crosses "+ETO->QO+" briefly, then "+ETO->QO+" "
                    "seems to calm.",ETO);
            }
            break;
       
        case 997..998:
       
            tell_object(ETO,"%^BOLD%^%^BLACK%^Something dances "
                "across the edge of your vision, retreating as soon as you turn"
                " to get a better look...then as your guard lowers, a blur to "
                "the side - turn, catch it!"
                "\n%^BOLD%^%^BLACK%^What you whirl to face is a being of "
                "%^RESET%^%^BLUE%^fl%^WHITE%^i%^BLUE%^cke%^WHITE%^r%^BLUE%^ing"
                " %^BOLD%^%^BLACK%^s%^WHITE%^h%^RESET%^a%^BOLD%^%^BLACK%^d"
                "%^WHITE%^o%^RESET%^w%^BOLD%^%^BLACK%^s, its grinning visage "
                "descending on you even now--"
                "\n%^RESET%^%^GREEN%^But the illusion, the hallucination, it "
                "breaks, leaving you struggling for breath...when will this "
                "madness end?");
            
            if(!ETO->query_invis())
            {
                tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETO->QCN+" begins "
                "looking around warily, as if searching for something. Just as "
                ""+ETO->QS+" seems to relax, "+ETO->QS+" turns suddenly, "
                "gaping upward at something unseen - then glances about in a "
                "daze, panting heavily.",ETO);
            }

            break;
       
        case 999..1000:
       
            if(!ETO->query_invis())
            {
                tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETO->QCN+" falls "
                    "into a fit of uncontrollable %^RESET%^%^MAGENTA%^g"
                    "%^BOLD%^%^BLACK%^i%^RESET%^%^MAGENTA%^g%^BOLD%^%^BLACK%^g"
                    "%^RESET%^%^MAGENTA%^l%^BOLD%^%^BLACK%^i%^RESET%^%^MAGENTA%^n"
                    "%^BOLD%^%^BLACK%^g as "+ETO->QS+" stares into the "
                    "%^RESET%^%^WHITE%^empty eyes %^BOLD%^%^BLACK%^of the skull "
                    "in "+ETO->QP+" hands, a %^RESET%^%^RED%^disturbed "
                    "%^MAGENTA%^g%^BOLD%^%^BLACK%^%^r%^WHITE%^i%^RESET%^%^MAGENTA%^n"
                    " upon "+ETO->QP+" face.",ETO);
            }
        break;
    }
}
