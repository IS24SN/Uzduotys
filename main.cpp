#include <iostream>
#include <windows.h>
#include <string>
#include <cstdlib> // reikalinga rand() ir srand()
#include <ctime>   // reikalinga time()
#include <vector>  // keliems skaičiams saugoti
#include <fstream> // reikalinga darbui su failais
#include <algorithm> // reikalinga sort()
#include <functional> // dėl std::function
#include <limits>

using namespace std;

// 1. Kiek skaičių dalinasi iš septynių
int countDivisibleBy7(int N) {
    return N / 7;
}

void vykdytiCountDivisibleBy7() {
    int N;
    cout << "Įvesti skaičių N: ";
    cin >> N;

    while (N < 1) {
        cout << "N turi būti mažiausiai 1. Bandykite dar kartą: ";
        cin >> N;
    }

    int count = countDivisibleBy7(N);
    cout << "Skaičiai dalinami iš 7 tarp 1 ir " << N << ": " << count << '\n';
}

// 2. Rasti didžiausią ir mažiausią skaičius
void rastiDidziausiaIrMaziausia() {
    int a, b, c;
    cout << "Įveskite tris skaičius: ";
    cin >> a >> b >> c;

    int didziausias = a;
    int maziausias = a;

    if (b > didziausias) didziausias = b;
    if (c > didziausias) didziausias = c;

    if (b < maziausias) maziausias = b;
    if (c < maziausias) maziausias = c;

    cout << "Mažiausias skaičius: " << maziausias << '\n';
    cout << "Didžiausias skaičius: " << didziausias << '\n';
}

// 3. Konvertuoti centimetrus į metrus
void cmToMeters() {
    double cm;
    cout << "Įveskite ilgį centimetrais: ";
    cin >> cm;

    double meters = cm / 100.0;
    cout << "Ilgis metrais: " << meters << " m\n";
}

// 4. Konvertuoti metrus į centimetrus
void metersToCm() {
    double meters;
    cout << "Įveskite ilgį metrais: ";
    cin >> meters;

    double cm = meters * 100.0;
    cout << "Ilgis centimetrais: " << cm << " cm\n";
}

// 5. Skaičiuotuvas
void skaiciuotuvas() {
    double skaicius1, skaicius2;
    int veiksmas;

    cout << "Įveskite pirmą skaičių: ";
    cin >> skaicius1;
    cout << "Įveskite antrą skaičių: ";
    cin >> skaicius2;

    cout << "\nPasirinkite veiksmą:\n";
    cout << "1. Sudėtis\n";
    cout << "2. Atimtis\n";
    cout << "3. Daugyba\n";
    cout << "4. Dalyba\n";
    cout << "Pasirinkite: ";
    cin >> veiksmas;

    switch (veiksmas) {
        case 1:
            cout << "Rezultatas: " << (skaicius1 + skaicius2) << '\n';
            break;
        case 2:
            cout << "Rezultatas: " << (skaicius1 - skaicius2) << '\n';
            break;
        case 3:
            cout << "Rezultatas: " << (skaicius1 * skaicius2) << '\n';
            break;
        case 4:
            if (skaicius2 != 0)
                cout << "Rezultatas: " << (skaicius1 / skaicius2) << '\n';
            else
                cout << "Klaida: dalyba iš nulio negalima!\n";
            break;
        default:
            cout << "Neteisingas veiksmo pasirinkimas.\n";
            break;
    }
}

// 6. Tikrinti ar skaičius lyginis ar nelyginis
void tikrintiLygini() {
    int skaicius;
    cout << "Įveskite skaičių: ";
    cin >> skaicius;

    if (skaicius % 2 == 0) {
        cout << "Skaičius yra lyginis.\n";
    } else {
        cout << "Skaičius yra nelyginis.\n";
    }
}

// 7. Spausdinti daugybos lentelę nuo 1 iki N
void daugybosLentele() {
    int N;
    cout << "Įveskite N (iki kokio skaičiaus spausdinti daugybos lentelę): ";
    cin >> N;

    if (N < 1) {
        cout << "N turi būti bent 1.\n";
        return;
    }

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= 10; ++j) {
            cout << i << " x " << j << " = " << (i * j) << '\t';
        }
        cout << '\n';
    }
}

// 8. Rasti visus pirminius skaičius nuo 1 iki N
void rastiPirminius() {
    int N;
    cout << "Įveskite N (iki kokio skaičiaus ieškoti pirminių skaičių): ";
    cin >> N;

    if (N < 2) {
        cout << "N turi būti bent 2, nes 1 nėra pirminis skaičius.\n";
        return;
    }

    cout << "Pirminiai skaičiai nuo 1 iki " << N << " yra:\n";

    for (int i = 2; i <= N; ++i) {
        bool pirminis = true;
        for (int j = 2; j * j <= i; ++j) {
            if (i % j == 0) {
                pirminis = false;
                break;
            }
        }
        if (pirminis) {
            cout << i << " ";
        }
    }
    cout << '\n';
}

// 9. Konvertuoti valandas į minutes ir sekundes
void konvertuotiValandas() {
    int valandos;
    cout << "Įveskite valandų skaičių: ";
    cin >> valandos;

    if (valandos < 0) {
        cout << "Valandų skaičius negali būti neigiamas.\n";
        return;
    }

    int minutes = valandos * 60;
    int sekundes = valandos * 3600;

    cout << valandos << " val. yra " << minutes << " min. ir " << sekundes << " sek.\n";
}

// 10. Skaičiuoti balsius ir priebalsius
void skaiciuotiBalsiusIrPriebalsius() {
    string tekstas;
    cout << "Įveskite žodį arba sakinį: ";
    cin.ignore(); // kad sugertų likusį '\n'
    getline(cin, tekstas);

    int balsiai = 0, priebalsiai = 0;

    string balsiuRaides = "aąeęėiįyouųūAĄEĘĖIĮYOUŲŪ";

    for (char raide : tekstas) {
        if (isalpha(raide)) {
            if (balsiuRaides.find(raide) != string::npos) {
                balsiai++;
            } else {
                priebalsiai++;
            }
        }
    }

    cout << "Balsių: " << balsiai << '\n';
    cout << "Priebalsių: " << priebalsiai << '\n';
}

// 11. Generuoti masyvą ir skaičiuoti vidurkį
void generuotiMasyvaIrSkaiciuotiVidurki() {
    const int dydis = 10; // nustatome masyvo dydį
    int masyvas[dydis];

    srand(time(0)); // inicializuojam atsitiktinių skaičių generatorių

    cout << "Sugeneruoti atsitiktiniai skaičiai:\n";

    for (int i = 0; i < dydis; ++i) {
        masyvas[i] = rand() % 100 + 1; // skaičiai nuo 1 iki 100
        cout << masyvas[i] << " ";
    }
    cout << '\n';

    // Skaičiuojam vidurkį
    int suma = 0;
    for (int i = 0; i < dydis; ++i) {
        suma += masyvas[i];
    }

    double vidurkis = static_cast<double>(suma) / dydis;
    cout << "Vidurkis: " << vidurkis << '\n';
}

// 12. Daugiausiai pasikartojantis skaičius masyve
void rastiDazniausiusSkaicius() {
    const int dydis = 20;
    int masyvas[dydis];

    srand(time(0));

    cout << "Sugeneruoti skaičiai:\n";
    for (int i = 0; i < dydis; ++i) {
        masyvas[i] = rand() % 10 + 1; // skaičiai nuo 1 iki 10
        cout << masyvas[i] << " ";
    }
    cout << "\n";

    // Skaičiuojama, kiek kartų pasikartoja kiekvienas skaičius
    int kiekKartu[11] = {0}; // nuo 0 iki 10

    for (int i = 0; i < dydis; ++i) {
        kiekKartu[masyvas[i]]++;
    }

    // Randamas maksimalus pasikartojimų skaičius
    int maxPasikartojimai = 0;
    for (int i = 1; i <= 10; ++i) {
        if (kiekKartu[i] > maxPasikartojimai) {
            maxPasikartojimai = kiekKartu[i];
        }
    }

    // Surenkami visi skaičiai, kurie pasikartojo maksimalų kartų skaičių
    vector<int> dazniausiSkaiciai;

    for (int i = 1; i <= 10; ++i) {
        if (kiekKartu[i] == maxPasikartojimai) {
            dazniausiSkaiciai.push_back(i);
        }
    }

    // Išvedamas rezultatas
    cout << "Dažniausiai pasikartojantys skaičiai (po " << maxPasikartojimai << " kartus): ";
    for (int skaicius : dazniausiSkaiciai) {
        cout << skaicius << " ";
    }
    cout << '\n';
}

// 13. Apskaičiuoti matricos determinantą (2x2 arba 3x3)
void skaiciuotiDeterminanta() {
    int dydis;
    cout << "Pasirinkite matricos dydį (2 arba 3): ";
    cin >> dydis;

    if (dydis == 2) {
        int matrica[2][2];
        cout << "Įveskite 2x2 matricos elementus:\n";
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                cout << "M[" << i << "][" << j << "] = ";
                cin >> matrica[i][j];
            }
        }
        int determinant = matrica[0][0] * matrica[1][1] - matrica[0][1] * matrica[1][0];
        cout << "2x2 matricos determinantas: " << determinant << '\n';

    } else if (dydis == 3) {
        int matrica[3][3];
        cout << "Įveskite 3x3 matricos elementus:\n";
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                cout << "M[" << i << "][" << j << "] = ";
                cin >> matrica[i][j];
            }
        }
        int determinant =
            matrica[0][0] * (matrica[1][1] * matrica[2][2] - matrica[1][2] * matrica[2][1]) -
            matrica[0][1] * (matrica[1][0] * matrica[2][2] - matrica[1][2] * matrica[2][0]) +
            matrica[0][2] * (matrica[1][0] * matrica[2][1] - matrica[1][1] * matrica[2][0]);
        cout << "3x3 matricos determinantas: " << determinant << '\n';

    } else {
        cout << "Neteisingas dydis. Galima pasirinkti tik 2 arba 3.\n";
    }
}

// 14. Apskaičiuoti dviejų skaičių didžiausią bendrą daliklį (DBD)
int skaiciuotiDBD(int a, int b) {
    while (b != 0) {
        int laikinas = b;
        b = a % b;
        a = laikinas;
    }
    return a;
}

void vykdytiDBDSkaiciavima() {
    int skaicius1, skaicius2;
    cout << "Įveskite pirmą skaičių: ";
    cin >> skaicius1;
    cout << "Įveskite antrą skaičių: ";
    cin >> skaicius2;

    int dbd = skaiciuotiDBD(skaicius1, skaicius2);
    cout << "Didžiausias bendras daliklis (DBD) yra: " << dbd << '\n';
}

// 15. Rasti n-tojo Fibonačio skaičiaus reikšmę
int fibonaci(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;

    int pirmas = 0, antras = 1, sekantis;
    for (int i = 2; i <= n; ++i) {
        sekantis = pirmas + antras;
        pirmas = antras;
        antras = sekantis;
    }
    return antras;
}

void vykdytiFibonaciSkaiciavima() {
    int n;
    cout << "Įveskite n (kelintas Fibonačio skaičius jus domina): ";
    cin >> n;

    if (n < 0) {
        cout << "n turi būti teigiamas skaičius.\n";
        return;
    }

    int rezultatas = fibonaci(n);
    cout << n << "-asis Fibonačio skaičius yra: " << rezultatas << '\n';
}

// 16. Konvertuoti temperatūrą tarp Celsijaus ir Farenheito
void konvertuotiTemperatura() {
    int pasirinkimas;
    cout << "Pasirinkite:\n";
    cout << "1. Celsijus -> Farenheitas\n";
    cout << "2. Farenheitas -> Celsijus\n";
    cout << "Pasirinkite: ";
    cin >> pasirinkimas;

    if (pasirinkimas == 1) {
        double celsijus;
        cout << "Įveskite temperatūrą Celsijumi: ";
        cin >> celsijus;

        double farenheitas = (celsijus * 9.0 / 5.0) + 32;
        cout << celsijus << "°C = " << farenheitas << "°F\n";
    }
    else if (pasirinkimas == 2) {
        double farenheitas;
        cout << "Įveskite temperatūrą Farenheitu: ";
        cin >> farenheitas;

        double celsijus = (farenheitas - 32) * 5.0 / 9.0;
        cout << farenheitas << "°F = " << celsijus << "°C\n";
    }
    else {
        cout << "Neteisingas pasirinkimas.\n";
    }
}

// 17. Rekursyviai konvertuoti dešimtainį skaičių į dvejetainį
void konvertuotiDesimtainiIDvejetaini(int skaicius) {
    if (skaicius > 1) {
        konvertuotiDesimtainiIDvejetaini(skaicius / 2); // kviečiame save rekursyviai
    }
    cout << (skaicius % 2);
}

void vykdytiDesimtainioKonvertavima() {
    int skaicius;
    cout << "Įveskite dešimtainį skaičių: ";
    cin >> skaicius;

    if (skaicius < 0) {
        cout << "Prašome įvesti teigiamą skaičių.\n";
        return;
    }

    cout << "Skaičius dvejetainiu formatu: ";
    if (skaicius == 0) {
        cout << "0"; // atskirai atvaizduojam 0
    } else {
        konvertuotiDesimtainiIDvejetaini(skaicius);
    }
    cout << '\n';
}

// 18. Rekursyviai apskaičiuoti sumą nuo 1 iki N
int sumaIkiN(int n) {
    if (n <= 1) {
        return n; // Bazinis atvejis: jei n yra 1 arba 0, grąžinam patį n
    } else {
        return n + sumaIkiN(n - 1); // Rekursyvus atvejis: n + suma iki (n-1)
    }
}

void vykdytiSumaIkiN() {
    int n;
    cout << "Įveskite skaičių N: ";
    cin >> n;

    if (n < 0) {
        cout << "Skaičius turi būti teigiamas arba nulis.\n";
        return;
    }

    int suma = sumaIkiN(n);
    cout << "Suma nuo 1 iki " << n << " yra: " << suma << '\n';
}

// 19. Įrašyti studentus į failą ir juos nuskaityti
void irasytiIrNuskaitytiStudentus() {
    int kiek;
    cout << "Kiek studentų norite įvesti? ";
    cin >> kiek;

    ofstream out("studentai.txt"); // sukuriam (arba perrašom) failą rašymui

    if (!out) {
        cout << "Klaida atidarant failą rašymui!\n";
        return;
    }

    for (int i = 0; i < kiek; ++i) {
        string vardas;
        int pazymys;

        cout << "Įveskite " << i + 1 << "-ojo studento vardą: ";
        cin >> vardas;
        cout << "Įveskite " << vardas << " pažymį: ";
        cin >> pazymys;

        out << vardas << " " << pazymys << endl;
    }
    out.close(); // svarbu uždaryti!

    cout << "\nStudentų duomenys įrašyti į failą. Dabar nuskaitome:\n";

    ifstream in("studentai.txt");

    if (!in) {
        cout << "Klaida atidarant failą skaitymui!\n";
        return;
    }

    string vardas;
    int pazymys;

    while (in >> vardas >> pazymys) {
        cout << "Studentas: " << vardas << ", pažymys: " << pazymys << '\n';
    }

    in.close();
}

// 20. Suskaičiuoti žodžių skaičių faile
void skaiciuotiZodziusFaile() {
    string failoPavadinimas;
    cout << "Įveskite failo pavadinimą (pvz., studentai.txt): ";
    cin >> failoPavadinimas;

    ifstream failas(failoPavadinimas);

    if (!failas) {
        cout << "Klaida: nepavyko atidaryti failo!\n";
        return;
    }

    string zodis;
    int zodziuKiekis = 0;

    cout << "\nFailo žodžiai:\n";

    while (failas >> zodis) {
        cout << zodis << '\n'; // Išvedam kiekvieną žodį naujoje eilutėje
        zodziuKiekis++;
    }

    failas.close();

    cout << "\nIš viso žodžių faile: " << zodziuKiekis << '\n';
}

// 21. Struktūra Automobilis
struct Automobilis {
    string marke;
    string modelis;
    int metai;
    double kaina;
};

// Funkcija automobilio duomenų įvedimui
void ivestiAutomobili(Automobilis &autoObj) {
    cout << "Įveskite markę: ";
    cin >> autoObj.marke;
    cout << "Įveskite modelį: ";
    cin >> autoObj.modelis;
    cout << "Įveskite gamybos metus: ";
    cin >> autoObj.metai;
    cout << "Įveskite kainą: ";
    cin >> autoObj.kaina;
}

// Funkcija automobilių atvaizdavimui
void atvaizduotiAutomobili(const Automobilis &autoObj) {
    cout << autoObj.marke << " " << autoObj.modelis << ", "
         << autoObj.metai << " m., " << autoObj.kaina << " €\n";
}

// Pagrindinė funkcija
void valdytiAutomobilius() {
    const int kiekis = 5;
    Automobilis automobiliai[kiekis];

    // Įvedimas
    cout << "Įveskite informaciją apie 5 automobilius:\n";
    for (int i = 0; i < kiekis; ++i) {
        cout << "\nAutomobilis #" << i + 1 << ":\n";
        ivestiAutomobili(automobiliai[i]);
    }

    // Rikiavimas pagal kainą
    sort(automobiliai, automobiliai + kiekis, [](const Automobilis &a, const Automobilis &b) {
        return a.kaina < b.kaina; // rikiuojam didėjimo tvarka pagal kainą
    });

    // Atvaizdavimas
    cout << "\nAutomobiliai surikiuoti pagal kainą:\n";
    for (int i = 0; i < kiekis; ++i) {
        atvaizduotiAutomobili(automobiliai[i]);
    }
}

// 22. Įvesti darbuotojus ir rasti turintį/čius didžiausią atlyginimą
struct Darbuotojas {
    string vardas;
    string pavarde;
    double atlyginimas;
};

// Funkcija įvesti darbuotoją
void ivestiDarbuotoja(Darbuotojas &darb) {
    cout << "Įveskite vardą: ";
    cin >> darb.vardas;
    cout << "Įveskite pavardę: ";
    cin >> darb.pavarde;
    cout << "Įveskite atlyginimą: ";
    cin >> darb.atlyginimas;
}

// Funkcija rasti visus darbuotojus su didžiausiu atlyginimu
void rastiDidziausiusAtlyginimus() {
    const int kiek = 5;
    Darbuotojas darbuotojai[kiek];

    cout << "Įveskite informaciją apie 5 darbuotojus:\n";
    for (int i = 0; i < kiek; ++i) {
        cout << "\nDarbuotojas #" << i + 1 << ":\n";
        ivestiDarbuotoja(darbuotojai[i]);
    }

    // Pirmas žingsnis: randam didžiausią atlyginimą
    double didziausiasAtlyginimas = darbuotojai[0].atlyginimas;
    for (int i = 1; i < kiek; ++i) {
        if (darbuotojai[i].atlyginimas > didziausiasAtlyginimas) {
            didziausiasAtlyginimas = darbuotojai[i].atlyginimas;
        }
    }

    // Antras žingsnis: surandam visus darbuotojus su tuo atlyginimu
    vector<Darbuotojas> darbuotojaiSuDidziausiuAtlyginimu;
    for (int i = 0; i < kiek; ++i) {
        if (darbuotojai[i].atlyginimas == didziausiasAtlyginimas) {
            darbuotojaiSuDidziausiuAtlyginimu.push_back(darbuotojai[i]);
        }
    }

    // Išvedam rezultatus
    cout << "\nDarbuotojai su didžiausiu atlyginimu (" << didziausiasAtlyginimas << " €):\n";
    for (const auto& darb : darbuotojaiSuDidziausiuAtlyginimu) {
        cout << darb.vardas << " " << darb.pavarde << '\n';
    }
}

// 23. Sukeisti dvi reikšmes naudojant rodykles
void sukeistiReiksmes(int* a, int* b) {
    int laikinas = *a;
    *a = *b;
    *b = laikinas;
}

void vykdytiReiksmiuSukeitima() {
    int pirmas, antras;
    cout << "Įveskite pirmą skaičių: ";
    cin >> pirmas;
    cout << "Įveskite antrą skaičių: ";
    cin >> antras;

    cout << "\nPrieš sukeitimą: pirmas = " << pirmas << ", antras = " << antras << '\n';

    sukeistiReiksmes(&pirmas, &antras); // perduodam adresus

    cout << "Po sukeitimo: pirmas = " << pirmas << ", antras = " << antras << '\n';
}

// 24. Dinaminis masyvas, kuris kinta įvedant naujus skaičius
void dinaminisMasyvas() {
    int* masyvas = nullptr; // pradžioje nėra jokių skaičių
    int dydis = 0; // dabartinis masyvo dydis
    int skaicius;
    char pasirinkimas;

    do {
        cout << "Įveskite skaičių: ";
        cin >> skaicius;

        // Sukuriam naują masyvą, didesnį vienu elementu
        int* naujasMasyvas = new int[dydis + 1];

        // Nukopijuojame senus duomenis į naują masyvą
        for (int i = 0; i < dydis; ++i) {
            naujasMasyvas[i] = masyvas[i];
        }

        // Įdedam naują įvestą skaičių į paskutinę vietą
        naujasMasyvas[dydis] = skaicius;
        dydis++;

        // Išlaisvinam seną masyvą
        delete[] masyvas;

        // Rodyklė rodo į naują masyvą
        masyvas = naujasMasyvas;

        cout << "Ar norite įvesti dar vieną skaičių? (t/n): ";
        cin >> pasirinkimas;

    } while (pasirinkimas == 't' || pasirinkimas == 'T');

    // Išvedame galutinį masyvą
    cout << "\nĮvesti skaičiai:\n";
    for (int i = 0; i < dydis; ++i) {
        cout << masyvas[i] << " ";
    }
    cout << '\n';

    // Išlaisvinam galutinį masyvą
    delete[] masyvas;
}

// 25. Dinamiškai saugoti ir keisti tekstą
void dinaminisTekstas() {
    string tekstas; // Naudojam std::string vietoj char*

    cout << "Įveskite tekstą: ";
    cin.ignore(); // išvalom likusį '\n'
    getline(cin, tekstas);

    cout << "\nJūsų įvestas tekstas: " << tekstas << '\n';

    char pasirinkimas;
    cout << "\nAr norite pakeisti tekstą? (t/n): ";
    cin >> pasirinkimas;
    cin.ignore();

    if (pasirinkimas == 't' || pasirinkimas == 'T') {
        cout << "Įveskite naują tekstą: ";
        getline(cin, tekstas);
        cout << "\nNaujas tekstas: " << tekstas << '\n';
    }
}

// Palaukti klavišo paspaudimo
void spaustiBetKą() {
    cout << "\nPaspauskite Enter, kad tęstumėte...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // išvalom bet kokį seną likusį įvedimą
    cin.get(); // laukiam, kol paspaus Enter
    }


int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    // Sukuriam dinaminį meniu sąrašą
    vector<pair<string, function<void()>>> meniu = {
        {"Suskaičiuoti kiek skaičių dalinasi iš 7", vykdytiCountDivisibleBy7},
        {"Rasti mažiausią ir didžiausią iš trijų skaičių", rastiDidziausiaIrMaziausia},
        {"Konvertuoti centimetrus į metrus", cmToMeters},
        {"Konvertuoti metrus į centimetrus", metersToCm},
        {"Skaičiuotuvas (sudėtis, atimtis, daugyba, dalyba)", skaiciuotuvas},
        {"Patikrinti ar skaičius lyginis ar nelyginis", tikrintiLygini},
        {"Spausdinti daugybos lentelę nuo 1 iki N", daugybosLentele},
        {"Rasti visus pirminius skaičius nuo 1 iki N", rastiPirminius},
        {"Konvertuoti valandas į minutes ir sekundes", konvertuotiValandas},
        {"Suskaičiuoti balsius ir priebalsius žodyje arba sakinyje", skaiciuotiBalsiusIrPriebalsius},
        {"Generuoti atsitiktinį skaičių masyvą ir apskaičiuoti vidurkį", generuotiMasyvaIrSkaiciuotiVidurki},
        {"Rasti daugiausiai pasikartojantį skaičių masyve", rastiDazniausiusSkaicius},
        {"Apskaičiuoti matricos determinantą (2x2 arba 3x3)", skaiciuotiDeterminanta},
        {"Apskaičiuoti dviejų skaičių didžiausią bendrą daliklį (DBD)", vykdytiDBDSkaiciavima},
        {"Rasti n-tojo Fibonačio skaičiaus reikšmę", vykdytiFibonaciSkaiciavima},
        {"Konvertuoti temperatūrą tarp Celsijaus ir Farenheito", konvertuotiTemperatura},
        {"Konvertuoti dešimtainį skaičių į dvejetainį (rekursija)", vykdytiDesimtainioKonvertavima},
        {"Rekursyviai apskaičiuoti sumą nuo 1 iki N", vykdytiSumaIkiN},
        {"Įrašyti studentų vardus ir pažymius į failą, tada nuskaityti", irasytiIrNuskaitytiStudentus},
        {"Suskaičiuoti žodžių skaičių faile", skaiciuotiZodziusFaile},
        {"Įvesti automobilius ir surikiuoti pagal kainą", valdytiAutomobilius},
        {"Įvesti darbuotojus ir rasti turintį/čius didžiausią atlyginimą", rastiDidziausiusAtlyginimus},
        {"Sukeisti dvi reikšmes naudojant rodykles", vykdytiReiksmiuSukeitima},
        {"Dinaminis masyvas, kuris auga įvedant skaičius", dinaminisMasyvas},
        {"Dinamiškai saugoti ir keisti tekstą", dinaminisTekstas}
    };

    int pasirinkimas;

    do {
        system("cls"); // išvalyti ekraną
        cout << "\n=== Meniu ===\n";

        // Automatiškai išvedam visas meniu parinktis
        for (size_t i = 0; i < meniu.size(); ++i) {
            cout << i + 1 << ". " << meniu[i].first << '\n';
        }
        cout << "0. Išeiti\n";
        cout << "Pasirinkite: ";
        cin >> pasirinkimas;

        if (pasirinkimas == 0) {
            cout << "Programa baigta.\n";
            break;
        } else if (pasirinkimas > 0 && pasirinkimas <= static_cast<int>(meniu.size())) {
            // Vykdom pasirinkimą
            meniu[pasirinkimas - 1].second();
            spaustiBetKą();
        } else {
            cout << "Neteisingas pasirinkimas. Bandykite dar kartą.\n";
            spaustiBetKą();
        }

    } while (pasirinkimas != 0);

    return 0;
}