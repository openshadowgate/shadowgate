//file 

#include <std.h>

inherit OBJECT;

void create(){
    ::create();
    set_name("paper");
    set_id(({"item","paper","letter","%^YELLOW%^Letter%^RESET%^",}));
    set_short("%^YELLOW%^Letter%^RESET%^");
    set_long(
@ITEM
%^YELLOW%^This letter is written in a beautiful elven script, obviously with care and compassion. If you wish you could easily read it.%^RESET%^
ITEM
        );
    set_weight(2);
    set_value(0);
    set("read","%^YELLOW%^
My Beloved Kaeldora, 

The day I took your name was a day I thought would never happen and yet here I am, standing 5 years from where our journey as one began. 

Each of those years has been filled with joy for me, despite the trials and the hard times.  It has been the knowledge of your presence in my life that continually carried me forward, the desire to be in your embrace again that has brought me home from my journeys, and the smile on your lips when I walk through the door that has been my soul's great joy.

My Love, you have shown me a greater love than I ever thought I could know. From the day I met you, you have offered me strength, showered me with Light and filled me with warmth. Know that I will be here for you in every way I can be, as I have tried to be, as you have been for me.  

I can only say to you, Kaeldora, that you have been all I could ever want you to be, and I will love you always. 

With All My Love, 

Jerimiah Carendore.
%^RESET%^
");
}