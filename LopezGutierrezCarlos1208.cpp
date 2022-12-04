/*
Programa: Base de datos de un hombre pobre
Por Carlos Eduardo López Gutiérrez
*/

#include <iostream>
#include <clocale>

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
    float weight;string display;
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
};
struct Mac{
    float price;
    int storage;
    string model;
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
    iPhone AppleiPhone;
    iPad AppleiPad;
    Mac AppleMac;
    AirPods AppleAirpods;
    Watch AppleWatch;
};

//**************************************** Prototypes **********************************
int showMainMenu();
int getMenuOption(int &Option, int firstOption, int lastOption);
int performMainOption(int mainOption);
int showDeviceMenu();


int main(void){
    system("COLOR F1");
    setlocale(LC_CTYPE, "spanish");
    // ************************************ Code ***************************************

    cout<<"\n\t\tBase de Datos de un Hombre Pobre\n\n";

    int menuSelectedOption;

    showMainMenu();
    getMenuOption(menuSelectedOption,1,8);
    performMainOption(menuSelectedOption);

    // ********************************** Footer ****************************************
    cout << "\n\n\n\nPara salir, presiona la tecla 'Enter'";
    cin.get();
}

//***************************************** Functions ***********************************

int addDevice(){
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
int performMainOption(int mainOption){
    switch(mainOption){
        case 1:
            int selectedDevice;
            showDeviceMenu();
            getMenuOption(selectedDevice,1,5);

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
