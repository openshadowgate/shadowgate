#include <std.h>
#include <daemons.h>
inherit DAEMON;

int cmd_weather() {
	WEATHER_D->weather();
	return 1;
}
void help() {
    write(
@MELNMARN
Syntax: <weather>
	This command will show the current area's weather in the
	following format:
	Climate:  < shows the area's climate type >
		Types are: Arctic, Tropical, Temperate and Desert.
	Season: < shows the current season >
		Types are: Summer, Autumn, Winter and Spring.
	Weather: < shows the current weather >
	Average Daily Temperature: < Shows the average temperature >
		Temperature is an average for that season.
	*NOTE* if the weather isn't set for this area, you will get
	a notice to that effect.
MELNMARN
);
}
