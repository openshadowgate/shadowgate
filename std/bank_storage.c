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

    dir = DIR_ACCOUNTS+"/"+bank+"/"+who;
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

            ob->move(TO);
        }
    }
}

void save_inventory(string who, string bank)
{

}
