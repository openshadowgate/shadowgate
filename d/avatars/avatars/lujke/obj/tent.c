//Coded by Lujke
#define LONG_UP "%^BOLD%^%^WHITE%^Before you stands a %^MAGENTA%^c%^RED%^a%^YELLOW%^r%^WHITE%^ni"\
                 +"%^YELLOW%^v%^RED%^a%^MAGENTA%^l %^WHITE%^sized tent positioned longways. The"\
                 +" entrance to the tent consists of flaps that have been neatly rolled up and tied"\
                 +" off to the left and right of the main opening. Above the tent's entrance is a"\
                 +" large sign made on a piece of slightly curved %^RESET%^%^ORANGE%^wood"\
                 +" %^BOLD%^%^WHITE%^in big bold common letters that say %^MAGENTA%^'Help the"\
                 +" Hopeless'%^WHITE%^. The tent itself spans several yards across with a main center"\
                 +" pole supporting it's center. The walls of the tent are made of a thick canvas"\
                 +" that has been %^RESET%^white washed %^BOLD%^%^WHITE%^through and through so as"\
                 +" to make it easy to see, even with the dimest %^BLACK%^s%^WHITE%^t%^RESET%^a"\
                 +"%^BOLD%^%^WHITE%^r%^BLACK%^li%^WHITE%^g%^BLACK%^ht %^WHITE%^at night.%^RESET%^"\
                 +" You could <disassemble tent> if it is empty."

#define LONG_DOWN "%^RESET%^%^ORANGE%^This is a large %^BOLD%^%^BLACK%^duffle bag %^RESET%^%^ORANGE%^"\
                +"%^filled with neatly rolled %^BOLD%^%^WHITE%^canvas %^RESET%^%^ORANGE%^and many"\
                +" sectional poles. On the side of the bag are a series of %^BOLD%^%^BLACK%^stakes"\
                +" %^RESET%^%^ORANGE%^and lengths of coiled %^WHITE%^%^BOLD%^rope%^RESET%^%^ORANGE%^."\
                +"%^RESET%^ You could use it to <assemble tent>"
#define SHORT_UP "A tent"
#define SHORT_DOWN "a duffle bag"

#include <std.h>
inherit OBJECT;

int erect;
object setter;

void create() {
    ::create();
    erect = 0;
    set_name("tent");
    set_id( ({"bag","duffle bag", "tent" }) );
    set_short( (: TO, "short_desc" :) );
    set_weight(8);
    set_long( (:TO, "long_desc":) );
}

void init(){
  ::init();
  set_short( (: TO, "short_desc" :) );
  set_long( (:TO, "long_desc":) );
  add_action("erect_me", "erect");
  add_action("erect_me", "set");
  add_action("erect_me", "assemble");
  add_action("erect_me", "build");
  add_action("erect_me", "raise");
  add_action("erect_me", "build");
  add_action("disassemble_me", "disassemble");
  add_action("disassemble_me", "lower");
  add_action("disassemble_me", "dismantle");
  add_action("disassemble_me", "take");
  add_action("interrupt_me", "interrupt");
}

string long_desc(){
  switch(erect){
  case 0:
    return LONG_DOWN;
    break;
  case 1:  
    return LONG_UP;
    break;
  }
}

string short_desc(){
  switch(erect){
  case 0:
    return SHORT_DOWN; 
    break;
  case 1:  
    return SHORT_UP;
    break;
  }
}

int interrupt_me(string str){
  object room;
  if (!objectp(setter)){
    tell_object(TP, "No one is erecting or dismantling the tent at the moment. Perhaps you were too"
                   +" slow?");
    return 1;
  }
  tell_object(setter, TPQCN + " interrupts what you were doing with the tent");
  tell_object(TP, "You interrupt " + (string)setter->QCN + " from what they were doing with the tent");
  room = ETO;
  if (!objectp(room)){
    return 1;
  }
  if (interactive(room)){
    room = EETO;
  }
  if (!objectp(room)){
    return 1;
  }
  tell_room(room, TPQCN + " interrupts what " + (string)setter->QCN + " was doing with the tent", 
                                       TP, setter);
  setter = 0;
  return 1;
}


int erect_me(string str){
  object room;
  string verb, arg, what;
  verb = query_verb();
  switch(verb){
  case "set":
    if (sscanf (str, "%s %s", arg, what)<2){
      notify_fail("Try 'set up tent'");
      return 0;
    }
  default:
    what = str;    
  }
  if (!id(what)){
    notify_fail("Try 'set up tent'");
    return 0; 
  }
  room = ETO;
  if (interactive(room)){
    room =  EETO;
  }
  if ((string)room->query_exit("tent") != "/d/shadowgate/void"){
    tell_object(TP, "Sorry, you can't do that here. There is already a tent in the vicinity");
    return 1;
  }
  if (erect == 1){
    tell_object(TP, "The tent is already set up. You can <dismantle> it if you wish.");
    return 1;
  }
  if (objectp(setter) && present(setter, room)){
    tell_object(TP, (string)setter->QCN +" is already assembling the tent. You can <interrupt> them if"
                   +" you want ");
    return 1;
  }
  if (TP->query_property("busy")){
    tell_object(TP, "You are already doing something else");
    return 1;
  }
  setter = TP;
  tell_object(TP, "You begin setting up the tent");
  tell_room(room, TPQCN + "%^RESET%^ begins setting up a tent", TP);
  TP->set_property("busy", 1); 
  call_out("erect2",5, TP, room);
  return 1;
}

void erect2(object ob, object room){
  object interior;
  string roomname;
  if (!objectp(ob) ||!objectp(room)){
    return;
  }
  if (!present(ob, room)){
    tell_object(ob, "You've moved out of the room, so you stop setting up the tent");
    ob->remove_property("busy");
    return;
  }
  if (setter != ob){
    tell_object(ob, "You were interrupted before finishing setting up the tent");
    ob->remove_property("busy");
    return;
  }
  interior = find_object_or_load("/d/avatars/lujke/rooms/tent_interior");
  if (!objectp(interior)){
    tell_object(ob, "Sorry, something's gone wrong with the interior of the tent. Please make a bug"
                   +" report. Or tell Lujke he's a silly Draconian, or something");
    ob->remove_property("busy");
    setter = 0;
    return;
  }
  tell_object(ob, "You finish setting up the tent");
  tell_room(room, (string)ob->QCN + " finishes setting up the tent", ob);
  erect = 1;
  room->add_exit("/d/avatars/lujke/rooms/tent_interior", "tent");
  roomname = file_name(room);
  TO->move(room);
  ob->remove_property("busy");
  interior->add_exit( roomname,  "out" ); 
  setter = 0;
  set_weight(1000);
    set_id( ({"tent" }) );
}


int disassemble_me(string str){
  object room, * stuff, interior;
  string verb, what;
  verb = query_verb();
  switch(verb){
  case "set":
    if (sscanf (str, "down %s", what)<1){
      notify_fail("Try 'take down tent'");
      return 0;
    }
  default:
    what = str;    
  }
  room = ETO;
  if (erect == 0){
    tell_object(TP, "The tent is not set up. You can <set up tent> it if you wish.");
    return 1;
  }
  if (objectp(setter) && present(setter, room)){
    tell_object(TP, (string)setter->QCN+" is already dismantling the tent. You can <interrupt> them if"
                   +" you want ");
    return 1;
  }
  if (TP->query_property("busy")){
    tell_object(TP, "You are already doing something else");
    return 1;
  }
  interior = find_object_or_load("/d/avatars/lujke/rooms/tent_interior");
  if (!objectp(interior)){
    tell_room(room, "haha! Lujke made an error!");
    return 1;
  }
  stuff = all_inventory(interior);
  if (sizeof(stuff)>0){
    tell_object(TP, "You can't dismantle the tent just now. It's not empty");
    return 1;
  }
  setter = TP;
  tell_object(TP, "You begin dismantling the tent");
  tell_room(room, TPQCN + "%^RESET%^ begins dismantling the tent", TP);
  call_out("dismantle2",5, TP, room);
  TP->set_property("busy", 1);
  return 1;
}

void dismantle2(object ob, object room){
  object interior, * stuff;
  string roomname;
  if (!objectp(ob) ||!objectp(room)){
    return;
  }
  if (!present(ob, room)){
    tell_object(ob, "You've moved out of the room, so you stop dismantling the tent");
    ob->remove_property("busy");
    return;
  }
  if (setter != ob){
    tell_object(ob, "You were interrupted before you could finish dismantling the tent");
    ob->remove_property("busy");
    return;
  }
  interior = find_object_or_load("/d/avatars/lujke/rooms/tent_interior");
  if (!objectp(interior)){
    tell_object(ob, "Sorry, something's gone wrong with the interior of the tent. Please make a bug"
                   +" report. Or tell Lujke he's a silly Draconian, or something");
    ob->remove_property("busy");
    setter = 0;
    return;
  }
  stuff = all_inventory(interior);
  if (sizeof(stuff)>0){
    tell_object(ob, "You can't dismantle the tent just now. It's not empty");
    tell_room(room, TPQCN +" seems to have a problem and can't finish dismantling the tent");
    ob->remove_property("busy");
    setter = 0;
    return;
  }

  tell_object(ob, "You finish dismantling the tent");
  tell_room(room, (string)ob->QCN + " finishes dismantling the tent", ob);
  erect = 0;
  setter = 0;
  room->remove_exit("tent");
  roomname = file_name(room);
  interior->remove_exit( "out" ); 
  set_weight(8);
  TO->move(ob);
  ob->remove_property("busy");
    set_id( ({"bag","duffle bag", "tent" }) );
}
