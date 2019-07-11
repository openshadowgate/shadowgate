//	/bin/adm/_rid.c
//	from the Nightmare mudlib
//	the administrators command to get rid of players
//	created by Descartes of Borg 01 March 1993

#include <std.h>
#include <objects.h>
#include <security.h>
#include <bank.h>
#include <dirs.h>
#include <daemons.h>

#define BOAT_DIR "/d/shadow/virtual/sea/obj/boats/"
#define PRISON_D "/adm/daemon/prison_d.c"

inherit OB_USER;
void create() {
   seteuid(getuid());
}

string admins;

int do_actual_rid(object ridder, string str, string rid_type)
{
    object ob, ob2;
    int is_hm;
    int x,j;
    string *oldfiles;
    string who, msg, alias;
    if(!stringp(str)) return 0;
    str = lower_case(str);
    if(!objectp(ridder)) return 0;
    if(!member_group(geteuid(ridder), "law") && geteuid(PO) != UID_ROOT) return 0;
    if(member_group(str, "superuser")) 
    {
        notify_fail("Shyeah...NOT.\n");
        return 0;
    }
    ob = find_player(str);
    if(!ob && !user_exists(str)) 
    {
        tell_object(ridder, "No such player: "+capitalize(str)+".\n");
        return 0;
    }
    who = sprintf("%s/%s/%s", "/adm/save/users", str[0..0], str);
    seteuid(UID_ROOT);
    write("restoring "+who);
    restore_object(who);
    is_hm = high_mortalp(TO);
    if(rid_type == "default" || rid_type == "email" || rid_type == "ip")
    {
        msg = ridder->getenv("RID");
        if(stringp(msg) && !ridder->query_property("quiet rid")) message("rid",replace_string(msg,"$N", capitalize(str)),users());
    }
    if(!ob)
      if(ob) alias = ob->query("advance place");
      else alias = query("advance place");
    "daemon/room_d"->remove_room(alias);
    if(ob) ob->remove();
    if(ob)
    {
        seteuid(UID_DESTRUCT);
        destruct(ob);
        seteuid(getuid());
    }

    seteuid(UID_SAVEACCESS);
    if(rid_type == "immortal iced") rename(DIR_USERS+"/"+str[0..0]+"/"+str+".o", DIR_USERS+"/icedimmortals/"+str+".o");
    else if(rid_type == "newbie") rm(DIR_USERS+"/"+str[0..0]+"/"+str+".o");
    else rename(DIR_USERS+"/"+str[0..0]+"/"+str+".o", DIR_USERS+"/rid/"+str+".o");
    
    if(file_size(DIR_ACCOUNTS+"/"+str+".o") > -1) rm(DIR_ACCOUNTS+"/"+str+".o");
    if(file_size(DIR_POSTAL+"/"+str[0..0]+"/"+str+".o") > -1) rm(DIR_POSTAL+"/"+str[0..0]+"/"+str+".o");
    if(file_exists(BOAT_DIR+str+"boat.c")) rm(BOAT_DIR+str+"boat.c");
    oldfiles = get_dir("/inv/"+str+"/");
    for(x=0;x<sizeof(oldfiles);x++) 
    {
        j = rm("/inv/"+str+"/"+oldfiles[x]);
    }
    rmdir("/inv/"+str);
    //Was not previously cleaning up backup inventories
    //or removing the name from the backup mapping - corrected the issue - Saide, December 2016
    oldfiles = get_dir("/inv/backup_inv/"+str+"/");
    for(x=0;x<sizeof(oldfiles);x++) 
    {
        j = rm("/inv/"+str+"/"+oldfiles[x]);
    }
    rmdir("/inv/backup_inv/"+str);
    "/daemon/yuck_d.c"->remove_from_backup(str);
    //End of addition
    if (!is_hm)
        rm("/d/save/background/"+str);
    "/daemon/guilds_d.c"->delete_player(str);
    write(capitalize(str)+" is removed from "+mud_name()+".\n");
    seteuid(UID_LOG);
    log_file("rid", (string)this_player()->query_name()+" rid "+
	    str+": "+ctime(time())+"\n");
    "daemon/killing_d"->remove_all_bounties(lower_case(str));
    "daemon/save_d"->remove_name(lower_case(str));
    seteuid(getuid());
    if(PRISON_D->is_imprisoned(str)) 
    {
        PRISON_D->remove_player(str);
    }
    seteuid(UID_ROOT);
    BANK_D->cull_accounts();
    if(file_exists("/log/adm/ICQ/"+str+".log"))
    rename("/log/adm/ICQ/"+str+".log","/log/adm/ICQ/rid/"+str+".rid");
    seteuid(getuid());
    return 1;
}


int cmd_rid(string str)
{
    if(!member_group(geteuid(this_player()), "law") && geteuid(PO) != UID_ROOT) return 0;
    if(!str) 
    {
        notify_fail("Syntax: <rid [player]>\n");
        return 0;
    }
    do_actual_rid(TP, str, "default");
    return 1;
}

void help() {
   write( 
@EndText
	  Syntax: rid <name>
	  Effect: Deletes, nukes, wipes out and annhilates unwanted player <name>
	  See also: demote, promote, sponsor
EndText
	);
}

