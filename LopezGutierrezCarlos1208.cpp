/*
Programa: Base de datos de un hombre (o mujer) pobre
Por Carlos Eduardo López Gutiérrez
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
    string CPU;
    string GPU;
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
    string color;
    int id_Device;
    Watch_SpecsByModel specsByModel;
};
struct AirPods{
    float price;
    string model;
    string color;
    int id_Device;
    AirPods_SpecsByModel specsByModel;
    AirPods_CharginCaseSpecs caseSpecs;
};
struct Mac{
    float price;
    int storage;
    string model;
    string color;
    int RAM;
    int id_Device;
    Mac_SpecsByModel specsByModel;
};
struct iPad{
    float price;
    int storage;
    string model;
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
int showDeviceMenu();
int showMenuiPhone();
int showMenuiPad();
int showMenuMac();
int showMenuAirPods();
int showMenuWatch();
int showOneDevice(Device myDevice, int numberDevice, int typeDevice);
int showAllDevices(Device myDevice, int *amountDevices);

int setiPhoneData(int selectedModel, int amountDevices, Device &myDevice);
int setiPadData(int selectedModel, int amountDevices, Device &myDevice);
int setMacData(int selectedModel, int amountDevices, Device &myDevice);
int setAirPodsData(int selectedModel, int amountDevices, Device &myDevice);
int setWatchData(int selectedModel, int amountDevices, Device &myDevice);

int getMenuOption(int &Option, int firstOption, int lastOption);

int performMainOption(int mainOption, Device &myDevice, int *amountDevices);

int addDeviceOption(int selectedDevice, Device &myDevice, int &amountDevices);

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

    for(int k=0;k<5;k++){
        cout<<amountDevices[k]<<"\n";
    }

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
        cout<<"\tModelo: "<<myDevice.AppleiPhone[numberDevice].model<<endl;
        cout<<"\tColor: "<<myDevice.AppleiPhone[numberDevice].color<<endl;
        cout<<"\tID: "<<myDevice.AppleiPhone[numberDevice].id_Device<<endl;
        cout<<"\tAlmacenamiento: "<<myDevice.AppleiPhone[numberDevice].storage<<endl;
        cout<<"\tPrecio: "<<myDevice.AppleiPhone[numberDevice].price<<endl;
        cout<<"\tCamara: "<<myDevice.AppleiPhone[numberDevice].specsByModel.camera<<endl;
        cout<<"\tChip: "<<myDevice.AppleiPhone[numberDevice].specsByModel.chip<<endl;
        cout<<"\tConector: "<<myDevice.AppleiPhone[numberDevice].specsByModel.conector<<endl;
        cout<<"\tPantalla: "<<myDevice.AppleiPhone[numberDevice].specsByModel.display<<endl;
        cout<<"\tBateria (rendimiento): "<<myDevice.AppleiPhone[numberDevice].specsByModel.energy_batery<<endl;
        cout<<"\tResistencia: "<<myDevice.AppleiPhone[numberDevice].specsByModel.resistance<<endl;
        cout<<"\tSeguridad: "<<myDevice.AppleiPhone[numberDevice].specsByModel.secureAuth<<endl;
        cout<<"\tGrosor: "<<myDevice.AppleiPhone[numberDevice].specsByModel.depth<<endl;
        cout<<"\tAlto: "<<myDevice.AppleiPhone[numberDevice].specsByModel.height<<endl;
        cout<<"\tPeso: "<<myDevice.AppleiPhone[numberDevice].specsByModel.weight<<endl;
        cout<<"\tAncho: "<<myDevice.AppleiPhone[numberDevice].specsByModel.width<<endl<<endl;
        break;
    case 1:
        cout<<"\tModelo: "<<myDevice.AppleiPad[numberDevice].model<<endl;
        cout<<"\tColor: "<<myDevice.AppleiPad[numberDevice].color<<endl;
        cout<<"\tID: "<<myDevice.AppleiPad[numberDevice].id_Device<<endl;
        cout<<"\tAlmacenamiento: "<<myDevice.AppleiPad[numberDevice].storage<<endl;
        cout<<"\tPrecio: "<<myDevice.AppleiPad[numberDevice].price<<endl;
        cout<<"\tCamara: "<<myDevice.AppleiPad[numberDevice].specsByModel.camera<<endl;
        cout<<"\tChip: "<<myDevice.AppleiPad[numberDevice].specsByModel.chip<<endl;
        cout<<"\tCompatibilidad: "<<myDevice.AppleiPad[numberDevice].specsByModel.compatibility<<endl;
        cout<<"\tConector: "<<myDevice.AppleiPad[numberDevice].specsByModel.conector<<endl;
        cout<<"\tPantalla: "<<myDevice.AppleiPad[numberDevice].specsByModel.display<<endl;
        cout<<"\tBateria (Rendimiento): "<<myDevice.AppleiPad[numberDevice].specsByModel.energy_batery<<endl;
        cout<<"\tSeguridad: "<<myDevice.AppleiPad[numberDevice].specsByModel.secureAuth<<endl;
        cout<<"\tGrosor: "<<myDevice.AppleiPad[numberDevice].specsByModel.depth<<endl;
        cout<<"\tAlto: "<<myDevice.AppleiPad[numberDevice].specsByModel.height<<endl;
        cout<<"\tPeso: "<<myDevice.AppleiPad[numberDevice].specsByModel.weight<<endl;
        cout<<"\tAncho: "<<myDevice.AppleiPad[numberDevice].specsByModel.width<<endl<<endl;
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
    cout<<"\n\t\tID producto: ";
    cin>>myDevice.AppleiPhone[amountDevices].id_Device; cin.ignore();
    cout<<"\t\tColor: ";
    getline(cin,myDevice.AppleiPhone[amountDevices].color);
    cout<<"\t\tAlmacenamiento [GB]: ";
    cin>>myDevice.AppleiPhone[amountDevices].storage; cin.ignore();
    cout<<"\t\tPrecio (USD): ";
    cin>>myDevice.AppleiPhone[amountDevices].price; cin.ignore();

    switch(selectedModel){
        case 1:
            myDevice.AppleiPhone[amountDevices].model="iPhone 14 Pro Max";
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
            myDevice.AppleiPhone[amountDevices].model="iPhone 14";
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
            myDevice.AppleiPhone[amountDevices].model="iPhone 13 Pro Max";
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
            myDevice.AppleiPhone[amountDevices].model="iPhone 13";
            myDevice.AppleiPhone[amountDevices].specsByModel.camera="Sistema de dos cámaras Gran angular de 12 MP | Ultra gran angular";
            myDevice.AppleiPhone[amountDevices].specsByModel.chip="Chip A15 Bionic";
            myDevice.AppleiPhone[amountDevices].specsByModel.conector="Lightning";
            myDevice.AppleiPhone[amountDevices].specsByModel.display="6.1\" Pantalla Super Retina XDR";
            myDevice.AppleiPhone[amountDevices].specsByModel.energy_batery="Hasta 19 horas de reproducción de video";
            myDevice.AppleiPhone[amountDevices].specsByModel.resistance="Frente de Ceramic Shield | Resistente al agua, 30 minutos - 6 metros | Aluminio de calidad aeroespacial";
            myDevice.AppleiPhone[amountDevices].specsByModel.secureAuth="Face ID";
            myDevice.AppleiPhone[amountDevices].specsByModel.depth=7.65;
            myDevice.AppleiPhone[amountDevices].specsByModel.height=146.7;
            myDevice.AppleiPhone[amountDevices].specsByModel.weight=173;
            myDevice.AppleiPhone[amountDevices].specsByModel.width=71.5;
            break;
        case 5:
            myDevice.AppleiPhone[amountDevices].model="iPhone 12 Pro Max";
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
            myDevice.AppleiPhone[amountDevices].model="iPhone 12";
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
            myDevice.AppleiPhone[amountDevices].model="iPhone 11 Pro Max";
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
            myDevice.AppleiPhone[amountDevices].model="iPhone 11";
            myDevice.AppleiPhone[amountDevices].specsByModel.camera="Sistema de dos cámaras Gran angular de 12 MP | Ultra gran angular";
            myDevice.AppleiPhone[amountDevices].specsByModel.chip="Chip A13 Bionic";
            myDevice.AppleiPhone[amountDevices].specsByModel.conector="Lightning";
            myDevice.AppleiPhone[amountDevices].specsByModel.display="6.1\" Pantalla Liquid Retina HD";
            myDevice.AppleiPhone[amountDevices].specsByModel.energy_batery="Hasta 17 horas de reproducción de video";
            myDevice.AppleiPhone[amountDevices].specsByModel.resistance="Delantera y posterior de vidrio | Resistente al agua, 30 minutos - 2 metros | Aluminio de calidad aeroespacial";
            myDevice.AppleiPhone[amountDevices].specsByModel.secureAuth="Face ID";
            myDevice.AppleiPhone[amountDevices].specsByModel.depth=8.3;
            myDevice.AppleiPhone[amountDevices].specsByModel.height=150.9;
            myDevice.AppleiPhone[amountDevices].specsByModel.weight=194;
            myDevice.AppleiPhone[amountDevices].specsByModel.width=75.7;
            break;
        case 9:
            myDevice.AppleiPhone[amountDevices].model="iPhone Xs Max";
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
            myDevice.AppleiPhone[amountDevices].model="iPhone X";
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
        default:
            cout<<"\nError, modelo de iPhone no encontrado\n";
            break;
    }
    return 0;
}
int setiPadData(int selectedModel, int amountDevices, Device &myDevice){
    cout<<"\n\t\tID producto: ";
    cin>>myDevice.AppleiPad[amountDevices].id_Device; cin.ignore();
    cout<<"\t\tColor: ";
    getline(cin,myDevice.AppleiPad[amountDevices].color);
    cout<<"\t\tAlmacenamiento [GB]: ";
    cin>>myDevice.AppleiPad[amountDevices].storage; cin.ignore();
    cout<<"\t\tPrecio (USD): ";
    cin>>myDevice.AppleiPad[amountDevices].price; cin.ignore();

    switch(selectedModel){
        case 1:
            myDevice.AppleiPad[amountDevices].model="iPad Pro";
            myDevice.AppleiPad[amountDevices].specsByModel.camera="Cámara gran angular de 12 MP y cámara ultra gran angular de 10 MP";
            myDevice.AppleiPad[amountDevices].specsByModel.chip="Chip M2";
            myDevice.AppleiPad[amountDevices].specsByModel.compatibility="Compatible con Apple Pencil (2da G), Magic Keyboard y Smart Keyboard";
            myDevice.AppleiPad[amountDevices].specsByModel.conector="Conector USB-C compatible con thunderbolt/USB 4";
            myDevice.AppleiPad[amountDevices].specsByModel.display="12.9\" Pantalla Liquid Retina XDR";
            myDevice.AppleiPad[amountDevices].specsByModel.energy_batery="Hasta 10 horas para navegar por Internet a través de Wi-Fi o ver videos";
            myDevice.AppleiPad[amountDevices].specsByModel.secureAuth="Face ID";
            myDevice.AppleiPad[amountDevices].specsByModel.depth=6.4;
            myDevice.AppleiPad[amountDevices].specsByModel.height=280.6;
            myDevice.AppleiPad[amountDevices].specsByModel.weight=682;
            myDevice.AppleiPad[amountDevices].specsByModel.width=214.9;
            break;
        case 2:
            myDevice.AppleiPad[amountDevices].model="iPad Air";
            myDevice.AppleiPad[amountDevices].specsByModel.camera="Cámara gran angular de 12 MP";
            myDevice.AppleiPad[amountDevices].specsByModel.chip="Chip M1";
            myDevice.AppleiPad[amountDevices].specsByModel.compatibility="Compatible con Apple Pencil (2da G), Magic Keyboard y Smart Keyboard";
            myDevice.AppleiPad[amountDevices].specsByModel.conector="Conector USB-C";
            myDevice.AppleiPad[amountDevices].specsByModel.display="10.9\" Pantalla Liquid Retina";
            myDevice.AppleiPad[amountDevices].specsByModel.energy_batery="Hasta 10 horas para navegar por Internet a través de Wi-Fi o ver videos";
            myDevice.AppleiPad[amountDevices].specsByModel.secureAuth="Touch ID";
            myDevice.AppleiPad[amountDevices].specsByModel.depth=6.1;
            myDevice.AppleiPad[amountDevices].specsByModel.height=247.6;
            myDevice.AppleiPad[amountDevices].specsByModel.weight=461;
            myDevice.AppleiPad[amountDevices].specsByModel.width=178.5;
            break;
        case 3:
            myDevice.AppleiPad[amountDevices].model="iPad mini";
            myDevice.AppleiPad[amountDevices].specsByModel.camera="Cámara gran angular de 12 MP";
            myDevice.AppleiPad[amountDevices].specsByModel.chip="Chip A15 Bionic";
            myDevice.AppleiPad[amountDevices].specsByModel.compatibility="Compatible con Apple Pencil (2da G) y Teclados Bluetooth";
            myDevice.AppleiPad[amountDevices].specsByModel.conector="Conector USB-C";
            myDevice.AppleiPad[amountDevices].specsByModel.display="8.3\" Pantalla Liquid Retina";
            myDevice.AppleiPad[amountDevices].specsByModel.energy_batery="Hasta 10 horas para navegar por Internet a través de Wi-Fi o ver videos";
            myDevice.AppleiPad[amountDevices].specsByModel.secureAuth="Touch ID";
            myDevice.AppleiPad[amountDevices].specsByModel.depth=6.3;
            myDevice.AppleiPad[amountDevices].specsByModel.height=195.4;
            myDevice.AppleiPad[amountDevices].specsByModel.weight=293;
            myDevice.AppleiPad[amountDevices].specsByModel.width=134.8;
            break;
        default:
            cout<<"\nError, modelo de iPad no encontrado\n";
            break;
    }
    return 0;
}
int setMacData(int selectedModel, int amountDevices, Device &myDevice){
    cout<<"\n\t\tID producto: ";
    cin>>myDevice.AppleMac[amountDevices].id_Device; cin.ignore();
    cout<<"\t\tColor: ";
    getline(cin,myDevice.AppleMac[amountDevices].color);
    cout<<"\t\tAlmacenamiento [GB]: ";
    cin>>myDevice.AppleMac[amountDevices].storage; cin.ignore();
    cout<<"\t\tMemoria RAM [GB]: ";
    cin>>myDevice.AppleMac[amountDevices].RAM; cin.ignore();
    cout<<"\t\tPrecio (USD): ";
    cin>>myDevice.AppleMac[amountDevices].price; cin.ignore();

    switch(selectedModel){
        case 1:
            myDevice.AppleiPad[amountDevices].model="MacBook Pro";
            myDevice.AppleMac[amountDevices].specsByModel.camera="Cámara FaceTime HD de 720p";
            myDevice.AppleMac[amountDevices].specsByModel.chip="Chip M2 de Apple";
            myDevice.AppleMac[amountDevices].specsByModel.CPU="8 núcleos";
            myDevice.AppleMac[amountDevices].specsByModel.display="Pantalla Retina 13.3\"";
            myDevice.AppleMac[amountDevices].specsByModel.energy_batery="20 horas de bateria";
            myDevice.AppleMac[amountDevices].specsByModel.GPU="10 núcleos";
            myDevice.AppleMac[amountDevices].specsByModel.keyboard_trackpad="Magic Keyboard retroiluminado | Touch Bar";
            myDevice.AppleMac[amountDevices].specsByModel.ports="Dos puertos Thunderbolt/USB 4";
            myDevice.AppleMac[amountDevices].specsByModel.secureAuth="Touch Bar y Touch ID";
            myDevice.AppleMac[amountDevices].specsByModel.depth=21.24;
            myDevice.AppleMac[amountDevices].specsByModel.height=1.56;
            myDevice.AppleMac[amountDevices].specsByModel.weight=1.4;
            myDevice.AppleMac[amountDevices].specsByModel.width=30.41;
            break;
        case 2:
            myDevice.AppleiPad[amountDevices].model="MacBook Air";
            myDevice.AppleMac[amountDevices].specsByModel.camera="Cámara FaceTime HD de 1080p";
            myDevice.AppleMac[amountDevices].specsByModel.chip="Chip M2 de Apple";
            myDevice.AppleMac[amountDevices].specsByModel.CPU="8 núcleos";
            myDevice.AppleMac[amountDevices].specsByModel.display="Pantalla Liquid Retina 13.6\"";
            myDevice.AppleMac[amountDevices].specsByModel.energy_batery="18 horas de bateria";
            myDevice.AppleMac[amountDevices].specsByModel.GPU="10 núcleos";
            myDevice.AppleMac[amountDevices].specsByModel.keyboard_trackpad="Magic Keyboard retroiluminado";
            myDevice.AppleMac[amountDevices].specsByModel.ports="Dos puertos Thunderbolt/USB 4";
            myDevice.AppleMac[amountDevices].specsByModel.secureAuth="Touch ID";
            myDevice.AppleMac[amountDevices].specsByModel.depth=21.5;
            myDevice.AppleMac[amountDevices].specsByModel.height=1.13;
            myDevice.AppleMac[amountDevices].specsByModel.weight=1.24;
            myDevice.AppleMac[amountDevices].specsByModel.width=30.41;
            break;
        case 3:
            myDevice.AppleiPad[amountDevices].model="iMac";
            myDevice.AppleMac[amountDevices].specsByModel.camera="Cámara FaceTime HD de 1080p";
            myDevice.AppleMac[amountDevices].specsByModel.chip="Intel Core i9";
            myDevice.AppleMac[amountDevices].specsByModel.CPU="10 núcleos";
            myDevice.AppleMac[amountDevices].specsByModel.display="Pantalla Retina 5K 27\"";
            myDevice.AppleMac[amountDevices].specsByModel.energy_batery="No Aplica";
            myDevice.AppleMac[amountDevices].specsByModel.GPU="AMD Radeon Pro 5700 XT";
            myDevice.AppleMac[amountDevices].specsByModel.keyboard_trackpad="Magic Mouse o Magic Trackpad";
            myDevice.AppleMac[amountDevices].specsByModel.ports="Dos puertos Thunderbolt 3 (USB-C) | Cuatro puertos USB-A";
            myDevice.AppleMac[amountDevices].specsByModel.secureAuth="Magic Keyboard";
            myDevice.AppleMac[amountDevices].specsByModel.depth=20.3;
            myDevice.AppleMac[amountDevices].specsByModel.height=51.6;
            myDevice.AppleMac[amountDevices].specsByModel.weight=8.92;
            myDevice.AppleMac[amountDevices].specsByModel.width=65;
            break;
        case 4:
            myDevice.AppleiPad[amountDevices].model="iMac Pro";
            myDevice.AppleMac[amountDevices].specsByModel.camera="Cámara FaceTime HD de 1080p";
            myDevice.AppleMac[amountDevices].specsByModel.chip="Intel Xeon W";
            myDevice.AppleMac[amountDevices].specsByModel.CPU="18 núcleos";
            myDevice.AppleMac[amountDevices].specsByModel.display="Pantalla Retina 5k de 27 pulgadas (diagonal) retroiluminada por LED";
            myDevice.AppleMac[amountDevices].specsByModel.energy_batery="No aplica";
            myDevice.AppleMac[amountDevices].specsByModel.GPU="AMD Radeon Pro Vega 64X";
            myDevice.AppleMac[amountDevices].specsByModel.keyboard_trackpad="Magic Keyboard con teclado numérico";
            myDevice.AppleMac[amountDevices].specsByModel.ports="Cuatro puertos Thunderbolt 3 (USB-C) | Cuatro puertos USB-A";
            myDevice.AppleMac[amountDevices].specsByModel.secureAuth="No aplica";
            myDevice.AppleMac[amountDevices].specsByModel.depth=20.3;
            myDevice.AppleMac[amountDevices].specsByModel.height=51.6;
            myDevice.AppleMac[amountDevices].specsByModel.weight=9.7;
            myDevice.AppleMac[amountDevices].specsByModel.width=65;
            break;
        case 5:
            myDevice.AppleiPad[amountDevices].model="Mac mini";
            myDevice.AppleMac[amountDevices].specsByModel.camera="No aplica";
            myDevice.AppleMac[amountDevices].specsByModel.chip="Chip M1 de Apple";
            myDevice.AppleMac[amountDevices].specsByModel.CPU="8 núcleos";
            myDevice.AppleMac[amountDevices].specsByModel.display="Admite un monitor hasta 6K y un monitor hasta 4K";
            myDevice.AppleMac[amountDevices].specsByModel.energy_batery="No aplica";
            myDevice.AppleMac[amountDevices].specsByModel.GPU="8 núcleos";
            myDevice.AppleMac[amountDevices].specsByModel.keyboard_trackpad="No aplica";
            myDevice.AppleMac[amountDevices].specsByModel.ports="Dos puertos Thunderbolt/USB 4";
            myDevice.AppleMac[amountDevices].specsByModel.secureAuth="No aplica";
            myDevice.AppleMac[amountDevices].specsByModel.depth=19.7;
            myDevice.AppleMac[amountDevices].specsByModel.height=3.6;
            myDevice.AppleMac[amountDevices].specsByModel.weight=1.2;
            myDevice.AppleMac[amountDevices].specsByModel.width=19.7;
            break;
        case 6:
            myDevice.AppleiPad[amountDevices].model="Mac studio";
            myDevice.AppleMac[amountDevices].specsByModel.camera="No aplica";
            myDevice.AppleMac[amountDevices].specsByModel.chip="Chip M1 Max de Apple o Chip M1 Ultra de Apple";
            myDevice.AppleMac[amountDevices].specsByModel.CPU="20 núcleos";
            myDevice.AppleMac[amountDevices].specsByModel.display="Admite hasta cuatro monitores Pro Display XDR y un monitor 4K";
            myDevice.AppleMac[amountDevices].specsByModel.energy_batery="No aplica";
            myDevice.AppleMac[amountDevices].specsByModel.GPU="64 núcleos";
            myDevice.AppleMac[amountDevices].specsByModel.keyboard_trackpad="No aplica";
            myDevice.AppleMac[amountDevices].specsByModel.ports="Cuatro puertos Thunderbolt 4 (M1 Max); seis puertos Thunderbolt 4 (M1 Ultra)";
            myDevice.AppleMac[amountDevices].specsByModel.secureAuth="No aplica";
            myDevice.AppleMac[amountDevices].specsByModel.depth=19.7;
            myDevice.AppleMac[amountDevices].specsByModel.height=9.5;
            myDevice.AppleMac[amountDevices].specsByModel.weight=3.1;
            myDevice.AppleMac[amountDevices].specsByModel.width=19.7;
            break;
        default:
            cout<<"\nError, modelo de iPad no encontrado\n";
            break;
    }
    return 0;
}
int setAirPodsData(int selectedModel, int amountDevices, Device &myDevice){
    cout<<"\n\t\tID producto: ";
    cin>>myDevice.AppleiPad[amountDevices].id_Device; cin.ignore();
    cout<<"\t\tColor: ";
    getline(cin,myDevice.AppleiPad[amountDevices].color);
    cout<<"\t\tAlmacenamiento [GB]: ";
    cin>>myDevice.AppleiPad[amountDevices].storage; cin.ignore();
    cout<<"\t\tPrecio (USD): ";
    cin>>myDevice.AppleiPad[amountDevices].price; cin.ignore();

    switch(selectedModel){
        case 1:
            myDevice.AppleiPad[amountDevices].model="iPad Pro";
            myDevice.AppleiPad[amountDevices].specsByModel.camera="Cámara gran angular de 12 MP y cámara ultra gran angular de 10 MP";
            myDevice.AppleiPad[amountDevices].specsByModel.chip="Chip M2";
            myDevice.AppleiPad[amountDevices].specsByModel.compatibility="Compatible con Apple Pencil (2da G), Magic Keyboard y Smart Keyboard";
            myDevice.AppleiPad[amountDevices].specsByModel.conector="Conector USB-C compatible con thunderbolt/USB 4";
            myDevice.AppleiPad[amountDevices].specsByModel.display="12.9\" Pantalla Liquid Retina XDR";
            myDevice.AppleiPad[amountDevices].specsByModel.energy_batery="Hasta 10 horas para navegar por Internet a través de Wi-Fi o ver videos";
            myDevice.AppleiPad[amountDevices].specsByModel.secureAuth="Face ID";
            myDevice.AppleiPad[amountDevices].specsByModel.depth=6.4;
            myDevice.AppleiPad[amountDevices].specsByModel.height=280.6;
            myDevice.AppleiPad[amountDevices].specsByModel.weight=682;
            myDevice.AppleiPad[amountDevices].specsByModel.width=214.9;
            break;
        case 2:
            myDevice.AppleiPad[amountDevices].model="iPad Air";
            myDevice.AppleiPad[amountDevices].specsByModel.camera="Cámara gran angular de 12 MP";
            myDevice.AppleiPad[amountDevices].specsByModel.chip="Chip M1";
            myDevice.AppleiPad[amountDevices].specsByModel.compatibility="Compatible con Apple Pencil (2da G), Magic Keyboard y Smart Keyboard";
            myDevice.AppleiPad[amountDevices].specsByModel.conector="Conector USB-C";
            myDevice.AppleiPad[amountDevices].specsByModel.display="10.9\" Pantalla Liquid Retina";
            myDevice.AppleiPad[amountDevices].specsByModel.energy_batery="Hasta 10 horas para navegar por Internet a través de Wi-Fi o ver videos";
            myDevice.AppleiPad[amountDevices].specsByModel.secureAuth="Touch ID";
            myDevice.AppleiPad[amountDevices].specsByModel.depth=6.1;
            myDevice.AppleiPad[amountDevices].specsByModel.height=247.6;
            myDevice.AppleiPad[amountDevices].specsByModel.weight=461;
            myDevice.AppleiPad[amountDevices].specsByModel.width=178.5;
            break;
        case 3:
            myDevice.AppleiPad[amountDevices].model="iPad mini";
            myDevice.AppleiPad[amountDevices].specsByModel.camera="Cámara gran angular de 12 MP";
            myDevice.AppleiPad[amountDevices].specsByModel.chip="Chip A15 Bionic";
            myDevice.AppleiPad[amountDevices].specsByModel.compatibility="Compatible con Apple Pencil (2da G) y Teclados Bluetooth";
            myDevice.AppleiPad[amountDevices].specsByModel.conector="Conector USB-C";
            myDevice.AppleiPad[amountDevices].specsByModel.display="8.3\" Pantalla Liquid Retina";
            myDevice.AppleiPad[amountDevices].specsByModel.energy_batery="Hasta 10 horas para navegar por Internet a través de Wi-Fi o ver videos";
            myDevice.AppleiPad[amountDevices].specsByModel.secureAuth="Touch ID";
            myDevice.AppleiPad[amountDevices].specsByModel.depth=6.3;
            myDevice.AppleiPad[amountDevices].specsByModel.height=195.4;
            myDevice.AppleiPad[amountDevices].specsByModel.weight=293;
            myDevice.AppleiPad[amountDevices].specsByModel.width=134.8;
            break;
        default:
            cout<<"\nError, modelo de iPad no encontrado\n";
            break;
    }
    return 0;
}
int setWatchData(int selectedModel, int amountDevices, Device &myDevice){
    cout<<"\n\t\tID producto: ";
    cin>>myDevice.AppleiPad[amountDevices].id_Device; cin.ignore();
    cout<<"\t\tColor: ";
    getline(cin,myDevice.AppleiPad[amountDevices].color);
    cout<<"\t\tAlmacenamiento [GB]: ";
    cin>>myDevice.AppleiPad[amountDevices].storage; cin.ignore();
    cout<<"\t\tPrecio (USD): ";
    cin>>myDevice.AppleiPad[amountDevices].price; cin.ignore();

    switch(selectedModel){
        case 1:
            myDevice.AppleiPad[amountDevices].model="iPad Pro";
            myDevice.AppleiPad[amountDevices].specsByModel.camera="Cámara gran angular de 12 MP y cámara ultra gran angular de 10 MP";
            myDevice.AppleiPad[amountDevices].specsByModel.chip="Chip M2";
            myDevice.AppleiPad[amountDevices].specsByModel.compatibility="Compatible con Apple Pencil (2da G), Magic Keyboard y Smart Keyboard";
            myDevice.AppleiPad[amountDevices].specsByModel.conector="Conector USB-C compatible con thunderbolt/USB 4";
            myDevice.AppleiPad[amountDevices].specsByModel.display="12.9\" Pantalla Liquid Retina XDR";
            myDevice.AppleiPad[amountDevices].specsByModel.energy_batery="Hasta 10 horas para navegar por Internet a través de Wi-Fi o ver videos";
            myDevice.AppleiPad[amountDevices].specsByModel.secureAuth="Face ID";
            myDevice.AppleiPad[amountDevices].specsByModel.depth=6.4;
            myDevice.AppleiPad[amountDevices].specsByModel.height=280.6;
            myDevice.AppleiPad[amountDevices].specsByModel.weight=682;
            myDevice.AppleiPad[amountDevices].specsByModel.width=214.9;
            break;
        case 2:
            myDevice.AppleiPad[amountDevices].model="iPad Air";
            myDevice.AppleiPad[amountDevices].specsByModel.camera="Cámara gran angular de 12 MP";
            myDevice.AppleiPad[amountDevices].specsByModel.chip="Chip M1";
            myDevice.AppleiPad[amountDevices].specsByModel.compatibility="Compatible con Apple Pencil (2da G), Magic Keyboard y Smart Keyboard";
            myDevice.AppleiPad[amountDevices].specsByModel.conector="Conector USB-C";
            myDevice.AppleiPad[amountDevices].specsByModel.display="10.9\" Pantalla Liquid Retina";
            myDevice.AppleiPad[amountDevices].specsByModel.energy_batery="Hasta 10 horas para navegar por Internet a través de Wi-Fi o ver videos";
            myDevice.AppleiPad[amountDevices].specsByModel.secureAuth="Touch ID";
            myDevice.AppleiPad[amountDevices].specsByModel.depth=6.1;
            myDevice.AppleiPad[amountDevices].specsByModel.height=247.6;
            myDevice.AppleiPad[amountDevices].specsByModel.weight=461;
            myDevice.AppleiPad[amountDevices].specsByModel.width=178.5;
            break;
        case 3:
            myDevice.AppleiPad[amountDevices].model="iPad mini";
            myDevice.AppleiPad[amountDevices].specsByModel.camera="Cámara gran angular de 12 MP";
            myDevice.AppleiPad[amountDevices].specsByModel.chip="Chip A15 Bionic";
            myDevice.AppleiPad[amountDevices].specsByModel.compatibility="Compatible con Apple Pencil (2da G) y Teclados Bluetooth";
            myDevice.AppleiPad[amountDevices].specsByModel.conector="Conector USB-C";
            myDevice.AppleiPad[amountDevices].specsByModel.display="8.3\" Pantalla Liquid Retina";
            myDevice.AppleiPad[amountDevices].specsByModel.energy_batery="Hasta 10 horas para navegar por Internet a través de Wi-Fi o ver videos";
            myDevice.AppleiPad[amountDevices].specsByModel.secureAuth="Touch ID";
            myDevice.AppleiPad[amountDevices].specsByModel.depth=6.3;
            myDevice.AppleiPad[amountDevices].specsByModel.height=195.4;
            myDevice.AppleiPad[amountDevices].specsByModel.weight=293;
            myDevice.AppleiPad[amountDevices].specsByModel.width=134.8;
            break;
        default:
            cout<<"\nError, modelo de iPad no encontrado\n";
            break;
    }
    return 0;
}

int showMenuiPhone(){
    cout<<"\n\t\tModelo del iPhone: \n";
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
int showMenuiPad(){
    cout<<"\n\t\tModelo del iPad: \n";
    cout<<"\t-------------------------------------------------------\n";
    cout<<"  1-. iPad Pro\n";
    cout<<"  2-. iPad Air\n";
    cout<<"  3-. iPad mini\n\n";
    return 0;
}
int showMenuMac(){
    //"MacBook Pro","MacBook Air","iMac","iMac Pro","Mac mini","Mac studio","Mac Pro";
    cout<<"\n\t\tModelo de la Mac: \n";
    cout<<"\t-------------------------------------------------------\n";
    cout<<"  1-. MacBook Pro\n";
    cout<<"  2-. MacBook Air\n";
    cout<<"  3-. iMac\n";
    cout<<"  4-. iMac Pro\n";
    cout<<"  5-. iMac mini\n";
    cout<<"  6-. Mac studio\n\n";
    return 0;
}
int showMenuAirPods(){
    cout<<"\n\t\tModelo de los AirPods: \n";
    cout<<"\t-------------------------------------------------------\n";
    cout<<"  1-. AirPods (2da Generación)\n";
    cout<<"  2-. AirPods (3ra Generación)\n";
    cout<<"  3-. AirPods Pro\n";
    cout<<"  4-. AirPods Max\n";
    return 0;
}
int showMenuWatch(){
    //"","","";
    cout<<"\n\t\tModelo del Apple Watch: \n";
    cout<<"\t-------------------------------------------------------\n";
    cout<<"  1-. Apple Watch Ultra\n";
    cout<<"  2-. Apple Watch Series\n";
    cout<<"  3-. Apple Watch SE\n";
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
            showMenuiPad();
            getMenuOption(selectedModel,1,3);
            setiPadData(selectedModel,amountDevices,myDevice);
            amountDevices++;
            break;
        case 3:
            showMenuMac();
            getMenuOption(selectedModel,1,7);
            setMacData(selectedModel,amountDevices,myDevice);
            amountDevices++;
            break;
        case 4:
            showMenuAirPods();
            getMenuOption(selectedModel,1,4);
            setAirPodsData(selectedModel,amountDevices,myDevice);
            amountDevices++;
            break;
        case 5:
            showMenuWatch();
            getMenuOption(selectedModel,1,3);
            setWatchData(selectedModel,amountDevices,myDevice);
            amountDevices++;
            break;
        default:
            cout<<"\nError, dispositivo no encontrado\n";
            break;
    }
    return 0;
}

int performMainOption(int mainOption, Device &myDevice, int *amountDevices){
    switch(mainOption){
        case 1:
            int selectedDevice;
            showDeviceMenu();
            getMenuOption(selectedDevice,1,5);
            addDeviceOption(selectedDevice,myDevice,amountDevices[selectedDevice-1]);
            break;
        case 2:
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
    cout<<"  8-. Eliminar un registro especifico\n";
    cout<<"  9-. Salir\n\n";
    return 0;
}
