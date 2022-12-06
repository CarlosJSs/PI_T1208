/*
Programa: Base de datos de un hombre (o mujer) pobre
Por Carlos Eduardo López Gutiérrez
*/

#include <iostream>
#include <clocale>
#include <fstream>
#include <cstring>

#define DeviceMAX 100

using namespace std;

//**************************************** Structures *********************************
struct Watch_SpecsByModel{
    string display;
    string resistance;
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
    string independentTime;
    string dependingTime;
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
int showRegistersByDevice(int typeDevice, int *amountDevices, Device myDevice);

int setiPhoneData(int selectedModel, int amountDevices, Device &myDevice);
int setiPadData(int selectedModel, int amountDevices, Device &myDevice);
int setMacData(int selectedModel, int amountDevices, Device &myDevice);
int setAirPodsData(int selectedModel, int amountDevices, Device &myDevice);
int setWatchData(int selectedModel, int amountDevices, Device &myDevice);

int getMenuOption(int &Option, int firstOption, int lastOption);

int performMainOption(int mainOption, Device &myDevice, int *amountDevices);

int addDeviceOption(int selectedDevice, Device &myDevice, int &amountDevices);

int generateFile(string fileName, Device myDevice, int *amountDevices);
int getAllDataFromFile(string fileName, Device &myDevice, int *amountDevices);
int getDataFromLine(string line, string *lineData, int maxAmountData);
int whichTypeDevice(string dataStr);

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

int showRegistersByDevice(int typeDevice, int *amountDevices, Device myDevice){
    switch(typeDevice-1){
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
    for(int k=0;k<amountDevices[typeDevice-1];k++){
            showOneDevice(myDevice,k,typeDevice-1);
    }
    return 0;
}
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
        cout<<"\tModelo: "<<myDevice.AppleMac[numberDevice].model<<endl;
        cout<<"\tColor: "<<myDevice.AppleMac[numberDevice].color<<endl;
        cout<<"\tID: "<<myDevice.AppleMac[numberDevice].id_Device<<endl;
        cout<<"\tAlmacenamiento: "<<myDevice.AppleMac[numberDevice].storage<<endl;
        cout<<"\tMemoria RAM: "<<myDevice.AppleMac[numberDevice].RAM<<endl;
        cout<<"\tPrecio: "<<myDevice.AppleMac[numberDevice].price<<endl;
        cout<<"\tCamara: "<<myDevice.AppleMac[numberDevice].specsByModel.camera<<endl;
        cout<<"\tChip: "<<myDevice.AppleMac[numberDevice].specsByModel.chip<<endl;
        cout<<"\tCPU: "<<myDevice.AppleMac[numberDevice].specsByModel.CPU<<endl;
        cout<<"\tPantalla: "<<myDevice.AppleMac[numberDevice].specsByModel.display<<endl;
        cout<<"\tBateria (Rendimiento): "<<myDevice.AppleMac[numberDevice].specsByModel.energy_batery<<endl;
        cout<<"\tGPU: "<<myDevice.AppleMac[numberDevice].specsByModel.GPU<<endl;
        cout<<"\tCompatibilidad: "<<myDevice.AppleMac[numberDevice].specsByModel.keyboard_trackpad<<endl;
        cout<<"\tPuertos: "<<myDevice.AppleMac[numberDevice].specsByModel.ports<<endl;
        cout<<"\tSeguridad: "<<myDevice.AppleMac[numberDevice].specsByModel.secureAuth<<endl;
        cout<<"\tProfundidad: "<<myDevice.AppleMac[numberDevice].specsByModel.depth<<endl;
        cout<<"\tAlto: "<<myDevice.AppleMac[numberDevice].specsByModel.height<<endl;
        cout<<"\tPeso: "<<myDevice.AppleMac[numberDevice].specsByModel.weight<<endl;
        cout<<"\tAncho: "<<myDevice.AppleMac[numberDevice].specsByModel.width<<endl<<endl;
        break;
    case 3:
        cout<<"\tModelo: "<<myDevice.AppleAirpods[numberDevice].model<<endl;
        cout<<"\tColor: "<<myDevice.AppleAirpods[numberDevice].color<<endl;
        cout<<"\tID: "<<myDevice.AppleAirpods[numberDevice].id_Device<<endl;
        cout<<"\tPrecio: "<<myDevice.AppleAirpods[numberDevice].price<<endl;
        cout<<"\tEstuche de carga: "<<myDevice.AppleAirpods[numberDevice].specsByModel.chargingCase<<endl;
        cout<<"\tChip: "<<myDevice.AppleAirpods[numberDevice].specsByModel.chip<<endl;
        cout<<"\tConectividad: "<<myDevice.AppleAirpods[numberDevice].specsByModel.conectivity<<endl;
        cout<<"\tBateria dependiente: "<<myDevice.AppleAirpods[numberDevice].specsByModel.dependingTime<<endl;
        cout<<"\tPlay mode: "<<myDevice.AppleAirpods[numberDevice].specsByModel.environmentMode<<endl;
        cout<<"\tGestos: "<<myDevice.AppleAirpods[numberDevice].specsByModel.gestures<<endl;
        cout<<"\tBateria independiente: "<<myDevice.AppleAirpods[numberDevice].specsByModel.independentTime<<endl;
        cout<<"\tReducción de ruido: "<<myDevice.AppleAirpods[numberDevice].specsByModel.noiseReduction<<endl;
        cout<<"\tResistencia: "<<myDevice.AppleAirpods[numberDevice].specsByModel.resistance<<endl;
        cout<<"\tSonido espacial: "<<myDevice.AppleAirpods[numberDevice].specsByModel.spaceSound<<endl;
        cout<<"\tGrosor (Airpod): "<<myDevice.AppleAirpods[numberDevice].specsByModel.depth<<endl;
        cout<<"\tAlto (Airpod): "<<myDevice.AppleAirpods[numberDevice].specsByModel.height<<endl;
        cout<<"\tPeso (Airpod): "<<myDevice.AppleAirpods[numberDevice].specsByModel.weight<<endl;
        cout<<"\tAncho (Airpod): "<<myDevice.AppleAirpods[numberDevice].specsByModel.width<<endl;
        cout<<"\tGrosor (Case): "<<myDevice.AppleAirpods[numberDevice].caseSpecs.depth<<endl;
        cout<<"\tAlto (Case): "<<myDevice.AppleAirpods[numberDevice].caseSpecs.height<<endl;
        cout<<"\tPeso (Case): "<<myDevice.AppleAirpods[numberDevice].caseSpecs.weight<<endl;
        cout<<"\tAncho (Case): "<<myDevice.AppleAirpods[numberDevice].caseSpecs.width<<endl<<endl;
        break;
    case 4:
        cout<<"\tModelo: "<<myDevice.AppleWatch[numberDevice].model<<endl;
        cout<<"\tColor: "<<myDevice.AppleWatch[numberDevice].color<<endl;
        cout<<"\tID: "<<myDevice.AppleWatch[numberDevice].id_Device<<endl;
        cout<<"\tPrecio: "<<myDevice.AppleWatch[numberDevice].price<<endl;
        cout<<"\tChip: "<<myDevice.AppleWatch[numberDevice].specsByModel.chip<<endl;
        cout<<"\tPantalla: "<<myDevice.AppleWatch[numberDevice].specsByModel.display<<endl;
        cout<<"\tHerramientas de Emergencia: "<<myDevice.AppleWatch[numberDevice].specsByModel.emergencyTools<<endl;
        cout<<"\tBateria (Rendimiento): "<<myDevice.AppleWatch[numberDevice].specsByModel.energy_batery<<endl;
        cout<<"\tHerramientas de salud: "<<myDevice.AppleWatch[numberDevice].specsByModel.healthTools<<endl;
        cout<<"\tMaterial: "<<myDevice.AppleWatch[numberDevice].specsByModel.material<<endl;
        cout<<"\tResistencia: "<<myDevice.AppleWatch[numberDevice].specsByModel.resistance<<endl<<endl;
        break;
    default:
        cout<<"\nError, dispositivo no encontrado\n";
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
            myDevice.AppleiPhone[amountDevices].specsByModel.display="6.7\" Super Retina XDR";
            myDevice.AppleiPhone[amountDevices].specsByModel.energy_batery="Hasta 29 horas de reproducción de video";
            myDevice.AppleiPhone[amountDevices].specsByModel.resistance="Frente de Ceramic Shield | Resistente al agua | 30 minutos - 6 metros | Acero inoxidable de calidad quirúrgica";
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
            myDevice.AppleiPhone[amountDevices].specsByModel.display="6.1\" Super Retina XDR";
            myDevice.AppleiPhone[amountDevices].specsByModel.energy_batery="Hasta 20 horas de reproducción de video";
            myDevice.AppleiPhone[amountDevices].specsByModel.resistance="Frente de Ceramic Shield | Resistente al agua | 30 minutos - 6 metros | Aluminio de calidad aeroespacial";
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
            myDevice.AppleiPhone[amountDevices].specsByModel.display="6.7\" Super Retina XDR";
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
            myDevice.AppleiPhone[amountDevices].specsByModel.resistance="Frente de Ceramic Shield | Resistente al agua | 30 minutos - 6 metros | Aluminio de calidad aeroespacial";
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
            myDevice.AppleiPhone[amountDevices].specsByModel.resistance="Frente de Ceramic Shield | Resistente al agua | 30 minutos - 6 metros | Acero inoxidable de calidad quirurgica";
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
            myDevice.AppleiPhone[amountDevices].specsByModel.resistance="Frente de Ceramic Shield | Resistente al agua | 30 minutos - 6 metros | Aluminio de calidad aeroespacial";
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
            myDevice.AppleiPhone[amountDevices].specsByModel.resistance="Delantera y posterior de vidrio | Resistente al agua | 30 minutos - 4 metros | Acero inoxidable de calidad quirúrgica";
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
            myDevice.AppleiPhone[amountDevices].specsByModel.resistance="Delantera y posterior de vidrio | Resistente al agua | 30 minutos - 2 metros | Aluminio de calidad aeroespacial";
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
            myDevice.AppleiPhone[amountDevices].specsByModel.resistance="Delantera y posterior de vidrio | Resistente al agua | 30 minutos - 2 metros | Acero inoxidable de calidad quirúrgica";
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
            myDevice.AppleiPhone[amountDevices].specsByModel.resistance="Delantera y posterior de vidrio | Resistente al agua | 30 minutos - 1 metro | Acero inoxidable de calidad quirúrgica";
            myDevice.AppleiPhone[amountDevices].specsByModel.secureAuth="Face ID";
            myDevice.AppleiPhone[amountDevices].specsByModel.depth=7.7;
            myDevice.AppleiPhone[amountDevices].specsByModel.height=143.6;
            myDevice.AppleiPhone[amountDevices].specsByModel.weight=174;
            myDevice.AppleiPhone[amountDevices].specsByModel.width=70.9;
            break;
        default:
            cout<<"\nError modelo de iPhone no encontrado\n";
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
            myDevice.AppleiPad[amountDevices].specsByModel.compatibility="Compatible con Apple Pencil (2da G) | Magic Keyboard | Smart Keyboard";
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
            myDevice.AppleiPad[amountDevices].specsByModel.compatibility="Compatible con Apple Pencil (2da G) | Magic Keyboard | Smart Keyboard";
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
            cout<<"\nError modelo de iPad no encontrado\n";
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
            myDevice.AppleMac[amountDevices].model="MacBook Pro";
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
            myDevice.AppleMac[amountDevices].model="MacBook Air";
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
            myDevice.AppleMac[amountDevices].model="iMac";
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
            myDevice.AppleMac[amountDevices].model="iMac Pro";
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
            myDevice.AppleMac[amountDevices].model="Mac mini";
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
            myDevice.AppleMac[amountDevices].model="Mac studio";
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
            cout<<"\nError modelo de Mac no encontrado\n";
            break;
    }
    return 0;
}
int setAirPodsData(int selectedModel, int amountDevices, Device &myDevice){
    cout<<"\n\t\tID producto: ";
    cin>>myDevice.AppleAirpods[amountDevices].id_Device; cin.ignore();
    cout<<"\t\tColor: ";
    getline(cin,myDevice.AppleAirpods[amountDevices].color);
    cout<<"\t\tPrecio (USD): ";
    cin>>myDevice.AppleAirpods[amountDevices].price; cin.ignore();

    switch(selectedModel){
        case 1:
            myDevice.AppleAirpods[amountDevices].model="AirPods 2da generacion";
            myDevice.AppleAirpods[amountDevices].specsByModel.chargingCase="Estuche de carga Lightning";
            myDevice.AppleAirpods[amountDevices].specsByModel.chip="Chip H1";
            myDevice.AppleAirpods[amountDevices].specsByModel.conectivity="Bluetooth 5.0";
            myDevice.AppleAirpods[amountDevices].specsByModel.dependingTime="Más de 24 horas de audio con el estuche de carga";
            myDevice.AppleAirpods[amountDevices].specsByModel.environmentMode="No aplica";
            myDevice.AppleAirpods[amountDevices].specsByModel.gestures="Doble toque";
            myDevice.AppleAirpods[amountDevices].specsByModel.independentTime="Hasta 5 horas de audio con una sola carga";
            myDevice.AppleAirpods[amountDevices].specsByModel.noiseReduction="No aplica";
            myDevice.AppleAirpods[amountDevices].specsByModel.resistance="No aplica";
            myDevice.AppleAirpods[amountDevices].specsByModel.spaceSound="No aplica";
            myDevice.AppleAirpods[amountDevices].specsByModel.depth=18;
            myDevice.AppleAirpods[amountDevices].specsByModel.height=40.5;
            myDevice.AppleAirpods[amountDevices].specsByModel.weight=4;
            myDevice.AppleAirpods[amountDevices].specsByModel.width=16.5;
            myDevice.AppleAirpods[amountDevices].caseSpecs.depth=21.3;
            myDevice.AppleAirpods[amountDevices].caseSpecs.height=53.5;
            myDevice.AppleAirpods[amountDevices].caseSpecs.weight=38.2;
            myDevice.AppleAirpods[amountDevices].caseSpecs.width=44.3;
            break;
        case 2:
            myDevice.AppleAirpods[amountDevices].model="AirPods 3ra generacion";
            myDevice.AppleAirpods[amountDevices].specsByModel.chargingCase="Estuche de carga MagSafe";
            myDevice.AppleAirpods[amountDevices].specsByModel.chip="Chip H1";
            myDevice.AppleAirpods[amountDevices].specsByModel.conectivity="Bluetooth 5.0";
            myDevice.AppleAirpods[amountDevices].specsByModel.dependingTime="Hasta 30 horas de audio con el estuche de carga";
            myDevice.AppleAirpods[amountDevices].specsByModel.environmentMode="No aplica";
            myDevice.AppleAirpods[amountDevices].specsByModel.gestures="Sensor de fuerza";
            myDevice.AppleAirpods[amountDevices].specsByModel.independentTime="Hasta 6 horas de audio con una sola carga";
            myDevice.AppleAirpods[amountDevices].specsByModel.noiseReduction="No aplica";
            myDevice.AppleAirpods[amountDevices].specsByModel.resistance="Resistentes al agua y al sudor: AirPods y estuche de carga";
            myDevice.AppleAirpods[amountDevices].specsByModel.spaceSound="Audio espacial personalizado con seguimiento dinámico de la cabeza";
            myDevice.AppleAirpods[amountDevices].specsByModel.depth=19.21;
            myDevice.AppleAirpods[amountDevices].specsByModel.height=30.79;
            myDevice.AppleAirpods[amountDevices].specsByModel.weight=4.28;
            myDevice.AppleAirpods[amountDevices].specsByModel.width=18.26;
            myDevice.AppleAirpods[amountDevices].caseSpecs.depth=21.38;
            myDevice.AppleAirpods[amountDevices].caseSpecs.height=46.40;
            myDevice.AppleAirpods[amountDevices].caseSpecs.weight=37.91;
            myDevice.AppleAirpods[amountDevices].caseSpecs.width=54.40;
            break;
        case 3:
            myDevice.AppleAirpods[amountDevices].model="AirPods Pro";
            myDevice.AppleAirpods[amountDevices].specsByModel.chargingCase="Estuche de carga MagSafe con bocina y ojal para correa";
            myDevice.AppleAirpods[amountDevices].specsByModel.chip="Chip H2";
            myDevice.AppleAirpods[amountDevices].specsByModel.conectivity="Bluetooth 5.3";
            myDevice.AppleAirpods[amountDevices].specsByModel.dependingTime="Hasta 30 horas de audio con el estuche de carga";
            myDevice.AppleAirpods[amountDevices].specsByModel.environmentMode="Modo ambiente adaptable";
            myDevice.AppleAirpods[amountDevices].specsByModel.gestures="Control táctil";
            myDevice.AppleAirpods[amountDevices].specsByModel.independentTime="Hasta 6 horas de audio con una sola carga";
            myDevice.AppleAirpods[amountDevices].specsByModel.noiseReduction="Cancelación activa de ruido";
            myDevice.AppleAirpods[amountDevices].specsByModel.resistance="Resistentes al agua y al sudor: AirPods Pro y estuche de carga";
            myDevice.AppleAirpods[amountDevices].specsByModel.spaceSound="Audio espacial personalizado con seguimiento dinámico de la cabeza";
            myDevice.AppleAirpods[amountDevices].specsByModel.depth=24.0;
            myDevice.AppleAirpods[amountDevices].specsByModel.height=30.9;
            myDevice.AppleAirpods[amountDevices].specsByModel.weight=5.3;
            myDevice.AppleAirpods[amountDevices].specsByModel.width=21.8;
            myDevice.AppleAirpods[amountDevices].caseSpecs.depth=21.7;
            myDevice.AppleAirpods[amountDevices].caseSpecs.height=45.2;
            myDevice.AppleAirpods[amountDevices].caseSpecs.weight=50.8;
            myDevice.AppleAirpods[amountDevices].caseSpecs.width=60.6;
            break;
        case 4:
            myDevice.AppleAirpods[amountDevices].model="AirPods Max";
            myDevice.AppleAirpods[amountDevices].specsByModel.chargingCase="Smart Case";
            myDevice.AppleAirpods[amountDevices].specsByModel.chip="Chip H1";
            myDevice.AppleAirpods[amountDevices].specsByModel.conectivity="Bluetooth 5.0";
            myDevice.AppleAirpods[amountDevices].specsByModel.dependingTime="No aplica";
            myDevice.AppleAirpods[amountDevices].specsByModel.environmentMode="Modo ambiente";
            myDevice.AppleAirpods[amountDevices].specsByModel.gestures="No aplica";
            myDevice.AppleAirpods[amountDevices].specsByModel.independentTime="Hasta 20 horas de audio con una sola carga";
            myDevice.AppleAirpods[amountDevices].specsByModel.noiseReduction="Cancelación activa de ruido";
            myDevice.AppleAirpods[amountDevices].specsByModel.resistance="No aplica";
            myDevice.AppleAirpods[amountDevices].specsByModel.spaceSound="Audio espacial personalizado con seguimiento dinámico de la cabeza";
            myDevice.AppleAirpods[amountDevices].specsByModel.depth=83.4;
            myDevice.AppleAirpods[amountDevices].specsByModel.height=187.3;
            myDevice.AppleAirpods[amountDevices].specsByModel.weight=384.8;
            myDevice.AppleAirpods[amountDevices].specsByModel.width=168.6;
            myDevice.AppleAirpods[amountDevices].caseSpecs.depth=0;
            myDevice.AppleAirpods[amountDevices].caseSpecs.height=0;
            myDevice.AppleAirpods[amountDevices].caseSpecs.weight=134.5;
            myDevice.AppleAirpods[amountDevices].caseSpecs.width=0;
            break;
        default:
            cout<<"\nError modelo de AirPods no encontrado\n";
            break;
    }
    return 0;
}
int setWatchData(int selectedModel, int amountDevices, Device &myDevice){
    cout<<"\n\t\tID producto: ";
    cin>>myDevice.AppleWatch[amountDevices].id_Device; cin.ignore();
    cout<<"\t\tColor: ";
    getline(cin,myDevice.AppleWatch[amountDevices].color);
    cout<<"\t\tPrecio (USD): ";
    cin>>myDevice.AppleWatch[amountDevices].price; cin.ignore();

    switch(selectedModel){
        case 1:
            myDevice.AppleWatch[amountDevices].model="AppleWatch Ultra";
            myDevice.AppleWatch[amountDevices].specsByModel.chip="LTE y UMTS";
            myDevice.AppleWatch[amountDevices].specsByModel.display="Pantalla Retina OLED LTPO siempre activa";
            myDevice.AppleWatch[amountDevices].specsByModel.emergencyTools="Detección de caidas | choques | llamada SOS | Sirena";
            myDevice.AppleWatch[amountDevices].specsByModel.energy_batery="Hasta 36 horas | carga rapida";
            myDevice.AppleWatch[amountDevices].specsByModel.healthTools="Oxígeno en sangre | ECG | Frecuencia cardiaca | Temperatura | Control de ciclo";
            myDevice.AppleWatch[amountDevices].specsByModel.material="Titanio";
            myDevice.AppleWatch[amountDevices].specsByModel.resistance="Certificación IP6X de resistencia al polvo | Resistencia al agua 100m";
            break;
        case 2:
            myDevice.AppleWatch[amountDevices].model="AppleWatch Series";
            myDevice.AppleWatch[amountDevices].specsByModel.chip="LTE y UMTS";
            myDevice.AppleWatch[amountDevices].specsByModel.display="Pantalla Retina OLED LTPO siempre activa";
            myDevice.AppleWatch[amountDevices].specsByModel.emergencyTools="Detección de caidas | choques | llamada SOS";
            myDevice.AppleWatch[amountDevices].specsByModel.energy_batery="Hasta 18 horas | carga rapida";
            myDevice.AppleWatch[amountDevices].specsByModel.healthTools="Frecuencia cardiaca | Temperatura | Control de ciclo";
            myDevice.AppleWatch[amountDevices].specsByModel.material="Aluminio | Acero inoxidable";
            myDevice.AppleWatch[amountDevices].specsByModel.resistance="Certificación IP6X de resistencia al polvo | Resistencia al agua 50m";
            break;
        case 3:
            myDevice.AppleWatch[amountDevices].model="AppleWatch SE";
            myDevice.AppleWatch[amountDevices].specsByModel.chip="LTE y UMTS";
            myDevice.AppleWatch[amountDevices].specsByModel.display="Pantalla Retina OLED LTPO";
            myDevice.AppleWatch[amountDevices].specsByModel.emergencyTools="Detección de caidas | choques | llamada SOS";
            myDevice.AppleWatch[amountDevices].specsByModel.energy_batery="Hasta 18 horas";
            myDevice.AppleWatch[amountDevices].specsByModel.healthTools="Frecuencia cardiaca y Control de ciclo";
            myDevice.AppleWatch[amountDevices].specsByModel.material="Aluminio";
            myDevice.AppleWatch[amountDevices].specsByModel.resistance="Resistencia al agua 50m";
            break;
        default:
            cout<<"\nError modelo de AppleWatch no encontrado\n";
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
    cout<<"  4-. AirPods Max\n\n";
    return 0;
}
int showMenuWatch(){
    cout<<"\n\t\tModelo del Apple Watch: \n";
    cout<<"\t-------------------------------------------------------\n";
    cout<<"  1-. Apple Watch Ultra\n";
    cout<<"  2-. Apple Watch Series\n";
    cout<<"  3-. Apple Watch SE\n\n";
    return 0;
}

int whichTypeDevice(string dataStr){
    int typeDevice=0;

    if(dataStr=="iPhone 14 Pro Max" || dataStr=="iPhone 14" || dataStr=="iPhone 13 Pro Max" || dataStr=="iPhone 13" || dataStr=="iPhone 12 Pro Max" || dataStr=="iPhone 12" || dataStr=="iPhone 11 Pro Max" || dataStr=="iPhone 11" || dataStr=="iPhone Xs Max" || dataStr=="iPhone X")
        typeDevice=0;
    if(dataStr=="iPad Pro" || dataStr=="iPad Air" || dataStr=="iPad mini")
        typeDevice=1;
    if(dataStr=="MacBook Pro" || dataStr=="MacBook Air" || dataStr=="iMac" || dataStr=="iMac Pro" || dataStr=="iMac mini" || dataStr=="Mac studio")
        typeDevice=2;
    if(dataStr=="AirPods 2da generacion" || dataStr=="AirPods 3ra generacion" || dataStr=="AirPods Pro" || dataStr=="AirPods Max")
        typeDevice=3;
    if(dataStr=="AppleWatch Ultra" || dataStr=="AppleWatch Series" || dataStr=="AppleWatch SE")
        typeDevice=4;

    return typeDevice;
}

int getDataFromLine(string line, string *lineData, int maxAmountData){
    int amountData=0, MAXDATALINE=10000;

    char typeDevice[MAXDATALINE];
    strcpy(typeDevice,line.c_str());

    char aux[MAXDATALINE];
    int idx=0;

    int k=0;
    while(typeDevice[k++]){
        if(typeDevice[k-1]!=','){

            aux[idx++]=typeDevice[k-1];
        }
        else{
            aux[idx]='\0';
            if(amountData==maxAmountData){
                cout<<"\n\nLos datos en la cadena son mas que la capacidad.";
                return amountData;
            }
            lineData[amountData++]=aux;
            idx=0;
        }
    }
    aux[idx]='\0';
    if(amountData>=maxAmountData){
        cout<<"\n\nLos tokens en la cadena son mas que la capacidad.";
        return amountData;
    }
    lineData[amountData++]=aux;
    return amountData;
}

int getAllDataFromFile(string fileName, Device &myDevice, int *amountDevices){
    int maxAmountData=25;
    string lineData[maxAmountData];

    ifstream myFile(fileName);
    if(!myFile){
        cout<<"\nNo se pudo abrir el archivo para lectura\n";
        return -1;
    }

    string line="";
    while(getline(myFile,line)){
        getDataFromLine(line,lineData,maxAmountData);

        int amountData=0;
        switch(whichTypeDevice(lineData[0])){
        case 0:
            myDevice.AppleiPhone[amountDevices[0]].model=lineData[amountData++];
            myDevice.AppleiPhone[amountDevices[0]].color=lineData[amountData++];
            myDevice.AppleiPhone[amountDevices[0]].id_Device=atoi(lineData[amountData++].c_str());
            myDevice.AppleiPhone[amountDevices[0]].storage=atoi(lineData[amountData++].c_str());
            myDevice.AppleiPhone[amountDevices[0]].price=atof(lineData[amountData++].c_str());
            myDevice.AppleiPhone[amountDevices[0]].specsByModel.camera=lineData[amountData++];
            myDevice.AppleiPhone[amountDevices[0]].specsByModel.chip=lineData[amountData++];
            myDevice.AppleiPhone[amountDevices[0]].specsByModel.conector=lineData[amountData++];
            myDevice.AppleiPhone[amountDevices[0]].specsByModel.display=lineData[amountData++];
            myDevice.AppleiPhone[amountDevices[0]].specsByModel.energy_batery=lineData[amountData++];
            myDevice.AppleiPhone[amountDevices[0]].specsByModel.resistance=lineData[amountData++];
            myDevice.AppleiPhone[amountDevices[0]].specsByModel.secureAuth=lineData[amountData++];
            myDevice.AppleiPhone[amountDevices[0]].specsByModel.depth=atof(lineData[amountData++].c_str());
            myDevice.AppleiPhone[amountDevices[0]].specsByModel.height=atof(lineData[amountData++].c_str());
            myDevice.AppleiPhone[amountDevices[0]].specsByModel.weight=atof(lineData[amountData++].c_str());
            myDevice.AppleiPhone[amountDevices[0]].specsByModel.width=atof(lineData[amountData].c_str());
            break;
        case 1:
            myDevice.AppleiPad[amountDevices[1]].model=lineData[amountData++];
            myDevice.AppleiPad[amountDevices[1]].color=lineData[amountData++];
            myDevice.AppleiPad[amountDevices[1]].id_Device=atoi(lineData[amountData++].c_str());
            myDevice.AppleiPad[amountDevices[1]].storage=atoi(lineData[amountData++].c_str());
            myDevice.AppleiPad[amountDevices[1]].price=atof(lineData[amountData++].c_str());
            myDevice.AppleiPad[amountDevices[1]].specsByModel.camera=lineData[amountData++];
            myDevice.AppleiPad[amountDevices[1]].specsByModel.chip=lineData[amountData++];
            myDevice.AppleiPad[amountDevices[1]].specsByModel.compatibility=lineData[amountData++];
            myDevice.AppleiPad[amountDevices[1]].specsByModel.conector=lineData[amountData++];
            myDevice.AppleiPad[amountDevices[1]].specsByModel.display=lineData[amountData++];
            myDevice.AppleiPad[amountDevices[1]].specsByModel.energy_batery=lineData[amountData++];
            myDevice.AppleiPad[amountDevices[1]].specsByModel.secureAuth=lineData[amountData++];
            myDevice.AppleiPad[amountDevices[1]].specsByModel.depth=atof(lineData[amountData++].c_str());
            myDevice.AppleiPad[amountDevices[1]].specsByModel.height=atof(lineData[amountData++].c_str());
            myDevice.AppleiPad[amountDevices[1]].specsByModel.weight=atof(lineData[amountData++].c_str());
            myDevice.AppleiPad[amountDevices[1]].specsByModel.width=atof(lineData[amountData].c_str());
            break;
        case 2:
            myDevice.AppleMac[amountDevices[2]].model=lineData[amountData++];
            myDevice.AppleMac[amountDevices[2]].color=lineData[amountData++];
            myDevice.AppleMac[amountDevices[2]].id_Device=atoi(lineData[amountData++].c_str());
            myDevice.AppleMac[amountDevices[2]].storage=atoi(lineData[amountData++].c_str());
            myDevice.AppleMac[amountDevices[2]].RAM=atoi(lineData[amountData++].c_str());
            myDevice.AppleMac[amountDevices[2]].price=atof(lineData[amountData++].c_str());
            myDevice.AppleMac[amountDevices[2]].specsByModel.camera=lineData[amountData++];
            myDevice.AppleMac[amountDevices[2]].specsByModel.chip=lineData[amountData++];
            myDevice.AppleMac[amountDevices[2]].specsByModel.CPU=lineData[amountData++];
            myDevice.AppleMac[amountDevices[2]].specsByModel.display=lineData[amountData++];
            myDevice.AppleMac[amountDevices[2]].specsByModel.energy_batery=lineData[amountData++];
            myDevice.AppleMac[amountDevices[2]].specsByModel.GPU=lineData[amountData++];
            myDevice.AppleMac[amountDevices[2]].specsByModel.keyboard_trackpad=lineData[amountData++];
            myDevice.AppleMac[amountDevices[2]].specsByModel.ports=lineData[amountData++];
            myDevice.AppleMac[amountDevices[2]].specsByModel.secureAuth=lineData[amountData++];
            myDevice.AppleMac[amountDevices[2]].specsByModel.depth=atof(lineData[amountData++].c_str());
            myDevice.AppleMac[amountDevices[2]].specsByModel.height=atof(lineData[amountData++].c_str());
            myDevice.AppleMac[amountDevices[2]].specsByModel.weight=atof(lineData[amountData++].c_str());
            myDevice.AppleMac[amountDevices[2]].specsByModel.width=atof(lineData[amountData].c_str());
            break;
        case 3:
            myDevice.AppleAirpods[amountDevices[3]].model=lineData[amountData++];
            myDevice.AppleAirpods[amountDevices[3]].color=lineData[amountData++];
            myDevice.AppleAirpods[amountDevices[3]].id_Device=atoi(lineData[amountData++].c_str());
            myDevice.AppleAirpods[amountDevices[3]].price=atof(lineData[amountData++].c_str());
            myDevice.AppleAirpods[amountDevices[3]].specsByModel.chargingCase=lineData[amountData++];
            myDevice.AppleAirpods[amountDevices[3]].specsByModel.chip=lineData[amountData++];
            myDevice.AppleAirpods[amountDevices[3]].specsByModel.conectivity=lineData[amountData++];
            myDevice.AppleAirpods[amountDevices[3]].specsByModel.dependingTime=lineData[amountData++];
            myDevice.AppleAirpods[amountDevices[3]].specsByModel.environmentMode=lineData[amountData++];
            myDevice.AppleAirpods[amountDevices[3]].specsByModel.gestures=lineData[amountData++];
            myDevice.AppleAirpods[amountDevices[3]].specsByModel.independentTime=lineData[amountData++];
            myDevice.AppleAirpods[amountDevices[3]].specsByModel.noiseReduction=lineData[amountData++];
            myDevice.AppleAirpods[amountDevices[3]].specsByModel.resistance=lineData[amountData++];
            myDevice.AppleAirpods[amountDevices[3]].specsByModel.spaceSound=lineData[amountData++];
            myDevice.AppleAirpods[amountDevices[3]].specsByModel.depth=atof(lineData[amountData++].c_str());
            myDevice.AppleAirpods[amountDevices[3]].specsByModel.height=atof(lineData[amountData++].c_str());
            myDevice.AppleAirpods[amountDevices[3]].specsByModel.weight=atof(lineData[amountData++].c_str());
            myDevice.AppleAirpods[amountDevices[3]].specsByModel.width=atof(lineData[amountData++].c_str());
            myDevice.AppleAirpods[amountDevices[3]].caseSpecs.depth=atof(lineData[amountData++].c_str());
            myDevice.AppleAirpods[amountDevices[3]].caseSpecs.height=atof(lineData[amountData++].c_str());
            myDevice.AppleAirpods[amountDevices[3]].caseSpecs.weight=atof(lineData[amountData++].c_str());
            myDevice.AppleAirpods[amountDevices[3]].caseSpecs.width=atof(lineData[amountData].c_str());
            break;
        case 4:
            myDevice.AppleWatch[amountDevices[4]].model=lineData[amountData++];
            myDevice.AppleWatch[amountDevices[4]].color=lineData[amountData++];
            myDevice.AppleWatch[amountDevices[4]].id_Device=atoi(lineData[amountData++].c_str());
            myDevice.AppleWatch[amountDevices[4]].price=atof(lineData[amountData++].c_str());
            myDevice.AppleWatch[amountDevices[4]].specsByModel.chip=lineData[amountData++];
            myDevice.AppleWatch[amountDevices[4]].specsByModel.display=lineData[amountData++];
            myDevice.AppleWatch[amountDevices[4]].specsByModel.emergencyTools=lineData[amountData++];
            myDevice.AppleWatch[amountDevices[4]].specsByModel.energy_batery=lineData[amountData++];
            myDevice.AppleWatch[amountDevices[4]].specsByModel.healthTools=lineData[amountData++];
            myDevice.AppleWatch[amountDevices[4]].specsByModel.material=lineData[amountData++];
            myDevice.AppleWatch[amountDevices[4]].specsByModel.resistance=lineData[amountData];
            break;
        default:
            cout<<"\nError al definir el tipo de dispositivo\n";
            break;
        }
        amountDevices[whichTypeDevice(lineData[0])]++;
    }

    myFile.close();
    return 0;
}
int generateFile(string fileName, Device myDevice, int *amountDevices){
    ofstream myFile(fileName);
    if(!myFile){
        cout<<"\nNo se pudo abrir el archivo \""<<fileName<<"\" para escritura.\n";
        return -1;
    }

    for(int k=0;k<5;k++){
        for(int l=0;l<amountDevices[k];l++){
            switch(k){
            case 0:
                myFile<<myDevice.AppleiPhone[l].model
                <<","<<myDevice.AppleiPhone[l].color
                <<","<<myDevice.AppleiPhone[l].id_Device
                <<","<<myDevice.AppleiPhone[l].storage
                <<","<<myDevice.AppleiPhone[l].price
                <<","<<myDevice.AppleiPhone[l].specsByModel.camera
                <<","<<myDevice.AppleiPhone[l].specsByModel.chip
                <<","<<myDevice.AppleiPhone[l].specsByModel.conector
                <<","<<myDevice.AppleiPhone[l].specsByModel.display
                <<","<<myDevice.AppleiPhone[l].specsByModel.energy_batery
                <<","<<myDevice.AppleiPhone[l].specsByModel.resistance
                <<","<<myDevice.AppleiPhone[l].specsByModel.secureAuth
                <<","<<myDevice.AppleiPhone[l].specsByModel.depth
                <<","<<myDevice.AppleiPhone[l].specsByModel.height
                <<","<<myDevice.AppleiPhone[l].specsByModel.weight
                <<","<<myDevice.AppleiPhone[l].specsByModel.width<<endl;
                break;
            case 1:
                myFile<<myDevice.AppleiPad[l].model
                <<","<<myDevice.AppleiPad[l].color
                <<","<<myDevice.AppleiPad[l].id_Device
                <<","<<myDevice.AppleiPad[l].storage
                <<","<<myDevice.AppleiPad[l].price
                <<","<<myDevice.AppleiPad[l].specsByModel.camera
                <<","<<myDevice.AppleiPad[l].specsByModel.chip
                <<","<<myDevice.AppleiPad[l].specsByModel.compatibility
                <<","<<myDevice.AppleiPad[l].specsByModel.conector
                <<","<<myDevice.AppleiPad[l].specsByModel.display
                <<","<<myDevice.AppleiPad[l].specsByModel.energy_batery
                <<","<<myDevice.AppleiPad[l].specsByModel.secureAuth
                <<","<<myDevice.AppleiPad[l].specsByModel.depth
                <<","<<myDevice.AppleiPad[l].specsByModel.height
                <<","<<myDevice.AppleiPad[l].specsByModel.weight
                <<","<<myDevice.AppleiPad[l].specsByModel.width<<endl;
                break;
            case 2:
                myFile<<myDevice.AppleMac[l].model
                <<","<<myDevice.AppleMac[l].color
                <<","<<myDevice.AppleMac[l].id_Device
                <<","<<myDevice.AppleMac[l].storage
                <<","<<myDevice.AppleMac[l].RAM
                <<","<<myDevice.AppleMac[l].price
                <<","<<myDevice.AppleMac[l].specsByModel.camera
                <<","<<myDevice.AppleMac[l].specsByModel.chip
                <<","<<myDevice.AppleMac[l].specsByModel.CPU
                <<","<<myDevice.AppleMac[l].specsByModel.display
                <<","<<myDevice.AppleMac[l].specsByModel.energy_batery
                <<","<<myDevice.AppleMac[l].specsByModel.GPU
                <<","<<myDevice.AppleMac[l].specsByModel.keyboard_trackpad
                <<","<<myDevice.AppleMac[l].specsByModel.ports
                <<","<<myDevice.AppleMac[l].specsByModel.secureAuth
                <<","<<myDevice.AppleMac[l].specsByModel.depth
                <<","<<myDevice.AppleMac[l].specsByModel.height
                <<","<<myDevice.AppleMac[l].specsByModel.weight
                <<","<<myDevice.AppleMac[l].specsByModel.width<<endl;
                break;
            case 3:
                myFile<<myDevice.AppleAirpods[l].model
                <<","<<myDevice.AppleAirpods[l].color
                <<","<<myDevice.AppleAirpods[l].id_Device
                <<","<<myDevice.AppleAirpods[l].price
                <<","<<myDevice.AppleAirpods[l].specsByModel.chargingCase
                <<","<<myDevice.AppleAirpods[l].specsByModel.chip
                <<","<<myDevice.AppleAirpods[l].specsByModel.conectivity
                <<","<<myDevice.AppleAirpods[l].specsByModel.dependingTime
                <<","<<myDevice.AppleAirpods[l].specsByModel.environmentMode
                <<","<<myDevice.AppleAirpods[l].specsByModel.gestures
                <<","<<myDevice.AppleAirpods[l].specsByModel.independentTime
                <<","<<myDevice.AppleAirpods[l].specsByModel.noiseReduction
                <<","<<myDevice.AppleAirpods[l].specsByModel.resistance
                <<","<<myDevice.AppleAirpods[l].specsByModel.spaceSound
                <<","<<myDevice.AppleAirpods[l].specsByModel.depth
                <<","<<myDevice.AppleAirpods[l].specsByModel.height
                <<","<<myDevice.AppleAirpods[l].specsByModel.weight
                <<","<<myDevice.AppleAirpods[l].specsByModel.width
                <<","<<myDevice.AppleAirpods[l].caseSpecs.depth
                <<","<<myDevice.AppleAirpods[l].caseSpecs.height
                <<","<<myDevice.AppleAirpods[l].caseSpecs.weight
                <<","<<myDevice.AppleAirpods[l].caseSpecs.width<<endl;
                break;
            case 4:
                myFile<<myDevice.AppleWatch[l].model
                <<","<<myDevice.AppleWatch[l].color
                <<","<<myDevice.AppleWatch[l].id_Device
                <<","<<myDevice.AppleWatch[l].price
                <<","<<myDevice.AppleWatch[l].specsByModel.chip
                <<","<<myDevice.AppleWatch[l].specsByModel.display
                <<","<<myDevice.AppleWatch[l].specsByModel.emergencyTools
                <<","<<myDevice.AppleWatch[l].specsByModel.energy_batery
                <<","<<myDevice.AppleWatch[l].specsByModel.healthTools
                <<","<<myDevice.AppleWatch[l].specsByModel.material
                <<","<<myDevice.AppleWatch[l].specsByModel.resistance<<endl;
                break;
            default:
                myFile<<"Error, No se encontro el registro o tipo de dispositivo"<<endl;
                break;
            }
        }
    }

    myFile.close();
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
            int selectedDeviceFilter;
            showDeviceMenu();
            getMenuOption(selectedDeviceFilter,1,5);
            showRegistersByDevice(selectedDeviceFilter,amountDevices,myDevice);
            break;
        case 4:
            generateFile("misRegistros.csv",myDevice,amountDevices);
            break;
        case 5:
            getAllDataFromFile("tusRegistros.csv",myDevice,amountDevices);
            break;
        case 6:
            cout<<"la 6";
            break;
        case 7:
            cout<<"la 7";
            break;
        case 8:
            cout<<"la 8";
            break;
        case 9:
            cout<<"la 9";
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
