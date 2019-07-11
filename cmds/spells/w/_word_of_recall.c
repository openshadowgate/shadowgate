//      Teleport without error
// Ganked for Succor -Ares
// Ganked for Word of Recall -Ares
#include <spell.h>
#include <magic.h>
#include <daemons.h>

inherit SPELL;

void move_caster(object endplace);

void create()
{
    ::create();
    set_spell_name("word of recall");
    set_spell_level(([ "druid" : 8 ]));
    set_spell_sphere("alteration");
    set_syntax("cast CLASS word of recall to <location>");
    set_description("The word of recall spell will allow a druid to travel to a location that he or she has previously "
        " remembered from the 'remembered location' list.  To remember a new location use 'remember here as <location>', to see a list of all "
        "remembered locations, use 'recall locations'.\nThis spell must be cast while at peace.\nSee also: remember, unremember, recall");
    set_verbal_comp();
    set_arg_needed();
    set_peace_needed(1);
	set_helpful_spell(1);
}


string query_cast_string()
{
    tell_object(caster,"%^GREEN%^You close your eyes and concentrate, slowly fading into the essence of the world.");
    tell_room(place,"%^GREEN%^"+caster->QCN+" closes "+caster->QP+" eyes and concentrates, slowly fading away!",caster);
    return "display";
}

void spell_effect(int prof)
{
    string a, file, tempstr, *tempdir;
    int mypower,startpower,endpower,bonus;
    mapping tmp;
    object endplace;

    tempstr = ARG;
    if(!tempstr) { tempstr = ""; }

    if(!sscanf(tempstr, "%s", a)) 
    {
        tell_object(caster,"Your spell has no effect without a location.");
        tell_room(place,caster->QCN+" looks around with a concerned expression.",caster);
        TO->remove();
        return;
    }
    tmp = caster->query_rem_rooms();
    file = tmp[a];
    if(member_array(a, caster->query_rem_rooms_sort()) < 0 || !file || !stringp(file)) 
    {
        tell_object(caster,"Your can't remember a place named "+a+" so "
            "your spell has no effect.");
        tell_room(place,caster->QCN+" looks around with a concerned expression.",caster);
        TO->remove();
        return;
    }
    if(file)
    {
        if(!(endplace = find_object_or_load(file))) 
        { 
            file = 0; 
        }
    }
    if(endplace && (endplace->query_property("no teleport") 
      || place->query_property("no teleport") || !endplace->is_room()))
    {
        file = 0;
    }    
//teleport proof stuff by ~Circe~ 6/20/08
//new property to be used for areas protected from teleport 
//but not foolproof
   if(endplace && 
      (endplace->query_property("teleport proof") ||
      place->query_property("teleport proof") ||
      !endplace->is_room())){
      startpower = place->query_property("teleport proof");
      endpower = endplace->query_property("teleport proof");
      bonus = caster->query_stats("wisdom");
      bonus = bonus -10;
      if((object *)caster->query_attackers() != ({})){
         mypower = CLEVEL + bonus + random(6);
      }else{
         mypower = CLEVEL + bonus + random(6) + 5;
//making it easier to teleport out if you aren't in combat
      }
      if((mypower < startpower) || (mypower < endpower)){
          file = 0;
      }
   }
    if(!file) 
    {
        tell_object(caster,"You stop casting as you feel something magically "
            "blocking your passage.");
        tell_room(place,caster->QCN+" looks concerned.",caster);
        TO->remove();
        return;
    }
   if(endplace->is_flight_room())
   {
      tell_object(caster,"You cease your spell-casting as "+
         "you sense something blocking your magical "+
         "passage.");
      tell_room(place,caster->QCN+" apparently "+
         "looks startled.",caster);
      TO->remove();
      return;
   }

   caster->clear_followers();

    spell_successful();
    tell_object(caster,"%^BOLD%^%^GREEN%^You can feel yourself moving effortlessly through the ether.");
    tell_room(place,"%^GREEN%^As "+caster->QCN+" concentrates, "+caster->QS+" begins to fade from existance.",caster);
    tell_room(endplace,"%^BOLD%^%^GREEN%^An ghostly mist begins to appear in the air!",caster);
    caster->setAdminBlock();
    call_out("move_caster",1, endplace);
    return;
}

void move_caster(object endplace) 
{
    string height;

    if (!caster) 
    {
        dest_effect();
        return;
    }
    caster->removeAdminBlock();
    if(caster->query_ghost()) 
    { 
        dest_effect(); 
        return;
    }
    tell_object(caster,"%^BOLD%^%^GREEN%^When you open your eyes, you find yourself in "+endplace->query_short()+".");
    tell_room(place,"%^BOLD%^%^GREEN%^"+caster->QCN+" fades away to nothing and simply vanishes!",CASTER);
    tell_room(endplace,"%^BOLD%^%^GREEN%^The ghostly mist begins to take shape, and in its place is left "+caster->QCN+".",CASTER);
    caster->move_player(endplace);
    dest_effect();
}

void dest_effect() 
{
    ::dest_effect();
    if(objectp(TO)) TO->remove();

}
