#include <std.h>
#include <html_converter.h>
#define HTML_OUT "/d/save/wholist.html"
#define GEOMYIDAE_OUT "/d/save/wholist.gph"
inherit DAEMON;

/**
 * @file
 * @brief This true dameon writes list of online players for display outside of the game.
 */
int clean_up()
{
    return 1;
}

void write_who()
{
    string html, gph;
    object *people, *wizes, *players;
    string *peepnames=({});
    string peep;

    call_out("write_who",90);

    html="<!DOCTYPE html>
<html>
<head>
<link href=\"wholist.css\" rel=\"stylesheet\" type=\"text/css\">
</head>
<body>
";
    gph="[1|Back to the root|/|server|port]

Online:

";

    people = real_users();
    wizes = filter_array(people,
                         (:wizardp($1):));
    players = filter_array(people,
                           (:!wizardp($1):));
    peepnames+=map_array(wizes->query_title(),
                         (:"Staff: "+$1:));
    peepnames+=players->getWholeDescriptivePhrase();

    foreach(peep in peepnames)
    {
        if(!stringp(peep))
            continue;
        html+=CONVERTER->convertFromInput(peep)+"<br /><font color=\"#FFFFFF\">\n";
        gph+="  "+strip_colors(peep)+"\n";
    }
    html+="<br/><br/>
</body>
</html>";

    write_file(HTML_OUT,html,1);
    write_file(GEOMYIDAE_OUT,gph,1);

}

void create(){
    seteuid(getuid());
    write_who();
}
