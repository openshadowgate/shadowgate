#include <std.h>
#include <daemons.h>
inherit "/d/common/obj/weapon/hammer_lg.c";

#define AIDTIME 1500
#define DISPELTIME 1200
#define SUMMONTIME 2400

int aid_time;
int dispel_time;
int summon_time;

void init() {
    ::init();
    add_action("heal_em","aid");
    add_action("dispel_em","disrupt");
    add_action("summon_em","call");
}

void create() {
    ::create();
    set_name("hammer");
    set_id(({"redemption","hammer","large hammer","two handed hammer","mithril hammer"}));
    set_obvious_short("%^BOLD%^%^BLACK%^a %^BOLD%^%^CYAN%^rune-engraved %^BOLD%^%^WHITE%^mithril %^BOLD%^%^YELLOW%^large hammer%^RESET%^");
    set_short("%^YELLOW%^Red%^WHITE%^e%^YELLOW%^mption%^RESET%^");
    set_long("%^RESET%^This beautifully %^BOLD%^%^CYAN%^rune-engraved %^RESET%^hammer is finely crafted, with a holy of symbol of %^BOLD%^%^YELLOW%^Lathander%^RESET%^ etched in the side of "
"the hammer head. One side of the head protrudes %^BOLD%^%^RED%^viciously %^RESET%^with a spike and the other is the flat surface of the hammer. The face of the flat hammer has an etching on "
"it, depicting a man alone, surrounded by %^BOLD%^%^BLACK%^darkness %^RESET%^with a thin line of %^BOLD%^%^YELLOW%^light %^RESET%^creating a path ahead. The entire hammer is %^BOLD%^%^WHITE%^"
"polished mithril %^RESET%^and has engravings along the entire length of the grip in the languages %^BOLD%^%^GREEN%^elven, %^BOLD%^%^BLUE%^common%^RESET%^, and %^BOLD%^%^BLACK%^drow%^RESET%^ "
"with the inscription 'There is no forgiveness for the wicked save that of His grace.'%^RESET%^"); 
    set_lore("This hammer was created by the famous paladin, %^BOLD%^%^WHITE%^Sir Saradin Torvall%^RESET%^, soon after gaining the status of paladinship from the church of %^BOLD%^%^YELLOW%^"
"Lathander%^RESET%^. Sir Saradin, after living the life of nearly forty years as a %^BOLD%^%^RED%^villainous assassin-warlord%^RESET%^ who killed thousands of innocents, gave up the life "
"and all his wealth in search of redemption. After forty years of faithful service to %^BOLD%^%^YELLOW%^Lathander%^RESET%^, he was granted knighthood by the %^BOLD%^%^WHITE%^King of Antioch "
"%^RESET%^for honorable service to the crown. Soon after, after having proven his faith to his god, Saradin Torvall became a full fledged paladin, seeking to aid others in changing from the "
"%^BOLD%^%^BLACK%^darkness of the world %^RESET%^and back to the %^BOLD%^%^YELLOW%^light%^RESET%^.");
    set_read(
@CIRCE
    %^BOLD%^%^WHITE%^The faithful heart may ask for %^CYAN%^aid
    %^WHITE%^When hope and health begin to fade
  The zealous spirit can seek to %^RED%^disrupt
 %^WHITE%^The magic of one whose heart is corrupt
  The weary warrior may send forth a %^YELLOW%^call
     %^WHITE%^To summon a mount, proud and tall
CIRCE
    );
    set_value(10000);
    if((int)TO->query_property("enchantment") < 5){
       remove_property("enchantment");
       set_property("enchantment",5);
    }
    set_wield((:TO,"paladin":));
    set_unwield((:TO,"removeme":));
    set_hit((:TO,"extra_hit":));
    set_heart_beat(1);
}

int paladin() {
    if((string)ETO->query_name() != "saradin") {
	tell_object(ETO,"You may not wield this weapon!");
	return 0;
    }
    tell_object(ETO,"%^YELLOW%^You feel the grace of Lathander come over you as you wield the massive hammer.%^RESET%^");
    tell_room(EETO, "%^RESET%^"+ETO->QCN+"'s eyes flare with %^YELLOW%^holy light %^RESET%^briefly as "+ETO->QS+" wields the massive hammer.%^RESET%^",ETO);
    ETO->add_sight_bonus(2);
    ETO->set_property("good item",1);
    return 1;
}  

int removeme() {
    tell_object(ETO,"%^YELLOW%^You hesitate in unwielding the weapon as the faded presence leaves you less confident.%^RESET%^");
    tell_room(EETO, "%^YELLOW%^Grudgingly, "+ETO->QCN+" unwields the massive hammer.%^RESET%^",ETO);
    ETO->add_sight_bonus(-2);
    ETO->set_property("good item",-1);
    return 1;
}

void failure(){
   tell_object(ETO,"The hammer must regain its power before it can attempt that again.");
   return 1;
}

int extra_hit() {
    object ob;
    int dam,FLAG,align;
    FLAG = 0;
    ob=ETO->query_current_attacker();
    align = ob->query_alignment();
    if(!objectp(ob)) return random(5);
    if(random(6) > 3) return 1;
    if(random(100)>40){
        if(align == 9 || align == 6 || align == 3) {
            FLAG = 1;
            dam = dam + random(5) + 1;
        } else {
	    dam = dam + random(2) - random(2);
        }
    }
    if(random(100) > 50) {
        dam = dam + random(6) + 2;
    } else {
        dam = dam + random(3) + 1;
    }
    switch(random(30)){
      case 0..19:
       tell_object(ETO,"%^BOLD%^%^WHITE%^The hammer channels your "+
          "%^MAGENTA%^holy energy%^WHITE%^ into its swing!\n"+
          "%^BOLD%^%^CYAN%^A bright %^RED%^flash%^CYAN%^ is seen "+
          "as you strike at "+ob->QCN+"!%^RESET%^");    
          if(FLAG == 1){
             tell_object(ETO,"\n%^BOLD%^%^RED%^The Avenger tells "+
                "you: I detect great evil in our foe!%^RESET%^\n%^RED%^"+
   	          ""+ob->QCN+" screams as the avenger sinks into "
	          ""+ob->QP+" evil flesh!%^RESET%^");
             FLAG = 0;
          }
       tell_room(EETO,"%^BOLD%^%^WHITE%^The hammer wielded by "+
          ""+ETOQCN+" %^MAGENTA%^sings %^WHITE%^out to the "+
          "heavens!\n%^BOLD%^%^CYAN%^A bright %^RED%^flash%^CYAN%^ "+
          "is seen as "+ETOQCN+" strikes at "+ob->QCN+"!%^RESET%^",({ETO,ob}));
       tell_object(ob,"%^BOLD%^%^WHITE%^The hammer wielded by "+
          ""+ETOQCN+" %^MAGENTA%^sings %^WHITE%^out to the "+
          "heavens!\n%^BOLD%^%^CYAN%^A bright %^RED%^flash"+
          "%^CYAN%^ is seen as "+ETOQCN+" strikes at you!%^RESET%^");
       break;
      case 20..28:
       tell_object(ETO,"%^YELLOW%^Your hammer radiates a divine "+
          "light, and you feel the benevolent gaze of "+
          ""+capitalize(ETO->query_diety())+" upon you as you "+
          "hit "+ob->QCN+"!\n%^RED%^A voice utters%^RESET%^: "+
          "Be well, my warrior.\n%^BOLD%^%^CYAN%^You feel "+
          "some of your weariness drain away!");
       tell_object(ob,"%^YELLOW%^"+ETOQCN+"'s hammer radiates a brilliant "+
          "light as it hits you!");
       tell_room(EETO,"%^YELLOW%^"+ETOQCN+"'s face beams as "+
          ""+ETO->QP+" hammer hits "+ob->QCN+" with a "+
          "brilliant flash!",({ob,ETO}));
       ETO->do_damage("torso",-dam);
       break;
      case 29:
       tell_object(ETO,"%^BOLD%^The hammer begins to vibrate in your "+
          "hands, then sends forth a %^YELLOW%^blinding beam of light "+
          "%^WHITE%^at "+ob->QCN+"!");
       tell_object(ob,"%^BOLD%^"+ETOQCN+" points the hammer at you, and "+
          "a %^YELLOW%^blinding beam of light %^WHITE%^sprays forth, "+
          "blinding you!");
       tell_room(EETO,"%^BOLD%^"+ETOQCN+" points the hammer at "+
          ""+ob->QCN+", causing a %^YELLOW%^beam of light %^WHITE%^"+
          "to shoot forth!",({ETO,ob}));
       if(random(22) > (int)ob->query_stats("constitution")){
          ob->set_blind(1);
       }
       break;
      default:  break;
   }
   return dam;
}

void heart_beat(){
object *live;
object targ;
int align, i, counter;
   if(!objectp(TO)) return;
   if(!objectp(ETO)) return;
   if(!living(ETO)) return;
   if(!objectp(EETO)) return;
   live = all_living(EETO);
   live = filter_array(live, "is_non_immortal_player", FILTERS_D);
   if(TO->query_wielded()){
     if(!random(20)){
      for(i=0;i<sizeof(live);i++){
         targ = live[i];
         if(!objectp(targ)) continue;
         align = targ->query_alignment();
         if((align == 3) || (align == 6) || (align == 9)){
            tell_object(ETO,"%^CYAN%^Your hammer glows blue as "+
               "it senses the presence of an evil intent.");
            tell_room(EETO,"%^CYAN%^The hammer held by "+ETOQCN+" "+
               "glows blue.",ETO);
            continue;            
         }
       }
      }
   }
}

int heal_em(string str){
object ob;
   if (ETO->query_bound() || ETO->query_unconscious() || ETO->query_paralyzed()) {
        ETO->send_paralyzed_message("info",ETO);
    }
   if(!str){
      tell_object(ETO,"You may ask your deity for aid through your "+
         "sword - <aid me>");
      return 1;
   }
   if(!TO->query_wielded()){
      tell_object(ETO,"You must be wielding the hammer to call on its power.");
      return 1;
   }
   if(AIDTIME > (time() - aid_time)) {
      failure();
      return 1;
   }
   if(str == "me"){
      aid_time = time();
      tell_object(ETO,"%^BOLD%^%^CYAN%^Your hammer glows with a soft "+
         "light and you feel your wounds heal.");
      tell_room(EETO,"%^BOLD%^%^CYAN%^"+ETOQCN+"'s hammer glows softly.",ETO);
      ETO->set_hp(ETO->query_max_hp());
      ETO->heal(1);
      return 1;
   }
   tell_object(ETO,"You may only ask the hammer to <aid me>.");
   return 1;
}

int dispel_em(string str){
object ob;
   if (ETO->query_bound() || ETO->query_unconscious() 
    || ETO->query_paralyzed()) {
        ETO->send_paralyzed_message("info",ETO);
    }
   if(!str){
      tell_object(ETO,"You may ask your hammer to <disrupt target>.");
      return 1;
   }
   if(!TO->query_wielded()){
      tell_object(ETO,"You must be wielding the hammer to call on its power.");
      return 1;
   }
   if(!(ob = present(str, ETP))) return notify_fail("You do not see that!\n");
   if(DISPELTIME > (time() - dispel_time)) {
      failure();
      return 1;
   }
   dispel_time = time();
   tell_room(EETO,"%^BOLD%^%^WHITE%^"+ETOQCN+" turns to face "+
      ""+ob->QCN+" and closes "+ETO->QP+" "+
      "eyes while uttering a fervent prayer!",ETO);
   tell_object(ETO,"%^BOLD%^%^WHITE%^You face "+ob->QCN+" and close "+
      "your eyes, uttering a fervent prayer to "+
      ""+capitalize(ETO->query_diety())+"!");
   new("/cmds/spells/d/_dispel_magic")->use_spell(TP,ob,45,100,"cleric");
   TP->set_paralyzed(3,"You are channelling your deity through the hammer!");
   return 1;
}

int summon_em(string str){
   string god = ETO->query_diety();
   object ob;
   if (ETO->query_bound() || ETO->query_unconscious() 
    || ETO->query_paralyzed()) {
        ETO->send_paralyzed_message("info",ETO);
    }
   if(!str){
      tell_object(ETO,"You may ask your deity for aid in the form of "+
         "a mount - <call mount>");
      return 1;
   }
   if(!TO->query_wielded()){
      tell_object(ETO,"You must be wielding the hammer to call on its power.");
      return 1;
   }
   if(str == "mount"){
      if(SUMMONTIME > (time() - summon_time)) {
         failure();
         return 1;
      }
      summon_time = time();
      tell_object(ETO,"%^CYAN%^You set the head of your hammer upon "+
         "the ground and spread your arms wide, calling for aid.");
      tell_room(EETO,"%^CYAN%^"+ETOQCN+" sets the head of "+ETO->QP+" hammer "+
         "upon the ground and spreads "+ETO->QP+" arms wide.",ETO);
      tell_room(EETO,"%^BOLD%^%^CYAN%^A mighty beast appears before you, answering the call!");
      ob = new("/d/common/mounts/gpegasus");
      if(ob) {
        ob->set_owner(TP);
        ob->move(EETO);
      }
      return 1;
   }
   tell_object(ETO,"You may only ask the hammer to <call mount>.");
   return 1;
}