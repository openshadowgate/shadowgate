#include <std.h>

mixed * arealist = ({});

//sort -t, -nk2
//DO NOT USE COMMA IN THE LIST BELOW.
arealist = ({
        ({"Offestry" ,1,6,}),
            ({"Ekibi Caverns (Ekibi Ridge)" ,6,10,}),
            ({"Gobgob" ,6,10,}),
            ({"Darkwood Forest" ,8,10,}),
            ({"Dragon's Den Caverns" ,8,10,}),
            ({"Grasslands/Meadowlands" ,8,10,}),
            ({"Orc Cave" ,8,10,}),
            ({"Echoes Mountains" ,8,12,}),
            ({"Centaur Meadow (Darkwood Side)" ,10,12,}),
            ({"Cryptkeeper's Lair" ,10,12,}),
            ({"Gentleman's Tower" ,10,12,}),
            ({"Gore's Hoarde" ,10,12,}),
            ({"Kildare Glen" ,10,12,}),
            ({"Muileann" ,10,12,}),
            ({"Piaf's Farm" ,10,12,}),
            ({"Pyramid (Darkwood Side)" ,10,12,}),
            ({"Underwater Tunnels (Darkwood Side)" ,10,12,}),
            ({"Yntala Forest" ,10,12,}),
            ({"Feyren Farm (West of Shadow)" ,10,15,}),
            ({"Nereid's Cove" ,10,15,}),
            ({"Dark Trail (East of Antioch)" ,12,15,}),
            ({"Deep Gnome Cavern (Charu Mountains)" ,12,15,}),
            ({"King's Forest (Slightly southwest of Antioch)" ,12,15,}),
            ({"Spider Nests" ,12,15,}),
            ({"Antioch Ruins (East of Antioch)" ,15,20,}),
            ({"Dry Rum Cove (00 55)",15,20,}),
            ({"Githyanki Fortress (East of Shadow)" ,15,20,}),
            ({"Purple Worm Lair (Southeast of Antioch)" ,15,20,}),
            ({"Shadowlord's Forest (Deku)",15,20,}),
            ({"Shadowlord's Fortress (Deku)",15,20,}),
            ({"Shadowlord's Graveyard (Deku)",15,20,}),
            ({"Tharis Forest" ,15,20,}),
            ({"The Vale" ,15,20,}),
            ({"The Dark Forest (Bordering The Vale)" ,18,25,}),
            ({"Altar of Fire (Deku)",20,25,}),
            ({"Amazon Forest (Dallyh)",20,25,}),
            ({"Archemond's Mansion (Near Lothwaite)" ,20,25,}),
            ({"Barrier Mountains (South of Torm)" ,20,25,}),
            ({"Barrow Downs (Dagger Mountains)" ,20,25,}),
            ({"Dagger Marsh" ,20,25,}),
            ({"Drow Underdark (Dagger Mountains)" ,20,25,}),
            ({"Firbolg Barrows (In Lothwaite)" ,20,25,}),
            ({"Gnoll Encampment (Laerad)",20,25,}),
            ({"God's Plains (Laerad)",20,25,}),
            ({"Lizardman Sewers (Laerad)",20,25,}),
            ({"Misty Grove" ,20,25,}),
            ({"Parnelli Forest (Laerad)",20,25,}),
            ({"Sanctuary Ruins (Deku)",20,25,}),
            ({"Sanctuary Sewers (Deku)",20,25,}),
            ({"Sanctuary Tower (Deku)",20,25,}),
            ({"Swamp of Death (Laerad)",20,25,}),
            ({"Wasteland (Laerad)",20,25,}),
            ({"Battlefield (Graez)",20,30,}),
            ({"BlackTongue's Keep (Deku)",20,30,}),
            ({"Coral Reef (Sea 08 62)",20,30,}),
            ({"Derro Tunnels (Dagger Mountains)" ,20,30,}),
            ({"Graez City",20,30,}),
            ({"Marsh (Graez)",20,30,}),
            ({"Minotaur Maze (Graez)",20,30,}),
            ({"Mountains (Graez)",20,30,}),
            ({"Shadowlord's Mausoleum (Deku)",20,30,}),
            ({"Tonerra Monastery",20,35,}),
            ({"Dino Island (30 20)",25,30,}),
            ({"Dojo (Laerad)",25,30,}),
            ({"Drow Temple" ,25,30,}),
            ({"Ice Caves (Dagger Mountains)" ,25,30,}),
            ({"Laerad Caverns",25,30,}),
            ({"Lower Aramanth Island",25,30,}),
            ({"Marsh of Fear" ,25,30,}),
            ({"Ogre Caverns (Dagger Mountains)" ,25,30,}),
            ({"Ovadexel Island (21 46)",25,30,}),
            ({"Plane of Fire" ,25,30,}),
            ({"Tonerra Jungle",25,30,}),
            ({"Tonerra Native Village",25,30,}),
            ({"Assassin Tunnels",30,35,}),
            ({"Attaya Jungle",30,35,}),
            ({"Black Stairway (Crystal Tower)",30,35,}),
            ({"Demongate" ,30,35,}),
            ({"Devil Tunnels",30,35,}),
            ({"Geonslu's Lair (Tonerra)",30,35,}),
            ({"Haunted House (Deku)",30,35,}),
            ({"Ice Island (30 16)",30,35,}),
            ({"Kinaro Underdark (Beneath Kinaro)" ,30,35,}),
            ({"Muln's Lair (Charu Mountains)" ,30,35,}),
            ({"Oubliette (Crystal Tower)",30,35,}),
            ({"Lava Tubes (Tonerra)",33,42,}),
            ({"Arkhon's Lair" ,35,40,}),
            ({"Forest on Argentrock Island",35,40,}),
            ({"Batlin's House (Argentrock)",35,50,}),
            ({"Crystal Tower",40,45 ,}),
            ({"Ibrandul's Temple (Tonerra)",40,45,}),
            ({"Shoreline on Argentrock Island",40,45,}),
            ({"Eldebaro Island (07 51)",40,50,}),
            ({"Klauth's Lair",40,50,}),
            ({"Dallyh Marsh (Dallyh)",45,50,}),
            ({"Mysterious Plateau (Aramanth)",45,50,}),
                });

int cmd_rumors(string args)
{
    mixed * area;
    int lev = TP->query_character_level();
    int allflag = 0;
    int dispflag = 0;
    string color;

    if(args =="all")
        allflag = 1;
    write("%^BOLD%^Levels Area");
    foreach(area in arealist)
    {
        dispflag = 0;
        if(lev >= area[1] && lev <= area[2])
        {
            dispflag = 1;
            color ="%^GREEN%^";
        }
        if(area[2] < lev)
            color ="%^ORANGE%^";

        if(area[1] > lev)
            color ="%^RED%^";

        if(allflag||dispflag)
            write("%^CYAN%^"+sprintf("%2d",area[1])+"-"+sprintf("%2d",area[2])+color+" "+area[0]+"%^RESET%^");
    }
    return 1;
}

void help()
{
    write(
"%^CYAN%^NAME%^RESET%^

rumors - display areas appropriate to your level

%^CYAN%^SYNTAX%^RESET%^

rumors [all]

%^CYAN%^DESCRIPTION%^RESET%^

This command prints recommended areas list that fits withing your level range.

%^CYAN%^SEE ALSO%^RESET%^

gossip, background, score");


}
