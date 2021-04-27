// note. This sword manually specifies the settings for a 1h/2h bastard sword. If the inherit is updated, it will also need updated. N, 7/15.
#include <std.h>
#include <magic.h>
inherit "/d/common/obj/weapon/bastard";

void set_mysize(int size);

void create() {
   ::create();
   set_name("bastard sword");
   set_id(({"bastard","sword","bastard sword","diamond blade","blade","Diamond Blade","The Diamond Blade","thebastardswordx99"}));
   set_short("%^BOLD%^%^WHITE%^The D%^BOLD%^%^CYAN%^i%^BOLD%^%^WHITE%^amond Bl%^BOLD%^%^CYAN%^a%^BOLD%^%^WHITE%^de%^RESET%^");
   set_obvious_short("%^BOLD%^%^WHITE%^an ex%^BOLD%^%^CYAN%^c%^BOLD%^%^WHITE%^epti%^BOLD%^%^CYAN%^o%^BOLD%^%^WHITE%^nal bastard sword%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^This bastard sword is clearly of %^RESET%^%^MAGENTA%^ex%^RED%^c%^MAGENTA%^e%^BOLD%^%^RED%^p%^RESET%^%^RED%^t"
"%^MAGENTA%^io%^BOLD%^%^MAGENTA%^n%^RESET%^%^MAGENTA%^al %^BOLD%^%^WHITE%^smithing, even more remarkable to the eye than a master-crafted "
"piece. The metal of its flawless surface bears a fine %^RESET%^si%^BOLD%^%^WHITE%^l%^BOLD%^%^CYAN%^v%^BOLD%^%^WHITE%^e%^RESET%^ry-b"
"%^BOLD%^%^CYAN%^l%^BOLD%^%^WHITE%^u%^RESET%^e %^BOLD%^%^WHITE%^sheen, although when light plays across its surface, it is reflected in "
"vibrant %^RESET%^%^GREEN%^e%^BOLD%^%^GREEN%^m%^YELLOW%^e%^RESET%^%^GREEN%^ra%^BOLD%^%^GREEN%^l%^RESET%^%^GREEN%^d%^BOLD%^%^WHITE%^. The "
"quality of its crafting is easily noted by its %^BOLD%^%^BLACK%^ra%^WHITE%^z%^YELLOW%^o%^BLACK%^r-s%^RED%^h%^BLACK%^arp %^WHITE%^edge, or "
"in the perfect weighting of the weapon itself. It stands at roughly five feet in length, of which nearly four feet form the blade itself. "
"%^RESET%^%^CYAN%^Li%^GREEN%^ght%^CYAN%^er %^BOLD%^%^WHITE%^than its size would suggest, the hollow-ground blade has been deliberately "
"shaped for strength without weight. Its fine edge proceeds straight and uninterrupted from tapered point through foible and forte, but "
"becomes blunted a short distance before the guard to allow for a ricasso, upon which is an engraved glyph - a simple %^BOLD%^%^CYAN%^di"
"%^BOLD%^%^WHITE%^a%^BOLD%^%^CYAN%^mond %^BOLD%^%^WHITE%^shape. The hilt commences with a guard that is as plain and elegant as the blade "
"itself, a smooth bar of gleaming metal to either side with a slight sweep to catch and deflect a blow. From its protective guard leads the "
"waisted grip, allowing for an easier hold in one hand, bound in %^BOLD%^%^BLACK%^night-black %^BOLD%^%^WHITE%^leather. The weapon finishes "
"with a pommel of the same fine metal, which broadens to a hexagonal butt in a similar shape to that of a vial's stopper.%^RESET%^\n");
   set_lore("\n%^BOLD%^%^WHITE%^...a blade such as this is commonly known as a bastard sword, or hand-and-a-half sword. At approximately "
"five feet in length, such weapons can prove cumbersome to be used in a one-handed grip, and thus they are only ever used in this manner "
"by masters of swordplay. More commonly, the off-hand is used to grip the pommel in order to land a steady blow...\n\n%^BOLD%^%^CYAN%^..."
"the blade's fine silvery-blue sheen, and its green reflective shine, are tell-tale of a blade made of Arandur. Such a metal is incredibly "
"rare and valuable, its forging once only the secret of gnomekind but since learned and replicated also by the elves. Usually found deep "
"underground amidst streaks of vitreous glass, it must be tempered with the blood of a dragon when forged, so as not to become as brittle "
"as the glass alongside which it was birthed. It is famous for holding an incredibly sharp edge despite abuse, and is often favored for "
"crafting swords of sharpness and vorpal blades...\n\n%^BOLD%^%^GREEN%^...the Diamond Blade, as it became known many centuries ago, slips "
"in and out of history's pages at many points. Whether named for the distinctive diamond shape to the blade's cross-section, or the glyph "
"upon its shoulder, remains unclear. No records seem to exist of its crafter or original owner; stories only mention those points where it "
"appeared in the hands of a warrior. And certainly there have been many...\n\n%^YELLOW%^...less diligent lorekeepers might suggest a pattern "
"to those in whose hands the blade was found; unknown, and relatively unremarkable mortals, save for their skill with a blade. Each was "
"known for turning the tide of a particular battle, though in many cases at the cost their lives. Such 'patterns', however, should be "
"regarded by a true scholar as mere coincidence, or the result of stories with sufficient witnesses and dramatic flare to merit their "
"retention in the annals of history...\n%^RESET%^");
   set_property("lore difficulty",25);
   set_property("id difficulty",25);
   set_value(12200);
   set_weapon_prof("exotic");
   set_wield((:TO,"wield_func":));
   set_unwield((:TO,"unwield_func":));
   set_hit((:TO,"hit_func":));
}

int wield_func(){
   int mylvl,mymax,manualenchant;

// removing this, it's breaking people with appropriate PrCs now. N, 6/19
/*   if(sizeof(ETO->query_classes()) > 1 && !avatarp(ETO)) { // SC only...
     tell_object(ETO,"You try to make sense of how best to grip the weapon, but end up simply uncertain. It "
"seems only someone practiced purely in their art might make effective use of it.");
     return 0;
   } */
   if(!ETO->is_class("fighter") && !avatarp(ETO)) { // fighter only...
     tell_object(ETO,"You try to make sense of how best to grip the weapon, but end up simply uncertain. It "
"seems only someone practiced purely in their art might make effective use of it.");
     return 0;
   }
   if(ETO->query_property("master weapon")) { //preventing stack up with other "top" weapons, since it can potentially scale there with the Arkhon mini-quest
     tell_object(ETO,"%^BOLD%^%^WHITE%^You reach out to grasp the blade, before thinking twice.  What other weapon "
"could equal your capacity with this one alone?  You find yourself unwilling even to lift the second weapon!");
     tell_room(EETO,"%^BOLD%^%^WHITE%^"+ETO->QCN+" reaches out to grasps the blade, but then hesitates, and "
"stops.",ETO);
     return 0;
   }

// this weapon scales with user level, both for bonuses and specials.
   mylvl = ((int)ETO->query_level()-3) / 5; // slightly above the normal +1/5; should scale at 8/13/18/23/28/33/38.
//problem - as with most scaling weapons, this one can't be enchanted manually! Let's make it so with the enchanter updated flag!
   manualenchant = (int)TO->query_property("manual enchantment"); // need to use this as it will pick up cursed enchantress attempts as well!
   mymax = 5 + manualenchant; // +5 is the base cap; anyone who hasn't paid for more enchants should only get a standard weapon
//    if(mymax > 7) mymax = 7; // potentially they could add up to two more to +7 (L38 max scaled level)
   if(mymax > 9) mymax = 9; // revised for new L50 levelcap instead of L40
   if(mylvl > mymax) mylvl = mymax; // downscale to the hard cap; only ever +5 unless they've paid for it!
   while(query_property("enchantment") != mylvl) {
     remove_property("enchantment");
     set_property("enchantment",mylvl);
   }
   mylvl = mylvl/2; // should give +1 at 13/23/33, caps at +3
   set_item_bonus("attack bonus",mylvl);
   set_item_bonus("damage bonus",mylvl);
   ETO->set_property("master weapon",1);

   if((int)ETO->query_size() > 2) { // manual override to size for large races - 2h setting only
     tell_object(ETO,"%^BOLD%^%^WHITE%^You realise this blade would only be effective for you in a one-handed grip.%^RESET%^");
     set_mysize(3);
     return 1;
   }
   if((int)ETO->query_size() == 1) { // manual override to size for small races - 1h setting only
     tell_object(ETO,"%^BOLD%^%^WHITE%^You realise this blade would only be effective for you in a two-handed grip.%^RESET%^");
     set_mysize(2);
     return 1;
   }
   if((int)TO->query_size() == 3) { // messages are already done in the switch. This size can only ever trigger from the manual switch.
     TO->remove_property("silentwield");
     return 1;
   }
   if(!TO->query_property("silentwield")) tell_object(ETO,"%^BOLD%^%^WHITE%^You take up the bastard sword in a light one-handed grip.  "
"You realise you could use a more powerful fighting style if you <grip bastard sword in two hands>.%^RESET%^");
   else TO->remove_property("silentwield");
   return 1;
}

int unwield_func(){
   if(!TO->query_property("silentwield")) tell_object(ETO,"%^BOLD%^%^WHITE%^You release your hold on the perfectly-balanced sword.%^RESET%^");
   ETO->set_property("master weapon",-1);
   set_mysize(2);
   return 1;
}

int hit_func(object targ){
    int mylvl,mymax,mysize,rand;
    object *mywielded;
    string *myids;

    if(!objectp(ETO)) return 0;
    if(!objectp(EETO)) return 0;
    targ = ETO->query_current_attacker();
    if(!objectp(targ)) return 0;

    mylvl = ((int)ETO->query_level()-3) / 5; // slightly above the normal +1/5; should scale at 8/13/18/23/28/33/38.
// at max level this specials as much as a sunblade (38% vs 37%), however far less often at lower levels (per progression above).
    if(random(100) > ((mylvl*5)+3)) return roll_dice(1,2);
    mysize = (int)TO->query_size();
    rand = roll_dice(1,700);

//1 damage - size 3 for sideways chop, size 2 for weakness
    if(rand <= 210) { // 0 -> 30%
      if(mysize == 3) {
        tell_object(ETO,"%^BOLD%^%^WHITE%^You brace the sword's pommel with your off-hand, as you bring it up "
"and across in a %^RESET%^%^RED%^fo%^BOLD%^%^RED%^r%^BOLD%^%^WHITE%^c%^RESET%^%^RED%^e%^YELLOW%^f%^RESET%^"
"%^RED%^ul %^BOLD%^%^WHITE%^blow at "+targ->QCN+"!%^RESET%^");
        tell_object(targ,"%^BOLD%^%^WHITE%^"+ETO->QCN+" brings "+ETO->QP+" blade up and across in a %^RESET%^"
"%^RED%^fo%^BOLD%^%^RED%^r%^BOLD%^%^WHITE%^c%^RESET%^%^RED%^e%^YELLOW%^f%^RESET%^%^RED%^ul %^BOLD%^%^WHITE%^blow "
"that bites deep and true!%^RESET%^");
        tell_room(EETO,"%^BOLD%^%^WHITE%^"+ETO->QCN+" brings "+ETO->QP+" blade up and across in a %^RESET%^"
"%^RED%^fo%^BOLD%^%^RED%^r%^BOLD%^%^WHITE%^c%^RESET%^%^RED%^e%^YELLOW%^f%^RESET%^%^RED%^ul %^BOLD%^%^WHITE%^blow "
"that bites deep and true into "+targ->QCN+"!%^RESET%^",({ETO,targ}));
      }
      else {
        tell_object(ETO,"%^BOLD%^%^WHITE%^You move with a %^YELLOW%^li%^BOLD%^%^WHITE%^g%^YELLOW%^htn"
"%^BOLD%^%^WHITE%^i%^RESET%^%^WHITE%^n%^YELLOW%^g-fa%^BOLD%^%^WHITE%^s%^YELLOW%^t %^BOLD%^%^WHITE%^strike to take "
"advantage of a weakness in "+targ->QCN+"'s defenses, and your blade draws %^RESET%^%^RED%^blood%^BOLD%^%^WHITE%^!"
"%^RESET%^");
        tell_object(targ,"%^BOLD%^%^WHITE%^"+ETO->QCN+" moves with a %^YELLOW%^li%^BOLD%^%^WHITE%^g%^YELLOW%^htn"
"%^BOLD%^%^WHITE%^i%^RESET%^%^WHITE%^n%^YELLOW%^g-fa%^BOLD%^%^WHITE%^s%^YELLOW%^t %^BOLD%^%^WHITE%^strike to take "
"advantage of a momentary weakness in your defenses!%^RESET%^");
        tell_room(EETO,"%^BOLD%^%^WHITE%^"+ETO->QCN+" moves with a %^YELLOW%^li%^BOLD%^%^WHITE%^g%^YELLOW%^htn"
"%^BOLD%^%^WHITE%^i%^RESET%^%^WHITE%^n%^YELLOW%^g-fa%^BOLD%^%^WHITE%^s%^YELLOW%^t %^BOLD%^%^WHITE%^strike to take "
"advantage of a momentary weakness in "+targ->QCN+"'s defenses!%^RESET%^",({ETO,targ}));
      }
      TO->set_property("magic",1);
      targ->do_damage(targ->return_target_limb(),roll_dice(2,10)+2);
      TO->remove_property("magic");
    }

//2 extra damage - size 3 for powerful overhead blow, size 2 for strike at vital point
    if(rand > 210 && rand <= 350) { // 30 -> 50%
      if(mysize == 3) {
        tell_object(ETO,"%^BOLD%^%^WHITE%^Putting all of your strength into the strike, you bring the sword "
"overhead in a two-handed grip and nearly take off one of "+targ->QCN+"'s limbs!%^RESET%^");
        tell_object(targ,"%^BOLD%^%^WHITE%^"+ETO->QCN+" puts all of "+ETO->QP+" strength into an overhead strike "
"that nearly takes off one of your limbs!%^RESET%^");
        tell_room(EETO,"%^BOLD%^%^WHITE%^"+ETO->QCN+" puts all of "+ETO->QP+" strength into an overhead strike "
"that nearly takes off one of "+targ->QCN+"'s limbs!%^RESET%^",({ETO,targ}));
      }
      else {
        tell_object(ETO,"%^BOLD%^%^WHITE%^Your brilliant blade %^BOLD%^%^GREEN%^f%^BOLD%^%^WHITE%^l%^BOLD%^%^CYAN%^a"
"%^BOLD%^%^GREEN%^s%^YELLOW%^h%^BOLD%^%^WHITE%^e%^BOLD%^%^GREEN%^s %^BOLD%^%^WHITE%^as you thrust at a vital point, "
"scoring a hit on "+targ->QCN+"!%^RESET%^");
        tell_object(targ,"%^BOLD%^%^WHITE%^"+ETO->QCN+"'s brilliant blade %^BOLD%^%^GREEN%^f%^BOLD%^%^WHITE%^l"
"%^BOLD%^%^CYAN%^a%^BOLD%^%^GREEN%^s%^YELLOW%^h%^BOLD%^%^WHITE%^e%^BOLD%^%^GREEN%^s %^BOLD%^%^WHITE%^as "+ETO->QS+
" thrusts it at you and finds "+ETO->QP+" mark!%^RESET%^");
        tell_room(EETO,"%^BOLD%^%^WHITE%^"+ETO->QCN+"'s brilliant blade %^BOLD%^%^GREEN%^f%^BOLD%^%^WHITE%^l"
"%^BOLD%^%^CYAN%^a%^BOLD%^%^GREEN%^s%^YELLOW%^h%^BOLD%^%^WHITE%^e%^BOLD%^%^GREEN%^s %^BOLD%^%^WHITE%^as "+ETO->QS+
" thrusts it at "+targ->QCN+" and finds "+ETO->QP+" mark!%^RESET%^",({ETO,targ}));
      }
      TO->set_property("magic",1);
      targ->do_damage(targ->return_target_limb(),roll_dice(3,10)+2);
      TO->remove_property("magic");
    }

//3 stun - size 3 for reach used to sweep feet, size 2 for precise strike to head
    if(rand > 350 && rand <= 490) { // 50% -> 70%
      if(mysize == 3) {
        tell_object(ETO,"%^BOLD%^%^WHITE%^You feint at "+targ->QCN+" before sweeping the blade around low with "
"both hands, and "+targ->QCN+" %^RESET%^%^ORANGE%^stum%^BOLD%^%^BLACK%^bl%^RESET%^%^ORANGE%^es %^BOLD%^%^WHITE%^as "
+targ->QS+" scrambles to avoid your attacks!%^RESET%^");
        tell_object(targ,"%^BOLD%^%^WHITE%^A feint is immediately followed by a sweeping low blow from "+ETO->QCN+
", forcing you to %^RESET%^%^ORANGE%^stum%^BOLD%^%^BLACK%^bl%^RESET%^%^ORANGE%^e %^BOLD%^%^WHITE%^as you evade "
"the attacks!%^RESET%^");
        tell_room(EETO,"%^BOLD%^%^WHITE%^A feint is immediately followed by a sweeping low blow from "+ETO->QCN+
", forcing "+targ->QCN+" to %^RESET%^%^ORANGE%^stum%^BOLD%^%^BLACK%^bl%^RESET%^%^ORANGE%^e %^BOLD%^%^WHITE%^as "
+targ->QS+" evades the attacks!%^RESET%^",({ETO,targ}));
        targ->set_paralyzed(roll_dice(1,10) + 10, "You are trying to regain your balance!");
      }
      else {
        tell_object(ETO,"%^BOLD%^%^WHITE%^You twist the sword suddenly to impact "+targ->QCN+" with the flat of "
"the blade, and "+targ->QS+" looks momentarily %^YELLOW%^d%^BOLD%^%^RED%^a%^BOLD%^%^WHITE%^z%^YELLOW%^ed"
"%^BOLD%^%^WHITE%^!%^RESET%^");
        tell_object(targ,"%^BOLD%^%^WHITE%^"+ETO->QCN+" twists the sword without warning and impacts you with the "
"flat of the blade, causing %^YELLOW%^s%^BOLD%^%^RED%^t%^BOLD%^%^WHITE%^a%^YELLOW%^rs %^BOLD%^%^WHITE%^to burst "
"before your eyes!%^RESET%^");
        tell_room(EETO,"%^BOLD%^%^WHITE%^"+ETO->QCN+" twists the sword suddenly to impact "+targ->QCN+" with the "
"flat of the blade, and "+targ->QS+" looks momentarily %^YELLOW%^d%^BOLD%^%^RED%^a%^BOLD%^%^WHITE%^z%^YELLOW%^ed"
"%^BOLD%^%^WHITE%^!%^RESET%^",({ETO,targ}));
        targ->set_paralyzed(roll_dice(1,10) + 10, "You're still seeing stars!");
      }
    }

//4 disarm - size 3 sheer force to strike the weapon, size 2 for flick out of hand
    if(rand > 490 && rand <= 560) { // 70 -> 80%, default to stun if it's not a wielder
      mywielded = targ->query_wielded();
      if(!sizeof(mywielded)) rand = 561; // trigger extra attack instead, nothing to disarm
      else {
        if(mysize == 3) {
          tell_object(ETO,"%^BOLD%^%^WHITE%^You lash out with a %^RESET%^%^ORANGE%^ja%^RESET%^r%^BOLD%^%^BLACK%^ri"
"%^RESET%^%^ORANGE%^ng %^BOLD%^%^WHITE%^strike at "+targ->QCN+"'s weapon, and the impact forces "+targ->QO+" to "
"release "+targ->QP+" grip!%^RESET%^");
          tell_object(targ,"%^BOLD%^%^WHITE%^"+ETO->QCN+" lashes out with a %^RESET%^%^ORANGE%^ja%^RESET%^r"
"%^BOLD%^%^BLACK%^ri%^RESET%^%^ORANGE%^ng %^BOLD%^%^WHITE%^strike at your weapon, and the impact forces you to "
"release your grip!%^RESET%^");
          tell_room(EETO,"%^BOLD%^%^WHITE%^"+ETO->QCN+" lashes out with a %^RESET%^%^ORANGE%^ja%^RESET%^r"
"%^BOLD%^%^BLACK%^ri%^RESET%^%^ORANGE%^ng %^BOLD%^%^WHITE%^strike at "+targ->QCN+"'s weapon, and the impact forces "
+targ->QO+" to release "+targ->QP+" grip!%^RESET%^",({ETO,targ}));
        }
        else {
          tell_object(ETO,"%^BOLD%^%^WHITE%^You flick your wrist with a %^RESET%^%^GREEN%^p%^BOLD%^%^GREEN%^r"
"%^YELLOW%^e%^RESET%^%^GREEN%^ci%^BOLD%^%^GREEN%^s%^RESET%^%^GREEN%^e %^BOLD%^%^WHITE%^motion, knocking the weapon "
"from "+targ->QCN+"'s hand!%^RESET%^");
          tell_object(targ,"%^BOLD%^%^WHITE%^"+ETO->QCN+" flicks "+ETO->QP+" wrist with a %^RESET%^%^GREEN%^p"
"%^BOLD%^%^GREEN%^r%^YELLOW%^e%^RESET%^%^GREEN%^ci%^BOLD%^%^GREEN%^s%^RESET%^%^GREEN%^e %^BOLD%^%^WHITE%^motion, "
"knocking the weapon from your hand!%^RESET%^");
          tell_room(EETO,"%^BOLD%^%^WHITE%^"+ETO->QCN+" flicks "+ETO->QP+" wrist with a %^RESET%^%^GREEN%^p"
"%^BOLD%^%^GREEN%^r%^YELLOW%^e%^RESET%^%^GREEN%^ci%^BOLD%^%^GREEN%^s%^RESET%^%^GREEN%^e %^BOLD%^%^WHITE%^motion, "
"knocking the weapon from "+targ->QCN+"'s hand!%^RESET%^",({ETO,targ}));
        }
        myids = mywielded[0]->query_id();
        targ->force_me("unwield "+myids[0]+"");
        targ->remove_property("disarm time");
        targ->set_property("disarm time",time()+(ROUND_LENGTH*roll_dice(1,4)));
      }
    }

//5 extra attack - size 3 sweep and momentum (cleave), size 2 twists & swings blade back (standard +atk)
    if(rand > 560) { // 80%+, or extra attack if no wielded item
      targ->do_damage("torso",roll_dice(2,10)+2);
      if(mysize == 3) {
        tell_object(ETO,"%^BOLD%^%^WHITE%^You use the momentum of your %^RESET%^%^RED%^po%^BOLD%^%^RED%^w"
"%^RESET%^%^RED%^erful %^BOLD%^%^WHITE%^blow to carry you forward, bringing the sword down in a second "
"successive strike!%^RESET%^");
        tell_room(EETO,"%^BOLD%^%^WHITE%^"+ETO->QCN+" uses the momentum of a %^RESET%^%^RED%^po%^BOLD%^%^RED%^w"
"%^RESET%^%^RED%^erful %^BOLD%^%^WHITE%^blow to carry "+ETO->QO+"self forward into a second successive "
"strike!%^RESET%^",ETO);
      }
      else {
        tell_object(ETO,"%^BOLD%^%^WHITE%^You land a single %^BOLD%^%^GREEN%^s%^BOLD%^%^CYAN%^wi%^BOLD%^%^GREEN%^ft "
"%^BOLD%^%^WHITE%^blow and twist, startling your opponent as you lash out again without warning!%^RESET%^");
        tell_room(EETO,"%^BOLD%^%^WHITE%^"+ETO->QCN+" lands a %^BOLD%^%^GREEN%^s%^BOLD%^%^CYAN%^wi%^BOLD%^%^GREEN%^ft "
"%^BOLD%^%^WHITE%^blow and twists, lashing out again with startling speed!%^RESET%^",ETO);
      }
      ETO->execute_attack();
    }
    return 0;
}

void init() {
   ::init();
   add_action("switch_hands","grip");
}

int switch_hands(string str) {
   int mysize,wepsize;
   string switchto;

   if(!str) return 0;
   if(!objectp(ETO)) return 0;
   if(!userp(ETO)) return 0;
   if((object)TO->query_wielded() != ETO) return 0;

   if(sscanf(str,"bastard sword in %s",switchto) != 1) {
     tell_object(ETO,"Syntax: <grip bastard sword in (one hand)/(two hands)>.");
     return 1;
   }
   mysize = (int)ETO->query_size();
   wepsize = (int)TO->query_size();
   switch(wepsize) {
     case 3:
       if(mysize > 2) { // a large race can't downsize; they would only use it as heavier size-3 opt by default
         tell_object(ETO,"You could only wield such a blade in one hand!");
         return 1;
       }
       if(mysize == 1) { // wha? They shouldn't have it at this setting!!
         tell_object(ETO,"How did you wield it at this size? Contact Nienne!");
         return 1;
       }
       if(switchto == "two hands") { // size 3, already 2h setting
         tell_object(ETO,"You're already holding it in a two-handed grip!");
         return 1;
       }
       if(switchto != "one hand") { // only 'two hands' and 'one hand' syntax will work
         tell_object(ETO,"Syntax: <grip bastard sword in (one hand)/(two hands)>.");
         return 1;
       }
       TO->set_property("silentwield",1);
       ETO->force_me("unwield thebastardswordx99");
       tell_object(ETO,"%^BOLD%^%^WHITE%^You ease off your sturdy grasp with both hands, shifting the blade's hilt to a lighter "
"single-handed hold.  You realise you could <grip bastard sword in two hands> to return to your previous fighting style.%^RESET%^");
       ETO->force_me("wield thebastardswordx99 in left hand");
     break;
     default: // should only run at size 2!
       if(mysize == 1) { // a small race can't upsize; they would only use it as smaller size-2 opt by default
         tell_object(ETO,"You could only wield such a blade in two hands anyway!");
         return 1;
       }
       if(mysize > 2) { // wha? They shouldn't have it at this setting!!
         tell_object(ETO,"How did you wield it at this size? Contact Nienne!");
         return 1;
       }
       if(switchto == "one hand") { // size 2, already 1h setting
         tell_object(ETO,"You're already holding it in a one-handed grip!");
         return 1;
       }
       if(switchto != "two hands") { // only 'two hands' and 'one hand' syntax will work
         tell_object(ETO,"Syntax: <grip bastard sword in (one hand)/(two hands)>.");
         return 1;
       }
       if(sizeof(ETO->query_wielded()) > 1) { // if more than 1 wep wielded (this one), they clearly don't have a free hand!
         tell_object(ETO,"You should probably have both hands free to wield it that way!");
         return 1;
       }
       if(member_array("shield",((mapping)ETO->query_body())["right hand"]["armour"]) != -1) { //if they have a shield on, they clearly don't have a free hand! shields are always in right hand
         tell_object(ETO,"You should probably have both hands free to wield it that way!");
         return 1;
       }
       TO->set_property("silentwield",1);
       ETO->force_me("unwield thebastardswordx99");
       tell_object(ETO,"%^BOLD%^%^WHITE%^You forgo your light single-handed hold for a more sturdy two-handed grip.  You realise "
"you could <grip bastard sword in one hand> to return to your previous fighting style.%^RESET%^");
       TO->set_mysize(3);
       ETO->force_me("wield thebastardswordx99");
     break;
   }
   return 1;
}

void set_mysize(int size) {
   if(size == 3) {
     TO->set_size(3);
     TO->set_wc(2,6);
     TO->set_large_wc(2,6);
     TO->set_weapon_speed(8);
     return;
   }
   TO->set_size(2);
   TO->set_wc(1,10);
   TO->set_large_wc(1,10);
   TO->set_weapon_speed(6);
}

/* From /d/common/obj/weapon/ inherits, for reference:
Bastard 2h:   set_size(3);   set_wc(2,6);   set_large_wc(2,6);   set_weapon_speed(8);
Bastard 1h:   set_size(2);   set_wc(1,8);   set_large_wc(1,8);   set_weapon_speed(6); */
