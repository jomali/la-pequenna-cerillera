! Inform / INFSP 6


!!==============================================================================
!!
!!	GRAMÁTICA ESPAÑOLA EXTENDIDA
!!
!!==============================================================================
!!
!!	File:			SpanishEG.inf
!!	Author(s):		Emily Short (emshort@mindspring.com)
!!					J. Francisco Martín (jfm.lisaso@gmail.com)
!!					Mapache
!!	Language:		ES (Castellano)
!!	System:			Inform/INFSP 6
!!	Platform:		Máquina-Z / Glulx
!!	Version:		12.05 (2012/05/29)
!!
!!------------------------------------------------------------------------------
!!
!!	NOTES:
!!
!!	Based on "ExpertGrammar.h", by Emily Short (emshort@mindsping.com)
!!	and on its spanish translation "GramaticaExperta.h", by Mapache.
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
!!	Include "SpanishEG.h" after SpanishG in your gamefile.
!!
!!	Se puede definir una variable GRAMMATICAL_INFLECTION en el archivo de 
!!	juego que puede tomar los valores: 1 (PRESENTE 1ª PERSONA), 2 (PRESENTE 2ª 
!!	PERSONA), 3 (PRESENTE 3ª PERSONA), 4 (PASADO 1ª PERSONA), 5 (PASADO 2ª 
!!	PERSONA) o 6 (PASADO 3ª PERSONA) para modificar la conjugación gramatical 
!!	de los mensajes de la librería. Si no se define esta variable, la librería 
!!	interpreta que se usa el valor 2 con lo que los mensajes se imprimen en 
!!	presente y segunda persona.
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

Default	GRAMMATICAL_INFLECTION 2;

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

Verb	'baila'
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

Extend	'salta'
	* 'en' noun						-> JumpOver
;

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

Verb	'capullo' 'capulla'
	*								-> Mild
	* topic							-> Mild
;

Extend	'lee' first
	* noun							-> Read
;

Extend	'busca'
	* 'bajo' noun					-> LookUnder
	* 'debajo' 'de' noun			-> LookUnder
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
    * 'de' noun 					-> StandUp
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
	switch (GRAMMATICAL_INFLECTION) {
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
	switch (GRAMMATICAL_INFLECTION) {
	1,2,3:
		if ( noun has door) "Nadie contesta.";
		"No ocurre nada.";
	4,5,6:
		if ( noun has door) "Nadie contestó.";
		"No ocurrió nada.";
	}
];

[ MasturbateSub;
	switch (GRAMMATICAL_INFLECTION) {
	1:	"Ahora no tengo ganas.";
	2:	"Ahora no tienes ganas.";
	3:	"Ahora no tiene ganas.";
	4:	"No tenía ganas.";
	5:	"No tenías ganas.";
	6:	"No tenía ganas.";
	}
];

[ ReadSub;
	switch (GRAMMATICAL_INFLECTION) {
		1,2,3:	"No hay nada que leer en ", (the) noun, ".";
		4,5,6:	"No había nada que leer en ", (the) noun, ".";
	}
];

[ ShoutSub;
	switch (GRAMMATICAL_INFLECTION) {
	1:	"Grito con fuerza.";
	2:	"Gritas con fuerza.";
	3:	"Grita con fuerza.";
	4:	"Grité con fuerza.";
	5:	"Gritaste con fuerza.";
	6:	"Gritó con fuerza.";
	}
!	"---¡AARRGHH!";
];

[ SitSub;
	switch (GRAMMATICAL_INFLECTION) {
	1:	"Ya estoy bastante cómodo de pie.";
	2:	"Ya estás bastante cómodo de pie.";
	3:	"Ya está bastante cómodo de pie.";
	4:	"Ya estaba bastante cómodo de pie.";
	5:	"Ya estabas bastante cómodo de pie.";
	6:	"Ya estaba bastante cómodo de pie.";
	}
];

[ SleepWithSub;
	if ( noun == player ) <<Masturbate>>;
	switch (GRAMMATICAL_INFLECTION) {
	1:	"No creo que deba.";
	2:	"En realidad no crees que debas.";
	3:	"No cree que deba.";
	4:	"No creo que algo así se me pasase por la cabeza siquiera.";
	5:	"En realidad no crees que algo así se te pasase por la cabeza siquiera.";
	6:	"No cree que algo así se le pasase por la cabeza siquiera.";
	}
];

[ StandUpSub;
	switch (GRAMMATICAL_INFLECTION) {
		1:	"No estoy en ningún sitio del que deba levantarme.";
		2:	"No estás en ningún sitio del que debas levantarte.";
		3:	"No está en ningún sitio del que deba levantarse.";
		4:	"No estaba en ningún sitio del que debiese levantarme.";
		5:	"No estabas en ningún sitio del que debieses levantarte.";
		6:	"No estaba en ningún sitio del que debiese levantarse.";
	}
];

[ UntieSub;
	switch (GRAMMATICAL_INFLECTION) {
	1:	"No estoy seguro de cómo hacerlo.";
	2:	"No estás seguro de cómo hacerlo.";
	3:	"No parece estar seguro de cómo hacerlo.";
	4:	"No sabía cómo hacer eso.";
	5:	"No sabías cómo hacer eso.";
	6:	"No sabía cómo hacer eso.";
	}
];

[ UseSub;
	switch (GRAMMATICAL_INFLECTION) {
	1:	"Pienso en algún uso para ", (the) noun ,", pero no termino de 
		decidirme por una acción concreta.";
	2:	"Piensas en algún uso para ", (the) noun, ", pero no terminas de 
		decidirte por una acción concreta.";
	3:	"Piensa en algún uso para ", (the) noun, ", pero no termina de 
		decidirse por una acción concreta.";
	4:	"Pensé en algún uso para ", (the) noun, ", pero no terminé de 
		decidirme por una acción concreta.";
	5:	"Pensaste en algún uso para ", (the) noun, ", pero no terminaste de 
		decidirte por una acción concreta.";
	6:	"Pensó en algún uso para ", (the) noun, ", pero no terminó de 
		decidirse por una acción concreta.";
	}
];

[ WriteSub;
	switch (GRAMMATICAL_INFLECTION) {
	1:	"Ahora no tengo nada que escribir.";
	2:	"Ahora no tienes nada que escribir.";
	3:	"Ahora no tiene nada que escribir.";
	4:	"No tenía nada que escribir.";
	5:	"No tenías nada que escribir.";
	6:	"No tenía nada que escribir.";
	}
];

[ XyzzySub;
	switch (GRAMMATICAL_INFLECTION) {
	1:	"Un rumor silencioso responde a mis palabras.";
	2:	"Un rumor silencioso responde a tus palabras.";
	3:	"Un rumor silencioso responde a sus palabras.";
	4:	"Un rumor silencioso respondió a mis palabras.";
	5:	"Un rumor silencioso respondió a tus palabras.";
	6:	"Un rumor silencioso respondió a sus palabras.";
	}
];


