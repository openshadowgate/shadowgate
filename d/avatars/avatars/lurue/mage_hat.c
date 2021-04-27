// Mage Hat  - Savini's Cap - LoKi - 03-02-2008

#include <std.h>
inherit ARMOUR;



void create(){
    ::create();
    set_type("clothing");
    set_id(({"hat","summoner hat","Savini's hat","blue hat"}));
    set_name("Savini's Hat");
    set_short("%^RESET%^%^BOLD%^%^BLUE%^Sa%^RESET%^%^BLUE%^v%^RESET%^%^BOLD%^"+
"%^BLUE%^i%^RESET%^%^CYAN%^n%^RESET%^%^BOLD%^%^BLUE%^i's H%^RESET%^%^BLUE%^a"+
"%^RESET%^%^BOLD%^%^BLUE%^t of S%^RESET%^%^BOLD%^%^CYAN%^u%^RESET%^%^BLUE%^m"+
"%^RESET%^%^BOLD%^%^BLUE%^mo%^RESET%^%^CYAN%^n%^RESET%^%^BOLD%^%^BLUE%^i"+
"%^RESET%^%^BLUE%^n%^RESET%^%^BOLD%^%^BLUE%^g%^RESET%^");
    set_obvious_short("%^RESET%^%^BOLD%^%^BLUE%^cr%^RESET%^%^BLUE%^o%^RESET%^%"+
"^BOLD%^%^BLUE%^oked bl%^RESET%^%^BLUE%^u%^RESET%^%^BOLD%^%^BLUE%^e ha%^RESET%^"+
"%^BLUE%^t%^RESET%^");
    set_long("%^RESET%^%^BOLD%^%^BLUE%^This hat is made of a s%^RESET%^%^BLUE%^o"+
"%^RESET%^%^BOLD%^%^BLUE%^ft fe%^RESET%^%^BLUE%^l%^RESET%^%^BOLD%^%^BLUE%^t, and"+
" even though it looks old, the felt is still %^RESET%^%^BLUE%^soft %^RESET%^"+
"%^BOLD%^%^BLUE%^and there are no tears or tatters. The blue is the color of a d"+
"%^RESET%^%^CYAN%^e%^RESET%^%^BOLD%^%^BLUE%^ep se%^RESET%^%^CYAN%^a%^RESET%^%^BOLD%^"+
"%^BLUE%^, with a %^RESET%^%^RED%^th%^RESET%^%^BOLD%^%^RED%^i%^RESET%^%^RED%^ck red "+
"%^RESET%^%^BOLD%^%^RED%^t%^RESET%^%^RED%^hre%^RESET%^%^BOLD%^%^RED%^a%^RESET%^%^RED%^"+
"d %^RESET%^%^BOLD%^%^BLUE%^woven into the fabric in intricate patterns of %^RESET%^"+
"%^BOLD%^%^BLACK%^arcane symbols%^RESET%^%^BOLD%^%^BLUE%^. The hat is large, and without"+
" any structure, it flops down constantly. The inside of the hat, strangely, is a pure "+
"%^RESET%^%^BOLD%^%^BLACK%^bl%^RESET%^%^WHITE%^a%^RESET%^%^BOLD%^%^BLACK%^ck si%^RESET%^"+
"%^WHITE%^l%^RESET%^%^BOLD%^%^BLACK%^k%^RESET%^%^BOLD%^%^BLUE%^, and as hard as you "+
"look you can't see the entire inside of the hat at any time.%^RESET%^");
    set_property("enchantment",1);
    set_ac(0);
    set_limbs(({"head"}));
    set_weight(3);
    set_value(15000);
    set_property("lore",18);
    set_lore("%^BOLD%^%^BLACK%^Savini was a summoner of great skill, if not great forsight. "+
"He could summon most any creature, demon, devil or spirit. His skills were so great that he"+
" was able to place a lot of his smaller work in the hands of apprentices and worked instead "+
"on his ultimate project... Summoning himself! (Did I mention Savini was a gnome?) When he "+
"tried however, to the amazement of his apprentices, he reached into his hat and... "+
"disapeared. %^RESET%^");
    set_wear((:TO,"wear_func":));
    set_remove((:TO,"remove_func":));
    set_struck((:TO,"struck_func":));
}

int wear_func(){
if(((int)ETO->query_highest_level() < 28)){
      tell_room(EETO,"%^BLACK%^%^BOLD%^The hat falls off of "+ETOQCN+"%^BLACK%^%^BOLD%^'s head",ETO);
      tell_object(ETO,"%^BLACK%^%^BOLD%^You can't seem to figure out how to put on the hat%^RESET%^");
    return 0;
    }
   
   if((int)ETO->query_highest_level() > 27){
      tell_room(EETO,"%^RESET%^%^BLUE%^With a smile, "+ETOQCN+"%^RESET%^%^BLUE%^ sets the hat on their head",ETO);
      tell_object(ETO,"%^RESET%^%^BLUE%^You put on the hat with a smile%^RESET%^");
    return 1;
    }

    tell_room(EETO,"%^BLACK%^%^BOLD%^The hat falls off of "+ETOQCN+"%^BLACK%^%^BOLD%^'s head",ETO);
    tell_object(ETO,"%^BLACK%^%^BOLD%^You can't seem to figure out how to put on the hat%^RESET%^");
}

int remove_func(){
    tell_room(EETO,"%^RESET%^%^BLUE%^You can hear some muffled sounds coming from "+ETOQCN+"%^RESET%^"+
"%^BLUE%^'s hat as they remove it%^RESET%^",ETO);
    tell_object(ETO,"%^BLACK%^%^BOLD%^You hear someone screaming at you from far away... in.. gnomish"+
"?%^RESET%^");
    return 1;
}

int struck_func(int damage, object what, object who){
        if(random(1000) < 150){

            switch(random(2)){
        case 1:
            tell_room(EETO,"%^RESET%^%^BOLD%^With a smirk, "+ETOQCN+"%^RESET%^%^BOLD%^ removes the hat "+
"and summons a GREAT WYRM! Alas it can't fit through the hat and instead a blast of it's wet musky "+
"breath buffets "+who->QCN+" dead on...");
            who->set_paralyzed(random(2));
            return damage; 
        break;

        default:
            tell_room(EETO,"%^RESET%^%^CYAN%^Reaching a hand into the hat, "+ETOQCN+" pulls out a "+
"handful of monsters. They take up defensive positions.%^RESET%^");
            new("/cmds/spells/m/_monster_summoning_ii.c")->use_spell(ETO,0,20,100,"mage");
        break;
        
        return 0;

            }
        }
}
