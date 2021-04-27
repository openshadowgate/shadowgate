#include <std.h>
// fancy bracers, made by hades
#include <daemons.h>
inherit "/d/common/obj/armour/bracers";
int uses = 10;

void create(){
    ::create();

    set_name("Bracers of the weave");
    set_id(({ "bracers", "bracer", "bracers of the weave",}));
    set_short("%^RESET%^%^MAGENTA%^Bra%^BOLD%^ce"+
	"%^RESET%^%^MAGENTA%^rs of the w%^BOLD%^ea%^RESET%^%^MAGENTA%^ve%^RESET%^");
    set_obvious_short("%^RESET%^%^MAGENTA%^cloth covered bracers%^RESET%^");
    set_long(
"%^MAGENTA%^These bracers are created from many layers of fine %^BOLD%^purple%^RESET%^ "+
"%^MAGENTA%^cloth%^BLUE%^.%^MAGENTA%^  The cloth itself seems strange%^BLUE%^.%^MAGENTA%^  The weaving is "+
"extremly fine and almost seems to %^BOLD%^swirl%^RESET%^%^MAGENTA%^ on its own%^BLUE%^.%^MAGENTA%^  It "+
"gives off the aura of %^BOLD%^strange magic%^RESET%^%^MAGENTA%^%^BLUE%^.%^MAGENTA%^  There are many "+
"%^BLUE%^sapphires%^MAGENTA%^ that line the edges%^BLUE%^.%^MAGENTA%^  The bracers held together"+
" with several %^BLUE%^blue cloth straps%^MAGENTA%^ that fit under the forearm%^BLUE%^.%^MAGENTA%^\n"+
"%^RESET%^There is something that can be read on the back.");
    set_lore("%^MAGENTA%^These bracers were created by circle of"+
	" elven magi%^BLUE%^%^BLUE%^.%^MAGENTA%^%^MAGENTA%^  They used high magic to enchant "+
	"them with unenchantments%^BLUE%^.%^MAGENTA%^  That being said, they"+
	" are quite difficult to use%^BLUE%^.%^MAGENTA%^  It is said that only"+
	" aged ones can understand Mystra well enough to use these bracers%^BLUE%^.%^MAGENTA%^");
    set_property("lore difficulty",25);
    set_weight(1);
    set_value(1000);
    set_size(2);
    set_property("enchantment",4);
    set_remove((:TO,"remove_func":));
    set_wear( (:TO,"check":) );
    set_struck((:TO,"strike_func":));
}
void init(){
    ::init();
    add_action("read","read");
    add_action("dsm","dsm");
	add_action("recharge","recharge");

}
void recharge(string str){
  write("You focus on the bracers and they drain your energy to give them more power");
  ETO->set_paralyzed(30,"You are regaining your strength.");
  ETO->add_exp(-40000);
  uses +=1;
}
void read(string str){
    string tmp;
    if(!str || str != "bracer") return notify_fail("Read what?  Bracer?\n");
     
    write("These are bracers of dispel magic, it has the following function:\n"
        "dsm <name>: casts a polar ray at target(2 charges)\n"+
        uses+" charges left.\n"+
		"recharge: will drain your exp to give the bracers more power." );
    return 1;
}
void dsm(string str){
    object ob;
	if((string)ETO->query_real_age_cat()=="child" || (string)ETO->query_real_age_cat()=="normal"  )
	  return notify_fail("You are too young grasp this power");
	  if(ETO->query_casting()) return notify_fail("Already casting.");
    if(uses < 0) return notify_fail("The wand is out of charges.\n");
    if (ETO->query_bound() || ETO->query_unconscious()) {
       ETO->send_paralyzed_message("info",TP);
       return 1;
    }


    if(!str) return notify_fail("dsm who?\n");
    if(!(ob = present(str, ETP))) return notify_fail("That isn't here!\n");
    if(!ETO->is_class("mage") && !ETO->is_class("bard") &&
       !ETO->is_class("thief")) 
    return notify_fail("Only arcane spellcasters and"+
               " rogues can use this power.\n");
    if(ETO->is_class("mage"))
new("/cmds/wizard/_dispel_magic")->use_spell(ETO,ob,ETO->query_guild_level("mage"));
        else if(ETO->is_class("bard"))
        
new("/cmds/wizard/_dispel_magic")->use_spell(ETO,ob,ETO->query_guild_level("bard"));
    else if (ETO->is_class("thief"))
     new("/cmds/wizard/_dispel_magic")->use_spell(ETO,ob,25);

    uses --;
    return 1;
}
int check(){

   ::check();
   if(objectp(ETO) && ETO->query_property("no bracers")){    
       tell_object(ETO,"You are currently using an object that "+
          "cannot be worn with bracers.");
       return 0;
   }
 
   if((string)ETO->query_real_age_cat()=="child" || 
     (string)ETO->query_real_age_cat()=="normal"  ){
	  write("You are too young grasp this power"); 
      return 0;}	  
      tell_object(ETO,"%^MAGENTA%^The bracers seem to "+
	  "%^BOLD%^shimmer%^RESET%^%^MAGENTA%^ as you settle them on your forearms.");
      tell_room(EETO,"%^MAGENTA%^"+ETOQCN+"'s bracers seem to %^BOLD%^shimmer "+
         "%^RESET%^%^MAGENTA%^as they settle on "+ETO->QP+" forearms.",ETO);
      ETO->set_property("magic resistance",25);
	  return 1;
	  
   
}

int remove_func(){
    if(!ETO->query_invis()) {
        tell_room(EETO,"%^MAGENTA%^"+ETOQCN+"'s bracer shimmer "+
           "as "+ETO->QS+" removes them.",ETO);
    }
    tell_object(ETO,"%^MAGENTA%^You see the bracers shimmer as you "+
      "remove them.");
	ETO->set_property("magic resistance",-25);
        return 1;
}

int strike_func(int damage, object what, object who){
        if(random(1000) < 200){
        tell_room(environment(query_worn()),""+
            "%^BOLD%^%^BLUE%^"+ETOQCN+"'s bracers "+
            "glow blue as "+
            ""+who->QCN+" strikes them!",({ETO,who}));
        tell_object(ETO,"%^BOLD%^%^BLUE%^Your bracers "+
            "glow blue as "+
            ""+who->QCN+" strikes them!");
        tell_object(who,"%^BOLD%^%^BLUE%^"+ETOQCN+"'s bracers "+
            "glow blue as "+
            "you strike them!");
	    if(ETO->is_class("mage"))
new("/cmds/wizard/_dispel_magic")->use_spell(ETO,who,ETO->query_guild_level("mage"));
        else if(ETO->is_class("bard"))
        
new("/cmds/wizard/_dispel_magic")->use_spell(ETO,who,ETO->query_guild_level("bard"));
    else if (ETO->is_class("thief"))
     new("/cmds/wizard/_dispel_magic")->use_spell(ETO,who,25);
        return (damage-1);
 }
}
