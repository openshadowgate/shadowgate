#include <std.h>
inherit OBJECT;

void create() {
  ::create();
  set_id( ({"crystal","crystal of rememberance","quartz crystal"}));
  set_name("crystal of remembrance");
  set_short("%^RESET%^%^CYAN%^A tarnished quartz crystal%^RESET%^");
  set_weight(1);
  set_value(0);
  set_long("%^CYAN%^This is a very small crystal made "+
  "from quartz.  It has some etching that"+
  " cover it and seem to form runes.  Perhaps"+
  " one could %^GREEN%^_touch_%^CYAN%^ it.%^RESET%^");
  set_lore("This looks to be an elven memory stone. "+
  " It seems old, even by elven standards.  It"+
  " likely dates back to the era of the crown wars.");
  set_property("lore difficulty",35);
}
void init(){
  ::init();
  add_action("touch_fun","touch");
  return;
}

void play_scene(int cnt){
string *msg;

msg = ({"Your vision blurs and you enter a dream-like trance.",
"In this vision you are an aging Elven Lord.  ",
"'Ingwe Serron,' a herald addressees you as you sit upon your throne.",
"You regard him warily.  ",
"Heasirretyn tends to have many demands.  Being a branch family during the war has turned into more of a curse than a blessing.",
"When you asked the head family for support they sent the family's high mage.",
"He came and performed the magic to altar the Mythal to allow for a prolonged infernal summoning.  ",
"'You must send your daughter back with us.  The enemy is at the gates and she will not be safe in this place for much longer.'",
"You scowl at the Heasirretyn.  ",
"You expected him to send troops, weapons, magic.  Not make more demands.",
"'Fine,' you say between clenched teeth.  You were loathe to part with your last remaining child even though any who saw her would consider her an abomination.  ",
"'Also, other houses have sensed the high magic performed her.  They will ask questions tell them that the high mage of Heasirretyn came to strengthen the defenses of the Mythal.  ",
"And with that, he took his leave.",
"You had mixed feelings about this, your land was in ruins from orc hoards.  Your only remaining heir was about to take a carriage to safety.  ",
"She had but ten years in this life.  Most of that spent isolated in a tower or under enchantment from his court mage to hide her infernal half.  ",
"If she was the key to winning this war you did not see it.",});
 write("%^GREEN%^"+msg[cnt]);
 if (cnt == sizeof(msg)-1) return;
 call_out("play_scene",4,cnt+1); 
 return;
}
void touch_fun(string str){
   if ( !str || str !="crystal of rememberance" && str !="crystal" && str !="quartz crystal") {
      notify_fail ("Touch what?\n");
      return 0;
   }
   else 
      if (find_call_out("play_scene") != -1) {
          notify_fail("The stone is in use.");
          return 0;
          }
   play_scene(0);
   tell_room(ETO,""+TPQCN+" touches the stone.",TP);
   write("You touch the stone");
   TP->set_disable(40);
   return 1;
}
