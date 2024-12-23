#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structures for Weather, Crop, Equipment, Sensor, and Field
struct WeatherForecast {
    float temperature;  // in celsius
    float rainfall;     // in mm
    float windSpeed;    // in km/h
};

struct Crop {
    char cropType[50];         // Type of the crop
    int growthStage;           // Growth stage (0 to 5)
    float expectedYield;       // Expected yeild in kg
    struct WeatherForecast *weather; // Pointer to weather info
};

struct Equipment {
    char name[50];         // Equipment name
    float fuelLevel;       // Fuel level as percentage
    char operationalStatus[20]; // Status (active/offline)
};

struct Sensor {
    float nutrients;       // Nutrient level
    float pH;              // pH level
    int pestActivity;      // Pest activity scale (0 to 3)
};

struct Field {
    float gps[2];            // GPS coordinates [latitude, longitude]
    float soilHealth;        // Soil health score
    float moistureLevel;     // Moisture level percentage
    struct Crop *crops;      // Pointer to crops array
    struct Equipment *equipment; // Pointer to equipment array
    struct Sensor *sensors;  // Pointer to sensors array
};

int main() {
    int numFields;
     int numCrops;

    printf("Enter no. of fileds in the regional hub: "); // Typo: "fileds"
    scanf("%d", &numFields);

    struct Field *fields = (struct Field *)calloc(numFields, sizeof(struct Field));
    if (!fields) {
        printf("Memory allocation faied.\n"); // Typo: "faied"
        return 1;
    }
    int i;
    for ( i = 0; i < numFields; i++) {
        printf("\n--- Feild %d ---\n", i + 1); // Typo: "Feild"
        printf("Enter GPS cordinates (lat lng): "); // Typo: "cordinates"
        scanf("%f %f", &fields[i].gps[0], &fields[i].gps[1]);
        printf("Enter soil helth (0-1): "); // Typo: "helth"
        scanf("%f", &fields[i].soilHealth);
        printf("Enter moisure level (percentage): "); // Typo: "moisure"
        scanf("%f", &fields[i].moistureLevel);

       
        printf("How many crpos in field %d? ", i + 1);
		 // Typo: "crpos"
        scanf("%d", &numCrops);
        
        fields[i].crops = (struct Crop *)calloc(numCrops, sizeof(struct Crop));

int j;
        for (j = 0; j < numCrops; j++) {
        	
            printf("\nEnter crop %d type: ", j + 1);
            scanf("%s", fields[i].crops[j].cropType);
            printf("Enter growth stage (0-5): ");
            scanf("%d", &fields[i].crops[j].growthStage);
            printf("Enter expexted yeild (kg): "); // Typo: "expexted" and "yeild"
            scanf("%f", &fields[i].crops[j].expectedYield);

            fields[i].crops[j].weather = (struct WeatherForecast *)malloc(sizeof(struct WeatherForecast));
            printf("Enter weather (temp, rain, wind): ");
            scanf("%f %f %f", 
                &fields[i].crops[j].weather->temperature, 
                &fields[i].crops[j].weather->rainfall, 
                &fields[i].crops[j].weather->windSpeed);
        }
        

        int numEquipment;
        printf("Enter no. of equipments: ");
        scanf("%d", &numEquipment);
        fields[i].equipment = (struct Equipment *)calloc(numEquipment, sizeof(struct Equipment));

        for (j = 0; j < numEquipment; j++) {
            printf("\nEquipment %d name: ", j + 1);
            scanf("%s", fields[i].equipment[j].name);
            printf("Fuel level (percentage): ");
            scanf("%f", &fields[i].equipment[j].fuelLevel);
            printf("Operational status (active/offline): ");
            scanf("%s", fields[i].equipment[j].operationalStatus);
        }
        

        int numSensors;
        printf("Enter no. of sensors: ");
        scanf("%d", &numSensors);
        fields[i].sensors = (struct Sensor *)calloc(numSensors, sizeof(struct Sensor));

        for (j = 0; j < numSensors; j++) {
            printf("\nSensor %d - Nutrients level: ", j + 1);
            scanf("%f", &fields[i].sensors[j].nutrients);
            printf("pH Level: ");
            scanf("%f", &fields[i].sensors[j].pH);
            printf("Pest Activity (0-3): ");
            scanf("%d", &fields[i].sensors[j].pestActivity);
        }
        int num=numCrops;
    }
    

    printf("\n--- Summary ---\n");
    for (i = 0; i < numFields; i++) {
        printf("\nField %d\n", i + 1);
        printf("  GPS: %.2f, %.2f\n", fields[i].gps[0], fields[i].gps[1]);
        printf("  Soil Health: %.2f, Moisture: %.2f%%\n", fields[i].soilHealth, fields[i].moistureLevel);
    }
    
int j;
    for (i = 0; i < numFields; i++) {
        for ( j = 0; j < numCrops; j++) {
            free(fields[i].crops[j].weather);
        }
        free(fields[i].crops);
        free(fields[i].equipment);
        free(fields[i].sensors);
    }
    free(fields);

    return 0;
}
