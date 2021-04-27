// modified scythe of death for sengann
#include <std.h>
#include "/d/common/common.h"
inherit CWEAP"two_hand_scythe";

object owner;

void init() {
    ::init();
    if(interactive(ETO) && !owner) { owner = ETO->query_name(); }
}

void create() {
    ::create();
    set_name("scythe");
    set_id(({"scythe","scythe of the avenger","rune scythe","rune-inscribed scythe"}));
    set_short("%^BOLD%^%^BLACK%^Sc%^RESET%^%^RED%^y%^BOLD%^%^BLACK%^the "+
       "of the Av%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^nger%^RESET%^");
    set_obvious_short("%^BOLD%^%^BLACK%^Shimmering %^RESET%^%^RED%^r"+
       "%^BOLD%^u%^RESET%^%^RED%^n%^BLACK%^%^BOLD%^e inscr%^RED%^i"+
       "%^BLACK%^bed scythe%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^Forged of a shimmering spectral metal, "+
       "this sleekly curved weapon is truly of magnificent craft.  The "+
       "shadowy transparancy serves only to more fully accentuate the "+
       "%^BOLD%^%^RED%^gl%^RESET%^%^RED%^ow%^BOLD%^ing %^CYAN%^arcane "+
       "symbols %^BLACK%^inscribed along its surface, each one c%^RED%^r"+
       "%^RESET%^%^RED%^a%^BOLD%^c%^BLACK%^kling with its own %^RESET%^"+
       "%^RED%^po%^BOLD%^tent ene%^RESET%^%^RED%^rgy%^BOLD%^%^BLACK%^"+
       ".  The haft has been fashioned to resemble leaping tongues of "+
       "flame, each curling and lashing higher than the last, with "+
       "t%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^nd%^RESET%^%^RED%^r"+
       "%^BOLD%^%^BLACK%^i%^RESET%^%^RED%^l%^BOLD%^%^BLACK%^s of "+
       "fire that run the length of the column before "+
       "tapering off at a %^RESET%^%^RED%^serrated blade%^BOLD%^%^BLACK%^"+
       "-like tip.  The haft is topped with a coiled %^BOLD%^"+
       "%^WHITE%^salamander%^BLACK%^, its slitted eyes gleaming with a "+
       "%^RED%^fervent fire%^BLACK%^ and its fanged maw "+
       "spewing forth a %^RESET%^flickering ghostly blade%^BLACK%^"+
       "%^BOLD%^. The great curving blade emits a powerful %^RED%^he"+
       "%^YELLOW%^a%^RED%^t %^BLACK%^and as you watch you see rippling "+
       "waves of heat, each lashing wildly across its surface before "+
       "fading back into the blade as silently as they appeared.%^RESET%^"
    );
    set_lore("Once a weapon of choice for those of evil intent, "+
       "this weapon was reforged by Valchor of Shadow, as thanks "+
       "for the efforts of the firbolg Sengann in the apprehension "+
       "of the dangerous and wanted murderer, the gnome Jimijuker.");
    set_property("enchantment",4);
    set_value(4000);
    set_wield((:TO,"extra_wield":));
    set_hit((:TO,"extra_hit":));
}
int extra_wield() {
    int align;
    if(!userp(ETO)) return 1;

    if((int)ETO->query_level() < 25) {    
	tell_object(ETO,"%^BOLD%^%^BLACK%^The %^RED%^arcane symbols "+
         "%^BLACK%^flare to life and burn into your vision!");
	tell_room(EETO,"%^BOLD%^%^BLACK%^The %^RED%^arcane symbols "+
         "%^BLACK%^flare to life as "+ETOQCN+" tries to wield it!\n"+
         "%^RED%^It disappears!",ETO);
	ETO->do_damage("torso",random(25)+25);
	ETO->add_attacker(TO);
	ETO->continue_attack();
	ETO->remove_attacker(TO);
      ETO->set_blind(1);
	TO->remove();
	return 0;
    }
    if(interactive(ETO) && (string)ETO->query_name() != "sengann" && !avatarp(ETO)){
	tell_object(ETO,"%^BOLD%^%^BLACK%^You hear a crackling sound in "+
         "the air as the %^RED%^symbols %^BLACK%^flare to life "+
         "and the scythe vanishes!");
	tell_room(EETO,"%^BOLD%^%^BLACK%^You hear a crackling sound in "+
         "the air as the %^RED%^symbols %^BLACK%^flare to life "+
         "and the scythe vanishes when "+ETOQCN+" tries to wield it!",ETO);
	TO->remove();
	return 0;
    }
    tell_object(ETO,"%^BOLD%^%^BLACK%^A soft whisper fills your mind: "+
       "%^RED%^'%^BOLD%^%^BLACK%^Come, let us cleanse this land..."+
       "%^RESET%^%^RED%^'%^RESET%^");
    tell_object(ETO,"%^BOLD%^%^BLACK%^The shimmering haft of the weapon "+
       "ripples in your grasp, and you feel a new strength as its %^RED%^"+
       "e%^BLACK%^n%^RED%^e%^BLACK%^r%^RESET%^%^RED%^g%^BOLD%^y "+
       "%^BLACK%^washes over you.%^RESET%^");
    tell_room(EETO,"%^BOLD%^%^BLACK%^Ripples spread along the length of "+
       "the weapon as its %^RED%^e%^RESET%^%^RED%^n%^BOLD%^e%^RESET%^"+
       "%^RED%^rg%^BOLD%^y %^BLACK%^b%^RED%^u%^BLACK%^rsts "+
       "forth and %^RED%^a%^BLACK%^rcs along "+ETOQCN+"'s body.",ETO);
    return 1;
}

int extra_hit(object vic) {
    int dmg;
    object obj;
    string wielder = ETO;
    vic = ETO->query_current_attacker();
    if(!objectp(vic)) return 0;
    if(!random(4)){
       switch(random(80)){
          case 0..58:   tell_room(EETO,"%^BOLD%^%^BLACK%^A %^BOLD%^%^RED%^"+
                           "f%^ORANGE%^i%^RED%^e%^ORANGE%^r"+
                           "%^RED%^c%^ORANGE%^e sna%^RED%^r"+
                           "%^ORANGE%^l %^BLACK%^"+
                           "erupts from the blade as it %^RESET%^%^RED%^"+
                           "scythes%^BOLD%^%^BLACK%^ through "+vic->QCN+"!"+
                           "%^RESET%^",vic);
                        tell_object(vic,"%^BOLD%^%^BLACK%^As the blade "+
                           "%^RESET%^%^RED%^scythes%^BOLD%^%^BLACK%^ into "+
                           "you, a %^BOLD%^%^RED%^"+
                           "f%^ORANGE%^i%^RED%^e%^ORANGE%^r"+
                           "%^RED%^c%^ORANGE%^e sna%^RED%^r"+
                           "%^ORANGE%^l %^BOLD%^%^BLACK%^resonates through "+
                           "your body, setting your %^RESET%^%^RED%^blood "+
                           "%^YELLOW%^ab%^RED%^l%^YELLOW%^aze%^BLACK%^!%^RESET%^");
                        dmg = random(4)+8;
                        ETO->set_property("magic",1);
                        vic->do_damage(vic->return_target_limb(),dmg);
                        ETO->set_property("magic",-1);
                        break;
          case 59..65:  tell_room(EETO,"%^MAGENTA%^With surprising speed "+
                           ""+ETOQCN+" catches "+vic->QCN+"'s leg with "+
                           "the blade and sends "+vic->QO+" sprawling with "+
                           "a vicious kick to the chest!%^RESET%^",({ETO,vic}));
                        tell_object(ETO,"%^MAGENTA%^Deftly hooking the "+
                           "curving blade behind "+vic->QCN+"'s knee, you "+
                           "spin quickly to launch a kick to the chest "+
                           "that sends "+vic->QO+" sprawling!%^RESET%^");
                        tell_object(vic,"%^MAGENTA%^"+ETOQCN+" suddenly "+
                           "hooks your leg with "+ETO->QP+" curving "+
                           "blade and spins, sending you tumbling over "+
                           "with a solid kick to the chest!%^RESET%^");
                        vic->set_tripped(1,"You are trying to stand!");
                        break;
          case 66..71:  tell_room(EETO,"%^RED%^Spinning quickly "+
                           ""+ETOQCN+" sends "+vic->QCN+" stumbling "+
                           "with a vicious slash, then quickly slams "+
                           "the serrated tip down into "+vic->QP+" "+
                           "%^BOLD%^%^BLACK%^shadow%^RESET%^%^RED%^, trapping "+
                           "it!%^RESET%^",({ETO,vic}));
                        tell_object(ETO,"%^RED%^With a vicious strike "+
                           "you send "+vic->QCN+" stumbling back, then "+
                           "quickly slam the serrated tip down into "+
                           ""+vic->QP+" %^BOLD%^%^BLACK%^shadow%^RESET%^%^RED%^, "+
                           "trapping it!%^RESET%^");
                        tell_object(vic,"%^RED%^With a vicious strike "+
                           ""+ETOQCN+" sends you stumbling back, then "+
                           "quickly slams the serrated tip down into "+
                           "your %^BOLD%^%^BLACK%^shadow%^RESET%^%^RED%^, "+
                           "trapping it!%^RESET%^");
                        tell_room(EETO,"%^BOLD%^%^BLACK%^The shadow "+
                           "rises up before "+ETOQCN+"!",ETO);
                        tell_object(ETO,"%^BOLD%^%^BLACK%^The shadow "+
                           "rises up before you!");
                        obj = new("/d/avatars/nienne/scythe_shadow");
	                  obj->move(EETO);
	                  obj->force_me("protect "+wielder->query_name());
	                  wielder->add_follower(obj);
                        break;
          case 72..76:  tell_room(EETO,"%^BLUE%^"+ETOQCN+" spins, "+
                           "sweeping "+ETO->QP+" %^RED%^scythe%^BLUE%^ "+
                           "through "+vic->QCN+" before suddenly "+
                           "reversing "+ETO->QP+" momentum and driving "+
                           "the weapon's barbed tip deep into "+
                           ""+vic->QP+" %^BOLD%^%^RED%^gut%^RESET%^"+
                           "%^BLUE%^!%^RESET%^",({ETO,vic}));
                        tell_object(ETO,"%^BLUE%^Whirling with your "+
                           "blade, you slash your %^RED%^scythe%^BLUE%^ "+
                           "through "+vic->QCN+", you suddenly reverse "+
                           "your momentum, driving the weapon's barbed "+
                           "tip deep into "+vic->QP+" %^BOLD%^%^RED%^gut"+
                           "%^RESET%^%^BLUE%^!%^RESET%^");
                        tell_object(vic,"%^BLUE%^"+ETOQCN+" spins, "+
                           "sweeping "+ETO->QP+" %^RED%^scythe%^BLUE%^ "+
                           "through you before suddenly reversing "+
                           ""+ETO->QP+" momentum and driving the "+
                           "weapon's barbed tip deep into your "+
                           "%^BOLD%^%^RED%^gut%^RESET%^%^BLUE%^!%^RESET%^");
                        dmg = random(8)+12;
                        ETO->set_property("magic",1);
                        vic->do_damage(vic->return_target_limb(),dmg);
                        ETO->set_property("magic",-1);
                        break;
          case 77..79:  if(!(int)vic->query_stats("constitution") > random(25)){
                       tell_object(ETO,"%^RED%^The %^RESET%^"+
                          "fi%^BOLD%^%^BLACK%^e%^RESET%^ry "+
                          "%^RED%^scything blade suddenly %^BOLD%^"+
                          "fl%^RESET%^%^RED%^a%^BOLD%^res %^RESET%^"+
                          "%^RED%^to life as it sinks deeply into "+
                          ""+vic->QCN+"'s chest!%^RESET%^");
                       tell_room(EETO,"%^RED%^The fiery "+
                          "scything blade suddenly %^BOLD%^fl%^RESET%^"+
                          "%^RED%^a%^BOLD%^res%^RESET%^%^RED%^ to "+
                          "life as it sinks deeply into "+vic->QCN+"'s "+
                          "chest.%^RESET%^",({ETO,vic}));
                       tell_room(EETO,"%^RED%^"+vic->QCN+" "+ 
                          "screams, clutching the haft of the weapon "+
                          "as the %^BOLD%^%^WHITE%^color %^RESET%^"+
                          "%^RED%^is drained from "+vic->QP+" skin "+
                          "and "+vic->QP+" eyes melt as crimson "+
                          "%^BOLD%^flames%^RESET%^%^RED%^ pour "+
                          "from the sockets!%^RESET%^",vic);
                       tell_object(ETO,"%^RED%^You tug the "+
                          "weapon free contemptiously letting the "+
                          "lifeless body fall to the ground.%^RESET%^");
                       tell_room(EETO,"%^RED%^"+ETOQCN+" smirks "+
                          "contemptiously as "+ETO->QS+" tugs the "+
                          "weapon free, letting the lifeless body "+
                          "fall to the ground.%^RESET%^",({ETO,vic}));
                       tell_object(vic,"%^RED%^The %^RESET%^fi"+
                          "%^BOLD%^%^BLACK%^e%^RESET%^ry %^RED%^"+
                          "scything blade suddenly %^BOLD%^fl%^RESET%^"+
                          "%^RED%^a%^BOLD%^res %^RESET%^%^RED%^to "+
                          "life as it sinks deeply into your chest!%^RESET%^");
                       tell_object(vic,"%^RED%^Your mind is suddenly "+
                          "filled with a thousand images of %^BOLD%^"+
                          "%^BLACK%^searing flames%^RESET%^%^RED%^, and "+
                          "your blood seems to ignite!%^RESET%^");
                       tell_object(vic,"%^RED%^Clutching at the "+
                          "weapon in you, you scream as your vision "+
                          "turns %^RED%^blood-red%^RESET%^%^RED%^ and "+
                          "then, everything goes %^BOLD%^%^BLACK%^"+
                          "black...%^RESET%^");
                       vic->set_hp(-1000);
                     }else{
                       tell_object(vic,"%^RED%^You barely move in time to "+
                          "avoid being beheaded by "+ETOQCN+"'s scythe!  "+
                          "%^BOLD%^Blood pours everywhere!");
                       tell_room(EETO,"%^RED%^The %^RESET%^fi%^BOLD%^"+
                          "%^BLACK%^e%^RESET%^ry %^RED%^scything "+
                          "blade suddenly %^BOLD%^fl%^RESET%^%^RED%^"+
                          "a%^BOLD%^res %^RESET%^%^RED%^to life as "+
                          "it sinks deeply into "+vic->QCN+"'s chest!"+
                          "%^RESET%^",vic);
                       tell_room(EETO,"%^RED%^"+vic->QCN+" screams, "+
                          "clutching at the shaft of the weapon, before "+
                          "gritting "+vic->QP+" teeth and pushing "+
                          "free, stumbling back.%^RESET%^",vic);
                       tell_object(vic,"%^RED%^The %^RESET%^fi"+
                          "%^BOLD%^%^BLACK%^e%^RESET%^ry %^RED%^"+
                          "scything blade suddenly %^BOLD%^fl%^RESET%^"+
                          "%^RED%^a%^BOLD%^res %^RESET%^%^RED%^to "+
                          "life as it sinks deeply into your chest!%^RESET%^");
                       tell_object(vic,"%^RED%^You scream as you feel "+
                          "the blade's blazing power tearing at your "+
                          "essence, before gritting your teeth and "+
                          "pushing free, stumbling back.%^RESET%^");
                       ETO->set_property("magic",1);
                       vic->do_damage("torso",random(50)+50);
                       ETO->set_property("magic",-1);
                     }
                     break;
          default:  break;
       }
   return random(3)+2;
   }
   return random(2)+1;
}
