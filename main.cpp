#include <iostream>
#include <string>
#include <utility>

//class declaration
class Patient{
private:
    std::string _notesRec;
public:
    int HID;
    std::string _name;
    int _age;
    std::string _condition;
    // default constructors
    Patient() {
        HID = 0;
        _name = "";
        _age = 0;
        _condition = "";
        _notesRec = "";
    }   // parameterized constructor
    Patient(int id, std::string n, int a, std::string con) :
            HID(id), _name(std::move(n)),_age(a), _condition(std::move(con)) {
    }
    // Method to set notes and records (private attribute)
    void setnr(std::string nr) {
        _notesRec = std::move(std::move(nr));
    }

    // Method to get notes and records (private attribute)
    [[nodiscard]] std::string getnr() const {
        return _notesRec;
    }



};
class PatientManager {
public:
    static const int maxPatients = 100;  // Adjust the size as needed
    Patient patients[maxPatients];
    int numPatients = 0;

    // Method to add a new patient
    void addpat() {
        //get user input
        int id;
        std::string n;
        int a;
        std::string con;
        std::string nr;

        std::cout << "Enter Patient Name: ";
        std::cin.ignore();  // Ignore the newline character in the buffer
        std::getline(std::cin, n);
        std::cout << "Enter Patient Age: " << std::endl;
        std::cin >> a;
        std::cout << "Enter Patient Condition(s): " << std::endl;
        std::cin >> con;
        std::cout << "Assign Hospital ID Number: " << std::endl;
        std::cin >> id;
        std::cout << "Additional Notes / Relevant Records: " << std::endl;
        std::cin >> nr;

        // Check if the array is not full
        if (numPatients < maxPatients) {
            // Create a new Patient object and add it to the array
            patients[numPatients++] = Patient(id, n, a, con);
            patients[numPatients - 1].setnr(nr);
        } else {
            std::cout << "Available Beds Full\n Please make room by removing patients before attempting to add new ones!\n" << std::endl;
        }
    }
    // method to display
    void displaypat() const{
        std::cout << "\n [Current Patients] \n";
            for (int i = 0; i < numPatients; ++i) {
                std::cout << i + 1 << ". ID: " << patients[i].HID << ", Name: " << patients[i]._name << '\n';
            }

            if (numPatients> 0) {
                int choice;
                // Get user choice to view details of a specific student
                std::cout << "Enter the number (not hid!) of the Patient to view the rest of their information (0 to exit) ";
                std::cin >> choice;
/*
 *
 */
                if (choice > 0 && choice <= numPatients) {
                    // Display Patient Information
                    std::cout <<"Patient Name: " << patients[choice - 1]._name << "\n"
                    << "Patient Age: " << patients[choice - 1]._age << "\n"
                    << "Patient Known Condition(s): " << patients[choice - 1]._condition <<"\n"
                    << "Patient Hospital ID Number: " << patients[choice -1].HID << "\n"
                    << "N&R For Patient: " << patients[choice - 1].getnr() << "\n";
                }
            }
        }
    // Method to delete a specific Student object
    void DeleteStudent() {
        if (numPatients > 0) {
            int choice;
            // Get user choice to delete a specific student
            std::cout << "Enter the number (not hid!) of the student to delete (0 to exit): ";
            std::cin >> choice;

            if (choice > 0 && choice <= numPatients) {
                // Delete the selected student
                for (int i = choice - 1; i < numPatients - 1; ++i) {
                    patients[i] = patients[i + 1];
                }
                --numPatients;
                std::cout << "Student deleted.\n";
            }
        }
    }

};

class Staff{
public:
    int HID, contactnum[9];
    std::string name;
    std::string position;

    // default constructors
    Staff() {
        HID = 0;
        name = "";
        position = "";
        contactnum[9] = {};
    }   // parameterized constructor
    Staff(int id, std::string n, const int num[9], const std::string& pos) :
            HID(id), name(std::move(n)), position(pos, contactnum[num[9]]) {
    }
};

class StaffManager{
public:
    static const int maxStaff = 100;  // Adjust the size as needed
    Staff staff[maxStaff];
    int numStaff = 0;

    // Method to add a new staff member
    void addstaf() {
        //get user input
        int id;
        std::string n;
        int num[9];
        std::string pos;

        std::cout << "Enter Staff Member Name: ";
        std::cin.ignore();  // Ignore the newline character in the buffer
        std::getline(std::cin, n);
        std::cout << "Enter Staff Member Position: " << std::endl;
        std::cin >> pos;
        std::cout << "Enter Staff Contact Number: " << std::endl;
        std::cin >> num[9];
        std::cout << "Assign Hospital ID Number: " << std::endl;
        std::cin >> id;

        // Check if the array is not full
        if (numStaff < maxStaff) {
            // Create a new Staff object and add it to the array
            staff[numStaff++] = Staff(id, n, num, pos);
        } else {
            std::cout << "Staff Roster Full\n Try Again When There Is More Room\n" << std::endl;
        }
    }
    // method to display all staff members
    void displaystaf() const{
        std::cout << "\n [Staff Members] \n";
        for (int i = 0; i < numStaff; ++i) {
            std::cout << i + 1 << ". ID: " << staff[i].HID << ", Name: " << staff[i].name << '\n';
        }

        if (numStaff> 0) {
            int choice;
            // Get user choice to view staff contact number
            std::cout << "Enter the number (not hid!) of the Staff Member to view Employee Details\n (0 to exit) ";
            std::cin >> choice;
/*
 *
 */
            if (choice > 0 && choice <= numStaff) {
                // Display Patient Information
                std::cout <<"Staff Member Name: " << staff[choice - 1].name << "\n"
                          << "Staff Member Position: " << staff[choice - 1].position << "\n"
                          << "Staff Member Phone Number: " << staff[choice - 1].contactnum <<"\n"
                          << "Staff Hospital ID Number: " << staff[choice -1].HID << "\n";
            }
        }
    }
    // Method to delete a specific Staff Member
    void DeleteStaff() {
        if (numStaff > 0) {
            int choice;
            // Get user choice to delete a specific student
            std::cout << "Enter the number (not hid!) of the student to delete (0 to exit): ";
            std::cin >> choice;

            if (choice > 0 && choice <= numStaff) {
                // Delete the selected student
                for (int i = choice - 1; i < numStaff- 1; ++i) {
                    staff[i] = staff[i + 1];
                }
                --numStaff;
                std::cout << "Student deleted.\n";
            }
        }
    }

};


//class notepad{
//public:
  //  std::string& author;
    //std::string& data;


//};

int main() {
    char on = 'y';
    int ask;
    std::string hospitalname;
    std::cout << "What is the name of the Hospital?" << std::endl;
    std::cin >> hospitalname;
    do {
        std::cout << "Initializing..." << std::endl;
        std::cout << "* " << hospitalname << " Management System *" << std::endl;
        std::cout << "[1] Patient Index\n";
        std::cout << "[2] Staff Index\n";
        //std::cout << "[3] Notekeeper\n";
        std::cout << "[0] Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> ask;

        switch (ask) {
            case '1': {
                // Patient Index
                int patientask;
                do {
                    std::cout << "\nPatient Index:\n";
                    std::cout << "[1] Add Patient\n";
                    std::cout << "[2] Remove Patient\n";
                    std::cout << "[3] View Patients\n";
                    std::cout << "[0] Back to Main Menu\n";
                    std::cout << "Enter your choice: ";
                    std::cin >> patientask;
                    switch (patientask) {
                        case 1:
                            PatientManager.addpat();
                            break;
                        case 2:
                            PatientManager.displaypat();
                            break;
                        case 3:
                            PatientManager.deletepat();
                            break;
                        case 0:
                            std::cout << "Returning to Main Menu.\n";
                            break;
                        default:
                            std::cout << "Invalid choice. Try again.\n";
                    }
                    case 2:
                        int staffChoice;
                    do {
                        std::cout << "\n[Staff Index]\n";
                        std::cout << "[1] Add Staff Member\n";
                        std::cout << "[2] Display Staff Members\n";
                        std::cout << "[3] Delete Staff Member\n";
                        std::cout << "[0] Back to Main Menu\n";
                        std::cout << "Enter your choice: ";
                        std::cin >> staffChoice;

                        switch (staffChoice) {
                            case 1:
                                StaffManager.addstaf();
                                break;
                            case 2:
                                StaffManager.displaystaf();
                                break;
                            case 3:
                                StaffManager.deletestaf();
                                break;
                            case 0:
                                std::cout << "Returning to Main Menu.\n";
                                break;
                            default:
                                std::cout << "Invalid choice. Try again.\n";
                        }
                    } while (staffChoice != 0);
                    break;

                    case 0:
                        std::cout << "Exiting...\n";
                    break;

                    default:
                        std::cout << "Invalid choice. Try again.\n";
                }while (ask != 0);
            }

                return 0;
        } return 0;