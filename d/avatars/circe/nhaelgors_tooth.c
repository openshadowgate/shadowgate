//Reward for Aunuit for the Tharis plot. Coded by ~Circe~ 10/26/11
//Descriptions provided by Aunuit
//Based on /d/token_hunt/obj/high/songblade.c and
///d/avatars/myrkul/moonwand.c

#include <std.h>
#include <daemons.h>

inherit "/d/common/obj/weapon/mace.c";

int hit_func;
int wield_func;
int unwield_func;

void create() {
   ::create();
   set_id(({"wand","ivory wand","N'haelgor's Tooth","n'haelgor's tooth","tooth","Tooth"}));
   set_name("ivory wand");
   set_obvious_short("%^RESET%^%^WHITE%^i%^BOLD%^%^WHITE%^v%^ORANGE%^o"+
      "%^WHITE%^r%^RESET%^y %^BOLD%^%^WHITE%^w%^RESET%^a%^BOLD%^%^WHITE%^nd "+
      "%^BLACK%^with a %^RESET%^%^MAGENTA%^b%^BOLD%^%^MAGENTA%^e%^RESET%^"+
      "%^MAGENTA%^j%^BOLD%^%^MAGENTA%^e%^RESET%^%^MAGENTA%^w%^WHITE%^e"+
      "%^MAGENTA%^l%^BOLD%^%^MAGENTA%^e%^RESET%^%^MAGENTA%^d %^RESET%^pl"+
      "%^BOLD%^%^CYAN%^a%^RESET%^ti%^BOLD%^%^WHITE%^n%^CYAN%^u%^WHITE%^m "+
      "%^RESET%^h%^MAGENTA%^a%^WHITE%^ndl%^BOLD%^%^WHITE%^e%^RESET%^");
   set_short("%^BOLD%^%^WHITE%^N'%^RESET%^h%^BOLD%^%^CYAN%^a%^ORANGE%^e"+
      "%^RESET%^l%^BOLD%^%^WHITE%^g%^RESET%^o%^BOLD%^%^WHITE%^r's T"+
      "%^MAGENTA%^o%^RESET%^%^MAGENTA%^o%^BOLD%^%^WHITE%^th%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^Crafted from an %^WHITE%^iv%^ORANGE%^o"+
      "%^WHITE%^ry %^BLACK%^material that upon closer inspection "+
      "appears to be %^WHITE%^b%^RESET%^o%^BOLD%^%^WHITE%^ne%^BLACK%^, "+
      "this %^WHITE%^wand %^BLACK%^is surprisingly light weight and very "+
      "durable. The %^WHITE%^sh%^ORANGE%^a%^RESET%^f%^BOLD%^%^WHITE%^t "+
      "%^BLACK%^is approximately six inches long and two inches in "+
      "diameter at the base, though it becomes gradually slimmer toward "+
      "the tip. The %^WHITE%^p%^RESET%^a%^BOLD%^%^WHITE%^le b%^ORANGE%^o"+
      "%^WHITE%^ne %^BLACK%^has been sanded until its surface is a "+
      "flawless cylinder. The %^WHITE%^wand %^BLACK%^sports a solid "+
      "%^RESET%^p%^BOLD%^%^WHITE%^l%^CYAN%^a%^WHITE%^t%^RESET%^in%^CYAN%^"+
      "u%^WHITE%^m h%^BOLD%^%^CYAN%^a%^RESET%^ndl%^BOLD%^%^WHITE%^e "+
      "%^BLACK%^inl%^RESET%^%^MAGENTA%^a%^BOLD%^%^MAGENTA%^i%^BLACK%^d "+
      "with o%^MAGENTA%^v%^BLACK%^al-shaped %^RESET%^%^MAGENTA%^ameth%^BOLD%^"+
      "%^MAGENTA%^y%^RESET%^%^MAGENTA%^st o%^BOLD%^%^MAGENTA%^p%^WHITE%^a"+
      "%^RESET%^%^MAGENTA%^ls %^BOLD%^%^BLACK%^surrounded by thin borders "+
      "of %^RESET%^t%^BOLD%^%^CYAN%^i%^RESET%^ny s%^BOLD%^%^WHITE%^p%^CYAN%^"+
      "a%^WHITE%^r%^RESET%^kl%^BOLD%^%^BLACK%^i%^RESET%^ng d%^BOLD%^%^CYAN%^i"+
      "%^WHITE%^a%^RESET%^m%^CYAN%^o%^WHITE%^nds%^BOLD%^%^BLACK%^. The hilt "+
      "contributes opulent flair to this otherwise simplistic, but beautiful "+
      "weapon. %^CYAN%^Ar%^RESET%^%^CYAN%^c%^BOLD%^%^CYAN%^ane e%^RESET%^"+
      "%^CYAN%^n%^BOLD%^%^CYAN%^ergy %^BLACK%^swells within the %^MAGENTA%^"+
      "la%^RESET%^%^MAGENTA%^v%^BOLD%^%^MAGENTA%^ender-h%^RESET%^%^MAGENTA%^"+
      "u%^WHITE%^e%^BOLD%^%^MAGENTA%^d gems%^BLACK%^, growing from a tiny "+
      "%^MAGENTA%^gl%^WHITE%^i%^RESET%^m%^BOLD%^%^WHITE%^m%^MAGENTA%^er "+
      "%^BLACK%^to a %^RESET%^%^MAGENTA%^br%^BOLD%^%^WHITE%^i%^MAGENTA%^g"+
      "%^WHITE%^h%^RESET%^%^MAGENTA%^t gl%^BOLD%^%^MAGENTA%^o%^RESET%^"+
      "%^MAGENTA%^w %^BOLD%^%^BLACK%^before %^RESET%^%^MAGENTA%^eb%^BOLD%^"+
      "%^MAGENTA%^b%^RESET%^i%^BOLD%^%^WHITE%^ng%^BLACK%^. The wand %^WHITE%^"+
      "p%^RESET%^u%^BOLD%^%^WHITE%^lsat%^RESET%^e%^BOLD%^%^WHITE%^s %^BLACK%^"+
      "subtly, not so strongly that it affects its owner's aim, but enough "+
      "to indicate a %^CYAN%^sentien%^RESET%^%^CYAN%^c%^BOLD%^%^CYAN%^e%^BLACK%^.%^RESET%^");
   set_lore("On the 17th of Winterstime in 703 Shadowgate the Dark elven "+
      "forces of House Teken'ghym engaged the human army of Tharis deep "+
      "within the Darkwood forest. Their forces combined with that of the "+
      "Sylvans' defeated the human army and took control over the Elven "+
      "Quarter of the city. After the victory at the Darkwood she abolished "+
      "House Teken'ghym and named she and her brother, Ryzan, Queen and King "+
      "of the Dark elves as well as took the surname Rilynath, House of "+
      "Dragons. As a sign of his approval, the god Vhaerun sent the great "+
      "Shadow dragon N'haelgor to bestow a gift upon Aunuit. N'haelgor shed "+
      "one of his own teeth and in Dark elven guise presented it to Aunuit. "+
      "She and her apprentice Pyranda forged the tooth into this powerful wand.");
   set_property("lore difficulty",25);
   set_value(15000);
   set_property("enchantment",5);
   set_property("able to cast",1);
   set_item_bonus("caster level",1);
   set_item_bonus("spell penetration",5);
   set_item_bonus("intelligence",2);
   set_hit((:TO,"hit_func":));
   set_wield((:TO,"wield_func":));
   set_unwield((:TO,"unwield_func":));
   set_overallStatus(150);
   set_property("no repair",1);      
   set_heart_beat(1);
}

int wield_func(){
      tell_object(ETO,"RESET%^%^MAGENTA%^Your %^BOLD%^%^CYAN%^w%^BOLD%^%^WHITE%^a"+
         "%^CYAN%^nd %^RESET%^%^MAGENTA%^s%^BOLD%^%^MAGENTA%^i%^RESET%^%^MAGENTA%^ngs "+
         "with %^BOLD%^%^WHITE%^d%^RESET%^e%^BOLD%^%^WHITE%^li%^RESET%^g%^BOLD%^"+
         "%^ORANGE%^h%^WHITE%^t %^RESET%^%^MAGENTA%^as you wield it.%^RESET%^");
      tell_room(EETO,"%^RESET%^%^MAGENTA%^"+ETOQCN+"'s %^BOLD%^%^WHITE%^w%^CYAN%^a"+
         "%^WHITE%^nd %^RESET%^%^MAGENTA%^s%^BOLD%^%^MAGENTA%^i%^RESET%^%^MAGENTA%^"+
         "ngs with %^BOLD%^%^WHITE%^d%^RESET%^e%^BOLD%^%^WHITE%^li%^RESET%^g%^BOLD%^"+
         "%^ORANGE%^h%^WHITE%^t%^RESET%^%^MAGENTA%^ as "+ETO->QS+" wields it.%^RESET%^",ETO);
   return 1;
}

int unwield_func(){
      tell_object(ETO,"%^BOLD%^%^BLACK%^Your %^WHITE%^w%^RESET%^%^MAGENTA%^a%^BOLD%^%^WHITE%^nd "+
         "%^BLACK%^seems to %^CYAN%^s%^RESET%^i%^CYAN%^g%^BOLD%^%^CYAN%^h %^BLACK%^as you "+
         "release it.%^RESET%^");
      tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETOQCN+"'s %^WHITE%^w%^RESET%^%^MAGENTA%^a%^BOLD%^"+
         "%^WHITE%^nd %^BLACK%^seems to %^CYAN%^s%^RESET%^i%^CYAN%^g%^BOLD%^%^CYAN%^h "+
         "%^BLACK%^as "+ETO->QS+" releases it.%^RESET%^",ETO);
   return 1;
}

int hit_func(object target) {
   object ob;
   if(!objectp(target)) return 0;
   if(random(1000) < 300){
      switch(random(12)){
 	   case 0..4:
  	      tell_object(ETO,"%^RESET%^%^MAGENTA%^You deftly manipulate your %^BOLD%^%^WHITE%^"+
               "w%^CYAN%^a%^WHITE%^nd%^RESET%^%^MAGENTA%^, firing one %^CYAN%^b%^BOLD%^"+
               "%^CYAN%^e%^RESET%^a%^CYAN%^m %^MAGENTA%^of %^CYAN%^ar%^BOLD%^%^CYAN%^c"+
               "%^RESET%^%^CYAN%^ane e%^BOLD%^%^CYAN%^n%^RESET%^%^CYAN%^ergy %^MAGENTA%^after "+
               "an%^BOLD%^%^CYAN%^o%^RESET%^%^MAGENTA%^ther at "+target->QCN+".%^RESET%^");
            tell_object(target,"%^RESET%^%^MAGENTA%^"+ETOQCN+" deftly manipulates "+ETO->QP+" "+
               "%^BOLD%^%^WHITE%^w%^CYAN%^a%^WHITE%^nd%^RESET%^%^MAGENTA%^, firing one "+
               "%^CYAN%^b%^BOLD%^%^CYAN%^e%^RESET%^a%^CYAN%^m %^MAGENTA%^of %^CYAN%^ar"+
               "%^BOLD%^%^CYAN%^c%^RESET%^%^CYAN%^ane e%^BOLD%^%^CYAN%^n%^RESET%^%^CYAN%^"+
               "ergy %^MAGENTA%^after an%^BOLD%^%^CYAN%^o%^RESET%^%^MAGENTA%^ther "+
               "at you.%^RESET%^");
            tell_room(EETO, "%^RESET%^%^MAGENTA%^"+ETOQCN+" deftly manipulates "+ETO->QP+" "+
               "%^BOLD%^%^WHITE%^w%^CYAN%^a%^WHITE%^nd%^RESET%^%^MAGENTA%^, firing one "+
               "%^CYAN%^b%^BOLD%^%^CYAN%^e%^RESET%^a%^CYAN%^m %^MAGENTA%^of %^CYAN%^ar"+
               "%^BOLD%^%^CYAN%^c%^RESET%^%^CYAN%^ane e%^BOLD%^%^CYAN%^n%^RESET%^%^CYAN%^"+
               "ergy %^MAGENTA%^after an%^BOLD%^%^CYAN%^o%^RESET%^%^MAGENTA%^ther "+
               "at "+target->QCN+".%^RESET%^",({ETO,target}));
            ETO->execute_attack();
            break;
 	   case 5..10:
            tell_object(ETO,"%^RESET%^%^RED%^You point your %^BOLD%^%^WHITE%^w%^ORANGE%^a"+
               "%^WHITE%^nd %^RESET%^%^RED%^at "+target->QCN+" and gr%^BOLD%^%^RED%^o"+
               "%^RESET%^%^RED%^wl, '%^BOLD%^%^RED%^Flamgra%^RESET%^%^RED%^.' Your "+
               "%^BOLD%^%^WHITE%^w%^MAGENTA%^a%^WHITE%^nd q%^RESET%^u%^BOLD%^%^WHITE%^iv"+
               "%^RESET%^e%^BOLD%^%^WHITE%^rs %^RESET%^%^RED%^as a b%^BOLD%^%^RED%^a"+
               "%^RESET%^%^RED%^ll of %^BOLD%^%^WHITE%^wh%^ORANGE%^i%^WHITE%^te%^RESET%^"+
               "%^RED%^-h%^BOLD%^%^RED%^o%^RESET%^%^RED%^t f%^BOLD%^%^RED%^i%^RESET%^"+
               "%^ORANGE%^r%^RED%^e er%^BOLD%^%^RED%^u%^RESET%^%^RED%^pts from the "+
               "%^BOLD%^%^WHITE%^tip %^RESET%^%^RED%^and %^BOLD%^%^RED%^engulfs%^RESET%^"+
               "%^RED%^ "+ETO->QO+".%^RESET%^");
            tell_object(target,"%^RESET%^%^RED%^"+ETOQCN+" points "+ETO->QP+" %^BOLD%^"+
               "%^WHITE%^w%^ORANGE%^a%^WHITE%^nd %^RESET%^%^RED%^at you and gr%^BOLD%^"+
               "%^RED%^o%^RESET%^%^RED%^wls, '%^BOLD%^%^RED%^Flamgra%^RESET%^%^RED%^.' "+
               "Before you can react, you are %^BOLD%^%^RED%^engulfed %^RESET%^%^RED%^by "+
               "a b%^BOLD%^%^RED%^a%^RESET%^%^RED%^ll of %^BOLD%^%^WHITE%^wh%^ORANGE%^i"+
               "%^WHITE%^te%^RESET%^%^RED%^-h%^BOLD%^%^RED%^o%^RESET%^%^RED%^t fl%^BOLD%^"+
               "%^RED%^a%^RESET%^%^ORANGE%^m%^RED%^e, your very bl%^BOLD%^%^RED%^oo"+
               "%^RESET%^%^RED%^d b%^BOLD%^%^RED%^o%^BLACK%^i%^RESET%^%^RED%^l%^BOLD%^"+
               "%^RED%^i%^RESET%^%^RED%^ng.%^RESET%^");
            tell_room(EETO,"%^RESET%^%^RED%^"+ETOQCN+" gr%^BOLD%^%^RED%^o%^RESET%^%^RED%^"+
               "wls the word '%^BOLD%^%^RED%^Flamgra%^RESET%^%^RED%^' and "+ETO->QP+" "+
               "%^BOLD%^%^WHITE%^w%^ORANGE%^a%^WHITE%^nd %^RESET%^%^RED%^releases a "+
               "%^BOLD%^%^WHITE%^wh%^ORANGE%^i%^WHITE%^te%^RESET%^%^RED%^-h%^BOLD%^%^RED%^"+
               "o%^RESET%^%^RED%^t b%^BOLD%^%^RED%^a%^RESET%^%^RED%^ll of fl%^BOLD%^"+
               "%^RED%^a%^RESET%^%^ORANGE%^m%^RED%^e that engulfs "+target->QCN+".%^RESET%^",({target,ETO}));
		return roll_dice(1,8)+4;
            break;
         default:
            tell_object(ETO,"%^BOLD%^%^BLACK%^Maneuvering your %^WHITE%^w%^ORANGE%^a"+
               "%^WHITE%^nd %^BLACK%^like a conductor, you shout '%^RESET%^%^MAGENTA%^Tlu "+
               "k'jakr%^BOLD%^%^BLACK%^!' causing the %^WHITE%^w%^CYAN%^e%^ORANGE%^a"+
               "%^WHITE%^p%^RESET%^%^MAGENTA%^o%^BOLD%^%^WHITE%^n %^BLACK%^to emit a "+
               "%^RESET%^%^RED%^p%^BOLD%^%^RED%^r%^RESET%^%^ORANGE%^i%^BOLD%^%^ORANGE%^s"+
               "%^RESET%^%^GREEN%^m%^BOLD%^%^GREEN%^a%^BLUE%^t%^BOLD%^%^MAGENTA%^i%^RESET%^"+
               "%^MAGENTA%^c %^BOLD%^%^BLACK%^blast of %^ORANGE%^l%^WHITE%^i%^RESET%^"+
               "%^ORANGE%^g%^BOLD%^%^ORANGE%^ht %^BLACK%^that sends "+target->QCN+" reeling.%^RESET%^");
            tell_object(target,"%^BOLD%^%^BLACK%^"+ETOQCN+" flicks her %^WHITE%^w%^CYAN%^a"+
               "%^WHITE%^nd %^BLACK%^and points it at you, shouting '%^RESET%^%^MAGENTA%^Tlu "+
               "k'jakr%^BOLD%^%^BLACK%^!' The resulting blast of %^RESET%^%^RED%^p%^BOLD%^"+
               "%^RED%^r%^RESET%^%^ORANGE%^i%^BOLD%^%^ORANGE%^s%^RESET%^%^GREEN%^m%^BOLD%^"+
               "%^GREEN%^a%^BLUE%^t%^BOLD%^%^MAGENTA%^i%^RESET%^%^MAGENTA%^c %^BOLD%^"+
               "%^ORANGE%^l%^WHITE%^i%^RESET%^%^ORANGE%^g%^BOLD%^%^ORANGE%^ht "+
               "%^BOLD%^%^BLACK%^leaves you totally disoriented!%^RESET%^");
            tell_room(EETO,"%^BOLD%^%^BLACK%^With a graceful flick of "+ETO->QP+" wand, "+
               ""+ETOQCN+" shouts, '%^RESET%^%^MAGENTA%^Tlu k'Jakr%^BOLD%^%^BLACK%^' "+
               "and blasts "+target->QCN+" with a %^RESET%^%^RED%^p%^BOLD%^%^RED%^r"+
               "%^RESET%^%^ORANGE%^i%^BOLD%^%^ORANGE%^s%^RESET%^%^GREEN%^m%^BOLD%^%^GREEN%^a"+
               "%^BLUE%^t%^BOLD%^%^MAGENTA%^i%^RESET%^%^MAGENTA%^c %^BOLD%^%^BLACK%^burst "+
               "of %^ORANGE%^l%^WHITE%^i%^RESET%^%^ORANGE%^g%^BOLD%^%^ORANGE%^ht "+
               "%^BOLD%^%^BLACK%^that sends "+target->QO+" reeling.%^RESET%^",({target,ETO}));
            target->set_paralyzed(10+random(11),"You are trying to get to your feet.");
            if(!random(3)){
               tell_object(target,"%^YELLOW%^The light sears your eyes, blinding you!%^RESET%^");
               target->set_blind(1);
            }
            break;   
      } 
   }
}

void init(){
   ::init();
   if(!TO->query_property("no repair")){
      TO->set_property("no repair",1);
	  TO->set_overallStatus(150);
   }
}

void heart_beat(){
   if(!objectp(TO)){ return; }
   if(!objectp(ETO)){ return; }
   if(!interactive(ETO)){ return; } 
   if(random(500) > 495){
      switch(random(3)){
         case 0: tell_object(ETO, "%^RESET%^%^CYAN%^Your %^WHITE%^i%^BOLD%^"+
                    "%^WHITE%^v%^ORANGE%^o%^WHITE%^r%^RESET%^y pl%^CYAN%^a"+
                    "%^WHITE%^t%^MAGENTA%^i%^BOLD%^%^WHITE%^n%^CYAN%^u%^WHITE%^m"+
                    "%^RESET%^-h%^BOLD%^%^MAGENTA%^a%^RESET%^ndl%^BOLD%^"+
                    "%^WHITE%^e%^RESET%^d %^BOLD%^%^WHITE%^w%^RESET%^%^MAGENTA%^a"+
                    "%^BOLD%^%^WHITE%^nd %^RESET%^%^CYAN%^h%^BOLD%^%^CYAN%^u"+
                    "%^RESET%^%^CYAN%^ms with ar%^BOLD%^%^CYAN%^c%^RESET%^"+
                    "%^CYAN%^ane e%^BOLD%^%^CYAN%^n%^RESET%^%^CYAN%^ergy.%^RESET%^");
                 tell_room(EETO,"%^RESET%^%^CYAN%^"+ETOQCN+"'s %^WHITE%^i%^BOLD%^"+
                    "%^WHITE%^v%^ORANGE%^o%^WHITE%^r%^RESET%^y pl%^CYAN%^a%^WHITE%^"+
                    "t%^MAGENTA%^i%^BOLD%^%^WHITE%^n%^CYAN%^u%^WHITE%^m%^RESET%^-h"+
                    "%^BOLD%^%^MAGENTA%^a%^RESET%^ndl%^BOLD%^%^WHITE%^e%^RESET%^d "+
                    "%^BOLD%^%^WHITE%^w%^RESET%^%^MAGENTA%^a%^BOLD%^%^WHITE%^nd "+
                    "%^RESET%^%^CYAN%^h%^BOLD%^%^CYAN%^u%^RESET%^%^CYAN%^ms with "+
                    "ar%^BOLD%^%^CYAN%^c%^RESET%^%^CYAN%^ane e%^BOLD%^%^CYAN%^n"+
                    "%^RESET%^%^CYAN%^ergy.%^RESET%^",({ETO}));
                 break;
         case 1: tell_object(ETO,"%^RESET%^The %^MAGENTA%^ameth%^BOLD%^%^MAGENTA%^y"+
                    "%^RESET%^%^MAGENTA%^sts %^WHITE%^emb%^MAGENTA%^e%^WHITE%^dd"+
                    "%^BOLD%^%^MAGENTA%^e%^RESET%^%^WHITE%^d in the hilt of your "+
                    "%^BOLD%^%^WHITE%^w%^ORANGE%^a%^WHITE%^nd %^RESET%^%^MAGENTA%^gl"+
                    "%^BOLD%^%^MAGENTA%^o%^RESET%^%^MAGENTA%^w f%^BOLD%^%^MAGENTA%^a"+
                    "%^RESET%^i%^MAGENTA%^ntly.%^RESET%^");
                 tell_room(EETO,"%^RESET%^The %^MAGENTA%^ameth%^BOLD%^%^MAGENTA%^y"+
                    "%^RESET%^%^MAGENTA%^sts %^WHITE%^emb%^MAGENTA%^e%^WHITE%^dd"+
                    "%^BOLD%^%^MAGENTA%^e%^RESET%^%^WHITE%^d in the hilt of "+ETOQCN+"'s "+
                    "%^BOLD%^%^WHITE%^w%^ORANGE%^a%^WHITE%^nd %^RESET%^%^MAGENTA%^gl"+
                    "%^BOLD%^%^MAGENTA%^o%^RESET%^%^MAGENTA%^w f%^BOLD%^%^MAGENTA%^a"+
                    "%^RESET%^i%^MAGENTA%^ntly.%^RESET%^",({ETO}));
                 break;
         default: tell_object(ETO,"%^BOLD%^%^CYAN%^C%^WHITE%^r%^CYAN%^a%^WHITE%^c"+
                    "%^CYAN%^kl%^RESET%^%^CYAN%^i%^BOLD%^%^CYAN%^ng b%^ORANGE%^o%^CYAN%^"+
                    "lts %^BLACK%^of %^RESET%^%^CYAN%^ar%^BOLD%^%^CYAN%^c%^RESET%^"+
                    "%^CYAN%^ane e%^BOLD%^%^CYAN%^n%^RESET%^%^CYAN%^ergy %^BOLD%^"+
                    "%^ORANGE%^arc %^BLACK%^acr%^CYAN%^o%^BLACK%^ss the %^RESET%^h"+
                    "%^MAGENTA%^a%^WHITE%^ndle %^BOLD%^%^WHITE%^%^BLACK%^of your "+
                    "%^WHITE%^b%^CYAN%^e%^ORANGE%^a%^WHITE%^ut%^MAGENTA%^i%^WHITE%^f"+
                    "%^RESET%^u%^BOLD%^%^WHITE%^l w%^RESET%^%^MAGENTA%^a%^BOLD%^"+
                    "%^WHITE%^nd%^BLACK%^.");
                  tell_room(EETO,"%^BOLD%^%^CYAN%^C%^WHITE%^r%^CYAN%^a%^WHITE%^c"+
                    "%^CYAN%^kl%^RESET%^%^CYAN%^i%^BOLD%^%^CYAN%^ng b%^ORANGE%^o%^CYAN%^"+
                    "lts %^BLACK%^of %^RESET%^%^CYAN%^ar%^BOLD%^%^CYAN%^c%^RESET%^"+
                    "%^CYAN%^ane e%^BOLD%^%^CYAN%^n%^RESET%^%^CYAN%^ergy %^BOLD%^"+
                    "%^ORANGE%^arc %^BLACK%^acr%^CYAN%^o%^BLACK%^ss the %^RESET%^h"+
                    "%^MAGENTA%^a%^WHITE%^ndle %^BOLD%^%^WHITE%^%^BLACK%^of "+ETOQCN+"'s "+
                    "%^WHITE%^b%^CYAN%^e%^ORANGE%^a%^WHITE%^ut%^MAGENTA%^i%^WHITE%^f"+
                    "%^RESET%^u%^BOLD%^%^WHITE%^l w%^RESET%^%^MAGENTA%^a%^BOLD%^"+
                    "%^WHITE%^nd%^BLACK%^.",({ETO}));
                  break;
		}
	}
}