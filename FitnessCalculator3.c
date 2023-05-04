#include <stdio.h>

void calorie_intake_calculator(FILE *);
void bmi_calculator(FILE *);
void steps_calculator(FILE *);
void vo2_calculator(FILE *);
void heart_rate_calculator(FILE *);

int main() {
    int choice;
    char filename[100];
    FILE *file;

    printf("Fitness Calculator\n");
    printf("Please select an option:\n");
    printf("1. Calorie Intake Calculator\n");
    printf("2. Body Mass Index (BMI) Calculator\n");
    printf("3. Steps Calculator\n");
    printf("4. VO2 Max Calculator\n");
    printf("5. Heart Rate Calculator\n");
    printf("Enter your choice (1-5): ");
    scanf("%d", &choice);

    // open file for writing
    printf("Enter the name of the output file: ");
    scanf("%s", filename);
    file = fopen(filename, "w");

    switch (choice) {
        case 1:
            calorie_intake_calculator(file);
            break;
        case 2:
            bmi_calculator(file);
            break;
        case 3:
            steps_calculator(file);
            break;
        case 4:
            vo2_calculator(file);
            break;
        case 5:
            heart_rate_calculator(file);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }

    // close file
    fclose(file);

    return 0;
}

void calorie_intake_calculator(FILE *file) {
    float weight, height, age, bmr, tdee;
    int gender, activity_level;

    // get user input
    printf("\nCalorie Intake Calculator\n");
    fprintf(file, "Calorie Intake Calculator\n");
    printf("Enter your weight in kilograms: ");
    fprintf(file, "Enter your weight in kilograms: ");
    scanf("%f", &weight);
    fprintf(file, "%.2f\n", weight);
    printf("Enter your height in centimeters: ");
    fprintf(file, "Enter your height in centimeters: ");
    scanf("%f", &height);
    fprintf(file, "%.2f\n", height);
    printf("Enter your age in years: ");
    fprintf(file, "Enter your age in years: ");
    scanf("%f", &age);
    fprintf(file, "%.2f\n", age);
    printf("Enter your gender (1 for male, 2 for female): ");
    fprintf(file, "Enter your gender (1 for male, 2 for female): ");
    scanf("%d", &gender);
    fprintf(file, "%d\n", gender);
    printf("Enter your activity level (1 for sedentary, 2 for lightly active, 3 for moderately active, 4 for very active, 5 for extra active): ");
    fprintf(file, "Enter your activity level (1 for sedentary, 2 for lightly active, 3 for moderately active, 4 for very active, 5 for extra active): ");
    scanf("%d", &activity_level);
    fprintf(file, "%d\n", activity_level);

    // calculate BMR based on gender
    if (gender == 1) { // male
        bmr = 88.362 + (13.397 * weight) + (4.799 * height) - (5.677 * age);
    } else if (gender == 2) { // female
        bmr = 447.593 + (9.247 * weight) + (3.098 * height) - (4.330 * age);
    } else{
    	printf("Invalid Gender please try again\n");
    	return;
	}
	
// calculate TDEE based on BMR and activity level
    switch (activity_level) {
        case 1: 
            tdee = bmr * 1.2;
            break;
        case 2: 
            tdee = bmr * 1.375;
            break;
        case 3: 
            tdee = bmr * 1.55;
            break;
        case 4: 
            tdee = bmr * 1.725;
            break;
        case 5:
            tdee = bmr * 1.9;
            break;
        default:
            printf("Invalid activity level. Please try again.\n");
            return;
    }

 
    printf("Your BMR is %.2f calories.\n", bmr);
    printf("Your TDEE is %.2f calories.\n", tdee);
}

void bmi_calculator(FILE *file) {
    float weight, height, bmi;

    // get user input
    printf("\nEnter your weight in kilograms: ");
    fprintf(file, "Enter your weight in kilograms: ");
    scanf("%f", &weight);
    fprintf(file, "%.2f\n", weight);
    printf("Enter your height in meters: ");
    fprintf(file, "Enter your height in meters: ");
    scanf("%f", &height);
    fprintf(file, "%.2f\n", height);

    // calculate BMI
    bmi = weight / (height * height);

    // output results
    printf("\nYour BMI is: %.2f\n", bmi);
    fprintf(file, "Your BMI is: %.2f\n", bmi);

    // interpret BMI results
    if (bmi < 18.5) {
        printf("You are underweight.\n");
        fprintf(file, "You are underweight.\n");
    } else if (bmi >= 18.5 && bmi < 25) {
        printf("You are normal weight.\n");
        fprintf(file, "You are normal weight.\n");
    } else if (bmi >= 25 && bmi < 30) {
        printf("You are overweight.\n");
        fprintf(file, "You are overweight.\n");
    } else {
        printf("You are obese.\n");
        fprintf(file, "You are obese.\n");
    }
}

void steps_calculator(FILE *file) {
    int steps;
    float stride_length, distance;

    // get user input
    printf("\nSteps Calculator\n");
    fprintf(file, "Steps Calculator\n");
    printf("Enter the number of steps you have walked: ");
    fprintf(file, "Enter the number of steps you have walked: ");
    scanf("%d", &steps);
    fprintf(file, "%d\n", steps);
    printf("Enter your stride length in meters: ");
    fprintf(file, "Enter your stride length in meters: ");
    scanf("%f", &stride_length);
    fprintf(file, "%.2f\n", stride_length);

    // calculate distance
    distance = steps * stride_length;

    // print result
    printf("You have walked %.2f meters.\n", distance);
    fprintf(file, "You have walked %.2f meters.\n", distance);
}

void vo2_calculator(FILE *file) {
    float distance, time;
    int gender, age;
    float vo2max;

    // get user input
    printf("\nVO2 Max Calculator\n");
    fprintf(file, "VO2 Max Calculator\n");
    printf("Enter the distance covered in meters: ");
    fprintf(file, "Enter the distance covered in meters: ");
    scanf("%f", &distance);
    fprintf(file, "%.2f\n", distance);
    printf("Enter the time taken in seconds: ");
    fprintf(file, "Enter the time taken in seconds: ");
    scanf("%f", &time);
    fprintf(file, "%.2f\n", time);
    printf("Enter your gender (1 for male, 2 for female): ");
    fprintf(file, "Enter your gender (1 for male, 2 for female): ");
    scanf("%d", &gender);
     fprintf(file, "%d\n", gender);
    printf("Enter your age in years: ");
    fprintf(file, "Enter your age in years: ");
    scanf("%d", &age);
    fprintf(file, "%d\n", age);

    // calculate vo2max
    float pace = time / distance; // seconds per meter
    float speed = distance / time; // meters per second
    float mets = speed / 1.4; // metabolic equivalents
    if (gender == 1) { // male
        vo2max = 15 * mets;
    } else if (gender == 2) { // female
        vo2max = 15 * mets * 1.1;
    } else {
        printf("Invalid gender. Please try again.\n");
        return;
    }
    vo2max = vo2max * (1 - 0.01 * age);

    // display results
    printf("Your VO2 Max is %.2f ml/kg/min\n", vo2max);
    fprintf(file, "Your VO2 Max is %.2f ml/kg/min\n", vo2max);
}

void heart_rate_calculator(FILE *file) {
  int age;
  printf("Enter your age\n");
  scanf("%d",&age);
  int maxHeartRate = 220 - age;
  int targetHeartRate[3];
  targetHeartRate[0] = 0.5 * maxHeartRate;
  targetHeartRate[1] = 0.7 * maxHeartRate;
  targetHeartRate[2] = 0.85 * maxHeartRate;

  printf("For a person with age %d:\n", age);
  fprintf(file,"For a person with age %d:\n", age);
  printf("Maximum Heart Rate: %d bpm\n", maxHeartRate);
  fprintf(file,"Maximum Heart Rate: %d bpm\n", maxHeartRate);
  printf("Target Heart Rate Range:\n");
  printf("- Low: %d bpm\n", targetHeartRate[0]);
  fprintf(file,"- Low: %d bpm\n", targetHeartRate[0]);
  printf("- Moderate: %d bpm\n", targetHeartRate[1]);
  fprintf(file,"- Moderate: %d bpm\n", targetHeartRate[1]);
  printf("- High: %d bpm\n", targetHeartRate[2]);
  fprintf(file,"- High: %d bpm\n", targetHeartRate[2]);
  
   int ageGroup = (age - 1) / 10 + 1;  // Group ages into 10-year intervals

  switch (ageGroup) {
    case 1:
      printf("Age group: 1 (1-10 years old)\n");
      fprintf(file,"Age group: 1 (1-10 years old)\n");
      break;
    case 2:
      printf("Age group: 2 (11-20 years old)\n");
      fprintf(file,"Age group: 2 (11-20 years old)\n");
      break;
    case 3:
      printf("Age group: 3 (21-30 years old)\n");
      fprintf(file,"Age group: 3 (21-30 years old)\n");
      break;
    case 4:
      printf("Age group: 4 (31-50 years old)\n");
      fprintf(file,"Age group: 4 (31-50 years old)\n");
      break;
    case 5:
      printf("Age group: 5 (51-75 years old)\n");
      fprintf(file,"Age group: 5 (51-75 years old)\n");
      break;
    default:
      printf("Invalid age group\n");
      fprintf(file,"Invalid age group\n");
      
  }
}







