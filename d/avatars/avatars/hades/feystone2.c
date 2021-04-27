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
"In this vision you are an aging Elven Lord.",
"You look out over your land and survey the destruction wrought by the hoards.",
"Huge forest fires bellow black smoke off in the distance.",
"What once was fighting in the streets of the city has turned to desperate skirmishes.",
"Desperate elves fire from battlements or housetops at groups of orcs who have them surrounded. ", 
"A group of ogres are carrying a felled tree trunk with ropes on it to use as a battering ram directly below you.  ",
"All that was left is to die with dignity.",
"An old elf enters the empty throne chamber, 'Lord Serron, High Mage Haesirretyn is here to see you.'",
"You raise an eyebrow and turn around.",
"There stands the cocky looking elf in his normal overly flamboyant gold and red robes. ",
"He smiles sweetly and said, 'It looks like I've arrived just at the right time.  I need a group of your best elves.  We will seal the mythal in the earth so these barbarians cannot destroy it.'",
"You huff, 'There is no one left, the only ones left are women, children and the elderly holed up in here.  Everyone else is out there fighting for their lives.'",
"He shrugs, 'Those will do, arm them and we will head to the mythal chamber.'",
"You protest, 'They will be cut down in minutes.  Do you not care about the helpless?'",
"The mage continues unphased. 'That will do, let us begin it will not take long to sink and seal the chamber.  After that our plans for this place will be complete.'",
"Complete.",
"You gawk at the idea.",
"The Haesirretyn mean to sacrifice everyone.",
"You can tell by the annoyed look on the high mages face that this was not up for discussion.  ",
"You look to the old steward who is gaping at the idea and say, 'Gather everyone tell them to find anything that they could use as a weapon or armor.'",
"The cocky mage smiles wicketly, 'I will open a portal to the temple on the hill.  We will secure it.  This will be the last task house Haesirretyn will require of you Serron.  Thank you for your service.'",
"He bows.",
"You can tell he is mocking you.",
"You glance to the old elf and he glances between the two of you and hurries out of the throne room.  ",
"This will be a slaughter..."
"'What of my daughter?'You ask."
"'The child?,' He pauses, as if somewhat taken off guard by the question.  'She is doing well.  Her training is going better than expected.'",});
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
