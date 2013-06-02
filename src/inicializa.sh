#!/bin/sh
# Script para inicializar librerias y extensiones del programa

# Rutas:
fichero_sintaxis="/usr/share/gtksourceview-3.0/language-specs"
fichero_librerias="/usr/share/inform/6.31/module"
fichero_extensiones="/usr/share/inform/6.31/include"

sudo true

# Resaltado de sintaxis para GtkSourceView:
echo -n "Copiando archivo de resaltado de sintaxis para GtkSourceView..."
sudo cp inform6.lang $fichero_sintaxis/inform6.lang
echo " hecho."

# Librerías Inform v.6/11 e INFSP6 v.0.9:
echo -n "Copiando archivos de las librerías Inform v.6/11 e INFSP6 v.0.9..."
if [ -d $fichero_librerias ]; then
	sudo rm -r $fichero_librerias
fi
sudo mkdir $fichero_librerias
sudo cp InformLibrary611/*.h $fichero_librerias
sudo cp INFSP6/*.h $fichero_librerias
cp InformLibrary611/README README_temp
echo " " >> README_temp
cat INFSP6/README >> README_temp
sudo mv README_temp $fichero_librerias/README
echo " hecho."

# Otras librerías:
echo -n "Copiando archivos de otras librerías..."
if [ -d $fichero_extensiones/other ]; then
	sudo rm -r $fichero_extensiones/other
fi
sudo mkdir $fichero_extensiones/other
sudo cp SpanishEG.h		$fichero_extensiones/other/SpanishEG.h
sudo cp types.h			$fichero_extensiones/other/types.h
sudo ln -s $fichero_extensiones/other/types.h $fichero_extensiones/other/Types.h
echo " hecho."

echo " "
echo $fichero_librerias
sudo ls --color=auto $fichero_librerias

echo " "
echo $fichero_extensiones
sudo ls --color=auto $fichero_extensiones

echo " "
echo $fichero_extensiones/other
sudo ls --color=auto $fichero_extensiones/other/

sudo -k
