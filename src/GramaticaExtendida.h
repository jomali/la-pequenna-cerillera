! Inform / INFSP 6


!!==============================================================================
!!
!!	GRAMÁTICA EXTENDIDA
!!
!!==============================================================================
!!
!!
!!	File:			GramaticaExtendida.inf
!!	Author(s):		Emily Short (emshort@mindspring.com)
!!					J. Francisco Martín (jfm.lisaso@gmail.com)
!!					Mapache
!!	Language:		ES (Castellano)
!!	System:			Inform/INFSP 6
!!	Platform:		Máquina-Z / Glulx
!!	Version:		10.12
!!	Notes:
!!
!!		Based on "ExpertGrammar.h", by Emily Short (emshort@mindsping.com)
!!		and on its spanish translation "GramaticaExperta.h", by Mapache.
!!
!!		Algunos mensajes han sido modificados expresamente para "La pequeña 
!!		cerillera": [Dance, Masturbate, Shout]
!!
!!------------------------------------------------------------------------------
!!
!!
!!	RIGHTS:
!!
!!	This library file may be trated as public domain. It may be 
!!	included with or without credit to the original author. It may be 
!!	modified at the user's discretion. It may be freely distributed.
!!	Parts may be extracted.
!!
!!
!!	INSTALLATION:
!!
!!	Include "GramaticaExtendida.h" after SpanishG in your gamefile.
!!
!!	Se puede definir la constante o la variable GRAMMATICAL_FLEXION en el 
!!	archivo de juego con los valores: 1 (PRESENTE 1ª PERSONA), 2 (PRESENTE 2ª 
!!	PERSONA), 3 (PRESENTE 3ª PERSONA), 4 (PASADO 1ª PERSONA), 5 (PASADO 2ª 
!!	PERSONA) o 6 (PASADO 3ª PERSONA) para modificar la conjugación gramatical 
!!	de los mensajes de la librería. Si no se define ninguna GRAMMATICAL_FLEXION, 
!!	la librería interpreta que se usa el valor 2: los mensajes de 
!!	"GramaticaExtendida.h" se imprimen en presente y segunda persona.
!!
!!
!!	NEW ACTIONS:
!!
!!	Dance
!!	GoDown
!!	GoUp
!!	KnockOn
!!	Masturbate
!!	Shout
!!	Sit
!!	SleepWith
!!	StandUp
!!	Untie
!!	Use
!!	Write
!!	Xyzzy
!!
!!------------------------------------------------------------------------------


Default	GRAMMATICAL_FLEXION 2;


!!------------------------------------------------------------------------------


Verb	'machaca'						= 'ataca';
Verb	'silba' 'tararea' 'tatarea'		= 'canta';
Verb	'roba' 'agarra'					= 'coge';
Verb	'talla' 'esculpe'				= 'corta';
Verb	'emplaza' 'deposita' 'abandona'	= 'deja';
Verb	'berrea' 'aulla'				= 'grita';
Verb	'marcha'						= 'ir';
Verb	'incinera' 'tuesta'				= 'quema';
VerboIrregular "tostar" with imperativo 'tuesta';
Verb	'acaricia'						= 'toca';


!!------------------------------------------------------------------------------


Extend	'sopla'
	* 'sobre' / 'dentro' / 'a' noun	-> Blow
	* 'a' 'traves' 'de' noun		-> Blow
;

Extend	'prende' last
	* 'fuego' noun					-> Burn
	* noun 'fuego'					-> Burn
	* 'fuego' 'a//' noun			-> Burn
	* 'a//' noun 'fuego'			-> Burn
	* 'fuego' noun 'con' held		-> Burn
	* noun 'fuego' 'con' held		-> Burn
	* 'fuego' 'a//' noun 'con' held	-> Burn
	* 'a//' noun 'fuego' 'con' held	-> Burn
;

Verb	'baila' 'danza' 'bailotea'
	*								-> Dance
;

Verb	'muerde'
	* noun							-> Eat
	* edible						-> Eat
!	* animate						-> Attack
!	* 'a' animate					-> Attack
; VerboIrregular "morder" with imperativo 'muerde';


Verb	'desciende'
	*								-> GoDown
	* noun							-> Enter
	* 'por' noun					-> Enter
; VerboIrregular "descender" with imperativo 'desciende';


Verb	'asciende'
	*								-> GoUp
	* noun							-> Enter
	* 'por' noun					-> Enter
; VerboIrregular "ascender" with imperativo 'asciende';


Verb	'llama'
	* door							-> KnockOn
	* 'a' door						-> KnockOn
	* animate						-> Tell
	* 'a' animate					-> Tell
;

Extend only 'golpea' first
	* door							-> KnockOn
	* 'a' door						-> KnockOn
;

Extend	'mira'
	* 'alrededor'					-> Look
	* 'a' 'tu' 'alrededor'			-> Look
;

Verb	'masturba'
	* '-me'/'-te'					-> Masturbate
;

Extend	'lee' first
	* noun							-> Read
;

Extend	'busca'
	* 'entre' noun					-> Search
;

Extend	'mira'
	* 'entre' noun					-> Search
;

Extend	'grita' last
	*								-> Shout
;

Extend    'sienta' replace
    * 								-> Sit
	* '-te' / '-me'					-> Sit
	* noun							-> Sit
	* '-te' / '-me' noun			-> Sit
	* 'en' noun						-> Sit
	* '-te' / '-me'	'en' noun		-> Sit
; VerboIrregular "sentar" with imperativo 'sientate';


Verb	'folla' 'copula'
	* animate						-> SleepWith
	* '-te' / '-me' animate			-> SleepWith
	* 'a//' / 'con' animate			-> SleepWith
	* '-te' / '-me' 'a' animate		-> SleepWith
;


Extend	only 'jode' first
	* animate						-> SleepWith
	* 'a//' / 'con' animate			-> SleepWith
;


Verb	'ten'
	* 'sexo' 'con' animate			-> SleepWith
	* 'coito' 'con' animate			-> SleepWith
;


Verb	'haz'
	* 'el' 'amor' 'con' animate		-> SleepWith
;


Extend	only 'levantate' 'levantarse' 'levantarte' first
	*								-> StandUp
	* 'de' noun						-> StandUp;
Verb    'levanta' 'incorpora'
    * 								-> StandUp
	* '-te' / '-me'					-> StandUp
    * 'de//' noun 					-> StandUp
	* '-te' / '-me' 'de//' noun		-> StandUp
;


Verb	'desata' 'libera' 'desune' 'desenchufa'
	* noun							-> Untie
	* 'a//' creature				-> Untie
	* 'a//' creature 'de' noun		-> Untie
	* noun 'de' noun				-> Untie
;

Extend	only 'desconecta' last
	* noun 'de' noun				-> Untie
;

Verb	'usa' 'utiliza' 'emplea'
	* noun							-> Use
	* noun 'con' / 'en' noun		-> Use
;

Verb	meta 'creditos' 'credits' 'autor' 'author' 'informacion' 'info'
	*								-> Version
;

Verb	'escribe'
	* noun							-> Write
	* 'en'/'el' noun				-> Write
	* noun 'con' noun				-> Write
	* 'en'/'el' noun 'con' noun		-> Write
; VerboIrregular "escribir" with imperativo 'escribe';

Verb	'xyzzy' 'plugh' 'plover' 'abracadabra'
	*								-> Xyzzy
;


!!------------------------------------------------------------------------------


[ DanceSub;
	if ( player has female ) { switch (GRAMMATICAL_FLEXION) {
	1:	"Nunca he sido una gran bailarina.";
	2:	"Nunca has sido una gran bailarina.";
	3:	"Nunca ha sido una gran bailarina.";
	4:	"Nunca fui una gran bailarina.";
	5:	"Nunca fuiste una gran bailarina.";
!	6:	"Nunca fue una gran bailarina.";
	6:	"No tenía fuerzas ni ánimos suficientes para ponerse a bailar en 
		aquel momento.";
	}}
	switch (GRAMMATICAL_FLEXION) {
	1:	"Nunca he sido un gran bailarín.";
	2:	"Nunca has sido un gran bailarín.";
	3:	"Nunca ha sido un gran bailarín.";
	4:	"Nunca fui un gran bailarín.";
	5:	"Nunca fuiste un gran bailarín.";
	6:	"Nunca fue un gran bailarín.";
	}
];

[ GoDownSub;
	<<Go d_obj>>;
];

[ GoUpSub;
	<<Go u_obj>>;
];

[ KnockOnSub;
	switch (GRAMMATICAL_FLEXION) {
	1, 2, 3:
		if ( noun has door) "Nadie contesta.";
		"No ocurre nada.";
	4, 5, 6:
		if ( noun has door) "Nadie contestó.";
		"No ocurrió nada.";
	}
];

[ MasturbateSub;
	switch (GRAMMATICAL_FLEXION) {
	1:	"Ahora no tengo ganas.";
	2:	"Ahora no tienes ganas.";
	3:	"Ahora no tiene ganas.";
	4:	"No tenía ganas.";
	5:	"No tenías ganas.";
!	6:	"No tenía ganas.";
	6:	print_ret (stparser) "¿En serio? ¿En qué estás pensando para intentar 
		que la protagonista del cuento haga eso? Además, si los patrones de los 
		cuentos infantiles no impidiesen hablar abiertamente de sexo, y si la 
		protagonista ya se hubiese iniciado en esa clase de experiencias, no 
		creo que en aquel momento tuviese gana alguna de practicarlas.";
	}
];

[ ReadSub;
	<<Examine noun>>;
];

[ ShoutSub;
	switch (GRAMMATICAL_FLEXION) {
	1:	"Grito con fuerza.";
	2:	"Gritas con fuerza.";
	3:	"Grita con fuerza.";
	4:	"Grité con fuerza.";
	5:	"Gritaste con fuerza.";
!	6:	"Gritó con fuerza.";
	6:	"No tenía fuerzas para gritar.";
	}
!	"---¡AARRGHH!";
];

[ SitSub;
	switch (GRAMMATICAL_FLEXION) {
	1:	"Ya estoy bastante cómod", (o) player, " de pie.";
	2:	"Ya estás bastante cómod", (o) player, " de pie.";
	3:	"Ya está bastante cómod", (o) player, " de pie.";
	4:	"Ya estaba bastante cómod", (o) player, " de pie.";
	5:	"Ya estabas bastante cómod", (o) player, " de pie.";
	6:	"Ya estaba bastante cómod", (o) player, " de pie.";
	}
];

[ SleepWithSub;
	if ( noun == player ) <<Masturbate>>;
	switch (GRAMMATICAL_FLEXION) {
	1:	"No creo que deba.";
	2:	"No creo que debas.";
	3:	"No creo que deba.";
	4:	"No creo que se me pasase por la cabeza siquiera.";
	5:	"Tal vez se te pasase por la cabeza, pero dudo que hubieses podido 
		hacerlo.";
	6:	"No creo que se le pasase por la cabeza siquiera.";
	}
];

[ StandUpSub;
	if (parent(player) has supporter) <<Exit>>;
	switch (GRAMMATICAL_FLEXION) {
	1:	"No estoy sentad", (o) player, " en ningún sitio del que deba 
		levantarme.";
	2:	"No estás sentad", (o) player, " en ningún sitio del que debas 
		levantarte.";
	3:	"No está sentad", (o) player, " en ningún sitio del que deba 
		levantarse.";
	4:	"No estaba sentad", (o) player, "en ningún sitio del que debiese 
		levantarme.";
	5:	"No estabas sentad", (o) player, " en ningún sitio del que debieses 
		levantarte.";
	6:	"No estaba sentad", (o) player, " en ningún sitio del que debiese 
		levantarse.";
	}
];

[ UntieSub;
	switch (GRAMMATICAL_FLEXION) {
	1:	"No estoy segur", (o) player, " de cómo hacerlo.";
	2:	"No estás segur", (o) player, " de cómo hacerlo.";
	3:	"No parece estar segur", (o) player, " de cómo hacerlo.";
	4:	"No sabía cómo hacer eso.";
	5:	"No sabías cómo hacer eso.";
	6:	"No sabía cómo hacer eso.";
	}
];

[ UseSub;
	switch (GRAMMATICAL_FLEXION) {
	1:	"Trato de encontrar un uso para ", (the) noun ," pero soy incapaz de 
		dar con con la acción concreta.";
	2:	"Tratas de encontrar un uso para ", (the) noun, " pero tu mente no 
		acierta con la acción concreta.";
	3:	"Trata de econtrar un uso para ", (the) noun, " pero no parece capaz de 
		acertar con la acción concreta.";
	4:	"Traté de encontrar un uso para ", (the) noun, " pero fui incapaz de 
		dar con la acción concreta.";
	5:	"Trataste de encontrar un uso para ", (the) noun, " pero fuiste incapaz 
		de dar con la acción concreta.";
	6:	"Trató de encontrar un uso para ", (the) noun, " pero fue incapaz de 
		dar con la acción concreta.";
	}
];

[ WriteSub;
	switch (GRAMMATICAL_FLEXION) {
	1:	"Ahora no tengo nada que escribir.";
	2:	"Ahora no tienes nada que escribir.";
	3:	"Ahora no tiene nada que escribir.";
	4:	"No tenía nada que escribir.";
	5:	"No tenías nada que escribir.";
	6:	"No tenía nada que escribir.";
	}
];

[ XyzzySub;
	switch (GRAMMATICAL_FLEXION) {
	1:	"Un rumor silencioso responde a mis palabras.";
	2:	"Un rumor silencioso responde a tus palabras.";
	3:	"Un rumor silencioso responde a sus palabras.";
	4:	"Un rumor silencioso respondió a mis palabras.";
	5:	"Un rumor silencioso respondió a tus palabras.";
	6:	"Un rumor silencioso respondió a sus palabras.";
	}
];


