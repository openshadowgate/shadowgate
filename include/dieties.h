// Occult classes or ic development only
#define OCCULT_GODS (([\
    "usuiguth":({"Dreams/Madness", ({4, 5, 6, 7, 8, 9}), ({5, 7, 8, 9})}), \
]))
/**
 * List of deities with follower-clergy pairs
 */
#define DIETIES (([\
   "jarmila":({"Light/Love",({1, 2, 4, 5, 6, 7, 8}),({1, 4, 5, 7})}),\
   "callamir":({"Luck/Trickery",({1, 4, 5, 7, 8, 9}),({4, 7, 8})}),\
   "kreysneothosies":({"Justice/Protection",({1, 2, 3, 4, 5, 7}),({1, 2, 4})}),\
   "nilith":({"Undead/War",({3, 5, 6, 7, 8, 9}),({6, 8, 9})}),\
   "lord shadow":({"Darkness/Tyranny",({1, 2, 3, 5, 6, 9}),({2, 3, 6})}),\
   "the faceless one":({"Murder/Deception",({2, 3, 4, 5, 6, 8, 9}),({3, 5, 6, 9})}),\
   "kismet":({"Magic/Knowledge",({1, 2, 3, 4, 5, 6, 7, 8, 9}),({2, 4, 5, 6, 8})}),\
   "lysara":({"Death/Fate",({1, 2, 3, 4, 5, 6, 7, 8, 9}),({2, 4, 5, 6, 8})}),\
   "nimnavanon":({"Forests/Weather",({1, 2, 3, 4, 5, 6, 7, 8, 9}),({2, 4, 5, 6, 8})}),\
]))

#define PANTHEON DIETIES + OCCULT_GODS

#define PALADIN_GODS ({"jarmila", "kreysneothosies", "nilith", "lord shadow", "kismet", "lysara"})
