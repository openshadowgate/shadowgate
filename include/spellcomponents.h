#define MAGE_COMPONENTS ({ \
"aluminum chaff", "amber rod", "bat guano", "beeswax", "bit of bone", "bitumen", "blessed leather",\
"carbon", "charcoal", "citric acid", "clay model ziggurat", "clear crystal", "copper", "corn extract",\
"crane's feather", "crushed black pearl", "crystal", "dart", "diamond", "diamond dust", "large diamond",\
"small diamond", "disc of bronze", "dragon scale", "drop of blood", "dung scrapings", "emerald",\
"eyelash", "eyelash of ogre-mage", "eye of roc", "feather", "firefly", "flint", "fur", "glass rod",\
"granite dust", "gum arabic", "incense stick", "ivory portal", "jade circlet", "magnets",\
"mini platinum sword", "minute tarts", "nitric acid", "onyx dust", "owlfeather", "parchment", "pearl", "phosphorus",\
"piece of mirror", "piece of iron", "piece of reed", "pinch of special dust", "powdered amber",\
"powdered chalk", "powdered diamond", "powdered silver", "quicksilver", "ruby dust", "sand", "sack of salt",\
"sapphire dust", "sesame seeds", "silver pin", "small candle", "small drum", "small silver mirror",\
"snakes tongue", "soft clay", "spider", "spider web", "sulfur", "sunstone", "talc", "tiny bag",\
"tiny hearing trumpet", "vermilion", "water", "white feather", "will o wisp essence", "wing feather", "zinc",\
"smoky quartz", "rose petals", "slug", "lodestone"\
})

#define PSI_COMPONENTS ({ \
"adamite", "blue lace agate", "gray agate", "leopard agate", "banded amethyst", "amethyst", "blue amethyst",\
"apatite", "aquamarine", "aventurine", "azurite", "beryl", "bloodstone", "yellow calcite", "blue calcite",\
"orange calcite", "carnelian", "chalcopyrite", "charoite", "dallyhanite", "danburite", "blue diamond",\
"ectoplasmic crystal", "emerald", "flowstone", "green fluorite", "purple fluorite", "garnet", "hematite",\
"jade", "red jasper", "yellow jasper", "mottled jasper", "lapiz lazuli", "larvikite", "lodestone", "malachite",\
"moonstone", "green moss agate", "obsidian", "snowflake obsidian", "fire opal", "opal", "peridot", "pyrite",\
"citrine quartz", "clear quartz", "rose quartz", "rutilated quartz", "smoky quartz", "rhodochrosite",\
"rhodonite", "ruby", "black star sapphire", "sapphire", "seraphinite", "sodalite", "blue spinel", "red spinel",\
"sunstone", "tektite", "blue tigers eye", "tigers eye", "topaz", "tourmaline", "turquoise", "unakite",\
"wemic tears", "zoisite",\
})

#define BARDCOMPS ({ \
"alliteration", "ballad", "chord", "conceit", "couplet", "dialogue", "dirge", "elegy", "epic", "epithet",\
"haiku", "hymn", "hyperbole", "invective", "joke", "lament", "limerick", "lullaby", "lyric", "metaphor",\
"narrative", "note", "octave", "ode", "parody", "poem", "prose", "quatrain", "rhetoric", "rhyme",\
"shanty", "soliloquy", "song", "sonnet", "stanza", "trill", "verse", "whisper", "whistle",\
})

// had to be split into two defs; mud cannot handle the size of it in a single one.
// any new components should be added to COMPONENTS2 in future. N, 5/14.
#define COMPONENTS1 ([ \
"adders stomach" : 25,\
"alliteration" : 87,\
"alkaline salt" : 1,\
"alum" : 8,\
"aluminum chaff" : 50,\
"amber rod" : 75,\
"animal hair" : 5,\
"ballad" : 47,\
"bark chips" : 1,\
"bat fur" : 25,\
"bat guano" : 10,\
"beeswax" : 45,\
"bit of bone" : 30,\
"bit of seashell" : 62,\
"bitumen" : 35,\
"black silk" : 100,\
"blessed leather" : 50,\
"blood of umber hulk" : 150,\
"butter" : 5,\
"carbon" : 15,\
"caterpillar cocoon" : 20,\
"chalk" : 3,\
"charcoal" : 20,\
"chord" : 62,\
"citric acid" : 5,\
"clay model ziggurat" : 50,\
"clear crystal" : 20,\
"coal" : 3,\
"colored sand" : 1,\
"conceit" : 60,\
"copper wire" : 10,\
"copper" : 5,\
"corn extract" : 5,\
"couplet" : 376,\
"crane's feather" : 30,\
"cricket" : 1,\
"crushed black pearl" : 1000,\
"crushed pearls" : 1000,\
"crystal" : 10,\
"dart" : 1,\
"dialogue" : 45,\
"diamond dust" : 1250,\
"diamond" : 1000,\
"dirge" : 41,\
"disc of bronze" : 50,\
"dragon scale" : 500,\
"drop of blood" : 10,\
"drop of oil" : 1,\
"dung scrapings" : 5,\
"earth from grave" : 1,\
"ebony canine statuette" : 250,\
"elegy" : 33,\
"emerald dust" : 500,\
"emerald" : 300,\
"epic" : 72,\
"epithet" : 120,\
"exotic feather" : 75,\
"eye of roc" : 2500,\
"eyelash of ogre-mage" : 150,\
"eyelash" : 3,\
"feather" : 1,\
"fine cloth" : 5,\
"firefly" : 10,\
"fleece" : 8,\
"flint" : 1,\
"forked twig" : 1,\
"fur" : 100,\
"glass rod" : 25,\
"gloworm" : 25,\
"gold tube" : 1000,\
"golden needle" : 100,\
"grain of salt" : 1,\
"granite block" : 20,\
"granite dust" : 50,\
"grasshopper leg" : 1,\
"ground mica" : 5,\
"gum arabic" : 20,\
"haiku" : 17,\
"honey" : 1,\
"honeycomb" : 3,\
"hymn" : 3405,\
"hyperbole" : 24,\
"incense stick" : 1,\
"invective" : 14,\
"iron blade" : 2,\
"iron rod" : 50,\
"ivory canine statuette" : 200,\
"ivory plaque" : 150,\
"ivory portal" : 50,\
"jade circlet" : 200,\
"joke" : 3,\
"lament" : 24,\
"large diamond" : 3000,\
"lead based ink" : 300,\
"leather glove" : 20,\
"leather loop" : 3,\
"legume seed" : 5,\
"licorice root" : 2,\
"lime" : 3,\
"limerick" : 15,\
"lodestone" : 12,\
"lullaby" : 10,\
"lyric" : 43,\
"magnetic needle" : 2,\
"magnets" : 10,\
"mercury" : 85,\
"metal rod" : 10,\
"metaphor" : 267,\
"mini brass trumpet" : 200,\
"mini platinum sword" : 500,\
"mini shovel" : 50,\
"minute tarts" : 3,\
"multi-colored silk" : 100,\
"narrative" : 23,\
"nitric acid" : 75,\
"note" : 7,\
"nutshells" : 1,\
"oak leaf" : 1,\
"octave" : 245,\
"ode" : 34,\
"ogre's eyelash" : 25,\
"oil" : 5,\
"owlfeather" : 10,\
"parchment" : 2,\
"parody" : 61,\
"pearl" : 100,\
"phosphorescent moss" : 20,\
"phosphorus" : 90,\
"piece of bone" : 30,\
"piece of glass" : 2,\
"piece of iron" : 1,\
"piece of mirror" : 1,\
"piece of mirror" : 25,\
"piece of reed" : 10,\
"piece of steel" : 1,\
"pinch of dung" : 5,\
"pinch of soot" : 1,\
"pinch of special dust" : 50,\
"poem" : 475,\
"poison ivy leaf" : 9,\
"polished marble" : 18,\
"powdered amber" : 100,\
"powdered bone" : 20,\
"powdered chalk" : 2,\
"powdered diamond" : 5000,\
"powdered hoof" : 7,\
"powdered iron" : 9,\
"powdered lime" : 12,\
"powdered rhubarb leaf" : 5,\
"powdered silver" : 50,\
"prose" : 132,\
"quatrain" : 68,\
"quicksilver" : 100,\
"red cloth" : 1,\
"rod of iron" : 5,\
"rose petals" : 2,\
"ruby dust" : 500,\
"sack of salt" : 50,\
"sand" : 1,\
"sapphire dust" : 500,\
"sesame seeds" : 4,\
"silver pin" : 10,\
"silver rod" : 50,\
"silver whistle" : 100,\
"silver wire" : 25,\
"slug" : 4,\
"small candle" : 2,\
"small crystal bead" : 5,\
"small diamond":750,\
"small drum" : 50,\
"small horn" : 100,\
"small silver mirror" : 50,\
"smoky quartz" : 55,\
"snake scale" : 35,\
"snakes tongue" : 80,\
"snakeskin glove" : 100,\
"soft clay" : 10,\
"soft glove" : 5,\
"spider web" : 15,\
"spider" : 10,\
"squid ink" : 100,\
"squid tentacle" : 100,\
"straw" : 1,\
"string" : 1,\
"strip of parchment" : 1,\
"sulfur" : 25,\
"sunstone" : 50,\
"talc" : 70,\
"tallow" : 1,\
"thread" : 1,\
"tiny bag" : 5,\
"tiny bell" : 25,\
"tiny bucket" : 25,\
"tiny fan" : 50,\
"tiny hearing trumpet" : 100,\
"turtle shell" : 10,\
"vampire dust" : 10000,\
"vermilion" : 18,\
"water" : 1,\
"will o wisp essence" : 100,\
"wing feather" : 20,\
"wood" : 1,\
"zinc" : 50,\
])

#define COMPONENTS2 ([ \
"rhetoric" : 1415, "rhyme" : 52, "shanty" : 18, "soliloquy" : 15,\
"song" : 128, "sonnet" : 97, "stanza" : 38, "trill" : 18,\
"verse" : 106, "whisper" : 54, "whistle" : 2,\
"gray agate" : 8, "dallyhanite" : 14, "banded amethyst" : 75, "amethyst" : 17,\
"blue amethyst" : 125, "wemic tears": 6, "apatite" : 5, "aventurine" : 55,\
"beryl" : 10, "bloodstone" : 8, "blue lace agate" : 2550, "yellow calcite" : 12,\
"blue calcite" : 13, "orange calcite" : 14, "carnelian" : 50, "chalcopyrite" : 30,\
"charoite" : 27, "citrine quartz" : 3, "danburite" : 310,\
"green fluorite" : 18, "purple fluorite" : 11, "green moss agate" : 9, "garnet" : 37,\
"hematite" : 70, "jade" : 83, "red jasper" : 4, "yellow jasper" : 8,\
"mottled jasper" : 11, "lapiz lazuli" : 68, "larvikite" : 12, "leopard agate" : 21,\
"lodestone" : 1, "malachite" : 43, "moonstone" : 16, "obsidian" : 7,\
"clear quartz" : 3, "smoky quartz" : 8, "rhodochrosite" : 35, "rhodonite" : 17,\
"rose quartz" : 215, "zoisite" : 52, "rutilated quartz" : 2300, "seraphinite" : 200,\
"snowflake obsidian" : 10, "sodalite" : 2, "blue tigers eye" : 250, "tigers eye" : 75,\
"tourmaline" : 15, "turquoise" : 4, "unakite" : 100, "azurite" : 80,\
"adamite" : 100, "tektite" : 150, "flowstone" : 42, "topaz" : 4,\
"blue diamond" : 2000, "black star sapphire" : 5000, "peridot" : 55,\
"ruby" : 130, "sapphire" : 500, "aquamarine" : 40, "pyrite" : 5,\
"fire opal" : 180, "opal" : 65, "blue spinel" : 40, "red spinel" : 40,\
"ectoplasmic crystal" : 1000, "white feather" : 5, "onyx dust" : 500,\
])
