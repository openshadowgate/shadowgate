//Octothorpe (2/15/10)
//Rod of Summoning for Myrkul to use with his plot
//Summons Weave Eater and Greater Mundanoid mobs specially created for plot

#include <std.h>
inherit "/d/common/obj/weapon/mstaff.c";

void create(){
   ::create();
   set_name("summoning staff");
   set_id(({"summoning staff","staff","summoning"}));
   set_short("%^BOLD%^%^BLACK%^Myrkul's Staff of Plottage "+
      "Summoning%^RESET%^");
   set_obvious_short("%^BOLD%^%^BLACK%^a long on%^RESET%^y%^BOLD%^"+
      "%^BLACK%^x staff%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^This magnificent staff was formed out "+
      "of a single piece of on%^RESET%^y%^BOLD%^%^BLACK%^x.  It "+
	  "emmanates with a foul energy, yet curiously a %^RESET%^g"+
	  "%^BOLD%^u%^RESET%^nm%^BOLD%^e%^RESET%^t%^BOLD%^a%^RESET%^l "+
	  "%^BOLD%^%^BLACK%^plate has been bolted onto the staff.\n "+
	  "The following is printed on the plate:\n "+
	  "%^BOLD%^%^WHITE%^While wielded, you can %^CYAN%^bringme "+
	  "<mob>%^WHITE%^.\n "+
	  "The following mobs are currently supported:\n "+
	  "%^CYAN%^Weave Eater & Greater Mundanoid%^RESET%^\n");
   set_wield((:TO,"wield_func":));
}

int wield_func(){
   if((int)ETO->query_highest_level() < 150){
      tell_object(ETO,"%^BOLD%^%^RED%^This object is for imm use only.%^RESET%^");
	  TO->move("/d/shadowgate/void");
	  TO->remove();
	  return 0;
   }
   return 1;
}

void init(){
   ::init();
   if(living(ETO)){
      add_action("bringme","bringme");
   }
}

int bringme(string str){
   if(!str){
      tell_object(ETO,"%^BOLD%^Bringme what?%^RESET%^");
      return 1;
   }  
   if(!(query_wielded())){
      tell_object(ETO,"%^BOLD%^You need to wield the staff to be "+
	     "able to do that.%^RESET%^");
      return 1;
   }
   if(str == "Weave Eater" || str == "weave eater"){
      new("/d/avatars/myrkul/weave_eater")->move(EETO);
	  tell_object(ETO,"%^BOLD%^Weaver Eater, (/d/avatars/myrkul"+
	     "/weave_eater.c), has been cloned.%^RESET%^");
	  return 1;
   }
   if(str == "Greater Mundanoid" || str == "greater mundanoid"){
      new("/d/avatars/myrkul/gtr_mundanoid")->move(EETO);
	  tell_object(ETO,"%^BOLD%^Greater Mundanoid, (/d/avatars/myrkul"+
	     "/gtr_mundanoid.c), has been cloned.%^RESET%^");	  
	  return 1;
   }
}