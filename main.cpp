#include "principal.h"

#include <QApplication>
#include <QTranslator>
#include <QInputDialog>
#include <QLocale>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //Obtener la configuracion local del sistema (idioma)
    //QString locale = QLocale::system().name();
    //Creando un objeto QLocale de Italiano de Italia
    QLocale ubicacion(QLocale::French);
    QString locale = ubicacion.name();

    // Objeto para manejar las traducciones
    QTranslator traducion;

    traducion.load(QString("Calculadora_") + locale);
    a.installTranslator(&traducion);

    /*
    // Objeto para manejar las traducciones
    QTranslator traducion;
    // Dependiendo del idioma del sistema, carga el archivo de rtaducción
    if (locale.contains("it")){
        traducion.load(":/Calculadora_it_IT.qm");
    }else if (locale.contains("en")){
        traducion.load(":/Calculadora_en.qm");
    }
    // Si es diferente de español, se instala la traducción en TODA la aplicación
    if (!locale.contains("es")){
        a.installTranslator(&traducion);
    }*/

    /*
    // Objeto para manejar las traducciones
    QTranslator traducion;
    // Solicitando al usuario que seleccione un idioma
    QStringList idiomas;
    idiomas << "Italiano" << "Inglés" << "Español";
    QString idiomaSeleccionado = QInputDialog::getItem(NULL,
                               "Idioma",
                               "Seleccione un idioma",
                               idiomas);
    // Dependiendo del idioma seleccionado, carga el archivo de rtaducción
    if (idiomaSeleccionado == "Italiano"){
        traducion.load(":/Calculadora_it_IT.qm");
    }else if (idiomaSeleccionado == "Inglés"){
        traducion.load(":/Calculadora_en.qm");
    }
    // Si es diferente de español, se instala la traducción en TODA la aplicación
    if (idiomaSeleccionado != "Español"){
        a.installTranslator(&traducion);
    }*/

    // Muestra la ventana principal
    Principal w;
    w.show();
    return a.exec();
}
