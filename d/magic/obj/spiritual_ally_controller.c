#include <std.h>

inherit OBJECT;

object caster, sally, *foes;
int freed, count;

void save_me(string file){return 1;}

void create()
{
    ::create();
    set_name("device");
    set("id", ({ "device_sally999" }) );
    set_weight(0);
}

int move(mixed dest)
{
   if(ETO && objectp(ETO))
      if(interactive(ETO))
         return 0;
   ::move(dest);
   set_heart_beat(1);
}

set_caster(object ob)
{
   if(objectp(ob)){
      caster = ob;
   }
   else
      remove();
}

object query_sally(){return sally;}

object query_caster(){return caster;}

void set_sally(object ob)
{
   sally = ob;
}

void heart_beat()
{
   object *tmp;
   int i,j;

   tmp = ({});
   if(!objectp(caster))
      remove();
   if(!objectp(sally))
       remove();
}

void remove()
{
    if(!objectp(TO)) { return; }
    if(objectp(TO->query_property("spell")))
        TO->query_property("spell")->dest_effect();
    if(objectp(TO))
        return ::remove();
}

void init()
{
   ::init();
   add_action("cmd","command");
   add_action("dismiss","dismiss");
}

int cmd(string str){
   object ob;
   string what, who, what2, holder;
   int i,j;

   if(!str)
       return notify_fail("Care to tell it what to do?\n");
   if(sscanf(str, "%s to %s", who, what) != 2)
      return notify_fail("Syntax: <command ally to ACTION>\n");
   if(who != "ally")
      return 0;
   if(what[0..3] == "kill")
   {
      if(sscanf(what, "kill %s",who) == 1)
      {
         if(ob = present(who,environment(caster)))
         {
            if(objectp(ob))
            {
               if(!caster->ok_to_kill(ob))
               {
                  tell_object(caster,"You are not allowed to kill that creature!");
                  return 1;
               }
            }
         }
      }
   }
   if(what == "follow")
   {
      if(present(sally,environment(caster)))
      {
         tell_object(caster,"%^CYAN%^Spiritual weapon is now following you.");
         caster->add_follower(sally);
         return 1;
      }
      else
      {
         tell_object(caster,"%^CYAN%^The weapon must be present before it can follow you!");
         return 1;
      }
   }
   if(!caster->query_property("safe arena") || !ob->query_property("safe arena"))
       "/daemon/killing_d"->check_actions(caster,ob);
   if(!sally->force_me(what))
      return notify_fail("You fail to command the ally to "+what+"!\n");
   tell_object(caster,"%^CYAN%^Spiritual ally obeys your command to "+what+".");
   if(!objectp(sally))
       return 1;
   return 1;
}

int dismiss(string str)
{
   if(!str || str != "ally")
      return 0;
   tell_object(caster,"%^BOLD%^You dismiss the ally!\n");
   if (objectp(sally)) sally->remove();
   call_out("timed",1);
   return 1;
}

int timed(){
   remove();
}
