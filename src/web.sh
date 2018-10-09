#! /bin/sh

#===============================================================================
# Script para compilar y ejecutar relatos interactivos programados en Inform 6.
# Herramientas utilizadas:
#	<>	inform:			Compilador Inform 6
#	<>	bresc:			Blorb resource compiler (sólo en Glulx)
#	<>	gargoyle-free:	Intérprete multi-plataforma
#-------------------------------------------------------------------------------

bresc_location=~/data/bin
zcode_interpreter=gargoyle-free;
glulx_interpreter=gargoyle-free;

inform_path=,/usr/share/inform6/library/,/usr/share/inform6/extensions/,/usr/share/inform6/extensions/gwindows/,/usr/share/inform6/extensions/vorple/

#-------------------------------------------------------------------------------

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

cd libs/
./inicializa.sh
cd ..
perl ./libs/preprocesaTexto.pl ./$gameFile\_objects.txt ./$gameFile\_langOM.inf

echo "============================================="
echo "COMPILANDO PARA GLULX..."
echo "---------------------------------------------"
inform +include_path=$inform_path -G $gameFile.inf $gameFile.ulx
$bresc_location/bres $gameFile.res
inform +include_path=$inform_path -G $gameFile.inf
$bresc_location/bresc $gameFile.res
rm $gameFile.ulx
mv $gameFile.gblorb /home/jomali/Desktop/html/cerillera/resources/$gameFile.gblorb

echo " "
echo -n "Pulsa cualquier tecla para ejecutar la aplicación ('q' para salir): "
read key

if [ "$key" = "q" ]; then exit 0;
fi
if [ "$key" = "Q" ]; then exit 0;
fi
$glulx_interpreter /home/jomali/Desktop/html/cerillera/resources/$gameFile.gblorb

exit 0;
