#include <std.h>
inherit "/d/common/obj/weapon/double_bladed_sword";

void create(){
	int placeholder, *placeholder2;
	::create();
	set_property("creator","gaius");
	set_property("quality",28);
	set_name("%^RED%^R%^BOLD%^o%^RESET%^%^RED%^se's %^RESET%^%^ORANGE%^F%^BOLD%^l%^RESET%^%^ORANGE%^am%^YELLOW%^e%^RESET%^");
	set_id(({ "sword", "double bladed sword", "double sword", "rose's flame", "roses flame", "%^RED%^R%^BOLD%^o%^RESET%^%^RED%^se's %^RESET%^%^ORANGE%^F%^BOLD%^l%^RESET%^%^ORANGE%^am%^YELLOW%^e%^RESET%^" }));
	set_short("%^BOLD%^%^WHITE%^Im%^BLACK%^m%^RESET%^a%^BOLD%^cu%^BLACK%^l%^RESET%^at%^BOLD%^e %^RESET%^%^ORANGE%^a%^BOLD%^da%^WHITE%^ma%^YELLOW%^nti%^RESET%^%^ORANGE%^um%^BOLD%^%^BLACK%^ double-bladed sword%^RESET%^");
	set_long("%^BOLD%^%^BLACK%^With an elongated hilt composed entirely of %^RED%^r%^RESET%^%^RED%^h%^BOLD%^o%^RESET%^%^RED%^do%^BOLD%^n%^RESET%^%^RED%^i%^BOLD%^%^RED%^te%^BOLD%^%^BLACK%^, this double-bladed sword "
	"makes an unmistakable impression.  The %^RED%^r%^RESET%^%^RED%^h%^BOLD%^o%^RESET%^%^RED%^do%^BOLD%^n%^RESET%^%^RED%^i%^BOLD%^%^RED%^te%^BOLD%^%^BLACK%^ itself is exquisitely carved with subtle grooves"
	" that are patterned after %^RESET%^%^ORANGE%^de%^YELLOW%^se%^RESET%^%^ORANGE%^rt %^RESET%^%^RED%^r%^BOLD%^o%^RESET%^%^RED%^ses%^BOLD%^%^BLACK%^, replete with %^RESET%^%^GREEN%^th%^BOLD%^o%^RESET%^%^GR"
	"EEN%^rns%^BOLD%^%^BLACK%^, that would make for a sure grip.  Blades on either end have been honed to exquisite sharpness and comprised of a material similar to %^RESET%^%^CYAN%^wa%^BOLD%^t%^WHITE%^e%^"
	"CYAN%^re%^RESET%^%^CYAN%^d%^RESET%^-s%^BOLD%^%^CYAN%^t%^WHITE%^e%^RESET%^el%^BOLD%^%^BLACK%^, a rarity to find in this age. A rough-hewn spine adds weight to each strike, and the chiseled point of eac"
	"h blade penetrates even the hardest of armors.  %^CYAN%^W%^RESET%^%^CYAN%^at%^BOLD%^%^WHITE%^e%^CYAN%^r%^BLACK%^ patterns within the blade add a %^RESET%^sm%^BOLD%^%^WHITE%^o%^BLACK%^k%^RESET%^y%^BOLD"
	"%^%^BLACK%^, sh%^WHITE%^a%^RESET%^d%^BOLD%^%^BLACK%^o%^BLUE%^w%^BLACK%^y effect to one's swings.  Starting from the midpoint of the bottom blade, wrapping snake-like about the hilt, and then finishing"
	" in dramatic flair just above the top blade's hilt is a %^RESET%^%^ORANGE%^b%^RED%^r%^YELLOW%^on%^RESET%^%^RED%^z%^ORANGE%^ed d%^RED%^r%^YELLOW%^a%^RESET%^%^RED%^g%^RESET%^%^ORANGE%^on%^BOLD%^%^BLACK%"
	"^ - its mouth agape as if it ready to breathe upon its enemies.  The legs and talons of both hind and forequarters comprise the cross-piece to each bladeside.  Finally, the sinewy, bat-like wings of t"
	"he great serpent are arranged in a rather striking fashion, swept forward with honed edges and brought to startling points where they might be used to catch weapons, or impale opponents. Curving along the main blade is an inscription in elegant script.%^RESET%^

Mastercrafte"
	"d"
	);
	set_lore("%^MAGENTA%^It is said that this weapon was forged in secret, with a secret - by a secret.  Originally thought to be crafted with the intent to bind the lady of a great house to a man from another, its"
	" purpose was seemingly misinterpreted from the outright.  Through desert sands, shadowed forests, deep oceans and seas, the components of this blade made their perilous journey, sought by many, and fo"
	"und by one.  Once crafted, the smith did gift the lady with the blade, but never did he claim her bond.  Her freedom wished, some say earned, was met with admiration and respect - her beauty unbound t"
	"o the path she, like a smith herself, must forge.%^RESET%^
"
	);
	set_read("\n%^BOLD%^%^CYAN%^Freedom is earned - Not given.\n May the path forged ahead be\n One of passion and mystery,\n  One served across an age.\n           ~G%^RESET%^");
	set_language("common");
	set_property("lore difficulty",28);
   set_property("enchantment",3);
   set_item_bonus("attack bonus",1);
   set_item_bonus("damage bonus",2);
   set_wield((:this_object(),"wield_func":));
   set_hit((:TO,"hit_func":));
}
int wield_func(){
   if((int)ETO->query_level() < 15) {
      tell_object(ETO,"%^RESET%^%^RED%^You do not have the power to wield this weapon yet.  It refuses you!%^RESET%^");
                return 0;
   }
      tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETOQCN+" grips the shaft of the weapon and quickly slashes one end to the right and the other to the left.%^RESET%^",ETO);
      tell_object(ETO,"%^BOLD%^%^BLACK%^You grip the shaft of the weapon and quickly slash one blade to the right and the other to the left.%^RESET%^");
      return 1;
}
int hit_func(object target) {
   if(!objectp(target)) return 0;
      if(random(1000) < 325){
        switch(random(5)){
         case 0:
            tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETO->query_cap_name()+" lunges forward and smashes the center of the shaft straight into "+target->query_cap_name()+"!%^RESET%^",({target,ETO}));
            tell_object(ETO,"%^BOLD%^%^BLACK%^You lunge forward and smash the center of the shaft straight into  "+target->query_cap_name()+"!%^RESET%^",target);
            tell_object(target,"%^BOLD%^%^BLACK%^"+ETO->query_cap_name()+" lunges towards you and smashes the center of the shaft right into you!%^RESET%^");
            target->set_paralyzed(20,"You are still reeling from the blow!");
            target->do_damage("torso",random(5)+1);
         break ;
           case 1..3:
           ETO->execute_attack();
tell_room(environment(ETO),"%^RESET%^%^RED%^"+ETO->query_cap_name()+" stabs one blade of "+ETO->query_possessive()+" into "+target->query_cap_name()+" with primal savagery before flipping the sword to strike again with the other!%^RESET%^",({target,ETO}));
       tell_object(ETO,"%^RESET%^%^RED%^You stab one blade of your weapon into "+target->query_cap_name()+" primal savagery before expertly flipping the sword to strike again with the other!%^RESET%^");
tell_object(target,"%^RESET%^%^RED%^"+ETO->query_cap_name()+" stabs one blade of "+ETO->query_possessive()+" into "+ETO->query_possessive()+" with primal savagery before expertly flipping the sword to strike again with the other!%^RESET%^");

            target->do_damage("torso",random(10)+1);
      }
   }
}
