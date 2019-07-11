//
// Based on Tristan's _dispell.c, changed to allow dispell <spell name> rather than number
//
#include <std.h>


inherit DAEMON;

int help();

int cmd_dispell(string str)
{
    string spell_name,spell_target,tmp,tmp1,tmp2,type;
    object *spells, *e_spells;
    int i,j, index, spell_num;

    spells = TP->query_property("dispellable spells");
    for(i=0;i<sizeof(spells);i++) {
        if(objectp(spells[i])) {
            if(!e_spells) {
                e_spells = ({spells[i]});
                continue;
            }
            e_spells += ({spells[i]});
        }
    }
    spells = e_spells;
   
    if (!pointerp(spells)) 
    {
        message("info","%^BOLD%^%^WHITE%^You have nothing listed as effecting you.",TP);
        return 1;
    }
  

    if (!str) 
    {
        j = sizeof(spells);
        message("info","%^CYAN%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-",TP);
        for (i=0;i<j;i++) 
        {
            if (objectp (spells[i])) 
            {
                message("info","%^BOLD%^%^BLUE%^"+sprintf("%2d",i)+".%^BOLD%^GREEN%^ "+spells[i]->querySpellDisplay(),TP);
            }
        }
        message("info","%^CYAN%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-",TP);
    return 1;
    }
    if(sizeof(spells))
    {
        if(sscanf(str,"%d",spell_num) == 1) {
            if(sizeof(spells) > spell_num && spell_num > -1) {
                if(!objectp(spells[spell_num])) return notify_fail("That "+
                "spell or power appears to have been lost.\n");

                message("info","%^CYAN%^You release your concentration.%^RESET%^", TP);
                spells[spell_num]->dest_effect();
                return 1;
            }
            else {
                return notify_fail("That's not a valid spell index.");
            }
        }
        else {

            if(sscanf(str,"%s on %s",spell_name,spell_target) == 2)             {}
            else if(sscanf(str,"%s",spell_name) == 1)                           { }
            else if(sscanf(str,"%d",spell_num) == 1)                            { }
        }
    }
    else
    {
        message("info","%^BOLD%^%^WHITE%^You have nothing listed as effecting you.",TP);
        return 1;
    }
    if(spell_name && spell_target)
    {               
        for (i=0;i<sizeof(spells);i++)
        {  
            if (objectp (spells[i])) 
            {
                if(spells[i]->query_target_object())
                {                    
                    if((string)spells[i]->query_spell_name() == spell_name && (string)spells[i]->query_target_object()->query_name() == spell_target)
                    {
                        if(!objectp(spells[i])) return notify_fail("That spell or power appears to have been lost.\n");
                        message("info","%^BOLD%^%^CYAN%^You release your concentration.", TP);
                        spells[i]->dest_effect();
                        return 1;
                    }
                    if(i == sizeof(spells) - 1) {
                        if((string)spells[i]->query_spell_name() == spell_name && (string)spells[i]->query_target_object()->query_name() != spell_target) {
                            return notify_fail("No "+spell_name+" spell affecting "+spell_target+" in your dispell list.\n");
                        }
                        if((string)spells[i]->query_spell_name() != spell_name) {
                            return notify_fail("No such spell "+spell_name+" in your dispell list.\n");
                        }
                    }
                }
                if(i == sizeof(spells) - 1) {
                    if((string)spells[i]->query_spell_name() == spell_name && (spell_target && !spells[i]->query_target_object())) {
                        return notify_fail(capitalize(spell_name)+" does not have a target!\n");
                    }
                    if((string)spells[i]->query_spell_name() == spell_name && (string)spells[i]->query_target_object()->query_name() != spell_target) {
                        return notify_fail("No "+spell_name+" spell affecting "+spell_target+" in your dispell list.\n");
                    }
                    if((string)spells[i]->query_spell_name() != spell_name) {
                            return notify_fail("No such spell "+spell_name+" in your dispell list.\n");
                    }
                }
            }
        }
        return 1;
    }

    if(spell_name)
    {               
        for (i=0;i<sizeof(spells);i++)
        {  
            if (objectp (spells[i])) 
            {
                if(!spells[i]->query_target_object())
                {    
                    if((string)spells[i]->query_spell_name() == spell_name)
                    {
                        if(!objectp(spells[i])) return notify_fail("That spell or power appears to have been lost.\n");
                        message("info","%^BOLD%^%^CYAN%^You release your concentration.", TP);
                        spells[i]->dest_effect();
                        return 1;
                    }
                    if(i == sizeof(spells) - 1) {
                        if((string)spells[i]->query_spell_name() != spell_name) {
                            return notify_fail("No such spell or power in your dispell list.\n");
                        }
                    }
                }
                if((string)spells[i]->query_spell_name() == spell_name && (spells[i]->query_target_object() && !spell_target)) {
                    return notify_fail("Which "+spell_name+" do you wish to dispel?\n");
                }
                if(i == sizeof(spells) - 1) {
                    if((string)spells[i]->query_spell_name() != spell_name) {
                        return notify_fail("No such spell or power in your dispell list.\n");
                    }
                }
            }
        
        }
        return 1;
    }

    return 1;

}


int
 help(){

   write(
"
%^CYAN%^NAME%^RESET%^

dispell - display and manage active spells

%^CYAN%^SYNTAX%^RESET%^

dispell [%^ORANGE%^%^ULINE%^NUM%^RESET%^|%^ORANGE%^%^ULINE%^NAME%^RESET%^]

%^CYAN%^DESCRIPTION%^RESET%^

Without an argument, this command will list all spells you have casted and that are currently active. The list will update as spells go up and down. It won't list, however, spells someone casted on you.

If you provide optional NUM argument or a spell NAME, you'll cancel that spell's effect. Note, after you do so the list will be renewed.

%^CYAN%^SEE ALSO%^RESET%^

cast, prepare, buff, bonuses

"
      );
   return 1;
}
