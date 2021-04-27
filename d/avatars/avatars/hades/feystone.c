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

msg = ({"Your vision blurs and you enter a dream-like trance."
"In this vision you take the role of a gold elven nurse in a castle.",
"'The lord's words are absolute', you say to yourself.",
"You have these terrible doubts that he has crossed the line though.",
"He has made terrible sacrifices.",
"Half of his family had died fighting the war at the frontier. ",
"Gruumsh's children would not be culled.  The attacks just kept coming.  ",
"When his wife perished on the battlefield my lord said he would do whatever it took to secure our lands.",
"You look down at the babe in your hands and try not to be disgusted by her scaly red skin and snake-like eyes.  ",
"My lord you claimed the succubus was completely enthralled this heir a combination of infernal blood and elven blood would never fall.",
"'Itarille, when you come to years please be not the monster I fear.'",
"You then proceed to nurse the babe and remember that your lord's words are absolute.",
"Fear fills your thoughts.",});
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
