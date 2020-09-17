//bumped the enchantment range and special damage to bring it more competitive with other Klauth weapons that can be brought to +10 - Yves 7/30/19
//added call to setup_shadow on summon special - Yves 8/9/19


#include <std.h>
#include <daemons.h>
inherit "/d/common/obj/weapon/falcata.c";

int firstwield, burn, charm;


create()
{
    ::create();
    set_id(({ "falcata","sword","falcata sword","Akra Mashul","akra mashul","Akra mashul","akra Mashul","Akra'Mashul","akra'mashul"}));
    set_name("%^BOLD%^%^BLACK%^Akra'Mashul%^RESET%^");
    set_short("%^BOLD%^%^BLACK%^Akra'Mashul%^RESET%^");

    set_obvious_short("%^BOLD%^%^BLACK%^A dark %^RESET%^s%^BOLD%^%^WHITE%^i%^RESET%^l%^BOLD%^%^BLACK%^v%^RESET%^e%^BOLD%^%^WHITE%^r %^RESET%^and %^BOLD%^%^BLACK%^ebony f%^RESET%^a%^BOLD%^%^BLACK%^lca%^RESET%^t%^BOLD%^%^BLACK%^a%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^This beautifully crafted falcata yields a softly glowing light around its"
        " %^RESET%^s%^BOLD%^%^WHITE%^i%^RESET%^l%^BOLD%^%^BLACK%^v%^RESET%^e%^BOLD%^%^WHITE%^r %^RESET%^blade"
        " %^BOLD%^%^BLACK%^while the obsidian hilt stands in a dark and foreboding contrast.  %^RESET%^%^CYAN%^Runes"
        " %^BOLD%^%^BLACK%^freely float within the %^RESET%^crystal %^BOLD%^%^BLACK%^pommel of the sword, surrounding"
        " two darkly peering %^RESET%^%^MAGENTA%^eyes %^BOLD%^%^BLACK%^that shift with your movements as to never remove"
        " their sultry gaze from you.  The sword is amazingly light weight and the elegantly curved %^RESET%^blade"
        " %^BOLD%^%^BLACK%^is honed to a paper fine edge.%^RESET%^");

    set_lore("%^BOLD%^%^BLACK%^This dark weapon is rumored to be of drow make.  Hidden deep within the underdark,"
        " it was embued with the dark magics known only to their kind.  It is known to have been given the name"
        " Akra'Mashul, but little else can be said of it... None know for sure if the drow made it, or if they are"
        " only the ones to have found it and given it the name.  In fact, none are even sure why it was hidden, was"
        " it because even they were afraid of the awesome power that could be yielded from such a weapon?  Few creations"
        " can be called evil, despite who made it.  This sword however, is said to embody the very presence of evil.");

    set_value(375000);

    set_property("no curse",1);


    set_item_bonus("damage bonus",7);
    set_item_bonus("will",6);
    set_item_bonus("charisma",-2);

    set_hit((:TO,"hit_func":));
    set_wield((:TO,"wield_func":));
    set_unwield((:TO,"unwield_func":));

    set_property("quest required","%^BOLD%^%^RED%^Defeated the great red wyrm Klauth!%^RESET%^");

    set_heart_beat(1);
    burn = 0;
    charm = 0;
    firstwield = 0;
}


int wield_func()
{
    object ob;

    if((string)ETO->query_gender() == "male")
    {
        if((int)ETO->query_highest_level()<40)
        {
            tell_object(ETO,"%^BOLD%^%^BLACK%^Dark laughter echos through your head followed by the knowledge that you are not ready to wield such power as that possessed by Akra'Mashul!");
            ETO->do_damage("torso",random(100)+200);
            ETO->add_attacker(TO);
            ETO->continue_attack();
            ETO->remove_attacker(TO);
            TO->remove();
            return 0;
        }

        if(!present("akrasheath",find_player((string)ETO->query_name())))
        {
            ob=new("/d/token_hunt/obj/high/asheath.c");
            ob->move(ETO);
            ETO->force_me("wear soulwell");
            tell_object(ETO,"%^BOLD%^%^BLACK%^A black sheath slowly materializes in your possession.%^RESET%^");
        }

        // evils can only be recognized as the master
        if(((int)ETO->query_alignment() % 3)==0 && !firstwield)
        {
            tell_object(ETO,"%^BOLD%^%^BLACK%^A dark presence fills your mind as you realize the sword, Akra'Mashul, has accepted you as master!");
            tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETO->QCN+" is encompassed by a soothing dark shadow as "+ETO->QS+" takes command of the mighty falcata!",ETO);
            firstwield = 1;
        }

        if((int)ETO->query_highest_level() < 41)
        {
            tell_object(ETO,"%^BOLD%^%^RED%^Akra'Mashul warms to your touch as you grasp her slender hilt.  Visions of blood race through your head and a small voice creeps into the back of your mind and whispers sweetly: %^BLACK%^We must have ...victory!");
            tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETO->QCN+" takes on an eerily blank expression as "+ETO->QS+" grasps the hilt of the sword.",ETO);
            if(!query_property("enchantment")) { set_property("enchantment",6); }
            return 1;
        }

        if((int)ETO->query_highest_level() < 43)
        {
            tell_object(ETO,"%^BOLD%^%^BLACK%^A sweet, silky voice echos through your mind as you grasp the hilt, followed by the visions of you dancing through the shadows, letting the mighty Akra'Mashul slice through everything in her path!");
            tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETO->QCN+" grins darkly as "+ETO->QS+" lovingly grasps the hilt of the sword.",ETO);
            if(!query_property("enchantment")) { set_property("enchantment",7); }
            return 1;
        }

        if((int)ETO->query_highest_level() < 45)
        {
            tell_object(ETO,"%^RESET%^%^MAGENTA%^The sword purrs happily as you take her into your hands.");
            tell_room(EETO,"%^RESET%^%^MAGENTA%^The sounds of purring emits from the sword as "+ETO->QCN+" grasps its hilt!",ETO);
            if(!query_property("enchantment")) { set_property("enchantment",8); }
            return 1;
        }

        tell_object(ETO,"%^RESET%^%^MAGENTA%^The sword purrs happily as you take her into your hands.");
        tell_room(EETO,"%^RESET%^%^MAGENTA%^What almost sounds like purring emits from the sword as "+ETO->QCN+" grasps its hilt!",ETO);
        if(!query_property("enchantment")) { set_property("enchantment",9); }
        return 1;
    }

    tell_object(ETO,"%^BOLD%^%^BLACK%^A loud hiss can be heard as you try to wield the falcata, followed by the sounds of a dark voice echoing "
        "through your mind: %^RED%^You will never have me foolish Mortal!  Akra'Mashul was not meant for your type!");
    tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETO->QCN+" recoils in horror as "+ETO->QS+" grasps its hilt!",ETO);
    ETO->do_damage("torso",random(350)+250);
    ETO->force_me("drop Akra'Mashul");
    return 0;
}


int unwield_func()
{
    if(ETO->query_hp()<((int)ETO->query_max_hp()) / 3)
    {
        tell_object(ETO,"%^BOLD%^%^RED%^The voice of Akra'Mashul rings out in your head: %^BOLD%^%^BLACK%^You fool!  You have failed me, "
            "look how hurt you are!  How dare you unwield my might, get back up and fight!%^RESET%^");
        remove_property("enchantment");
        return 1;
    }

    switch(random(42))
    {
    case 0..10:
        tell_object(ETO,"%^BOLD%^%^BLACK%^The voice of Akra'Mashul haunts your mind as you unwield the sword.");
        break ;
    case 11..20:
        tell_object(ETO,"%^BOLD%^%^MAGENTA%^Feelings of dismay flood your mind as Akra'Mashul's soothing voice begs you to give it more glory.");
        break ;
    case 21..30:
        tell_object(ETO,"%^BOLD%^%^RED%^Visions of blood fills your mind as you try to unwield the sword.");
        break ;
    case 31..40:
        tell_object(ETO,"%^RESET%^MAGENTA%^Akra'Mashul purrs to you, her hilt reluctant to leave your hands.");
        break ;
    case 41:
        tell_object(ETO,"%^BOLD%^%^RED%^Akra'Mashul snarls angrily, her voice echoing in your head as pain floods through "
            "your body:%^BOLD%^%^BLACK%^You fool!  I was not done yet!  How dare you take my glory from me!");
        ETO->do_damage("torso",random(50)+25);
        break ;
    }

    charm = 0;
    remove_property("enchantment");
    return 1;
}


int hit_func(object target)
{
    object ob, ob2;

    if(!objectp(target)) return 0;
    if(!objectp(ETO)) return 0;

    if(random(1000) < ((TO->query_property("enchantment") + 1) * 3 * 10 )) //50% at highest enchantment, per other klauth weapons
    {
        switch(random(6))
        {
        case 0:

            tell_room(EETO,"%^BOLD%^BLACK%^The sword takes on a life of its own as it lashes out at "+target->QCN+"!%^RESET%^",({target,ETO}));
            tell_object(ETO,"%^BOLD%^%^BLACK%^The sword takes on a life of its own as it lashes out at "+target->QCN+", its energy filling your mind with images of rage as the sword reaches for her mark!%^RESET%^");
            tell_object(target,"%^BOLD%^%^BLACK%^The sword in "+ETO->QCN+"'s hand takes on a life of its own as it lashes out at you!%^RESET%^");
            return roll_dice(6,10)+2;

        case 1..2:

            tell_room(EETO,"%^RESET%^%^MAGENTA%^"+ETO->QCN+" dances deftly around "+target->QCN+" as the sword leads "+ETO->QO+" in for another attack!",({target,ETO}));
            tell_object(ETO,"%^RESET%^%^MAGENTA%^You dance with agility around "+target->QCN+" as the sword leads you in for another attack!%^RESET%^");
            tell_object(target,"%^RESET%^%^MAGENTA%^"+ETO->QCN+" dances with ease around you as the sword leads "+ETO->QO+" in for another attack!%^RESET%^");
            ETO->execute_attack();
            target->do_damage("torso",roll_dice(3,10)+1);
            break;

        case 3:
            tell_room(EETO,"%^BOLD%^%^BLACK%^The sword darkens as the shadows begin to swirl and take on a humanoid form!");
            ob2 = new("/d/islands/common/obj/new/smon.c");
            ob2->setup_shadow(ETO);
            ob2->move(EETO);
            break;

        case 4:

            tell_room(EETO,"%^BOLD%^%^BLACK%^The sword sucks in the darkness from around it and hurtles it at "+target->QCN+"!",({target,ETO}));
            tell_object(ETO,"%^BOLD%^%^BLACK%^The sword sucks in the darkness from around it and hurtles it at "+target->QCN+"!%^RESET%^");
            tell_object(target,"%^BOLD%^%^BLACK%^The sword in "+ETO->QCN+" hand sucks up the darkness from around it and hurtles it at you!");
            target->set_paralyzed(18,"You are trying to get to your feet.");
            if(!random(5)) { target->set_blind(1); }
            else { target->set_paralyzed(3+random(4),"%^BOLD%^%^BLACK%^You are trying to remove the orb of darkness from around you!"); }
            break;

        case 5:

            tell_object(ETO,"%^BOLD%^%^BLACK%^Akra'Mashul's voice cackles with glee in your mind as it and strikes out at "+target->QCN+"!%^RESET%^");
            return roll_dice(5,10)+1;
      }
   }
}


void heart_beat()
{
    object *livings,target,temp,obj,ob,sm,nombre;
    int i,j;

    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(ETO->is_room()) return;

    if(ETO->id("akrasheath") && sm=present("smon",environment(EETO)))
    {
        tell_room(environment(EETO),"%^BOLD%^%^BLACK%^The shadow no longer feels the pull of its master and begins to break apart, disappearing back into that from which it came!");
        sm->move("/d/shadowgate/void");
        sm->remove();
        return;
    }

    if(ETO->id("akrasheath")) { charm=0; return; }

    if(!ETO->id("akrasheath") && EETO->is_player() && burn == 0)
    {
        TO->move(EETO);
        tell_room(EETO,"%^BOLD%^%^RED%^The sword breaks free of its confines and appears back at "+ETO->QCN+"'s side!",ETO);
        tell_object(ETO,"%^RESET%^%^MAGENTA%^The swords thoughts fill your mind: %^RED%^You'll not get rid of me so easily, do you think that will hold me?  Next time I shall burn whatever confines you place me in!%^RESET%^",EETO);
        burn = 1;
        return ;
    }

    else if(EETO->is_player()&&burn==1)
    {
        temp = ETO;
        TO->move(EETO);
        tell_room(EETO,"%^RESET%^%^RED%^The "+temp->query_name()+" bursts into %^BOLD%^%^RED%^flames %^RESET%^%^RED%^as"
            " a %^BOLD%^%^BLACK%^darkly gl%^MAGENTA%^o%^BLACK%^w%^MAGENTA%^i%^BLACK%^ng sword %^RESET%^%^RED%^appears"
            " at "+ETO->QCN+"'s side!",ETO);
        tell_object(ETO,"%^RESET%^%^RED%^The "+temp->query_name()+" bursts into %^BOLD%^%^RED%^flames %^RESET%^%^RED%^and disappears, leaving the sword back at your side!%^RESET%^",EETO);
        burn = 0;
        temp->remove();
        return ;
    }

    if(EETO->is_player()) return;
    if(!objectp(EETO)) return;

    nombre = (string)ETO->query_name();
    livings = ({});
    livings = filter_array(all_living(EETO),"is_non_immortal_player",FILTERS_D);

    j = sizeof(livings);

    if(random(1000) < 5)
    {
        for(i=0;i<j;i++)
        {
            if((string)livings[i]->query_gender()=="male" && (string)livings[i]->query_name() != nombre)
            {
                switch(random(4))
                {
                case 0:
                    tell_object(livings[i],"%^BOLD%^%^BLACK%^The sword calls to you.. yes, just hold it, yes!  We can be great together!%^RESET%^",ETO);
                    break;
                case 1:
                    tell_object(livings[i],"%^BOLD%^%^BLACK%^Visions of you standing over a mountain of fallen enemies enter your mind.. At your side is the sword, Akra'Mashul!%^RESET%^",ETO);
                    break;
                case 2:
                    tell_object(livings[i],"%^BOLD%^%^BLACK%^The voice of Akra'Mashul enters your mind '%^RED%^Take me from this weak fool.  He is not worthy, only you and I can be great together.%^RESET%^",ETO);
                    break;
                case 3:
                    tell_object(livings[i],"%^BOLD%^%^BLACK%^The voice of Akra'Mashul enters your mind '%^RED%^Please, hold me.  Just hold me.. Take me now, for you know you are more powerful!%^RESET%^",ETO);
                    break;
                }
            }
            else if((string)livings[i]->query_gender() == "female")
            {
                if(charm==1) { return ; }
                if(livings[i]->query_bound() || livings[i]->query_unconscious())
                {
                    switch(random(100))
                    {
                    case 0..2:
                        tell_object(ETO,"%^BOLD%^%^BLACK%^The sword seems to be laughing at your side: %^RED%^Ah ha ha!  THAT is a challenge?  Look at the simple fool!  Kill her and be done with it, she is not worthy of our notice.%^RESET%^",livings[i]);
                        break;
                    case 3..99:
                        break;
                    }

                    ETO->remove_attacker(livings[i]);
                    return ;
                }

                if(!TO->query_wielded())
                {
                    switch(random(100))
                    {
                    case 0..2:
                        tell_room(livings[i],"%^BOLD%^%^BLACK%^The sword begins to glow darkly as %^RESET%^%^BLUE%^blue arcs %^BOLD%^%^BLACK%^are emmitted from it!",ETO);
                        tell_object(ETO,"%^BOLD%^%^BLACK%^The sword purrs to you: %^RED%^Grasp me now!  Let us begone with the female threat, I am your only true love... KILL HER..I WILL NOT REST UNTIL SHE IS DEAD!!!%^RESET%^",livings[i]);
                        ETO->do_damage("torso",roll_dice(3,10));
                        ETO->add_attacker(TO);
                        ETO->continue_attack();
                        break;
                    case 3:
                        tell_room(livings[i],"%^BOLD%^%^BLACK%^The sword at "+ETO->QCN+"'s side begins to shake violently!",ETO);
                        tell_object(ETO,"%^BOLD%^%^BLACK%^The sword at your side begins to shake violently as it screams to you: %^RED%^I will not let you rest until I am in your hands, kill the wench I sense!!!%^RESET%^",livings[i]);
                        ETO->do_damage("torso",roll_dice(3,10));
                        ETO->add_attacker(TO);
                        ETO->continue_attack();
                        break;
                    case 4..99:
                        break;
                    }
                }
                else
                {
                    if(sizeof(ETO->query_attackers()) == 0)
                    {
                        tell_object(ETO,"%^BOLD%^%^BLACK%^The sword in your hand snarls: %^RED%^Now we get to kill her!%^RESET%^");
                        if((random(4)+13)>ETO->query_stats("charisma"))
                        {
                            livings[i]->add_attacker(ETO);
                            ETO->add_attacker(livings[i]);
                            ETO->force_me("kill attacker");
                            return;
                        }
                        else
                        {
                            tell_object(ETO,"%^BOLD%^%^BLACK%^You resist the charms of the sword and refuse to attack the female!%^RESET%^");
                            charm = 1;
                            return ;
                        }
                    }

                    return ;
                }
            }
        }
    }
}


int save_me(string fname)
{
    int enchanted_to;
    int ret;

    if(enchanted_to = query_property("enchantment"))
    {
        remove_property("enchantment");
        ret = ::save_me(fname);
        set_property("enchantment",enchanted_to);
        while(query_property("enchantment") != enchanted_to )
        {
            set_property("enchantment",enchanted_to);
        }
        return ret;
    }
    else
    {
        return ::save_me(fname);
    }
}
