#include <iostream>
#include <cmath>

int main() {
    const int NUMBER_OF_PROJECTS{5};

    double midtermMaxGrade{-1}, finalMaxGrade{-1}, project1MaxGrade{-1}, project2MaxGrade{-1}, project3MaxGrade{-1}, project4MaxGrade{-1}, project5MaxGrade{-1};

    double midtermGrade{-1}, finalGrade{-1}, project1Grade{-1}, project2Grade{-1}, project3Grade{-1}, project4Grade{-1}, project5Grade{-1};
    double midtermGradeOf100, finalGradeOf100, project1GradeOf100, project2GradeOf100, project3GradeOf100, project4GradeOf100, project5GradeOf100;

    double projectTotal;
    double projectAverage;
    double examWeightedAverage;
    double finalAverage;

    
    while (finalMaxGrade <= 0 || std::round(finalMaxGrade) != finalMaxGrade){
        std::cout << "Please enter the final exam max grade: ";
        std::cin >> finalMaxGrade;
    }

    while (finalGrade < 0 or finalGrade > finalMaxGrade){
        std::cout << "Please enter your final exam grade: ";
        std::cin >> finalGrade;
    }
 
    while (midtermMaxGrade <= 0 || std::round(midtermMaxGrade) != midtermMaxGrade){
        std::cout << "Please enter the midterm exam max grade: ";
        std::cin >> midtermMaxGrade;
    }

    while (midtermGrade < 0 or midtermGrade > midtermMaxGrade){
        std::cout << "Please enter your midterm exam grade: ";
        std::cin >> midtermGrade;
    }

    while(project1MaxGrade <= 0 || std::round(project1MaxGrade) != project1MaxGrade){
        std::cout << "Please enter the Project 1 max grade: ";
        std::cin >> project1MaxGrade;
    }

    while (project1Grade < 0 or project1Grade > project1MaxGrade){
        std::cout << "Please enter your Project 1 grade: ";
        std::cin >> project1Grade;
    }

    while(project2MaxGrade <= 0 || std::round(project2MaxGrade) != project2MaxGrade){
        std::cout << "Please enter the Project 2 max grade: ";
        std::cin >> project2MaxGrade;
    }

    while (project2Grade < 0 or project2Grade > project2MaxGrade){
        std::cout << "Please enter your Project 2 grade: ";
        std::cin >> project2Grade;
    }

    while(project3MaxGrade <= 0 || std::round(project3MaxGrade) != project3MaxGrade){
        std::cout << "Please enter the Project 3 max grade: ";
        std::cin >> project3MaxGrade;
    }

    while (project3Grade < 0 or project3Grade > project3MaxGrade){
        std::cout << "Please enter your Project 3 grade: ";
        std::cin >> project3Grade;
    }

    while(project4MaxGrade <= 0 || std::round(project4MaxGrade) != project4MaxGrade){
        std::cout << "Please enter the Project 4 max grade: ";
        std::cin >> project4MaxGrade;
    }

    while (project4Grade < 0 or project4Grade > project4MaxGrade){
        std::cout << "Please enter your Project 4 grade: ";
        std::cin >> project4Grade;
    }

    while(project5MaxGrade <= 0 || std::round(project5MaxGrade) != project5MaxGrade){
        std::cout << "Please enter the Project 5 max grade: ";
        std::cin >> project5MaxGrade;
    }

    while (project5Grade < 0 or project5Grade > project5MaxGrade){
        std::cout << "Please enter your Project 5 grade: ";
        std::cin >> project5Grade;
    }

    finalGradeOf100 = 100*finalGrade/finalMaxGrade;

    midtermGradeOf100 = std::max(100*midtermGrade/midtermMaxGrade, finalGradeOf100);


    project1GradeOf100 = std::max(100*project1Grade/project1MaxGrade, finalGradeOf100);
    project2GradeOf100 = std::max(100*project2Grade/project2MaxGrade, finalGradeOf100);
    project3GradeOf100 = std::max(100*project3Grade/project3MaxGrade, finalGradeOf100);
    project4GradeOf100 = std::max(100*project4Grade/project4MaxGrade, finalGradeOf100);
    project5GradeOf100 = std::max(100*project5Grade/project5MaxGrade, finalGradeOf100);

    examWeightedAverage = 0.75*finalGradeOf100 + 0.25*midtermGradeOf100;

    projectTotal = project1GradeOf100 + project2GradeOf100 + project3GradeOf100 + project4GradeOf100 + project5GradeOf100;

    projectAverage = projectTotal/NUMBER_OF_PROJECTS;

    if (examWeightedAverage <= 40){
        finalAverage = examWeightedAverage;
    } else if (examWeightedAverage >= 60) {
        finalAverage = (2.0/3.0)*examWeightedAverage + (1.0/3.0)*projectAverage;

    } else {
        double projectWeight = (1.0/3.0)*((examWeightedAverage - 40)/20);
        finalAverage = projectWeight*projectAverage + (1.0-projectWeight)*examWeightedAverage;
    }

    std::cout << "your final grade is: " << std::round(finalAverage);

    return 0;
}