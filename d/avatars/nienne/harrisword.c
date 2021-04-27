#include <std.h>
inherit "/d/common/obj/weapon/scimitar.c";

void create(){
   ::create();
    set_name("%^BOLD%^%^WHITE%^adamantium scimitar%^RESET%^");
    set_id(({ "sword","scimitar","Call of Justice","call of justice","adamantium scimitar"}));
    set_short("%^BOLD%^%^WHITE%^C%^YELLOW%^a%^CYAN%^l%^WHITE%^l o%^YELLOW%^f %^WHITE%^J%^YELLOW%^u%^CYAN%^sti%^YELLOW%^c%^WHITE%^e%^RESET%^");
    set_obvious_short("%^BOLD%^%^WHITE%^A %^YELLOW%^shining %^CYAN%^bright %^WHITE%^scimitar%^RESET%^");
    set_long("%^BOLD%^%^WHITE%^This scimitar has been %^MAGENTA%^infused "
"%^WHITE%^with an almost supernatural, bright %^YELLOW%^glow %^WHITE%^which "
"seems to radiate from within the weapon itself, as if it had a %^CYAN%^soul "
"%^WHITE%^of its own. All along the edge of the broad, well-curved blade, an "
"%^RED%^inscription %^WHITE%^in beautifully crafted letters has been "
"engraved. To further enhance the purity of the sword, %^BLUE%^Lord Tyr's "
"%^WHITE%^holy %^BLACK%^hammer %^WHITE%^and %^BLACK%^scales %^WHITE%^have "
"been etched into the side of the blade. Two impressive %^RESET%^%^ORANGE%^"
"war dogs %^BOLD%^%^WHITE%^leap out in oppsite directions, thus creating a "
"secure crosspiece, holding the blade entangled with their tails. The hilt is "
"shaped in the form of a hammer, with the %^YELLOW%^gilded %^WHITE%^head as a "
"mighty pommel.%^RESET%^");
   set("read","%^BOLD%^%^RED%^- Justice through benevolent force and armed "
"vigilance -%^RESET%^");
   set("langage","common");
   set_lore("This magnificent scimitar was crafted in the year 679SG. Forged "
"by a master smith of a thousand names, it was imbued with enchantments drawn "
"from a drow scimitar by the magess and lorekeeper Ellora St Cyr. These dark "
"enchantments were then blessed and purified with the power of Tyr by his "
"faithful priest, Knight Commander Harrison Fisher, resulting in this blessed "
"scimitar. It is said that only a truly blessed follower of the Maimed God "
"can lift the blade against a foe.");
   set_property("lore difficulty",26);
   while ((int)TO->query_property("enchantment") != 4) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",4);
   }
   set_value(3200);
   set_wield((:TO,"wield_func":));
   set_unwield((:TO,"unwield_func":));
   set_hit((:TO,"hit_func":));
}

int wield_func(){
   if((string)ETO->query_diety() != "tyr" && !avatarp(TP)) {
     tell_object(ETO,"%^YELLOW%^A shiver runs down your spine as you reach "
"for the blade... you can almost feel the strength and energy radiating from "
"it. Touching it is probably a bad idea.");
     tell_room(EETO,"%^YELLOW%^"+ETO->QCN+" seems about to take up the blade, "
"but thinks better of it.",ETO);
     return 0;
   }
   if(ETO->query_lowest_level() < 35) {
     tell_object(ETO,"%^YELLOW%^A shiver runs down your spine as you reach "
"for the blade... you can almost feel the strength and energy radiating from "
"it. Touching it is probably a bad idea.");
     tell_room(EETO,"%^YELLOW%^"+ETO->QCN+" seems about to take up the blade, "
"but thinks better of it.",ETO);
     return 0;
   }
   tell_object(ETO,"%^YELLOW%^A great feeling of strength and righteousness "
"fills you as you take up the scimitar.%^RESET%^");
   tell_room(EETO,"%^YELLOW%^"+ETO->QCN+" seems filled with confidence as "
+ETO->QS+" lifts the scimitar.%^RESET%^",ETO);
   ETO->add_attack_bonus(1);
   return 1;
}

int unwield_func(){
   tell_object(ETO,"%^YELLOW%^The rush of confidence fades as you release the "
"scimitar, but you know that %^BLUE%^Tyr %^YELLOW%^is still watching over "
"you.");
   tell_room(EETO,"%^YELLOW%^"+ETO->QCN+" becomes more subdued as "+ETO->QS+
" releases the scimitar.%^RESET%^",ETO);
   ETO->add_attack_bonus(-1);
   return 1;
}

int hit_func(object targ) {
   targ = ETO->query_current_attacker();
   if(!objectp(targ) || !objectp(ETO)) return 1;
   if(!random(5)) {
     switch(random(9)) {
        case 0..4:
          tell_object(targ,"%^YELLOW%^The scimitar %^RED%^glows%^YELLOW%^ "
"intensely as a %^CYAN%^spectral war dog %^YELLOW%^leaps out, tearing and "
"ripping your flesh with its jaws!%^RESET%^");
          tell_room(EETO,"%^YELLOW%^The scimitar %^RED%^glows%^YELLOW%^ "
"intensely as a %^CYAN%^spectral war dog %^YELLOW%^leaps out, tearing and "
"ripping "+targ->QCN+"'s flesh with its jaws!%^RESET%^", targ);
        set_property("magic",1);
          targ->do_damage(targ->return_target_limb(),random(6)+5);
        set_property("magic",-1);
          break;
        case 5..6:
           tell_object(targ, "%^BOLD%^%^BLUE%^A mighty %^CYAN%^war hammer "
"%^BLUE%^of pure %^WHITE%^light %^BLUE%^rises from "+ETO->QCN+"'s blade and "
"strikes you, sending you reeling to the ground!%^RESET%^");
           tell_room(EETO,"%^BOLD%^%^BLUE%^A mighty %^CYAN%^war hammer "
"%^BLUE%^of pure %^WHITE%^light %^BLUE%^rises from "+ETO->QCN+"'s blade and "
"strikes "+targ->QCN+", sending "+targ->QO+" reeling to the "
"ground!%^RESET%^",({targ,ETO}));
           tell_object(ETO,"%^BOLD%^%^BLUE%^A mighty %^CYAN%^war hammer "
"%^BLUE%^of pure %^WHITE%^light %^BLUE%^rises from your blade and strikes "
+targ->QCN+", sending "+targ->QO+" reeling to the ground!%^RESET%^");
        set_property("magic",1);
          targ->do_damage(targ->return_target_limb(),random(4)+3);
        set_property("magic",-1);
          targ->set_paralyzed(15,"You are recovering from that hit.");
          break;
        case 7..8:
           tell_object(targ,"%^BOLD%^%^RED%^As "+ETO->QCN+" swings "+ETO->QP+
" %^YELLOW%^scimitar %^RED%^in a wide arc, it seems to come %^WHITE%^alive"
"%^RED%^, and strikes at you again of its own accord!%^RESET%^");
           tell_room(EETO,"%^BOLD%^%^RED%^As "+ETO->QCN+" swings "+ETO->QP+
" %^YELLOW%^scimitar %^RED%^in a wide arc, it seems to come %^WHITE%^alive"
"%^RED%^, and strikes at "+targ->QCN+" again of its own "
"accord!%^RESET%^",({targ,ETO}));
           tell_object(ETO,"%^BOLD%^%^RED%^As you swing your %^YELLOW%^"
"scimitar %^RED%^in a wide arc, it seems to come %^WHITE%^alive%^RED%^, and "
"strikes at "+targ->QCN+" again of its own accord!%^RESET%^");
           ETO->execute_attack();
           break;
        default:
           break;
      }
   return 1;
   }
}
