#include <std.h>
inherit ARMOUR;

void create(){
	::create();
		set_heart_beat(1);
        set_name("bracelet");
        set_id(({ "bracelet", "armlet", "bangle", "serpent's coil", 
			"coil" }));
		set_short("%^BOLD%^%^BLACK%^s%^RESET%^%^RED%^e%^BOLD%^r"+
			"%^RESET%^%^RED%^p%^BOLD%^%^BLACK%^en%^RED%^t"+
			"%^BLACK%^'s c%^RESET%^%^RED%^o%^BOLD%^i%^BLACK%^"+
			"l%^RESET%^");
        set_obvious_short("%^RESET%^%^ORANGE%^a %^BOLD%^%^BLACK%^"+
			"s%^RESET%^%^RED%^n%^BOLD%^a%^BLACK%^ke %^RESET%^"+
			"%^ORANGE%^shaped bracelet%^RESET%^");
		set_long("%^RESET%^%^ORANGE%^This delicate bracelet is made "+
			"up of a hundred small, jointed box-links that form the "+
			"body of this %^RED%^%^BOLD%^ruby %^RESET%^%^ORANGE%^and "+
			"%^BOLD%^%^BLACK%^onyx %^RESET%^%^ORANGE%^serpent.  "+
			"Delicate in form, the head of the snake like being "+
			"rests near the wrist while the body coils around the "+
			"forearm several times and ends with a narrow %^BOLD%^"+
			"%^BLACK%^black rattle%^RESET%^%^ORANGE%^.  A base of "+
			"%^WHITE%^mithril %^ORANGE%^forms the links and diamond "+
			"shaped silvers of %^BOLD%^%^BLACK%^onyx %^RESET%^"+
			"%^ORANGE%^and %^BOLD%^%^RED%^ruby %^RESET%^%^ORANGE%^"+
			"form the intricate design along the back of the "+
			"snake.  Two tiny %^WHITE%^opal %^ORANGE%^chips have "+
			"been set for eyes and the jaw is hinged to "+
			"occasionally display a slender %^BOLD%^%^RED%^ruby fork "+
			"tongue%^RESET%^%^ORANGE%^.%^RESET%^");
        set_weight(2);
        set_value(5000);
        set_lore("Awarded to Innaeli of Talos for her second place "+
			"story entry in the Second Annual Spooky Story Contest, "+
			"some might think that this bit of jewelry has multiple "+
			"meanings.  Imbued with a bit of magic to make it seem "+
			"alive, the serpent like form slithers and moves around "+
			"the arm, occasionally rattling a warning.  Though what "+
			"that warning is, could be anyone's guess.  Others might "+
			"think it appropriate an award for its design is both "+
			"beautiful and deadly appearing, much like the one who "+
			"wears it.");
        set_property("lore difficulty",12);
        set_type("ring");
        set_limbs(({ "right hand" }));
        set_size(2);
        set_property("enchantment",0);
        set_wear((:TO,"wear_func":));
        set_remove((:TO,"remove_func":));
        set_struck((:TO,"strike_func":));
}

int wear_func(){
        tell_room(environment(ETO),"%^RED%^The warning rattle of a "+
			"snake can be heard as"+ETOQCN+" wears a serpent shaped "+
			"bracelet.%^RESET%^",ETO);
        tell_object(ETO,"%^RED%^%^BOLD%^The small rattle shakes as "+
			"you slip the bracelet on.%^RESET%^");
        return 1;
}

int remove_func(){
        tell_room(environment(ETO),"%^RED%^The warning rattle of a "+
			"snake can be heard as"+ETOQCN+" removes a serpent "+
			"shaped bracelet.%^RESET%^",ETO);
        tell_object(ETO,"%^RED%^%^BOLD%^The small rattle shakes as "+
			"you remove the bracelet.%^RESET%^");
        return 1;
}

int strike_func(int damage, object what, object who){
        if(random(1000) < 50){
        tell_room(environment(query_worn()),"%^BOLD%^%^RED%^"+
			"Uncoiling from its secure spot around"+ETOQCN+"'s "+
			"arm, the %^RESET%^"+query_short()+"%^BOLD%^%^RED%^ "+
			"strikes out at "+who->QCN+", burying tiny poisoned "+
			"fangs into "+who->QCN+"'s exposed flesh.%^RESET%^",
			({ETO,who}));
        tell_object(ETO,"%^BOLD%^%^RED%^Uncoiling from its secure "+
			"spot around your arm, the %^RESET%^"+query_short()+""+
			"%^BOLD%^%^RED%^ strikes out at your enemy, burying "+
			"tiny poisoned fangs into their exposed flesh.%^RESET%^");
        tell_object(who,"%^BOLD%^%^RED%^Uncoiling from its secure "+
			"spot around "+ETOQCN+"'s arm, the %^RESET%^"+
			""+query_short()+"%^BOLD%^%^RED%^ strikes out at you, "+
			"burying tiny poisoned fangs into your exposed flesh."+
			"%^RESET%^");
                who->set_paralyzed(roll_dice(2,4));
return damage;  }

}

//Following based upon Storm Robes heartbeat - Octothorpe 12/23/08
///d/dagger/derro/obj/Stormrobe.c
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
   yy = random(4);
   
   if((xx > 997)) {
      switch(yy) {
         case 0:
            tell_object(ETO,"%^BOLD%^%^BLACK%^The snake coils around "+
               "your arm, the small box-links feels startlingly like "+
               "scales!%^RESET%^");
            tell_room(EETO,"%^BOLD%^%^BLACK%^The bracelet on "+ETOQCN+"'s "+
               "arm coils around their wrist almost as if its a living "+
               "snake!%^RESET%^",ETO);
            break;
         case 1:
            tell_object(ETO,"%^RESET%^%^ORANGE%^The %^BOLD%^%^BLACK%^"+
               "onyx %^RESET%^%^ORANGE%^and %^BOLD%^%^RED%^ruby "+
               "%^RESET%^%^ORANGE%^snake hisses, flicking its tiny "+
               "%^BOLD%^%^RED%^ruby tongue %^RESET%^%^ORANGE%^"+
               "outward.%^RESET%^");
            tell_room(EETO,"%^RESET%^%^ORANGE%^A flicker of %^BOLD%^"+
               "%^RED%^ruby %^RESET%^%^ORANGE%^alerts you to the "+
               "movement of "+ETOQCN+"'s bracelet. Did that snake "+
               "just open its mouth and hiss?%^RESET%^",ETO);
            break;
         case 2:
            tell_object(ETO,"%^BOLD%^%^RED%^The snake rattles its "+
               "small tail causing the little links to clatter with "+
               "a realistic sound.%^RESET%^");
            tell_room(EETO,"%^BOLD%^%^RED%^You hear the sound of a "+
               "snake's warning rattle.%^RESET%^",ETO);
            break;
         case 3:
            tell_object(ETO,"%^RESET%^%^ORANGE%^The snake slithers "+
               "up your arm and hisses quietly in your ear. The feel "+
               "of its tiny %^BOLD%^%^RED%^ruby tongue %^RESET%^"+
               "%^ORANGE%^oddly realistic.%^RESET%^");
            tell_room(EETO,"%^RESET%^%^ORANGE%^You watch with "+
               "amazement as "+ETOQCN+"'s bracelet comes to life "+
               "and slithers up their arm to hiss against their "+
               "ear.%^RESET%^",ETO);
            break;
      default:
      tell_object(ETO,"Something broke, please contact a Imm.");
         return 0;
      }
   }
}
