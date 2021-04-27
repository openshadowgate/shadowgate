#include <std.h>
inherit ROOM;

void create() {
   ::create();
}

void init() {
   ::init();
   add_action("memories_fun","touch");
}

int memories_fun(string str) {
   int picked;
   if(!str) return 0;
   if(str != "box" && str != "the box" && str != "music box" && str != "the music box") return 0;
   tell_object(TP,"%^CYAN%^As your hand makes contact with the carved music box, a fine %^RESET%^mist %^CYAN%^arises "
"from the centre, shifting and whorling to recreate a vibrant illusion; a memory of another place and time.%^RESET%^");
   tell_room(TO,"%^CYAN%^As "+TP->QCN+"'s hand makes contact with the carved music box, a fine %^RESET%^mist %^CYAN%^"
"arises from the centre, shifting and whorling to recreate a vibrant illusion; a memory of another place and time"
".%^RESET%^",TP);
   picked = random(50)+1;
   switch(picked) {
     default:
       tell_room(TO,"\n%^MAGENTA%^The sounds of travellers' voices breaks the %^CYAN%^silence%^MAGENTA%^ of the forest, "
"as a few elves step into view in a glade among the trees. A %^YELLOW%^blonde-haired%^RESET%^%^MAGENTA%^ ranger leads "
"their group, laughing aloud as he moves with graceful steps, while a few paces behind him follow two more elves - one "
"male, tall and %^CYAN%^azure-eyed%^MAGENTA%^, with the appearance of a warrior, and the other female with %^BLACK%^"
"%^BOLD%^long dark hair%^RESET%^%^MAGENTA%^. Somewhere behind them another voice is yelling, calling for them to wait, "
"though none among the three heed the cries. The group of three continue on, still laughing and talking among themselves "
"as they disappear into the forest ahead.\n\n%^MAGENTA%^A few moments later, another elf clad in the garb of a warrior "
"stumbles clumsily into the glade, a sword in his hand and a frown upon his lips, as he looks around for some sign of the "
"group that had just passed. He pauses for a moment, obviously confused, then yells out yet again, %^BOLD%^%^BLUE%^'"
"Sorrel? Kiya? Tal?'%^RESET%^%^MAGENTA%^. Finally he shakes his head, and tramps off through the brush again in search of "
"the elves that had just passed.");
       break;
     case 2:
       tell_room(TO,"\n%^MAGENTA%^A timid elven woman follows along, a few steps behind a tall warrior of the same "
"race, through %^ORANGE%^towering gates%^MAGENTA%^ and into a great city. Her eyes are wide as she looks around, an "
"expression of mingled awe and curiosity visible upon her face. She trails along behind her companion as they move "
"through the city's streets, slipping out of the way as she passes by the countless people within the city, most human, "
"but some of more exotic heritages. The smells, noises and atmosphere of the city seem to be a lot for the elven woman to "
"take in.\n\n%^MAGENTA%^After a few moments they step into a meeting hall, where another elf is already standing, leaning "
"against the wall. The stranger looks to the two with a welcoming smile as they enter, while the elven woman still seems "
"a little unsure of herself in the surroundings, yet despite her hesitance there is an almost tangible fondness woven "
"into the scene as it unfolds. She looks to the elf across the room from her; he stands slightly taller than herself, "
"with %^ORANGE%^short sable hair%^MAGENTA%^ that rests lightly atop his brow. %^WHITE%^Bright armor%^MAGENTA%^, and even "
"more %^MAGENTA%^%^BOLD%^br%^RESET%^%^MAGENTA%^ig%^BLUE%^ht%^BOLD%^ly%^RESET%^%^MAGENTA%^-%^GREEN%^co%^BOLD%^lo%^YELLOW%^"
"ur%^RESET%^%^ORANGE%^ed%^MAGENTA%^ clothes cover his slim form. Extending a hand, he offers his introductions to the "
"pair - %^GREEN%^'Daco Hest, humble priest of Torm'%^MAGENTA%^.");
       break;
     case 3:
       tell_room(TO,"\n%^MAGENTA%^The dark-haired elf rests her hands on her knees, trying to catch her breath; beside "
"her on the ground lie the bodies of two fallen blood-hawks, slain by her spells. A lisping voice from beside her "
"interrupts her rest, %^BLUE%^'%^WHITE%^Hello again, Kiya%^BLUE%^'%^MAGENTA%^. She pauses and glances around her, smiling "
"with recognition of the speaker, and begins to speak with the disembodied voice in halting common.\n\n%^MAGENTA%^Her "
"attention drifts from her surrounds, when a sudden roar and the sound of crashing from beside her causes her to turn on "
"her heel in fright, as a wereboar rushes at her and knocks her helpless to the ground, with no spells ready to call upon "
"in her defence. For long moments she struggles simply to stand... only to glance up as a great bolt of %^YELLOW%^li"
"%^WHITE%^g%^YELLOW%^ht%^WHITE%^n%^YELLOW%^in%^WHITE%^g%^RESET%^%^MAGENTA%^ arcs down upon her from the heavens above, "
"and the world fades into %^BLACK%^%^BOLD%^blackness%^RESET%^%^MAGENTA%^.\n\n%^MAGENTA%^What seems only moments later she "
"opens her eyes again, looking around in a %^ORANGE%^daze%^MAGENTA%^. As her vision clears, she sees that beside her in "
"the grass is the body of the wereboar that had threatened her life, now quite dead. And raising her eyes, she looks to "
"the figure standing over her - her eyes widen in shock as she takes in %^WHITE%^white hair%^MAGENTA%^ and %^BLACK%^"
"%^BOLD%^ash-grey skin%^RESET%^%^MAGENTA%^, a half-drow in long robes. His eyes dart immediately to her as he realises "
"she is conscious, and with a few brisk syllables he pulls the weave about himself and %^BLUE%^%^BOLD%^vanishes%^RESET%^"
"%^MAGENTA%^ from sight.");
       break;
     case 4:
       tell_room(TO,"\n%^MAGENTA%^A %^GREEN%^grassy%^MAGENTA%^ clearing at night, and two figures within a circle of "
"tree-shaped stones - both elven and dark-haired, one an %^CYAN%^azure-eyed%^MAGENTA%^ warrior, lying in the grass "
"relaxing, and the other a female of long robes and light armor, sitting crosslegged beside him. Both are quietly "
"conversing, occasionally sharing a laugh at some topic or other; vague scraps of their speech can be overheard as the "
"long-haired female grins a little, %^BLUE%^'%^CYAN%^...but no matter Tal, I've learnt well enough now.%^BLUE%^'\n\n"
"%^MAGENTA%^Taliesin nods, looking up to her as he asks %^GREEN%^'%^WHITE%^I hope, Daco didn't try and defeat the drow "
"warrior?%^GREEN%^'%^MAGENTA%^ She replies with a wry smile, %^BLUE%^'%^CYAN%^Take a guess... his curiosity knows no "
"bounds...%^BLUE%^'%^MAGENTA%^ The azure-eyed male sighs and shakes his head, %^GREEN%^'%^WHITE%^and on that note, who "
"names their child Daco anyway?%^GREEN%^'%^MAGENTA%^, to which the female replies with a wink %^BLUE%^'%^CYAN%^Well, I "
"suppose Kiya's not so much the greatest name either, but it does for me.%^BLUE%^'%^MAGENTA%^ Taliesin looks up to her "
"with a smile, saying %^GREEN%^'%^WHITE%^Kiya is a fine enough name... I assumed it to be a shortened version of "
"something?%^GREEN%^'%^MAGENTA%^ His companion pauses a moment as if in thought, finally shaking her head and speaking "
"quietly %^BLUE%^'%^CYAN%^No, just Kiya... all there is to it.%^BLUE%^'");
       break;
     case 5:
       tell_room(TO,"\n%^MAGENTA%^Low-set dirt roofing looms above the darkened caverns, as the long-haired elven woman "
"follows as best she can behind the %^ORANGE%^sable-haired%^MAGENTA%^ elf priest. Both are stooped low, still often "
"hitting their heads on the roof above them, despite their best attempts not to. After a long distance of wandering "
"around in seemingly aimless directions, they exchange places and the female takes the lead, but she seems just as lost "
"as her companion, and only to be guiding them %^BLUE%^deeper%^MAGENTA%^ into the caves.\n\n%^MAGENTA%^Finally after "
"unmeasured time of random wanderings, the priest grows weary and slumps to the ground to rest, with a very sore head "
"and a defeated look upon his face. The elven woman crouches down beside him as he mumbles %^GREEN%^'We'll never find "
"the way out, we're lost.'%^MAGENTA%^ She shakes her head, reaching into a small pocket of her robes and producing a "
"single %^WHITE%^%^BOLD%^white daisy%^RESET%^%^MAGENTA%^, which she hands to the male beside her with a slight grin, "
"%^BLUE%^'%^CYAN%^Don't give up Daco, it could be worse... at least you're stuck here with me.%^BLUE%^'%^MAGENTA%^ Her "
"companion manages a wry smile and nods his head, standing again as they continue on together into the %^BLACK%^%^BOLD%^"
"darkness%^RESET%^%^MAGENTA%^.");
       break;
     case 6:
       tell_room(TO,"\n%^MAGENTA%^Again walking the streets of the crowded city, the elf slows as she approaches a "
"familiar figure - a taller half-elf, shrouded in a %^BLUE%^flowing cloak%^MAGENTA%^ and rubbing a %^BLACK%^%^BOLD%^ring"
"%^RESET%^%^MAGENTA%^ on his hand, glancing about in an agitated fashion. She smiles up at him, %^BLUE%^'%^CYAN%^"
"Greetings Galyrion, how do you fare this day?%^BLUE%^'%^MAGENTA%^ He looks up as if noticing her for the first time, "
"nodding abruptly in response to the greeting, before shifting his eyes back to the people passing by.\n\n%^MAGENTA%^The "
"elf looks a little confused at his demeanor, glancing curiously to the %^BLACK%^%^BOLD%^dark ring%^RESET%^%^MAGENTA%^ he "
"is still rubbing on his hand. He turns back to her, eyes flashing dangerously as he snarls %^WHITE%^'%^BLACK%^%^BOLD%^"
"You were looking at it weren't you??%^RESET%^%^WHITE%^'%^MAGENTA%^ Suddenly and without warning his hand lashes out, "
"catching the elf around the throat and lifting her bodily from the ground. He holds her there for what seems an age to "
"her, watching with narrowed eyes while she struggles to breathe, before finally he drops her back to the ground. She "
"gasps for a ragged breath, as he stalks away without a backward glance, disappearing into the %^BLACK%^%^BOLD%^shadows"
"%^RESET%^%^MAGENTA%^.");
       break;
     case 7:
       tell_room(TO,"\n%^MAGENTA%^The same female elf, sitting beneath the %^WHITE%^faint light%^MAGENTA%^ of the moon, "
"beside towering closed gates. Nearby at the side of the well-worn roadway rests a well-armored, %^YELLOW%^blonde-haired"
"%^RESET%^%^MAGENTA%^ human by the name of Turyia - after their initial meeting, and his extensive attempts to converse "
"with the elf in the common tongue, he had given up and was now attempting to gather some sleep. The elven woman hums to "
"herself, watching the human with curiosity as he begins to snore lightly.\n\n%^MAGENTA%^The sound of light hoofbeats "
"cause her to look up, as another elf approaches on horseback, %^BLACK%^%^BOLD%^dark-haired%^RESET%^%^MAGENTA%^ and "
"%^BLUE%^%^BOLD%^blue-eyed%^RESET%^%^MAGENTA%^, in the garb of a forest-dweller. He jumps easily down from the horse as "
"he nears the gates and approaches the female, trading brief introductions with her and giving his name as Aramel. He "
"glances sideways at Turyia, grins wickedly and slips a few pebbles from the path into his hand, wandering over to the "
"sleeping human and dropping them one by one on his head.\n\n%^MAGENTA%^The human warrior awakes with a start, "
"disoriented for a few seconds before he realises his attacker's identity and strugges to regain his footing. He takes a "
"few misdirected swipes with his hands at the elven ranger, who simply laughs and springs back with a single fluid "
"movement, mounting the horse and directing it back up the road from where he came. After a moment of grumbling, the "
"human lies back down to rest again, as the elven woman just sits and watches the ranger disappear into the distance, "
"wondering why he seemed so familiar...");
       break;
     case 8:
       tell_room(TO,"\n%^MAGENTA%^A small and silent room, with one door opened into the %^YELLOW%^daylight%^RESET%^"
"%^MAGENTA%^ outside, and the other barred with a strong padlock. The elven woman slips in, unseen under guise of "
"invisibility, studying her surroundings and quickly taking it all in. She begins a chant in a low voice, focussing her "
"concentration as the key from the jail-guard's belt floats up noiselessly through the air and into her hands. With "
"another cautious glance, she puts it into the lock and turns the key... as a sudden heavy hand falls over hers, and a "
"heavy cuff to the back of the head knocks her into %^BLACK%^%^BOLD%^unconsciousness%^RESET%^%^MAGENTA%^.\n\n%^MAGENTA%^"
"She awakens to a %^BLACK%^%^BOLD%^dank%^RESET%^%^MAGENTA%^, smelly room with a single %^ORANGE%^dirty mat%^MAGENTA%^ "
"discarded against one wall... and another elven figure slumped upon it, unmoving and bound at the hands and feet. She "
"begins struggling wildly as she finds herself bound also, falling several more times into unconsciousness before she "
"finally breaks the ropes' hold. After taking several moments to catch her breath she drags herself to her hands and "
"knees, making her way across to the still form of the elven male across the room. Carefully she frees him from his bonds "
"and rests a hand on his shoulder, shaking him gently, %^BLUE%^'%^CYAN%^Merrick? Wake up, I'm here now...%^BLUE%^'");
       break;
     case 9:
       tell_room(TO,"\n%^MAGENTA%^Taking two steps at a time, the elven woman rushes up a spiral staircase until she "
"reaches a small shop near the top of the tower. She requests a scroll abruptly and opens her book, hurriedly trying to "
"interpret the symbols written on the paper. She manages to set the scroll's symbols in her book without mistake and "
"commits it to memory, then slams the book shut and dashes back down the staircases and out the gate. Firstly pulling a "
"spell of %^BLUE%^invisibility%^MAGENTA%^ around her, she calls upon the words of the newly mastered spell - a %^CYAN%^"
"%^BOLD%^bright glow%^RESET%^%^MAGENTA%^ appears around her form and she vanishes.\n\n%^MAGENTA%^The glow fades as she "
"finds herself on a small boat in the middle of the ocean. Across from her on the deck is a %^WHITE%^shi%^BOLD%^m%^RESET%^"
"%^WHITE%^mer%^BOLD%^i%^RESET%^%^WHITE%^ng%^MAGENTA%^ form of air, an elemental, with a stack of equipment in its grasp. "
"At its feet is the familiar form of the %^BLUE%^blue-eyed%^MAGENTA%^ elven ranger, bound hand and foot. The female seems "
"wary to approach the elemental and the bound elf nearby, hesitantly looking around the seemingly empty ship's deck for "
"company. With a bump the ship runs aground and the gangplank is somehow lowered without visible aid - the invisible elf "
"panicks and finally makes a decision, rushing to the ranger's side. She lifts him from the deck and chants a word of "
"power, as the two are lifted by her spell from the ship and vanish.");
       break;
     case 10:
       tell_room(TO,"\n%^MAGENTA%^The elven woman sits alone on a couch in a crowded inn, gazing out the doorway at three "
"figures in hushed conversation. The %^CYAN%^azure-eyed %^MAGENTA%^warrior that had accompanied her before stands, his "
"lips moving with words inaudable to the elf female, and sending occasional glances in her direction. Listening carefully "
"are two elven priests, one a %^YELLOW%^blonde-haired %^RESET%^%^MAGENTA%^female and one a %^BLACK%^%^BOLD%^dark-haired "
"%^RESET%^%^MAGENTA%^male, nodding their heads in mute agreement at his words. The elf inside the inn sighs, leaning her "
"head against the back of the couch and closing her eyes. Behind her, a shadowy form, possibly another elf, utters hushed "
"whispers to her in a low rasping voice, words that remain in her mind long after, %^BLACK%^%^BOLD%^'...and so he tells "
"them, to their agreement, my pretty kitty - even cats have claws.'%^RESET%^");
       break;
     case 11:
       tell_room(TO,"\n%^MAGENTA%^Inside the small temple is a gathering of several elves, occasionally glancing to the "
"doorway where the %^BLUE%^blue-eyed%^MAGENTA%^ elven ranger stands guard. For a good while the air is tense, with the "
"travellers whispering among themselves in hushed voices, though as time passes they slowly relax, speaking more freely. "
"Finally, from among them the %^BLACK%^%^BOLD%^dark-haired%^RESET%^%^MAGENTA%^ female elf stands, stepping toward the "
"door and telling them she would only run a short errand and then return. She walks through the doorway and down the "
"temple steps, when suddenly a flicker of movement to her side catches her eye - a %^GREEN%^dir%^ORANGE%^t%^GREEN%^y "
"goblin%^MAGENTA%^ appears from nowhere and sinks a blade between her shoulders, dropping her easily into unconsciousness"
".\n\n%^MAGENTA%^She awakens to an elven male standing over her, calling her name and holding a vial of %^BLUE%^%^BOLD%^"
"liquid%^RESET%^%^MAGENTA%^ to her lips. Through her blurred senses she sees his familiar face framed with %^BLACK%^"
"%^BOLD%^jet-black%^RESET%^%^MAGENTA%^ hair, and a name flashes for a second through her thoughts... %^CYAN%^Cal..."
"%^MAGENTA%^ He peers closely at her with his %^BLUE%^blue%^MAGENTA%^ eyes... %^BLUE%^blue%^MAGENTA%^? She frowns "
"slightly and shakes her head to clear it, looking up again with confusion... to the face of the ranger that had been "
"guarding the door previously. %^BLUE%^'%^CYAN%^Aramel%^BLUE%^'%^MAGENTA%^ she whispers under her breath, lowering her "
"eyes to the side as he helps her slowly to her feet, and back into the safety of the temple.");
       break;
     case 12:
       tell_room(TO,"\n%^MAGENTA%^A glipse appears of a %^BLACK%^%^BOLD%^dark%^RESET%^%^MAGENTA%^ and %^ORANGE%^dir"
"%^BLACK%^%^BOLD%^t%^RESET%^%^ORANGE%^y%^MAGENTA%^ jailcell, with the same diminutive, %^BLACK%^%^BOLD%^dark-haired"
"%^RESET%^%^MAGENTA%^ elven figure slumped in the corner. Sounds become audable at the doorway for a second before it "
"slams open, revealing the silhouette of a tall %^RED%^s%^BOLD%^c%^RESET%^%^RED%^ar%^BOLD%^l%^RESET%^%^RED%^et%^MAGENTA%^"
"-haired human male, and a roguish half-elf following a few steps behind. The human stalks toward the elf, directing "
"questions at her in strongly-accented common. The imprisoned elf understands the words but gives them no answer, and so "
"the half-elf begins to translate into her own native tongue.\n\n%^MAGENTA%^Despite their insistance the elf still leaves "
"the questions unanswered, watching the two larger figures before her, visibly intimidated by the pair. After a few short "
"moments the human grows impatient, glaring down at her when still she fails to answer his questions. He steps forward "
"and grabs her by the collar of her robe, snarling %^RED%^'%^WHITE%^Ye were there with 'im, ye aided 'im, we 'ave "
"witnesses.%^RED%^'%^MAGENTA%^ A thought flickers through her mind at the mention... %^CYAN%^he would never have cowered "
"before this... this -human-... he would have died first...%^MAGENTA%^ Her eyes flash with sudden and determined anger as "
"she raises them to match the human's gaze, and the hand hanging by her side begins tracing the patterns of a familiar "
"spell...");
       break;
     case 13:
       tell_room(TO,"\n%^MAGENTA%^Beneath the great tree two elven figures move gracefully in dance, oblivious to all "
"around them, except the %^CYAN%^light musical notes%^MAGENTA%^ from the flute played by a third elf off to the side. "
"Near him sits a fourth, the %^BLACK%^%^BOLD%^dark-haired%^RESET%^%^MAGENTA%^ female, watching on. For a long while there "
"is nothing but the music as the pair sway and weave in time, until one breaks away from the dance and steps across to "
"the %^BLACK%^%^BOLD%^dark-haired%^RESET%^%^MAGENTA%^ elf, taking her hand and dragging her to her feet. She laughs, "
"seeming a little unsure of herself as she follows his lead, but with only a little time she too is relaxed, dancing "
"beside them.");
       break;
     case 14:
       tell_room(TO,"\n%^MAGENTA%^A small, simple temple at night, empty except for three male elven figures, surrounding "
"the single %^BLACK%^%^BOLD%^dark-haired%^RESET%^%^MAGENTA%^ female elf standing weakly in the centre of the room. In one "
"of her shaking hands is tightly clasped a globe of %^YELLOW%^li%^WHITE%^g%^YELLOW%^ht%^RESET%^%^MAGENTA%^, and a %^RED%^"
"trickle of blood%^MAGENTA%^ flows down her arm. %^BLACK%^%^BOLD%^Shadows%^RESET%^%^MAGENTA%^ flicker around the darkened "
"corners of the room as she looks around fearfully, uttering responses to the air as if someone were there to hear them, "
"and tugging half-heartedly at a ring that seems to be stuck on one finger. Two of the male elves watch around warily, "
"one the %^BLUE%^%^BOLD%^blue-eyed%^RESET%^%^MAGENTA%^ ranger with twin blades in his practiced hands, and the other the "
"%^ORANGE%^sable-haired%^MAGENTA%^ priest holding a bright holy symbol. The third, with long %^YELLOW%^blonde%^RESET%^"
"%^MAGENTA%^ hair and robed in the garb of a magus, simply stands by a nearby pillar and watches the female with obvious "
"curiosity.\n\n%^MAGENTA%^Suddenly and without warning, the female cries out and staggers to the floor, clutching at the "
"sides of her head - the ball of light falls from her hand unheeded to the ground beside her. The two guarding elves turn "
"upon hearing the scream, and rush across the room to her side. Her lips move, uttering a name in a faint whisper %^BLUE%^"
"'%^CYAN%^Da... co...?%^BLUE%^'%^MAGENTA%^ The priest puts an arm around the female to steady her, shaking her lightly, "
"%^GREEN%^'Kiya, can you hear me?'%^MAGENTA%^, but she makes no response, as her eyes flutter slowly closed... then flash "
"open again, glowing a %^RED%^%^BOLD%^feral red hue%^RESET%^%^MAGENTA%^. A low %^BLUE%^hiss%^MAGENTA%^ escapes her lips, "
"and both the male elves jump back in fright.");
       break;
     case 15:
       tell_room(TO,"\n%^MAGENTA%^A rooftop open to the air, with %^WHITE%^snow%^MAGENTA%^ falling lightly upon several "
"blankets folded about. Beneath one of these is huddled the %^ORANGE%^sable-haired%^MAGENTA%^ priest, shivering in the "
"obviously %^CYAN%^%^BOLD%^icy-cold%^RESET%^%^MAGENTA%^ air. Beside him on the rooftop sits the armor that usually "
"protects his slim form, as he curls up seeking protection instead from the warm cloth. His teeth chatter quietly as he "
"converses with the elf sitting beside him, the %^BLACK%^%^BOLD%^dark-haired%^RESET%^%^MAGENTA%^ priestess, who seems to "
"be not nearly so bothered by the cold as her companion.\n\n%^MAGENTA%^The female smiles as she speaks, gazing out over "
"the forest a short distance away as %^WHITE%^snowflakes%^MAGENTA%^ drift around her, a few settling lightly in her hair. "
"The priest watches her silently for a few moments, and then she blinks in surprise as he reaches out from beneath the "
"blanket and pulls her gently across beside him. Her initial surprise disappears in a relaxed smile as he leaves a soft "
"kiss upon her cheek, and she snuggles up close into his %^RED%^warm%^MAGENTA%^ embrace.");
       break;
     case 16:
       tell_room(TO,"\n%^MAGENTA%^The smaller %^BLACK%^%^BOLD%^dark-haired%^RESET%^%^MAGENTA%^ elf stands in a darkened "
"cavern, beside a massive %^BLUE%^blue-eyed%^MAGENTA%^ male human in shining plate armor. Despite her impressive company, "
"she seems distinctly nervous in her surroundings, constantly glancing this way and that into the %^BLACK%^%^BOLD%^shadows"
"%^RESET%^%^MAGENTA%^ around her. For time unknown they wait, until eventually several more shapes approach from the "
"darkness - a %^BLUE%^%^BOLD%^blue-eyed%^RESET%^%^MAGENTA%^ elven ranger, walking a few paces ahead of a taller, grizzled "
"human leading a horse, with a motionless elven form draped across its saddle.\n\n%^MAGENTA%^Both the awaiting elf and "
"the human rush to meet the newcomers, checking with worried looks to the second elf in the saddle as she stirs with a "
"groan - she seems terribly weary, with several mostly-superficial %^RED%^%^BOLD%^cuts%^RESET%^%^MAGENTA%^ and %^RED%^"
"marks%^MAGENTA%^ about her face and arms. The ranger swiftly reminds the three gathered with him to beware their "
"surrounds, and with a few careful glances the group of four begin moving out of the cave, in a protective formation "
"around the horse and the elf upon it. Finally they reach a dead end, and the grizzled human presses nods to each of the "
"travellers to trigger their escape.\n\n%^MAGENTA%^The %^BLUE%^%^BOLD%^blue-eyed%^RESET%^%^MAGENTA%^ ranger helps the "
"injured elf from the horse's saddle, prompting her forward, though she seems far too dazed to make any sense of his "
"words. Long moments pass as she fails to react, with the companions sending their wary gazes back into the cave behind "
"them, fearful of pursuit. The human leading the horse shifts his feet with impatience and mutters a few words under his "
"breath, but then abruptly falls silent, as a shaft of %^WHITE%^%^BOLD%^pure-white light%^RESET%^%^MAGENTA%^ spills down "
"into the cave, enveloping the two elven women. Slowly it lifts the pair from the ground into the air, as the brightness "
"grows, and the two forms vanish from view.");
       break;
     case 17:
       tell_room(TO,"\n%^MAGENTA%^The %^BLACK%^%^BOLD%^dark-haired%^RESET%^%^MAGENTA%^ elf slips through a dense jungle, "
"shrouded in arcane concealment. Her steps are silent, her movements cautious as she glances constantly around her. "
"Abruptly she halts, her breath catching in her throat as a great %^GREEN%^sca%^BOLD%^l%^RESET%^%^GREEN%^ed%^MAGENTA%^ "
"foot thuds into the muddy ground before her, and her gaze lifts to reveal a massive dinosaur towering above her. It "
"peers about myopically, sharp teeth %^WHITE%^%^BOLD%^gl%^YELLOW%^i%^WHITE%^nting%^RESET%^%^MAGENTA%^ in the bright sun "
"as it seeks its next meal. With a great roar it stomps away through the bushes... and after a second's hesitation, the "
"terrified elf flees in the opposite direction.");
       break;
     case 18:
       tell_room(TO,"\n%^MAGENTA%^The small temple of the moon, far more crowded than usual, comes into view. The temple "
"is in disarray and strewn with rubble, swarming with humans in some fit of madness as they rush about, breaking and "
"tearing at anything they can get their hands upon. Two elven women, both with long, %^BLACK%^%^BOLD%^black%^RESET%^"
"%^MAGENTA%^ hair and the flowing robes of the priesthood, step in through the doorway, colour draining from their "
"already alabaster features as a %^ORANGE%^sable-haired%^MAGENTA%^ male follows in behind them. One of the females raises "
"her voice, calling for the humans to halt in their destruction - and they do, turning as one to glare angrily at the "
"three elves by the door. Then with a %^RED%^%^BOLD%^shout%^RESET%^%^MAGENTA%^ from one in the crowd, the mob surges "
"forward in a rage, bearing down upon the three tiny elves.");
       break;
     case 19:
       tell_room(TO,"\n%^MAGENTA%^A half-elven male in dark armor stands across the room as the %^BLACK%^%^BOLD%^dark-"
"haired%^RESET%^%^MAGENTA%^ elf steps in, his bestial %^GREEN%^%^BOLD%^gre%^WHITE%^e%^GREEN%^n eyes%^RESET%^%^MAGENTA%^ "
"watching her with an unreadable expression. With a few seconds pause, then not a greeting uttered as he throws questions "
"at her in a cold, confident tone, beginning to pace back and forth as she makes uncertain answers to his words. Slowly "
"his questions spur him to more and more annoyance, as he turns on the elf again.\n\n%^RED%^'I nearly died because of her"
", you and every other elf has turned against me!'%^MAGENTA%^ he accuses, his eyes %^WHITE%^fla%^BOLD%^s%^RESET%^%^WHITE%^"
"hing%^MAGENTA%^ with anger. She pauses, not knowing how to respond, when he doubles over coughing painfully. He raises "
"his hands to hold against the sides of his head, his voice changing from a low growl to finally a scream, as he falls to "
"his knees. The elven woman runs to his side as he sways and falls with a thump to the floor, unconscious.");
       break;
     case 20:
       tell_room(TO,"\n%^MAGENTA%^A quiet clearing, and the same %^BLACK%^%^BOLD%^dark-haired%^RESET%^%^MAGENTA%^ elf "
"sitting crosslegged in the %^GREEN%^long grass%^MAGENTA%^. Resting with paws and head upon one knee is a lithe, slender "
"feline form, stretched out at rest beside her. A bird chirps a cheerful song somewhere in the trees above, while a few "
"feet away, the %^ORANGE%^sable-haired%^MAGENTA%^ priest watches the cheetah with a wary gaze.\n\n%^MAGENTA%^The female's "
"concentration seems elsewhere, as she gazes distantly up at the sky, one hand running absent strokes through the "
"cheetah's %^ORANGE%^sh%^YELLOW%^o%^RESET%^%^ORANGE%^rt f%^BLACK%^%^BOLD%^u%^RESET%^%^ORANGE%^rry%^MAGENTA%^ coat. Still "
"the priest watches the pair, waiting for long moments before finally, and very cautiously, daring to move a little closer"
". The cheetah's ears flicker as it lifts its head to turn its intent %^GREEN%^emerald%^MAGENTA%^ gaze upon the male elf, "
"one lip lifting to reveal very sharp teeth in warning. He quickly shifts back to his original place, mumbling something "
"about walking rugs. Drawn out of her thoughts by the pair, the elven female just grins and shakes her head, ruffling the "
"cheetah's fur with her ungloved hand.");
       break;
     case 21:
       tell_room(TO,"\n%^MAGENTA%^An %^RED%^eerie glow%^MAGENTA%^ lights the darkened cavern around the elf, as she looks "
"around quickly in all directions. A shiver runs through her as she listens to the thundering footfalls echoing off the "
"cave walls, and she clutches her fingers tightly around the %^WHITE%^%^BOLD%^small brooch%^RESET%^%^MAGENTA%^ in her "
"hand. With a glance to the east her breath catches in her throat - with a few quickly spoken words she cloaks herself in "
"%^BLUE%^%^BOLD%^inv%^RESET%^%^BLUE%^i%^BOLD%^sibi%^RESET%^%^BLUE%^l%^BOLD%^ity%^RESET%^%^MAGENTA%^, and with only "
"seconds to spare as a great demon steps into the cavern beside her. Shivering, she keeps back near the wall as the demon "
"looks around, fortunately not sensing the elven form mere metres away. Finally it turns and moves on, but as it leaves "
"the walls rumble ominously, and the elven woman screams and covers her head as the cavern walls come crashing down "
"around her.");
       break;
     case 22:
       tell_room(TO,"\n%^MAGENTA%^Senses return to the elf as she lifts her head - %^RED%^pain%^MAGENTA%^ wracks her "
"body, and bindings are tight about her wrists and feet, while another cloth renders her blinded to her surrounds. A "
"voice hisses in her ear, %^BLUE%^'%^RED%^Do you know who I am, Kiya?%^BLUE%^'%^MAGENTA%^, as someone pins her harshly to "
"the ground. More voices whisper among themselves nearby, as the elven woman shakes her head weakly. The unseen assailant "
"roughly pulls her back by her hair and begins questioning her rapidly, seeming overly eager for answers. Upon "
"discovering after a few moments that the elf knows nothing of the questions, the aggressor drops her back to the ground, "
"kicking her a few times for good measure and demanding her death, when the others present have finished their own "
"questions.\n\n%^MAGENTA%^An acknowledgement from other voices within the room, and farewells are exchanged between "
"several sharp, hissing voices. Finally, footfalls recede into the distance, leaving the elf with only the sound of one "
"other's breathing nearby. In the silence, a hand reaches down toward her, loosing her bindings to let her fall, weak but "
"free, to the ground. A quiet voice speaks in flowing elven, %^BLUE%^'%^WHITE%^Do what you want. You're free. Farewell "
"Kiya.%^BLUE%^'%^MAGENTA%^ The elf inhales deeply, speaking the words of a spell with the last of her strength, as a "
"%^CYAN%^%^BOLD%^blue light%^RESET%^%^MAGENTA%^ grows around her and carries her to safety.");
       break;
     case 23:
       tell_room(TO,"\n%^MAGENTA%^The %^BLACK%^%^BOLD%^dark-haired%^RESET%^%^MAGENTA%^ elven woman sits crosslegged in "
"the grass, surrounded by a quiet gardens overlooking the sea. A few feet away from her is the tall, %^YELLOW%^blonde-"
"haired%^RESET%^%^MAGENTA%^ elven magus, wandering around the garden as he gestures wildly, explaining something with "
"enthusiasm. %^CYAN%^%^BOLD%^'You see, chaos was meant to happen, it's predictable. Nothing chaotic about chaos, really. "
"Don't know why they called it that, really.'%^RESET%^%^MAGENTA%^ He shrugs his delicate shoulders. %^CYAN%^%^BOLD%^"
"'Always keep your mind open'%^RESET%^%^MAGENTA%^ he continues... and then adds in a whisper under his breath, %^CYAN%^"
"%^BOLD%^'but not so open it falls out.'\n\n%^MAGENTA%^He nods a few times as if to himself, continuing to pace and "
"motion wildly as he goes on, %^CYAN%^%^BOLD%^'...so you should expect the unexpected, but even then, don't expect the "
"unexpected because then it becomes expected, which you're not expecting, and then that leads to confusion...'%^RESET%^"
"%^MAGENTA%^ The %^YELLOW%^blonde-haired%^RESET%^%^MAGENTA%^ elf pauses, looking to the female who is watching him with "
"an expression of utter bafflement. He returns her puzzled look with a bright, cheerful smile - %^CYAN%^%^BOLD%^'Easy, "
"no?'");
       break;
     case 24:
       tell_room(TO,"\n%^MAGENTA%^A drow female with %^WHITE%^long white hair%^MAGENTA%^ slips out of the %^BLACK%^"
"%^BOLD%^shadows of night%^RESET%^%^MAGENTA%^ into the temple without a sound, concealed as a shadow within spells of "
"magecraft. She freezes partway inside the door - at this dark hour the temple would usually be almost deserted, but a "
"%^ORANGE%^sable-haired%^MAGENTA%^ male elf is sitting on a bench nearby, head resting in his hands. The drow pauses and "
"studies him a moment, uncertainity painted across her features.\n\n%^MAGENTA%^A few moments pass, and she steps out "
"tentatively toward him. He lifts his head upon hearing her faint footsteps brushing the floor, looking around for the "
"source of the sound. Without understanding why, the drow reaches out a shaking hand, drawing it in a %^ORANGE%^light "
"caress%^MAGENTA%^ against his cheek. The elf flinches and pulls away from the touch, calling out a prayer to Torm as "
"the air around him %^WHITE%^%^BOLD%^sh%^CYAN%^i%^WHITE%^mm%^YELLOW%^e%^WHITE%^rs%^RESET%^%^MAGENTA%^ and the drow's "
"spell of concealment falls, causing her to flicker into view. She stumbles away from him in fright, disappearing out "
"through the doorway into the night beyond.");
       break;
     case 25:
       tell_room(TO,"\n%^MAGENTA%^A tall %^BLACK%^%^BOLD%^black-haired%^RESET%^%^MAGENTA%^ male elf in a warrior's armor "
"moves cautiously along the road, carrying the still body of the same drow female in his arms. As he continues onward she "
"groans, regaining consciousness, and slips from his hold to the ground with a disoriented look in her %^RED%^dark eyes"
"%^MAGENTA%^. She forces herself to stand, calling a name after him in broken elven %^BLUE%^'%^CYAN%^Maryn?%^BLUE%^'"
"%^MAGENTA%^ Maryn halts his steps and turns back to her, glancing up and down the road to check for onlookers, before "
"wrapping the drow in a tight hug.\n\n%^MAGENTA%^She smiles a little as he steps back and opens his mouth to speak, when "
"a %^CYAN%^%^BOLD%^bright light%^RESET%^%^MAGENTA%^ coalesces in the air before them and a human appears from the mists. "
"Before either can react, the human magus narrows his eyes upon the drow and screams out the arcane words of a spell, "
"forcing her to stagger back stunned; the elf Maryn shouts out a %^RED%^%^BOLD%^cry of fury%^RESET%^%^MAGENTA%^ and "
"draws his blade, rushing weapon-first at the human before him.");
       break;
     case 26:
       tell_room(TO,"\n%^MAGENTA%^An ornately-decorated %^WHITE%^marble%^MAGENTA%^ temple, and the drow female kneeling "
"to rest on the floor, while two elven males stand nearby. Under the %^ORANGE%^sable-haired%^MAGENTA%^ elven priest's "
"gaze is a third elf, %^BLACK%^%^BOLD%^dark-robed%^RESET%^%^MAGENTA%^ and bound at the hands and feet. The other, a "
"tall warrior elf, stands protectively over the drow while the priest questions the captive, impatience lining his "
"features as his patience wears thin.\n\n%^MAGENTA%^Finally, he seems to get the answer he sought - he turns, and begins "
"speaking a strange chant over the drow as she watches him in confusion. He stumbles over a few of the strange-sounding "
"words, but finally pronounces the last syllable with confidence, as a ray of %^WHITE%^%^BOLD%^pure light%^RESET%^"
"%^MAGENTA%^ shoots down from above, landing upon the drow and swirling around her. She closes her eyes against the "
"light, disappearing from view within the blinding brightness... then in an instant the illumination vanishes, and the "
"%^BLACK%^%^BOLD%^dark-haired%^RESET%^%^MAGENTA%^ elven woman slumps to the marble floor in its wake.");
       break;
     case 27:
       tell_room(TO,"\n%^MAGENTA%^The elven woman stands before the gates of a %^BLACK%^%^BOLD%^grand, dark tower%^RESET%^"
"%^MAGENTA%^, reading a page of impeccably-written text while a human and half-elf stand nearby. Moments pass as she "
"scans the paper, then looks up to the pair before her, directing several questions to them concerning the page. For a "
"long while she seems to be considering something in her mind, and eventually when the questions are answered and the "
"three fall silent, she exhales slowly and nods her head, %^BLUE%^'%^CYAN%^I will help then, if I can...%^BLUE%^'"
"%^MAGENTA%^ The two taller magi nod approvingly, and the half-elf turns to the gates and opens them with a snap of his "
"fingers, leading the way inside. The human follows, speaking with precise dictum %^BOLD%^%^BLUE%^'%^WHITE%^Welcome to "
"the Spheres, Kiya.%^BLUE%^'");
       break;
     case 28:
       tell_room(TO,"\n%^MAGENTA%^The ornate temple of the moon, with the domed roof arching over several elves below. "
"The %^ORANGE%^sable-haired%^MAGENTA%^ priest sits upon a bench, arms wrapped about the %^BLACK%^%^BOLD%^dark-haired"
"%^RESET%^%^MAGENTA%^ elven female. Another two elves, one male and one female, stand by the doorway as they watch a "
"tall elven warrior pace about the room before them. He abruptly turns on his heel to face them all as he snaps his "
"fingers, %^BOLD%^%^CYAN%^'%^WHITE%^Hey I just thought of a title for myself - Maryn! What do you think?%^CYAN%^'\n\n"
"%^MAGENTA%^The %^BLACK%^%^BOLD%^dark-haired%^RESET%^%^MAGENTA%^ elven woman looks to him curiously, %^BLUE%^'%^CYAN%^"
"What would that make you? Maryn the Maryn?%^BLUE%^' %^BOLD%^%^CYAN%^'%^WHITE%^INDEED!%^CYAN%^'%^RESET%^%^MAGENTA%^ he "
"replies immediately. Her and her companion try to hide their laughter as the pair by the doorway just watch on with "
"looks of puzzlement. Again the female speaks %^BLUE%^'%^CYAN%^You're going to confuse someone shortly...%^BLUE%^'"
"%^MAGENTA%^ The warrior glances to the two elves at the doorway and grins broadly - %^BOLD%^%^CYAN%^'%^WHITE%^Too late "
"I think.%^CYAN%^'");
       break;
     case 29:
       tell_room(TO,"\n%^MAGENTA%^The last rays of sunset fall upon three figures in the desert sands. Two are elven, one "
"a female of %^BLACK%^%^BOLD%^dark hair%^RESET%^%^MAGENTA%^ and the other male, taller with %^YELLOW%^long blonde locks"
"%^RESET%^%^MAGENTA%^. Beside them is another elven figure, but with %^WHITE%^pure-white%^MAGENTA%^ hair and skin the "
"colour of %^BLACK%^%^BOLD%^onyx%^RESET%^%^MAGENTA%^. He lies in the sand, cloak wrapped tightly around him as he rests, "
"while the two elves watch over him - at a closer look, both his arms end in short stumps, where his hands should be.\n\n"
"%^MAGENTA%^The female sighs, shaking her head and gazing back east toward the ocean. Beside her the male nudges her once"
", then again and again until finally he has her attention. %^BLUE%^'%^CYAN%^You will be the death of me one day%^BLUE%^'"
"%^MAGENTA%^ she tells him, a slight smile touching at the edges of her lips. He just grins and nudges her again, %^CYAN%^"
"%^BOLD%^'Aww, well, it will be a pleasant death.'%^RESET%^%^MAGENTA%^ She looks down upon the slumbering, shrouded form "
"in the sand beside her, mumbling under her breath %^BLUE%^'%^CYAN%^I trust Her guidance... but it has to be a drow of "
"all things...%^BLUE%^'%^MAGENTA%^ And yet despite this, looking upon the seemingly defenseless sleeper, another emotion "
"brushes at her senses... pity... for a drow?");
       break;
     case 30:
       tell_room(TO,"\n%^MAGENTA%^Tall trees surround the grassy clearing, where a %^CYAN%^%^BOLD%^s%^RESET%^%^CYAN%^a"
"%^BLUE%^p%^BOLD%^ph%^RESET%^%^BLUE%^i%^CYAN%^r%^BOLD%^e%^RESET%^%^MAGENTA%^-%^CYAN%^%^BOLD%^e%^RESET%^%^CYAN%^y%^BLUE%^e"
"%^CYAN%^d%^MAGENTA%^ elven woman sits in wait beside a %^WHITE%^white-haired%^MAGENTA%^ half-elven male. He is clad in "
"leather and well-worn garments, with the bearing of being quite relaxed in his surroundings, and yet with the ability to "
"be on his feet at a mere second's notice. Across the clearing from the pair, a few faded leaves fall from the trees "
"above onto the lake's %^CYAN%^cl%^BOLD%^e%^WHITE%^a%^RESET%^%^CYAN%^r su%^WHITE%^%^BOLD%^r%^RESET%^%^CYAN%^face"
"%^MAGENTA%^, near which is set a tall %^ORANGE%^wooden statue%^MAGENTA%^ of several elven figures.\n\n%^MAGENTA%^A few "
"moments later, and into the clearing steps the same %^BLACK%^%^BOLD%^dark-haired%^RESET%^%^MAGENTA%^ elf. She pauses to "
"smile and incline her head toward the second woman of her kin, offering greetings in flowing elven speech. The sapphire-"
"eyed woman stands, returning the smile and greetings with her own, then turning as she gestures to her companion, "
"%^CYAN%^%^BOLD%^'%^WHITE%^I don't believe you've both met?%^CYAN%^'%^RESET%^%^MAGENTA%^ The half-elf nods toward the "
"newcomer, speaking with a smile %^WHITE%^'Well met Kiya, I am Zeal Marcivious.'");
       break;
     case 31:
       tell_room(TO,"\n%^MAGENTA%^The elven woman steps quietly into the empty room, pulling the door shut behind her. "
"Her gaze slowly moves around the familiar settings of the room, obviously of human design but crafted entirely of "
"%^ORANGE%^faded oak furniture%^MAGENTA%^ and cloth of soft hues. She relaxes only slightly, her footsteps drawing her "
"across the room to stand before the mirror resting upon the dresser. %^GREEN%^Deep gre%^BOLD%^e%^RESET%^%^GREEN%^n eyes"
"%^MAGENTA%^ gaze back at her from her reflection, as she raises one hand slowly to run over the %^WHITE%^pure silver "
"streak%^MAGENTA%^ of hair among her %^BLACK%^%^BOLD%^black locks%^RESET%^%^MAGENTA%^. She sighs with a shake of her "
"head, turning away from the image in the glass as her hand falls back to her side.");
       break;
     case 32:
       tell_room(TO,"\n%^BLACK%^%^BOLD%^Dark-stained walls%^RESET%^%^MAGENTA%^ rise around the perimeter of the temple, "
"where smells of %^BLUE%^fear%^MAGENTA%^ and %^RED%^blood%^MAGENTA%^ fill the air, mingling with feral animalistic cries"
". Within the room is a %^RED%^blo%^BOLD%^o%^RESET%^%^RED%^d-sta%^BLACK%^%^BOLD%^i%^RESET%^%^RED%^ned%^MAGENTA%^ altar, "
"beside which stands a black-haired elven priest, growling prayers to the god of the temple. Upon the altar is another "
"elven form, but %^YELLOW%^blonde-haired%^RESET%^%^MAGENTA%^ and %^GREEN%^%^BOLD%^em%^WHITE%^e%^GREEN%^ra%^RESET%^"
"%^GREEN%^l%^BOLD%^d-ey%^WHITE%^e%^GREEN%^d%^RESET%^%^MAGENTA%^, and bound at the hands and feet. She shifts fearfully "
"within her restraints, and the priest pauses only for a second, to spare a malevolent smile down upon her.\n\n%^MAGENTA%^"
"Under cover of %^BLUE%^%^BOLD%^inv%^RESET%^%^BLUE%^i%^BOLD%^sibi%^RESET%^%^BLUE%^l%^BOLD%^ity%^RESET%^%^MAGENTA%^, the "
"%^BLACK%^%^BOLD%^dark-haired%^RESET%^%^MAGENTA%^ elf slips into the room, a shiver running down her spine at the sounds "
"and smells around her. Slowly she steps forward with perfectly-silent footfalls while the male elf pays no notice, "
"entirely engrossed within his prayers. She reaches the altar, slipping one hand beneath the body of the %^YELLOW%^blonde"
"-haired%^RESET%^%^MAGENTA%^ elf upon the altar - half-lifting her from the stone, she murmurs under her breath in a "
"prayer of her own, and in a matter of seconds her spell lifts the two women from the room.");
       break;
     case 33:
       tell_room(TO,"\n%^MAGENTA%^Two elven women stand within the %^WHITE%^mar%^BOLD%^b%^RESET%^%^WHITE%^le-wa%^CYAN%^"
"%^BOLD%^l%^RESET%^%^WHITE%^led%^MAGENTA%^ temple of the moon, facing the drow silhouette figure who stands before them. "
"One of the two elves steps forward, %^CYAN%^%^BOLD%^s%^RESET%^%^CYAN%^a%^BLUE%^p%^BOLD%^ph%^RESET%^%^BLUE%^i%^CYAN%^r"
"%^BOLD%^e e%^RESET%^%^CYAN%^y%^BLUE%^e%^CYAN%^s%^MAGENTA%^ shimmering as she beseeches her goddess for aid, and %^WHITE%^"
"%^BOLD%^beams of moonlight%^RESET%^%^MAGENTA%^ fall from the dome above, bathing the three below in a pale glow. The "
"second elf, the same %^BLACK%^%^BOLD%^dark-haired%^RESET%^%^MAGENTA%^ priestess, remains a few paces back as she adds "
"her voice to the prayer in a lower tone, and %^CYAN%^%^BOLD%^fa%^WHITE%^in%^CYAN%^t l%^WHITE%^ig%^CYAN%^ht%^RESET%^"
"%^MAGENTA%^ forms around brooch in her hand, merging with the glow around her.\n\n%^MAGENTA%^The illumination %^WHITE%^"
"%^BOLD%^int%^YELLOW%^e%^WHITE%^nsi%^YELLOW%^f%^WHITE%^ies%^RESET%^%^MAGENTA%^, becoming almost painfully bright around "
"the dark-elf's form. The %^CYAN%^%^BOLD%^s%^RESET%^%^CYAN%^a%^BLUE%^p%^BOLD%^ph%^RESET%^%^BLUE%^i%^CYAN%^r%^BOLD%^e"
"%^RESET%^%^MAGENTA%^-%^CYAN%^%^BOLD%^e%^RESET%^%^CYAN%^y%^BLUE%^e%^CYAN%^d%^MAGENTA%^ priestess gestures to the drow and "
"he extends the stumps that remain of his arms. As they pass into the moonlight, it seems the ghostly gray outline of the "
"arms he once had are visible again... and he flexes the fingertips that are suddenly again at his command. A look of "
"wonderment fills his eyes as he opens his mouth to speak, and his missing tongue is replaced by one of shining silver. "
"He chokes on the words that go unsaid, shock leaving him speechless. The harmonious voices of the elven priestesses "
"suddenly fall silent, as the light abruptly snuffs out and the two women slip to the floor, completely exhausted.");
       break;
     case 34:
       tell_room(TO,"\n%^MAGENTA%^A small crowd of travellers, mostly elven, are gathered within the temple speaking in "
"hushed tones. As one they look up as a lone figure stumbles in from the road - human, female and only within perhaps her "
"second decade of life. She has a %^ORANGE%^wi%^BLACK%^%^BOLD%^l%^RESET%^%^ORANGE%^d%^MAGENTA%^ look about her, with her "
"hair and clothes in disarray, glancing this way and that with one hand held over her stomach as if in pain. She groans, "
"falling weakly to the floor as a few of the elves dart across the room to aid her, amidst murmurs of %^GREEN%^'"
"...another one...'%^MAGENTA%^ and %^ORANGE%^'...not again...'\n\n%^MAGENTA%^From the group one elf steps forward, "
"%^CYAN%^%^BOLD%^s%^RESET%^%^CYAN%^a%^BLUE%^p%^BOLD%^ph%^RESET%^%^BLUE%^i%^CYAN%^r%^BOLD%^e%^RESET%^%^MAGENTA%^-%^CYAN%^"
"%^BOLD%^e%^RESET%^%^CYAN%^y%^BLUE%^e%^CYAN%^d%^MAGENTA%^ and with a confident demeanor. From within a sack she takes a "
"vial of liquid, kneeling beside the human girl and lifting her head, gently helping her to drink the liquid within it. "
"The girl swallows the liquid and gasps, doubling over and clutching her stomach. She chokes a few times for breath and "
"her eyes take on a glassy sheen - as a multitude of %^BLACK%^%^BOLD%^sp%^RESET%^%^RED%^i%^BLACK%^%^BOLD%^de%^BLUE%^r"
"%^BLACK%^s%^RESET%^%^MAGENTA%^ spill forth from her mouth, admidst screams from the acolytes and elves nearby.");
       break;
     case 35:
       tell_room(TO,"\n%^MAGENTA%^The vast temple of the moon, still in the dark of night, and empty except for the "
"%^BLACK%^%^BOLD%^dark-haired%^RESET%^%^MAGENTA%^ elven woman, head bowed in prayer. From the shadows behind her steps a "
"half-elven figure, with an %^WHITE%^%^BOLD%^ab%^BLACK%^a%^WHITE%^l%^BLACK%^a%^WHITE%^ster%^RESET%^%^MAGENTA%^ complexion "
"and %^RED%^%^BOLD%^w%^RESET%^%^RED%^il%^BOLD%^d r%^RESET%^%^RED%^e%^BOLD%^d%^RESET%^%^MAGENTA%^ hair. She turns on her "
"heel as she senses his presence, stepping back a pace and looking over him with a wary gaze. His oddly %^BLACK%^%^BOLD%^"
"m%^RESET%^%^GREEN%^i%^BOLD%^s%^RESET%^%^GREEN%^m%^BLACK%^%^BOLD%^a%^CYAN%^t%^RESET%^%^CYAN%^c%^BLUE%^%^BOLD%^h%^RESET%^"
"%^CYAN%^e%^BOLD%^d%^RESET%^%^MAGENTA%^ eyes flicker as he steps forward, %^BLACK%^%^BOLD%^unnatural shadows%^RESET%^"
"%^MAGENTA%^ following his movements.\n\n%^MAGENTA%^He looks down upon the shorter elf, and long moments pass in silence "
"before he speaks quietly, %^BLUE%^%^BOLD%^'%^RED%^you... you hold a place in his heart...%^BLUE%^'%^RESET%^%^MAGENTA%^ "
"He winces, one hand moving to cover his %^BLUE%^blue%^MAGENTA%^ eye - he blinks once and shakes his head, beginning to "
"pace around the elven woman. She continues to watch him cautiously as he stalks around her, and again his lips part in a "
"whisper of speech, %^BLUE%^%^BOLD%^'%^RED%^why... why does he care so much... for those who do not care for him"
"...?%^BLUE%^'");
       break;
     case 36:
       tell_room(TO,"\n%^BLACK%^%^BOLD%^Dusky twilight%^RESET%^%^MAGENTA%^ settles around the garden, cloaking the view "
"of the distant ocean in darkness. Upon a bench a little back from the cliffside is the same dark-elven figure, shrouded "
"in a %^BLACK%^%^BOLD%^shadowy cloak%^RESET%^%^MAGENTA%^, and with a %^WHITE%^%^BOLD%^bright pendant%^RESET%^%^MAGENTA%^ "
"hanging from his neck. Sitting in the grass facing him is the dark-haired elven woman, mending a %^CYAN%^pale azure robe"
"%^MAGENTA%^ with careful stitches. For a short while he simply watches her, until finally he breaks the silence with "
"hesitant speech, %^BLUE%^'%^WHITE%^Kiahnlliya...?%^BLUE%^'\n\n%^MAGENTA%^She glances up at the sound of her name, and he "
"extends one %^WHITE%^pale hand%^MAGENTA%^ to touch lightly against the %^RED%^sc%^MAGENTA%^a%^RED%^r%^MAGENTA%^ upon her "
"cheek, %^BLUE%^'%^WHITE%^How did you get this?%^BLUE%^'%^MAGENTA%^ She freezes at the mention, her %^GREEN%^ey%^BOLD%^e"
"%^RESET%^%^GREEN%^s%^MAGENTA%^ meeting his, showing her obvious surprise and wariness of the question. Seconds pass and "
"she seems on the edge of replying, when the %^CYAN%^%^BOLD%^s%^RESET%^%^CYAN%^a%^BLUE%^p%^BOLD%^ph%^RESET%^%^BLUE%^i"
"%^CYAN%^r%^BOLD%^e%^RESET%^%^MAGENTA%^-%^CYAN%^%^BOLD%^e%^RESET%^%^CYAN%^y%^BLUE%^e%^CYAN%^d%^MAGENTA%^ elven priestess "
"steps into the room, and the drow drops his hand, lowering his gaze to the ground.");
       break;
     case 37:
       tell_room(TO,"\n%^MAGENTA%^The %^BLACK%^%^BOLD%^dark-haired%^RESET%^%^MAGENTA%^ elven woman stands within the same "
"marble temple, head bowed in prayer. Her eyes move quickly to the doorway as loud footsteps interrupt her thoughts - a "
"%^ORANGE%^ba%^BLACK%^%^BOLD%^r%^RESET%^%^ORANGE%^bar%^RED%^i%^ORANGE%^c%^MAGENTA%^-looking half-orc stands there, "
"covered in cuts and scars. Her %^GREEN%^gr%^BOLD%^e%^WHITE%^e%^RESET%^%^GREEN%^n%^MAGENTA%^ eyes narrow sharply as she "
"recognizes the intruder, and she rises to her feet with a hiss, %^BLUE%^'%^CYAN%^You that would slay my kin, give me one "
"reason not to strike you down where you stand.%^BLUE%^'%^MAGENTA%^ The half-orc backs away in obvious fright, despite "
"his size compared to the diminutive elf before him. The elven woman's gloved hand clenches and she advances a step; a "
"mere second later the %^CYAN%^%^BOLD%^s%^RESET%^%^CYAN%^a%^BLUE%^p%^BOLD%^ph%^RESET%^%^BLUE%^i%^CYAN%^r%^BOLD%^e%^RESET%^"
"%^MAGENTA%^-%^CYAN%^%^BOLD%^e%^RESET%^%^CYAN%^y%^BLUE%^e%^CYAN%^d%^MAGENTA%^ elven priestess appears beside her by "
"spellcast.\n\n%^MAGENTA%^The half-orc jumps back in surprise, and the newly-arrived priestess moves forward, speaking in "
"a silvery tone %^CYAN%^%^BOLD%^'%^WHITE%^Don't worry, I can handle this.%^CYAN%^'%^RESET%^%^MAGENTA%^ The first elven "
"woman looks to the priestess, and then to the half-orc, hesitance apparent upon her face. A moment passes, until she "
"nods and relinquishes the situation to her superior, slipping into her native speech to speak a farewell to the priestess"
". Finally, she turns her gaze to the half-orc, enunciating clearly, %^BLUE%^'%^CYAN%^If I hear or see -anything- of you "
"troubling elvenkin again, I'll find you myself. You've been warned.%^BLUE%^'%^MAGENTA%^ Without another word she turns "
"and disappears down the temple's back corridor.");
       break;
     case 38:
       tell_room(TO,"\n%^MAGENTA%^Upon the %^RED%^bloodstained%^MAGENTA%^ altar lies the form of the %^BLACK%^%^BOLD%^dark"
"-haired%^RESET%^%^MAGENTA%^ elf; countless deep cuts and slashes mar her skin, only freshly left and still %^RED%^"
"%^BOLD%^b%^RESET%^%^RED%^le%^BOLD%^ed%^RESET%^%^RED%^in%^BOLD%^g%^RESET%^%^MAGENTA%^, barely covered by the tatters of "
"cloth that remain clinging to her body. She makes no movement, all strength seemingly gone from her body, and her eyes "
"glazed and unfocussed. Over her stands another elven figure, with a look of triumph upon his face and an empty, stained "
"bottle in his hand, yelling aloud to his god. A wild wolf sits by his side, shifting uneasily and pawing at the ground, "
"as the priest turns his %^BLUE%^%^BOLD%^fe%^CYAN%^r%^BLUE%^vent%^RESET%^%^MAGENTA%^ gaze toward the doorway.\n\n"
"%^MAGENTA%^A sudden peal of %^YELLOW%^thu%^WHITE%^n%^YELLOW%^der%^RESET%^%^MAGENTA%^ crashes outside the temple, as the "
"wolf whines and shies away from the door. %^BLACK%^%^BOLD%^Darkness%^RESET%^%^MAGENTA%^ fills the room, and the priest "
"spreads his arms %^GREEN%^'%^BOLD%^%^RED%^He's coming for you!%^RESET%^%^GREEN%^'%^MAGENTA%^ The terrified wolf takes on "
"a possessed look, scampering forward to gnaw at the ropes binding the woman's limbs, and then retreating with its tail "
"between its legs. A hideous laughter fills the temple, as an unearthly voice booms %^RED%^'Run... Begin the hunt... RUN!'"
"%^MAGENTA%^ A wild look of terror fills the elven woman's eyes, as she finds the will to slip from the altar, and drag "
"herself painstakingly across the floor and out of the doorway, leaving a trail of %^RED%^blood%^MAGENTA%^ in her wake.");
       break;
     case 39:
       tell_room(TO,"\n%^MAGENTA%^Faint streaks of %^CYAN%^%^BOLD%^co%^MAGENTA%^l%^YELLOW%^ou%^CYAN%^r%^RESET%^"
"%^MAGENTA%^ light the morning sky above the elven woman, who stands a few feet back from the cliff's edge where another "
"%^BLACK%^%^BOLD%^shadowy%^RESET%^%^MAGENTA%^ figure kneels before her - the drow from past visions. His hair catches in "
"the wind as the first rays of the sun's light appear over the ocean's distant horizon, striking his eyes painfully as he "
"whispers %^BLUE%^'%^WHITE%^Let us end it, Kiahnlliya.%^BLUE%^'%^MAGENTA%^ The elven woman lowers her eyes, murmuring a "
"prayer under her breath as she slowly raises a hand above her head. She hesitates a moment longer... and then calls upon "
"her goddess, as a bolt of %^YELLOW%^li%^WHITE%^g%^YELLOW%^htn%^WHITE%^i%^YELLOW%^ng%^RESET%^%^MAGENTA%^ streaks down "
"upon the drow from the heavens above, and he slumps to the ground, one last breath escaping his lips.\n\n%^MAGENTA%^A "
"few tears roll down the elf's cheeks as she falls to her knees beside the motionless body, lifting it from the ground in "
"her arms. She calls upon a spell as the weave envelopes her, and she reappears kneeling in a %^GREEN%^%^BOLD%^grassy "
"meadow%^RESET%^%^MAGENTA%^, beneath the overhanging branches of an ancient chestnut tree. Gently she rests the body down "
"upon the ground, wrapping the %^BLACK%^%^BOLD%^shadowy cloak%^RESET%^%^MAGENTA%^ carefully around it and brushing a few "
"whisps of %^WHITE%^fine white hair%^MAGENTA%^ away from its face.\n\n%^MAGENTA%^Closing her eyes, she extends both hands "
"to touch lightly against the figure's forehead, murmuring prayers for blessing and guidance in a shaking voice. Silence "
"follows for time uncounted, as she remains alone with her thoughts and the body beside her. Finally, she stands slowly "
"and steps back a pace, softly murmuring %^BLUE%^'%^CYAN%^Farewell my friend... may the Lady grant you peace where you could find none here...%^BLUE%^'%^MAGENTA%^ She raises her voice again to her goddess, as a pillar of %^WHITE%^silvery "
"flame%^MAGENTA%^ descends upon the body... and seconds later when the fire dissipates, only the unburnt grass remains.");
       break;
     case 40:
       tell_room(TO,"\n%^MAGENTA%^Around the tidy garden are several adventurers, relaxing in the quiet surroundings. A "
"battleworn half-elf stands by, watching another half-elf, who is sitting with a %^YELLOW%^blonde-haired%^RESET%^"
"%^MAGENTA%^ elven woman on his lap, and looking more than a little uncomfortable about it. Across from them sits another "
"elven priestess with %^WHITE%^shi%^WHITE%^%^BOLD%^m%^RESET%^%^WHITE%^mer%^BOLD%^i%^RESET%^%^WHITE%^ng%^MAGENTA%^ robes; "
"beside her lies a human warrior with %^WHITE%^sc%^BLACK%^%^BOLD%^r%^RESET%^%^ORANGE%^u%^WHITE%^ffy %^YELLOW%^go%^RESET%^"
"%^ORANGE%^ld%^YELLOW%^en%^RESET%^%^MAGENTA%^ hair, tinkering with a dagger. All five look up as a %^RED%^%^BOLD%^scarlet-"
"haired%^RESET%^%^MAGENTA%^ human steps in. The %^BLACK%^%^BOLD%^dark-haired%^RESET%^%^MAGENTA%^ priestess is obviously "
"bothered by his presence, asking %^BLUE%^'%^CYAN%^I suppose there is a reason you grace us with your presence, Saradin? "
"Again?%^BLUE%^'\n\n%^RED%^'%^WHITE%^ecause I just love seein' ye, Kiya%^RED%^'%^MAGENTA%^ he replies, to which she "
"narrows her eyes, mumbling %^BLUE%^'%^CYAN%^I bet%^BLUE%^'%^MAGENTA%^ under her breath. She pointedly turns away to "
"ignore him, and returns to speaking with the human beside her in hushed whispers, as conversation takes up between "
"Saradin and the rest. The priestess looks back again, sending an irritated glare at the %^RED%^%^BOLD%^scarlet-haired"
"%^RESET%^%^MAGENTA%^ human. The man beside her watches the clouds roll across the sky, nudging the elf and pointing up, "
"with a whisper %^ORANGE%^'%^WHITE%^%^BOLD%^That cloud over there looks like a whale...%^RESET%^%^ORANGE%^'%^MAGENTA%^ "
"She turns with a wry smile to him as he nods sagely, %^BLUE%^'%^CYAN%^You're something else, you know that?%^BLUE%^'"
"%^MAGENTA%^ He just laughs, as she reaches down and ruffles his already-scruffy hair.");
       break;
     case 41:
       tell_room(TO,"\n%^MAGENTA%^A great crowd of travellers approach the jail-cells through the %^RED%^%^BOLD%^inte"
"%^YELLOW%^n%^RED%^se%^RESET%^%^MAGENTA%^ heat. Among their number are six elves and four humans, as well as a half-elf, "
"a tall voadkyn, and an elemental of water, struggling in the smouldering temperature. %^RED%^Lava%^MAGENTA%^ laps at the "
"sides of the rock path as they cross cautiously, nearing close enough to see the three captives within the cells: two "
"humans, and a half-elf. One human has the frail appearance and flowing robes of a magus, while the second holds himself "
"with proud bearing despite his imprisonment... and two of the elven woman rush forward upon recognizing the half-elf, "
"with a joint cry of %^CYAN%^'%^WHITE%^%^BOLD%^Zeal!?%^RESET%^%^CYAN%^'");
       break;
     case 42:
       tell_room(TO,"\n%^MAGENTA%^Just out of view of the mountaintop, a small group of travellers huddle warily upon the "
"stairs, the %^BLACK%^%^BOLD%^dark-haired%^RESET%^%^MAGENTA%^ elven woman among them. One by one the spellcasters among "
"them summon a hoard of snakes, monsters, shimmering bats and an elemental. %^CYAN%^Auras%^MAGENTA%^ flicker into "
"existance around the group, and the three magi begin blinking in and out of place. With a nod from their leader, a "
"blade-wielding half-elf, the group moves as one, around the last rocky outcropping to the flat mountaintop. They are "
"greeted by a %^YELLOW%^dea%^RESET%^%^ORANGE%^f%^YELLOW%^en%^RESET%^%^ORANGE%^i%^YELLOW%^ng%^RESET%^%^MAGENTA%^ roar, as "
"a gargantuan %^RED%^red wyrm%^MAGENTA%^ unfolds its wings and bears down upon the group.\n\n%^MAGENTA%^The half-elven "
"ranger and the two human warriors, one %^WHITE%^sc%^BLACK%^%^BOLD%^r%^RESET%^%^ORANGE%^u%^WHITE%^ffy%^MAGENTA%^-haired, "
"and the other another much older, rush forward to meet the dragon, all landing hit after hit upon its thick hide. "
"Another elven ranger battles alongside them, struggling to leave an occasional wound. Behind them, an elven woman with "
"%^RED%^rose-%^BOLD%^red%^RESET%^%^MAGENTA%^ hair throws arcs of %^YELLOW%^li%^WHITE%^g%^YELLOW%^htn%^WHITE%^i%^YELLOW%^"
"ng%^RESET%^%^MAGENTA%^ across the room at their foe, while a human priestess chants spells of healing over her. Another "
"elven male blinks across the room, as the dragon rears its head, spewing forth a %^RED%^%^BOLD%^bla%^YELLOW%^z%^RED%^ing "
"f%^RESET%^%^RED%^l%^BOLD%^ame%^RESET%^%^MAGENTA%^ upon the entire mountaintop! The %^BLACK%^%^BOLD%^dark-haired%^RESET%^"
"%^MAGENTA%^ elf staggers to her knees, barely alive, as four of the eight companions slump lifelessly to the stony "
"ground around her.");
       break;
     case 43:
       tell_room(TO,"\n%^MAGENTA%^The same elven woman sitting crosslegged on the floor of a marble temple, with a slip "
"of paper sitting flat on the ground before her. She concentrates intently, sketching as best she can with a quill in her "
"hand. Upon the paper slowly appears an image of a building made of %^ORANGE%^stone%^MAGENTA%^, half-open to the air with "
"steps leading up to it through long grass. Above it overhangs the branches of a great tree, brushing the rooftop with "
"its %^GREEN%^leaves%^MAGENTA%^. Blowing lightly on the paper to dry the ink, she lifts the page and checks carefully "
"over it. She smiles and nods to herself, folding up the page and slipping it into a pocket of her robes.");
       break;
     case 44:
       tell_room(TO,"\n%^MAGENTA%^A bustling city street where humans and a few half-humans go about their business, "
"barely heeding the smaller elven woman as she passes by. She pays them little attention either, moving with silent "
"footsteps to approach a street-vendor selling reams of cloth. She stops to look over the different cloths offered, "
"eventually deciding on one and requesting to purchase it from the vendor. The vendor turns to her with a cold stare, "
"and refuses the offered coin, uttering %^BLUE%^'%^WHITE%^Oh, I've heard all about you. Leave my shop scum, I will not "
"serve you.%^BLUE%^'%^MAGENTA%^ The elf blinks once, twice, a stunned expression on her face for a moment - then finally "
"she backs away, turns and disappears into the crowd.");
       break;
     case 45:
       tell_room(TO,"\n%^MAGENTA%^The %^BLACK%^%^BOLD%^dark-haired%^RESET%^%^MAGENTA%^ elf slips in through the doorway, "
"concealed within her magecraft. Around her are several women, clad in %^WHITE%^silken robes%^MAGENTA%^ that hide nothing "
"of their bodies, and over them a taller human guard watches sternly, with a sharply-curved blade wielded in each muscled "
"hand. The elf chants quietly under her breath, summoning %^WHITE%^stone armor%^MAGENTA%^, %^BOLD%^mag%^RED%^i%^MAGENTA%^"
"cal fla%^RED%^m%^MAGENTA%^es%^RESET%^%^MAGENTA%^ and a hoard of creatures to protect her. Finally, she steps forward and "
"calls a cry to her goddess, sending a %^WHITE%^%^BOLD%^beam of moonlight%^RESET%^%^MAGENTA%^ directly at the armed male "
"across the room, as suddenly the world turns %^BLACK%^%^BOLD%^dark%^RESET%^%^MAGENTA%^ around her.\n\n%^MAGENTA%^Moments "
"later she recovers her senses, barely standing and breathing heavily. She looks around her, while the %^BLACK%^%^BOLD%^"
"haziness%^RESET%^%^MAGENTA%^ slowly clears from her mind. Somehow she cannot remember the fight or anything that "
"occurred, and yet across the floor are spread countless bodies - both summoned creatures and humans alike. Scattered "
"around are a few broken pieces of the stone that had protected her, and her body is criss-crossed with %^RED%^cuts"
"%^MAGENTA%^ and %^RED%^%^BOLD%^slas%^RESET%^%^RED%^h%^BOLD%^es%^RESET%^%^MAGENTA%^ from the blades that now lie unheeded "
"beside the guard's corpse. An uncontrollable shiver runs through her body, and she turns and flees from the room.");
       break;
     case 46:
       tell_room(TO,"\n%^MAGENTA%^Her face hidden for a moment with her back turned, the elf stands poised over a %^CYAN%^"
"rune-marked %^MAGENTA%^circle upon a stone floor. One arm lifts higher than the other, her %^RESET%^pale %^MAGENTA%^and "
"slender hands extending from billowing sleeves as each passes over the unfolding conjuration. Sweat beads her brow as "
"her face comes into view, her lips pursed and her concentration unwavering as her eyes of %^GREEN%^e%^BOLD%^m%^RESET%^"
"%^GREEN%^er%^YELLOW%^a%^RESET%^%^GREEN%^ld %^MAGENTA%^remain narrowed and fixed upon a point in the air before her.\n\n"
"%^MAGENTA%^She mouths a final word, a whisper so soft it goes nearly unheard, and as she spreads the fingers of both "
"hands in a last gesture, the circle springs to life in a gleaming burst of %^CYAN%^az%^BOLD%^ur%^RESET%^%^CYAN%^e "
"%^MAGENTA%^light. Casting her head aside to shield her gaze from the sudden brightness, she turns back seconds later to "
"espy what now lies before her. The circle has gone completely dead, with no hint of its presence to hint at the spell "
"now faded. But in its place sits a small, gleaming %^RESET%^s%^BOLD%^i%^RESET%^l%^BOLD%^%^BLACK%^v%^RESET%^e%^BOLD%^r"
"%^RESET%^y %^MAGENTA%^fox. Its nose lifts inquisitively as a broad grin spreads across her face.");
       break;
     case 47:
       tell_room(TO,"\n%^MAGENTA%^She stands, hands on hips, head tilted so that one pointed ear lifts free of her "
"%^BOLD%^%^BLACK%^midnight hair%^RESET%^%^MAGENTA%^. A smile plays about her lips as she attempts to suppress it, "
"watching the scene unfolding before her. A massive, barrel-like dwarf sits a short distance away, astride a rugged and "
"sturdy little %^ORANGE%^mountain pony%^MAGENTA%^. The pony itself has its ears laid back on its head and a %^BLUE%^"
"baleful %^MAGENTA%^expression upon its face, and the beast is quite clearly stationary. Irritation is just as apparent "
"upon the dwarf's face, despite most of it being hidden behind a thick beard, as he gives his valiant steed another kick. "
"It stays stubbornly put.\n\n%^MAGENTA%^With a %^RED%^ro%^BOLD%^a%^RESET%^%^RED%^r %^MAGENTA%^of frustration the dwarf "
"pushes off the beast and slides to the ground, his feet hitting with an audible thud. The elf ventures to speak, %^BLUE%^"
"'%^CYAN%^You catch more flies with honey than vinegar, Nalthic...%^BLUE%^'%^MAGENTA%^ He casts a dark look her way and "
"grumbles, %^RESET%^'%^ORANGE%^Flies, long-ear? It's a ruddy donkey!%^RESET%^'%^MAGENTA%^ before raising his voice and "
"pointing directly at the offending creature, %^RESET%^'%^ORANGE%^and if it don't learn to do what it's told it's gonna "
"be stew!%^RESET%^'");
       break;
     case 48:
       tell_room(TO,"\n%^MAGENTA%^Sunset casts lengthening %^RESET%^si%^BOLD%^%^BLACK%^l%^RESET%^hou%^BOLD%^%^BLACK%^et"
"%^RESET%^tes %^MAGENTA%^across the plateau, as an elven woman moves like a living shadow amongst the motionless trees. "
"Her steps are graceful and effortless, borne with a dancer's poise as she twirls a pair of matching %^BOLD%^%^WHITE%^ada"
"%^RESET%^m%^BOLD%^%^WHITE%^an%^RESET%^t%^BOLD%^%^WHITE%^ium %^RESET%^%^MAGENTA%^scimitars through the air in her wake. A "
"sudden strike forward at an unseen opponent, before she leans backwards nearly in half to evade an imagined swipe at her "
"head. All the while, a %^CYAN%^wo%^GREEN%^rdl%^CYAN%^ess t%^GREEN%^un%^CYAN%^e %^MAGENTA%^escapes her lips and drifts "
"through the glade, meandering back and forth as though guiding her on her way. The darkness deepens as night encroaches, "
"until soon enough sight of her is finally lost among the %^BLUE%^shadows%^MAGENTA%^, and her voice trails away to "
"silence.");
       break;
     case 49:
       tell_room(TO,"\n%^MAGENTA%^Early morning breaks over the marble walls of the temple of the moon, where a robed "
"elven woman sits in the garden outside. She lifts her gaze as a white-haired half-elf stalks in, with a look of "
"%^ORANGE%^br%^YELLOW%^i%^RESET%^%^ORANGE%^mm%^YELLOW%^i%^RESET%^%^ORANGE%^ng %^MAGENTA%^excitement that can't quite be "
"suppressed from his normally stoic face. Hope lights her eyes as he confirms %^RESET%^'Kiya, we've found your brother. "
"It's definite this time. He's up past Kilkaen, supposedly he's been living on the remote northern fringes for more than "
"a decade. One of Yardleyu's own will take you there.'\n\n%^MAGENTA%^She leaps to her feet, suddenly a study in %^GREEN%^"
"mo%^CYAN%^ti%^GREEN%^on%^MAGENTA%^, as she seems to take mental inventory of herself, and then turns to wrap the half-"
"elf in a tight hug. %^BLUE%^'%^CYAN%^Zeal, I can't thank you enough... I might never have found him if it wasn't for you"
". I should make sure everything here is set before I...%^BLUE%^'%^MAGENTA%^ He pulls her up short from her scattered "
"thoughts, his calloused hands upon either shoulder as he shakes his head and smiles, %^RESET%^'I'll sort things out here"
". Just go. He's waiting for you.' %^MAGENTA%^She grins abashedly, skipping back a step and giving a small wave, before "
"heading out the temple's main door with nothing more than the clothes on her back.");
       break;
     case 50:
       tell_room(TO,"\n%^MAGENTA%^Dust stirs the %^RED%^st%^BOLD%^i%^RESET%^%^RED%^fling-h%^BOLD%^o%^RESET%^%^RED%^t "
"%^MAGENTA%^air of the bustling city street as people push through the throng of bodies lining the marketplace. A "
"diminutive, %^BLUE%^cowled %^MAGENTA%^figure slips among them, avoiding the worst of the jostling to slip into a side "
"alcove, where a bronze-skinned elf awaits. Slender %^RESET%^alabaster %^MAGENTA%^hands push back the cowl to reveal an "
"elven woman, dark-haired and emerald eyed, her intent gaze searching the face of the stranger. %^BLUE%^'%^CYAN%^"
"Zanthyrra said you'd seen him? Sable hair, green eyes, a slim frame. Perhaps halfway through his second century. "
"Amethyst garb per his rank, no doubt. If there's a cost...%^BLUE%^'\n\n%^MAGENTA%^The bronze-skinned stranger shakes "
"his head, %^RESET%^'%^ORANGE%^No need. If Zanthyrra sent you, that's enough. The last word of him that I have is of a "
"few months previous; he was said to have passed through the outskirts of Djyarimisk, heading north-west via the main "
"trade route.%^RESET%^'%^MAGENTA%^ He pauses, a curious look lighting his eyes as he asks %^RESET%^'%^ORANGE%^Why are you "
"looking for this Daco, anyway?%^RESET%^'%^MAGENTA%^ She just grins and replies, %^BLUE%^'%^CYAN%^We have a lot to catch "
"up on.%^BLUE%^'");
       break;
   }
   return 1;
}