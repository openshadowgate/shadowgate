#include <std.h>
inherit ARMOUR;

// Death's Mask - Created February 2009 by Ari

/* Reward for Anson for his win at the 2008 Masquerade Ball 
and Storytelling Contest.   Held by Lurue.  Mask is fluff / rp item
and has no actual bonus or features beyond a small heartbeat set
of echoes that are meant to be spooky.  This should be 
considered a prop item.  I have ownered it to prevent it getting
into the hands of someone who may not be as trustworthy as 
the HM Anson is. */

// Item loosely based on code from Storm Robes.

string owner;

void init(){
	if(stringp(owner)) return;
	if(interactive(TP) && TP == ETO){
		owner = TPQN;
		set_size(TP->query_size());
	}
}
void create(){
	::create();
		set_heart_beat(1);
		
		set_name("skull mask");
		set_id(({"mask","skull mask","death's mask","death mask"}));
		set_short("%^BOLD%^%^BLACK%^D%^RESET%^%^RED%^e%^MAGENTA%^a"+
			"%^BOLD%^%^BLACK%^th's M%^RESET%^%^RED%^a%^BOLD%^"+
			"%^BLACK%^sk%^RESET%^");
		set_obvious_short("%^BOLD%^%^WHITE%^skull mask%^RESET%^");
		set_long("%^BOLD%^%^WHITE%^This life-like skull mask fits "+
			"easily over the face of the wearer and secures at the "+
			"back with a pair of %^BLACK%^black silk %^WHITE%^ties.  "+
			"One set going above the ears and the other set closer "+
			"to the jaw line to keep the mask firmly in place.  The "+
			"thin material of the mask appears to be some sort of "+
			"leather that has been bleached to a %^RESET%^bone "+
			"white %^BOLD%^%^WHITE%^and then aged and painted to "+
			"give it the appearance of being real bone yet retaining "+
			"the comfortable fit of soft leather.  A thin %^BLACK%^"+
			"black gauze %^WHITE%^has been stretched across the eye "+
			"slits under the mask to hide the wearer's eyes while "+
			"still providing them with a clear view of their "+
			"surroundings.  The jaw portion is cleverly hinged and "+
			"a few bits of strategically placed putty allows the "+
			"wearer to affix the moving portion to their own jaw "+
			"line.  The effect of which provides a very life-like "+
			"appearance, especially when seen in %^BLACK%^shadowy "+
			"lightning%^WHITE%^.");

        set_lore("Awarded to Anson of Beshaba for his first place "+
			"story entry in the Second Annual Spooky Story Contest. "+
			"Designed in replica of his styalized mask and given a "+
			"hint of magic to complete the effect, the mask was "+
			"crafted by Tabor artisans, some might say with a bit of "+
			"humor mixed in."); 
        set_property("lore difficulty",12);

		set_weight(2);
        set_value(2500);
        set_type("ring");
        set_limbs(({"head"}));
        set_size(2);
        set_property("enchantment",1);
        set_wear((:TO,"wearme":));
        set_remove((:TO,"removeme":));
}

int wearme(){
	if((string)ETO->query_name() != "anson"){
	
		tell_object(ETO,"%^BOLD%^%^WHITE%^The mask doesn't "+
			"appear to fit you.%^RESET%^");
	return 0;
	}
	if((string)ETO->query_name() == "anson"){
        tell_room(EETO,"%^BOLD%^%^WHITE%^"+TP->QCN+" secures the "+
			"%^BLACK%^ties%^WHITE%^ of their life-like mask behind "+
			"their head.%^RESET%^",TP);
        tell_object(ETO,"%^BOLD%^%^WHITE%^You carefully press the "+
			"putty against your skin, causing the mask to come to "+
			"life with your movements.%^RESET%^");
        return 1;
	}
}

int removeme(){
        tell_room(EETO,"%^BOLD%^%^WHITE%^"+TP->QCN+" removes "+
			"the mask, revealing the living person below.%^RESET%^",TP);
        tell_object(ETO,"%^BOLD%^%^WHITE%^You carefully peel the "+
			"mask from your skin and wipe away the residual "+
			"putty.%^RESET%^");
        return 1;
}

void heart_beat(){
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
   yy = random(6);

   if((xx > 995)) {
      switch(yy) {
         case 0:
            tell_object(ETO,"%^BOLD%^%^RED%^You lick your lips and "+
				"have the faint taste of blood upon them.%^RESET%^");
            tell_room(EETO,"%^BOLD%^%^RED%^Blood drips from the "+
				"lipless grin of "+ETO->QCN+"'s mask.%^RESET%^",ETO);            
            break;
         case 1:
            tell_object(ETO,"%^BOLD%^%^MAGENTA%^You swear you hear "+
				"laughter. Something must be amusing.%^RESET%^");
            tell_room(EETO,"%^BOLD%^%^MAGENTA%^The sound of mad "+
				"laughter erupts all around you!%^RESET%^",ETO);
            break;
         case 2:
            tell_object(ETO,"%^BOLD%^%^RED%^Your vision blurs "+
				"slightly as everything takes on a red haze."+
				"%^RESET%^");
            tell_room(EETO,"%^BOLD%^%^WHITE%^The eyes "+
				"of "+ETO->QCN+"'s mask blaze with %^RED%^crimson "+
				"%^WHITE%^light.%^RESET%^",ETO);
            break;
         case 3:
            tell_object(ETO,"%^BOLD%^%^BLACK%^Why did everyone "+
				"suddenly turn and look around them?%^RESET%^");
			tell_room(EETO,"%^BOLD%^%^BLACK%^A ghostly figure "+
				"crosses through your peripheral vision.  Its "+
				"haunting visage leaving you shaken.%^RESET%^",ETO);
            break;
		case 4:
			tell_object(ETO,"%^BOLD%^%^BLACK%^Is it you, or did the "+
				"room just get darker?%^RESET%^");
			tell_room(EETO,"%^BOLD%^%^BLACK%^The room seems darker "+
				"suddenly.%^RESET%^",ETO);
			break;
		case 5:
			tell_object(ETO,"%^BOLD%^%^WHITE%^The air smells "+
				"especially sweet right now.%^RESET%^");
			tell_room(EETO,"%^RESET%^%^ORANGE%^The air tastes thick "+
				"with the coppery scent of %^RED%^fresh blood"+
				"%^ORANGE%^.%^RESET%^",ETO);
			break;

	default:
      tell_object(ETO,"%^BOLD%^%^WHITE%^Hmm.. Something appears to "+
		"be wrong, please contact a wizard and ask for assistance."+
		"%^RESET%^");
         return 0;
      }
   }
}