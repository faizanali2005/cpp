#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>

using namespace std;

/* =========================================================
   PROGRAMMING FUNDAMENTALS QUIZ APPLICATION
   Concepts Covered:
   - Variables
   - Data Types
   - Operators
   - Conditions
   - Loops
   - Arrays
   - Functions
   - Structures
   - File Handling (CSV)
   - Menu Driven Program
   ========================================================= */

/* ===================== CONSTANTS ===================== */
const int MAX_QUESTIONS = 50;
const string QUESTION_FILE = "questions.csv";
const string RESULT_FILE = "result.txt";

/* ===================== STRUCT ===================== */
struct Question {
    int id;
    string question;
    string optionA;
    string optionB;
    string optionC;
    string optionD;
    char correct;
};

/* ===================== GLOBAL VARIABLES ===================== */
Question quiz[MAX_QUESTIONS];
int totalQuestions = 0;

/* ===================== FUNCTION DECLARATIONS ===================== */
void mainMenu();
void adminMenu();
void studentMenu();

void loadQuestions();
void saveQuestionToFile(Question q);
void addQuestion();
void viewQuestions();

void startQuiz();
void showResult(string name, int score, int total);

void pause();
void clearScreen();

/* ===================== UTILITY FUNCTIONS ===================== */
void pause() {
    cout << "\nPress Enter to continue...";
    cin.ignore();
    cin.get();
}

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

/* ===================== FILE HANDLING ===================== */
void loadQuestions() {
    ifstream file(QUESTION_FILE);
    totalQuestions = 0;

    if (!file.is_open()) {
        return;
    }

    while (!file.eof()) {
        Question q;
        string temp;

        getline(file, temp, ',');
        if (temp == "") break;

        q.id = stoi(temp);
        getline(file, q.question, ',');
        getline(file, q.optionA, ',');
        getline(file, q.optionB, ',');
        getline(file, q.optionC, ',');
        getline(file, q.optionD, ',');
        file >> q.correct;
        file.ignore();

        quiz[totalQuestions++] = q;
    }

    file.close();
}

void saveQuestionToFile(Question q) {
    ofstream file(QUESTION_FILE, ios::app);
    if (file.is_open()) {
        file << q.id << ","
             << q.question << ","
             << q.optionA << ","
             << q.optionB << ","
             << q.optionC << ","
             << q.optionD << ","
             << q.correct << "\n";
        file.close();
    }
}

/* ===================== ADMIN FUNCTIONS ===================== */
void addQuestion() {
    clearScreen();
    Question q;
    q.id = totalQuestions + 1;

    cin.ignore();
    cout << "Enter Question: ";
    getline(cin, q.question);

    cout << "Option A: ";
    getline(cin, q.optionA);

    cout << "Option B: ";
    getline(cin, q.optionB);

    cout << "Option C: ";
    getline(cin, q.optionC);

    cout << "Option D: ";
    getline(cin, q.optionD);

    cout << "Correct Option (A/B/C/D): ";
    cin >> q.correct;

    saveQuestionToFile(q);
    quiz[totalQuestions++] = q;

    cout << "\nQuestion Added Successfully!\n";
    pause();
}

void viewQuestions() {
    clearScreen();
    loadQuestions();

    for (int i = 0; i < totalQuestions; i++) {
        cout << "\nQ" << quiz[i].id << ": " << quiz[i].question << endl;
        cout << "A) " << quiz[i].optionA << endl;
        cout << "B) " << quiz[i].optionB << endl;
        cout << "C) " << quiz[i].optionC << endl;
        cout << "D) " << quiz[i].optionD << endl;
        cout << "Correct: " << quiz[i].correct << endl;
    }

    pause();
}

void adminMenu() {
    int choice;
    do {
        clearScreen();
        cout << "\n===== ADMIN PANEL =====\n";
        cout << "1. Add Question\n";
        cout << "2. View Questions\n";
        cout << "3. Back\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addQuestion(); break;
            case 2: viewQuestions(); break;
        }
    } while (choice != 3);
}

/* ===================== STUDENT FUNCTIONS ===================== */
void startQuiz() {
    clearScreen();
    loadQuestions();

    if (totalQuestions == 0) {
        cout << "No questions available.\n";
        pause();
        return;
    }

    string name;
    int score = 0;
    char answer;

    cin.ignore();
    cout << "Enter Your Name: ";
    getline(cin, name);

    for (int i = 0; i < totalQuestions; i++) {
        clearScreen();
        cout << "\nQuestion " << i + 1 << " of " << totalQuestions << endl;
        cout << quiz[i].question << endl;
        cout << "A) " << quiz[i].optionA << endl;
        cout << "B) " << quiz[i].optionB << endl;
        cout << "C) " << quiz[i].optionC << endl;
        cout << "D) " << quiz[i].optionD << endl;
        cout << "Your Answer: ";
        cin >> answer;

        if (toupper(answer) == quiz[i].correct) {
            score++;
        }
    }

    showResult(name, score, totalQuestions);
}

void showResult(string name, int score, int total) {
    clearScreen();
    float percentage = (float(score) / total) * 100;

    cout << "\n===== RESULT =====\n";
    cout << "Name: " << name << endl;
    cout << "Score: " << score << "/" << total << endl;
    cout << "Percentage: " << fixed << setprecision(2) << percentage << "%\n";

    if (percentage >= 50)
        cout << "Status: PASS\n";
    else
        cout << "Status: FAIL\n";

    ofstream file(RESULT_FILE, ios::app);
    file << name << " " << score << "/" << total << " " << percentage << "%\n";
    file.close();

    pause();
}

void studentMenu() {
    int choice;
    do {
        clearScreen();
        cout << "\n===== STUDENT PANEL =====\n";
        cout << "1. Start Quiz\n";
        cout << "2. Back\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: startQuiz(); break;
        }
    } while (choice != 2);
}

/* ===================== MAIN MENU ===================== */
void mainMenu() {
    int choice;
    do {
        clearScreen();
        cout << "\n==============================\n";
        cout << " PROGRAMMING FUNDAMENTALS QUIZ \n";
        cout << "==============================\n";
        cout << "1. Admin\n";
        cout << "2. Student\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: adminMenu(); break;
            case 2: studentMenu(); break;
        }
    } while (choice != 3);
}

/* ===================== MAIN FUNCTION ===================== */
int main() {
    mainMenu();
    return 0;
}

