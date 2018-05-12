#! /bin/sh

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

# Librería GWindows (DA-Gwindows v1.2):
echo -n "Copiando archivos de la librería GWindows (DA-Gwindows v1.2)..."
if [ -d $fichero_extensiones/gwindows ]; then
	sudo rm -r $fichero_extensiones/gwindows
fi
sudo mkdir $fichero_extensiones/gwindows
sudo cp DaGWindows12/README		$fichero_extensiones/gwindows/README
sudo cp DaGWindows12/gcdefs.h	$fichero_extensiones/gwindows/gcdefs.h
sudo cp DaGWindows12/gcore.h	$fichero_extensiones/gwindows/gcore.h
sudo cp DaGWindows12/gimage.h	$fichero_extensiones/gwindows/gimage.h
sudo cp DaGWindows12/gpopup.h	$fichero_extensiones/gwindows/gpopup.h
sudo cp DaGWindows12/gquote.h	$fichero_extensiones/gwindows/gquote.h
sudo cp DaGWindows12/gtile.h	$fichero_extensiones/gwindows/gtile.h
sudo cp DaGWindows12/gtrans.h	$fichero_extensiones/gwindows/gtrans.h
sudo cp DaGWindows12/gwincls.h	$fichero_extensiones/gwindows/gwincls.h
sudo cp DaGWindows12/gwindefs.h	$fichero_extensiones/gwindows/gwindefs.h
sudo cp DaGWindows12/gwindows.h	$fichero_extensiones/gwindows/gwindows.h
sudo cp DaGWindows12/infglk.h	$fichero_extensiones/gwindows/infglk.h
sudo cp DaGWindows12/utility.h	$fichero_extensiones/gwindows/utility.h
sudo cp extensions/gstatusX.h	$fichero_extensiones/gwindows/gstatusX.h
echo " hecho."

# Otras librerías:
echo -n "Copiando archivos de otras librerías..."
if [ -d $fichero_extensiones/other ]; then
	sudo rm -r $fichero_extensiones/other
fi
sudo mkdir $fichero_extensiones/other
sudo cp extensions/*.h			$fichero_extensiones/other/
sudo ln -s $fichero_extensiones/other/dainunek.h $fichero_extensiones/other/Dainunek.h
sudo ln -s $fichero_extensiones/other/damusix.h $fichero_extensiones/other/Damusix.h
echo " hecho."
echo " "

echo $fichero_librerias
sudo ls --color=auto $fichero_librerias
echo " "

echo $fichero_extensiones
sudo ls --color=auto $fichero_extensiones
echo " "

echo $fichero_extensiones/gwindows
sudo ls --color=auto $fichero_extensiones/gwindows/
echo " "

echo $fichero_extensiones/other
sudo ls --color=auto $fichero_extensiones/other/
echo " "

#sudo -k
