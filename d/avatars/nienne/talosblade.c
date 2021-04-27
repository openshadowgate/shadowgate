#include <std.h>
inherit "/d/common/obj/weapon/scimitar.c";

int mylevel;

void create(){
   ::create();
   set_name("%^BOLD%^%^BLACK%^darksteel scimitar%^RESET%^");
   set_id(({"scimitar","sword","darksteel scimitar","silver-etched scimitar","silver-etched scimitar of darksteel","maelstroms edge","maelstrom's edge","Maelstrom's Edge"}));
set_short("%^BOLD%^%^BLACK%^Ma%^RESET%^%^WHITE%^e%^BOLD%^l%^YELLOW%^s%^RESET%^%^WHITE%^t%^BOLD%^%^BLACK%^ro%^RESET%^%^WHITE%^m%^BOLD%^%^WHITE%^'%^BLACK%^s %^WHITE%^E%^CYAN%^d%^RESET%^%^WHITE%^g%^BOLD%^%^BLACK%^e%^RESET%^");
   set_obvious_short("%^BOLD%^%^BLACK%^a s%^RESET%^%^WHITE%^i%^BOLD%^l%^RESET%^%^WHITE%^v%^BOLD%^%^BLACK%^er-et%^RESET%^%^WHITE%^c%^BOLD%^h%^RESET%^%^WHITE%^e%^BOLD%^%^BLACK%^d scimitar of darksteel%^RESET%^");
   set_long("%^CYAN%^This dark, slender blade has been shaped with a slight "
"curve, which has been honed to a %^WHITE%^wickedly sharp%^CYAN%^ edge.  "
"Light reflects %^YELLOW%^sharply %^RESET%^%^CYAN%^off its%^BOLD%^%^BLACK%^ "
"dark %^RESET%^%^CYAN%^surface, marked along its length by a jagged, "
"seemingly random pattern of deep etchings.  Each is lined with fine "
"%^BOLD%^%^WHITE%^s%^RESET%^%^WHITE%^i%^BOLD%^%^BLACK%^lv%^RESET%^%^WHITE%^e"
"%^BOLD%^%^WHITE%^r%^RESET%^%^CYAN%^, and raised high enough to tear the "
"flesh as the blade cuts.  Its hilt is perfectly weighted, and lined in "
"%^BOLD%^%^WHITE%^s%^RESET%^%^WHITE%^i%^BOLD%^%^BLACK%^lv%^RESET%^%^WHITE%^e"
"%^BOLD%^%^WHITE%^r%^RESET%^%^CYAN%^ in a similar style to the blade, with a "
"curved guard to protect the hand.  A single gemstone of "
"%^RED%^str%^ORANGE%^e%^RED%^aked crim%^BOLD%^s%^RESET%^%^RED%^on%^CYAN%^ "
"has been set where the blade meets the hilt.  An exquisite blade, both in "
"crafting and deadliness.\n%^RESET%^");
   set_value(1200);
   set_weapon_speed(4);
   set_lore("This stunning blade was crafted in the year 537SG, by the drow "
"Talszarr, renowned for his dual fighting style of arcane spells and "
"bladecraft.  It was said to have taken decades of his life to craft, and "
"then imbue with the heavy enchantments that now reside within it.  Rumours "
"say he held a fascination bordering on obsession with the skies and storms "
"of the aboveworld, and tried to capture their ferocity within the weapon "
"itself.");
   set_property("lore difficulty",18);
   set_wield((:TO,"wield_func":));
   set_unwield((:TO,"unwield_func":));
   set_hit((:TO,"hit_func":));
}

int wield_func(){
   if((string)ETO->query_diety() != "talos") {
     tell_object(ETO,"%^YELLOW%^A crackle of lightning arcs up along "
"the blade's edge as you attempt to grasp its hilt!%^RESET%^");
     tell_room(EETO,"%^YELLOW%^A crackle of lightning arcs up along "
"the blade's edge as "+ETO->QCN+" attempts to grasp its "
"hilt!%^RESET%^",ETO);
     ETO->do_damage("torso",roll_dice(6,6));
     return 0;
   }
   if(ETO->query_lowest_level() < 30) {
     tell_object(ETO,"%^BOLD%^%^BLACK%^A shiver runs down your spine as "
"you reach for the blade... you can almost feel the energy radiating "
"from it. Touching it is probably a bad idea.%^RESET%^");
     tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETO->QCN+" seems about to take "
"up the blade, but thinks better of it.%^RESET%^",ETO);
     return 0;
   }
   switch(random(4)) {
     case 0:
       tell_object(ETO,"%^YELLOW%^A crackle of lightning arcs down the blade "
"as you grasp its hilt.%^RESET%^");
       tell_room(EETO,"%^YELLOW%^A crackle of lightning arcs down the blade "
"as "+ETO->QCN+" grasps its hilt.%^RESET%^",ETO);
     break;
     case 1:
       tell_object(ETO,"%^BOLD%^%^CYAN%^A sudden gust of wind buffets you as "
"you take up the scimitar.%^RESET%^");
       tell_room(EETO,"%^BOLD%^%^CYAN%^A sudden gust of wind buffets you as "
+ETO->QCN+" takes up "+ETO->QP+" scimitar.%^RESET%^",ETO);
     break;
     case 2:
       tell_object(ETO,"%^ORANGE%^The earth itself seems to rumble as your "
"fingers close around the hilt of the scimitar.%^RESET%^");
       tell_room(EETO,"%^ORANGE%^The earth itself seems to rumble as "
+ETO->QCN+"'s fingers close around the hilt of "+ETO->QP+
" scimitar.%^RESET%^",ETO);
     break;
     case 3:
       tell_object(ETO,"%^BOLD%^%^BLACK%^You take up the scimitar, and hear a peal of thunder somewhere in the distance.");
       tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETO->QCN+" takes up "+ETO->QP+
" scimitar, and you hear a peal of thunder somewhere in the "
"distance.%^RESET%^",ETO);
     break;
   }
   mylevel = ((int)ETO->query_lowest_level())/7;
   while ((int)TO->query_property("enchantment") != mylevel) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",mylevel);
   }
   ETO->add_attack_bonus(1);
   return 1;
}

int unwield_func(){
   tell_object(ETO,"%^CYAN%^Your energy seems to fade as you release your "
"grip on the scimitar.");
   tell_room(EETO,"%^CYAN%^"+ETO->QCN+" seems to calm as "+ETO->QS+" releases "
+ETO->QP+" grip on the scimitar.%^RESET%^",ETO);
   TO->remove_property("enchantment");
   ETO->add_attack_bonus(-1);
   return 1;
}

int hit_func(object targ){
   if(!objectp(TO)) return 1;
   if(!objectp(ETO)) return 1;
   if(!objectp(targ)) return 1;
   if(random(1000) < 200){
     switch(random(6)){
       case 0:
         tell_room(EETO,"%^BOLD%^%^BLACK%^%^"+ETOQCN+"'s blade tears into "
+targ->QCN+"'s flesh, its raised surface leaving a jagged wound in its "
"wake!%^RESET%^",({ETO,targ}));
         tell_object(ETO,"%^BOLD%^%^BLACK%^You slash into your opponent's "
"flesh, leaving a wickedly jagged wound!%^RESET%^");
         tell_object(targ,"%^BOLD%^%^BLACK%^"+ETOQCN+"'s blade tears into "
"your flesh, leaving a jagged wound in its wake!%^RESET%^");
         targ->do_damage(targ->return_target_limb(),roll_dice(3,4)+2);
       break;
       case 1:
         tell_room(EETO,"%^YELLOW%^A crackle of energy runs up "+ETOQCN+"'s "
"blade and arcs forcefully into "+targ->QCN+"!%^RESET%^",({ETO,targ}));
         tell_object(ETO,"%^YELLOW%^A crackle of energy runs up your blade, "
"arcing forcefully into "+targ->QCN+"!%^RESET%^");
         tell_object(targ,"%^YELLOW%^A crackle of energy runs up "+ETOQCN+"'s "
"blade and arcs forcefully into you!%^RESET%^");
         set_property("magic",1);
         targ->do_damage(targ->return_target_limb(),roll_dice(2,6)+3);
         remove_property("magic");
       break;
       case 2:
         ETO->execute_attack();
         tell_room(EETO,"%^BOLD%^%^CYAN%^Swirling winds pick up around you as "
+ETOQCN+" lashes out with lightning speed!%^RESET%^",ETO);
         tell_object(ETO,"%^BOLD%^%^CYAN%^Swirling winds pick up around you, "
"carrying you into another lightning-fast attack!%^RESET%^");
         targ->do_damage(targ->return_target_limb(),roll_dice(2,4)+4);
         break;
       case 3:
         tell_room(EETO,"%^BOLD%^%^WHITE%^The pommel of "+ETOQCN+"'s blade "
"connects with the side of "+targ->QCN+"'s head, and a thunderclap booms "
"forth to knock "+targ->QO+" from "+targ->QP+" feet!%^RESET%^",({ETO,targ}));
         tell_object(ETO,"%^BOLD%^%^WHITE%^The pommel of your blade connects "
"with the side of "+targ->QCN+"'s head, and a thunderclap booms forth, "
"knocking "+targ->QO+" from "+targ->QP+" feet!");
         tell_object(targ,"%^BOLD%^%^WHITE%^A thunderclap booms forth as "
"the pommel of "+ETOQCN+"'s blade connects with your head, knocking you from "
"your feet!%^RESET%^");
   targ->set_paralyzed(7,"The resonating boom is still echoing in your head!");
         targ->do_damage("head",roll_dice(1,10));
       break;
       case 4:
         tell_room(EETO,"%^BOLD%^%^BLUE%^The air suddenly turns icy around "
"you, and "+ETOQCN+"'s blade glitters like crystal as it hits "
+targ->QCN+"!%^RESET%^",({ETO,targ}));
         tell_object(ETO,"%^BOLD%^%^BLUE%^The air suddenly turns icy around "
"you, and your blade glitters like crystal as it hits "
+targ->QCN+"!%^RESET%^");
         tell_object(targ,"%^BOLD%^%^BLUE%^The air suddenly turns icy around "
"you, and "+ETOQCN+"'s blade glitters like crystal as it hits you!%^RESET%^");
         set_property("magic",1);
         targ->do_damage(targ->return_target_limb(),roll_dice(2,10));
         remove_property("magic");
       break;
       case 5:
         tell_room(EETO,"%^RED%^You catch a whiff of burning flesh, as "
+ETOQCN+"'s scimitar suddenly grows fiercely hot, searing "+targ->QCN+"'s "
"skin where it makes contact!%^RESET%^",({ETO,targ}));
         tell_object(ETO,"%^RED%^The scimitar takes on a blazing heat as it "
"sears "+targ->QCN+"'s flesh, so hot that even your own fingers sizzle "
"momentarily!%^RESET%^");
         tell_object(targ,"%^RED%^"+ETOQCN+"'s sword takes on an intense "
"heat, searing your flesh where it makes contact!%^RESET%^");
         set_property("magic",1);
         targ->do_damage(targ->return_target_limb(),(random(10)+10));
         ETO->do_damage("left hand",(random(4)+4));
         remove_property("magic");
       break;
     }
   return 1;
   }
}
