// Personal residence
// Thorn@ShadowGate
// 001027
// Solaren's Player House
// solaren9.c
// modified to become a mage guild tower ala Sherlock & Stefano by *Styx* 4/21/03

#include <std.h>

inherit ROOM;

void create() {
  ::create();
  set_name("Tower Library");
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
  set_property("light", 2);
  set_property("indoors", 1);
  set_short("%^BOLD%^Tower Library%^RESET%^");
  set_long("%^BOLD%^Tower Library%^RESET%^\n"
"The library takes up the entire floor of the tower.  Large %^ORANGE%^oak "
"shelves %^RESET%^stand in silent tribute to the wealth of knowledge that "
"will be held within them.  Members come here to research and expand their "
"knowledge of the weave in all its forms.  The shelves are largely empty "
"at the moment - waiting to be filled by members.  The floor is carpeted "
"in a %^GREEN%^plush green carpet %^RESET%^that muffles the steps of mages "
"seeking knowledge, wisdom, and to further their own work.  The library is "
"illuminated from above, the source not obvious.  The room is divided "
"into several sections with signs hanging from the ceiling naming each "
"section.  Tables are placed within the library allowing mages to sit, "
"read and study the books.  Alcoves lead off at the sides to allow some "
"privacy.  Steps lead down to the hall and stairs lead up to the Laboratory."
   );

/*
@THORN
%^BOLD%^Personal residence%^RESET%^
This is a comfortably decorated room that must be the owner's personal
residence.  Several chairs and couches surround a fireplace which
provides an intimate seating area for the owner's personal guests.  Of
note is one intricately carved rocking chair on the diagonal to the
fireplace which appears to be very old, for the sheen of its wood is
blue, the mark of ancient Ironwood taken from the Tharis forests.  Books
of all sorts can be found lining the walls of the chamber, with titles
ranging from the ordinary to the esoteric.

In one section of the room, a small work table has been set up with
several scrolls and maps spread about.  The curtained bed, wardrobe,
washbasin and dresser complete the living quarters.

There are a set of spiral steps in the corner of the room that you can
take up or down.
THORN
  );
*/
  set_exits(([
      "up" : "/d/player_houses/solaren/solaren10",
      "down" : "/d/player_houses/solaren/solaren8",
  ]));
  set_listen("default", "The sound of pages turning overlays the a silence born through absorbing intelligence.");
  set_smell("default", "The smell of oak, leather and parchment mix to create a somber mood.");
  set_items(([
    ({ "floor", "carpet"}) : "%^GREEN%^A thick green carpet %^RESET%^with the crest of the Guild woven into it in %^BOLD%^%^CYAN%^light blue %^RESET%^adorns the entire floor of the library.",
    ({"section", "sections"}) : "There is a section for each school of magic and religion.  They include realm history, magic artifacts, famous mages, monsters of the realm, mage combat, ancient magics, professional conduct of a mage, and new magics.",
    "crest" : "The crest takes the form of an orb containing a scroll lying across an open spell book.  Around the edges is written '%^BOLD%^%^CYAN%^The greatest part of the weave has yet to be discovered, seek this knowledge always yet know that only by the Spheres of the Arcane can this knowledge be found.%^RESET%^'",
    "shelves" : "The shelves are meant to hold a vast number of books and tomes.  It is here that knowledge is stored.",
   ]));   

}

void reset(){
  ::reset();
// moved her here from Consortium rooms in Shadow 6/18/03 *Styx*
   if (!present("Thazorus"))   
      new("/d/guilds/consortium/hall/thazorus")->move(TO);
}
