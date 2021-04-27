// tigger2.c
//
// Tigger's house

#include <std.h>
inherit VAULT;

void create(){
    ::create();
    set_short("A cozy halfling living room");
    set_long(
@DESC
%^YELLOW%^As you enter the house, you look into a brightly lit living room.
In the center of the room you see a big fireplace with a round
chimney letting the smoke rise through the roof. On the fireplace
there is a big %^GREEN%^pot of stew %^YELLOW%^bubbling away. The room looks very cozy,
with a small rocking chair next to a %^RED%^big bookcase %^YELLOW%^filled with books.
The room doesn't have many pictures, but there is one, with the face
of the greatest of masters. Under the picture there is a small rack
with a %^GREEN%^small lockable chest %^YELLOW%^on top of it. There are two doors, one
leading out and one leading into the bedroom.
DESC
    );
    set_indoors(1);
    set_light(3);
    set_smell("default","You smell the stew bubbling from the pot.");
    set_listen("default","The bubbling stew gives a relaxing quiet atmosphere.");
    set_items(([
        "bookcase":"As you look upon the bookcase you see a lot of different litterature, most of it is in halfling but some are in common too. You manage to decipher one of the cryptic titles... it says %^RED%^'Proper Halfling Courtship'%^RESET%^.",
        "picture":"A shiver runs down your spine as you look at the picture.\n%^YELLOW%^As you look upon the picture, you clearly recognize the face of one of the greatest, if not the greatest, assassin to ever live in ShadowGate... %^RED%^Berset.",
        "chest":"%^GREEN%^As you look into the chest you see Tigger's trademark Halfling daggers, which he uses expertly.",

    ]));
    set_exits(([
        "out":"/d/player_houses/tigger/tigger1",
        "bedroom":"/d/player_houses/tigger/tigger3",
    ]));
    set_door("door","/d/player_houses/tigger/tigger1","out",0);
    set_door("bedroom door","/d/player_houses/tigger/tigger3","bedroom",0);
    set_open("bedroom door",1);
}

void reset(){
    ::reset();
    remove_exit("north");
    set_open("bedroom door",1);
    "/d/player_houses/tigger/tigger3"->set_open("bedroom door",1);
}

void init(){
    ::init();
    add_action("pull_book","pull");
}

int pull_book(string str){
    if(!str) return 0;
    if(str != "love book") return 0;
    tell_object(TP,"As you attempt to pull the book off the shelf, a secret doorway opens!");
    tell_room(TO,"As "+TPQCN+" tried to pull a book off the shelf, a secret doorway opens!",TP);
    add_exit("/d/player_houses/tigger/tigger4","north");
    return 1;
}

