//VERY VERY VERY IMPORTANT for the basement of the haunted house - would be a better decision to disable the exit down in /d/deku/hhouse/rooms/ffiw20.c should there be serious issues - Saide 

#include "area_stuff.h"

#define e "east"
#define w "west"
#define n "north"
#define s "south"
#define ne "northeast"
#define se "southeast"
#define nw "northwest"
#define sw "southwest"
#define u "up"
#define dr "door"

#define MAPONE (["1" : ([e : 74, s : 2, u : BEXIT ]),\
"2" : ([n : 1, w : 26]),\
"3" : ([e : 76, w : 25]),\
"4" : ([e : 77, s : 5]),\
"5" : ([n : 4, s : 6]),\
"6" : ([n : 5, e : 79, s : 7]),\
"7" : ([n : 6, w : 21]),\
"8" : ([n : 9, w : 28]),\
"9" : ([e : 72, s : 8]),\
"10" : ([w : 30]),\
"11" : ([s : 12, w : 61]),\
"12" : ([n : 11, s : 13]),\
"13" : ([n : 12, s : 14]),\
"14" : ([n : 13, s : 15, w : 64]),\
"15" : ([n : 14, s : 16, w : 65]),\
"16" : ([n : 15, s : 17]),\
"17" : ([n : 16, w : 67]),\
"18" : ([s : 19, nw : 67]),\
"19" : ([n : 18, s : 20, w : 69]),\
"20" : ([n : 19, w : 70]),\
"21" : ([e : 7, n : 22]),\
"22" : ([n : 23, s : 21]),\
"23" : ([s : 22]),\
"24" : ([n : 25, w : 97]),\
"25" : ([n : 26, e : 3, s : 24]),\
"26" : ([e : 2, s : 25, w : 95]),\
"27" : ([n : 28]),\
"28" : ([e : 8, s : 27]),\
"29" : ([n : 30, w : 92]),\
"30" : ([e : 10, s : 29, w : 91]),\
"31" : ([ e : 90, s : 32 ]),\
"32" : ([n : 31, s : 33, nw: 60]),\
"33" : ([n : 32, e : 88]),\
"34" : ([ne : 88]),\
"35" : ([e : 86]),\
"36" : ([w : 55, se : 84]),\
"37" : ([s : 38, w : 54]),\
"38" : ([n : 37]),\
"39" : ([e : 82, s : 40, w : 52]),\
"40" : ([n : 39]),\
"41" : ([dr : "r2", s : 42]),\
"42" : ([e : 92]),\
"43" : ([e : 93]),\
"44" : ([s : 45]),\
"45" : ([n : 44, e : 95]),\
"46" : ([e : 96]),\
"47" : ([ne : 96, s : 48]),\
"48" : ([n : 47, s : 49]),\
"49" : ([n : 48, ne : 98, e : 99]),\
"50" : ([e : 100]),\
"51" : ([w : 80, nw : 79]),\
"52" : ([n : 53, e : 39]),\
"53" : ([s : 52, sw : 79, w : 78]),\
"54" : ([n : 55, e : 37]),\
"55" : ([e : 36, s : 54]),\
"56" : ([n : 57, w : 75]),\
"57" : ([n : 58, s : 56]),\
"58" : ([s : 57, w : 73]),\
"59" : ([n : 60, w : 72]),\
"60" : ([s : 59, w : 71, se : 32]),\
"61" : ([e : 11, s : 62]),\
"62" : ([n : 61, s : 63]),\
"63" : ([dr : "r1", n : 62]),\
"64" : ([e : 14]),\
"65" : ([e : 15, s : 66]),\
"66" : ([n : 65, w : 85]),\
"67" : ([e : 17, se : 18, s : 68, w : 84]),\
"68" : ([n : 67]),\
"69" : ([e : 19, w : 82]),\
"70" : ([e : 20, w : 81]),\
"71" : ([e : 60]),\
"72" : ([e : 59, s : 73, w : 9]),\
"73" : ([n : 72, e : 58]),\
"74" : ([s : 75, w : 1]),\
"75" : ([n : 74, e : 56]),\
"76" : ([s : 77, w : 3]),\
"77" : ([n : 76, w : 4]),\
"78" : ([e : 53]),\
"79" : ([ne : 53, se : 51, w : 6]),\
"80" : ([e : 51]),\
"81" : ([dr : "r3", e : 70]),\
"82" : ([ e : 69, w : 39]),\
"83" : ([n : 84]),\
"84" : ([e : 67, s : 83, nw : 36]),\
"85" : ([e : 66]),\
"86" : ([n : 87, w : 35]),\
"87" : ([s : 86]),\
"88" : ([n : 89, sw : 34, w : 33]),\
"89" : ([s : 88]),\
"90" : ([w : 31]),\
"91" : ([e : 30]),\
"92" : ([e : 29, s : 93, w : 42]),\
"93" : ([n : 92, s : 94, w : 43]),\
"94" : ([n : 93, s : 95]),\
"95" : ([n : 94, e : 26, w : 45]),\
"96" : ([sw : 47, w : 46]),\
"97" : ([e : 24, s : 98]),\
"98" : ([n : 97, sw : 49]),\
"99" : ([s : 100, w : 49]),\
"100" : ([n : 99, w : 50]),\
"r1" : ([dr : 63]),\
"r2" : ([dr : 41]),\
"r3" : ([dr : 81]), ])

#define MAPTWO (["1" : ([sw : 2, u : BEXIT]),\
"2" : ([ne : 1, se : 28, nw : 66]),\
"3" : ([n : 44, e : 46, s : 67, w : 43]),\
"4" : ([s : 96, w : 42]),\
"5" : ([n : 42, s : 16]),\
"6" : ([s : 85]),\
"7" : ([e : 85, nw : 82]),\
"8" : ([n : 40, e : 76, s : 39]),\
"9" : ([n : 59, s : 58]),\
"10" : ([n : 37, e : 58]),\
"11" : ([e : 65, s : 30]),\
"12" : ([n : 65]),\
"13" : ([n : 79, w : 64]),\
"14" : ([n : 74, w : 80]),\
"15" : ([n : 86, sw : 41]),\
"16" : ([n : 5, e : 95]),\
"17" : ([w : 94]),\
"18" : ([dr : "r1", n : 70]),\
"19" : ([e : 21, se : 20, s : 52]),\
"20" : ([nw : 19]),\
"21" : ([n : 23, w : 19]),\
"22" : ([s : 99]),\
"23" : ([s : 21, w : 51]),\
"24" : ([n : 25, w : 50, nw : 49]),\
"25" : ([s : 24]),\
"26" : ([n : 27, sw : 49]),\
"27" : ([s : 26, w : 47]),\
"28" : ([n : 29, sw : 47, nw : 2]),\
"29" : ([s : 28]),\
"30" : ([n : 11, se : 64, s : 31]),\
"31" : ([n : 30]),\
"32" : ([se : 62, s : 33]),\
"33" : ([n : 32, dr : "r2"]),\
"34" : ([dr : "r3", s : 35]),\
"35" : ([n : 34, s : 36]),\
"36" : ([n : 35, s : 37]),\
"37" : ([n : 36, s : 10]),\
"38" : ([e : 57, w : 58]),\
"39" : ([n : 8, se : 57]),\
"40" : ([s : 8]),\
"41" : ([n : 75, ne : 15, w : 82]),\
"42" : ([e : 4, s : 5]),\
"43" : ([e : 3, w : 97]),\
"44" : ([s : 3, w : 98]),\
"45" : ([w : 66]),\
"46" : ([s : 47, w : 3]),\
"47" : ([n : 46, ne : 28, e : 27]),\
"48" : ([w : 68]),\
"49" : ([ne : 26, se : 24, nw : 68]),\
"50" : ([e : 24, s : 51]),\
"51" : ([n : 50, e : 23]),\
"52" : ([n : 19]),\
"53" : ([n : 71, w : 54, nw : 90]),\
"54" : ([e : 53, nw : 92]),\
"55" : ([n : 92, w : 56]),\
"56" : ([e : 55]),\
"57" : ([w : 38, nw : 39]),\
"58" : ([n : 9, e : 38, w : 10]),\
"59" : ([n : 60, s : 9]),\
"60" : ([n : 61, s : 59]),\
"61" : ([e : 82, s : 60]),\
"62" : ([e : 81, nw : 32]),\
"63" : ([n : 64]),\
"64" : ([e : 13, s : 63, nw : 30]),\
"65" : ([s : 12, w : 11]),\
"66" : ([e : 45, se : 2]),\
"67" : ([n : 3]),\
"68" : ([e : 48, se : 49, w : 96]),\
"69" : ([s : 70]),\
"70" : ([n : 69, s : 18, nw : 95]),\
"71" : ([s : 53]),\
"72" : ([e : 89, s : 73]),\
"73" : ([n : 72, s : 74, w : 79]),\
"74" : ([n : 73, e : 87, s : 14]),\
"75" : ([s : 41]),\
"76" : ([w : 8]),\
"77" : ([ne : 84, e : 83]),\
"78" : ([s : 79]),\
"79" : ([n : 78, e : 73, s : 13]),\
"80" : ([e : 14, s : 81]),\
"81" : ([n : 80, w : 62]),\
"82" : ([e : 41, se : 7, w : 61]),\
"83" : ([w : 77]),\
"84" : ([n : 85, sw : 77]),\
"85" : ([n : 6, s : 84, w : 7]),\
"86" : ([n : 87, s : 15]),\
"87" : ([e : 97, s : 86, w : 74]),\
"88" : ([e : 99]),\
"89" : ([se : 99, w : 72]),\
"90" : ([n : 91, se : 53]),\
"91" : ([s : 90, w : 93]),\
"92" : ([s : 55, se : 54]),\
"93" : ([n : 94, e : 91]),\
"94" : ([ne : 95, e : 17, s : 93]),\
"95" : ([se : 70, sw : 94, w : 16]),\
"96" : ([n : 4, e : 68]),\
"97" : ([e : 43, w : 87]),\
"98" : ([n : 100, e : 44]),\
"99" : ([n : 22, w : 88, nw : 89]),\
"100" : ([s : 98]),\
"r1" : ([dr : 18]),\
"r2" : ([dr : 33]),\
"r3" : ([dr : 34]),])

#define MAPTHREE (["1" : ([n : 2, e : 56, s : 8, w : 6, u : BEXIT]),\
"2" : ([e : 69, s : 1, nw : 4]),\
"3" : ([e : 68]),\
"4" : ([se : 2, s : 5]),\
"5" : ([n : 4]),\
"6" : ([e : 1]),\
"7" : ([e : 8]),\
"8" : ([n : 1, w : 7]),\
"9" : ([n : 10, w : 48, nw : 47]),\
"10" : ([s : 9]),\
"11" : ([ne : 13, w : 18]),\
"12" : ([n : 95, sw : 18, w : 17]),\
"13" : ([ne : 93, sw : 11]),\
"14" : ([dr : "r1", e : 16]),\
"15" : ([n : 93, s : 16]),\
"16" : ([n : 15, w : 14]),\
"17" : ([dr : "r3", e : 12]),\
"18" : ([ne : 12, e : 11]),\
"19" : ([n : 20]),\
"20" : ([s : 19, sw : 27, w : 28]),\
"21" : ([e : 24, se : 23, s : 22]),\
"22" : ([n : 21]),\
"23" : ([se : 44, nw : 21]),\
"24" : ([n : 73, w : 21]),\
"25" : ([n : 43, s : 26]),\
"26" : ([n : 25]),\
"27" : ([ne : 20, w : 30]),\
"28" : ([n : 64, e : 20]),\
"29" : ([n : 63, s : 30]),\
"30" : ([n : 29, e : 27, s : 65]),\
"31" : ([n : 85, se : 51]),\
"32" : ([e : 51, s : 33]),\
"33" : ([n : 32, e : 52]),\
"34" : ([n : 35]),\
"35" : ([n : 36, s : 34, nw : 69]),\
"36" : ([e : 57, s : 35]),\
"37" : ([e : 84, nw : 67]),\
"38" : ([n : 39, w : 64]),\
"39" : ([n : 40, s : 38]),\
"40" : ([e : 80, s : 39, w : 60]),\
"41" : ([s : 42, w : 71]),\
"42" : ([n : 41]),\
"43" : ([s : 25, w : 73, nw : 72]),\
"44" : ([w : 74, nw : 23]),\
"45" : ([s : 46, w : 75]),\
"46" : ([n : 45, w : 76]),\
"47" : ([se : 9, sw : 49, w : 50]),\
"48" : ([e : 9]),\
"49" : ([ne : 47, w : 52]),\
"50" : ([n : 77, e : 47]),\
"51" : ([w : 32, nw : 31]),\
"52" : ([e : 49, w : 33]),\
"53" : ([n : 57, s : 54]),\
"54" : ([n : 53]),\
"55" : ([n : 56]),\
"56" : ([s : 55, w : 1]),\
"57" : ([n : 84, s : 53, w : 36]),\
"58" : ([ne : 78, e : 77]),\
"59" : ([dr : "r2", s : 61]),\
"60" : ([e : 40]),\
"61" : ([n : 59, e : 62]),\
"62" : ([sw : 63, w : 61]),\
"63" : ([ne : 62, s : 29]),\
"64" : ([e : 38, s : 28]),\
"65" : ([n : 30, e : 66]),\
"66" : ([e : 67, w : 65]),\
"67" : ([e : 70, se : 37, w : 66]),\
"68" : ([s : 69, w : 3]),\
"69" : ([n : 68, se : 35, w : 2]),\
"70" : ([e : 83, w : 67]),\
"71" : ([e : 41, w : 90]),\
"72" : ([se : 43, nw : 90]),\
"73" : ([e : 43, s : 24, w : 92]),\
"74" : ([e : 44, w : 88]),\
"75" : ([e : 45]),\
"76" : ([e : 46, w : 77]),\
"77" : ([e : 76, s : 50, w : 58]),\
"78" : ([n : 88, sw : 58, w : 79]),\
"79" : ([e : 78]),\
"80" : ([se : 91, w : 40]),\
"81" : ([e : 91, s : 82]),\
"82" : ([n : 81, e : 95]),\
"83" : ([se : 85, w : 70]),\
"84" : ([s : 57, w : 37]),\
"85" : ([n : 89, s : 31, nw : 83]),\
"86" : ([n : 96, ne : 98]),\
"87" : ([e : 88]),\
"88" : ([e : 74, s : 78, w : 87]),\
"89" : ([s : 85]),\
"90" : ([e : 71, w : 99, se : 72]),\
"91" : ([n : 94, w : 81, nw : 80]),\
"92" : ([e : 73]),\
"93" : ([s : 15, sw : 13]),\
"94" : ([s : 91]),\
"95" : ([s : 12, w : 82]),\
"96" : ([s : 86]),\
"97" : ([e : 99, se : 98]),\
"98" : ([e : 100, sw : 86, nw : 97]),\
"99" : ([e : 90, w : 97]),\
"100" : ([w : 98]),\
"r1" : ([dr : 14]),\
"r2" : ([dr : 59]),\
"r3" : ([dr : 17]), ])