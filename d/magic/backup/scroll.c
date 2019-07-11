//      A Magic Scroll
//      Thorn@Shadowgate
//      12/1/94
//      General Wizard Class Items
//      scroll.c
//
//      Modified 8/2/97 by Vetri
//      Sets spellname randomly from among all up to
//        certain level spells


#include <std.h>
#include <spellsbylevel.h>
inherit OBJECT;

string spell;
int usable;

void set_spell_name(string str);
void set_desc();
void set_spell(int level);

void create(){
  ::create();
  set_name("scroll");
  set_id(({"scrollx", "scroll"}));
  set_short("a scroll");
  set_spell(1);
  set_weight(5);
  set_value(10);
  if(!random(4)) usable = 1;
}

void init(){
  ::init();
  set_desc();
  if(environment(TO)==TP && interactive(TP)){
    if(wizardp(TP)) add_action("set_scroll", "set");
    add_action("transcribe", "transcribe");
    add_action("use_scroll", "use");
  }
}

void set_spell(int level){
  int i,j,num;
  string *whichspells,str;

  if(!level) level = 1;
  whichspells == ({});
  for(i=1;i<=level;i++){
    switch(i){
      case 1: 
        for(j=1;j<10;j++)
          whichspells = whichspells + LEVEL_1;
        break;
      case 2:
        for(j=1;j<9;j++)
          whichspells = whichspells + LEVEL_2;
        break;
      case 3:
        for(j=1;j<8;j++)
          whichspells = whichspells + LEVEL_3;
        break;
      case 4:
        for(j=1;j<7;j++)
          whichspells = whichspells + LEVEL_4;
        break;
      case 5:
        for(j=1;j<6;j++)
           whichspells = whichspells + LEVEL_5;
       break;
      case 6:
        for(j=1;j<5;j++)
          whichspells = whichspells + LEVEL_6;
        break;
      case 7:
        for(j=1;j<4;j++)
          whichspells = whichspells + LEVEL_7;
        break;
      case 8:
        for(j=1;j<3;j++)
          whichspells = whichspells + LEVEL_8;
        break;
      case 9:
          whichspells = whichspells + LEVEL_9;
        break;
    }     
  }
  num = random(sizeof(whichspells));
  str = whichspells[num];
  set_spell_name(str);
}

void set_scroll(string str){
  string scroll_id, scroll_spell;
  if(sscanf(str,"%s to %s",scroll_id,scroll_spell) != 2)
    return 0;
  if(present(scroll_id,TP)!=TO)
    return 0;
  set_spell_name(scroll_spell);
  write("Scroll altered.");
}

void set_spell_name(string str){
  spell = str;
  set_long("This is a magic scroll of "+spell+".  You can <transcribe> it into your spell book.");
  return 1;
}

void set_desc(){
  if (interactive(environment(TO)) 
      && ((string)environment(TO)->is_class("mage")
      || (int)environment(TO)->query_guild_level("mage") > 0 
      || (int)environment(TO)->query_guild_level("thief") > 0 
      || (int)environment(TO)->query_guild_level("bard") > 1 
      || wizardp(environment(TO))) 
      && (usable || (TP->is_class("mage") || TP->is_class("bard"))))
    set_long("This is a magic scroll of "+spell+".  You can <transcribe scroll> to write it into your spellbook.");
  else
    set_long("This is a scroll with some undecipherable writing on it.");
   return 1;
}

string query_spell_name() { return spell; }

int transcribe(string str){
  object book;
  int prev;
  int after;
  string class;

  if(present(str,TP) != TO) return 0;
  if(!(TP->is_class("mage") || wizardp(TP) || TP->is_class("bard")))
    return notify_fail("You don't know how to copy magical spells.");
  book = present("bookx",TP);
  if(!book){
    notify_fail("You don't have a spell book to transcribe the spell into!");
    return 0;
  }
  write("%^ORANGE%^You carefully transcribe "+spell+" into your spellbook.\n");
  book->set_spellbook(spell);
  write("You finish the transcription and the scroll suddenly disappears in a wisp of smoke!\n");
  TO->remove();
  return 1;
}

int use_scroll(string str){
  int lev, back,num;
  string caster, targ, what,what2;
  object ob;

  caster = TP->query_name();
  if(!str)
    return notify_fail("Use what?\n");
  if(!(sscanf(str,"%s on %s",what,targ)==2))
    if(!(sscanf(str,"%s at %s",what,targ)==2))
      if(!(sscanf(str,"%s to %s",what,targ)==2)){
        what = str;
        
       }
  /*
  if(sscanf(what,"%s %d",what,num) != 2){
	write("what2 ="+what+" what = "+what+"num = "+num);
  	if(!id(what))
    	return 0;
  }else{
  write("what2 ="+what+" what = "+what+" num ="+num+"stufffff");
  	
  	if(!id(what+" "+num))
  		return 0;
  }
  */
  
  if(!present(what,TP) || present(what,TP) != TO) return 0;
  if(!TP->is_class("thief") && !TP->is_class("bard") && !TP->is_class("mage"))
    return 0;
  if(!usable && !(TP->is_class("mage") || TP->is_class("bard")))
    return notify_fail("You can't figure out how to use this scroll.");
  lev = random(50);
  back = random(100);
  if(back < 10)
    targ = caster;
  ob = new("/cmds/wizard/_"+replace_string(spell," ","_"));
  if(ob->query_target_required() && !targ)
    return notify_fail("You need to specify a target to use that spell!\n");
  ob->use_spell(TP, targ, lev);
  call_out("remove",1);
  return 1;
}
