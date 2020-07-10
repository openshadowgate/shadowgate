//halberd for trade from fey'ri glaive hades 7-6/20
#include <std.h>
#include <daemons.h>
#include "../argabbr.h"
inherit "/d/common/obj/weapon/halberd.c";

void create(){
    ::create();

    set_name("Halberd");
    set_id(({"halberd","sapphire glaive","glaive of the exterminated"}));
    set_short("Fey Halberd ");
    set_obvious_short("leaf covered halberd");
    set_long("This large polearm consists of a large wooden pole"+
    " that is covered with green leaves and a silver axe head on the end."+
    "  Above the axe there is a pointed spike.  All of the metal parts"+
    " of this weapon seem to be created with a hardened silver alloy.");
    set_lore("An adventurer brought this strange weapon to the elves "+
    "leading the revolt against the fey'ri on Argentrock.  They didn't"+
    " know what to do with it and it took years before an oracle was"+
    " able to find a way to release the souls trapped within."+
    "  Some of the spirits were so grateful to be purified that even "+
    "though they were free to leave they banded together to create"+
    " this blessed weapon.  The weapon seems alive and could <grow>"+
    " a rope from the vines.");
    set_property("lore difficulty",60);
    set_value(9000);
    set_hit((: TO, "extra_hit":));
    set_wield((: TO, "extra_wield":));
    set_unwield((: TO, "extra_unwield" :));
    set_property("enchantment",5);
    set_item_bonus("attack bonus",3);
    set_item_bonus("negative energy resistance", 20)
}

void mess() {
    int i;
    object *msgs;
    if(!query_wielded() || !ETO) return;
        msgs = ({"Fey'ri are not to be trusted.",  
"What villains would harvest the souls of their companions to try to imitate the power of a moonblade?",
"The evils of this world would do anything for power.  ",
"Protecting the pure against those who would defile the forest that is our goal.",
"The Fey'ri abandoned the gods when they chastised them and sought favor with the demons.",
"Kill any Fey'ri that you see.",
"Fey'ri harvest souls for corrupt moonblades.",
"The weapon the watcher has is but a dark shadow to the true high magic of the pure fey.",
"I seek a hero who is pure of heart and will fight back against the demons who corrupted the elves into fey'ri.",
"Seek to purify demonic corruption wherever you see it.",
"Gathering power for the sake of becoming powerful only is what lead the fey'ri into the hands of the demons.",
"The Fey'ri are an example of history repeating itself.",
"Fey'ri should have learned from the drow's mistakes but instead repeated them.  Bathing souls in malice and forcing them into a gem to be used as a weapon.",
"The fey'ri will stop at nothing.",

        });
write("%^BOLD%^%^RED%^The Halberd tells you: %^RESET%^"
   +msgs[random(sizeof(msgs))]);
call_out("mess",120+random(1000));
return;
}

int extra_hit(object targ)
{ int i;
  object *attackers, ob,tree;
 if(!objectp(ETO)) return 1;
 if(!objectp(targ)) return 1;
 //brambles around head
 if((string)targ->return_target_limb()=="head") {
    tell_room(EETO,""+ETO->QCN+" slices the blade into "
        +targ->QCN+"'s head and brambles tighten around "+ETO->QP+" neck."
        ,({ETO,targ}));
        tell_object(ETO,"You slice the weapon into "+
        targ->QCN+"'s head and brambles tighten around "+
        ETO->QP+"neck.");
        tell_object(targ,""+ETO->QCN+" slices you in the"+
        " head and brambles slide from the blade around your neck.  "+
        "Your airway slowly gets cut off!.");
        if(!"/daemon/saving_throw_d.c"->reflex_save(targ,-40))
          targ->set_paralyzed(5,"The brambles around your neck "+
          "stop you from breathing.");

                if(!present("brambobj",targ)){
                ob = new(OBJ+"bram");
                ob->move(targ);
                if(objectp(ob) && objectp(targ))
                                  ob->hurt(targ);
                                }
        return roll_dice(2,6);
  }
  // possess a tree
    if (member_array(EETO->query_terrain(),({"heavy forest",
    "lightforest","jungle","branches"})) != -1 &&
        !present("tree",EETO))
        {  tell_room(EETO,"A blue haze shoots from one of the sapphires in "
           +ETO->QCN+"'s glaive into a nearby tree",({ETO}));
        tell_object(ETO,"A soul comes out from one"+
         " of the saphires on your weapon and posseses a tree.");
        tree =new(MON+"tree");
        tree ->move(environment(ETO));
        ETO->add_protector(tree);
        tree ->force_me("kill "+targ->query_name());
        ETO->add_follower(tree);
         return 1;
        }
   if(!random(16)) {
      tell_object(ETO,"You drive the glaive across"+
                " "+targ->QCN+", leaving a thorn filled wound.");
      tell_object(targ,""+ETO->QCN+"'s"+
                " glaive slashes into you leaving a thorn filled wound.");
      tell_room(EETO,""+ETO->QCN+"'s glaive slashes "+targ->QCN+"'s"+
                " body, leaving a thorn filled wound.",({ETO,targ}));

        return roll_dice(2,6)+2;}
   if(!random(50)) {


     tell_object(ETO,"You slash into "+targ->QCN+
         " and your weapon sprays thorns into the wound..");
     tell_room(EETO,""+ETO->QCN+"'s"+
          " glaive sprays thorns at "+
                  targ->QCN+".",({ETO,targ}));
         tell_object(targ,""+ETO->QCN+"'s"+
                " glaive slashes you then begins spraying thorns.");
    
new("/cmds/spells/t/_thorn_spray")->use_spell(ETO,targ,15,100,"cleric");
        return 1;
   }
}


int extra_wield() { // only part elven
    int racey;
    if (!ETO) return 0;
        racey=ETO->query_race();
 if(member_array(racey,({"elf","half-elf","drow",
        "half-drow", "voadkyn" })) != -1){
                write(
            "As you wield the glaive, visions "+
            "of a desperate battle fill your head,"+
            " your companions are slain left and right
alongside you.");
        say(
            ""+ETOQCN+" wields a glaive and gets a far "+
            "away look in "+ETO->QP+" eyes.\n"+
            "Blinking, "+ETO->QS+" looks quite disturbed. ");

                ETO->set_property("good item",1);
         if(find_call_out("mess")==-1)
           call_out("mess",120+random(1000));
                }
        else{
           say(""+ETOQCN+" holds the glaive but jerks violently"+
             " as brambles lash out from it, wrapping "+ETO->QO+"
tightly.");
           write("The glaive juts out brambles that bind"+
           " you fast when you place your hand on it."+
           "  \n They cut into you terribly.");
           ETO->set_paralyzed(10,"You can't move!");
       ETO->set_bound(150,"Brambles bind you fast.");
           ETO->do_damage(100);
           return 0;
           }
    return 1;
}
int extra_unwield() {
    if (!ETO) return 0;
    tell_object(ETO,
    "You release the "+
         "Halberd and sigh.");
        ETO->set_property("good item",-1);
   return 1;
}
void init() {
   ::init();
    if(!objectp(TP)) return;
    if(!objectp(ETO)) return;
    if(TP != ETO) return;
   add_action("grow","grow");
}

int grow(string str) {
   object rope;

   if(ETO->query_bound() || ETO->query_unconscious()) {
     ETO->send_paralyzed_message("info",ETO);
         return 1;}
   if(!query_wielded()){
     write("You must wield the halberd to use this power.");
     return 1; }

       tell_object(ETO,"Your weapon grows a rope-like vine."+
             "  The action drains your energy.");
       tell_room(EETO,""+ETO->QCN+"'s weapon grows a rope-like vine.",ETO);
       rope = new("/d/common/obj/misc/rope");
       rope->set_short("A vine rope");
       rope->set_long("This rope looks more like a "+
            "jungle vine than a rope.  It is quite flexable"+
                " and could bind a person very well.");
       rope->move(ETO);
       ETO->use_stamina(50);
       ETO->set_paralyzed(5,"The weapon drains your stamina.");
       return 1;
}
