/*
  cooldowns.c
  
  This inheritable handles cooldowns on pretty much
  anything.
  
  -- Tlaloc --
*/

mapping cooldowns = ([  ]);

int notify_available(string str)
{
    tell_object(this_object(), "[%^CYAN%^COOLDOWN%^RESET%^] -- %^YELLOW%^" + capitalize(str) + "%^CYAN%^ is now available.%^RESET%^\n");
    return 1;
}

int cooldown(string str)
{
    if(mapping_member(cooldowns, str))
        return cooldowns[str];
    
    return 0;
}

int add_cooldown(string str, int delay)
{
    if(mapping_member(cooldowns, str))
        return 0;
    
    (mapping)cooldowns += ([ str : (time() + delay), ]);
    return 1;
}

int remove_cooldown(string str)
{
    if(!mapping_member(cooldowns, str))
        return 0;
    
    map_delete(cooldowns, str);
    notify_available(str);
    return 1;
}

void process_cooldowns(string key, int delay)
{
    if(delay <= time())
        remove_cooldown(key);
}

mapping query_cooldowns()
{
    return cooldowns;
}

void heart_beat()
{
    if(sizeof(cooldowns))
    {
        foreach(string key in (keys(cooldowns)))
            process_cooldowns(key, cooldowns[key]);
    }
    else
        cooldowns = ([  ]);
}
