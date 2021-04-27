// Altered for Aunuit ~Circe~ 8/15/15
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

void create(){
    ::create();
    set_name("mantle");
    set_id(({"robe","mantle","mantle of the valsharess","valsharess's mantle","gown","multicolored gown","gown of many colors"}));
    set_short("%^BOLD%^%^WHITE%^M%^CYAN%^a%^WHITE%^nt%^ORANGE%^l%^WHITE%^e "
       "%^CYAN%^of the %^MAGENTA%^V%^RED%^a%^MAGENTA%^lshar%^RED%^e%^MAGENTA%^ss%^RESET%^");
    set_obvious_short("%^RESET%^%^CYAN%^A splendid %^BOLD%^%^WHITE%^gown %^RESET%^%^CYAN%^of "
       "many %^BOLD%^%^WHITE%^c%^CYAN%^o%^RESET%^%^CYAN%^l%^BOLD%^%^BLUE%^o%^RESET%^"
       "%^MAGENTA%^r%^BLUE%^s%^RESET%^");
    set_long("%^RESET%^%^CYAN%^This resplendent gown is made from diaphanous silk that "
       "has been dyed so that the color gradually transitions from %^BOLD%^%^WHITE%^light "
       "%^RESET%^%^CYAN%^to %^BLUE%^dark%^CYAN%^; from the purest %^BOLD%^%^WHITE%^white "
       "%^RESET%^%^CYAN%^of a %^BOLD%^%^WHITE%^cum%^RESET%^u%^BOLD%^%^WHITE%^lus cl"
       "%^RESET%^o%^BOLD%^%^WHITE%^ud%^RESET%^%^CYAN%^, to the soft %^BOLD%^%^CYAN%^a"
       "%^RESET%^%^CYAN%^z%^BOLD%^%^CYAN%^ure %^RESET%^%^CYAN%^of the sky on a %^BOLD%^"
       "%^CYAN%^clear day%^RESET%^%^CYAN%^, then the dusky %^MAGENTA%^violet %^CYAN%^of "
       "%^MAGENTA%^tw%^BOLD%^%^BLACK%^i%^RESET%^%^MAGENTA%^li%^RESET%^g%^BOLD%^%^BLACK%^h"
       "%^RESET%^%^MAGENTA%^t %^CYAN%^and eventually the %^BOLD%^%^BLACK%^inky %^RESET%^"
       "%^BLUE%^blue%^CYAN%^-%^BOLD%^%^BLACK%^black %^RESET%^%^CYAN%^of %^BOLD%^%^BLACK%^"
       "m%^RESET%^%^BLUE%^i%^BOLD%^%^BLACK%^d%^RESET%^%^BLUE%^n%^BOLD%^%^BLACK%^ight%^RESET%^"
       "%^CYAN%^. Tiny %^BOLD%^%^WHITE%^crystals %^RESET%^%^CYAN%^are seamlessly affixed "
       "to the robe and give the dazzling impression of a sky lit by thousands of %^BOLD%^"
       "%^WHITE%^sp%^CYAN%^a%^WHITE%^rkl%^ORANGE%^i%^WHITE%^ng st%^RESET%^a%^BOLD%^%^WHITE%^"
       "rs%^RESET%^%^CYAN%^, during the day or night depending upon where they are placed.  "
       "The gown is sleeveless, with a neckline cut into a dramatic V that leaves much of "
       "the wearer's torso %^BOLD%^%^WHITE%^exposed%^RESET%^%^CYAN%^, and the back is open "
       "until just above the tailbone and tailored to complement an hourglass figure. The "
       "skirt is long and free fl%^BLUE%^o%^BOLD%^%^BLUE%^w%^RESET%^%^BLUE%^i%^RESET%^"
       "%^CYAN%^ng, with a high slit up the front that allows for greater mobility. While "
       "the %^RED%^sensu%^BOLD%^%^RED%^a%^RESET%^%^RED%^l %^CYAN%^garment leaves little to "
       "the imagination and would certainly require a confident wearer, its design is still "
       "elegant and the materials used to craft it are exquisite.");
	set_lore("It is said that this garment once belonged to Witchlord "
	   "Vic'daerrysn of House Rilynath. However, he found himself called "
	   "to the ways of he wild and to Rillifane's embrace so he placed his "
	   "mantle in the hands of Aunuit Rilynath for safe keeping. The archmage "
	   "Pyranda was meant to inherit the mantle, but tragically she was "
	   "assassinated before she could don it. As time went on, Aunuit, who "
	   "had once been a powerful enchantress but had lost her power whilst "
	   "dealing with the dark god Vhaeraun, began to long for the arcane. "
	   "Knowing the heart and soul of her priestess, Eilistraee lit a spark "
	   "within Aunuit so that she might once more feel whole. Aunuit felt it "
	   "would be fitting to take up the mantle, but it was still a thing of "
	   "darkness, corrupted by the influences of Lolth and Vhaeraun. Aunuit "
	   "brought the mantle to Eilistraee's shrine and placed it below the waters "
	   "there so that the goddess might cleanse it. The waters purged the "
	   "darkness from it, and when Aunuit lifted it from the waters of reflection, "
	   "she found it had been transformed into a beautiful gown, worthy of a queen.");
	set_property("lore difficulty",18);
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
	    
        if((int)ETO->query_level() < 35) { 
	        tell_object(ETO,"The robe snaps away from your body as you try to wear it.");
	        return 0;
        }


    	if(!TO->query_owns_item(ETOQN)) {
            tell_room(EETO,"This beautiful gown will not fit you.",ETO);
            return 0;
	}
    
        if(!ETO->query_invis()){
            tell_room(EETO,"%^RESET%^%^CYAN%^"+ETOQCN+" dons the luxurious gown, "
               "the %^BOLD%^%^WHITE%^c%^CYAN%^r%^ORANGE%^y%^CYAN%^s%^WHITE%^t"
               "%^RESET%^a%^BOLD%^%^WHITE%^ls sp%^CYAN%^a%^WHITE%^rkl%^ORANGE%^i"
               "%^WHITE%^ng%^RESET%^%^CYAN%^.%^RESET%^",EETO);
        }else{
            tell_room(EETO,"You hear a strange rustling sound.",ETO);
        }
        
        tell_object(ETO,"%^RESET%^%^CYAN%^You don the luxurious gown, the %^BOLD%^"
               "%^WHITE%^c%^CYAN%^r%^ORANGE%^y%^CYAN%^s%^WHITE%^t%^RESET%^a%^BOLD%^"
               "%^WHITE%^ls sp%^CYAN%^a%^WHITE%^rkl%^ORANGE%^i%^WHITE%^ng%^RESET%^%^CYAN%^.%^RESET%^");
        set_item_bonus("charisma",4);
        set_heart_beat(1);
        return 1;
    }
    
    return 0;
}

int remove_it(){
    tell_room(EETO,"%^RESET%^%^CYAN%^"+ETOQCN+" shrugs off the beautiful gown, "
       "watching it %^BOLD%^%^CYAN%^pool %^RESET%^%^CYAN%^around "+ETO->QP+" feet. %^RESET%^",ETO);
    tell_object(ETO,"%^RESET%^%^CYAN%^You shrug off the beautiful gown, "
       "watching it %^BOLD%^%^CYAN%^pool %^RESET%^%^CYAN%^around your feet.%^RESET%^");
    set_item_bonus("charisma",-4);
    return 1;
}

int struck(int damage, object what, object who){
    if(!objectp(who)) return 1;
    if(!(random(2))) {

        tell_room(EETO,"%^BOLD%^%^WHITE%^A %^CYAN%^magic%^RESET%^%^CYAN%^a"
           "%^BOLD%^%^CYAN%^l sh%^RESET%^%^CYAN%^i%^BOLD%^%^CYAN%^eld "
           "%^WHITE%^composed of pure %^ORANGE%^l%^WHITE%^i%^CYAN%^g"
           "%^ORANGE%^ht %^WHITE%^encompasses "+ETOQCN+", protecting "+ETO->QO+" "
           "from the onslaught.%^RESET%^",({who,ETO}));

        tell_object(who,"%^BOLD%^%^WHITE%^As you move to strike "+ETOQCN+", "
           "%^BOLD%^%^WHITE%^a %^CYAN%^magic%^RESET%^%^CYAN%^a"
           "%^BOLD%^%^CYAN%^l sh%^RESET%^%^CYAN%^i%^BOLD%^%^CYAN%^eld "
           "%^WHITE%^composed of pure %^ORANGE%^l%^WHITE%^i%^CYAN%^g"
           "%^ORANGE%^ht %^WHITE%^encompasses "+ETO->QO+", protecting "+ETO->QO+" "
           "from the onslaught.%^RESET%^");
        tell_object(ETO,"%^BOLD%^%^WHITE%^As "+who->QCN+" moves to strike you, "
           "%^BOLD%^%^WHITE%^a %^CYAN%^magic%^RESET%^%^CYAN%^a"
           "%^BOLD%^%^CYAN%^l sh%^RESET%^%^CYAN%^i%^BOLD%^%^CYAN%^eld "
           "%^WHITE%^composed of pure %^ORANGE%^l%^WHITE%^i%^CYAN%^g"
           "%^ORANGE%^ht %^WHITE%^encompasses you, protecting you "
           "from the onslaught.%^RESET%^");

        if(!random(4)) {
            tell_room(EETO,"%^BOLD%^%^ORANGE%^Gl%^WHITE%^o%^ORANGE%^wing "
               "o%^WHITE%^r%^ORANGE%^bs %^BOLD%^%^BLACK%^materialize around "
               ""+ETOQCN+"'s person. They expand and contract unpredictably "
               "before %^RESET%^%^RED%^e%^BOLD%^%^RED%^r%^RESET%^%^RED%^upting "
               "%^BOLD%^%^BLACK%^into %^ORANGE%^beams %^BLACK%^of pure "
               "%^ORANGE%^l%^WHITE%^i%^CYAN%^g%^ORANGE%^ht %^BLACK%^that sear "
               ""+who->QCN+".%^RESET%^",({who,ETO}));

            tell_object(who,"%^BOLD%^%^ORANGE%^Gl%^WHITE%^o%^ORANGE%^wing "
               "o%^WHITE%^r%^ORANGE%^bs %^BOLD%^%^BLACK%^materialize around "
               ""+ETOQCN+"'s person. They expand and contract unpredictably "
               "before %^RESET%^%^RED%^e%^BOLD%^%^RED%^r%^RESET%^%^RED%^upting "
               "%^BOLD%^%^BLACK%^into %^ORANGE%^beams %^BLACK%^of pure "
               "%^ORANGE%^l%^WHITE%^i%^CYAN%^g%^ORANGE%^ht %^BLACK%^that sear "
               "you.%^RESET%^");
            tell_object(ETO,"%^BOLD%^%^ORANGE%^Gl%^WHITE%^o%^ORANGE%^wing "
               "o%^WHITE%^r%^ORANGE%^bs %^BOLD%^%^BLACK%^materialize around "
               "you. They expand and contract unpredictably "
               "before %^RESET%^%^RED%^e%^BOLD%^%^RED%^r%^RESET%^%^RED%^upting "
               "%^BOLD%^%^BLACK%^into %^ORANGE%^beams %^BLACK%^of pure "
               "%^ORANGE%^l%^WHITE%^i%^CYAN%^g%^ORANGE%^ht %^BLACK%^that sear "
               ""+who->QCN+".%^RESET%^");
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

    xx = random(1000);
    
    if((xx > 995)) {
        tell_object(owner,"%^BOLD%^%^CYAN%^You feel a mixture of %^BLUE%^power%^CYAN%^ "
           "and %^WHITE%^serenity%^CYAN%^ surge through you.%^RESET%^");
    
        switch(random(4)) {
            case 0:
                tell_room(env,"%^BOLD%^%^WHITE%^The %^ORANGE%^light %^WHITE%^plays off the "
                   "tiny crystals dotting "+ETOQCN+"'s gown, revealing a c%^RESET%^o%^BOLD%^%^WHITE%^"
                   "rus%^RESET%^c%^BOLD%^%^WHITE%^at%^RESET%^i%^BOLD%^%^WHITE%^ng kaleidoscope "
                   "of %^ORANGE%^c%^CYAN%^o%^MAGENTA%^l%^WHITE%^o%^CYAN%^r%^ORANGE%^s%^WHITE%^.%^RESET%^", owner);
                break;
            case 1:
                tell_room(env,"%^RESET%^%^CYAN%^Some of the tiny %^BOLD%^%^WHITE%^crystals "
                   "%^RESET%^%^CYAN%^on "+ETOQCN+"'s gown begin to %^BOLD%^%^CYAN%^glow%^RESET%^"
                   "%^CYAN%^, their light coalescing to form familiar %^BOLD%^%^WHITE%^c"
                   "%^CYAN%^o%^WHITE%^nst%^ORANGE%^e%^WHITE%^llat%^ORANGE%^i%^CYAN%^o"
                   "%^WHITE%^ns%^RESET%^%^CYAN%^.%^RESET%^",owner);
                break;
            case 2:
                tell_room(env,"%^BOLD%^%^BLACK%^"+ETOQCN+"'s shadow begins to move of its "
                   "own accord, dancing elegantly whilst it swings a sword that "+ETO->QS+" "
                   "does not actually wield. %^RESET%^",owner);
                break;
            default:
                tell_room(env,"%^RESET%^%^MAGENTA%^Tiny %^WHITE%^m%^BOLD%^%^WHITE%^o"
                   "%^RESET%^tes %^MAGENTA%^suddenly flare into existence, surrounding "
                   ""+ETOQCN+" and bathing her in %^WHITE%^ether%^BOLD%^WHITE%^e%^CYAN%^"
                   "a%^RESET%^l l%^BOLD%^%^WHITE%^i%^ORANGE%^g%^RESET%^ht %^MAGENTA%^"
                   "before winking out of existence.",owner);
                break;
          }
    }
}
