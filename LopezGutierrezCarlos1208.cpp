/*
Programa: Base de datos de un hombre pobre
Por Carlos Eduardo López Gutiérrez
*/

#include <iostream>
#include <clocale>

#define DeviceMAX 100
#define iPhoneMAX 10
#define iPadMAX 3
#define MacMAX 7
#define AirPodsMAX 4
#define WatchMAX 3

using namespace std;

//**************************************** Structures *********************************
struct Watch_SpecsByModel{
    string display;
    string resistance;
    string sensors;
    string tools;
    string energy_batery;
    string material;
    string healthTools;
    string emergencyTools;
    string chip;
};
struct AirPods_CharginCaseSpecs{
    float height;
    float width;
    float depth;
    float weight;
};
struct AirPods_SpecsByModel{
    string noiseReduction;
    string environmentMode;
    string gestures;
    string spaceSound;
    string resistance;
    string chip;
    int independentTime;
    int dependingTime;
    string chargingCase;
    float height;
    float width;
    float depth;
    float weight;
    string conectivity;
};
struct Mac_SpecsByModel{
    float height;
    float width;
    float depth;
    float weight;
    string display;
    string chip;
    string energy_batery;
    string secureAuth;
    string camera;
    string keyboard_trackpad;
    string ports;
};
struct iPad_SpecsByModel{
    float height;
    float width;
    float depth;
    float weight;
    string chip;
    string camera;
    string display;
    string secureAuth;
    string energy_batery;
    string conector;
    string compatibility;
};
struct iPhone_SpecsByModel{
    float height;
    float width;
    float depth;
    float weight;
    string display;
    string chip;
    string camera;
    string secureAuth;
    string energy_batery;
    string conector;
    string resistance;
};

struct Watch{
    float price;
    string model[WatchMAX]={"Apple Watch Ultra","Apple Watch Series","Apple Watch SE"};
    string color;
    int id_Device;
    Watch_SpecsByModel specsByModel;
};
struct AirPods{
    float price;
    string model[AirPodsMAX]={"AirPods (2da Generación)","AirPods (3ra Generación)","AirPods Pro","AirPods Max"};
    string color;
    int id_Device;
    AirPods_SpecsByModel specsByModel;
    AirPods_CharginCaseSpecs caseSpecs;
};
struct Mac{
    float price;
    int storage;
    string model[MacMAX]={"MacBook Pro","MacBook Air","iMac","iMac Pro","Mac mini","Mac studio","Mac Pro"};
    string color;
    string CPU;
    string GPU;
    string RAM;
    int id_Device;
    Mac_SpecsByModel specsByModel;
};
struct iPad{
    float price;
    int storage;
    string model[iPadMAX]={"iPad Pro","iPad Air","iPad mini"};
    string color;
    int id_Device;
    iPad_SpecsByModel specsByModel;
};
struct iPhone{
    float price;
    int storage;
    string model[iPhoneMAX]={"iPhone 14 Pro Max","iPhone 14","iPhone 13 Pro Max","iPhone 13","iPhone 12 Pro Max",
                            "iPhone 12","iPhone 11 Pro Max","iPhone 11","iPhone Xs Max","iPhone X"};
    string color;
    int id_Device;
    iPhone_SpecsByModel specsByModel;
};

struct Device{
    iPhone AppleiPhone[DeviceMAX];
    iPad AppleiPad[DeviceMAX];
    Mac AppleMac[DeviceMAX];
    AirPods AppleAirpods[DeviceMAX];
    Watch AppleWatch[DeviceMAX];
};

//**************************************** Prototypes **********************************
int showMainMenu();
int getMenuOption(int &Option, int firstOption, int lastOption);
int performMainOption(int mainOption, Device &myDevice, int amountDevices);
int showDeviceMenu();
int addDeviceOption(int selectedDevice, Device &myDevice, int amountDevices);
int showMenuiPhone();
int setiPhoneData(int selectedModel, int amountDevices, Device &myDevice);

int main(void){
    system("COLOR F1");
    setlocale(LC_CTYPE, "spanish");
    // ************************************ Code ***************************************

    cout<<"\n\t\tBase de Datos de un Hombre Pobre\n\n";

    Device myDevice;
    int menuSelectedOption, amountDevices=0;

    showMainMenu();
    getMenuOption(menuSelectedOption,1,8);
    performMainOption(menuSelectedOption,myDevice,amountDevices);

    // ********************************** Footer ****************************************
    cout << "\n\n\n\nPara salir, presiona la tecla 'Enter'";
    cin.get();
}

//***************************************** Functions ***********************************

int setiPhoneData(int selectedModel, int amountDevices, Device &myDevice){
    myDevice.AppleiPhone[amountDevices].model[selectedModel-1];
    cout<<"\nID producto (4 números): ";
    cin>>myDevice.AppleiPhone[amountDevices].id_Device; cin.ignore();
    cout<<"Color: ";
    getline(cin,myDevice.AppleiPhone[amountDevices].color);
    cout<<"Almacenamiento [GB]: ";
    cin>>myDevice.AppleiPhone[amountDevices].storage; cin.ignore();
    cout<<"Precio (USD): ";
    cin>>myDevice.AppleiPhone[amountDevices].price; cin.ignore();

    switch(selectedModel){
        case 1:
            myDevice.AppleiPhone[amountDevices].specsByModel.camera="Sistema de cámaras Pro Gran angular de 48 MP | Ultra gran angular | Teleobjetivo";
            myDevice.AppleiPhone[amountDevices].specsByModel.chip="A16 Bonic";
            myDevice.AppleiPhone[amountDevices].specsByModel.conector="Lightning";
            myDevice.AppleiPhone[amountDevices].specsByModel.display="6,7\" Super Retina XDR";
            myDevice.AppleiPhone[amountDevices].specsByModel.energy_batery="Hasta 29 horas de reproducción de video";
            myDevice.AppleiPhone[amountDevices].specsByModel.resistance="Frente de Ceramic Shield | Resistente al agua, 30 minutos - 6 metros | Acero inoxidable de calidad quirúrgica";
            myDevice.AppleiPhone[amountDevices].specsByModel.secureAuth="Face ID";
            myDevice.AppleiPhone[amountDevices].specsByModel.depth=7.85;
            myDevice.AppleiPhone[amountDevices].specsByModel.height=160.7;
            myDevice.AppleiPhone[amountDevices].specsByModel.weight=240;
            myDevice.AppleiPhone[amountDevices].specsByModel.width=77.6;
            break;
        case 2:
            myDevice.AppleiPhone[amountDevices].specsByModel.camera="Sistema avanzado de dos cámaras Gran angular de 12 MP | Ultra gran angular";
            myDevice.AppleiPhone[amountDevices].specsByModel.chip="A15 Bonic";
            myDevice.AppleiPhone[amountDevices].specsByModel.conector="Lightning";
            myDevice.AppleiPhone[amountDevices].specsByModel.display="6,1\" Super Retina XDR";
            myDevice.AppleiPhone[amountDevices].specsByModel.energy_batery="Hasta 20 horas de reproducción de video";
            myDevice.AppleiPhone[amountDevices].specsByModel.resistance="Frente de Ceramic Shield | Resistente al agua, 30 minutos - 6 metros | Aluminio de calidad aeroespacial";
            myDevice.AppleiPhone[amountDevices].specsByModel.secureAuth="Face ID";
            myDevice.AppleiPhone[amountDevices].specsByModel.depth=7.80;
            myDevice.AppleiPhone[amountDevices].specsByModel.height=146.7;
            myDevice.AppleiPhone[amountDevices].specsByModel.weight=172;
            myDevice.AppleiPhone[amountDevices].specsByModel.width=71.5;
            break;
        case 3:
            myDevice.AppleiPhone[amountDevices].specsByModel.camera="Sistema de cámaras Pro Gran angular de 12 MP | Ultra gran angular | Teleobjetivo";
            myDevice.AppleiPhone[amountDevices].specsByModel.chip="A15 Bonic";
            myDevice.AppleiPhone[amountDevices].specsByModel.conector="Lightning";
            myDevice.AppleiPhone[amountDevices].specsByModel.display="6,7\" Super Retina XDR";
            myDevice.AppleiPhone[amountDevices].specsByModel.energy_batery="Hasta 28 horas de reproducción de video";
            myDevice.AppleiPhone[amountDevices].specsByModel.resistance="Frente de Ceramic Shield | Resistente al agua, 30 minutos - 6 metros | Acero inoxidable de calidad quirúrgica";
            myDevice.AppleiPhone[amountDevices].specsByModel.secureAuth="Face ID";
            myDevice.AppleiPhone[amountDevices].specsByModel.depth=7.65;
            myDevice.AppleiPhone[amountDevices].specsByModel.height=160.8;
            myDevice.AppleiPhone[amountDevices].specsByModel.weight=240;
            myDevice.AppleiPhone[amountDevices].specsByModel.width=78.1;
            break;
        case 4:
            myDevice.AppleiPhone[amountDevices].specsByModel.camera="Sistema de dos cámaras Gran angular de 12 MP | Ultra gran angular";
            myDevice.AppleiPhone[amountDevices].specsByModel.chip="Chip A15 Bionic";
            myDevice.AppleiPhone[amountDevices].specsByModel.conector="Lightning";
            myDevice.AppleiPhone[amountDevices].specsByModel.display="6.1\" Pantalla Super Retina XDR";
            myDevice.AppleiPhone[amountDevices].specsByModel.energy_batery="Hasta 19 horas de reproducción de video";
            myDevice.AppleiPhone[amountDevices].specsByModel.resistance="Frente de Ceramic Shield | Resistente al agua, 30 minutos - 6 metros | Aluminio de calidad aeroespacial";
            myDevice.AppleiPhone[amountDevices].specsByModel.secureAuth="Face ID";
            myDevice.AppleiPhone[amountDevices].specsByModel.depth=7.65;
            myDevice.AppleiPhone[amountDevices].specsByModel.height=146.7;
            myDevice.AppleiPhone[amountDevices].specsByModel.weight=173;
            myDevice.AppleiPhone[amountDevices].specsByModel.width=71.5;
            break;
        case 5:
            myDevice.AppleiPhone[amountDevices].specsByModel.camera="Sistema de cámaras Pro Gran angular de 12 MP | Ultra gran angular | Teleobjetivo";
            myDevice.AppleiPhone[amountDevices].specsByModel.chip="Chip A14 Bionic";
            myDevice.AppleiPhone[amountDevices].specsByModel.conector="Lightning";
            myDevice.AppleiPhone[amountDevices].specsByModel.display="6.7\" Pantalla Super Retina XDR";
            myDevice.AppleiPhone[amountDevices].specsByModel.energy_batery="Hasta 20 horas de reproducción de video";
            myDevice.AppleiPhone[amountDevices].specsByModel.resistance="Frente de Ceramic Shield | Resistente al agua, 30 minutos - 6 metros | Acero inoxidable de calidad quirurgica";
            myDevice.AppleiPhone[amountDevices].specsByModel.secureAuth="Face ID";
            myDevice.AppleiPhone[amountDevices].specsByModel.depth=7.4;
            myDevice.AppleiPhone[amountDevices].specsByModel.height=160.8;
            myDevice.AppleiPhone[amountDevices].specsByModel.weight=228;
            myDevice.AppleiPhone[amountDevices].specsByModel.width=78.1;
            break;
        case 6:
            myDevice.AppleiPhone[amountDevices].specsByModel.camera="Sistema de dos cámaras Gran angular de 12 MP | Ultra gran angular";
            myDevice.AppleiPhone[amountDevices].specsByModel.chip="Chip A14 Bionic";
            myDevice.AppleiPhone[amountDevices].specsByModel.conector="Lightning";
            myDevice.AppleiPhone[amountDevices].specsByModel.display="6.1\" Pantalla Super Retina XDR";
            myDevice.AppleiPhone[amountDevices].specsByModel.energy_batery="Hasta 17 horas de reproducción de video";
            myDevice.AppleiPhone[amountDevices].specsByModel.resistance="Frente de Ceramic Shield | Resistente al agua, 30 minutos - 6 metros | Aluminio de calidad aeroespacial";
            myDevice.AppleiPhone[amountDevices].specsByModel.secureAuth="Face ID";
            myDevice.AppleiPhone[amountDevices].specsByModel.depth=7.4;
            myDevice.AppleiPhone[amountDevices].specsByModel.height=146.7;
            myDevice.AppleiPhone[amountDevices].specsByModel.weight=164;
            myDevice.AppleiPhone[amountDevices].specsByModel.width=71.5;
            break;
        case 7:
            myDevice.AppleiPhone[amountDevices].specsByModel.camera="Sistema de tres cámaras Gran angular de 12 MP | Ultra gran angular | Teleobjetivo";
            myDevice.AppleiPhone[amountDevices].specsByModel.chip="Chip A13 Bionic";
            myDevice.AppleiPhone[amountDevices].specsByModel.conector="Lightning";
            myDevice.AppleiPhone[amountDevices].specsByModel.display="6.5\" Pantalla Super Retina XDR";
            myDevice.AppleiPhone[amountDevices].specsByModel.energy_batery="Hasta 20 horas de reproducción de video";
            myDevice.AppleiPhone[amountDevices].specsByModel.resistance="Delantera y posterior de vidrio | Resistente al agua, 30 minutos - 4 metros | Acero inoxidable de calidad quirúrgica";
            myDevice.AppleiPhone[amountDevices].specsByModel.secureAuth="Face ID";
            myDevice.AppleiPhone[amountDevices].specsByModel.depth=8.1;
            myDevice.AppleiPhone[amountDevices].specsByModel.height=158.0;
            myDevice.AppleiPhone[amountDevices].specsByModel.weight=226;
            myDevice.AppleiPhone[amountDevices].specsByModel.width=77.8;
            break;
        case 8:
            myDevice.AppleiPhone[amountDevices].specsByModel.camera="Sistema de dos cámaras Gran angular de 12 MP | Ultra gran angular";
            myDevice.AppleiPhone[amountDevices].specsByModel.chip="Chip A13 Bionic";
            myDevice.AppleiPhone[amountDevices].specsByModel.conector="Lightning";
            myDevice.AppleiPhone[amountDevices].specsByModel.display="6.1\" Pantalla Liquid Retina HD";
            myDevice.AppleiPhone[amountDevices].specsByModel.energy_batery="Hasta 17 horas de reproducción de video";
            myDevice.AppleiPhone[amountDevices].specsByModel.resistance="Delantera y posterior de vidrio | Resistente al agua, 30 minutos - 2 metros | Aluminio de calidad aeroespacial";
            myDevice.AppleiPhone[amountDevices].specsByModel.secureAuth="Face ID";
            myDevice.AppleiPhone[amountDevices].specsByModel.depth=8.3;
            myDevice.AppleiPhone[amountDevices].specsByModel.height=150.9;
            myDevice.AppleiPhone[amountDevices].specsByModel.weight=194;
            myDevice.AppleiPhone[amountDevices].specsByModel.width=75.7;
            break;
        case 9:
            myDevice.AppleiPhone[amountDevices].specsByModel.camera="Sistema de dos cámaras Gran angular de 12 MP | Teleobjetivo";
            myDevice.AppleiPhone[amountDevices].specsByModel.chip="Chip A12 Bionic";
            myDevice.AppleiPhone[amountDevices].specsByModel.conector="Lightning";
            myDevice.AppleiPhone[amountDevices].specsByModel.display="6.5\" Pantalla Super Retina HD";
            myDevice.AppleiPhone[amountDevices].specsByModel.energy_batery="Hasta 15 horas de reproducción de video";
            myDevice.AppleiPhone[amountDevices].specsByModel.resistance="Delantera y posterior de vidrio | Resistente al agua, 30 minutos - 2 metros | Acero inoxidable de calidad quirúrgica";
            myDevice.AppleiPhone[amountDevices].specsByModel.secureAuth="Face ID";
            myDevice.AppleiPhone[amountDevices].specsByModel.depth=7.7;
            myDevice.AppleiPhone[amountDevices].specsByModel.height=157.5;
            myDevice.AppleiPhone[amountDevices].specsByModel.weight=208;
            myDevice.AppleiPhone[amountDevices].specsByModel.width=77.4;
            break;
        case 10:
            myDevice.AppleiPhone[amountDevices].specsByModel.camera="Sistema de dos cámaras Gran angular de 12 MP | Teleobjetivo";
            myDevice.AppleiPhone[amountDevices].specsByModel.chip="A11 Bionic";
            myDevice.AppleiPhone[amountDevices].specsByModel.conector="Lightning";
            myDevice.AppleiPhone[amountDevices].specsByModel.display="5.8\" Pantalla Super Retina HD";
            myDevice.AppleiPhone[amountDevices].specsByModel.energy_batery="Hasta 13 horas de reproducción de video";
            myDevice.AppleiPhone[amountDevices].specsByModel.resistance="Delantera y posterior de vidrio | Resistente al agua, 30 minutos - 1 metro | Acero inoxidable de calidad quirúrgica";
            myDevice.AppleiPhone[amountDevices].specsByModel.secureAuth="Face ID";
            myDevice.AppleiPhone[amountDevices].specsByModel.depth=7.7;
            myDevice.AppleiPhone[amountDevices].specsByModel.height=143.6;
            myDevice.AppleiPhone[amountDevices].specsByModel.weight=174;
            myDevice.AppleiPhone[amountDevices].specsByModel.width=70.9;
            break;
    }
    return 0;
}
int showMenuiPhone(){
    cout<<"\n\t\tModelo del dispositivo: \n";
    cout<<"\t-------------------------------------------------------\n";
    cout<<"  1-. iPhone 14 Pro Max\n";
    cout<<"  2-. iPhone 14\n";
    cout<<"  3-. iPhone 13 Pro Max\n";
    cout<<"  4-. iPhone 13\n";
    cout<<"  5-. iPhone 12 Pro Max\n";
    cout<<"  6-. iPhone 12\n";
    cout<<"  7-. iPhone 11 Pro Max\n";
    cout<<"  8-. iPhone 11\n";
    cout<<"  9-. iPhone Xs Max\n";
    cout<<"  10-. iPhone X\n\n";
    return 0;
}
int addDeviceOption(int selectedDevice, Device &myDevice, int amountDevices){
    int selectedModel;
    switch(selectedDevice){
        case 1:
            showMenuiPhone();
            getMenuOption(selectedModel,1,10);
            setiPhoneData(selectedModel,amountDevices,myDevice);
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        default:
            break;
    }
    return 0;
}
int showDeviceMenu(){
    cout<<"\n\t\t¿Con qué tipo de dispositivo desea trabajar?:\n";
    cout<<"\t-------------------------------------------------------\n";
    cout<<"  1-. iPhone\n";
    cout<<"  2-. iPad\n";
    cout<<"  3-. Mac\n";
    cout<<"  4-. AirPods\n";
    cout<<"  5-. Watch\n\n";
    return 0;
}
int performMainOption(int mainOption, Device &myDevice, int amountDevices){
    switch(mainOption){
        case 1:
            int selectedDevice;
            showDeviceMenu();
            getMenuOption(selectedDevice,1,5);
            addDeviceOption(selectedDevice,myDevice,amountDevices);
            break;
        case 2:
            cout<<"la 1";
            break;
        case 3:
            cout<<"la 1";
            break;
        case 4:
            cout<<"la 1";
            break;
        case 5:
            cout<<"la 1";
            break;
        case 6:
            cout<<"la 1";
            break;
        case 7:
            cout<<"la 1";
            break;
        case 8:
            cout<<"la 1";
            break;
        default:
            cout<<"\nError, opción no encontrada.\n";
            break;
    }
    return 0;
}
int getMenuOption(int &Option, int firstOption, int lastOption){
    do{
        cout<<"\tDigite una opción: ";
        cin>>Option; cin.ignore();
    }while(Option<firstOption || Option>lastOption);
    return 0;
}
int showMainMenu(){
    cout<<"\t\t\tMenú de opciones:\n";
    cout<<"\t-------------------------------------------------------\n";
    cout<<"  1-. Agregar un registro\n";
    cout<<"  2-. Mostrar todos los registros\n";
    cout<<"  3-. Mostrar todos los registros (Dispositivo en especifico)\n";
    cout<<"  4-. Generar un archivo de texto con los datos actuales\n";
    cout<<"  5-. Obtener registros de un archivo de texto\n";
    cout<<"  6-. Buscar un registro\n";
    cout<<"  7-. Modificar un registro especifico\n";
    cout<<"  8-. Eliminar un registro especifico\n\n";
    return 0;
}
