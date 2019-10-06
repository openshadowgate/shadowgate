#include <std.h>
#include <clock.h>
#include <rooms.h>
#include <new_exp_table.h>
#include <objects.h>
#include <daemons.h>

inherit DAEMON;
#define DEDICATIONS (["way of the shadow" : "%^BOLD%^%^BLACK%^Way of The Sh%^BOLD%^%^WHITE%^a%^BOLD%^%^BLACK%^d%^BOLD%^%^WHITE%^o%^BOLD%^%^BLACK%^w%^RESET%^",\
                      "way of the fist" : "%^BOLD%^%^WHITE%^Way of The F%^BOLD%^%^YELLOW%^i%^BOLD%^%^WHITE%^st%^RESET%^",\
                      "way of the elements" : "%^BOLD%^%^RED%^Way of The %^BOLD%^%^WHITE%^E%^BOLD%^%^RED%^l%^BOLD%^%^CYAN%^e%^BOLD%^%^WHITE%^m%^BOLD%^%^RED%^e%^BOLD%^%^CYAN%^n%^BOLD%^%^WHITE%^t%^BOLD%^%^RED%^s%^RESET%^",\
                      "grandmaster of the way" : "%^BOLD%^%^BLUE%^Grandmaster of the Way"])
#define RED     "%^RED%^"
#define GREEN   "%^GREEN%^"
#define BLUE    "%^BLUE%^"
#define MAGENTA "%^MAGENTA%^"
#define CYAN    "%^CYAN%^"
#define WHITE   "%^WHITE%^"
#define YELLOW  "%^YELLOW%^"
#define BOLD    "%^BOLD%^"
#define RESET   "%^RESET%^"
#define AL_COLOR ({"%^BOLD%^%^YELLOW%^", "%^BOLD%^%^WHITE%^", "%^WHITE%^","%^BOLD%^%^BLUE%^", "%^BLUE%^", "%^CYAN%^","%^ORANGE%^", "%^BOLD%^%^RED%^", "%^RED%^" })
#define MINLEN 60
#define HRLEN 3600
#define DAYLEN 86400
/*#define SCORE_LAYOUT (["position" : "query_position", "gender" : "query_gender", "alignment" : "query_alignment", "race" : ({"query_race", "query("+"subrace"+")"}),\
                       "height" : "query_height", "weight" : "query_weight", "class" : "query_classes", "level" : ({"query_class_level", "query_character_level"}),\
                       "Exp to Next" : "", "Exp" : "query_exp"])*/

//#define SAVING_D ("/daemon/saving_d")

string posxxx;
mapping tmp_map;

object shape;

int cmd_score(string str)
{

    string melnmarn,title,title_tmp,race_var,hit,encumbrance,hunger,thirst,position;
    string sober,*classes,showexp,classstring,levelstring,stamina,way,age;
    string *spell_domains;
    int temp1, temp2, max,exp,expnext,i;
    object targ;
    if (str && avatarp(TP)) {
        if(!objectp(TP)) { return 0; }
        posxxx = lower_case((string)TP->query_position());
        if(posxxx == "builder" || posxxx == "apprentice")
        {
            tell_object(TP,"You cannot use this command as a builder or apprentice.");
            return 1;
        }
        if(!(targ = find_player(str)))
        {
            return notify_fail("That person is not available for scoring.\n");
        }

        else if ((targ = find_player(str))) {
            if((int)targ->query_level() > (int)TP->query_level())
            {
                return notify_fail("That person is not available for scoring.\n");
            }
        }
   } else {
      targ = TP;
   }
   if(targ->query_ghost() && base_name(ETP) != DEATH_ROOM) {
      notify_fail("You cannot do that in an immaterial state.\n");
      return 0;
   }
   if(str && !avatarp(TP)) {
      notify_fail("See also <skills> and <stats>\n");
      return 0;
   }
   if((string)targ->query_race() == "unborn" || (int)targ->query("score_inaccessible")) {
      notify_fail("You need to finish your character first.\n");
      return 0;
   }

   position = targ->query_position();
   //if(targ->query("advanced_player") && position != "high mortal") position = "advanced player";

   if(OB_ACCOUNT->is_high_mortal((string)targ->query_true_name()) && position != "high mortal" && !avatarp(targ)) { position += " (high mortal)"; }

   else if(targ->query("ex_hm") && (position != "high mortal")) position +=" (ex-hm)";
   max = targ->query_formula();
   temp1 = targ->query_stuffed();
   temp2 = max / 6;
   if(temp1 < temp2) hunger = BOLD+RED+"Starving";
   else if(temp1 < (temp2 * 2)) hunger = RED+"Very hungry";
   else if(temp1 < (temp2 * 3)) hunger = RED+"Really hungry";
   else if(temp1 < (temp2 * 4)) hunger = YELLOW+"Hungry";
   else if(temp1 < (temp2 * 5)) hunger = GREEN+"Not hungry";
   else hunger = BOLD+GREEN+"Stuffed";
   temp1 = targ->query_quenched();
   temp2 = max / 6;
   if(temp1 < temp2) thirst = BOLD+RED+"Parched             ";
   else if(temp1 < (temp2 * 2)) thirst = RED+"Very thirsty        ";
   else if(temp1 < (temp2 * 3)) thirst = RED+"Really thirsty      ";
   else if(temp1 < (temp2 * 4)) thirst = YELLOW+"Thirsty             ";
   else if(temp1 < (temp2 * 5)) thirst = GREEN+"Not thirsty         ";
   else thirst = BOLD+GREEN+"Quenched            ";
   temp1 = targ->query_intox();
   temp2 = max / 5;
   if(temp1 == 0) sober = GREEN+"Sober          ";
   else if(temp1 < temp2) sober = YELLOW+"Buzzed         ";
   else if(temp1 < (temp2 * 2)) sober = YELLOW+"Tipsy          ";
   else if(temp1 < (temp2 * 3)) sober = RED+"Lipped         ";
   else if(temp1 < (temp2 * 4)) sober = RED+"Drunk          ";
   else sober = BOLD+RED+"Wasted         ";

   age = targ->query_real_age()+" ("+targ->query_real_age_cat()+")";
   classes = targ->query_classes();

   if(!avatarp(targ))
   {
       if(targ->query("new_class_type"))
       {
           exp     = targ->query_exp();
           expnext = EXP_NEEDED[targ->query_character_level() + 1];
           expnext = expnext - exp;
           //showexp = ""+expnext+"";
           showexp = english_number(expnext);
       }
       else
       {
          exp = targ->get_general_exp(classes[0]);
          expnext = "/adm/daemon/advance_d"->get_exp(targ->query_class_level(classes[0])+1,classes[0], targ);
          expnext = expnext-exp;
          showexp = ""+expnext;
          for(i=1;i<sizeof(classes);i++)
          {
             exp = targ->get_general_exp(classes[i]);
             expnext = "/adm/daemon/advance_d"->get_exp(targ->query_class_level(classes[i])+1,classes[i], targ);
             expnext = expnext - exp;
             showexp += "/"+expnext;
          }
       }
   }
   else
      expnext = 0;

   exp = targ->query_exp();

   if(targ->query("new_class_type"))
   {
       expnext = 0;
       classstring = "";
       levelstring = "";

       temp1 = strlen(implode(classes,"/"));
       for(i=0;i<sizeof(classes);i++)
       {
           if(temp1 > 24)
           {
               if(strlen(classes[i]) > 7) { classstring += "/"+arrange_string(classes[i],7); }
               else { classstring += "/"+classes[i]; }
           }
           else { classstring += "/"+classes[i]; }
           levelstring += "/"+targ->query_class_level(classes[i]);
           expnext += targ->query_class_level(classes[i]);
       }
       classstring = replace_string(classstring,"/","",1);
       levelstring = replace_string(levelstring,"/","",1);
       if(expnext != (int)targ->query_character_level()) levelstring += " (%^RESET%^"+targ->query_character_level()+"%^BOLD%^%^GREEN%^)";
       if(targ->query("scaledlevel")) { levelstring += " %^RED%^(scaled)%^RESET%^"; }
   }
   else
   {
        classstring = classes[0];
        levelstring = ""+targ->query_class_level(classes[0]);
        for(i=1;i<sizeof(classes);i++) {
            levelstring += "/"+targ->query_class_level(classes[i]);
            classstring += "/"+classes[i];
        }
        if (targ->get_dual_class()) {
            classstring += "(dual classed)";
        }
   }

   temp1 = targ->query_hp();
   temp2 = targ->query_max_hp();
   hit = RESET + sprintf("%%^WHITE%%^%s%%^GREEN%%^/%%^BOLD%%^%%^WHITE%%^%s",english_number(temp1),english_number(temp2));
   temp1 = targ->query_internal_encumbrance();
   temp2 = targ->query_max_internal_encumbrance();
   encumbrance= RESET + sprintf("%%^WHITE%%^%d%%^GREEN%%^/%%^BOLD%%^%%^WHITE%%^%d",temp1,temp2);
   if(!title_tmp = targ->query_title()) title_tmp = "You are invisible";
   temp1 = strlen(title_tmp);
   temp2 = 78 - temp1;
   temp1 = temp2 / 2;
   title = "%^RESET%^%^GREEN%^--=%^BOLD%^<%^WHITE%^ "+title_tmp+ " %^BOLD%^%^GREEN%^>%^RESET%^%^GREEN%^=--%^RESET%^";
   spell_domains = targ->query_divine_domain();

   race_var = capitalize(targ->query_race());

   if(targ->query("subrace"))
   {
       if(strsrch(targ->query("subrace"),targ->query_race())<0)
           race_var = capitalize(targ->query("subrace"))+" "+race_var;
       else
           race_var = capitalize(targ->query("subrace"));
   }

   if(targ->is_undead())
   {
       if(targ->is_vampire())
           race_var = "Vampire "+race_var;
       else
           race_var = "Undead "+race_var;
   }

  if(objectp(shape = TP->query_property("shapeshifted")))
  {
      race_var = (string)shape->query_shape_race();
      race_var = capitalize(race_var);
  }

    way = targ->query("monk way");
    if(FEATS_D->usable_feat(targ,"grandmaster of the way")) { way = "grandmaster of the way"; }
    classstring = replace_string(classstring,"_"," ");

   stamina = targ->query_condition_string();
   write("\n%^BOLD%^%^GREEN%^"+title);
   melnmarn = sprintf("  %sPosition %s---- %s: %s%-20s       %sGender %s-- %s: %s%s",BOLD+GREEN,RESET+WHITE,GREEN,BOLD+CYAN,capitalize(position),BOLD+GREEN,RESET+WHITE,GREEN,CYAN,capitalize(targ->query_gender()));
   write(melnmarn);
   melnmarn = sprintf("  %sAlignment %s--- %s: %s%-20s       %sRace %s---- %s: %s",BOLD+GREEN,RESET+WHITE,GREEN,AL_COLOR[(int)targ->query_alignment()-1],capitalize(targ->query_al_title(targ->query_alignment())),BOLD+GREEN,RESET+WHITE,GREEN,race_var);
   write(melnmarn);
   melnmarn = sprintf("  %sHeight %s------ %s: %s%-3d inches                 %sWeight %s-- %s: %s%-3d pounds",BOLD+GREEN,RESET+WHITE,GREEN,YELLOW,targ->query_player_height(),BOLD+GREEN,RESET+WHITE,GREEN,YELLOW,targ->query_player_weight());
   write(melnmarn);
   melnmarn = sprintf("  %sClass %s------- %s: %s%-26s %sLevel %s--- %s: %s%s",BOLD+GREEN,RESET+WHITE,GREEN,BOLD+MAGENTA,classstring,BOLD+GREEN,RESET+WHITE,GREEN,BOLD+GREEN,levelstring);
   write(melnmarn);
   melnmarn = sprintf("  %sExp to Next %s- %s: %s%-20s       %sExp %s----- %s:%s %s",BOLD+GREEN,RESET+WHITE,GREEN,BOLD+CYAN,showexp,BOLD+GREEN,RESET+WHITE,GREEN,BOLD+CYAN,english_number(exp));
   write(melnmarn);
   tmp_map = ([]);
   tmp_map = targ->query_XP_tax();
   showexp = "";
   if(mapp(tmp_map))
   {
       if(mapp(tmp_map["improvement"]))
       {
           if(tmp_map["improvement"]["amount"] > 0)
           {
               showexp += english_number(tmp_map["improvement"]["amount"]);
           }
           if(tmp_map["death"]["percent"] > 0)
           {
               if(showexp != "") showexp += "%^RESET%^%^WHITE%^ / ";
               showexp += "%^BOLD%^%^RED%^"+ tmp_map["death"]["percent"]+"% death tax%^RESET%^";
           }
           if(showexp != "")
           {
               melnmarn = sprintf("  %sExp Tax %s----- %s: %s%s", BOLD+GREEN,RESET+WHITE,GREEN,BOLD+CYAN,showexp);
               write(melnmarn);
           }
       }
   }
   if(targ->query_diety() && targ->query_sphere())
        write(sprintf("  %sDeity %s------- %s: %s%-20s       %sSphere %s-- %s:%s %-10s",BOLD+GREEN,RESET+WHITE,GREEN,BOLD+BLUE,capitalize(targ->query_diety()),BOLD+GREEN,RESET+WHITE,GREEN,BOLD+BLUE,arrange_string(""+capitalize(targ->query_sphere())+"",18)));
   else if(targ->query_diety() && (!targ->query_sphere() || undefinedp(targ->query_sphere())))
        write(sprintf("  %sDeity %s------- %s: %s%-20s",BOLD+GREEN,RESET+WHITE,GREEN,BOLD+BLUE,capitalize(targ->query_diety())));
   if (sizeof(spell_domains) == 3)
       write(sprintf("  %sDomain %s------ %s: %s%s/%-20s",BOLD+GREEN,RESET+WHITE,GREEN,BOLD+BLUE,capitalize(spell_domains[0]),capitalize(spell_domains[1]),capitalize(spell_domains[2])));
   else if (sizeof(spell_domains) == 2)
       write(sprintf("  %sDomain %s------ %s: %s%s/%-20s",BOLD+GREEN,RESET+WHITE,GREEN,BOLD+BLUE,capitalize(spell_domains[0]),capitalize(spell_domains[1])));
   else if (sizeof(spell_domains) == 1)
       write(sprintf("  %sDomain %s------ %s: %s%-20s",BOLD+GREEN,RESET+WHITE,GREEN,BOLD+BLUE,capitalize(spell_domains[0])));

   if (targ->query_school() && targ->query("warlock heritage"))
 write(sprintf("  %sSpecialty %s--- %s: %s%-20s       %sHeritage %s %s: %s%-16s",BOLD+GREEN,RESET+WHITE,GREEN,BOLD+RED,targ->query_school(),BOLD+GREEN,RESET+WHITE,GREEN,BOLD+RED,targ->query("warlock heritage")));
   else if (targ->query_school())
 write(sprintf("  %sSpecialty %s--- %s: %s%-20s",BOLD+GREEN,RESET+WHITE,GREEN,BOLD+CYAN,targ->query_school()));
   else if (targ->query("warlock heritage"))
 write(sprintf("  %sHeritage %s---- %s: %s%-12s",BOLD+GREEN,RESET+WHITE,GREEN,BOLD+RED,targ->query("warlock heritage")));

   if (targ->query_discipline() && targ->query_fighter_style())
 write(sprintf("  %sDiscipline %s-- %s: %s%-20s       %sStyle %s--- %s: %s%-16s",BOLD+GREEN,RESET+WHITE,GREEN,BOLD+RED,targ->query_discipline(),BOLD+GREEN,RESET+WHITE,GREEN,BOLD+RED,targ->query_fighter_style()));
   else if (targ->query_discipline())
 write(sprintf("  %sDiscipline %s-- %s: %s%-20s",BOLD+GREEN,RESET+WHITE,GREEN,BOLD+CYAN,targ->query_discipline()));
   else if (targ->query_fighter_style())
 write(sprintf("  %sStyle %s------- %s: %s%-12s",BOLD+GREEN,RESET+WHITE,GREEN,BOLD+RED,targ->query_fighter_style()));
   if(stringp(way))
 write(sprintf("  %sDedication %s-- %s: %s%-20s",BOLD+GREEN,RESET+WHITE,GREEN,BOLD+CYAN,DEDICATIONS[way]));

   melnmarn = sprintf("  %sHitPoints %s--- %s: %s%-64s       %sCarrying# %s%s: %s",BOLD+GREEN,RESET+WHITE,GREEN,BOLD+WHITE,hit,GREEN,RESET+WHITE,GREEN,encumbrance);
   write(melnmarn);
   melnmarn = sprintf("  %sArmor Class %s- %s: %s%-15s            %sBase Hit %s-%s: %s",BOLD+GREEN,RESET+WHITE,GREEN,BOLD+WHITE,""+BONUS_D->effective_ac(targ)+" + "+BONUS_D->ac_bonus(targ,targ)+"",GREEN,RESET+WHITE,GREEN,BOLD+WHITE+""+"/daemon/bonus_d.c"->new_bab(1, targ));
   write(melnmarn);
   //melnmarn = sprintf("  %sQuest Points %s %s: %s%-20d       %sQuests %s-- %s: %s%-10d",BOLD+GREEN,RESET+WHITE,GREEN,WHITE,questsleft,BOLD+GREEN,RESET+WHITE,GREEN,WHITE,quests);
   //write(melnmarn);
   melnmarn = sprintf("  %sCopper %s------ %s: %s%-20s       %sSilver %s-- %s: %s%-10s",BOLD+GREEN,RESET+WHITE,GREEN,WHITE,english_number(targ->query_money("copper")),BOLD+GREEN,RESET+WHITE,GREEN,WHITE,english_number(targ->query_money("silver")));
   write(melnmarn);
   melnmarn = sprintf("  %sElectrum %s---- %s: %s%-20s       %sGold %s---- %s: %s%-10s",BOLD+GREEN,RESET+WHITE,GREEN,WHITE,english_number(targ->query_money("electrum")),BOLD+GREEN,RESET+WHITE,GREEN,WHITE,english_number(targ->query_money("gold")));
   write(melnmarn);
   melnmarn = sprintf("  %sPlatinum %s---- %s: %s%-20s       %sAge %s----- %s: %s%s",BOLD+GREEN,RESET+WHITE,GREEN,WHITE,english_number(targ->query_money("platinum")),BOLD+GREEN,RESET+WHITE,GREEN,WHITE,age);

   write(melnmarn);
   melnmarn = sprintf("  %sIntox Level %s- %s: %-20s            %sHunger %s-- %s: %s",BOLD+GREEN,RESET+WHITE,GREEN,sober,BOLD+GREEN,RESET+WHITE,GREEN,hunger);
   write(melnmarn);
   melnmarn = sprintf("  %sThirst %s------ %s: %s%-20s       %sPoison %s-- %s: %s",BOLD+GREEN,RESET+WHITE,GREEN,WHITE,thirst,BOLD+GREEN,RESET+WHITE,GREEN,(POISON_D->is_poisoned(targ) > 0) ? RED+"Poisoned" : GREEN+"Not poisoned" );
   write(melnmarn);

   melnmarn = sprintf("  %sCondition %s--- %s: %s%-20s       %sBody Type %s%s: %s",BOLD+GREEN,RESET+WHITE,GREEN,BOLD+MAGENTA,stamina,BOLD+GREEN,RESET+WHITE,GREEN,YELLOW+targ->query_body_type() );
   write(melnmarn);
   melnmarn = sprintf("  %sHair Color %s-- %s: %s%-20s       %sEye Color %s%s: %s",BOLD+GREEN,RESET+WHITE,GREEN,BOLD+WHITE,targ->query_hair_color(),BOLD+GREEN,RESET+WHITE,GREEN,BOLD+WHITE+targ->query_eye_color() );
   write(melnmarn);

   race_var = "";
   if(targ->get_pk_death_flag())
   {
       race_var = "No";
   }
   if(targ->query("no pk"))
   {
       race_var = "No";
   }
   if(race_var != "No") race_var = "Yes";
   melnmarn = sprintf("  %sPK Eligible %s- %s: %s%-20s       %sPlay Time %s%s: %s",BOLD+GREEN,RESET+WHITE,GREEN,BOLD+WHITE,race_var,BOLD+GREEN,RESET+WHITE,GREEN,BOLD+WHITE+parse_time((int)targ->query_age()) );
   write(melnmarn);


  if (targ->get_pk_death_flag()) {
    melnmarn=sprintf("%s under PK protection.",(targ==TP)?"You are":targ->query_name()+" is");
    if (targ->query_down_time()) melnmarn += "\nThis protection is due to a recent return, and will expire on: "+ctime(targ->query_down_time())+".";
   	else
	{
// Generate a random drift for the PK estimate if they're not an immortal.
		if (avatarp(TP))
		{
			i=0;
  		}
		else
		{
			if (undefinedp(i=(int)targ->query_property("pk_drift")))
			{
				targ->set_property("pk_drift",i=random(59)-29);
			}
		}
	// Figure out which is the limiting factor on that flag.
	temp1 = (int)targ->query("pk_death_age")*2 + PK_DEATH_FLAG_LOGIN_TIME;
	temp1 -= (int)targ->query_player_age()*2;

  	temp2=(int)targ->query_death_time()-time();

	melnmarn += sprintf("\nThis Pk Flag will expire sometime before "+
	"%s", ctime((int)targ->query_death_time() + (i * 60)));
  }
  write(melnmarn);
  }
   return 1;
}

void help() {
    write("
%^CYAN%^NAME%^RESET%^

score - show your characters score sheet");
    if(avatarp(TP)) write("
%^CYAN%^SYNTAX%^RESET%^

score [%^ORANGE%^%^ULINE%^TARGET%^RESET%^]");
    write(
        "
%^CYAN%^DESCRIPTION%^RESET%^

This command gives you overview of your character, listing many various facts about them.

%^CYAN%^SEE ALSO%^RESET%^

hp, stats, biography, money, inventory, eq
");
}
