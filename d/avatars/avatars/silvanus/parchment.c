//file 

#include <std.h>

inherit OBJECT;

void create(){
    ::create();
    set_name("paper");
    set_id(({"item","paper","parchment","%^RED%^Piece of Parchment%^RESET%^",}));
    set_short("%^RED%^Piece of Parchment%^RESET%^");
    set_long(
@ITEM
%^RED%^You carefully unroll this piece of parchment, only half of it remains as it has been burned almost beyond recognition. Perhaps though with some effort you can make out what it says by attempting to read the remains of the writing...%^RESET%^
ITEM
        );
    set_weight(2);
    set_value(0);
    set("read","%^RED%^(This appears to be a journal entry, you can barely make out writing in some places)

17 Winterstime 632

The raids have become mo e and more frequent   tely, and I am fearful of what may yet come. We have received warnings that bandits are massing to the no    in encampments and that we mi ht want to make them an offering in tead of waiting for them to come for us. I have decided to ask Hettman if he would hold a few things for us until this current threat subsides. I have only m  aged to retain a few small tr  sures and I could not bear to see them lost. He made the offer the last time we saw him, when Korath's bandages came off. He did so much for

(The rest of the page has been burned beyond use..)
%^RESET%^
");
}