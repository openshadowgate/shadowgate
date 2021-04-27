//file 

#include <std.h>

inherit OBJECT;

void create(){
    ::create();
    set_name("tome");
    set_id(({"item","tome","tome","Heavy looking Tome",}));
    set_short("Heavy looking Tome");
    set_long(
@ITEM
On top of the altar is a large book, bound in black leather.  It has withstood time very well and is very legible.  You can make out the words on the pages to be written in an ancient language.

ITEM
        );
    set_weight(250);
    set_value(0);
    set("read","Klicto unim foshnip star flight. Shnips faks agyo benor stars.  Several aogouo aluoob Mystra kajm unim abul wag abilu abyoa da jal lajb ablu.  Akau helgabel agyo honor.
");
}