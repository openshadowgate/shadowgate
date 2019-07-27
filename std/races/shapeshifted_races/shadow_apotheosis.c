// this file is only for use in the "alter self" spell. It creates a single same-race profile for the caster.
#include <std.h>
#include <objects.h>
#include <daemons.h>
inherit SHAPESHIFT;

void create(){
    ::create();
    set_ac_bonus(0);
    set_base_attack_num(0);
    set_castable(1);
    set_can_talk(1);
    set_shape_bonus("spellcraft",8);
    set_shape_bonus("sight bonus",4);
    set_shape_bonus("empowered",2);
    set_shape_bonus("damage resistance",4);
    set_shape_bonus("spell damage resistance",8);    
    set_shape_profile("shadow_apotheosis");
}

string * query_subraces() {
    return ({ "shadow" });
}

// custom descriptions here, override this function
int default_descriptions(object obj) {
    if(!objectp(obj)) { return 0; }

    obj->set_description(" is a dark figure surrounded by vortex of shadows. It has familiar humanoid features, but is inky black. It looks back at you wit its crimson red eyes.");
    obj->setDescriptivePhrase("$R vortex");
    return 1;
}

int change_into_message(object obj) {
    if(!objectp(obj)) { return 0; }
    return 1;
}

int change_outof_message(object obj) {
    if(!objectp(obj)) { return 0; }
    return 1;
}

int shape_attack(object tp, object targ) { return 0; }

int init_shape(object obj,string str){
    if(!objectp(obj)) { return 0; } //
    if(obj->query_property("altered") ||
       obj->query_property("shapeshifted"))
        return 0;
    obj->set_property("altered",shape = new(base_name(TO)+".c"));
    shape->set_owner(obj);
    shape->change_into_message(obj);
    shape->set_base_profile((string)obj->query("relationship_profile"));
    obj->set("relationship_profile",shape->query_shape_profile());
    obj->add_id(obj->query_race());
    if(objectp(to_object(DESC_D)))
    {
        desc = new(DESC_D);
        if(!desc->restore_profile_settings(obj,shape->query_shape_profile())) { 
            shape->default_descriptions(obj);
            desc->initialize_profile(obj);
        }
    }
    return 1;
}

int reverse_shape(object obj){
    if(!objectp(obj)) { return 3; }
    if(!objectp(shape = obj->query_property("altered"))) { return 5; }
    obj->set("relationship_profile",shape->query_base_profile());

    if(objectp(to_object(DESC_D))) {
        desc = new(DESC_D);
        desc->restore_profile_settings(obj,shape->query_base_profile());
    }
    shape->change_outof_message(obj);
    shape->set_owner(0);
    obj->remove_property("altered");
    clean_me = 1;
    destruct(TO);
    return 1;
}


