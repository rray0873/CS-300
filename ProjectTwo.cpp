#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct Course {
    string courseNumber;
    string title;
    vector<string> prerequisites;
};

static string ToUpper(string s) {
    for (char& ch : s) ch = static_cast<char>(toupper(static_cast<unsigned char>(ch)));
    return s;
}

static string Trim(const string& s) {
    size_t start = s.find_first_not_of(" \t\r\n");
    if (start == string::npos) return "";
    size_t end = s.find_last_not_of(" \t\r\n");
    return s.substr(start, end - start + 1);
}

struct Node {
    Course course;
    Node* left = nullptr;
    Node* right = nullptr;
    explicit Node(const Course& c) : course(c) {}
};

class BinarySearchTree {
public:
    BinarySearchTree() = default;
    ~BinarySearchTree() { Clear(); }

    void Clear() {
        Destroy(root);
        root = nullptr;
        size = 0;
    }

    void Insert(const Course& course) {
        if (!root) {
            root = new Node(course);
            ++size;
            return;
        }
        InsertNode(root, course);
    }

    const Course* Search(const string& courseNumber) const {
        Node* cur = root;
        while (cur) {
            if (courseNumber == cur->course.courseNumber) return &cur->course;
            if (courseNumber < cur->course.courseNumber) cur = cur->left;
            else cur = cur->right;
        }
        return nullptr;
    }

    void PrintInOrder() const {
        InOrder(root);
    }

    bool Empty() const { return root == nullptr; }
    size_t Count() const { return size; }

private:
    Node* root = nullptr;
    size_t size = 0;

    static void Destroy(Node* node) {
        if (!node) return;
        Destroy(node->left);
        Destroy(node->right);
        delete node;
    }

    void InsertNode(Node* node, const Course& course) {
        if (course.courseNumber < node->course.courseNumber) {
            if (!node->left) {
                node->left = new Node(course);
                ++size;
            } else {
                InsertNode(node->left, course);
            }
        } else if (course.courseNumber > node->course.courseNumber) {
            if (!node->right) {
                node->right = new Node(course);
                ++size;
            } else {
                InsertNode(node->right, course);
            }
        } else {
            // Duplicate key: overwrite existing course info.
            node->course = course;
        }
    }

    static void InOrder(Node* node) {
        if (!node) return;
        InOrder(node->left);
        cout << node->course.courseNumber << ", " << node->course.title << '\n';
        InOrder(node->right);
    }
};

static bool ParseCourseLine(const string& line, Course& outCourse) {
    // Expected CSV: courseNumber,title,prereq1,prereq2,... (may contain empty trailing fields)
    if (Trim(line).empty()) return false;

    vector<string> fields;
    string field;
    stringstream ss(line);
    while (getline(ss, field, ',')) fields.push_back(Trim(field));

    if (fields.size() < 2) return false;

    string number = ToUpper(fields[0]);
    string title = fields[1];

    if (number.empty() || title.empty()) return false;

    vector<string> prereqs;
    for (size_t i = 2; i < fields.size(); ++i) {
        if (!fields[i].empty()) prereqs.push_back(ToUpper(fields[i]));
    }

    outCourse.courseNumber = number;
    outCourse.title = title;
    outCourse.prerequisites = prereqs;
    return true;
}

static bool LoadCoursesFromFile(const string& fileName, BinarySearchTree& bst) {
    ifstream file(fileName);
    if (!file.is_open()) return false;

    bst.Clear();

    string line;
    while (getline(file, line)) {
        Course c;
        if (ParseCourseLine(line, c)) {
            bst.Insert(c);
        }
    }
    return true;
}

static void PrintMenu() {
    cout << "\n"
         << "  1. Load Data Structure.\n"
         << "  2. Print Course List.\n"
         << "  3. Print Course.\n"
         << "  9. Exit\n"
         << "\n"
         << "What would you like to do? ";
}

static void PrintCourseDetails(const Course& c) {
    cout << c.courseNumber << ", " << c.title << '\n';
    if (c.prerequisites.empty()) {
        cout << "Prerequisites: None\n";
        return;
    }
    cout << "Prerequisites: ";
    for (size_t i = 0; i < c.prerequisites.size(); ++i) {
        cout << c.prerequisites[i];
        if (i + 1 < c.prerequisites.size()) cout << ", ";
    }
    cout << '\n';
}

int main() {
    BinarySearchTree bst;
    bool loaded = false;

    cout << "Welcome to the course planner.\n";

    int choice = 0;
    while (choice != 9) {
        PrintMenu();

        if (!(cin >> choice)) {
            cin.clear();
            string junk;
            getline(cin, junk);
            cout << "Invalid input.\n";
            continue;
        }

        if (choice == 1) {
            cout << "Enter file name: ";
            string fileName;
            cin >> fileName;

            if (!LoadCoursesFromFile(fileName, bst)) {
                cout << "Error: Unable to open file '" << fileName << "'.\n";
                loaded = false;
            } else {
                loaded = true;
            }
        } else if (choice == 2) {
            if (!loaded || bst.Empty()) {
                cout << "Please load the data structure first.\n";
                continue;
            }
            cout << "Here is a sample schedule:\n\n";
            bst.PrintInOrder();
        } else if (choice == 3) {
            if (!loaded || bst.Empty()) {
                cout << "Please load the data structure first.\n";
                continue;
            }
            cout << "What course do you want to know about? ";
            string query;
            cin >> query;
            query = ToUpper(Trim(query));

            const Course* found = bst.Search(query);
            if (!found) {
                cout << "Course not found.\n";
            } else {
                PrintCourseDetails(*found);
            }
        } else if (choice == 9) {
            break;
        } else {
            cout << choice << " is not a valid option.\n";
        }
    }

    cout << "Thank you for using the course planner!\n";
    return 0;
}
