//      /adm/simul_efun/personal_log.c
//      from the Nightmare Mudlib
//      simulf efun allowing an immortal to log things securely
//      created by Descartes of Borg 09 july 1993

#include <dirs.h>
#include <security.h>

void personal_log(string str) {
    string dir, sub, where;

    seteuid(UID_ROOT);
    if(!str) return;
    sscanf(file_name(previous_object()), "/%s/%s/%*s", dir, sub);
    if(!sub) where = dir;
    else if(dir == "d" || dir == "realms") where = sub;
    else where = dir;
    write_file(DIR_PERSONAL_LOGS+"/"+where, str);
}
