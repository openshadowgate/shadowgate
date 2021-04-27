#include <std.h>
inherit "/d/common/obj/weapon/battle_axe";

void create() {
   ::create();
   set_name("flint axe");
   set_id(({"axe","stonehewer axe","flint headed axe","flint-headed axe","stonehewer's axe"}));
   set_short("%^BOLD%^%^BLACK%^Sto%^RESET%^n%^BOLD%^%^BLACK%^ehew%^RESET%^%^ORANGE%^e%^BOLD%^%^BLACK%^r's Axe%^RESET%^");
   set_obvious_short("%^BOLD%^%^BLACK%^A flint-headed axe%^RESET%^");
   set_long("%^RESET%^%^ORANGE%^At a first look, this weapon seems quite "
"%^CYAN%^primitive %^ORANGE%^in design, sporting a wedge-shaped head hewn from "
"what appears to be %^BOLD%^%^BLACK%^flint%^RESET%^%^ORANGE%^. Closer "
"inspection, however, reveals that the weapon carries more a deliberate and "
"precise design than its stone-crafted head would suggest. Its edge is of a "
"deep angle designed to add splitting force to the weapon, with the tip honed "
"to a %^YELLOW%^razor-sharp edge%^RESET%^%^ORANGE%^. A handle of %^RED%^solid "
"oak %^ORANGE%^is hafted to the blade, polished smooth to afford an easy grip "
"for the wielder. Not a particularly light weapon, it could still likely be "
"wielded in one hand by a strong human. Upon the heel of the haft, a small "
"sigil has been burnt into the wood, in the image of an %^RESET%^axe "
"%^ORANGE%^crossed by a %^BLUE%^mining pick%^ORANGE%^.%^RESET%^\n");
   set_value(2550);
   set_property("enchantment",3);
   set_lore("Commonly crafted by dwarven smiths, these axes are usually blessed "
"by their priests. Given the dwarven inclination to wariness of arcane magic, "
"enchanted weapons are usually imbued by clerics among their people, and thus "
"usually echo themes of those faiths held close to dwarvish hearts. Most common "
"are those of Grumbarryn and Tempussan origins, with distinct weaponry "
"heralding motifs and symbols of these faiths. They are often marked with a "
"sigil indicating the dwarven house that forged the weapon.\n");
   set_property("lore difficulty",12);
   set_wield("%^ORANGE%^The axe haft fits comfortably in your grip.%^RESET%^");
   set_unwield("%^ORANGE%^You release the heavy axe.%^RESET%^");
   set_hit((:TO,"hit_fun":));
}

int hit_fun(object targ) {
   object *armour, ob;
   int i, flag;
   targ = ETO->query_current_attacker();
   if(random(25)<4){
     switch(random(20)){
       case 0..13:
/*        armour = targ->query_armour("torso");
       for (i=0;i<sizeof(armour);i++) {
        if ((string)armour[i]->query_type() == "chain" || (string)armour[i]->query_type() == "armour") flag=1;
       }
       if(flag) {
         tell_object(ETO,"%^YELLOW%^Sparks fly as your axe glances off "
+targ->QCN+"'s armor and sinks into "+targ->QP+" flesh!%^RESET%^");
         tell_object(targ,"%^YELLOW%^Sparks fly as "+ETO->QCN+"'s axe glances "
"off your armor and sinks into your flesh!%^RESET%^");
         tell_room(EETO,"%^YELLOW%^Sparks fly as "+ETO->QCN+"'s axe glances off "
+targ->QCN+"'s armor and sinks into "+targ->QP+" flesh!%^RESET%^",({ETO,targ}));
       }
       else { */
         tell_object(ETO,"%^YELLOW%^Your axe sinks deeply into "+targ->QCN+
"'s flesh!%^RESET%^");
         tell_object(targ,"%^YELLOW%^"+ETO->QCN+"'s axe sinks deeply into your "
"flesh!%^RESET%^");
         tell_room(EETO,"%^YELLOW%^"+ETO->QCN+"'s axe sinks deeply into "
+targ->QCN+"'s flesh!%^RESET%^",({ETO,targ}));
//       }
       return 8;
       break;

       case 14..19:
       tell_object(ETO,"%^BOLD%^%^BLACK%^The impact of your axe causes a shard "
"of stone to break free from the head, embedding itself into "+targ->QCN+
"'s skin.%^RESET%^");
       tell_object(targ,"%^BOLD%^%^BLACK%^The impact of "+ETOQCN+"'s axe causes "
"a shard of stone to break free from the head, embedding itself into your "
"skin.%^RESET%^");
       tell_room(EETO,"%^BOLD%^%^BLACK%^The impact of "+ETOQCN+"'s axe causes "
"a shard of stone to break free from the head, embedding itself into "+targ->QCN+
"'s skin.%^RESET%^",({ETO,targ}));
       targ->do_damage("torso",random(3)+3);
       ob = new("/d/islands/tonerra/obj/stonechip");
       ob->move(targ);
       ob->hurt(targ);
       break;
     }
   }
   return 1;
}
