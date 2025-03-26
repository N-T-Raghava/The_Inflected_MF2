# The_Inflected_MF2

**MF2 + Unicode Inflection**  
This project extends **MessageFormat2 (MF2)** by integrating **Unicode Inflection** to enable grammatically correct pluralization, gender agreement, case handling, and list formatting across multiple languages.  

**Project Overview**  
- Handles **irregular plural forms** (e.g., "mouse" → "mice") automatically.  
- Supports **gender-based inflection** for languages with masculine and feminine forms (e.g., "le chat" vs "la chatte").  
- Applies **case-based inflection** (e.g., nominative, accusative, genitive).  
- Format lists with proper conjunctions based on language rules (e.g., "and" vs. "y").  
- Includes comprehensive **Catch2-based unit tests** to ensure accuracy and stability.  

**Why It Matters**  
This project solves complex grammatical challenges by automating the detection and correction of language-based rules, improving both usability and linguistic accuracy across different languages.

**Structure**
```text
The_Inflected_MF2/
├── include/
│   ├── catch.hpp
│   ├── dict.h
│   ├── inflection.h
│   └── mf2.h
├── src/
│   ├── dict.cpp
│   ├── inflection.cpp
│   └── mf2.cpp
├── tests/
│   └── tests.cpp
└── CMakeLists.txt
