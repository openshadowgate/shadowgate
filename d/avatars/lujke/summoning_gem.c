//Coded by Lujke


#include <std.h>
inherit OBJECT;

object item;
string owner;
string password;

void create() {
    ::create();
    set_name("gem");
    set_id( ({"gem","summoning gem",}) );
    set_short("summoning gem");
    set_obvious_short("a gem");
    set_weight(2);
    set_long("A nice looking gem");
}

void init()
{
  ::init();
  add_action("crush_gem", "crush");
}

int crush_gem(string str)
{
  string word;
  object env, envenv, holder, holdenv;
  holder = environment(TO);
  sscanf(str, "gem while saying %s", word);
  if (!objectp(holder)){
    return 0;
  }
  holdenv = environment(holder);
  if (!objectp(holdenv)){
    return 0;
  }
  if (!objectp(item)){
    tell_object(holder,"Unfortunately, the item seems no longer to"
                      +" exist");
  }
  if (word != password){
    tell_object(holder,"The gem does not respond to the word '"+ word 
                      +"' and you fail to crush it.");
    return 1;
  }
  env = environment(item);
  if (objectp(env) &&interactive(env)){
    envenv = environment(env);
    if (!objectp(envenv)){
      notify_fail("Error with the gem you are trying to crush; the object"
               +" is in a strange environment. Please make a bug report");
      return 0;
    }
    tell_room(holdenv,holder->QCN + " tighten's "+ (string)holder->QP 
                     + " fist around the gem " + (string)holder->QS
                     + " is holding.",holder);
    holder->force_me("say " + word);
    tell_object(holder, "You crush the gem and try to draw the "  
                   + (string)item->query_name() +" to you, but something"
                   + " resists you and a sudden vision of the " 
                   + (string)item->query_name() + " flashes before you,"
                   +" held in " + (string)env->query_name() +"'s hands,"
                   +" at " + (string)envenv->get_title());
    tell_room(holdenv,(string)holder->QCN + " crushes the gem and it"
                     +" crumbles into a fine powder which blows away" 
                     +" between "+(string)holder->QP + "fingers.",holder);
    return 1;
  }
  item->move(holder);
  tell_room(holdenv,holder->QCN + " tighten's "+ (string)holder->QP 
                     + " fist around the gem " + (string)holder->QS
                     + " is holding.",holder);
  holder->force_me("say " + word);
  tell_object(holder,"The gem crumbles to a fine powder in your hand as"
                    +" you say the password, and the " 
                    + (string)item->query_name() 
                    +" appears in its place in your hand.");
  tell_room(holdenv,(string)holder->QCN + " crushes the gem and it"
                     +" crumbles into a fine powder which blows away" 
                     +" between "+(string)holder->QP + "fingers. In its"
                     +" place, you see a " + (string)item->query_name() 
                     + ".",holder);
  TO->remove();
  return 1;
}

int set_item(string item_name, string word, object ob){
  if (!objectp(ob)||!interactive(ob)){
    return 0;
  }
  item = present(item_name,ob);
  if (!objectp(item)){
    tell_object(ob,"You don't have a " + item_name + " with you");
    return 1;
  }
  password = word;
  owner = (string)ob->query_name();
  return 1;
}