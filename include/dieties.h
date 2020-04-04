//updated by Circe 4/16/04 for new gods
//Added Sune, Shaundakul, and Beshaba - Cythera 8/05
//Added ranger deity restrictions - Nienne 02/07
//Loviatar removed following NF plot stuffs - Nienne 09/07.
//Anhur added by ~Circe~ 5/17/08 - will go in after Tiamat's plot
//Modified DIETIES definition for layman follower alignments, per 2e Faiths and Avatars.  Required modifications to /d/shadowgate/masters/masters.c and /std/temple.c - Octothorpe 4/4/10

#define KNIGHTS ({"auril","auppenser","bane","grumbar","helm","kelemvor","kossuth","lathander","mystra","selune","shar","sune","torm","tyr"})

#define NEWPANTHEON ({"jarmila","callamir","kreysneothosies","ryorik","lord shadow","the faceless one","kismet","lysara","nimnavanon","nilith"})

/**
 * List of deities with follower-clergy pairs
 */
#define DIETIES (([\
   "jarmila":({"Light/Love",({1,2,4,5,7}),({1,4,7})}),\
   "callamir":({"Luck/Trickery",({1,4,5,7,8}),({4,7,8})}),\
   "kreysneothosies":({"Justice/Protection",({1,2,4,5,7}),({1,2,4})}),\
   "ryorik":({"Elements/Destruction",({2,4,5,6,7,8,9}),({7,8,9})}),\
   "nilith":({"Undead/War",({3,5,6,8,9}),({3,6,8,9})}),\
   "lord shadow":({"Darkness/Tyranny",({1, 2, 3, 5, 6, 9}),({2, 3, 6})}), \
   "the faceless one":({"Murder/Deception",({2, 3, 4, 5, 6, 8, 9}),({3, 5, 6, 9})}), \
   "kismet":({"Magic/Knowledge",({1, 2, 3, 4, 5, 6, 7, 8, 9}),({2, 4, 5, 6, 8})}),\
   "lysara":({"Death/Fate",({1, 2, 3, 4, 5, 6, 7, 8, 9}),({2, 4, 5, 6, 8})}),\
   "nimnavanon":({"Forests/Weather",({1, 2, 3, 4, 5, 6, 7, 8, 9}),({2, 4, 5, 6, 8})}), \
]))

#define RANGERS ({})

#define DRUIDS ({})

#define MONKS ({})

#define KNIGHTALIGN (([]))

#define RANGERALIGN (([]))
