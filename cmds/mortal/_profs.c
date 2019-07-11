//_profs.c
// adapted to allow avatars/wizzes to check player profs added by *Styx* 8/2002

#include <std.h>
#include <daemons.h>
#define PROFS (["fighter":({3,5}),"cleric":({3,5}),"mage":({1,5}),"psion":({1,5}),"thief":({4,10})])

inherit DAEMON;

int check_permission(object ob,object player)
{
    string pos,name;
    if(!objectp(player)) { return 1; }
    name = (string)ob->query_true_name();
    pos = lower_case((string)player->query_position());
    if(pos == "builder" || pos == "apprentice")
    {
        if(lower_case(name) != lower_case((string)player->query_true_name()))
        {
            tell_object(player,"You can only use this on yourself.");
            return 0;
        }
    }
    return 1;
}

int cmd_profs(string str)
{
	//Made the code a little cleaner - Saide - 09/07
   	mapping skills, type,type2;
   	string *skillslist,theclass,*classes;
   	int i,j, level, total,profs1,profs2,num, used = 0;
   	object ob;

   	if(avatarp(TP)) 
	{
        if(!str || str=="me")   
		{
            str=(string)TP->query_name();
		}
	    if(!ob=find_player(str))
		{
            notify_fail(capitalize(str)+" is not in our reality.\n");
        	return 0;
     	}
		if(!check_permission(ob,TP)) 
		{ 
			return 1; 
		}
     		if(ob->query_invis() && ob->query_lowest_level() > 
		TP->query_lowest_level())
		{
      		notify_fail(capitalize(str)+" is not in our reality.\n");
        	return 0;
     	}
     	tell_object(TP,"%^BOLD%^%^MAGENTA%^The weapon profs for %^WHITE%^"
        	+capitalize(str)+" %^MAGENTA%^are as follows.");
   	}

   	if(!avatarp(TP)) 
	{
     		tell_object(TP,"%^MAGENTA%^Your weapon "+
		"proficiencies are as follows.");
		ob = TP;
	}

    if(TP->query("new_class_type"))
    {
        string *profs = ({ "light armor proficiency","medium armor proficiency","heavy armor proficiency",
            "shield proficiency","simple weapon proficiency","martial weapon proficiency","exotic weapon proficiency"});
        tell_object(TP,"%^BOLD%^You have the following weapon and armor proficiencies:\n");
        
        for(i=0;i<sizeof(profs);i++)
        {
            if(FEATS_D->usable_feat(ob,profs[i]))
            {
                tell_object(TP,"%^BOLD%^%^GREEN%^     "+capitalize(profs[i])+"");
            }
        }
        return 1;
    }

   	skills = ob->query_skills();
   	skillslist = keys(skills);
   	j = sizeof(skillslist);
   	tell_object(TP, ""+arrange_string("Weapon type",20)+
	arrange_string("prof. level", 15)+
	arrange_string("Weapon type",20)+
	arrange_string("prof. level", 15)+"\n");

   	for(i=0;i<j;i+=2)
	{
      	if(i+1 < j)
		{
	 		tell_object(TP, ""+
			arrange_string(skillslist[i],20)+
			arrange_string(skills[skillslist[i]]+"("+
			ob->query_profs(skillslist[i])+")", 15)+
			arrange_string(skillslist[i+1],20)+
			arrange_string(skills[skillslist[i+1]]+"("+
			ob->query_profs(skillslist[i+1])+")", 15));
			used += ob->query_profs(skillslist[i]);
			used += ob->query_profs(skillslist[i+1]);
			
      	}
		else
		{
	 		tell_object(TP, ""+
			arrange_string(skillslist[i],20)+
			arrange_string(skills[skillslist[i]]+
			"("+ob->query_profs(skillslist[i])+")", 15));
			used += ob->query_profs(skillslist[i]);
      	}
   	}

   	if(!ob->query("youth weapon"))
	{
      	ob->init_skills();
	}
	tell_object(TP,"\n%^CYAN%^Your parents taught you to use "+
	ob->query("youth weapon")+
	" and so you feel especially comfortable with it.");
   	if(ob->is_class("cleric") || ob->is_class("warlord"))
	{
      	type= "cleric";
	}
	else if( 	
	(ob->is_class("fighter") || ob->is_class("bard") ||
	ob->is_class("ranger") || ob->is_class("paladin") || 
	ob->is_class("antipaladin") || ob->is_class("cavalier")))
	{
      	type= "fighter";
   	} 
	else if((ob->is_class("thief")) || ob->is_class("assassin")) 
	{
      	type = "thief";
   	} 
	else 
	{
      	type= "mage";
   	}
   // This is just ugly -Ares
   	if(theclass = ob->get_dual_class())
   	{
       	classes = ob->query_classes();
       	classes -= ({ theclass });

       	if(ob->query_lowest_level() < ob->query_class_level(theclass))
       	{
           		if(theclass == "cleric") { type2 = "cleric"; }
           		else if(theclass == "fighter" || theclass == "bard" || 
			theclass == "ranger" || theclass == "paladin" || 
			theclass == "antipaladin" || theclass == "cavalier")
           		{
               		type2 = "fighter";
           		}
           		else if(theclass == "thief" || theclass == "assassin")
           		{ 
               		type2 = "thief";
           		}           
           		else { type2 = "mage"; }
           
           		num = PROFS[type2][0] * 
			((int)ob->query_level(theclass)/PROFS[type2][1] + 1);
           		theclass = classes[0]; // Just in case their first class happens 						  // to have more profs than their second

           		if(theclass == "cleric") { type2 = "cleric"; }
           		else if(theclass == "fighter" || theclass == "bard" || 
			theclass == "ranger" || theclass == "paladin" || 
			theclass == "antipaladin" || theclass == "cavalier")
           		{
               		type2 = "fighter";
           		}
           		else if(theclass == "thief" || theclass == "assassin")
           		{ 
               		type2 = "thief";
           		}
           		else { type2 = "mage"; }

           		profs2 = PROFS[type2][0] * 
			((int)ob->query_level(theclass)/PROFS[type2][1] + 1);

           		if(num > profs2) { profs2 = num; }
       	}
   	}

   	level = ob->query_lowest_level();
   	profs1 = PROFS[type][0] * (level/PROFS[type][1] + 1);
   	if(profs2 && profs2 > profs1)
   	{
       	total = profs2;
   	}
   	else { total = profs1; }
	i = total-used;
	if(i < 0)
	{
		i = 0;
	}
   	tell_object(TP,"%^YELLOW%^At your current level you have used "+
	"%^BOLD%^%^WHITE%^"+used+
	"/" +total+"%^RESET%^%^YELLOW%^ proficiency slots.  You have "+
	"%^BOLD%^%^WHITE%^"+i+"%^YELLOW%^ left, use them "+
	"wisely.");
   	return 1;
}

/*
int help(){
   if(avatarp(TP)) {
   write("Avatar/wizzes only:
         "You can check a player's profs by using <profs [name]>.  "
         "No argument or <profs me> will show your profs.\n\n");
   }
   write(
@OLI
   This command will list the weapon proficiencies that you know, the level
   of skill you've achieved with the weapon, and the number of profs you may
   currently learn.
OLI
   );
   return 1;
}
*/
