/*
// File: query_idle_string.c
// From the people at Portals.
// Checks the idle time on an object and returns a nice string
// rather than just the total seconds.
// Might error if called on non-interactive objects.
*/

string query_idle_string(object ob)
{
    int days,hours,minutes,seconds;
    int idle;
    string str;

    str = "";

    if(!(idle = query_idle(ob)))
        return "0s";

    days = idle / 86400;
    idle = idle % 86400;

    hours = idle / 3600;
    idle = idle % 3600;

    minutes = idle / 60;
    seconds = idle % 60;

    if(days) str += days+"d ";
    if(hours) str += hours+"h ";
    if(minutes) str += minutes+"m ";
    if(seconds) str += seconds+"s";

    return str;
}
