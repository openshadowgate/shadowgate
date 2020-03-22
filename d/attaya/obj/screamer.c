// Fixed several syntax errors ~Circe~ 11/05/07
// modified to run off new through-stoneskin code. Nienne, 02/08.
//Changed to level 20 wield, down from level 25.  I figure that cutting thru SS should count as a +1, thus +4 wield levels.  Octothorpe 5/6/09
// changed to only hit thru stoneskin on specials, but v high special rate. Moved wield level back to 25, as special is pretty badass. Nienne, 08/09.
//Getting rid of damage override and type override. It's a dagger.  If we want it to be a different type of weapon, so be it, but it's change base type ~ Odin
#include <std.h>

//inherit WEAPON;
inherit "/d/common/obj/weapon/dagger.c";

string OWNER;

void init(){
    ::init();
    if(interactive(TP) && TP==ETO && !OWNER) OWNER = TPQN;
}

void create(){
    ::create();
    set_name("screamer");
    set_id( ({"dagger","horrible screaming dagger","screaming dagger","dagger","horrible dagger","screamer"}) );
    set_short("%^BOLD%^%^RED%^Horrible screaming dagger%^RESET%^");
    set_obvious_short("%^RED%^an engraved dagger%^RESET%^");
/*    set_long(
      "A horrible dagger with an engraved blade.  The detail is magnificent "
      +"yet the scene depicted upon it's wicked blade is a gruesome one. "
      +"A young girl is lying beneath a dead tree, bleeding from numerous "
      +"wounds in her chest.  The blood has pooled around a glowing dagger with "
      +"it's blade planted in the earth."
    );
Old description - updated by Circe
*/
    set_long(
       "%^RED%^This wicked dagger is fashioned wholly from a "+
       "%^BOLD%^blood red gemstone%^RESET%^%^RED%^ that seems to soak up the "+
       "light, reflecting not a glimmer.  Hilt, crossguard, and "+
       "blade are all perfectly formed, leading the eye to a "+
       "gruesome scene etched into the blade.  The artwork is magnificent, clearly "+
       "completed by a master, making the picture itself all the "+
       "more %^BOLD%^%^BLACK%^haunting%^RESET%^%^RED%^.  Within that thin "+
       "blade rests the image of a beautiful young girl lying beneath "+
       "a %^ORANGE%^dead tree%^RED%^, %^BOLD%^blood %^RESET%^%^RED%^pouring "+
       "from numerous stab wounds in her chest.  Her long hair "+
       "swirls on the ground around her in a pool of her own %^BOLD%^"+
       "blood%^RESET%^%^RED%^, encircling a %^BOLD%^%^BLACK%^"+
       "dagger %^RESET%^%^RED%^with its blade planted in the earth.%^RESET%^"
    );
    set_lore("This dagger is known commonly as a 'horrible screaming "+
       "dagger', a name which clearly conveys what the dagger is "+
       "known to do but tells little of why.  The exact story of "+
       "the first such dagger is unknown fully, though the picture "+
       "on the blade hints at its creation.  Legends tell of a "+
       "dagger such as this that was able to trap the soul of its "+
       "victim, holding it evermore within the blade.  A sacrifice "+
       "must be made during the creation of the blade, it is said, "+
       "and the most desirable sacrifice was a young, beautiful "+
       "virgin, for such are believed to have the purest souls..."+
       "and know the greatest terror.  The screaming of the blade "+
       "is actually the screaming of the trapped soul, lost forever "+
       "in torment.  A vile weapon indeed, wielded only by those "+
       "most corrupt.  - A History of Daggers, by H.L. Reinault.");
    set_property("lore difficulty",20);
    //set_weight(5);
    set_value(1000);
    //set_wc(1,6);
    //set_large_wc(1,8);
    set_size(1);
    //set_weapon_prof("exotic");
    //set_prof_type("screamer");
    //set_type("slashing");
    set_property("enchantment",4);
    set_wield((:TO,"extra_wield":));
    set_unwield((:TO,"removeme":));
    set_hit((:TO,"extra_hit":));
}

int extra_wield(){
   if(ETO->is_player()){
//added because monsters weren't wielding their weapons ~Circe~ 5/4/11
      if((int)ETO->query_level() < 25){
         tell_object(ETO,"%^BOLD%^%^RED%^A shadowy presence tells "+
            "you: %^RESET%^You pathetic little fool, you cannot "+
            "handle such power!");
         return 0;
      }
      if(!ETO->is_class("thief")){
         tell_object(ETO,"%^BLUE%^The dagger flies out of your hand!");
         return 0;
      }
      if(interactive(ETO) && (string)ETO->query_name() != OWNER){
         tell_object(ETO,"%^MAGENTA%^You are not chosen by the gods to wield such power.");
         return 0;
      }
   }
   tell_object(ETO,"%^BLUE%^The hideous dagger suddenly makes a "+
      "horrible noise as if it were screaming!");
   tell_room(EETO,"%^RED%^"+ETOQCN+" gives a smug smile as a dagger "+
         "in "+ETO->QP+" possession begins screaming.%^RESET%^",ETO);
   ETO->set_property("evil item",1);
   return 1;
}

int removeme(){
   ETO->set_property("evil item",-1);
   return 1;
}

int extra_hit(object targ){
   targ = ETO->query_current_attacker();
   if(!objectp(targ)) return 0;
   if(random(1000) < 400){
     tell_object(ETO,"%^RED%^A horrible scream echos out from the dagger itself!");
     tell_room(EETO,"%^RED%^The dagger wielded by "+ETOQCN+" screams horribly "+
      "as it slashes "+targ->QCN+"'s body, spattering blood everywhere!%^RESET%^",({ETO,targ}));
     tell_object(targ,"%^BOLD%^%^RED%^The horrible dagger wielded by "+ETOQCN+" "+
      "lets out a haunting scream as it tears into you!");
     TO->set_property("magic",1);
     targ->do_damage("torso",roll_dice(3,12));
     TO->set_property("magic",-1);
   }
   return 0;
}
