// reskin of greater sunblade for Bainthor plottage. N, 9/16.
#include <std.h>
inherit "/d/common/obj/weapon/battle_axe";

int beam_em(mapping info);
void tell_em(string str);
int COUNTER, FLAG;

void create() {
    ::create();
    set_name("mithril axe");
    set_id(({"axe","mithril axe","masterwork mithril battle axe","battle axe","masterwork axe","might of the sonnlinor","Might of the Sonnlinor"}));
    set_short("%^BOLD%^%^BLACK%^M%^RESET%^i%^BOLD%^g%^RESET%^h%^BOLD%^%^BLACK%^t %^RESET%^of the %^YELLOW%^S%^RESET%^%^ORANGE%^o%^BOLD%^%^WHITE%^n%^ORANGE%^n%^RESET%^%^ORANGE%^l%^BOLD%^i%^WHITE%^n%^RESET%^%^ORANGE%^o%^BOLD%^r%^RESET%^");
    set_obvious_short("%^BOLD%^%^BLACK%^a %^ORANGE%^m%^WHITE%^a%^RESET%^s%^YELLOW%^t%^RESET%^e%^BOLD%^r%^ORANGE%^w%^RESET%^o%^BOLD%^r%^ORANGE%^k %^BLACK%^m%^RESET%^i%^BOLD%^thr%^RESET%^i%^BOLD%^%^BLACK%^l b%^RESET%^a%^BOLD%^%^BLACK%^t%^RESET%^t%^BOLD%^%^BLACK%^l%^RESET%^e %^BOLD%^%^BLACK%^a%^RESET%^x%^BOLD%^%^BLACK%^e%^RESET%^");
    set_long("%^RESET%^%^ORANGE%^Evoking the feel of a vast, %^BOLD%^%^BLACK%^darkly lit cavern %^RESET%^%^ORANGE%^in its appearance, this one-handed battle axe could "
"not be anything less than the work of a master weaponsmith. Its haft is made of polished %^BOLD%^%^BLACK%^darkwood%^RESET%^%^ORANGE%^, and %^BOLD%^d%^RESET%^%^ORANGE%^w"
"%^WHITE%^a%^YELLOW%^r%^RESET%^v%^ORANGE%^e%^BOLD%^n p%^RESET%^%^ORANGE%^r%^WHITE%^a%^YELLOW%^y%^RESET%^%^ORANGE%^e%^BOLD%^r r%^RESET%^u%^YELLOW%^n%^RESET%^%^ORANGE%^e"
"%^BOLD%^s %^RESET%^%^ORANGE%^inlaid with %^BOLD%^gold %^RESET%^%^ORANGE%^have been engraved upon its length. Rather than a wrap of leather, a rough band of "
"%^BOLD%^%^BLACK%^d%^RESET%^a%^BOLD%^%^BLACK%^rk%^RESET%^%^ORANGE%^, %^BOLD%^%^BLACK%^c%^RESET%^r%^BOLD%^a%^BLACK%^g%^RESET%^g%^BOLD%^%^BLACK%^y r%^RESET%^o"
"%^BOLD%^%^BLACK%^ck %^RESET%^%^ORANGE%^makes up its grip, its juts and crevices somehow providing a sure grip for ones hand. Most impressive of all is the axes "
"%^BOLD%^%^BLACK%^g%^RESET%^l%^BOLD%^eami%^RESET%^n%^BOLD%^%^BLACK%^g %^WHITE%^m%^RESET%^i%^BOLD%^t%^RESET%^h%^BOLD%^r%^RESET%^i%^BOLD%^l h%^BLACK%^e%^RESET%^a%^BOLD%^d"
"%^RESET%^%^ORANGE%^, forged expertly into a rounded edge and long curved beard. The image of a %^WHITE%^smiths hammer %^ORANGE%^imposed upon an %^BOLD%^%^BLACK%^anvil "
"%^RESET%^%^ORANGE%^has been embossed into the metal on either side, and a faint %^WHITE%^w%^BOLD%^h%^RESET%^i%^BOLD%^t%^RESET%^e g%^BOLD%^l%^RESET%^ow %^ORANGE%^seems "
"to emanate from each of the symbols.%^RESET%^\n");
    set_lore("%^ORANGE%^Of all the worlds many weapons, magical and not, this battle axe is easily amongst the rarest by the reckoning of surface dwellers. It is a "
"rare individual who has even glimpsed such a weapon, and to see it wielded beneath the open sky is all but unheard of. This is the %^BOLD%^Might of the Sonnlinor"
"%^RESET%^%^ORANGE%^, forged deep underground by the dwarves of %^BOLD%^%^BLACK%^Midar Denorth%^RESET%^%^ORANGE%^. Said to be forged as much in the soul as in fire, "
"weapons such as this are wielded by Moradins most devout priests in defense of the Dwarven Ideals: order, honesty and prosperity. Although the original Sonnlinor "
"were scattered upon the destruction of Midar Denorth at the hands of a drowish force, some say that their traditions still live on somewhere in the underdark - "
"unsilenced echoes of the proud dwarven kingdom.%^RESET%^");
    set_property("lore difficulty",35);
    set_property("id difficulty",35);
    set_property("enchantment",5);
    while((int)TO->query_property("enchantment") != 5) {
      TO->remove_property("enchantment");
      TO->set_property("enchantment",5);
    }
    set_item_bonus("attack bonus",3);
    set_item_bonus("damage bonus",3);
    set_item_bonus("sight bonus",3);
    set_value(17600);
    set_hit((:TO,"hit_func":));
    set_wield((:TO,"wield_func":));
    set_unwield((:TO,"unwield_func":));
    set_property("no alter",1);
    set_weapon_prof("exotic");
}

int wield_func(){
   int myflag, i;
   object *mywielded;
   if(!userp(ETO)) return 1;
   if(member_array("%^BOLD%^%^BLACK%^Vanquished Arkhon Bloodscale, ancient dragon of the deep!%^RESET%^",ETO->query_mini_quests())== -1) {
     tell_object(ETO,"%^BOLD%^%^WHITE%^You have not earned the right to make use of this item.%^RESET%^");
     return 0;
   }
   if(!((int)ETO->query_true_align()%3) || ((int)ETO->query_true_align() > 6)) { // non-evils and non-chaotics only
     tell_object(ETO,"You can't seem to get a good grip on the axe!%^RESET%^");
/*     tell_room(EETO,"%^YELLOW%^Brilliant %^WHITE%^light %^YELLOW%^bursts forth from the ruby stone within the blade's "
"hilt as "+ETO->QCN+" tries to wield it, and "+ETO->QS+" blinks, gazing around sightlessly!%^RESET%^",ETO);
     ETO->set_paralyzed(25,"%^BOLD%^%^RED%^You're still recovering from that flash of light!%^RESET%^");
     ETO->set_blind(1); */
     return 0;
   }
   if(ETO->query_property("evil item")) {
     tell_object(ETO,"%^YELLOW%^There is so much evil in the items you carry that the axe simply repels your hand!%^RESET%^");
     return 0;
   }
   if(ETO->query_level() < 35) {
     tell_object(ETO,"You are not experienced enough to use this weapon.");
     return 0;
   }
   if(ETO->query_property("master weapon")) { //preventing stack up with other "top" weapons
     tell_object(ETO,"%^BOLD%^%^WHITE%^You reach out to grasp the axe, and the weapon already in your hand "
"seems to radiate with denial.  You find yourself unwilling even to lift the second weapon!");
     tell_room(EETO,"%^BOLD%^%^WHITE%^"+ETO->QCN+" reaches out to grasps the axe, but then hesitates, and "
"stops.",ETO);
     return 0;
   }
/*   if(((string)ETO->query_name() != "bainthor") && !avatarp(ETO)) {
     tell_object(ETO,"The axe will not accept your hand!");
     return 0;
   } */
   tell_object(ETO,"%^RESET%^%^ORANGE%^Gripping the %^BOLD%^%^BLACK%^battle axe %^RESET%^%^ORANGE%^firmly, you sense a deeper connection to the "
"e%^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^r%^RED%^t%^ORANGE%^h below come over you.%^RESET%^");
   tell_room(EETO,"%^RESET%^%^ORANGE%^"+ETO->QCN+" takes up the %^BOLD%^%^BLACK%^battle axe%^RESET%^%^ORANGE%^, breathing in deeply.%^RESET%^",ETO);
   ETO->set_property("good item",1);
   ETO->set_property("master weapon",1);
   return 1;
}

int unwield_func(){
   tell_object(ETO,"%^RESET%^%^ORANGE%^You feel your connection to the e%^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^r%^RED%^t%^ORANGE%^h fade as you "
"release your grip on the %^BOLD%^%^BLACK%^axe%^RESET%^%^ORANGE%^.%^RESET%^");
   tell_room(EETO,"%^RESET%^%^ORANGE%^"+ETO->QCN+" releases the %^BOLD%^%^BLACK%^axe %^RESET%^%^ORANGE%^and lets out a deep breath as it is "
"set aside.%^RESET%^",ETO);
   ETO->set_property("good item",-1);
   ETO->set_property("master weapon",-1);
   return 1;
}

int hit_func(object targ){
    int rand;
    rand = roll_dice(1,10);
    if(!objectp(ETO)) return 0;
    if(!objectp(EETO)) return 0;
    targ = ETO->query_current_attacker();
    if(!objectp(targ)) return 0;
    if(roll_dice(1,100) > 37) { COUNTER++; return roll_dice(1,4); }

    if(rand > 0 && rand < 5) { // between 1 and 4 or 40%
	tell_object(ETO,"%^ORANGE%^You sense the %^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^a%^BOLD%^%^BLACK%^r%^RESET%^%^ORANGE%^t"
"%^BOLD%^%^BLACK%^h %^RESET%^%^ORANGE%^beneath you growing %^RED%^w%^ORANGE%^a%^BOLD%^r%^RESET%^%^RED%^m %^ORANGE%^as you "
"strike, and your wounds begin to close as you draw upon its energies!%^RESET%^");
	tell_room(EETO,"%^ORANGE%^A %^BOLD%^r%^RESET%^%^ORANGE%^e%^BOLD%^s%^BLACK%^o%^RESET%^%^ORANGE%^l%^BOLD%^u%^RESET%^"
"%^ORANGE%^t%^BOLD%^e %^RESET%^%^ORANGE%^expression comes over "+ETO->QCN+" as the gleaming axe comes down, "+ETO->QP+
" wounds closing before your eyes!%^RESET%^",ETO);
      TO->set_property("magic",1);
      ETO->do_damage("torso",roll_dice(6,4)*(-1));
      TO->set_property("magic",-1);
      COUNTER--;    
    }

    if(rand > 2 && rand < 6)  {// between 3 and 5 or 30%
	tell_object(ETO,"%^BOLD%^%^BLACK%^Your battle axe %^RESET%^%^ORANGE%^rumbles %^BOLD%^%^BLACK%^in your hand as it connects "
"with its target. "+targ->QCN+" staggers back, before shouting in pain as an %^RED%^a%^RESET%^%^ORANGE%^f%^BOLD%^%^RED%^t%^BLACK%^e"
"%^RED%^rs%^RESET%^%^ORANGE%^h%^BOLD%^%^BLACK%^o%^RESET%^%^ORANGE%^c%^BOLD%^%^RED%^k %^BLACK%^wracks "+targ->QP+" body!%^RESET%^");
	tell_object(targ,"%^BOLD%^%^BLACK%^"+ETO->QCN+"s battle axe %^RESET%^%^ORANGE%^rumbles %^BOLD%^%^BLACK%^as it crashes into "
"you. You stagger backward from the blow, only to find yourself wracked with pain as a ghostly %^RED%^a%^RESET%^%^ORANGE%^f"
"%^BOLD%^%^RED%^t%^BLACK%^e%^RED%^rs%^RESET%^%^ORANGE%^h%^BOLD%^%^BLACK%^o%^RESET%^%^ORANGE%^c%^BOLD%^%^RED%^k %^BLACK%^assaults "
"you!%^RESET%^");
	tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETO->QCN+"s battle axe %^RESET%^%^ORANGE%^rumbles %^BOLD%^%^BLACK%^as it crashes into its "
"target. "+targ->QCN+" staggers back, before shouting in pain as an %^RED%^a%^RESET%^%^ORANGE%^f%^BOLD%^%^RED%^t%^BLACK%^e%^RED%^rs"
"%^RESET%^%^ORANGE%^h%^BOLD%^%^BLACK%^o%^RESET%^%^ORANGE%^c%^BOLD%^%^RED%^k %^BLACK%^wracks "+targ->QP+" body!%^RESET%^",({ETO,targ}));
      targ->do_damage("torso",roll_dice(3,10));
      COUNTER--;
    }

    if(rand > 4 && rand < 7) { // between 4 and 6 or 20%
	tell_object(ETO,"%^BOLD%^The gleaming m%^RESET%^i%^BOLD%^t%^RESET%^h%^BOLD%^r%^RESET%^i%^BOLD%^l axe head t%^BLACK%^r"
"%^WHITE%^e%^BLACK%^m%^RESET%^b%^BOLD%^l%^BLACK%^e%^WHITE%^s before releasing an %^RESET%^%^ORANGE%^earth-rending %^BOLD%^-C"
"%^RESET%^%^ORANGE%^R%^BOLD%^A%^RESET%^%^ORANGE%^C%^BOLD%^K-%^WHITE%^, blasting "+targ->QCN+" backwards!%^RESET%^");
	tell_object(targ,"%^BOLD%^The gleaming head of "+ETO->QCN+"s axe begins to t%^BLACK%^r%^WHITE%^e%^BLACK%^m%^WHITE%^b"
"%^BLACK%^l%^WHITE%^e as it comes down on you, releasing an %^RESET%^%^ORANGE%^earth-rending %^BOLD%^-C%^RESET%^%^ORANGE%^R"
"%^BOLD%^A%^RESET%^%^ORANGE%^C%^BOLD%^K- %^WHITE%^as it connects that blasts you backwards!%^RESET%^");
	tell_room(EETO,"%^BOLD%^The gleaming head of "+ETO->QCN+"s axe begins to t%^BLACK%^r%^WHITE%^e%^BLACK%^m%^WHITE%^b"
"%^BLACK%^l%^WHITE%^e as it comes down, releasing an %^RESET%^%^ORANGE%^earth-rending %^BOLD%^-C%^RESET%^%^ORANGE%^R"
"%^BOLD%^A%^RESET%^%^ORANGE%^C%^BOLD%^K- %^WHITE%^as it blasts "+targ->QCN+" backwards!%^RESET%^",({ETO,targ}));
      targ->set_paralyzed(roll_dice(1,10) + 10, "%^BOLD%^%^RED%^You are struggling to stand up!%^RESET%^");
      COUNTER--;
    }

    if(rand > 6 && rand < 10) { // between 7 and 9 or 30%
	tell_object(ETO,"%^GREEN%^Your %^BOLD%^%^BLACK%^b%^RESET%^a%^BOLD%^tt%^RESET%^l%^BOLD%^%^BLACK%^e a%^WHITE%^x%^BLACK%^e "
"%^RESET%^%^GREEN%^grows impossibly %^WHITE%^l%^BOLD%^i%^RESET%^g%^BOLD%^h%^RESET%^t %^GREEN%^in your hand as you strike at "
"your opponent... and with a flick of the wrist you %^YELLOW%^t%^WHITE%^w%^ORANGE%^i%^WHITE%^r%^ORANGE%^l %^RESET%^%^GREEN%^the "
"weapon around, connecting again with the back side of the haft!%^RESET%^");
	tell_room(EETO,"%^GREEN%^"+ETO->QCN+" %^YELLOW%^t%^WHITE%^w%^RESET%^i%^YELLOW%^r%^WHITE%^l%^ORANGE%^s %^RESET%^%^GREEN%^the "
"%^BOLD%^%^BLACK%^b%^RESET%^a%^BOLD%^%^BLACK%^t%^WHITE%^t%^RESET%^l%^BOLD%^%^BLACK%^e a%^RESET%^x%^BOLD%^%^BLACK%^e %^RESET%^"
"%^GREEN%^around with a flick of the wrist, following up one blow with a %^ORANGE%^blunted %^GREEN%^second strike!%^RESET%^",ETO);
	if(sizeof(ETO->query_attackers())) ETO->execute_attack();
      COUNTER--;
    }

/*    if(rand == 10 && COUNTER > 999) { // 10 and counter 1000 or higher
	int i;
	object *living;
	mapping info;
	living = all_living(EETO);
	info = ([
		"living"  : living,
		"eto"     : ETO,
		"count"   : 0,
		"special" : ({}),
		"delay"   : 0,
		"targ"    : targ,
		"eeto"    : EETO,
	]);
	for(i=0;i<sizeof(living);i++) {
		living[i]->set_paralyzed(0);
		living[i]->cease_all_attacks();
	}
	call_out("beam_em",2,info);	
	COUNTER = 0;
    }
    else if(rand == 10 && COUNTER <= 999) { // Blind/Stun if 10 and the counter is not 1000 or higher
    if(rand == 10) { // this wep currently has no overdrive ability.
	tell_object(ETO,"%^BOLD%^%^CYAN%^A burst of fire races up the sword's %^YELLOW%^go%^RESET%^%^ORANGE%^ld%^YELLOW%^"
"en %^CYAN%^blade as you strike, and "+targ->QCN+" becomes momentarily engulfed in a mirroring pyre of %^RED%^in%^RESET%^"
"%^RED%^ca%^MAGENTA%^n%^BOLD%^%^RED%^de%^MAGENTA%^s%^YELLOW%^ce%^RED%^nt %^CYAN%^flame!%^RESET%^");
	tell_object(targ,"%^BOLD%^%^CYAN%^A burst of fire races up the sword's %^YELLOW%^go%^RESET%^%^ORANGE%^ld%^YELLOW%^"
"en %^CYAN%^blade as "+ETO->QCN+" strikes, and you becomes momentarily engulfed in a mirroring pyre of %^RED%^in%^RESET%^"
"%^RED%^ca%^MAGENTA%^n%^BOLD%^%^RED%^de%^MAGENTA%^s%^YELLOW%^ce%^RED%^nt %^CYAN%^flame!%^RESET%^");
	tell_room(EETO,"%^BOLD%^%^CYAN%^A burst of fire races up the sword's %^YELLOW%^go%^RESET%^%^ORANGE%^ld%^YELLOW%^en "
"%^CYAN%^blade as "+ETO->QCN+" strikes, and "+targ->QCN+" becomes momentarily engulfed in a mirroring pyre of %^RED%^in"
"%^RESET%^%^RED%^ca%^MAGENTA%^n%^BOLD%^%^RED%^de%^MAGENTA%^s%^YELLOW%^ce%^RED%^nt %^CYAN%^flame!%^RESET%^",({ETO,targ}));
      targ->set_paralyzed(roll_dice(5,5)+25,"%^BOLD%^%^WHITE%^You are overcome by the searing pain!%^RESET%^");
      if(!"daemon/saving_throw_d"->reflex_save(targ,-25)) targ->set_temporary_blinded(2);
    } */
    return 0;
}

int query_counter() { return COUNTER; }
void set_counter(int num) { COUNTER = num; }

int beam_em(mapping info) {
	int i,delay,count;
	object *living,*special,eto,targ,eeto;

	living  = info["living"];
	special = info["special"];
	eto     = info["eto"];
	count   = info["count"];
	eeto    = info["eeto"];
	targ    = info["targ"];
	delay   = info["delay"];

	if(!pointerp(living)) return 0;
	if(!objectp(eto))	return 0;
	if(!objectp(eeto)) return 0;

	if(!FLAG) {
		for(i=0;i<sizeof(living);i++) {
			if(living[i]->query_property("no paralyze")) special += ({ living[i] });
		}
		if(sizeof(special)) {
			for(i=0;i<sizeof(special);i++) {
				if(!objectp(special[i])) continue;
				special[i]->remove_property("no paralyze");
			}
		}
		for(i=0;i<sizeof(living);i++) {
			if(interactive(living[i]) && !living[i]->query_true_invis()) living[i]->force_me("cls");
			living[i]->cease_all_attacks();
			living[i]->set_paralyzed(1000,"%^YELLOW%^You can't tear your gaze away from the glowing golden "
				"blade!%^RESET%^");
		}
		tell_object(eto,"%^BOLD%^%^WHITE%^The air seems to %^RESET%^%^RED%^th%^BOLD%^i%^RESET%^%^RED%^cken %^BOLD%^"
"%^WHITE%^as the world around you slows, and the ground rumbles %^RESET%^%^ORANGE%^o%^RESET%^m%^RED%^i%^ORANGE%^n%^BOLD%^"
"%^BLACK%^ou%^RESET%^s%^RED%^l%^ORANGE%^y %^BOLD%^%^WHITE%^underfoot.  Your sword rises, as if of its own accord, and "
"pulls your hand up with it as it still grips the hilt, until the tip of the %^YELLOW%^go%^RESET%^%^ORANGE%^ld%^YELLOW%^"
"en %^WHITE%^blade points directly upwards.");
		tell_room(eeto,"%^BOLD%^%^WHITE%^The air seems to %^RESET%^%^RED%^th%^BOLD%^i%^RESET%^%^RED%^cken %^BOLD%^"
"%^WHITE%^as the world around you slows, and the ground rumbles %^RESET%^%^ORANGE%^o%^RESET%^m%^RED%^i%^ORANGE%^n%^BOLD%^"
"%^BLACK%^ou%^RESET%^s%^RED%^l%^ORANGE%^y %^BOLD%^%^WHITE%^underfoot.  "+eto->QP+"'s sword rises, as if of its own accord"
", and pulls "+eto->QP+" hand up with it as they still grip the hilt, until the tip of the %^YELLOW%^go%^RESET%^%^ORANGE%^"
"ld%^YELLOW%^en %^WHITE%^blade points directly upwards.",eto);

		info = ([
			"living"  : living,
			"eto"     : eto,
			"count"   : 1,
			"special" : special,
			"delay"   : 5,
			"targ"    : targ,
			"eeto"    : eeto,
		]);
		FLAG = 1;
		call_out("beam_em",15,info);
		return 0;
	}
	
	switch(count) {
	case 1:
		tell_em("%^YELLOW%^The sounds around you seem to become muted, as the sky above suddenly becomes flooded with "
"the radiant %^CYAN%^c%^RESET%^%^ORANGE%^o%^MAGENTA%^l%^BOLD%^o%^RED%^r%^RESET%^%^RED%^s %^YELLOW%^of sunrise.%^RESET%^");
		tell_room(eeto,"%^BOLD%^%^WHITE%^From the heavens above descends a single %^YELLOW%^br%^RED%^il%^MAGENTA%^l"
"%^RED%^ia%^YELLOW%^nt %^WHITE%^sunbeam, a thin and nearly blinding ray of radiance that strikes the blade and sets its "
"golden surface %^RED%^afi%^RESET%^%^RED%^r%^BOLD%^e%^WHITE%^.%^RESET%^");
		info["count"] = 2;
		call_out("beam_em",15,info);
		return 0;
	case 2:
		if(!objectp(targ)) return 0;
		tell_room(eeto,"%^BOLD%^%^WHITE%^As the sunbeam strikes the %^RESET%^%^RED%^r%^BOLD%^u%^RESET%^%^RED%^by "
"%^BOLD%^%^WHITE%^stone upon the blade's hilt, its light fractures into a thousand reflections with the sound of %^CYAN%^"
"sh%^WHITE%^a%^CYAN%^tter%^RESET%^%^CYAN%^i%^BOLD%^%^CYAN%^ng glass%^WHITE%^.  The spiderwebbed crystal veins cast out an "
"explosion of %^YELLOW%^d%^WHITE%^az%^YELLOW%^zl%^WHITE%^in%^YELLOW%^g %^WHITE%^rays in all directions!%^RESET%^");
		info["count"] = 3;
		call_out("beam_em",15,info);
		return 0;
	case 3:
		if(!objectp(targ)) return 0;
		//if(!ROLLSAVE(targ, PPD )) {
			tell_object(targ,"%^BOLD%^%^WHITE%^Though the sc%^MAGENTA%^i%^WHITE%^nti%^YELLOW%^ll%^WHITE%^ati%^CYAN%^"
"n%^WHITE%^g light plays harmlessly around you, the rays that fall upon you tear through your body, and you can't help "
"but %^BLACK%^s%^YELLOW%^h%^BLACK%^r%^RED%^i%^BLACK%^ek %^WHITE%^in agony.  Your body is lifted from the ground by the "
"incredible force, and is almost instantly %^RESET%^%^RED%^shr%^BOLD%^e%^RESET%^%^RED%^dded %^BOLD%^%^WHITE%^into "
"nothingness!%^RESET%^");
			tell_room(eeto,"%^BOLD%^%^WHITE%^Though the sc%^MAGENTA%^i%^WHITE%^nti%^YELLOW%^ll%^WHITE%^ati%^CYAN%^n"
"%^WHITE%^g light plays harmlessly around you, the rays that fall upon "+targ->QCN+" seem to tear through "+targ->QP+
" body, as "+targ->QP+" mouth opens in a jarring %^BLACK%^s%^YELLOW%^h%^BLACK%^r%^RED%^i%^BLACK%^ek %^WHITE%^of agony.  "
+capitalize(targ->QS)+" is lifted from the ground by the incredible force, and is almost instantly %^RESET%^%^RED%^shr"
"%^BOLD%^e%^RESET%^%^RED%^dded %^BOLD%^%^WHITE%^into nothingness!%^RESET%^",targ);
			ETO->set_property("magic",1);
			targ->do_damage("torso",roll_dice(10000,10000));
			ETO->set_property("magic",-1);
			targ->die();
		//}
		/*else {
			tell_object(targ,"%^BOLD%^%^WHITE%^Though the sc%^MAGENTA%^i%^WHITE%^nti%^YELLOW%^ll%^WHITE%^ati%^CYAN%^"
"n%^WHITE%^g light plays harmlessly around you, the rays that fall upon you tear through your body, and you can't help "
"but %^BLACK%^s%^YELLOW%^h%^BLACK%^r%^RED%^i%^BLACK%^ek %^WHITE%^in agony!%^RESET%^");
			tell_room(eeto,"%^BOLD%^%^WHITE%^Though the sc%^MAGENTA%^i%^WHITE%^nti%^YELLOW%^ll%^WHITE%^ati%^CYAN%^n"
"%^WHITE%^g light plays harmlessly around you, the rays that fall upon "+targ->QCN+" seem to tear through "+targ->QP+
" body, as "+targ->QP+" mouth opens in a jarring %^BLACK%^s%^YELLOW%^h%^BLACK%^r%^RED%^i%^BLACK%^ek %^WHITE%^of agony"
"!%^RESET%^",targ);
			targ->do_damage("torso",roll_dice(20,10));
		}*/
		info["count"] = 4;
		call_out("beam_em",15,info);
		return 0;
	case 4:
		tell_room(eto,"%^BOLD%^%^WHITE%^Just as suddenly as it happened, the %^YELLOW%^su%^RED%^n%^MAGENTA%^b%^RED%^e"
"%^YELLOW%^am %^WHITE%^winks out of existance and the radiance around you fades, as the %^RESET%^%^RED%^r%^BOLD%^u"
"%^RESET%^%^RED%^by %^BOLD%^%^WHITE%^darkens again to display its spiderwebbing of %^RESET%^clear crys%^CYAN%^t%^RESET%^al"
"%^BOLD%^.%^RESET%^");
		tell_em("%^RED%^The crimson hue fades from the air and the ground "
			"beneath you settles..you feel that something terrible has happened...%^RESET%^");
		for(i=0;i<sizeof(living);i++)	{
			if(!objectp(living[i])) { continue; }
			living[i]->set_paralyzed(0);
		}
		for(i=0;i<sizeof(special);i++) {
			if(!objectp(special[i])) continue;
			special[i]->set_property("no paralyze", 1);
		}
	}
	return 0;
}

void tell_em(string str) {
    int i;
    object *users;
    users = children("/std/user.c");
    for(i=0;i<sizeof(users);i++) { 
      if(!interactive(users[i])) continue;
      tell_object(users[i],str);
    }
}