// based on the storm robes by ~Circe~ 9/5/11
// reward for the Tharis plot

#include <std.h>
//inherit PARMOUR;
inherit "/d/common/obj/clothing/magerobe.c";

void init(){
    ::init();
	if(interactive(ETO)){
		TO->add_item_owner(ETOQN);	
	}
}

//Mantle of the Witchlord

void create(){
    ::create();
    set_heart_beat(1);
    set_name("mantle");
    set_id(({"robe","mantle","mantle of the witchlord","witchlord's mantle","coat","black coat"}));
    set_short("%^BOLD%^%^BLACK%^Ma%^RED%^n%^BLACK%^tle of the %^RESET%^"+
       "%^RED%^Wi%^BOLD%^t%^RESET%^%^RED%^chl%^BOLD%^%^BLACK%^o%^RESET%^"+
       "%^RED%^rd%^RESET%^");
    set_obvious_short("%^BOLD%^%^BLACK%^full-length black coat "+
       "accented with %^RESET%^%^RED%^red%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^This sleek coat is made from some sort of %^RESET%^matte black leather %^BOLD%^%^BLACK%^that is tailored to fit closely along the torso before flaring from the hips.  The hem reaches mid-calf, and the sleeves are rolled up to the elbows, revealing the unique %^RED%^red %^RESET%^%^RED%^w%^BOLD%^e%^RESET%^%^RED%^b%^BOLD%^b%^RESET%^%^RED%^i%^BOLD%^n%^RESET%^%^RED%^g %^BOLD%^%^BLACK%^that lines the coat.  %^RESET%^Sil%^BOLD%^v%^RESET%^er clasps %^BOLD%^%^BLACK%^in the shape of %^RESET%^%^BLUE%^spiders %^BOLD%^%^BLACK%^form double rows down the chest while the tall collar is graced with matching %^RESET%^silver dragons%^BOLD%^%^BLACK%^.  Their %^RED%^eyes %^BLACK%^are crafted from multi-faceted %^RED%^ru%^RESET%^%^RED%^b%^BOLD%^ies %^BLACK%^that seem to glow with their own inner light, almost as if recording everything they observe.%^RESET%^");
    set_lore("This coat is fashioned from the hide of a deep dragon so ancient that all the color has been leeched from its skin, leaving it this matte black that seems to soak up the light.  Crafted for the Witchlord of House Rilynath, the coat radiates power and prestige. It is said that the Witchlord won this garment as a prize for some service to the surface elves... but, surely, such a tale is as false as it is fantastic.");
    set_property("lore",18);
    set_weight(5);
    set_value(1500);
    while((int)TO->query_property("enchantment") != 5) 
    {
        TO->remove_property("enchantment");
        TO->set_property("enchantment",5);
    }
    set_item_bonus("magic resistance",2);
    set_item_bonus("bonus spell slots",2);
      set_item_bonus("spellcraft",10);
    set_type("clothing");
    set_limbs(({"torso"}));
    set_max_internal_encumbrance(21);
    set_wear((:TO,"wear_it":));
    set_remove((:TO,"remove_it":));
    set_struck((:TO,"struck":));
}

int query_size(){
    if(living(ETO)) return ETO->query_size();
    else return 3;
}

int wear_it(){
    if(((ETO->is_class("mage") || ETO->is_class("cleric") 
	|| ETO->is_class("psion") || ETO->is_class("sorcerer"))  &&
      (!ETO->is_class("fighter")) && (!ETO->is_class("thief")))) {
	    
        if((int)ETO->query_highest_level() < 15) { // standard +3 item cap
	        tell_object(ETO,"The robe snaps away from your body as you try to wear it.");
            if(!ETO->query_invis()) {
                tell_room(EETO,"With a mighty snap, the coat seems to snatch itself away from "+ETOQCN+"'s attempt to wear it.",ETO);
            }
	        return 0;
        }


    	if(!TO->query_owns_item(ETOQN)) {
            tell_room(EETO,"%^RESET%^%^RED%^The %^BOLD%^eyes %^RESET%^%^RED%^of the dragons flash red as they strike %^"+ETOQCN+"!%^RESET%^",ETO);
            tell_object(ETO,"%^BOLD%^%^RED%^You feel a flash of pain in your neck as something strikes you when you try to wear the coat!%^RESET%^");
	        ETO->do_damage("torso",(random(50)+10));
	        return 0;
	}
    
        if(!ETO->query_invis()){
            tell_room(EETO,"%^BOLD%^%^BLACK%^A low growl fills the room as "+ETOQCN+" slips into a coat.%^RESET%^",ETO);
        }else{
            tell_room(EETO,"%^BOLD%^%^BLACK%^You hear a strange growl that fades on the breeze.%^RESET%^",EETO);
        }
        
        tell_object(ETO,"%^BOLD%^%^BLACK%^You hear a low growl from the %^RED%^dragon %^BLACK%^pendants as the coat molds to your body.%^RESET%^");
        set_item_bonus("charisma",4);
        ETO->add_sight_bonus(-5);
        set_heart_beat(1);
        return 1;
    }
    
    return 0;
}

int remove_it(){
    
    tell_object(ETO,"%^RED%^Life fades from the dragons as you remove the robes.%^RESET%^");
    ETO->add_sight_bonus(5);
    set_item_bonus("charisma",-4);
    return 1;
}

int struck(int damage, object what, object who){
    if(!objectp(who)) return 1;
    if(!(random(2))) {

        tell_room(EETO,"%^BOLD%^%^BLACK%^The %^RED%^dragons %^BLACK%^on "+ETOQCN+"'s coat "+
           "seem to shift and grow, roaring to life as they deflect "+who->QCN+"'s "+
           "blow!%^RESET%^",({who,ETO}));

        tell_object(who,"%^BOLD%^%^BLACK%^As you move to strike "+ETOQCN+", "+
           "the %^RED%^dragons %^BLACK%^on "+ETO->QP+" coat roar to life, "+
           "deflecting your blow!%^RESET%^");
        tell_object(ETO,"%^BOLD%^%^BLACK%^As "+who->QCN+" moves to strike you, "+
           "power surges through your coat. The %^RED%^dragons %^BLACK%^roar to life, "+
           "deflecting "+who->QP+" blow!%^RESET%^");

        if(!random(4)) {
            tell_room(EETO,"%^RESET%^%^RED%^With a might hiss, the dragon "+
              "spews a cone of %^GREEN%^acid %^RED%^at "+who->QCN+"!%^RESET%^",who);

            tell_object(who,"%^RESET%^%^RED%^With a might hiss, the dragon "+
              "spews a cone of %^GREEN%^acid %^RED%^at you!%^RESET%^");
            
            who->do_damage("torso",random(15)+15);
        }
        return (damage*(1/2));
    }
    return 1;
}

void heart_beat() {
    object owner,env;
    int i,xx,yy;
    env = ETO;
    if(!objectp(ETO)) return;

    if(objectp(env) && living (env)) {
        owner = env;
        env = EETO;
    }

    if((!(TO->query_worn())) || (ETO->query_invis())) {
        return;
    } 

    xx = random(500);
    
    if((xx > 495)) {
        tell_object(owner,"%^BOLD%^%^BLACK%^You feel %^RED%^power%^BLACK%^ surge through you.%^RESET%^");
    
        switch(random(4)) {
            case 0:
                tell_room(env,"%^BOLD%^%^BLACK%^A shadow stretches behind "+ETOQCN+", "+
                   "enlongating into the silhouette of a dragon.%^RESET%^", owner);
                break;
            case 1:
                tell_room(env,"%^BOLD%^%^RED%^The spiders on "+ETOQCN+"'s coat seem to spring to "+
                   "life and crawl all over "+ETO->QP+" chest.%^RESET%^",owner);
                break;
            case 2:
                tell_room(env,"%^RESET%^%^RED%^The eyes of the dragons on "+ETOQCN+"'s lapels "+
                   "suddenly %^BOLD%^glow %^RESET%^%^RED%^with an inner fire.%^RESET%^",owner);
                break;
            default:
                tell_room(env,"%^BOLD%^%^BLACK%^You hear muted laughter and feel eyes on "+
                   "you as the wind rustles "+ETOQCN+"'s coat, revealing the %^RED%^webbed lining%^BLACK%^.%^RESET%^",owner);
                break;
          }
    }
}
