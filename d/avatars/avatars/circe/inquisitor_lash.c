//Circe 7/26/05 for NF
#include <std.h>
inherit "/d/common/obj/weapon/scourge";
void create(){
  ::create();
  set_name("chain whip");
  set_id(({"chain","whip","chain whip","lash"}));
  set_obvious_short("%^BOLD%^%^BLACK%^a black barbed whip%^RESET%^");
  set_short("%^RED%^Inq%^BOLD%^u%^RESET%^%^RED%^isit%^BOLD%^%^BLACK%^o"+
     "%^RESET%^%^RED%^r's %^BOLD%^%^BLACK%^Lash%^RESET%^");
  set_long("%^BOLD%^%^BLACK%^This whip is made of sinuous leather "+
     "that is supple to the touch in one direction.  Running a "+
     "finger along the other direction, however, causes thousands "+
     "of %^RED%^tiny barbs %^BLACK%^to bite at the flesh.  A single, "+
     "slender %^RED%^barb %^BLACK%^at the end of the whip grants an "+
     "added sting to the weapon.  The handle is made of carved "+
     "obs%^WHITE%^i%^BLACK%^dian, wrapped with slender leather thongs.%^RESET%^");
  set_lore("This whip was made for one purpose alone - to get answers.  "+
     "When used during an interrogation, the barbs pull at the flesh, "+
     "making the subject more willing to talk, usually.  Should they "+
     "not prove cooperative, however, it hardly matters, as the "+
     "whip can also make short work of a life.");
  set_value(20000);
  set_property("enchantment",4);
  set_wield((:TO,"wield_me":));
  set_unwield((:TO,"unwield_me":));
  set_hit((:TO,"extra_hit":));
}

int wield_me(){
   tell_object(ETO,"%^BOLD%^%^BLACK%^You grip the obs%^WHITE%^i"+
      "%^BLACK%^dian hilt and feel the power it commands.");
   tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETOQCN+" grasps the "+
      "obs%^WHITE%^i%^BLACK%^dian handle of a whip and "+
      "smirks coldly.",ETO);
   return 1;
}

int unwield_me(){
   tell_object(ETO,"%^BOLD%^%^BLACK%^You set aside the whip, "+
      "though you know it will be waiting anxiously for you.");
   tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETOQCN+" looks almost "+
      "regretful as "+ETO->QS+" sets aside the whip.",ETO);
   return 1;
}

int extra_hit(object ob){
   if(!objectp(ETO)) return 1;
   if(!objectp(ob)) return 1;
   if(!random(6)){
      tell_object(ETO,"%^BOLD%^%^RED%^You lash out with the whip, "+
         "flaying "+ob->QCN+"!");
      tell_object(ob,"%^BOLD%^%^RED%^"+ETOQCN+" strikes you with "+
         "a barbed whip, flaying the skin from your bones!");
      tell_room(EETO,"%^BOLD%^%^RED%^"+ETOQCN+" lashes out "+
         "at "+ob->QCN+" with a barbed whip, flaying "+ob->QP+" "+
         "skin!",({ETO,ob}));
      if(!random(4)){
         tell_object(ETO,"%^BOLD%^%^BLACK%^The barbs snag on "+
            ""+ob->QCN+", jerking "+ob->QO+" to the ground!");
         tell_object(ob,"%^BOLD%^%^BLACK%^The barbs snag "+
            "on your flesh, yanking you to the ground in "+
            "agony!");
         tell_room(EETO,"%^BOLD%^%^BLACK%^The barbs snag on "+
            ""+ob->QCN+", who goes tumbling to the ground!",({ETO,ob}));
         ob->set_tripped(1,"%^BOLD%^%^BLACK%^You're trying to find your feet!");
      }
   return random(8)+5;
   }
}
