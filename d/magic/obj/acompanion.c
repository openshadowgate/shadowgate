/*
  acompanion.c
  
  Animal companion for rangers. Will be fleshed
  out more over time.
  
  -- Tlaloc --
*/

inherit WEAPONLESS;

object owner;

int set_owner(object ob) { owner = ob; return 1; }
object query_owner()     { return owner; }

void create(){
    ::create();
    set_name("companion");
    set_id(({"companion", "greater summon"}));
    set_short("A generic animal companion");
    set_hd(4,1);
    set_hp(40);
    set_exp(1);
    set_size(2);
    set_gender("neuter");
}

void heart_beat()
{

    object *attackers,
           room;
           
    ::heart_beat();
    
    if(!owner)
        return;
    
    if(!interactive(owner))
    {
        destruct(this_object());
        return;
    }
    
    room = environment(this_object());
    
    //Faithful companion finds his master
    if(living(owner) && room != environment(owner))
        this_object()->move(owner);
    
    attackers = owner->query_attackers();
    
    if(sizeof(attackers))
    {
        //Companion always helps with the fight
        if(!this_object()->query_attackers())
        {
            tell_room(room, sprintf("%s joins the fight.", this_object()->query_name()));
            foreach(object ob in attackers)
                this_object()->kill_ob(ob);
        }
    }
    else
        add_hp(query_max_hp() / 25);
}

void die(object ob)
{
    owner && owner->remove_property("animal_companion");
    remove();
}

int remove()
{
    reset_all_status_effects();
    all_inventory(TO)->remove();
    ::remove();
}
