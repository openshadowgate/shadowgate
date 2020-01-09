#include <std.h>
#include <dirs.h>
#include <bank.h>

#define CAP_PER_TIER 10

static cell_tier;

void create()
{
    ::create();
    cell_tier = 0;
}

set_cell_tier(int x)
{
    cell_tier = x;
}

int load_inventory(string who, string bank)
{
    string dir;
    string fname;
    string * files;
    string shebang;
    string objfile;
    object ob;
    int i;
    int rest_status;

    dir = DIR_ACCOUNTS+"/cells/"+bank+"/"+who;
    files = get_dir(path+"/ob*");

    for (i; i < sizeof(files); i++)
    {
        fname = dir+"/"+files[i];
        if(file_exists(fname))
        {
            shebang = read_file(fname,1,1);
            if (!stringp(shebang))
            {
                log_file("bank_cells","Empty object for "+who+" in "+bank);
                continue;
            }

            sscanf(fn, "#%s\n",objfile);
            if(!stringp(objfile))
            {
                log_file("bank_cells","Object not found for "+who+" in "+bank);
                continue;
            }

            objfile = "/"+objfile;
            if(catch(ob = new(objfile)))
            {
                log_file("bank_cells","Unable to load object for "+who+" in "+bank);
                continue;
            }

            if(!objectp(ob))
            {
                log_file("bank_cells","Unable to preserve object for "+who+" in "+bank);
                continue;
            }

            sscanf(fname,"%s.o",shebang);

            if(catch(rest_status = ob->restore_me(shebang)))
            {
                log_file("bank_cells","Unable to restore object for "+who+" in "+bank);
                continue;
            }

            move_object(ob,TO);
            //ob->move(TO);
        }
    }
}

void save_inventory(string who, string bank)
{
    string dir;
    object *inv;
    string *oldfiles;
    string fname;

    int i;

    mkdir(DIR_ACCOUNTS+"/cells/"+"/"+bank);
    mkdir(DIR_ACCOUNTS+"/cells/"+bank+"/"+who);

    dir = DIR_ACCOUNTS+"/cells/"+bank+"/"+who;

    inv = all_inventory(TO);
    oldfiles = get_dir(path+"/");
    seteuid(UID_ROOT);

    for(i=0; i<sizeof(oldfiles); i++)
        rm(dir+"/"+oldfiles[i]);

    setuid(getuid());

    for (i=0; i<sizeof(inv); i++)
    {
        fname = dir+"/ob"+i;
        inv[i]->save_me(fname);
    }
}

void show_list(object player)
{

}
