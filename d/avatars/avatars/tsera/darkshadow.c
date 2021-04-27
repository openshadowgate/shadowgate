//file 

#include <std.h>

inherit ARMOUR;

void create(){
    ::create();
    set_name("%^BOLD%^%^BLACK%^A%^RESET%^%^RED%^u%^BLACK%^%^BOLD%^ra of Sh%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^de%^RESET%^");
    set_id(({"cape","halo","shadow cloak","aura of shade","Aura of shade","Aura of Shade","aura","shade","shadows","shadow","cloak","shadow cloak"}));
    set_short("%^BOLD%^%^BLACK%^A%^RESET%^%^RED%^u%^BLACK%^%^BOLD%^ra of Sh%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^de%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^This flickering, formless mass of tenebrous shade undulates like a living thing."
" A halo of darkness, it flows liquidly giving off an unearthly %^BLUE%^ch%^CYAN%^i%^BLUE%^ll%^BLACK%^ as small"
" tentacles of shadow lance and curl outward, hungry to consume all %^YELLOW%^l%^WHITE%^i%^YELLOW%^ght%^BLACK%^"
" that comes near. Within the darkness, shapes form and disappear so quickly that you cannot be sure they were"
" there, %^RESET%^%^BLUE%^serpentine%^BOLD%^%^BLACK%^ bodies slithering within, their eyes flashing a"
" %^RESET%^%^RED%^blood red%^BOLD%^%^BLACK%^ before vanishing once more into the murk.%^RESET%^");
   set_weight(2);
   set_size(2);
   set_type("clothing");
   set_limbs(({"neck",}));
   set_ac(3);
   set_property("enchantment",1);
   set_value(10000);
   set_wear((:TO,"wear_it":));
   set_remove((:TO,"unwearme":));
   set_struck((:TO,"struck":));
   set_heart_beat(1);
}

int wear_it(string str){
    tell_object(ETO,"%^BOLD%^%^BLACK%^Dark shadows flow downwards along your body, entwining themselves around you like a dark halo.%^RESET%^");
    tell_room(environment(ETO),"%^BOLD%^%^BLACK%^The shade flows downward along "+ETO->query_cap_name()+"'s body, entwining itself about "+ETO->query_objective()+" like a dark halo.%^RESET%^",ETO);

return 1;
}
int unwearme(string str){
    tell_object(ETO,"%^BOLD%^%^BLACK%^The shade slowly withdraws from your body, the tendrils lingering and clinging to you as if unwilling to part.%^RESET%^");
     tell_room(environment(ETO),"%^BOLD%^%^BLACK%^The shade slowly withdraws itself from "+ETO->query_cap_name()+"'s body, the tendrils lingering and clinging to "+ETO->query_objective()+" as if unwilling to part.%^RESET%^",ETO);

return 1;
}

int struck(int damage, object what, object who){
   if(query_worn()){
      if(!random(2)){
         switch(random(3)){
            case 0:
               tell_room(EETO,"%^BLUE%^A serpentine tendril lances outward from "+ETO->query_cap_name()+"'s %^BOLD%^%^BLACK%^shroud %^RESET%^%^BLUE%^and deflects "+who->query_cap_name()+"'s blow harmlessly to the side.%^RESET%^",({who,ETO}));
               tell_object(who,"%^BLUE%^A serpentine tendril lances outward from "+ETO->query_cap_name()+"'s %^BOLD%^%^BLACK%^shroud, %^RESET%^%^BLUE%^deflecting your blow harmlessly to the side.%^RESET%^");
               tell_object(ETO,"%^BLUE%^A serpentine tendril lances outward from your %^BOLD%^%^BLACK%^shroud, %^RESET%^%^BLUE%^deflecting the incoming blow harmlessly to the side.%^RESET%^");
               break;
            case 1:
               tell_room(EETO,"%^BOLD%^%^BLACK%^Great black wings unfurl suddenly from "+ETO->query_cap_name()+"'s back, whipping around to parry "+who->query_cap_name()+"'s strike!%^RESET%^",({who,ETO}));
               tell_object(who,"%^BOLD%^%^BLACK%^Great black wings unfurl suddenly from "+ETO->query_cap_name()+"'s back, whipping around to parry your strike!%^RESET%^");
               tell_object(ETO,"%^BOLD%^%^BLACK%^Great black wings unfurl suddenly from your back, whipping around to parry "+who->query_cap_name()+"'s strike!%^RESET%^");
              break;
            case 3:
               tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETO->query_cap_name()+"'s form suddenly flickers as "+who->query_cap_name()+"'s strike passes through "+ETO->query_objective()+" as harmlessly as if "+ETO->query_subjective()+" were a shadow.%^RESET%^",({who,ETO}));
               tell_object(who,"%^BOLD%^%^BLACK%^"+ETO->query_cap_name()+"'s form suddenly flickers as your strike passes through "+ETO->query_objective()+" as harmlessly as if "+ETO->query_subjective()+" were a shadow.%^RESET%^");
               tell_object(ETO,"%^BOLD%^%^BLACK%^Your form suddenly flickers as "+who->query_cap_name()+"'s strike passes through you as harmlessly as if you were a shadow.%^RESET%^");
               break;
         }
      }
   return(-1)*(damage);
   }
}
void heart_beat(){
   if(query_worn()){
      switch(random(1003)){
      case 0..996:
      break;
      case 997:
      tell_object(ETO,"%^BOLD%^%^BLACK%^Tendrils of shade weave outward from your back, unfurling into gle%^WHITE%^a%^BLACK%^ming black wings before collapsing back into the darkness.%^RESET%^");
   if(!ETO->query_invis()){
      tell_room(EETO,"%^BOLD%^%^BLACK%^Tendrils of shade weave outward from "+ETO->query_cap_name()+"'s back, unfurling into gle%^WHITE%^a%^BLACK%^ming black wings before collapsing back into the darkness.%^RESET%^",ETO);
   }
   else { tell_room(EETO,"%^BOLD%^%^BLACK%^Tendrils of shade weave outward from the dark and unfurl into gle%^WHITE%^a%^BLACK%^ming black wings before collapsing back into the darkness.%^RESET%^",ETO); }
      break;
     case 998:
     tell_object(ETO,"%^BLUE%^A dark serpent slithers out of the %^BOLD%^%^BLACK%^shadows%^RESET%^%^BLUE%^ and hisses as it entwines itself about your arm before dispersing into a fine %^BOLD%^%^BLACK%^black mist.%^RESET%^");
    if(!ETO->query_invis()){
       tell_room(EETO,"%^BLUE%^A dark serpent slithers out of the %^BOLD%^%^BLACK%^shadows%^RESET%^%^BLUE%^ and hisses as it entwines itself about "+ETO->query_cap_name()+"'s arm before dispersing into a fine %^BOLD%^%^BLACK%^black mist.%^RESET%^",ETO);
    }
    else { tell_room(EETO,"%^BLUE%^A soft hiss echoes throughout the area.%^RESET%^",ETO); }
      break;
     case 999:
   tell_object(ETO,"%^BOLD%^%^BLACK%^The sh%^RESET%^a%^BOLD%^%^BLACK%^dows about you flicker and bend toward you as if wanting to touch you.%^RESET%^");
   if(!ETO->query_invis()){
      tell_room(EETO,"%^BOLD%^%^BLACK%^The sh%^RESET%^a%^BOLD%^%^BLACK%^dows about "+ETO->query_cap_name()+" flicker and bend toward "+ETO->query_objective()+" as if wanting to touch "+ETO->query_objective()+".%^RESET%^",ETO);
      }
      break;
     case 1000:
      tell_room(EETO,"%^BOLD%^%^BLACK%^From within the darkness slitted %^RESET%^%^RED%^cr%^BOLD%^i%^RESET%^%^RED%^mson eyes%^BLACK%^%^BOLD%^ peer out at you before vanishing completely.%^RESET%^");
      break;
     case 1001:
     if(!ETO->query_invis()){
        tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETO->query_cap_name()+"'s shadow grows larger behind "+ETO->query_objective()+", a d%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^mon%^RED%^i%^BLACK%^c silhouette with outstretched wings.%^RESET%^",ETO);
   }
   else { tell_room(EETO,"%^BOLD%^%^BLACK%^A dark shadow grows from seemingly nowhere and transforms into the image of a d%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^mon%^RED%^i%^BLACK%^c silhouette with outstretched wings.%^RESET%^",ETO); }
      break;
     case 1002:
     tell_object(ETO,"%^BOLD%^%^BLACK%^Whisps of darkness whip violently about your body.%^RESET%^");
     if(!ETO->query_invis()){
        tell_room(EETO,"%^BOLD%^%^BLACK%^Whisps of darkness whip violently about "+ETO->query_cap_name()+"'s body.%^RESET%^",ETO);
    }
      break;
      }
      return ;
   }
}