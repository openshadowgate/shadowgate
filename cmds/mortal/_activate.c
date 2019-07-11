// _activate.c  Based on _cast and _chant
#include <std.h>
#include <daemons.h>

inherit DAEMON;

#define FEATS_FILE "/cmds/feats/"

void help();
int cmd_activate(string str)
{
    string feat,arg,file;

    if(!objectp(TP)) { return 0; }
    if(!stringp(str))
    {
        tell_object(TP,"Activate what?");
        return 1;
    }

    if(!sscanf(str,"%s on %s",feat,arg))
    {
        if(!sscanf(str,"%s at %s",feat,arg))
        {
            if(!sscanf(str,"%s to %s",feat,arg))
            {
                feat = str;
            }
        }
    }

    if(!FEATS_D->has_feat(TP,feat)) 
    {
        tell_object(TP,"You do not have the feat "+feat+"");
        return 1;
    }
    if(!FEATS_D->usable_feat(TP,feat))
    {
        tell_object(TP,"You can't use this feat now.");
        return 1;
    }

    file = replace_string(feat," ","_");
    file = "_"+file+".c";
    file = FEATS_FILE+""+file+"";
    if(!file_exists(file))
    {
        tell_object(TP,"That feat does not seem to exist.");
        return 1;
    }
    if(!stringp(arg)) { new(file)->setup_feat(TP,arg); }
    else { new(file)->setup_feat(TP); }
    return 1;
}

void help()
{
    tell_object(TP,"Usage:  activate <feat>\n"
        "\tThis command will activate feats that run on durations.  "
        "See the help file for the individual feat to learn the "
        "appropriate syntax.");
    return;
}
    




 




/*
int cmd_chant(string str) {
  object targ, *armor;
  int i,j,flag;
  int align;
  string str2,tmp;
  string type, spell, tar;

  seteuid(getuid());
  if(!str){
    write("Cast what on/at what?");
    return 1;
  }
  type = "none";

  if (TP->query_casting()) {
    return notify_fail("You are already doing something!\n");
  }

  if(!sscanf(str,"%s on %s",str2,tar))
    if(!sscanf(str,"%s at %s",str2,tar))
      if(!sscanf(str,"%s to %s",str2,tar))
        str2 = str;

  align = TP->query_alignment();
  if(TP->is_class("bard") && (align==1 || align==3 || align==7 || align==9)){
    notify_fail("You cannot use your bard commands unless you are of a neutral alignment!\n");
    return 0;
  }

    if((TP->query_guild_level("cleric") > 0) || (TP->query_guild_level("druid") > 0)){
      type = "priest";
    } else if((TP->query_guild_level("mage") > 0) || (TP->query_guild_level("bard") > 0) ) {
      type = "wizard";
    }

  spell = replace_string(str2," ","_");
  if(type == "none"){
    write("You have no magic powers!");
    return 1;
  }

  if(type == "wizard"){
    flag = 0;
    armor = TP->all_armour();
    i = sizeof(armor);
    
    for(j=0;j<i;j++){
        if((string)armor[j]->query_type()!="clothing" && (string)armor[j]->query_type()!="bracer" && (string)armor[j]->query_type()!="ring" && !armor[j]->query_property("magicarmor")){
     if(TP->is_class("bard") &&((string)armor[j]->query_type() == "chain" || (string)armor[j]->query_type() == "leather")) continue;
   if ((string)armor[j]->query_type() == "sheath") continue;
    // Added for sheaths on 6/3/2001 by Garrett.
        flag = 1;
        break;
      }
    }
    if(flag){
      write("You cannot cast while wearing all that armor!");
      return 1;
    }
  }  
  tmp = "/cmds/"+type+"/_"+spell+".c";
  if(!file_exists(tmp)){
    tmp = "/cmds/"+type+"/_"+spell+".c";
    if(!file_exists(tmp)){
      write("Either that spell does not exist, or you do not know it!");
      return 1;
    }
  }
  if(!tar)
    tar = 0;
//  TP->set_casting(1);
  new(tmp)->wizard_interface(TP,tar);
  return 1;
}

void help(){
  write("Syntax: chant <spell name>\n\n" +
        "Invokes the magic of the spell <spell name>.\n");
}
*/