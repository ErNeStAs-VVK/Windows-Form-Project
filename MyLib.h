#pragma once
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <fstream>

 
class Studentas {
    std::string vardas;
    std::string pavarde;
    std::vector<int> nd;
    int egz = 0;
    double galutinis = 0.0;

public:
    Studentas() = default;
    Studentas(std::string v, std::string p, std::vector<int> nd_, int egz_);

    void Skaiciuoti();
    double Galutinis() const { return galutinis; }
    const std::string& Vardas() const { return vardas; }
    const std::string& Pavarde() const { return pavarde; }
};

 
enum class ContainerType { Vector, List, Deque };

 
struct FinalGrades {
    double vidurkis;
    double mediana;
};

 
double vidurkis(const std::vector<int>& v);
double mediana(std::vector<int> v);

 
bool ParseND(const std::string& s, std::vector<int>& outNd, std::string& err);
bool ValidateStudentInput(const std::string& vardas, const std::string& pavarde, std::string& error);
bool ValidateExamGrade(int grade, std::string& error);

 
bool IsFileEmpty(const std::string& path);
void WriteHeaderKursiokai(std::ofstream& out);

 
FinalGrades CalculateFinalGrades(const std::vector<int>& nd, int egz);

 
void WriteStudentToFile(const std::string& filename,
    const std::string& pavarde,
    const std::string& vardas,
    double gal_vid, double gal_med);

 
void GeneruotiFaila(const std::string& filename, int N, int nd_kiek);

 
void GeneruotiSugeneruoti(const std::string& filename, int N, int nd_kiek);

 
std::vector<Studentas> SkaitytiVector(const std::string& path);
std::list<Studentas>   SkaitytiList(const std::string& path);
std::deque<Studentas>  SkaitytiDeque(const std::string& path);

 
void RasytiVector(const std::string& filename, const std::vector<Studentas>& c);
void RasytiList(const std::string& filename, const std::list<Studentas>& c);
void RasytiDeque(const std::string& filename, const std::deque<Studentas>& c);

 
void Strategija1_Vector(const std::string& inputFile);
void Strategija1_List(const std::string& inputFile);
void Strategija1_Deque(const std::string& inputFile);

void Strategija2_Vector(const std::string& inputFile);
void Strategija2_List(const std::string& inputFile);
void Strategija2_Deque(const std::string& inputFile);

 
void RunStrategy(ContainerType container, int strategyIndex,
    const std::string& inputFile,
    double& genTime, double& stratTime,
    int N, int nd_kiek);


std::string GetResultsFolder();
std::string MakePathInResults(const std::string& fileName);
std::string ResolvePath(const std::string& fileOrPath);
