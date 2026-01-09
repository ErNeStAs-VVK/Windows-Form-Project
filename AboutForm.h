#pragma once

namespace CppCLRWinFormsProject {

    using namespace System;
    using namespace System::Windows::Forms;
    using namespace System::Drawing;

    public ref class AboutForm : public Form
    {
    public:
        AboutForm()
        {
            this->Text = "About";
            this->StartPosition = FormStartPosition::CenterParent;
            this->Size = Drawing::Size(900, 700);

            TextBox^ tb = gcnew TextBox();
            tb->Multiline = true;
            tb->ReadOnly = true;
            tb->ScrollBars = ScrollBars::Vertical;
            tb->Dock = DockStyle::Fill;
            tb->Font = gcnew Drawing::Font("Segoe UI", 10);

            tb->Text =
                "Application Functionality\r\n\r\n"
                "Manual Input (Ivesti rankiniu budu)\r\n\r\n"
                "Allows the user to manually add a new student:\r\n"
                "- First name\r\n"
                "- Last name\r\n"
                "- Homework grades\r\n"
                "- Exam grade (optional)\r\n\r\n"
                "After submission:\r\n"
                "- The student is written to kursiokai.txt\r\n"
                "- Final grades are calculated using:\r\n"
                "  - Average (Vidurkis)\r\n"
                "  - Median (Mediana)\r\n\r\n"
                "Random Generation (Sugeneruoti atsitiktinai)\r\n\r\n"
                "Allows generating multiple students at once:\r\n"
                "- Number of students\r\n"
                "- Number of homework grades (ND) per student\r\n\r\n"
                "Result:\r\n"
                "- Random students with generated grades\r\n"
                "- Saved to sugeneruoti.txt\r\n"
                "- The file is formatted as a table with calculated final results\r\n\r\n"
                "Read From File (Nuskaityti is failo)\r\n\r\n"
                "Displays a panel that allows reading data from any file:\r\n"
                "- Click \"ikelti\" to select and load a file\r\n"
                "- File contents are displayed in a list\r\n"
                "- Click \"isvalyti\" to clear the displayed data\r\n\r\n"
                "Generate Files and Test Strategies\r\n\r\n"
                "Container selection:\r\n"
                "- vector\r\n"
                "- list\r\n"
                "- deque\r\n\r\n"
                "Strategy 1:\r\n"
                "- Generates students_generated.txt with all students\r\n"
                "- Splits into:\r\n"
                "  - students_generated_kietiakiai.txt (good results)\r\n"
                "  - students_generated_vargsiukai.txt (weak results)\r\n\r\n"
                "Strategy 2:\r\n"
                "- Moves weak students into a separate file\r\n"
                "- Removes them from the main container\r\n\r\n"
                "Performance Measurement:\r\n"
                "- File generation time\r\n"
                "- Strategy execution time\r\n\r\n"
                "Comparison:\r\n"
                "- Different STL containers\r\n"
                "- Different strategies\r\n";

            this->Controls->Add(tb);
        }
    };
}
