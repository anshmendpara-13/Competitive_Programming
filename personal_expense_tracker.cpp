#include<bits/stdc++.h>
using namespace std;

struct Expense {
    string date;
    string category;
    double amount;
    string description;
};

vector<Expense> expenses;

double monthlyBudget = 0;

void addExpense() {
    Expense newExpense;
    cout << "Enter the date (YYYY-MM-DD): ";
    cin >> newExpense.date;
    cout << "Enter the category (e.g., Food, Travel): ";
    cin.ignore();
    getline(cin, newExpense.category);
    cout << "Enter the amount: ";
    cin >> newExpense.amount;
    cout << "Enter a brief description: ";
    cin.ignore();
    getline(cin, newExpense.description);

    expenses.push_back(newExpense);
    cout << "Expense added successfully!\n";
}

void viewExpenses() {
    if (expenses.empty()) {
        cout << "No expenses recorded yet.\n";
        return;
    }

    cout << left << setw(15) << "Date" << setw(15) << "Category" << setw(10) << "Amount" << "Description" << endl;
    cout << string(55, '-') << endl;
    for (const auto &expense : expenses) {
        if (!expense.date.empty() && !expense.category.empty() && expense.amount > 0 && !expense.description.empty()) {
            cout << left << setw(15) << expense.date << setw(15) << expense.category
                 << setw(10) << expense.amount << expense.description << endl;
        } else {
            cout << "Incomplete expense data found.\n";
        }
    }
}

void trackBudget() {
    if (monthlyBudget == 0) {
        cout << "Enter your monthly budget: ";
        cin >> monthlyBudget;
        cout << "Monthly budget set to " << monthlyBudget << "\n";
    }

    double totalExpenses = 0;
    for (const auto &expense : expenses) {
        totalExpenses += expense.amount;
    }

    cout << "Total expenses so far: " << totalExpenses << "\n";
    if (totalExpenses > monthlyBudget) {
        cout << "You have exceeded your budget by " << (totalExpenses - monthlyBudget) << "!\n";
    } else {
        cout << "You have " << (monthlyBudget - totalExpenses) << " left for the month.\n";
    }
}

void saveExpenses() {
    ofstream file("expenses.csv");
    if (!file) {
        cerr << "Error: Unable to open file for saving.\n";
        return;
    }

    for (const auto &expense : expenses) {
        file << expense.date << "," << expense.category << "," << expense.amount << "," << expense.description << "\n";
    }

    file.close();
    cout << "Expenses saved successfully to expenses.csv!\n";
}

void loadExpenses() {
    ifstream file("expenses.csv");
    if (!file) {
        cerr << "No previous expenses found to load.\n";
        return;
    }

    Expense expense;
    string line;
    while (getline(file, line)) {
        size_t pos1 = line.find(',');
        size_t pos2 = line.find(',', pos1 + 1);
        size_t pos3 = line.find(',', pos2 + 1);

        expense.date = line.substr(0, pos1);
        expense.category = line.substr(pos1 + 1, pos2 - pos1 - 1);
        expense.amount = stod(line.substr(pos2 + 1, pos3 - pos2 - 1));
        expense.description = line.substr(pos3 + 1);

        expenses.push_back(expense);
    }

    file.close();
    cout << "Expenses loaded successfully from expenses.csv!\n";
}

void menu() {
    int choice;
    do {
        cout << "\nPersonal Expense Tracker Menu:\n";
        cout << "1. Add Expense\n";
        cout << "2. View Expenses\n";
        cout << "3. Track Budget\n";
        cout << "4. Save Expenses\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addExpense();
                break;
            case 2:
                viewExpenses();
                break;
            case 3:
                trackBudget();
                break;
            case 4:
                saveExpenses();
                break;
            case 5:
                saveExpenses();
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);
}

int main() {
    loadExpenses();
    menu();
    return 0;
}
