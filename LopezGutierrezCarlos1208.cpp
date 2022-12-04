/*
Programa: Base de datos de un hombre pobre
Por Carlos Eduardo L�pez Guti�rrez
*/

#include <iostream>
#include <clocale>

#define DeviceMAX 100

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
    string model;
    //"Apple Watch Ultra","Apple Watch Series","Apple Watch SE";
    string color;
    int id_Device;
    Watch_SpecsByModel specsByModel;
};
struct AirPods{
    float price;
    string model;
    //"AirPods (2da Generaci�n)","AirPods (3ra Generaci�n)","AirPods Pro","AirPods Max";
    string color;
    int id_Device;
    AirPods_SpecsByModel specsByModel;
    AirPods_CharginCaseSpecs caseSpecs;
};
struct Mac{
    float price;
    int storage;
    string model;
    //"MacBook Pro","MacBook Air","iMac","iMac Pro","Mac mini","Mac studio","Mac Pro";
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
    string model;
    //"iPad Pro","iPad Air","iPad mini";
    string color;
    int id_Device;
    iPad_SpecsByModel specsByModel;
};
struct iPhone{
    float price;
    int storage;
    string model;
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
int performMainOption(int mainOption, Device &myDevice, int *amountDevices);
int showDeviceMenu();
int addDeviceOption(int selectedDevice, Device &myDevice, int &amountDevices);
int showMenuiPhone();
int setiPhoneData(int selectedModel, int amountDevices, Device &myDevice);
int showOneDevice(Device myDevice, int numberDevice, int typeDevice);
int showAllDevices(Device myDevice, int *amountDevices);

int main(void){
    system("COLOR F1");
    setlocale(LC_CTYPE, "spanish");
    // ************************************ Code ***************************************

    cout<<"\n\t\tBase de Datos de un Hombre Pobre\n\n";

    Device myDevice;
    int menuSelectedOption;
    int amountDevices[5]={};

    do{
        showMainMenu();
        getMenuOption(menuSelectedOption,1,9);
        performMainOption(menuSelectedOption,myDevice,amountDevices);
    }while(menuSelectedOption!=9);

    cout<<"\n"<<amountDevices[0];

    // ********************************** Footer ****************************************
    cout << "\n\n\n\nPara salir, presiona la tecla 'Enter'";
    cin.get();
}

//***************************************** Functions ***********************************

int showAllDevices(Device myDevice, int *amountDevices){
    for(int k=0;k<5;k++){
        switch(k){
        case 0:
            cout<<"\n\t\tRegistros de iPhone: \n";
            break;
        case 1:
            cout<<"\n\t\tRegistros de iPad: \n";
            break;
        case 2:
            cout<<"\n\t\tRegistros de Mac: \n";
            break;
        case 3:
            cout<<"\n\t\tRegistros de AirPods: \n";
            break;
        case 4:
            cout<<"\n\t\tRegistros de Watch: \n";
            break;
        }
        cout<<"\t-------------------------------------------------------\n";
        for(int l=0;l<amountDevices[k];l++){
            showOneDevice(myDevice,l,k);
        }
    }
    return 0;
}
int showOneDevice(Device myDevice, int numberDevice, int typeDevice){
    switch(typeDevice){
    case 0:
        cout<<"\t\tModelo: "<<myDevice.AppleiPhone[numberDevice].model<<endl;
        cout<<"\t\tColor: "<<myDevice.AppleiPhone[numberDevice].color<<endl;
        cout<<"\t\tID: "<<myDevice.AppleiPhone[numberDevice].id_Device<<endl;
        cout<<"\t\tAlmacenamiento: "<<myDevice.AppleiPhone[numberDevice].storage<<endl;
        cout<<"\t\tPrecio: "<<myDevice.AppleiPhone[numberDevice].price<<endl;
        cout<<"\t\tCamara: "<<myDevice.AppleiPhone[numberDevice].specsByModel.camera<<endl;
        cout<<"\t\tChip: "<<myDevice.AppleiPhone[numberDevice].specsByModel.chip<<endl;
        cout<<"\t\tConector: "<<myDevice.AppleiPhone[numberDevice].specsByModel.conector<<endl;
        cout<<"\t\tPantalla: "<<myDevice.AppleiPhone[numberDevice].specsByModel.display<<endl;
        cout<<"\t\tBateria: "<<myDevice.AppleiPhone[numberDevice].specsByModel.energy_batery<<endl;
        cout<<"\t\tResistencia: "<<myDevice.AppleiPhone[numberDevice].specsByModel.resistance<<endl;
        cout<<"\t\tSeguridad: "<<myDevice.AppleiPhone[numberDevice].specsByModel.secureAuth<<endl;
        cout<<"\t\tGrosor: "<<myDevice.AppleiPhone[numberDevice].specsByModel.depth<<endl;
        cout<<"\t\tAlto: "<<myDevice.AppleiPhone[numberDevice].specsByModel.height<<endl;
        cout<<"\t\tPeso: "<<myDevice.AppleiPhone[numberDevice].specsByModel.weight<<endl;
        cout<<"\t\tAncho: "<<myDevice.AppleiPhone[numberDevice].specsByModel.width<<endl<<endl;
        break;
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    default:
        break;
    }
    return 0;
}
int setiPhoneData(int selectedModel, int amountDevices, Device &myDevice){
    cout<<"\nID producto (4 n�meros): ";
    cin>>myDevice.AppleiPhone[amountDevices].id_Device; cin.ignore();
    cout<<"Color: ";
    getline(cin,myDevice.AppleiPhone[amountDevices].color);
    cout<<"Almacenamiento [GB]: ";
    cin>>myDevice.AppleiPhone[amountDevices].storage; cin.ignore();
    cout<<"Precio (USD): ";
    cin>>myDevice.AppleiPhone[amountDevices].price; cin.ignore();

    switch(selectedModel){
        case 1:
            myDevice.AppleiPhone[amountDevices].model="iPhone 14 Pro Max";
            myDevice.AppleiPhone[amountDevices].specsByModel.camera="Sistema de c�maras Pro Gran angular de 48�MP | Ultra gran angular | Teleobjetivo";
            myDevice.AppleiPhone[amountDevices].specsByModel.chip="A16 Bonic";
            myDevice.AppleiPhone[amountDevices].specsByModel.conector="Lightning";
            myDevice.AppleiPhone[amountDevices].specsByModel.display="6,7\" Super Retina XDR";
            myDevice.AppleiPhone[amountDevices].specsByModel.energy_batery="Hasta 29�horas de reproducci�n de�video";
            myDevice.AppleiPhone[amountDevices].specsByModel.resistance="Frente de Ceramic Shield | Resistente al agua, 30�minutos - 6�metros | Acero inoxidable de calidad quir�rgica";
            myDevice.AppleiPhone[amountDevices].specsByModel.secureAuth="Face ID";
            myDevice.AppleiPhone[amountDevices].specsByModel.depth=7.85;
            myDevice.AppleiPhone[amountDevices].specsByModel.height=160.7;
            myDevice.AppleiPhone[amountDevices].specsByModel.weight=240;
            myDevice.AppleiPhone[amountDevices].specsByModel.width=77.6;
            break;
        case 2:
            myDevice.AppleiPhone[amountDevices].model="iPhone 14";
            myDevice.AppleiPhone[amountDevices].specsByModel.camera="Sistema avanzado de dos c�maras Gran angular de 12 MP | Ultra gran angular";
            myDevice.AppleiPhone[amountDevices].specsByModel.chip="A15 Bonic";
            myDevice.AppleiPhone[amountDevices].specsByModel.conector="Lightning";
            myDevice.AppleiPhone[amountDevices].specsByModel.display="6,1\" Super Retina XDR";
            myDevice.AppleiPhone[amountDevices].specsByModel.energy_batery="Hasta 20�horas de reproducci�n de�video";
            myDevice.AppleiPhone[amountDevices].specsByModel.resistance="Frente de Ceramic Shield | Resistente al agua, 30�minutos - 6�metros | Aluminio de calidad aeroespacial";
            myDevice.AppleiPhone[amountDevices].specsByModel.secureAuth="Face ID";
            myDevice.AppleiPhone[amountDevices].specsByModel.depth=7.80;
            myDevice.AppleiPhone[amountDevices].specsByModel.height=146.7;
            myDevice.AppleiPhone[amountDevices].specsByModel.weight=172;
            myDevice.AppleiPhone[amountDevices].specsByModel.width=71.5;
            break;
        case 3:
            myDevice.AppleiPhone[amountDevices].model="iPhone 13 Pro Max";
            myDevice.AppleiPhone[amountDevices].specsByModel.camera="Sistema de c�maras Pro Gran angular de 12�MP | Ultra gran angular | Teleobjetivo";
            myDevice.AppleiPhone[amountDevices].specsByModel.chip="A15 Bonic";
            myDevice.AppleiPhone[amountDevices].specsByModel.conector="Lightning";
            myDevice.AppleiPhone[amountDevices].specsByModel.display="6,7\" Super Retina XDR";
            myDevice.AppleiPhone[amountDevices].specsByModel.energy_batery="Hasta 28�horas de reproducci�n de�video";
            myDevice.AppleiPhone[amountDevices].specsByModel.resistance="Frente de Ceramic Shield | Resistente al agua, 30�minutos - 6�metros | Acero inoxidable de calidad quir�rgica";
            myDevice.AppleiPhone[amountDevices].specsByModel.secureAuth="Face ID";
            myDevice.AppleiPhone[amountDevices].specsByModel.depth=7.65;
            myDevice.AppleiPhone[amountDevices].specsByModel.height=160.8;
            myDevice.AppleiPhone[amountDevices].specsByModel.weight=240;
            myDevice.AppleiPhone[amountDevices].specsByModel.width=78.1;
            break;
        case 4:
            myDevice.AppleiPhone[amountDevices].model="iPhone 13";
            myDevice.AppleiPhone[amountDevices].specsByModel.camera="Sistema de dos c�maras Gran angular de 12�MP | Ultra gran angular";
            myDevice.AppleiPhone[amountDevices].specsByModel.chip="Chip A15�Bionic";
            myDevice.AppleiPhone[amountDevices].specsByModel.conector="Lightning";
            myDevice.AppleiPhone[amountDevices].specsByModel.display="6.1\" Pantalla Super Retina XDR";
            myDevice.AppleiPhone[amountDevices].specsByModel.energy_batery="Hasta 19�horas de reproducci�n de�video";
            myDevice.AppleiPhone[amountDevices].specsByModel.resistance="Frente de Ceramic Shield | Resistente al agua, 30�minutos - 6�metros | Aluminio de calidad aeroespacial";
            myDevice.AppleiPhone[amountDevices].specsByModel.secureAuth="Face ID";
            myDevice.AppleiPhone[amountDevices].specsByModel.depth=7.65;
            myDevice.AppleiPhone[amountDevices].specsByModel.height=146.7;
            myDevice.AppleiPhone[amountDevices].specsByModel.weight=173;
            myDevice.AppleiPhone[amountDevices].specsByModel.width=71.5;
            break;
        case 5:
            myDevice.AppleiPhone[amountDevices].model="iPhone 12 Pro Max";
            myDevice.AppleiPhone[amountDevices].specsByModel.camera="Sistema de c�maras Pro Gran angular de 12�MP | Ultra gran angular | Teleobjetivo";
            myDevice.AppleiPhone[amountDevices].specsByModel.chip="Chip A14�Bionic";
            myDevice.AppleiPhone[amountDevices].specsByModel.conector="Lightning";
            myDevice.AppleiPhone[amountDevices].specsByModel.display="6.7\" Pantalla Super Retina XDR";
            myDevice.AppleiPhone[amountDevices].specsByModel.energy_batery="Hasta 20�horas de reproducci�n de�video";
            myDevice.AppleiPhone[amountDevices].specsByModel.resistance="Frente de Ceramic Shield | Resistente al agua, 30�minutos - 6�metros | Acero inoxidable de calidad quirurgica";
            myDevice.AppleiPhone[amountDevices].specsByModel.secureAuth="Face ID";
            myDevice.AppleiPhone[amountDevices].specsByModel.depth=7.4;
            myDevice.AppleiPhone[amountDevices].specsByModel.height=160.8;
            myDevice.AppleiPhone[amountDevices].specsByModel.weight=228;
            myDevice.AppleiPhone[amountDevices].specsByModel.width=78.1;
            break;
        case 6:
            myDevice.AppleiPhone[amountDevices].model="iPhone 12";
            myDevice.AppleiPhone[amountDevices].specsByModel.camera="Sistema de dos c�maras Gran angular de 12�MP | Ultra gran angular";
            myDevice.AppleiPhone[amountDevices].specsByModel.chip="Chip A14�Bionic";
            myDevice.AppleiPhone[amountDevices].specsByModel.conector="Lightning";
            myDevice.AppleiPhone[amountDevices].specsByModel.display="6.1\" Pantalla Super Retina XDR";
            myDevice.AppleiPhone[amountDevices].specsByModel.energy_batery="Hasta 17�horas de reproducci�n de�video";
            myDevice.AppleiPhone[amountDevices].specsByModel.resistance="Frente de Ceramic Shield | Resistente al agua, 30�minutos - 6�metros | Aluminio de calidad aeroespacial";
            myDevice.AppleiPhone[amountDevices].specsByModel.secureAuth="Face ID";
            myDevice.AppleiPhone[amountDevices].specsByModel.depth=7.4;
            myDevice.AppleiPhone[amountDevices].specsByModel.height=146.7;
            myDevice.AppleiPhone[amountDevices].specsByModel.weight=164;
            myDevice.AppleiPhone[amountDevices].specsByModel.width=71.5;
            break;
        case 7:
            myDevice.AppleiPhone[amountDevices].model="iPhone 11 Pro Max";
            myDevice.AppleiPhone[amountDevices].specsByModel.camera="Sistema de tres c�maras Gran angular de 12�MP | Ultra gran angular | Teleobjetivo";
            myDevice.AppleiPhone[amountDevices].specsByModel.chip="Chip A13�Bionic";
            myDevice.AppleiPhone[amountDevices].specsByModel.conector="Lightning";
            myDevice.AppleiPhone[amountDevices].specsByModel.display="6.5\" Pantalla Super Retina XDR";
            myDevice.AppleiPhone[amountDevices].specsByModel.energy_batery="Hasta 20�horas de reproducci�n de�video";
            myDevice.AppleiPhone[amountDevices].specsByModel.resistance="Delantera y posterior de vidrio | Resistente al agua, 30�minutos - 4�metros | Acero inoxidable de calidad quir�rgica";
            myDevice.AppleiPhone[amountDevices].specsByModel.secureAuth="Face ID";
            myDevice.AppleiPhone[amountDevices].specsByModel.depth=8.1;
            myDevice.AppleiPhone[amountDevices].specsByModel.height=158.0;
            myDevice.AppleiPhone[amountDevices].specsByModel.weight=226;
            myDevice.AppleiPhone[amountDevices].specsByModel.width=77.8;
            break;
        case 8:
            myDevice.AppleiPhone[amountDevices].model="iPhone 11";
            myDevice.AppleiPhone[amountDevices].specsByModel.camera="Sistema de dos c�maras Gran angular de 12�MP | Ultra gran angular";
            myDevice.AppleiPhone[amountDevices].specsByModel.chip="Chip A13�Bionic";
            myDevice.AppleiPhone[amountDevices].specsByModel.conector="Lightning";
            myDevice.AppleiPhone[amountDevices].specsByModel.display="6.1\" Pantalla Liquid Retina HD";
            myDevice.AppleiPhone[amountDevices].specsByModel.energy_batery="Hasta 17�horas de reproducci�n de�video";
            myDevice.AppleiPhone[amountDevices].specsByModel.resistance="Delantera y posterior de vidrio | Resistente al agua, 30�minutos - 2�metros | Aluminio de calidad aeroespacial";
            myDevice.AppleiPhone[amountDevices].specsByModel.secureAuth="Face ID";
            myDevice.AppleiPhone[amountDevices].specsByModel.depth=8.3;
            myDevice.AppleiPhone[amountDevices].specsByModel.height=150.9;
            myDevice.AppleiPhone[amountDevices].specsByModel.weight=194;
            myDevice.AppleiPhone[amountDevices].specsByModel.width=75.7;
            break;
        case 9:
            myDevice.AppleiPhone[amountDevices].model="iPhone Xs Max";
            myDevice.AppleiPhone[amountDevices].specsByModel.camera="Sistema de dos c�maras Gran angular de 12�MP | Teleobjetivo";
            myDevice.AppleiPhone[amountDevices].specsByModel.chip="Chip A12�Bionic";
            myDevice.AppleiPhone[amountDevices].specsByModel.conector="Lightning";
            myDevice.AppleiPhone[amountDevices].specsByModel.display="6.5\" Pantalla Super Retina HD";
            myDevice.AppleiPhone[amountDevices].specsByModel.energy_batery="Hasta 15�horas de reproducci�n de�video";
            myDevice.AppleiPhone[amountDevices].specsByModel.resistance="Delantera y posterior de vidrio | Resistente al agua, 30�minutos - 2�metros | Acero inoxidable de calidad quir�rgica";
            myDevice.AppleiPhone[amountDevices].specsByModel.secureAuth="Face ID";
            myDevice.AppleiPhone[amountDevices].specsByModel.depth=7.7;
            myDevice.AppleiPhone[amountDevices].specsByModel.height=157.5;
            myDevice.AppleiPhone[amountDevices].specsByModel.weight=208;
            myDevice.AppleiPhone[amountDevices].specsByModel.width=77.4;
            break;
        case 10:
            myDevice.AppleiPhone[amountDevices].model="iPhone X";
            myDevice.AppleiPhone[amountDevices].specsByModel.camera="Sistema de dos c�maras Gran angular de 12�MP | Teleobjetivo";
            myDevice.AppleiPhone[amountDevices].specsByModel.chip="A11 Bionic";
            myDevice.AppleiPhone[amountDevices].specsByModel.conector="Lightning";
            myDevice.AppleiPhone[amountDevices].specsByModel.display="5.8\" Pantalla Super Retina HD";
            myDevice.AppleiPhone[amountDevices].specsByModel.energy_batery="Hasta 13�horas de reproducci�n de�video";
            myDevice.AppleiPhone[amountDevices].specsByModel.resistance="Delantera y posterior de vidrio | Resistente al agua, 30�minutos - 1�metro | Acero inoxidable de calidad quir�rgica";
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
int addDeviceOption(int selectedDevice, Device &myDevice, int &amountDevices){
    int selectedModel;
    switch(selectedDevice){
        case 1:
            showMenuiPhone();
            getMenuOption(selectedModel,1,10);
            setiPhoneData(selectedModel,amountDevices,myDevice);
            amountDevices++;
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
    cout<<"\n\t\t�Con qu� tipo de dispositivo desea trabajar?:\n";
    cout<<"\t-------------------------------------------------------\n";
    cout<<"  1-. iPhone\n";
    cout<<"  2-. iPad\n";
    cout<<"  3-. Mac\n";
    cout<<"  4-. AirPods\n";
    cout<<"  5-. Watch\n\n";
    return 0;
}
int performMainOption(int mainOption, Device &myDevice, int *amountDevices){
    switch(mainOption){
        case 1: //Agregar un dispositivo
            int selectedDevice;
            showDeviceMenu();
            getMenuOption(selectedDevice,1,5);
            addDeviceOption(selectedDevice,myDevice,amountDevices[selectedDevice-1]);
            break;
        case 2: //Mostrar todos los registros
            showAllDevices(myDevice,amountDevices);
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
        case 9:
            cout<<"la 1";
            break;
        default:
            cout<<"\nError, opci�n no encontrada.\n";
            break;
    }
    return 0;
}
int getMenuOption(int &Option, int firstOption, int lastOption){
    do{
        cout<<"\tDigite una opci�n: ";
        cin>>Option; cin.ignore();
    }while(Option<firstOption || Option>lastOption);
    return 0;
}
int showMainMenu(){
    cout<<"\t\t\tMen� de opciones:\n";
    cout<<"\t-------------------------------------------------------\n";
    cout<<"  1-. Agregar un registro\n";
    cout<<"  2-. Mostrar todos los registros\n";
    cout<<"  3-. Mostrar todos los registros (Dispositivo en especifico)\n";
    cout<<"  4-. Generar un archivo de texto con los datos actuales\n";
    cout<<"  5-. Obtener registros de un archivo de texto\n";
    cout<<"  6-. Buscar un registro\n";
    cout<<"  7-. Modificar un registro especifico\n";
    cout<<"  8-. Eliminar un registro especifico\n";
    cout<<"  9-. Salir\n\n";
    return 0;
}
