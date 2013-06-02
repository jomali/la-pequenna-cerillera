#!/bin/sh

# Script para compilar y ejecutar relatos interactivos programados en Inform 6.
# Herramientas utilizadas:
#	<>	inform:			Compilador Inform 6
#	<>	bresc:			Blorb resource compiler (solo GLULX)
#	<>	gargoyle-free:	Intérprete multi-plataforma

bresc_location=~/bin
zcode_interpreter=gargoyle-free;
glulx_interpreter=gargoyle-free;

if [ "$1" != "" ]; then gameFile=$1;
else 
	echo -n "Introduce el nombre del archivo (sin la extensión): ";
	read gameFile;
	echo " ";
fi
if [ ! -e "$gameFile.inf" ]; then
	echo "El archivo '$gameFile.inf' no existe.";
	exit 1;
fi

if [ "$2" != "" ]; then op=$2;
else 
	echo "[1] Compilar el relato para MÁQUINA-Z"
	echo "[2] Compilar el relato para GLULX"
	echo -n "Selecciona una opción: "
	read op;
	echo " "
fi

# Compilar el relato para GLULX
if [ "$op" = "2" ]; then
	echo "============================================="
	echo "COMPILANDO PARA GLULX..."
	echo "---------------------------------------------"
	$bresc_location/bres $gameFile
	inform +include_path=,/usr/share/inform/include/,/usr/share/inform/module/,/usr/share/inform/6.31/include/,/usr/share/inform/6.31/module/,/usr/share/inform/6.31/include/gwindows/,/usr/share/inform/6.31/include/other/ -G $gameFile.inf
	$bresc_location/bresc $gameFile
	mv $gameFile.blb ../$gameFile.blb
	rm $gameFile.ulx

	echo " "
	echo -n "Pulsa cualquier tecla para ejecutar la aplicación ('q' para salir): "
	read key

	if [ "$key" = "q" ]; then exit 0;
	fi
	if [ "$key" = "Q" ]; then exit 0;
	fi
	cd .. 
	$glulx_interpreter $gameFile.blb

# Compilar el relato para MÁQUINA-Z
else
	echo "============================================="
	echo "COMPILANDO PARA MÁQUINA-Z..."
	echo "---------------------------------------------"
	inform +include_path=,/usr/share/inform/include/,/usr/share/inform/module/,/usr/share/inform/6.31/include/,/usr/share/inform/6.31/module/,/usr/share/inform/6.31/include/gwindows/,/usr/share/inform/6.31/include/other/ $gameFile.inf ../$gameFile.z5

	echo " "
	echo -n "Pulsa cualquier tecla para ejecutar la aplicación ('q' para salir): "
	read key
	
	if [ "$key" = "q" ]; then exit 0;
	fi
	if [ "$key" = "Q" ]; then exit 0;
	fi
	cd ..
	$zcode_interpreter $gameFile.z5

fi

exit 0;
