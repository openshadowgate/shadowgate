//	chest.c
//	a lockable treasure chest
//	written by Descartes 21 October 1992

inherit "/d/common/obj/misc/chesti.c";

void create() 
{
	::create();
	create_treasure_chest("random", "random");
}

int is_carving(){return 1;}
