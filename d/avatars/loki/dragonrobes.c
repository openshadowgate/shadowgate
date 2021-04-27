// Dragon Robes - Based off of Storm Robes - LoKi
#include <std.h>
inherit PARMOUR;
object ARMO;

void init(){
    ::init();
	if(interactive(ETO))
 	{
		TO->add_item_owner(ETOQN);	
	}
}

void create(){
    ::create();
    set_heart_beat(1);
    set_name("robes");
    set_id(({"robe","robes","dragon robe","dragon robes","scaled robes","scales of the guardian"}));
    set_short("%^RESET%^%^CYAN%^Sc%^RESET%^%^BOLD%^%^CYAN%^a%^RESET%^%^CYAN%^"+
"les o%^RESET%^%^BOLD%^%^CYAN%^f%^RESET%^%^CYAN%^ the G%^RESET%^%^MAGENTA%^"+
"u%^RESET%^%^CYAN%^ard%^RESET%^%^MAGENTA%^i%^RESET%^%^CYAN%^an%^RESET%^");
    set_obvious_short("%^RESET%^%^CYAN%^shi%^RESET%^%^BOLD%^%^CYAN%^"+
"m%^RESET%^%^CYAN%^meri%^RESET%^%^BOLD%^%^CYAN%^n%^RESET%^%^CYAN%^g "+
"dr%^RESET%^%^MAGENTA%^a%^RESET%^%^CYAN%^gon%^RESET%^%^MAGENTA%^s"+
"%^RESET%^%^CYAN%^cale rob%^RESET%^%^BOLD%^%^CYAN%^e%^RESET%^%^CYAN%^"+
"s%^RESET%^");
    set_long("%^RESET%^%^CYAN%^This robe has a fine %^RESET%^"+
"%^MAGENTA%^gl%^RESET%^%^WHITE%^o%^RESET%^%^MAGENTA%^ssy lo%^RESET%^"+
"%^WHITE%^o%^RESET%^%^MAGENTA%^k%^RESET%^%^CYAN%^. It is made of very"+
" small dragon scales which are strong and durable yet very soft and "+
"supple to the touch. The scales are metallic in appearance and sh"+
"%^RESET%^%^BOLD%^%^CYAN%^i%^RESET%^%^CYAN%^m%^RESET%^%^BOLD%^%^CYAN%^"+
"m%^RESET%^%^CYAN%^er as they reflect light. At times the scales of the"+
" robe seem to be alive as they move of their own accord. When the "+
"scales move the robe darkens, absorbing the light all around turning"+
" the robe %^RESET%^%^BOLD%^%^BLACK%^black%^RESET%^%^CYAN%^. When the"+
" robe stops moving it is alive again with vibrant color. Ir%^RESET%^"+
"%^MAGENTA%^i%^RESET%^%^CYAN%^desc%^RESET%^%^MAGENTA%^e%^RESET%^%^CYAN%^"+
"nt and b%^RESET%^%^BOLD%^%^MAGENTA%^e%^RESET%^%^CYAN%^autiful.%^RESET%^");
    set_lore("%^RESET%^%^BOLD%^Deep under the ocean, where the sun's "+
"light never graces the waters, there lies a cave that is rumored to "+
"hold a portal beyond the realms of man.  It is through this portal which"+
" the island inhabitants of Rys claim Sholtra, the great dragon of sea "+
"and sky came into the world.  Birthed in a gout of fire and steam that "+
"lifted him from the deep depths through the waters that gave him form "+
"and into the air which gave him life.  Taking to the highest peak of "+
"the island, Sholtra watched over the island for a thousand years before"+
" the dark warriors came in their boats of wood and steel.  Lore tells "+
"that the inhabitants fought valiantly with their dragon guardian by "+
"their side, but the dark warriors wielded a fire metal which could slay "+
"even that which was crafted from the elements themselves.  And so Sholtra"+
" was destroyed, his glimmering scales flung far and wide as his essence"+
" was shattered.  Some claim that a few of the islanders who escaped the"+
" slaughter gathered these scales and tried to restore their guardian to "+
"life by sewing the scales together.%^RESET%^");
    set_property("lore",18);
    set_weight(5);
    set_value(1500);
    set_property("enchantment",2);
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
	|| ETO->is_class("psion"))  &&
      (!ETO->is_class("fighter")) && (!ETO->is_class("thief")))) {
	    
        if((int)ETO->query_highest_level() < 28) { // standard +4 item cap
	        tell_object(ETO,"The robe growls at the puny one "+
            "who tries to wear it.");
            if(!ETO->query_invis()) {
                tell_room(EETO,ETOQCN+"'s robe seems to mock "+ETO->QO+
                " with a soft growling.",ETO);
            }
	        return 0;
        }


    	if(!TO->query_owns_item(ETOQN)) {
            tell_room(EETO,"%^BOLD%^%^CYAN%^The robe seems to fold"+
" in on itself and tries to eat "+ETO->QO+"!%^RESET%^",ETO);
	        ETO->do_damage("torso",(random(50)+10));
	        return 0;
	    }
    
        if(!ETO->query_invis()) {
            tell_room(EETO,ETOQCN + "%^CYAN%^wraps themselves in "+
"the soft scaley robes.%^RESET%^",ETO);
        }
        
        tell_room(EETO,"%^BOLD%^%^BLUE%^Shimmering lights dance "+
        "across the scales as "+ETOQCN+"%^BOLD%^%^BLUE%^ wears "+
"the robe.%^RESET%^",ETO);

        tell_object(ETO,"%^BOLD%^%^BLUE%^Shimmering lights dance "+
        "across the scales as you wear the robe.%^RESET%^");

	  if((!ETO->is_class("psion") && ETO->is_class("mage")) ||
    	  (ETO->is_class("cleric") && !ETO->is_class("psion"))) 
    	  {		
        	ETO->set_property("magic resistance",15);
	  }
	    ETO->add_sight_bonus(5);
	    set_heart_beat(1);
	    return 1;
    }
    
    tell_object(ETO,"%^CYAN%^Wait, those aren't dragon scales, "+
"this obviously is a fake, you dont want to wear it!%^RESET%^");
    if(!ETO->query_invis()) {
        tell_room(EETO,ETOQCN+"%^CYAN%^ looks at a robe in "+
        ETO->QP+" possession and scoffs at it.%^RESET%^",ETO);
    }
    return 0;
}

int remove_it(){
    
    write("%^CYAN%^The shimmering in the scales fades as you remove the "+
    "robe.%^RESET%^");
    
    if(!ETO->query_invis()) {
        tell_room(EETO,"%^CYAN%^The scales stop shimmering in "+
        "its own light 	 as "+ETOQCN+"%^RESET%^%^CYAN%^ removes "+
        "it.%^RESET%^",ETO);
    }
    ETO->add_sight_bonus(-5);
    if((!ETO->is_class("psion") && ETO->is_class("mage")) ||
    (ETO->is_class("cleric") && !ETO->is_class("psion"))) 
    {
    
		ETO->set_property("magic resistance",-10); 
    }
    return 1;
}

int struck(int damage, object what, object who){
    if(objectp(who)) {
        tell_object(ETO,"%^RESET%^%^CYAN%^A Shadowy dragon figure blast at "+
        who->QCN+"%^RESET%^%^CYAN%^ as "+who->QO+" hits you "+
        "weaking "+who->QP+" blow!%^RESET%^");
    }

    if(!(random(2))) {

        tell_room(EETO,ETO->QCN+"%^RESET%^%^CYAN%^'s robe "+
        "suddenly snaps as a shadowy dragon leaps out and "+
        "knocks "+who->QCN+"'s blow off balance!",({who,ETO}));

        tell_object(who,"%^RESET%^%^MAGENTA%^As you try to hit "+
        ETO->QCN+"%^RESET%^%^CYAN%^ a spectral wing erupts from "+
        ETO->QP+ " robe and knocks you off balance, making your "+
        "blow less effective!%^RESET%^");

        if(!random(4)) {
            tell_room(EETO,"%^BOLD%^%^YELLOW%^A shimmering image of "+
            "a dragon snaps at "+who->QCN+" as "+who->QO+
            " touches them!%^RESET%^",who);

            tell_object(who,"%^BOLD%^%^YELLOW%^A shimmering dragon "+
            "leaps out at you as you strike the chains!%^RESET%^");
            
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
    yy = random(3);
    
    if((xx > 495)) {
        tell_object(owner,"\n%^CYAN%^The robe flaps restlessly as the colors "+
        "shift within its scales.\n%^RESET%^");
    
        switch(yy) {
            case 0:
                tell_room(env,"%^CYAN%^"+owner->QCN+"s robe shimmers softly "+
                "as the image of a dragon flows over.%^RESET%^",
                owner);
                break;
            case 1:
                tell_room(env,"%^BOLD%^%^YELLOW%^A scale drops off of "+
                owner->QCN+"'s robe and you see another quickly grow "+
                "to replace it.%^RESET%^",owner);
                break;
            case 2:
                tell_room(env,"%^BOLD%^%^CYAN%^Light shimmers off of"+
                " "+owner->QCN+"'s robe.%^RESET%^",owner);
                break;
            case 3:
                tell_room(env,"%^BOLD%^BLACK%^You hear the distant "+
                "flapping of wings!%^RESET%^",owner);
                break;
          }
    }
}
