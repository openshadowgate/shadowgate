#include <std.h>
inherit "/d/common/obj/weapon/two_hand_sword";

void create(){
   ::create();
   set_name("sword");
   set_id(({"sword","longsword","long sword","sword sheathed in energy","sword sheathed in otherworldly energy","iskcaex","isk'caex","Isk'caex","dragonslayer","dragon slayer"}));
   set_short("%^RESET%^%^MAGENTA%^Is%^BOLD%^%^BLACK%^k'ca%^RESET%^ex t%^GREEN%^he D%^BOLD%^rag%^RESET%^%^ORANGE%^ons%^YELLOW%^lay%^WHITE%^er%^RESET%^");
   set_obvious_short("%^BOLD%^%^BLACK%^a sword sheathed in %^RESET%^%^MAGENTA%^o%^BOLD%^%^BLACK%^t%^RESET%^h%^MAGENTA%^erw%^BOLD%^%^BLACK%^o%^RESET%^r%^MAGENTA%^ld%^BOLD%^%^BLACK%^l%^RESET%^%^MAGENTA%^y e%^BOLD%^%^BLACK%^n%^RESET%^e%^MAGENTA%^rgy%^RESET%^");
   set_long("%^BOLD%^%^BLUE%^With its grip sheathed in %^RESET%^%^ORANGE%^g%^YELLOW%^o%^BLACK%^l%^RESET%^"
"%^ORANGE%^den l%^YELLOW%^e%^BLACK%^a%^RESET%^%^ORANGE%^ther %^BOLD%^%^BLUE%^and set with bands of %^GREEN%^s"
"%^BLACK%^p%^RESET%^%^GREEN%^i%^BOLD%^ral%^RESET%^%^GREEN%^in%^BOLD%^g j%^BLACK%^a%^RESET%^%^GREEN%^d%^BOLD%^e"
"%^BLUE%^ and %^WHITE%^o%^RESET%^%^MAGENTA%^n%^RESET%^y%^BOLD%^%^WHITE%^x-f%^RESET%^%^MAGENTA%^i%^RESET%^r"
"%^BOLD%^%^WHITE%^e%^BLUE%^, this weapon is designed for one purpose and one purpose only, that of slaying a "
"dragon. Crackling with %^RESET%^%^MAGENTA%^o%^BOLD%^%^BLACK%^t%^RESET%^h%^MAGENTA%^erw%^BOLD%^%^BLACK%^o"
"%^RESET%^r%^MAGENTA%^ld%^BOLD%^%^BLACK%^l%^RESET%^%^MAGENTA%^y e%^BOLD%^%^BLACK%^n%^RESET%^e%^MAGENTA%^rgy"
"%^BOLD%^%^BLUE%^, arcane power plays along the long, straight blade before coalescing and jumping with "
"%^RESET%^%^ORANGE%^c%^YELLOW%^r%^BLACK%^a%^RESET%^%^ORANGE%^ck%^YELLOW%^l%^BLACK%^i%^RESET%^%^ORANGE%^ng "
"a%^YELLOW%^r%^BLACK%^c%^RESET%^%^ORANGE%^s %^BOLD%^%^BLUE%^to oscillate and flow over both heads of the war-"
"axe shaped crossguard. Forged from a blend of unknown metals the sword is %^BOLD%^%^BLACK%^d%^RESET%^"
"%^MAGENTA%^a%^RESET%^r%^BOLD%^%^BLACK%^kly h%^RESET%^%^MAGENTA%^u%^RESET%^e%^BOLD%^%^BLACK%^d%^BLUE%^, nearly "
"midnight at its core, with %^WHITE%^i%^RESET%^%^MAGENTA%^r%^RESET%^i%^BOLD%^%^WHITE%^desc%^RESET%^%^MAGENTA%^e"
"%^RESET%^n%^BOLD%^%^WHITE%^t s%^RESET%^%^MAGENTA%^w%^RESET%^i%^BOLD%^%^WHITE%^rls %^BLUE%^passing through it "
"in ribbons of illumination. Sharply ablaze against the deep gloss of the weapon's length, these %^RESET%^"
"%^MAGENTA%^s%^BLACK%^%^BOLD%^w%^RESET%^i%^RESET%^%^MAGENTA%^r%^BOLD%^%^BLACK%^l%^RESET%^%^MAGENTA%^s %^BOLD%^"
"%^BLUE%^glow with arcane %^BOLD%^%^WHITE%^b%^YELLOW%^r%^RESET%^i%^BOLD%^%^WHITE%^llia%^YELLOW%^n%^RESET%^c"
"%^BOLD%^%^WHITE%^e %^BOLD%^%^BLUE%^before giving way to a razor sharp, %^BOLD%^%^WHITE%^s%^BLACK%^i%^RESET%^l"
"%^BOLD%^%^BLACK%^v%^WHITE%^er %^BLUE%^edges. At the center of the crossguard a pair of fist sized, oval "
"%^RESET%^%^ORANGE%^t%^YELLOW%^i%^BLACK%^g%^RESET%^%^ORANGE%^er-e%^YELLOW%^y%^BLACK%^e%^RESET%^%^ORANGE%^s "
"%^BOLD%^%^BLUE%^have been set in a raised mount. The mount hiding the mechanical workings that allow the twin "
"axes to straighten into a proper cross guard, or curve back along the hilt to provide %^GREEN%^p%^BLACK%^r"
"%^RESET%^%^GREEN%^o%^BOLD%^tec%^BLACK%^t%^RESET%^%^GREEN%^i%^BOLD%^on %^BLUE%^for the hands that grip it. Two "
"handed, the weapon is meant for only one who is willing to master the weapon's unique form and balance"
".%^RESET%^\n");
   set_property("enchantment",4);
   set_lore("The actual lore behind the creation and enchanting of Isk'caex the Dragonslayer has been obscured "
"and is likely known to only the few who actually were involved in the crafting process. What is known, or at "
"least well rumored, is that the weapon was created for Drakan Slaion Bokara, wielder of Helism the Dragons "
"Bane Sword and famed dragon slayer of the Tsarven Empire. It is believed that the emperor himself gave Isk'"
"caex to Drakan with hopes that the blade would lend itself to his arsenal. This, after hearing of how the "
"great black wrym Feshung had knocked Helism from Drakan's hand during their epic battle. The idea of a backup "
"dragon slayer seemed wise, but it is said that Drakan has yet to wield Isk'caex. Instead he keeps Helism by "
"his side and lends the dark blade to would be dragon slayers who have proven their abilities by slaying at "
"least three evil dragons and presenting their heads to Drakan's father Vishnu to verify the validity of the "
"kill. It is rumored that this blade was lent to Brenamen Xelinos in the spring of 686 SG for use in battle "
"against Klauth.");
   set_property("lore difficulty",20);
   set_value(7550);
   set_wield((:TO,"wieldit":));
   set_hit((:TO,"hitit":));
   set_unwield((:TO,"unwieldit":));
}

int wieldit() {
   tell_object(ETO,"%^RESET%^%^MAGENTA%^The power of the sword vibrates through you, filling your mind with "
"hissing words: %^BOLD%^%^BLACK%^Where is the dragon, the one called Klauth?%^RESET%^");
   tell_room(EETO,"%^RESET%^%^MAGENTA%^"+ETO->QCN+" looks down at the sword with surprise!%^RESET%^",ETO);
   return 1;
}

int unwieldit() {
   tell_object(ETO,"%^RESET%^%^MAGENTA%^As you put the sword aside, the hissing voice stops filling your mind, "
"giving you some relief.%^RESET%^");
   tell_room(EETO,"%^RESET%^%^MAGENTA%^"+ETO->QCN+" sighs as "+ETO->QS+" sets the sword aside.%^RESET%^",ETO);
   return 1;
}

int hitit(object ob){
   int dmges;
   object targ;
   if(!objectp(TO)) return 1;
   if(!objectp(ETO)) return 1;
   targ = ETO->query_current_attacker();
   if(!objectp(targ)) return 1;
   if(member_array("klauth",targ->query_id()) == -1) return 1;

   if(random(1000) < 250 && !TO->query_property("whirling")){
     switch(random(6)){
       case 0..2:
         tell_object(ETO,"%^BOLD%^%^GREEN%^As the sword %^BOLD%^%^GREEN%^strikes "+targ->QCN+", it draws life "
"and vitality from the very soul of the dragon, infusing you with its power!%^RESET%^");
         tell_object(targ,"%^BOLD%^%^GREEN%^You feel the life sucked from your very soul, your vitality "
"drained away as a hissing voice screams triumph at you!%^RESET%^");
         tell_room(EETO,"%^BOLD%^%^GREEN%^"+ETO->QCN+" is surrounded with a pale aura that leaves them "
"refreshed and healthy looking.%^RESET%^",({ETO,targ}));
         dmges = (roll_dice(3,4)+5)*2;
         targ->do_damage(targ->return_target_limb(),dmges);
         TO->set_property("magic",1);
         ETO->do_damage(targ->return_target_limb(),dmges*(-1));
         TO->set_property("magic",-1);
       break;
       case 3..5:
         tell_object(ETO,"%^BOLD%^%^BLACK%^The axe blades upon the sword's crossguard %^BOLD%^%^BLACK%^rotate "
"up and turn to nearly flat before they begin to spin faster and faster around the blade's base. As you strike "
"out at "+targ->QCN+" you watch as the spinning blades slice deeply into "+targ->QP+" body, shredding %^RED%^"
"flesh%^BLACK%^, %^RESET%^%^CYAN%^sinew %^BOLD%^%^BLACK%^and %^WHITE%^bone %^BLACK%^as though it were little "
"more than paper!%^RESET%^");
         tell_object(targ,"%^BOLD%^%^BLACK%^Oh the pain! "+ETO->QCN+"'s sword %^BOLD%^%^BLACK%^comes to life "
"and with a hateful gleam begins to tear into your %^RED%^flesh %^BLACK%^and %^WHITE%^bone %^BLACK%^with the "
"spinning blades that create the crossguard! This is going to hurt so much!%^RESET%^");
         tell_room(EETO,"%^BOLD%^%^BLACK%^The twin axe blades upon the crosshilt of "+ETO->QCN+"'s sword "
"%^BOLD%^%^BLACK%^begin to spin around the hilt of the blade creating a whirlwind as "+ETO->QS+" carves into "
+targ->QCN+"'s hide!%^RESET%^",({ETO,targ}));
         TO->set_property("whirling",1);
         ETO->execute_attack();
         ETO->execute_attack();
         ETO->execute_attack();
         TO->set_property("whirling",-1);
       break;
     }
   }
   else return (roll_dice(3,4)+5);
}