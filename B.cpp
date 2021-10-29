
/*
B10. Doti trīs naturāli skaitļi, kas nosaka datumu, mēnesi un gadu. Atrast, kādā nedēļas dienā ir dotais datums,
izmantojot šim nolūkam speciālu funkciju. (pēc Gregora kalendāra garie gadi ir tie,
kuri dalās ar 4, izņemot tos, kuri dalās ar 100 un nedalās ar 400. Mūsu ēras 1. gada 1. janvāris bija pirmdiena).
Risinājumā izmantot funkciju, kas atpazīst garos gadus.
*/
#include <iostream>
using namespace std;

bool garsyyyy(int yyyy){ //funkcija parbauda vai ievaditais gads ir garais gads

    if(yyyy % 4 == 0)
        if(yyyy % 100 == 0 && yyyy % 400 != 0)
            return false;
        else
            return true;
    else
        return false;

}

int nedelasdiena(int dd, int mm,int yyyy){ //funkcija nosaka nedelas dienu

    int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 }; //lai izmantotu matematisko formulu, sie ir visi 12 menesi bet ar specialu novirzi

    yyyy -= mm < 3; //tiek izveidota

    return ( yyyy + yyyy / 4 - yyyy / 100 + yyyy / 400 + t[mm - 1] + dd) % 7; //matematiska formula ieguta no interneta
}

int main(){
    int dd, mm, yyyy;
    bool turpinat=true;
    while(turpinat==true){ //atkartosanas funkcija

    cout<<"Ievadi dienu"<<endl; //tiek ievaditi nepieciesamie paramtetri

    cin>>dd;
        if (dd>31 || dd<1) {
            cout<<"nepareizs datums"<<endl;
            cin>>dd;
        }

    cout<<"Ievadi menesi"<<endl;
    cin>>mm;
        if (mm>12 || mm<1){
            cout<<"nepareizs menesis"<<endl;
            cin>>mm;
        }

    cout<<"ievadi gadu"<<endl;
    cin>>yyyy;
        if(yyyy<0){
            cout<<"nepareizs gads"<<endl;
            cin>>yyyy;
        }

    int new_dd = nedelasdiena(dd,mm,yyyy); //tiek saukta funkcija

        string diena[] = { //izmantojot masivu tiek izdrukata nedelas dienas nosaukums
            "Svetdiena",
            "Pirmdiena",
            "Otrdiena",
            "Tresdiena",
            "Ceturtdiena",
            "Piektdiena",
            "Sestdiena"
        };

        cout<<diena[new_dd]<<endl;

    int garsgads=garsyyyy(yyyy);

    if (garsgads==0) //tiek izsaukta gada garuma noteiksanas funkcija
        cout<<"Isais gads"<<endl;
    else
        cout<<"Garais gads"<<endl;

    cout<<"Velaties atkartot? 1 / 0 "<<endl; //atkartosanas pieprasijums
    cin>>turpinat;
    }
}
