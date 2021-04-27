#include <std.h>
inherit ARMOUR;
#define MAXUSES 10
int uses, flag;

void create(){
	::create();
	set_name("Ring of Light");
	set_id(({ "ring", "ring of light", "light ring", "protection ring", "ring of protection" }));
	set_short("%^YELLOW%^Ring of %^BOLD%^%^WHITE%^L%^YELLOW%^i%^BOLD%^%^WHITE%^g%^YELLOW%^h%^BOLD%^%^WHITE%^t%^RESET%^");
	set_obvious_short("shining ring");
	set_long(
@AVATAR
%^YELLOW%^This ring is formed from two bands of metal that have been spiraled together.  One band is a deep %^RED%^cri%^YELLOW%^m%^RED%^son%^YELLOW%^ and has small etchings on the upper side of it.  The other band is made from a completely smooth, %^CYAN%^sapphire%^YELLOW%^ colored metal.  A %^RED%^warmth%^YELLOW%^ continually radiates forth from this ring and a very tiny inscription is engraved into the underside of it, overlapped onto both bands.%^RESET%^

AVATAR
	);
	set("read",
@AVATAR
%^YELLOW%^Light I shall be, if thee command me.%^RESET%^

AVATAR
	);
	set_weight(2);
	set_value(300);
	set_type("ring");
	set_limbs(({ "right hand", "left hand" }));
	set_size(2);
	set_property("enchantment",4);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
	flag=1;
}

void init(){
    ::init();
    add_action("light","light");
}

int wear_func(){
   object *stuff;
   int i,j, flag;
   stuff = TP->all_armour();
   j = sizeof(stuff);
   for(i=0;i<j;i++){
      if(!objectp(stuff[i])) continue;
      if((string)stuff[i]->query_type() == "ring"){
         if(member_array("ring of protection",stuff[i]->query_id()) != -1){
            flag = 1;
            break;
         }
      }
   }
   if(flag){
      write("%^BOLD%^The magic of the ring already worn prevents you from wearing this one!");
      return 0;
   }
   tell_room(ETP,"%^YELLOW%^A soft %^CYAN%^glow%^YELLOW%^ comes forth from "+ETO->query_cap_name()+"'s "+query_short()+"%^YELLOW%^!%^RESET%^",TP);
   tell_object(TP,"%^YELLOW%^A magical %^RED%^warmth%^YELLOW%^ comes forth from the "+query_short()+"%^YELLOW%^ and encompasses your hand!%^RESET%^");
   ETO->set_property("magic resistance",5);
   return 1;
}

int remove_func(){
	tell_room(EETO,"%^YELLOW%^The glow %^RED%^radiating%^YELLOW%^ forth from "+ETO->query_cap_name()+"'s "+query_short()+"%^YELLOW%^suddenly dims!%^RESET%^",ETO);
	tell_object(ETO,"%^YELLOW%^Your hand suddenly %^BLUE%^cools%^YELLOW%^ as you remove the "+query_short()+"%^YELLOW%^!%^RESET%^");
	ETO->set_property("magic resistance",-5);
	return 1;
}

int light(string str){
    if(str) notify_fail("light is all thee need command me\n");
    if (TP->query_bound() || TP->query_unconscious()) {
       TP->send_paralyzed_message("info",TP);
       return 0;
    } 
    if(!query_worn()) {
        write("You must wear the ring first.\n");
        return 1;
    }
    if(flag == 0)  {
       write("The ring fails to respond.\n");
       return 1;
    }
    if(uses < MAXUSES){
       tell_room(ETO,"%^BOLD%^YELLOW%^The ring lights up the room.");
       new("/cmds/priest/_light.c")->use_spell(TO,TP,10);
       flag=0;
       call_out("reset_flag",100,TO);
       uses += 1;
       return 1;
    }
    write("The ring is out of charges.");
    return 1;
}

void reset_flag(){flag=1;}
