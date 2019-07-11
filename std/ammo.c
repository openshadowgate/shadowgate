// Changing to wearable ring-type. N, 1/13.
//Altered by Circe 12/04 - fixed weight bug with combining quivers
//Also adding ability to split quivers
#include <std.h>
//inherit OBJECT;
inherit "/std/armour";

string query_ammo_type();
int missiles;
mapping __Damage;

void create() {  // added "void" (declaration) for bug prevention *Styx* 7/14/05
    ::create();
   set_weight(3);
   set("value", 1);
   set_limbs(({ "torso" }));
   set_type("ring");
   set_ac(0);
   __Damage = ([]);
}

void init(){
    ::init();
    add_action("count","count");
    add_action("combine","combine");
    add_action("take_em","take");
}

int count(string str){
    if(!str) return notify_fail("Try count <arrows/quiver>|<all/quivers>\n");
    if(str == "all" || str == "quivers"){
        if(missiles < 0) tell_object(TP,"You get the feeling your quiver of "+query_ammo_type()+" would never run out.");
        else tell_object(TP,"You count your quiver of "+query_ammo_type()+" and find you have "+missiles+" left.");
        return notify_fail("\n");
    }
    if(!id(str)) return notify_fail("You don't have any of those!.\n");
    
    if(missiles < 0) tell_object(TP,"You get the feeling your quiver of "+query_ammo_type()+" would never run out.\n");
    else tell_object(TP,"You count your quiver of "+query_ammo_type()+" and find you have "+missiles+" left.\n");
    tell_room(ETP,TPQCN+" counts the "+query_ammo_type()+" in "+TP->query_possessive()+" quiver.\n",TP);

    return 1;
}

int use_shots(){
    int myshots;
    if(missiles == 0) return 0;
    if(missiles > 0) missiles --;
    myshots = absolute_value(missiles);
    set_weight(myshots/5+3);
    if(living(ETO)) ETO->add_encumbrance((myshots/5)-(myshots+1)/5);
    return 1;	
}

int query_shots(){
    return missiles;
}

void set_shots(int shots){
    missiles = shots;
    set_weight((absolute_value(missiles))/5+3);
}

void set_wc(int num,int plus){
    __Damage["num"] = num;
    __Damage["plus"] = plus;
}

int *query_wc(){ return (({ __Damage["num"],__Damage["plus"] })); }

void set_large_wc(int num,int plus){
    __Damage["lnum"] = num;
    __Damage["lplus"] = plus;
}

int *query_large_wc(){ return (({ __Damage["lnum"],__Damage["lplus"] })); }

void set_poisoning(int amount){
//
    __Damage["poison"] = amount;
}

int query_poisoning(){
    return __Damage["poison"];
}

void set_ammo_type(string type){
    set("ammo type",type);
}

string query_ammo_type(){
    return query("ammo type");
}

int query_large_ammo_damage(){
    return roll_dice(__Damage["lnum"],__Damage["lplus"]) + query_property("enchantment");
}

int query_ammo_damage(){
    int dam = roll_dice(__Damage["num"],__Damage["plus"]);
    dam += query_property("enchantment");
    //Commented out by Saide - 7 - 16 - 04
    //write("dam = "+dam);
    return dam;
}

int combine(string str){
    object obj;
    string targ,dest;

    if(!str) return 0;
    if(TP->query_bound() || TP->query_unconscious()){
        TP->send_paralyzed_message("info",TP);
        return 1;
    }

    if(sscanf(str,"%s with %s",targ,dest) != 2)
        return notify_fail("Syntax: combine quiver with quiver\n");
    if(!id(targ)) return 0;
    if(!obj = present(dest,TP)) return notify_fail("There is no second quiver.\n");
    if(TO->query_shots() < 0 || obj->query_shots() < 0)
       return notify_fail("You can't combine a limitless quiver with something else!\n");
    if(present(dest,ETP)) return notify_fail("You will need to be holding "+
       "both quivers to do that.\n");
//I'm not happy with this fix, but it will work while I'm trying to get another.  Circe
    if(obj == TO) return notify_fail("You can't do that.\n");
    if(query_ammo_type() != (string)obj->query_ammo_type()) {
        return notify_fail("They are of different types.\n");
    }
/*
    TP->add_encumbrance(-(missiles/5));
    missiles += obj->query_shots();
    TP->add_encumbrance(missiles/5);
    set_weight(missiles/5+3);
    tell_object(TP,"You combine the two quivers of "+
    query_ammo_type()+".");
    if(!TP->query_invis()) {
        tell_room(ETP,"You see "+TPQCN+" combine two quivers of "+
        query_ammo_type()+".",TP);
    }
    obj->remove();
    return 1;
This was the original code but was bugging weight.  After much thought (probably way too much thought :P) and experimentation, I finally realized that the net result of combining quivers is that the current weight goes down by 3 (the weight of the extra "quiver" minus arrows).  The below code seems to work fine.  If my thinking is flawed, feel free to fix it and/or let me know.  Circe 12/7/04
*/
    missiles += obj->query_shots();
    set_weight(missiles/5+3);
    obj->set_shots(0); //this is so only the 3 pounds are taken away when removed
    tell_object(TP,"You combine the two quivers of "+
    query_ammo_type()+".");
    if(!TP->query_invis()) {
        tell_room(ETP,"You see "+TPQCN+" combine two quivers of "+
        query_ammo_type()+".",TP);
    }
    obj->remove(); 
//remove() takes away the weight left anyway.  
//This was part of what was causing the bug.  C 
    return 1;
}

int take_em(string str){
    object obj,obj2;
    string dest;
    int num;

    if(!str) return 0;
    if(TP->query_bound() || TP->query_unconscious()){
        TP->send_paralyzed_message("info",TP);
        return 1;
    }

    if(sscanf(str,"%d from %s",num,dest) != 2)
        return notify_fail("Syntax: take # from quiver\n");
    if(!id(dest)) return 0;
    if(!obj = present(dest,TP)) return notify_fail("You don't have any quiver.\n");
    if(missiles < 0) return notify_fail("You can't split a limitless quiver!\n");
    if((num == missiles) || (num > missiles)) return notify_fail("There "+
       "are not enough to take that many!  You have "+missiles+".\n");

    missiles -= num;
    set_weight(missiles/5+3);
    seteuid(getuid());
    TP->add_encumbrance((-1)*(num/5));
    obj2=new(base_name(TO));
    obj2->set_shots(num);
    tell_object(TP,"You take "+num+" "+query_ammo_type()+"s from "+
       "the quiver.");
    if(!TP->query_invis()) {
        tell_room(ETP,"You see "+TPQCN+" take some "+query_ammo_type()+" "+
           "from the quiver.",TP);
    }
   if (obj2->move(TP)) {
      write("%^ORANGE%^You appear to have your arms too full and "+
         "fumble the "+query_ammo_type()+".");
      tell_room(ETP,"%^ORANGE%^You see "+TPQCN+" fumble the quiver, "+
         "and it falls to the ground",TP);
      obj2->move(ETP);
   }
    return 1;
}

int query_weight(){
    return((absolute_value(missiles))/5+3);
}

//discard_quiver() added by Circe to stop bugs with damage.  
//Thanks for the help, g :)  12/20/04

int discard_quiver(){
   tell_object(ETO,"You have shot the last arrow and discard the quiver.");
   TO->remove();
   return 1;
}
