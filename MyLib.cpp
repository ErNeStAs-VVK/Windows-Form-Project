#include "pch.h"
#include "MyLib.h"
#include <fstream>
#include <sstream>
#include <random>
#include <iomanip>
#include <stdexcept>
#include <numeric>
#include <algorithm>
#include <chrono>
#include <msclr/marshal_cppstd.h>

static std::string ResolvePath(const std::string& fileOrPath);


 

double vidurkis(const std::vector<int>& v) {
    if (v.empty()) return 0.0;
    double sum = std::accumulate(v.begin(), v.end(), 0.0);
    return sum / v.size();
}

double mediana(std::vector<int> v) {
    if (v.empty()) return 0.0;
    std::sort(v.begin(), v.end());
    size_t n = v.size();
    if (n % 2 == 1) return static_cast<double>(v[n / 2]);
    return (v[n / 2 - 1] + v[n / 2]) / 2.0;
}

 

bool ParseND(const std::string& s, std::vector<int>& outNd, std::string& err) {
    outNd.clear();

    std::string t = s;
    for (char& c : t) {
        if (c == ',' || c == ';' || c == '\t') c = ' ';
    }

    std::istringstream iss(t);
    int x;
    while (iss >> x) {
        if (x < 1 || x > 10) {
            err = "ND pazymiai turi buti nuo 1 iki 10.";
            return false;
        }
        outNd.push_back(x);
    }

    if (!s.empty() && outNd.empty()) {
        err = "ND lauke turi buti skaiciai (pvz.: 10 9 8 7).";
        return false;
    }

    return true;
}

bool ValidateStudentInput(const std::string& vardas, const std::string& pavarde, std::string& error) {
    if (vardas.empty() || pavarde.empty()) {
        error = "Iveskite varda ir pavarde.";
        return false;
    }
    return true;
}

bool ValidateExamGrade(int grade, std::string& error) {
    if (grade < 1 || grade > 10) {
        error = "Egzamino bala turi buti nuo 1 iki 10.";
        return false;
    }
    return true;
}

 

bool IsFileEmpty(const std::string& path) {
    std::ifstream in(path, std::ios::binary);
    if (!in) return true;
    in.seekg(0, std::ios::end);
    return in.tellg() == 0;
}

void WriteHeaderKursiokai(std::ofstream& out) {
    out << std::left
        << std::setw(18) << "Pavarde"
        << std::setw(18) << "Vardas"
        << std::setw(18) << "Galutinis (Vid.)"
        << std::setw(18) << "Galutinis (Med.)"
        << "\n--------------------------------------------------------------------------\n";
}

 

FinalGrades CalculateFinalGrades(const std::vector<int>& nd, int egz) {
    FinalGrades result;

    if (!nd.empty()) {
        double hw_vid = vidurkis(nd);
        double hw_med = mediana(nd);
        result.vidurkis = 0.4 * hw_vid + 0.6 * egz;
        result.mediana = 0.4 * hw_med + 0.6 * egz;
    }
    else {
        result.vidurkis = 0.6 * egz;
        result.mediana = 0.6 * egz;
    }

    return result;
}

 

void WriteStudentToFile(const std::string& filename,
    const std::string& pavarde,
    const std::string& vardas,
    double gal_vid, double gal_med)
{
    std::string path = ResolvePath(filename);

    bool needHeader = IsFileEmpty(path);

    std::ofstream out(path, std::ios::app);
    if (!out) {
        throw std::runtime_error("Nepavyko atidaryti failo: " + path);
    }

    if (needHeader) {
        WriteHeaderKursiokai(out);
    }

    out << std::left
        << std::setw(18) << pavarde
        << std::setw(18) << vardas
        << std::fixed << std::setprecision(2)
        << std::setw(18) << gal_vid
        << std::setw(18) << gal_med
        << "\n";
}

 

Studentas::Studentas(std::string v, std::string p, std::vector<int> nd_, int egz_)
    : vardas(std::move(v)), pavarde(std::move(p)), nd(std::move(nd_)), egz(egz_) {
    Skaiciuoti();
}

void Studentas::Skaiciuoti() {
    double avg = vidurkis(nd);
    galutinis = 0.4 * avg + 0.6 * egz;
}

 

    static Studentas ParseLineToStudent(const std::string& line) {
     
    std::istringstream iss(line);
    std::string pavarde, vardas;
    if (!(iss >> pavarde >> vardas))
        throw std::runtime_error("Bloga eilute (truksta vardo/pavardes): " + line);

    std::vector<int> paz;
    int x;
    while (iss >> x) paz.push_back(x);

    if (paz.empty())
        throw std::runtime_error("Bloga eilute (nera pazymiu): " + line);

    int egz = paz.back();
    paz.pop_back();  

    return Studentas(vardas, pavarde, paz, egz);
}

static void WriteHeaderOneCol(std::ofstream& out) {
    out << std::left << std::setw(18) << "Pavarde"
        << std::setw(18) << "Vardas"
        << "Galutinis\n";
    out << std::string(54, '-') << "\n";
}

static void WriteStudent(std::ofstream& out, const Studentas& s) {
    out << std::left << std::setw(18) << s.Pavarde()
        << std::setw(18) << s.Vardas()
        << std::fixed << std::setprecision(2) << s.Galutinis()
        << "\n";
}

static std::string BaseNameNoExt(const std::string& path) {
    size_t dotPos = path.find_last_of('.');
    if (dotPos == std::string::npos) return path;
    return path.substr(0, dotPos);
}

 

void GeneruotiFaila(const std::string& filename, int N, int nd_kiek) 
{
    std::string path = ResolvePath(filename);
    
    if (N <= 0 || nd_kiek <= 0)
        throw std::runtime_error("N ir ND kiek turi buti > 0");

    std::mt19937 rng((unsigned)std::random_device{}());
    std::uniform_int_distribution<int> d(1, 10);

    std::ofstream out(path);
    if (!out) throw std::runtime_error("Nepavyko sukurti failo: " + filename);

     
    out << std::left
        << std::setw(18) << "Pavarde"
        << std::setw(18) << "Vardas";

    for (int j = 1; j <= nd_kiek; ++j) {
        out << std::setw(8) << ("ND" + std::to_string(j));
    }
    out << std::setw(8) << "Egz\n";

    out << std::string(34 + nd_kiek * 8 + 8, '-') << "\n";

    for (int i = 1; i <= N; ++i) {
        out << std::left
            << std::setw(18) << ("Pavarde" + std::to_string(i))
            << std::setw(18) << ("Vardas" + std::to_string(i));

        for (int j = 0; j < nd_kiek; ++j) {
            out << std::setw(8) << d(rng);
        }
        out << std::setw(8) << d(rng) << "\n";
    }
}

 
void GeneruotiSugeneruoti(const std::string& filename, int N, int nd_kiek)
{
    std::string path = ResolvePath(filename);
    
    if (N <= 0 || nd_kiek <= 0)
        throw std::runtime_error("N ir ND kiek turi buti > 0");

    std::mt19937 rng((unsigned)std::random_device{}());
    std::uniform_int_distribution<int> d(1, 10);

    std::ofstream out(path);
    if (!out) throw std::runtime_error("Nepavyko sukurti failo: " + filename);

     
    out << std::left
        << std::setw(18) << "Pavarde"
        << std::setw(18) << "Vardas"
        << std::setw(18) << "Galutinis (Vid.)"
        << std::setw(18) << "Galutinis (Med.)"
        << "\n--------------------------------------------------------------------------\n";

     
    for (int i = 1; i <= N; ++i) {
        std::vector<int> paz;
        paz.reserve(nd_kiek);
         
        for (int j = 0; j < nd_kiek; ++j)
            paz.push_back(d(rng));

         
        double hw_vid = vidurkis(paz);
        double hw_med = mediana(paz);

         
        double gal_vid = hw_vid;
        double gal_med = hw_med;

        out << std::left
            << std::setw(18) << ("Pavarde" + std::to_string(i))
            << std::setw(18) << ("Vardas" + std::to_string(i))
            << std::fixed << std::setprecision(2)
            << std::setw(18) << gal_vid
            << std::setw(18) << gal_med
            << "\n";
    }

    out.close();
}

 

std::vector<Studentas> SkaitytiVector(const std::string& path)
{
    std::string realPath = ResolvePath(path);
    
    std::ifstream in(realPath);
    if (!in) throw std::runtime_error("Nepavyko atidaryti failo: " + path);

    std::vector<Studentas> grupe;
    std::string line;

    std::getline(in, line); 
    std::getline(in, line);
    while (std::getline(in, line)) {
        if (line.empty()) continue;
        grupe.push_back(ParseLineToStudent(line));
    }
    return grupe;
}

std::list<Studentas> SkaitytiList(const std::string& path) 
{
    std::string realPath = ResolvePath(path);

    std::ifstream in(realPath);
    if (!in) throw std::runtime_error("Nepavyko atidaryti failo: " + path);

    std::list<Studentas> grupe;
    std::string line;

    std::getline(in, line);  
    std::getline(in, line);
    while (std::getline(in, line)) {
        if (line.empty()) continue;
        grupe.push_back(ParseLineToStudent(line));
    }
    return grupe;
}

std::deque<Studentas> SkaitytiDeque(const std::string& path)
{
    std::string realPath = ResolvePath(path);

    std::ifstream in(realPath);
    if (!in) throw std::runtime_error("Nepavyko atidaryti failo: " + path);

    std::deque<Studentas> grupe;
    std::string line;

    std::getline(in, line);  
    std::getline(in, line);
    while (std::getline(in, line)) {
        if (line.empty()) continue;
        grupe.push_back(ParseLineToStudent(line));
    }
    return grupe;
}

 

void RasytiVector(const std::string& filename, const std::vector<Studentas>& c) {
    std::string path = ResolvePath(filename);

    std::ofstream out(path);
    if (!out) throw std::runtime_error("Nepavyko sukurti failo: " + filename);
    WriteHeaderOneCol(out);
    for (const auto& s : c) WriteStudent(out, s);
}

void RasytiList(const std::string& filename, const std::list<Studentas>& c) {
    std::string path = ResolvePath(filename);
    
    std::ofstream out(path);
    if (!out) throw std::runtime_error("Nepavyko sukurti failo: " + filename);
    WriteHeaderOneCol(out);
    for (const auto& s : c) WriteStudent(out, s);
}

void RasytiDeque(const std::string& filename, const std::deque<Studentas>& c) {
    std::string path = ResolvePath(filename);
    
    std::ofstream out(path);
    if (!out) throw std::runtime_error("Nepavyko sukurti failo: " + filename);
    WriteHeaderOneCol(out);
    for (const auto& s : c) WriteStudent(out, s);
}

 
void Strategija1_Vector(const std::string& inputFile) {
    auto visi = SkaitytiVector(inputFile);
    std::vector<Studentas> kietiakiai, vargsiukai;

    for (const auto& s : visi) {
        if (s.Galutinis() >= 5.0) kietiakiai.push_back(s);
        else vargsiukai.push_back(s);
    }

    std::string base = BaseNameNoExt(inputFile);
    RasytiVector(base + "_kietiakiai.txt", kietiakiai);
    RasytiVector(base + "_vargsiukai.txt", vargsiukai);
}

void Strategija1_List(const std::string& inputFile) {
    auto visi = SkaitytiList(inputFile);
    std::list<Studentas> kietiakiai, vargsiukai;

    for (const auto& s : visi) {
        if (s.Galutinis() >= 5.0) kietiakiai.push_back(s);
        else vargsiukai.push_back(s);
    }

    std::string base = BaseNameNoExt(inputFile);
    RasytiList(base + "_kietiakiai.txt", kietiakiai);
    RasytiList(base + "_vargsiukai.txt", vargsiukai);
}

void Strategija1_Deque(const std::string& inputFile) {
    auto visi = SkaitytiDeque(inputFile);
    std::deque<Studentas> kietiakiai, vargsiukai;

    for (const auto& s : visi) {
        if (s.Galutinis() >= 5.0) kietiakiai.push_back(s);
        else vargsiukai.push_back(s);
    }

    std::string base = BaseNameNoExt(inputFile);
    RasytiDeque(base + "_kietiakiai.txt", kietiakiai);
    RasytiDeque(base + "_vargsiukai.txt", vargsiukai);
}

void Strategija2_Vector(const std::string& inputFile) {
    auto kietiakiai = SkaitytiVector(inputFile);
    std::vector<Studentas> vargsiukai;

    auto it = kietiakiai.begin();
    while (it != kietiakiai.end()) {
        if (it->Galutinis() < 5.0) {
            vargsiukai.push_back(*it);
            it = kietiakiai.erase(it);
        }
        else ++it;
    }

    std::string base = BaseNameNoExt(inputFile);
    RasytiVector(inputFile, kietiakiai);
    RasytiVector(base + "_vargsiukai.txt", vargsiukai);
}

void Strategija2_List(const std::string& inputFile) {
    auto kietiakiai = SkaitytiList(inputFile);
    std::list<Studentas> vargsiukai;

    auto it = kietiakiai.begin();
    while (it != kietiakiai.end()) {
        if (it->Galutinis() < 5.0) {
            vargsiukai.push_back(*it);
            it = kietiakiai.erase(it);
        }
        else ++it;
    }

    std::string base = BaseNameNoExt(inputFile);
    RasytiList(inputFile, kietiakiai);
    RasytiList(base + "_vargsiukai.txt", vargsiukai);
}

void Strategija2_Deque(const std::string& inputFile) {
    auto kietiakiai = SkaitytiDeque(inputFile);
    std::deque<Studentas> vargsiukai;

    auto it = kietiakiai.begin();
    while (it != kietiakiai.end()) {
        if (it->Galutinis() < 5.0) {
            vargsiukai.push_back(*it);
            it = kietiakiai.erase(it);
        }
        else ++it;
    }

    std::string base = BaseNameNoExt(inputFile);
    RasytiDeque(inputFile, kietiakiai);
    RasytiDeque(base + "_vargsiukai.txt", vargsiukai);
}

void RunStrategy(ContainerType container, int strategyIndex,
    const std::string& inputFile,
    double& genTime, double& stratTime,
    int N, int nd_kiek) {

    
    auto t0 = std::chrono::high_resolution_clock::now();
    GeneruotiFaila(inputFile, N, nd_kiek);
    auto t1 = std::chrono::high_resolution_clock::now();
    genTime = std::chrono::duration<double>(t1 - t0).count();

    
    auto t2 = std::chrono::high_resolution_clock::now();

    if (container == ContainerType::Vector) {
        if (strategyIndex == 0) Strategija1_Vector(inputFile);
        else Strategija2_Vector(inputFile);
    }
    else if (container == ContainerType::List) {
        if (strategyIndex == 0) Strategija1_List(inputFile);
        else Strategija2_List(inputFile);
    }
    else {
        if (strategyIndex == 0) Strategija1_Deque(inputFile);
        else Strategija2_Deque(inputFile);
    }

    auto t3 = std::chrono::high_resolution_clock::now();
    stratTime = std::chrono::duration<double>(t3 - t2).count();
}

std::string GetResultsFolder()
{
    System::String^ docPath =
        System::Environment::GetFolderPath(System::Environment::SpecialFolder::MyDocuments);

    System::String^ resultPath = System::IO::Path::Combine(docPath, "Rezultatas");

    if (!System::IO::Directory::Exists(resultPath))
        System::IO::Directory::CreateDirectory(resultPath);

    return msclr::interop::marshal_as<std::string>(resultPath);
}

std::string MakePathInResults(const std::string& fileName)
{
    std::string base = GetResultsFolder();
    return base + "\\" + fileName;
}


     std::string ResolvePath(const std::string& fileOrPath)
{
    
    if (fileOrPath.size() >= 2 && fileOrPath[1] == ':') return fileOrPath;          
    if (fileOrPath.rfind("\\\\", 0) == 0) return fileOrPath;                         
    if (!fileOrPath.empty() && (fileOrPath[0] == '\\' || fileOrPath[0] == '/')) return fileOrPath;

     
    return MakePathInResults(fileOrPath);
}
