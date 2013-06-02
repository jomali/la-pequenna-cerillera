

!!==============================================================================
!!
!!	TYPES
!!	Rutinas biplataforma (Z/GLULX) para imprimir texto con diferentes estilos
!!
!!==============================================================================
!!
!!	File:			types.h
!!	Author(s):		J. Francisco Martín <jfm.lisaso@gmail.com>
!!	Language:		ES (Castellano)
!!	System:			Inform, INFSP 6
!!	Platform:		Z-Machine / Glulx
!!	Version:		4.2
!!	Released:		2013/04/02
!!
!!------------------------------------------------------------------------------
!!
!!	Copyright (c) 2013, J. Francisco Martín
!!
!!	Este programa es software libre: usted puede redistribuirlo y/o 
!!	modificarlo bajo los términos de la Licencia Pública General GNU 
!!	publicada por la Fundación para el Software Libre, ya sea la versión 
!!	3 de la Licencia, o (a su elección) cualquier versión posterior.
!!
!!	Este programa se distribuye con la esperanza de que sea útil, pero 
!!	SIN GARANTÍA ALGUNA; ni siquiera la garantía implícita MERCANTIL o 
!!	de APTITUD PARA UN PROPÓSITO DETERMINADO. Consulte los detalles de 
!!	la Licencia Pública General GNU para más información.
!!
!!	Debería haber recibido una copia de la Licencia Pública General GNU 
!!	junto a este programa. En caso contrario, consulte
!!	<http://www.gnu.org/licenses/>.
!!
!!------------------------------------------------------------------------------
System_file;

Constant _RST_	= 0;
Constant _IST_	= 1;
Constant _MST_	= 2;
Constant _BST_	= 3;

Default PARSER_STYLE	_RST_;
Default	PARSER_PREFIX	"";
Default PARSER_SUFIX	"";

Global	current_style = _RST_;

!!==============================================================================
!!	Selección de estilo de texto
!!------------------------------------------------------------------------------

[ roman_style;
	#Ifdef	TARGET_ZCODE;
	font on; style roman;
	#Ifnot;	! TARGET_GLULX;
	glk($0086, 0);
	#Endif;	! TARGET_
	current_style = _RST_;
];

[ italic_style;
	#Ifdef	TARGET_ZCODE;
	font on; style underline;
	#Ifnot;	! TARGET_GLULX;
	glk($0086, 1);
	#Endif;	! TARGET_
	current_style = _IST_;
];

[ bold_style;
	#Ifdef	TARGET_ZCODE;
	font on; style bold;
	#Ifnot;	! TARGET_GLULX;
	glk($0086, 3);
	#Endif;	! TARGET_
	current_style = _BST_;
];

[ monospaced_style;
	#Ifdef	TARGET_ZCODE;
	font off;
	#Ifnot;	! TARGET_GLULX;
	glk($0086, 2);
	#Endif;	! TARGET_
	current_style = _MST_;
];

[ start_parser_style;
	switch (PARSER_STYLE) {
	_RST_:	roman_style();
	_IST_:	italic_style();
	_BST_:	bold_style();
	_MST_:	monospaced_style();
	}
	if (PARSER_PREFIX ~= 0)
		print (string) PARSER_PREFIX;
];

[ end_parser_style;
	if (PARSER_SUFIX ~= 0)
		print (string) PARSER_SUFIX;
	roman_style();
];

!!==============================================================================
!!	Imprimir texto en diferentes estilos
!!------------------------------------------------------------------------------

[ emph text st;
	if (text == 0) return false;
	st = current_style;
	switch (st) {
	_RST_:	italic_style();
	_IST_:	roman_style();
	_BST_:	roman_style();
	_MST_:	italic_style();
	}
	print (string) text;
	switch (st) {
	_RST_:	roman_style();
	_IST_:	italic_style();
	_BST_:	bold_style();
	_MST_:	monospaced_style();
	}
	return true;
];

[ strong text st;
	if (text == 0) return false;
	st = current_style;
	switch (st) {
	_RST_:	bold_style();
	_IST_:	bold_style();
	_BST_:	italic_style();
	_MST_:	bold_style();
	}
	print (string) text;
	switch (st) {
	_RST_:	roman_style();
	_IST_:	italic_style();
	_BST_:	bold_style();
	_MST_:	monospaced_style();
	}
	return true;
];

[ code text st;
	if (text == 0) return false;
	st = current_style;
	switch (st) {
	_RST_:	monospaced_style();
	_IST_:	monospaced_style();
	_BST_:	monospaced_style();
	_MST_:	italic_style();
	}
	print (string) text;
	switch (st) {
	_RST_:	roman_style();
	_IST_:	italic_style();
	_BST_:	bold_style();
	_MST_:	monospaced_style();
	}
	return true;
];

[ parser text st;
	if (text == 0) return false;
	st = current_style;
	start_parser_style();
	print (string) text;
	end_parser_style();
	switch (st) {
	_RST_:	roman_style();
	_IST_:	italic_style();
	_BST_:	bold_style();
	_MST_:	monospaced_style();
	}
	return true;
];

!! Alias:

[ em text; return emph(text); ];


