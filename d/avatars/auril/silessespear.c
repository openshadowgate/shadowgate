// Silesse plot reward, moonblade equivalent faith item.
#include <std.h>
inherit "/d/common/obj/weapon/mspear";

void create() {
   ::create();
   set_name("%^ORANGE%^wooden spear%^RESET%^");
   set_id(({"spear","miespear","wooden spear","etched spear","etched wooden spear","spire","spire of the forest warden","Spire of the Forest Warden","miespearx"}));
   set_short("%^RESET%^%^RED%^Spi%^MAGENTA%^r%^RED%^e of the %^GREEN%^F%^CYAN%^o%^GREEN%^rest War%^CYAN%^d%^GREEN%^en%^RESET%^");
   set_obvious_short("%^RESET%^%^RED%^orn%^MAGENTA%^a%^RED%^te wooden spear%^RESET%^");
   set_long("This is one of the most unique weapons you've seen. The entire "
"spear is made of %^RED%^wood%^RESET%^, with no metal head - yet carved to "
"such a %^BOLD%^%^CYAN%^ke%^WHITE%^e%^CYAN%^n%^RESET%^ tip that it could only "
"be magically sharpened. The wood itself is of a beautiful %^RED%^deep "
"reddish tone%^RESET%^, with the grain running parallel to the spear's shaft. "
"What makes the weapon most outstanding, though, are the "
"%^MAGENTA%^el%^RED%^a%^MAGENTA%^bora%^RED%^t%^MAGENTA%^e%^RESET%^ etchings "
"from its base to the very tip, detailing all kinds of "
"%^ORANGE%^wi%^BOLD%^%^BLACK%^l%^RESET%^%^ORANGE%^d creatures%^RESET%^ "
"amongst a swirling trail of %^GREEN%^lea%^BOLD%^v%^RESET%^%^GREEN%^es "
"%^RESET%^and %^BOLD%^%^GREEN%^vines %^RESET%^that run the length of the "
"wood. They are so %^MAGENTA%^i%^RED%^n%^MAGENTA%^tric%^RED%^a%^MAGENTA%^tely "
"%^RESET%^carved that, were the spear not so unnaturally sturdy, you would "
"fear that using the spear in combat would easily ruin them. A few "
"%^CYAN%^br%^GREEN%^il%^YELLOW%^li%^RESET%^%^ORANGE%^an%^RED%^t-%^MAGENTA%^hu"
"%^BLUE%^ed %^RESET%^feathers from some unknown bird have been secured near "
"the tip of the spear, giving the weapon somewhat of a tribal appearance.\n");
   set_value(17500);
   set("dexbonus",1);
   set_property("attack bonus",2);
   set_property("enchantment",5);
   set_hit((:TO,"hit_func":));
   set_wield((:TO,"wield_func":));
   set_unwield((:TO,"unwield_func":));
   set_property("no alter",1);
   set_weapon_prof("exotic");
   set_heart_beat(1);
}

int wield_func(){
   int myflag, i;
   object *mywielded;
   if((string)ETO->query_race() != "elf" && (string)ETO->query_diety() != "mielikki") {
     tell_object(ETO,"%^BOLD%^%^WHITE%^A shock runs through you, forcing you to drop the weapon!%^RESET%^");
     tell_room(EETO,"%^BOLD%^%^WHITE%^"+ETO->QCN+"%^BOLD%^%^WHITE%^ attempts to take up the spear, but "
+capitalize(ETO->QS)+" lets out a gasp and drops the weapon.%^RESET%^",ETO);
     TO->set_property("magic",1);
     ETO->do_damage("torso",roll_dice(20,10));
     TO->set_property("magic",-1);
     ETO->force_me("drop miespearx");
     return 0;
   }
   if(sizeof(ETO->query_wielded())) {
     myflag = 0;
     mywielded = ETO->query_wielded();
     for(i = 0; i < sizeof(mywielded); i ++) {
       if (member_array("moonbladex",mywielded[i]->query_id()) != -1) myflag = 1;
       if (member_array("Ragnarok",mywielded[i]->query_id()) != -1) myflag = 1;
       if (member_array("greater sunblade",mywielded[i]->query_id()) != -1) myflag = 1;
     }
     if(myflag) {
       tell_object(ETO,"%^BOLD%^%^WHITE%^You reach out to grasp the spear, but the weapon already in your hand "
"seems to radiate with denial.  You find yourself unwilling even to lift the second weapon!");
     tell_room(EETO,"%^BOLD%^%^WHITE%^"+ETO->QCN+" reaches out to grasp the spear, but then hesitates, and "
"stops.",ETO);
       return 0;
     }
   }
   tell_object(ETO,"%^BOLD%^%^WHITE%^The spear slides smoothly to rest in your grip.%^RESET%^");
   tell_room(EETO,"%^BOLD%^%^WHITE%^The longsword rests in a light and balanced hold in "+ETO->QCN+"'s hand.%^RESET%^",ETO);
   return 1;
}

int unwield_func(){
   tell_object(ETO,"%^BOLD%^%^WHITE%^You release your hold on the spear.%^RESET%^");
   tell_room(EETO,"%^BOLD%^%^WHITE%^"+ETO->QCN+"%^BOLD%^%^WHITE%^ releases hold of the spear.%^RESET%^",ETO);
   return 1;
}

int hit_func(object targ){
    object ob;
    int rand;
    rand = roll_dice(1,10);
    if(!objectp(ETO)) return 0;
    if(!objectp(EETO)) return 0;
    targ = ETO->query_current_attacker();
    if(!objectp(targ)) return 0;
    if(roll_dice(1,100) > 37) return roll_dice(1,4);

    if(rand > 0 && rand < 5) { // between 1 and 4 or 40%
	tell_object(ETO,"%^BOLD%^%^WHITE%^As you strike, %^GREEN%^co%^WHITE%^r%^GREEN%^u%^RESET%^%^GREEN%^sc%^BOLD%^a%^WHITE%^"
"ti%^YELLOW%^n%^GREEN%^g %^WHITE%^motes of light tumble from the gleaming spear to settle upon your skin.%^RESET%^");
	tell_room(EETO,"%^BOLD%^%^WHITE%^"+ETO->QCN+"'s spear sheds %^GREEN%^co%^WHITE%^r%^GREEN%^u%^RESET%^%^GREEN%^sc%^BOLD%^a%^WHITE%^"
"ti%^YELLOW%^n%^GREEN%^g %^WHITE%^motes of light that settle onto "+ETO->QP+" skin as "+ETO->QS+" strikes"
"!%^RESET%^",ETO);
      TO->set_property("magic",1);
      ETO->do_damage("torso",roll_dice(6,4)*(-1));
      TO->set_property("magic",-1);
    }

    if(rand > 2 && rand < 6)  {// between 3 and 5 or 30%
	tell_object(ETO,"%^BOLD%^%^GREEN%^Ve%^RESET%^%^GREEN%^r%^BOLD%^da%^RESET%^%^GREEN%^n%^BOLD%^t%^YELLOW%^ energy races along the blade as its "
"%^BOLD%^%^BLACK%^ra%^WHITE%^z%^YELLOW%^o%^BLACK%^r-s%^RED%^h%^BLACK%^arp %^YELLOW%^tip bites into "+targ->QCN+"!%^RESET%^");
	tell_object(targ,"%^BOLD%^%^GREEN%^Ve%^RESET%^%^GREEN%^r%^BOLD%^da%^RESET%^%^GREEN%^n%^BOLD%^t%^YELLOW%^energy races along "+ETO->QCN+"'s blade as "
"its %^BOLD%^%^BLACK%^ra%^WHITE%^z%^YELLOW%^o%^BLACK%^r-s%^RED%^h%^BLACK%^arp %^YELLOW%^tip bites into you!%^RESET%^");
	tell_room(EETO,"%^BOLD%^%^GREEN%^Ve%^RESET%^%^GREEN%^r%^BOLD%^da%^RESET%^%^GREEN%^n%^BOLD%^t%^YELLOW%^energy races along "+ETO->QCN+"'s blade as "
"its %^BOLD%^%^BLACK%^ra%^WHITE%^z%^YELLOW%^o%^BLACK%^r-s%^RED%^h%^BLACK%^arp %^YELLOW%^tip bites into "+targ->QCN+
"!%^RESET%^",({ETO,targ}));
      targ->do_damage("torso",roll_dice(3,10));
    }

    if(rand > 4 && rand < 7) { // between 4 and 6 or 20%
	tell_object(ETO,"%^BOLD%^%^GREEN%^You crouch to strike the spear's base abruptly upon the ground, and living "
"%^RESET%^%^GREEN%^v%^BOLD%^i%^RESET%^%^GREEN%^nes %^BOLD%^snake up from the earth to snatch at "+targ->QCN+"!%^RESET%^");
	tell_object(targ,"%^BOLD%^%^GREEN%^"+ETO->QCN+" crouches to strike the spear's base abruptly upon the ground, and "
"living %^RESET%^%^GREEN%^v%^BOLD%^i%^RESET%^%^GREEN%^nes %^BOLD%^snake up from the earth to snatch at "+targ->QCN+"!%^RESET%^");
	tell_room(EETO,"%^BOLD%^%^GREEN%^"+ETO->QCN+" crouches to strike the spear's base abruptly upon the ground, and "
"living %^RESET%^%^GREEN%^v%^BOLD%^i%^RESET%^%^GREEN%^nes %^BOLD%^snake up from the earth to snatch at "+targ->QCN+"!%^RESET%^",({ETO,targ}));
      targ->set_paralyzed(roll_dice(1,10) + 10, "%^BOLD%^%^GREEN%^You are struggling to get free of the vines!%^RESET%^");
    }

    if(rand > 6 && rand < 10) { // between 7 and 9 or 30%
	tell_object(ETO,"%^BOLD%^%^GREEN%^Your spear seems impossibly %^RESET%^%^CYAN%^li%^BOLD%^gh%^WHITE%^twe%^CYAN%^ig"
"%^RESET%^%^CYAN%^ht %^BOLD%^%^GREEN%^as you draw it back for a second blow, striking at your foes in rapid succession"
"!%^RESET%^");
	tell_room(EETO,"%^BOLD%^%^GREEN%^"+ETO->QCN+" hefts "+ETO->QP+" spear with the %^RESET%^%^CYAN%^s%^BOLD%^p%^WHITE%^e"
"%^CYAN%^e%^RESET%^%^CYAN%^d %^BOLD%^%^GREEN%^of a far lighter weapon, lashing out with several blows in rapid succession"
"!%^RESET%^",ETO);
	if(sizeof(ETO->query_attackers())) ETO->execute_attack();
    }

    if(rand == 10 && !present("elfshadow",EETO)) {
      tell_object(ETO,"%^BOLD%^%^WHITE%^The spear's etchings pulse with a sudden energy, and as you "
"blink, you realise the %^RESET%^%^BLUE%^shadowy silhouette %^BOLD%^%^WHITE%^of an elven figure stands "
"at your side in a protective stance!%^RESET%^");
      tell_room(EETO,"%^BOLD%^%^WHITE%^The etchings upon "+ETO->QCN+"'s spear pulse with sudden energy, "
"and as you blink, you realise the %^RESET%^%^BLUE%^shadowy silhouette %^BOLD%^%^WHITE%^of an elven figure "
"stands at "+ETO->QP+" side in a protective stance!",ETO);
      ob = new("/d/retired/obj/elfshadow.c");
      ob->move(EETO);
      ob->force_me("protect "+ETO->query_name());
      ETO->add_follower(ob);
    }
    return 0;
}

void heart_beat() {
   int myflag, i;
   object *mywielded;
   if(!objectp(ETO)) return;
   if(!userp(ETO)) return;
   if(sizeof(ETO->query_wielded())) {
     myflag = 0;
     mywielded = ETO->query_wielded();
     for(i = 0; i < sizeof(mywielded); i ++) {
       if (member_array("moonbladex",mywielded[i]->query_id()) != -1) myflag = 1;
       if (member_array("Ragnarok",mywielded[i]->query_id()) != -1) myflag = 1;
       if (member_array("greater sunblade",mywielded[i]->query_id()) != -1) myflag = 1;
     }
     if(myflag && (int)TO->query_wielded()) {
       tell_object(ETO,"%^BOLD%^%^WHITE%^The spear hums with sudden energy, and you find yourself unable to keep hold of it!");
       tell_room(EETO,"%^BOLD%^%^WHITE%^The spear in "+ETO->QCN+"'s hand hums with energy, and "+ETO->QS+" doesn't seem able to keep hold of it!",ETO);
       ETO->force_me("drop miespearx");
     }
   }
}