#include "../include/dict.h"

//Plural map
const std::unordered_map<std::string, std::string> irregularPlurals = {
    {"mouse", "mice"},
    {"child", "children"},
    {"man", "men"},
    {"woman", "women"},
    {"tooth", "teeth"},
    {"foot", "feet"},
    {"goose", "geese"},
    {"person", "people"},
    {"ox", "oxen"},
    {"fish", "fish"}
};

// Gender map
const std::unordered_map<std::string, std::pair<std::string, std::string>> genderMap = {
    // Animals
    {"cat", {"le chat", "la chatte"}},
    {"dog", {"le chien", "la chienne"}},
    {"horse", {"le cheval", "la jument"}},
    {"lion", {"le lion", "la lionne"}},
    {"tiger", {"le tigre", "la tigresse"}},
    {"fox", {"le renard", "la renarde"}},
    {"bear", {"l'ours", "l'ourse"}},
    {"rabbit", {"le lapin", "la lapine"}},

    // People
    {"friend", {"ami", "amie"}},
    {"teacher", {"professeur", "professeure"}},
    {"actor", {"acteur", "actrice"}},
    {"doctor", {"docteur", "docteure"}},
    {"king", {"roi", "reine"}},
    {"prince", {"prince", "princesse"}},
    {"hero", {"héros", "héroïne"}},
    {"host", {"hôte", "hôtesse"}},

    // Objects (where applicable)
    {"apple", {"la pomme", "la pomme"}},  // Same for both genders
    {"car", {"la voiture", "la voiture"}},  // Same for both genders
    {"house", {"la maison", "la maison"}},

    // Professions
    {"writer", {"écrivain", "écrivaine"}},
    {"engineer", {"ingénieur", "ingénieure"}},
    {"artist", {"artiste", "artiste"}},
    {"student", {"étudiant", "étudiante"}}
};

// Case map
const std::unordered_map<std::string, std::unordered_map<std::string, std::string>> caseForms = {
    {"apple", {{"nominative", "apple"}, {"accusative", "apple"}, {"genitive", "apple's"}}},
    {"cat", {{"nominative", "cat"}, {"accusative", "cat"}, {"genitive", "cat's"}}}
};

// Adjective agreement map
const std::unordered_map<std::string, std::string> adjectiveAgreement = {
    {"big", "big"},
    {"small", "small"},
    {"red", "red"},
    {"blue", "blue"},
    {"old", "old"},
    {"young", "young"}
};
