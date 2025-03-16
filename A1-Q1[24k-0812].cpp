#include <iostream>
using namespace std;

class Mentor;
class Sport;
class Skill;

class Student {
private:
    string studentID;
    string name;
    int age;
    Mentor* mentorAssigned;
    Sport** sportsInterests;
    int numSports;

public:
    Student(string id, string n, int studentAge) : studentID(id), name(n), age(studentAge), mentorAssigned(nullptr), sportsInterests(nullptr), numSports(0) {}

    void setMentor(Mentor* mentor) {
        mentorAssigned = mentor;
    }

    void setSportsInterest(Sport** sports, int count) {
        sportsInterests = new Sport*[count];
        numSports = count;
        for (int i = 0; i < count; i++) {
            sportsInterests[i] = sports[i];
        }
    }

    void registerForMentorship(Mentor* mentors, int size, string id);
    void viewMentorDetails();
    void updateSportsInterest(Sport* s);
    string getName() { return name; }
};

class Mentor {
private:
    string mentorID;
    string name;
    int maxLearners;
    Student** assignedLearners;
    int numAssigned;
    Sport** sportsExpertise;
    int numSports;

public:
    Mentor(string id, string n, int maxL) : mentorID(id), name(n), maxLearners(maxL), numAssigned(0), assignedLearners(new Student*[maxL]), sportsExpertise(nullptr), numSports(0) {}

    int getNoOfAssignedLearners() {
        return numAssigned;
    }

    string getMentorID() {
        return mentorID;
    }

    string getName() {
        return name;
    }

    int getMaxLearners() {
        return maxLearners;
    }

    void assignLearner(Student* s) {
        if (numAssigned < maxLearners) {
            assignedLearners[numAssigned++] = s;
            s->setMentor(this);
        }
    }

    void removeLearner(Student* s) {
        for (int i = 0; i < numAssigned; i++) {
            if (assignedLearners[i] == s) {
                for (int j = i; j < numAssigned - 1; j++) {
                    assignedLearners[j] = assignedLearners[j + 1];
                }
                numAssigned--;
                cout << "Learner removed successfully." << endl;
                return;
            }
        }
        cout << "Learner not found." << endl;
    }

    void viewLearners() {
        cout << "Learners assigned to Mentor " << name << ":" << endl;
        for (int i = 0; i < numAssigned; i++) {
            cout << "- " << assignedLearners[i]->getName() << endl;
        }
    }

    void provideGuidance() {
        cout << "Providing guidance to learners." << endl;
    }
};

class Sport {
private:
    string sportID;
    string name;
    string description;
    Skill** requiredSkills;
    int numSkills;

public:
    Sport(string ID, string sportName, string desc) : sportID(ID), name(sportName), description(desc), requiredSkills(nullptr), numSkills(0) {}

    void addSkill(Skill* s) {
        Skill** temp = new Skill*[numSkills + 1];
        for (int i = 0; i < numSkills; i++) {
            temp[i] = requiredSkills[i];
        }
        temp[numSkills++] = s;
        delete[] requiredSkills;
        requiredSkills = temp;
    }

    void removeSkill(Skill* s) {
        for (int i = 0; i < numSkills; i++) {
            if (requiredSkills[i] == s) {
                for (int j = i; j < numSkills - 1; j++) {
                    requiredSkills[j] = requiredSkills[j + 1];
                }
                numSkills--;
                cout << "Skill removed successfully" << endl;
                return;
            }
        }
        cout << "Skill not found" << endl;
    }
};

class Skill {
private:
    string skillID;
    string skillName;
    string description;

public:
    Skill(string id, string name, string desc) : skillID(id), skillName(name), description(desc) {}

    void showSkillDetails() {
        cout << "Skill ID: " << skillID << ", Skill Name: " << skillName << ", Description: " << description << endl;
    }

    void updateSkillDescription(string newDescription) {
        description = newDescription;
    }
};

int main() {
    Mentor mentor1("M001", "Umer", 3);
    Student student1("S001", "Ahmed", 20);
    Student student2("S002", "Usman", 21);
    Student student3("S003", "Hassan", 22);
    Student student4("S004", "Absar", 23);

    mentor1.assignLearner(&student1);
    mentor1.assignLearner(&student2);
    mentor1.assignLearner(&student3);

    cout << "Trying to assign a fourth student:" << endl;
    mentor1.assignLearner(&student4);

    mentor1.viewLearners();
    mentor1.removeLearner(&student2);
    mentor1.viewLearners();
    
    return 0;
}
