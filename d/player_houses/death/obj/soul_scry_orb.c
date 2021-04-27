#include <std.h>

inherit OBJECT;

#define SCRY_D "/daemon/ic_scry_locate_d"


object target,scry_control,caster;
int in_use;

void dest_effect();

void create()
{
    ::create();
   
    set_name("soul window");
    
    set_id(({ "orb", "scrying orb","window","soul window","crystal ball","ball" }));
	
    set_short("%^RESET%^%^CYAN%^So%^BOLD%^u%^RESET%^%^CYAN%^l Wi%^RESET%^n%^CYAN%^d%^BOLD%^%^o%^RESET%^%^CYAN%^w%^RESET%^");
	
    set_long("%^CYAN%^This roughly rectangular shape hangs in the sky, "
       "nearly invisible. A warping around the edges is all that gives "
       "it away. Looking closer, you realize you could use this window "
       "to <gaze> on those still in the mortal realms and <stop> whenever "
       "the pain - or boredom - becomes too much.%^RESET%^");
    
    set_weight(500);
    
    set_value(0);
	
    set_lore("%^BOLD%^Windows such as this exist at scattered points "
       "throughout the cosmos. No one knows when or where one will appear "
       "- or when it will disappear again. The clergy of Oghma speculate "
       "that these windows are evidence of the connections between the realms "
       "of existence and that the fabric that separates them is thinnest "
       "where these windows appear.%^RESET%^");
    
    set_property("lore difficulty",20);
    in_use = 0;
    set_heart_beat(4);

}

void init() {
    ::init();
    add_action("lookin","gaze");
    add_action("stop_scrying","stop");
}

void heart_beat(){

   if(!objectp(ETO)) { return; }
   if(!in_use){ return; }
   if(!objectp(caster)){
      dest_effect();
      return;
   }
   if(!present(caster,ETO)){
      dest_effect();
      return;
   }
}


int lookin(string str){
    string *map_keys,real;
    int i,matches,num,duration,power;
    mapping map;

    if(!objectp(TO)) { return 0; }
    if(!objectp(ETO)) { return 0; }
    if(in_use){
       tell_object(TP,"The window is already in use!");
       return 1;
    }

    if(!str) 
    {
        notify_fail("What?\n");
        return 0;
    }

    target = lower_case(str);
    
    if(!stringp(real = (string)TP->realName(target)))
    {
        tell_room(ETO,"%^CYAN%^The hazy sky shifts for a moment but then "
            "nothing happens.%^RESET%^");
        return 1;
    }

    target = find_player(real);
    
    if(!target) 
    {
        tell_room(ETO,"%^CYAN%^The hazy sky shifts for a moment but then "
            "nothing happens.%^RESET%^");
        return 1;
    }

    if(target == TP) 
    {
        tell_object(TP,"%^CYAN%^An image of yourself peers back at you for an instant and "
            "then it is gone!%^RESET%^");
        return 1;
    }

    if(target->query_property("no scry"))
    {
        tell_room(ETO,"%^GREEN%^The hazy sky takes on a sickly green "
           "glow before dissipating and returning to normal!%^RESET%^");
        return 1;
    }

    tell_object(TP,"%^CYAN%^As you stare into the hazy sky, the mist begins to clear "
        "and in its place forms a crystal clear image!%^RESET%^\n");

    tell_room(ETO,"%^CYAN%^As "+TPQCN+" stares into the hazy sky, "
        "the mist begins to clear and is replaced by a crystal clear image!%^RESET%^\n",TP);

    tell_object(TP,"%^YELLOW%^-%^RED%^*%^YELLOW%^-%^RED%^*%^YELLOW%^-%^RED%^*%^YELLOW%^-%^RED%^*%^YELLOW%^-%^RED%^*"
      "%^YELLOW%^-%^RED%^*%^YELLOW%^-%^RED%^*%^YELLOW%^-%^RED%^*%^YELLOW%^-%^RED%^*%^YELLOW%^-%^RED%^*"
      "%^YELLOW%^-%^RED%^*%^YELLOW%^-%^RED%^*%^YELLOW%^-%^RED%^*%^YELLOW%^-%^RED%^*%^YELLOW%^-%^RED%^*"
      "%^YELLOW%^-%^RED%^*%^YELLOW%^-%^RED%^*%^YELLOW%^-%^RED%^*%^YELLOW%^-%^RED%^*%^YELLOW%^-%^RED%^*"
      "%^YELLOW%^-%^RED%^*%^YELLOW%^-%^RED%^*%^YELLOW%^-%^RED%^*%^YELLOW%^-%^RED%^*%^YELLOW%^-%^RED%^*"
      "%^YELLOW%^-%^RED%^*%^YELLOW%^-%^RED%^*%^YELLOW%^-%^RED%^*%^YELLOW%^-%^RED%^*%^YELLOW%^-%^RED%^*"
      "%^YELLOW%^-%^RED%^*%^YELLOW%^-%^RED%^*%^YELLOW%^-%^RED%^*%^YELLOW%^-%^RED%^*%^YELLOW%^-%^RED%^*\n\n"
      "%^B_RED%^%^YELLOW%^PLEASE NOTE: %^RESET%^%^BOLD%^%^RED%^This window is provided "
       "for entertainment purposes only to help stave off boredom while you are "
       "trapped in the netherworld. No information you learn may be used when you "
       "return to the land of the living, unless an immortal specifically tells you "
       "otherwise. Those who abuse this ability will have it removed.%^RESET%^\n\n"
      "%^YELLOW%^-%^RED%^*%^YELLOW%^-%^RED%^*%^YELLOW%^-%^RED%^*%^YELLOW%^-%^RED%^*%^YELLOW%^-%^RED%^*"
      "%^YELLOW%^-%^RED%^*%^YELLOW%^-%^RED%^*%^YELLOW%^-%^RED%^*%^YELLOW%^-%^RED%^*%^YELLOW%^-%^RED%^*"
      "%^YELLOW%^-%^RED%^*%^YELLOW%^-%^RED%^*%^YELLOW%^-%^RED%^*%^YELLOW%^-%^RED%^*%^YELLOW%^-%^RED%^*"
      "%^YELLOW%^-%^RED%^*%^YELLOW%^-%^RED%^*%^YELLOW%^-%^RED%^*%^YELLOW%^-%^RED%^*%^YELLOW%^-%^RED%^*"
      "%^YELLOW%^-%^RED%^*%^YELLOW%^-%^RED%^*%^YELLOW%^-%^RED%^*%^YELLOW%^-%^RED%^*%^YELLOW%^-%^RED%^*"
      "%^YELLOW%^-%^RED%^*%^YELLOW%^-%^RED%^*%^YELLOW%^-%^RED%^*%^YELLOW%^-%^RED%^*%^YELLOW%^-%^RED%^*"
      "%^YELLOW%^-%^RED%^*%^YELLOW%^-%^RED%^*%^YELLOW%^-%^RED%^*%^YELLOW%^-%^RED%^*%^YELLOW%^-%^RED%^*%^RESET%^\n");
    
    scry_control = new("/d/magic/obj/eye_orb");
    scry_control->set_caster(TP);
    caster = TP;
    scry_control->set_scry_power(100);
    scry_control->set_target(target);
    scry_control->move(environment(target));
    in_use = 1;
    return 1;
}

void stop_scrying()
{
    if(!in_use){
       tell_object(TP,"The window is not in use!");
       return 1;
    }
    dest_effect();
    return 1;
}


void dest_effect() 
{
    if(objectp(scry_control)) 
    {
        SCRY_D->stop_scry(scry_control, 0);
        scry_control->dest_me();
    }
    if(objectp(ETO))
    {
                tell_room(ETO,"%^CYAN%^The images fade, leaving behind a hazy sky!%^RESET%^");
    }
    in_use = 0;
    return;
}
